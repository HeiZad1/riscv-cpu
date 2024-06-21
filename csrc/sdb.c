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

#include "verilated.h"
#include "Vrv32i.h"
//#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
//#include <memory/host.h>
//#include <memory/paddr.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  return -1;
}

static int cmd_si(char *args) {
  uint64_t nb_ex;
  if (sscanf(args," %ld",&nb_ex)==1){
    cpu_exec(nb_ex);
    return 0;
  }
  else {
    nb_ex = 1;
    cpu_exec(nb_ex);
    return 0;
  }
  return 0;

}



static int cmd_info(char *args){
  char cmd_type = 'r';
  if (sscanf(args,"%10s char *",&cmd_type)==1){
    if (cmd_type == 'r') {
      isa_reg_display();
    } else if (cmd_type == 'w') {
      print_wp();
    } else {
      printf("Error: Unknown command type '%c'.\n", cmd_type);
      return -1;
    }
  } else {
    printf("Error: Arguments parsing failed.\n");
    return -1;
  }
  return 0;
}

static int cmd_x(char *args){
  int nb_mem;
  paddr_t addr_mem;
  if (sscanf(args," %d %x",&nb_mem,&addr_mem)==2){
    for(int i=0;i<nb_mem;i++){
      printf("%x\n",paddr_read(addr_mem,4));//len 是4不是32
      addr_mem = addr_mem +4;
    }
    return 0;
  }
  else {
    printf("Error:Arguments parsing failed.\n");
    return -1;
  }
  return 0;

}
//表达式不能有空格
static int cmd_p(char *args){
  char expre[32];
  bool success = false;
  if (sscanf(args, "%32s", expre)==1){
    printf("%u\n",expr(expre,&success));
  }
  else {
    printf("Error:Arguments parsing failed.\n");
    return -1;
  }
  return 0;
}

static int cmd_w(char *args){
  char expr[32];
  if (sscanf(args," %32s",expr)==1){
    new_wp(expr);
  }
  else {
    printf("Error:Arguments parsing failed.\n");
    return -1;
  }
  return 0;
}

static int cmd_d(char *args){
  int no;
  if (sscanf(args," %d",&no)==1){
    free_wp(no);
    return 0;
  }
  else {
    printf("Error:Arguments parsing failed.\n");
    return -1;
  }
  return 0;

}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si"," ",cmd_si},
  { "info","Display register information",cmd_info},
  { "x","",cmd_x},
  { "p","Print the value of expression expr",cmd_p},
  { "w","Set a watchpoint for expression expr",cmd_w},
  { "d","Delete the watchpoint number N",cmd_d},
  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;

    
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}

