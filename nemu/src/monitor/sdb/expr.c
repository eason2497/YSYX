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

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include "sdb.h"  //in order to use paddr_read for deref


enum {
  TK_NOTYPE = 256, TK_EQ, TK_NOEQ, TK_AND, TK_NUMBER, TK_REG, TK_HEX, TK_POINTER_DEREF, TK_NEGATIVE,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\(", '('},         // left bracket
  {"\\)", ')'},         // right bracket
  {"\\*", '*'},         // multiplication
  {"/", '/'},            // division
  {"\\+", '+'},         // plus
  {"-", '-'},           // minus
  {"==", TK_EQ},        // equal
  {"!=", TK_NOEQ},	// not equal
  {"&&", TK_AND},	// and
  {"\\b[0-9]+\\b", TK_NUMBER}, //number
  {"\\$(\\$0|ra|[sgt]p|t[0-6]|a[0-7]|s([0-9]|l[0-1]))", TK_REG}, //registers
  {"0[xX][0-9a-fA-F]+", TK_HEX}, //hex
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {}; //一开始是32,为了兼容长表达式改大
static int nr_token __attribute__((used))  = 0;  //指示已经被识别出来的token数目

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
	      Token token;
        switch (rules[i].token_type) {
          case TK_NOTYPE: break;  //如果是空格，跳过
          default:
            strncpy(token.str, substr_start, substr_len); //将substr_start中的字符串拷贝到str中
            token.str[substr_len] = '\0';
            token.type = rules[i].token_type; //一个token的记录完成，放入tokens中并且nr_token数量加1
            tokens[nr_token++] = token;
            break;
	      }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

bool check_parentheses(word_t p, word_t q) {
  bool flag = false;
  if (tokens[p].type == '(' && tokens[q].type == ')') {
    for (int i = p + 1;i < q;) {
      if (tokens[i].type == ')') {
        return flag;
      } else if (tokens[i].type == '(') {
 	while (tokens[i+1].type != ')') {
	  i++;
	  if (i == q - 1)
 	    break;
	}
	i += 2; //a pair of parentheses found	
      }

      else i++;
    }
    flag = true;
  }
  return flag;
}

word_t get_operator(word_t p, word_t q){
  word_t ret = 0;
  word_t par = 0;
  word_t op_type = 0;
  word_t tmp_type = 0;
    
  for (word_t i = p;i <= q; i++){
   
    if (tokens[i].type == TK_NUMBER || tokens[i].type == TK_HEX || tokens[i].type == TK_REG) {   //数字都不是主运算符
      continue;
    } else if (tokens[i].type == TK_NOTYPE) {  //空格都不是主运算符
      continue;
    } else if (tokens[i].type == '(') {
      par++;
      continue;
    } else if (tokens[i].type == ')') {
      if (par == 0) {
        return -1;
      }
      par--;
    } else if (par > 0) {   //par大于0代表目前还在检索括号内符号，都不是主运算符
      continue;
    } else {
      switch (tokens[i].type) {      //根据case对于不同符号赋值并对比得出主运算符
        case TK_NEGATIVE: tmp_type = 1; break;
        case TK_POINTER_DEREF: tmp_type = 1; break;
        case '*': tmp_type = 2; break;
        case '/': tmp_type = 2; break;
        case '+': tmp_type = 3; break;
        case '-': tmp_type = 3; break;
        case TK_EQ: tmp_type = 4; break;
        case TK_NOEQ: tmp_type = 4; break;
        case TK_AND: tmp_type = 5; break;
        default: Log("No operator detected"); assert(0);
      }
      //printf("%d\n", tmp_type);
      //printf("%d\n", op_type);
      if (tmp_type >= op_type) {
        op_type = tmp_type;
	      ret = i;
        //Log("%d", ret);
      }
    }
  }
  if (par > 0) {    //如果检索完一遍后par大于0说明式子有问题，括号不匹配
    return -1;
  }
  //return tokens[ret].type;
  //Log("%d", ret);
  return ret;
}


uint32_t eval(word_t p, word_t q) {
  if (p > q) {
    Log("Bad expression");     //式子初始不可能左边界大于右边界
    assert(0);
  } else if (p == q) {
     /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    if (tokens[p].type == TK_NUMBER) {
      return strtol(tokens[p].str, NULL, 10);
    } else if (tokens[p].type == TK_REG) {
      word_t num;
      bool t = true;
      char *modify = tokens[p].str;   //因为对比寄存器名字的时候不需要美元符号，所以在这里作修改
      modify++;
      //printf("%s", modify);
      num = isa_reg_str2val(modify, &t);
      if (!t) {
        num = 0;
      }
      return num;
    } else if (tokens[p].type == TK_HEX) {
      return strtol(tokens[p].str, NULL, 16);
    } else {
      Log("Error occurs when p == q");
      assert(0);
      return 0;
    }
  } else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);  //去掉括号之后的左右边界
  } else {
    word_t op_type = get_operator(p, q);
    //Log("%d", op_type);
    if (tokens[op_type].type == TK_NEGATIVE || tokens[op_type].type == TK_POINTER_DEREF) {
      uint32_t val = eval(op_type + 1, q);
      switch (tokens[op_type].type) {
        case TK_NEGATIVE: return -val;
        case TK_POINTER_DEREF: return paddr_read(val, 4);
      }
    } 
    uint32_t val1 = eval(p, op_type - 1);
    uint32_t val2 = eval(op_type + 1, q);
    /*if (tokens[op_type].type == TK_NEGATIVE) {
      val2 = -val2;
      Log("%d", val2);
      return val2;
    }
    if (tokens[op_type].type == TK_POINTER_DEREF) {
      word_t* ptr = (word_t*) tokens[op_type + 1].str;
      return *ptr;
    }
    */
    switch (tokens[op_type].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': return val1 / val2;
      case TK_EQ: return val1 == val2;
      case TK_NOEQ: return val1 != val2;
      case TK_AND: return val1 && val2;
      default: Log("No operator detected."); assert(0);
    } 
  }

}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  //for (i = 0; i < nr_token; i++) {
  //  if (tokens[i].type == '*' && (i == 0 || tokens[i - 1].type == certain type)) {
  //    tokens[i].type = DEREF;
  //  }
  //}
  int i = 0;
  for (i = 0;i < nr_token; i++) {
    if (tokens[i].type == '-') {
      if (i == 0){
        tokens[i].type = TK_NEGATIVE;
        //Log("%d", tokens[i].type);
        //return i;
        continue;
      }
      if ((tokens[i - 1].type != ')') && (tokens[i - 1].type != TK_NUMBER) && (tokens[i - 1].type != TK_REG) && (tokens[i - 1].type != TK_HEX)) {
        tokens[i].type = TK_NEGATIVE;
        continue;
      }
    }
    // problem occur here, the condition to determine deref
    // solved by now by changing the conditions and do not use a for loop(still got problem)
    else if (tokens[i].type == '*') {  //指针解引用可以用p *0x80000000来测试
      if (i == 0){
        tokens[i].type = TK_POINTER_DEREF;
        //return i;
        continue;
      }
      if ((tokens[i - 1].type != ')') && (tokens[i - 1].type != TK_NUMBER) && (tokens[i - 1].type != TK_REG) && (tokens[i - 1].type != TK_HEX)) {
        tokens[i].type = TK_POINTER_DEREF;
        continue;
      }
    }
  }

  //TODO();
  printf("%d\n", nr_token);
  return eval(0, nr_token - 1);
}
