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



static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
static int next_no = 0;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP* new_wp(const char* expr) {
  if (free_ == NULL) {
    printf("No free watchpoints available!\n");
    return NULL;
  }

   WP *wp = free_;
  free_ = free_->next;

  // 初始化该节点
  wp->NO = next_no++;
  strncpy(wp->expre, expr, sizeof(wp->expre) - 1);
  wp->expre[sizeof(wp->expre) - 1] = '\0';
  wp->next = NULL;

  // 将节点插入到 head 链表的尾部
  if (head == NULL) {
    head = wp;
  } else {
    WP *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = wp;
  }

  return wp;
}

void free_wp(int n) {
  if (head == NULL || n < 0 || n >= NR_WP) {
    printf("Invalid watchpoint number!\n");
    return;
  }

  WP **prev = &head;
  while (*prev != NULL && (*prev)->NO != n) {
    prev = &(*prev)->next;
  }

  if (*prev != NULL && (*prev)->NO == n) {
    WP *wp = *prev;
    *prev = wp->next;
    wp->next = free_;
    free_ = wp;
    printf("Watchpoint %d deleted\n", n);
  } else {
    printf("Watchpoint %d not found\n", n);
  }
}

void print_wp() {
  bool success = false;
  WP *wp = head;
  printf("Num\tType\t\tDisp Enb Address    What\n");
  while (wp != NULL) {
    printf("%d\twatchpoint\tkeep y\t\t%-10p %s (old value: %u)\n", wp->NO, (void*)wp, wp->expre, expr(wp->expre,&success));
    wp = wp->next;
  }
}//bug：不是*success 而是要加&