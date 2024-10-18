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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
word_t expr(char *e, bool *success);

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif    //不能写在engine_start后面，因为会跳转到sdb_mainloop里
/*
  FILE *file;
  char lines[65536 + 128];  //expr + result
  char expression[65536];
  word_t result;

  file = fopen("/home/eason/ysyx-workbench/nemu/tools/gen-expr/build/input", "r");
  assert(file != NULL);
  while (fgets(lines, 65536 + 128, file) != NULL){
    int i = 0;
    int j = 0;

    int getResult = sscanf(lines, "%d", &result);
    assert(getResult == 1);
    while (lines[i] != ' '){
      i++;
    }
    while (lines[i] != '\n' && i < 65536){
      expression[j] = lines[i];
      j++;
      i++;
    }
    expression[j] = '\0';
    bool success = true;
    word_t ans = expr(expression, &success);
    if ((success == false) && (result - ans != 0)) {  //如果结果不一致将打印此表达式并退出运算
      printf("- origin line: %s- success: %d\n- expression: %s\n- result: %d\n- ans: %d\n",
            lines, success, expression, result, ans);
      return 0;
    }
  }
  return 0;

*/


  /* Start engine. */
  engine_start();   //通过查看此条function定义之后发现是在执行sdb_mainloop

  return is_exit_status_bad();   //之后通过return里的在个function来查看是否正常推出
}
