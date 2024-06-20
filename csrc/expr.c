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
#include <memory/host.h>
#include <memory/paddr.h>

enum {
  TK_NOTYPE = 256, TK_EQ = 261,TK_INT = 257 ,
  TK_HEXHEAD = 258,TK_NEQ = 259,TK_AND = 260,
  TK_DEREF = 262,

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
  {"\\+", '+'},         // plus
  {"==", TK_EQ},        // equal
  {"\\-", '-'},         //sub
  {"\\*", '*'},         //mul
  {"\\/", '/'},         //chu
  {"\\(", '('},
  {"\\)", ')'}, 
  {"0[xX][0-9a-fA-F]+",  TK_HEXHEAD},   //hex要放在整数之前，要不检测不出来;
  {"[0-9]+", TK_INT},
  {"\\$[a-zA-Z0-9]+", '$'},         //reg_name
  {"!=",  TK_NEQ},      //NOT EQ
  {"&&",  TK_AND},
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

static Token tokens[65536] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;
  //printf("%s",e);
  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

       // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
         //   i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_NOTYPE:
            break;
          case TK_INT:
            tokens[nr_token].type = TK_INT;
            if(substr_len >= 31) return false;
            strncpy(tokens[nr_token].str,substr_start,substr_len);
            tokens[nr_token].str[substr_len] = '\0' ;
            nr_token++;
            break;
          case TK_HEXHEAD:
            tokens[nr_token].type = TK_HEXHEAD;
            if(substr_len >= 31) return false;
            strncpy(tokens[nr_token].str,substr_start+2,substr_len-2);
            tokens[nr_token].str[substr_len-2] = '\0' ;
            nr_token++;
            break;
          case '$':
            tokens[nr_token].type = '$';
            if(substr_len >= 31) return false;
            strncpy(tokens[nr_token].str,substr_start+1,substr_len-1);
            tokens[nr_token].str[substr_len-1] = '\0' ;
            nr_token++;
            break;
          case '+':
            tokens[nr_token].type = '+';
            nr_token++;
            break;
          case '-':
            tokens[nr_token].type = '-';
            nr_token++;
            break;
          case '*':
            tokens[nr_token].type = '*';
            nr_token++;
            break;
          case '/':
            tokens[nr_token].type = '/';
            nr_token++;
            break;
          case '(':
            tokens[nr_token].type = '(';
            nr_token++;
            break;
          case ')':
            tokens[nr_token].type = ')';
            nr_token++;
            break;
          case TK_EQ:
            tokens[nr_token].type = TK_EQ;
            nr_token++;
            break;         
          case TK_NEQ:
            tokens[nr_token].type = TK_NEQ;
            nr_token++;
            break;
          case TK_AND:
            tokens[nr_token].type = TK_AND;
            nr_token++;
            break;
          default: return false;
        }
        //printf("%c",e[position+1]);
        break;//?
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

static bool check_parentheses(int p,int q){
  if (tokens[p].type != '(' || tokens[q].type != ')') {
    return false;
  }
  int balance = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') balance++;
    if (tokens[i].type == ')') balance--;
    if (balance == 0 && i != q) {
      return false;
    }
  }
  return balance == 0;
}

static int find_mainop(int p,int q){//每考虑括号
  int level = 0;
  int pos = -1;
  int min_priority = 10;

  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(') level++;
    else if (tokens[i].type == ')') level--;
    else if (level == 0) {
      int priority = 10;
      if (tokens[i].type == '+' || tokens[i].type == '-') priority = 1;//fenkai
      else if (tokens[i].type == '*' || tokens[i].type == '/') priority = 2;
      else if (tokens[i].type == TK_EQ || tokens[i].type == TK_NEQ) priority = 0; // 等于和不等于优先级较低
      else if (tokens[i].type == TK_AND) priority = -1; // 逻辑与优先级最低
      else if (tokens[i].type == TK_DEREF) priority = 3;


      if (priority <= min_priority) {
        min_priority = priority;
        pos = i;
      }
    }
  }

  if (pos == -1) {
    printf("Cannot find main operator in the expression from %d to %d\n", p, q);
  }

  return pos;


}

static u_int32_t eval(int p,int q) {
  bool success=false;
  char *endptr;
  if (p > q) {
    /* Bad expression */
    printf("Bad expression:%d,%d\n",p,q);

    assert(p>q);
    return -1;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    if (tokens[p].type == TK_INT) {
      return (u_int32_t)strtoul(tokens[p].str, &endptr, 10);
    } else if (tokens[p].type == TK_HEXHEAD) {
      return (u_int32_t)strtoul(tokens[p].str, &endptr, 16);
    } else if (tokens[p].type == '$') {
      return isa_reg_str2val(tokens[p].str,&success);
    }
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  }
  else {
    /* We should do more things here. */
    //printf("%c,%c",)
    //printf("third:%d,%d\n",p,q);
    int op = find_mainop(p,q);
    u_int32_t val1 = eval(p, op - 1);
    u_int32_t val2 = eval(op + 1, q);

    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': return val1 / val2;     
      case TK_EQ: return val1 == val2;
      case TK_AND: return val1 && val2;
      case TK_NEQ: return val1 != val2;
      case TK_DEREF: return paddr_read(val2,4);
      
      default: assert(0);
  }
}
return -1;
}






word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  //printf("%d\n",nr_token);
  *success = true;
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '*' && (i == 0 || 
        tokens[i - 1].type == '+' || 
        tokens[i - 1].type == '-' || 
        tokens[i - 1].type == '*' || 
        tokens[i - 1].type == '/' || 
        tokens[i - 1].type == '(')) {
      tokens[i].type = TK_DEREF;
    }
  }

  return eval(0, nr_token -1);
}
