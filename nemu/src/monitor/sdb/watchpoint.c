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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expression[100];
  int value;

  /* TODO: Add more members if necessary */

} WP;
//static here makes the variables can only be modified within this file,
//functions from other files can not modify these
static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {   //head设为NULL，free_指向监视点第一位的地址
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP* new_wp();
void free_wp(WP *wp);

WP* new_wp() {
  if (free_ == NULL){
    Log("no empty watchpoint");
    assert(0);
  }
  WP *current = free_;    //free_指向的就是空的监视点
  free_ = free_->next;
  current->next = head;   //原先的head现在是新wp的next
  head = current;
  return current;
}

void free_wp(WP *wp) {
  if (wp == head) {
    head = head->next;
  } else {
    WP *current = head;
    while (current && current->next != wp){
      current++;
    }
    if (!current) {
      Log("Watchpoint not in the list");
      assert(0);
    }
    current->next = wp->next;
  }
  //free up wp in free_
  wp->next = free_;
  free_ = wp;
}

void set_watchpoint(char *args, int32_t res) {
  WP *wp = new_wp();
  //Log("%s", args);
  strcpy(wp->expression, args);        //如果expression 定义为char * 类型会出现segmentation error
  wp->value = res;
  printf("Watchpoint %d: %s\n", wp->NO, wp->expression);
}

void remove_watchpoint(int no){
  if ((no < 0) || (no >= NR_WP)) {
    printf("The input is incorrect\n");
    assert(0);
  }
  WP *wp = &wp_pool[no];
  printf("Deleted Watchpoint %d: %s\n", wp->NO, wp->expression);
  free_wp(wp);
}

void watchpoint_info(){
  WP *pos = head;
  if (!pos) {
    printf("No watchpoints\n");
    return;
  }
  printf("NO    Expression    Value\n");
  while(pos) {
    printf("%-6d%-16s%-16d0x%x\n", pos->NO, pos->expression, pos->value, pos->value);
    pos = pos->next;
  }
}

void watchpoint_diff() {     //还需调试,未作出同时两个wp同时改变的应对
  WP *pos = head;
  while(pos) {
    bool success = true;
    word_t new = expr(pos->expression, &success);
    if (pos-> value != new) {
      printf("Watchpoint %d: %s\n"
		      "Old value = %d\n"
		      "New value = %d\n",
		      pos->NO, pos->expression, pos->value, new);
      pos->value = new;
      nemu_state.state = NEMU_STOP;
    }
    pos = pos->next;
  }
}
