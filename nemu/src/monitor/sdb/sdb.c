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
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
//#include "watchpoint.c"
//#include <memory/paddr.h>

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
  //Log("%d", nemu_state.state); //为修改前state是NEMU_RUNNING，过不了正常退出判断
  nemu_state.state = NEMU_QUIT;  //在退出时修改为退出的state
  return -1;
}

static int cmd_si(char *args) {
  uint64_t n = 0;
  char *endptr;
  char *arg = strtok(NULL, " ");  //这里使用NULL是因为需要提供的str已经在sdb_main中提供了
  if (arg == NULL) {
    cpu_exec(1);
    return 0;  
  } 
  n = strtol(arg, &endptr, 10);
  if (*endptr != '\0') {
    Log("Error. Not an integer.\n");
  } else {
    cpu_exec(n);
  }
  return 0;
}

static int cmd_info(char *args){
  char *arg = strtok(NULL, " ");
  if (arg == NULL) {
    Log("Please give the subcmd.\n");
    return 0;
  } else if (strcmp(arg, "r") == 0) {
    isa_reg_display();
    return 0;
  } else if (strcmp(arg, "w") == 0) {
    watchpoint_info();
    return 0;
  }
  return 0;
}

static int cmd_x(char *args){
  if (args == NULL) {
    printf("Error. Invalid Address input\n");
    return 0;
  }
  int N;
  uint32_t startAddress;
  sscanf(args, "%d %x", &N, &startAddress); //使用sscanf分别读如地址和输出的字节
  for (int i = 0;i < N; i++) {
    printf("%x\n", vaddr_read(startAddress, 4)); //4代表4个字节也就是32位
    startAddress += 4;
  }
  return 0;
}

static int cmd_p(char *args){
  bool success = true;
  int32_t res = expr(args, &success);
  if (!success) {
    printf("invalid expression\n");
  } else {
    printf("%d\n", res);
  }
  return 0;
}
static int cmd_w(char *args) {
  if (!args) {
    printf("Error");	  
    return 0;
  }
  bool success = true;
  //Log("%s", args);
  int32_t res = expr(args, &success);
  if (!success) {
    printf("Invalid expression\n");
  } else {
    set_watchpoint(args, res);
  }
  return 0;
}

static int cmd_d(char *args) {
  char *arg = strtok(NULL, "");
  if (!arg) {
    printf("Error");
    return 0;
  }
  int watchpoint = strtol(arg, NULL, 10);
  remove_watchpoint(watchpoint);
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
  { "si", "Execute n lines", cmd_si},
  { "info", "r to print registers status and w to print watchpoint information", cmd_info},
  { "x", "Get EXPR's value, take it as the start storage output n 4 Bytes", cmd_x},
  { "p", "Get expression value", cmd_p},
  { "w", "Set watchpoint", cmd_w},
  { "d", "Delete watchpoint", cmd_d},
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
    //char *subcmd = strtok(NULL, " ");

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
  Log("Watchpoint pool inited");
}
