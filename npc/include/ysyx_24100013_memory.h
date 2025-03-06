
#ifndef _NPC_MEM_
#define _NPC_MEM_


#include <ysyx_24100013_common.h>

#define MEMBASE 0x80000000
#define MEMSIZE 0x8000000

#define PG_ALIGN __attribute((aligned(4096)))

extern uint8_t pmem[MEMSIZE];

uint8_t* guest_to_host(uint32_t addr);
uint32_t host_to_guest(uint8_t *haddr);
uint32_t host_read(void *addr, int len);
extern "C" uint32_t pmem_read(uint32_t addr, int len);

#endif