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

#ifndef __NPC_COMMON_H__
#define __NPC_COMMON_H__

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>

#include <generated/autoconf.h>

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define FMT_WORD "0x%08"

#define FMT_PADDR "0x%08" 
typedef uint16_t ioaddr_t;

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

#endif

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define Log(...)        \
  do                     \
  {                      \
    printf(__VA_ARGS__); \
  } while (0)

#define Error(format, ...)                    \
  Log(FMT_RED("npc %s:%3d %s ") format "\n", \
       __FILENAME__, __LINE__, __func__, ##__VA_ARGS__)

#define Assert(cond, format, ...) \
  Error(format, ##__VA_ARGS__);   \
  assert(cond)


extern void display_iringbuf();
