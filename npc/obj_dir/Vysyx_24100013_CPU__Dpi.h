// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYX_24100013_CPU__DPI_H_
#define VERILATED_VYSYX_24100013_CPU__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/eason/ysyx-workbench/npc/vsrc/ysyx_24100013_IDU.v:15:33
    extern int instruction_type_check();
    // DPI import at /home/eason/ysyx-workbench/npc/vsrc/ysyx_24100013_IDU.v:13:34
    extern void npc_trap();
    // DPI import at /home/eason/ysyx-workbench/npc/vsrc/ysyx_24100013_IFU.v:12:38
    extern unsigned int pmem_read(unsigned int addr, int len);
    // DPI import at /home/eason/ysyx-workbench/npc/vsrc/ysyx_24100013_alu.v:19:30
    extern void segmentation_fault();

#ifdef __cplusplus
}
#endif

#endif  // guard
