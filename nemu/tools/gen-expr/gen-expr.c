/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

uint32_t choose(uint32_t n){
  uint32_t num = rand() % n;
  return num;
}

static void gen_num() {
  uint32_t num = rand() % 99 + 1;
  char num_str[3];
  snprintf(num_str, sizeof(num_str), "%d", num);  //使用snprintf可以方便的格式化数字并存入字符串，方便添加
  if ((strlen(buf) + strlen(num_str)) < sizeof(buf)) {
    strcat(buf, num_str);
  } else {
    return;
  }
}

static void gen_space() {
  uint32_t space = choose(5);
  uint32_t i;
  for (i = 1; i <= space; i++) {
    strcat(buf, " ");
  }
}

static void gen_rand_op() {
  char ops[] = {'+', '-', '*', '/'};
  uint32_t choice = choose(4);
  char op[2] = {ops[choice], '\0'};
  if ((strlen(buf) + strlen(op)) < sizeof(buf)) {
    strcat(buf, op);
  } else {
    return;
  }
}

static void gen_rand_expr(uint32_t recur) {
  if (strlen(buf) > 65530) {
    printf("Oversize\n");
  }
  uint32_t choice = choose(3);
  if (recur >= 5) {     //给予递归限制，以此来确保buf不会溢出
    choice = 0;
  }
  switch (choice) {
    case 0:
      //if (buf[strlen(buf) - 1] != ')') {
        gen_num();
        break;
      //}
    case 1:
      if (strchr("+/-*", buf[strlen(buf) - 1]) != NULL) {	 //确保括号不乱出
	      strcat(buf, "(");
        gen_space(); 
	      gen_rand_expr(recur + 1);
        gen_space(); 
	      strcat(buf, ")");
        break;
      }
    default: 
      gen_rand_expr(recur + 1);
      gen_space();
	    gen_rand_op();
      gen_space(); 
	    gen_rand_expr(recur + 1); 
	    break;
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);     //根据输入的值来确定生成多少个表达式
  }
  int i;
  for (i = 0; i < loop; i ++) {
    gen_rand_expr(1);
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);
    //运用-Wall 和 -Werror将warning当作error处理
    int ret = system("gcc -Wall -Werror /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) {   //当正常运行退出时，ret将会是0,所以当报错时会直接由continue跳到下一次循环
      //printf("%dError\n", ret);
      memset(buf, '\0', sizeof(buf)); //重置buf
      continue;
    }
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int res;
    ret = fscanf(fp, "%d", &res);
    pclose(fp);

    printf("%d %s\n", res, buf);  //原先打印的是%u，无符号数，改为打印%d，之后可以正常显示负数
    memset(buf, '\0', sizeof(buf));
  }
  return 0;
}
