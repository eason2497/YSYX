// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24100013_CPU.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24100013_CPU__Syms.h"
#include "Vysyx_24100013_CPU___024root.h"

extern "C" unsigned int pmem_read(unsigned int addr, int len);

VL_INLINE_OPT void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__ifu0__DOT__pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__ifu0__DOT__pmem_read_TOP\n"); );
    // Body
    unsigned int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int len__Vcvt;
    for (size_t len__Vidx = 0; len__Vidx < 1; ++len__Vidx) len__Vcvt = len;
    unsigned int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(addr__Vcvt, len__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void npc_trap();

VL_INLINE_OPT void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__npc_trap_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__npc_trap_TOP\n"); );
    // Body
    npc_trap();
}

extern "C" int instruction_type_check();

VL_INLINE_OPT void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__instruction_type_check_TOP(IData/*31:0*/ &instruction_type_check__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__instruction_type_check_TOP\n"); );
    // Body
    int instruction_type_check__Vfuncrtn__Vcvt;
    instruction_type_check__Vfuncrtn__Vcvt = instruction_type_check();
    instruction_type_check__Vfuncrtn = instruction_type_check__Vfuncrtn__Vcvt;
}

extern "C" void segmentation_fault();

VL_INLINE_OPT void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__alu0__DOT__segmentation_fault_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__alu0__DOT__segmentation_fault_TOP\n"); );
    // Body
    segmentation_fault();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100013_CPU___024root___dump_triggers__act(Vysyx_24100013_CPU___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_24100013_CPU___024root___eval_triggers__act(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__VactTriggered.at(1U) = (vlSelf->inst 
                                      != vlSelf->__Vtrigrprev__TOP__inst);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__inst = vlSelf->inst;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(1U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_24100013_CPU___024root___dump_triggers__act(vlSelf);
    }
#endif
}
