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

#ifndef __SDB_H__
#define __SDB_H__

#include "verilated.h"
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull.h"
#include <ostream>
#include <iostream>
#include "difftest.hpp"

#define ARRLEN(arr) (sizeof(arr) / sizeof((arr)[0]))
#define difftest1

extern VerilatedContext* contextp;
extern VysyxSoCFull* top;
//extern  char *regs[];


void sdb_mainloop();
void cpu_exec(uint64_t n);
//extern "C" void difftest_init(int port);

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expre[256];

  /* TODO: Add more members if necessary */

} WP;

__uint32_t expr(char *e, bool *success);
WP* new_wp(const char* expre);
void free_wp(int n);
void print_wp();


#endif
