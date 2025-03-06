#ifndef _NPC_SDB_
#define _NPC_SDB_

#include <ysyx_24100013_common.h>

enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };

typedef struct {
  int state;
  uint32_t halt_pc;
  uint32_t halt_ret;
} NPCState;

extern NPCState npc_state;

extern void isa_reg_display();
extern uint32_t isa_reg_str2val(const char *s, bool *success);
extern uint32_t expr(char *e, bool *success);
extern void set_watchpoint(char *args, int32_t res);
extern void remove_watchpoint(int no);
extern void watchpoint_info();
extern void init_regex();
extern void init_wp_pool();


void init_sdb();
void cpu_exec(uint64_t n);
void sdb_mainloop();

#endif

