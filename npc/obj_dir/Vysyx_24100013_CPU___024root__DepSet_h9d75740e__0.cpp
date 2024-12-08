// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24100013_CPU.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24100013_CPU___024root.h"

void Vysyx_24100013_CPU___024root___eval_act(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_act\n"); );
}

void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__alu0__DOT__segmentation_fault_TOP();

VL_INLINE_OPT void Vysyx_24100013_CPU___024root___nba_sequent__TOP__0(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__ysyx_24100013_CPU__DOT__rf0__DOT__rf__v0;
    __Vdlyvdim0__ysyx_24100013_CPU__DOT__rf0__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_24100013_CPU__DOT__rf0__DOT__rf__v0;
    __Vdlyvval__ysyx_24100013_CPU__DOT__rf0__DOT__rf__v0 = 0;
    // Body
    if (vlSelf->rst) {
        vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
        vlSelf->pc = 0x7ffffffcU;
        vlSelf->dnpc = 0x7ffffffcU;
    } else {
        if ((0x40U & vlSelf->inst)) {
            if ((0x20U & vlSelf->inst)) {
                if ((0x10U & vlSelf->inst)) {
                    vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                    vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                } else if ((8U & vlSelf->inst)) {
                    if ((4U & vlSelf->inst)) {
                        if ((2U & vlSelf->inst)) {
                            if ((1U & vlSelf->inst)) {
                                if (((0x80000000U > vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__auipc) 
                                     | (0x88000000U 
                                        < vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__auipc))) {
                                    Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__alu0__DOT__segmentation_fault_TOP();
                                }
                                vlSelf->dnpc = vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__auipc;
                                vlSelf->ysyx_24100013_CPU__DOT__result 
                                    = vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__jal;
                            } else {
                                vlSelf->dnpc = ((IData)(4U) 
                                                + vlSelf->pc);
                                vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                            }
                        } else {
                            vlSelf->dnpc = ((IData)(4U) 
                                            + vlSelf->pc);
                            vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                        }
                    } else {
                        vlSelf->dnpc = ((IData)(4U) 
                                        + vlSelf->pc);
                        vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                    }
                } else if ((4U & vlSelf->inst)) {
                    if ((2U & vlSelf->inst)) {
                        if ((1U & vlSelf->inst)) {
                            if (((0x80000000U > (0xfffffffeU 
                                                 & vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi)) 
                                 | (0x88000000U < (0xfffffffeU 
                                                   & vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi)))) {
                                Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__alu0__DOT__segmentation_fault_TOP();
                            }
                            vlSelf->dnpc = (0xfffffffeU 
                                            & vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi);
                            vlSelf->ysyx_24100013_CPU__DOT__result 
                                = vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__jal;
                        } else {
                            vlSelf->dnpc = ((IData)(4U) 
                                            + vlSelf->pc);
                            vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                        }
                    } else {
                        vlSelf->dnpc = ((IData)(4U) 
                                        + vlSelf->pc);
                        vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                    }
                } else {
                    vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                    vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                }
            } else {
                vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
            }
        } else if ((0x20U & vlSelf->inst)) {
            if ((0x10U & vlSelf->inst)) {
                if ((8U & vlSelf->inst)) {
                    vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                    vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                } else if ((4U & vlSelf->inst)) {
                    if ((2U & vlSelf->inst)) {
                        if ((1U & vlSelf->inst)) {
                            vlSelf->ysyx_24100013_CPU__DOT__result 
                                = vlSelf->ysyx_24100013_CPU__DOT__imm;
                            vlSelf->dnpc = ((IData)(4U) 
                                            + vlSelf->pc);
                        } else {
                            vlSelf->dnpc = ((IData)(4U) 
                                            + vlSelf->pc);
                            vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                        }
                    } else {
                        vlSelf->dnpc = ((IData)(4U) 
                                        + vlSelf->pc);
                        vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                    }
                } else {
                    vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                    vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                }
            } else {
                vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
            }
        } else if ((0x10U & vlSelf->inst)) {
            if ((8U & vlSelf->inst)) {
                vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
            } else if ((4U & vlSelf->inst)) {
                if ((2U & vlSelf->inst)) {
                    if ((1U & vlSelf->inst)) {
                        vlSelf->ysyx_24100013_CPU__DOT__result 
                            = vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__auipc;
                        vlSelf->dnpc = ((IData)(4U) 
                                        + vlSelf->pc);
                    } else {
                        vlSelf->dnpc = ((IData)(4U) 
                                        + vlSelf->pc);
                        vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                    }
                } else {
                    vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                    vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                }
            } else if ((2U & vlSelf->inst)) {
                if ((1U & vlSelf->inst)) {
                    vlSelf->ysyx_24100013_CPU__DOT__result 
                        = vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi;
                    vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                } else {
                    vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                    vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
                }
            } else {
                vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
                vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
            }
        } else {
            vlSelf->dnpc = ((IData)(4U) + vlSelf->pc);
            vlSelf->ysyx_24100013_CPU__DOT__result = 0U;
        }
        vlSelf->pc = vlSelf->dnpc;
    }
    __Vdlyvval__ysyx_24100013_CPU__DOT__rf0__DOT__rf__v0 
        = vlSelf->ysyx_24100013_CPU__DOT__result;
    __Vdlyvdim0__ysyx_24100013_CPU__DOT__rf0__DOT__rf__v0 
        = (0x1fU & (vlSelf->inst >> 7U));
    vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__jal 
        = ((IData)(4U) + vlSelf->pc);
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[__Vdlyvdim0__ysyx_24100013_CPU__DOT__rf0__DOT__rf__v0] 
        = __Vdlyvval__ysyx_24100013_CPU__DOT__rf0__DOT__rf__v0;
}

VL_INLINE_OPT void Vysyx_24100013_CPU___024root___nba_sequent__TOP__1(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->ysyx_24100013_CPU__DOT__imm = ((4U & vlSelf->ysyx_24100013_CPU__DOT__immtype)
                                            ? ((2U 
                                                & vlSelf->ysyx_24100013_CPU__DOT__immtype)
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & vlSelf->ysyx_24100013_CPU__DOT__immtype)
                                                    ? vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immJ
                                                    : 
                                                   (0xfffff000U 
                                                    & vlSelf->inst)))
                                            : ((2U 
                                                & vlSelf->ysyx_24100013_CPU__DOT__immtype)
                                                ? (
                                                   (1U 
                                                    & vlSelf->ysyx_24100013_CPU__DOT__immtype)
                                                    ? vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immB
                                                    : 
                                                   ((0xfe0U 
                                                     & (vlSelf->inst 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelf->inst 
                                                          >> 7U))))
                                                : (
                                                   (1U 
                                                    & vlSelf->ysyx_24100013_CPU__DOT__immtype)
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->inst 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (vlSelf->inst 
                                                       >> 0x14U))
                                                    : 0U)));
}

VL_INLINE_OPT void Vysyx_24100013_CPU___024root___nba_comb__TOP__0(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__auipc 
        = (vlSelf->pc + vlSelf->ysyx_24100013_CPU__DOT__imm);
}

void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__ifu0__DOT__pmem_read_TOP(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ &pmem_read__Vfuncrtn);
void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__npc_trap_TOP();
void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__instruction_type_check_TOP(IData/*31:0*/ &instruction_type_check__Vfuncrtn);

VL_INLINE_OPT void Vysyx_24100013_CPU___024root___nba_sequent__TOP__2(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___nba_sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ __Vfunc_ysyx_24100013_CPU__DOT__ifu0__DOT__pmem_read__0__Vfuncout;
    __Vfunc_ysyx_24100013_CPU__DOT__ifu0__DOT__pmem_read__0__Vfuncout = 0;
    // Body
    if (vlSelf->rst) {
        vlSelf->inst = 0U;
    } else {
        Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__ifu0__DOT__pmem_read_TOP(vlSelf->pc, 4U, __Vfunc_ysyx_24100013_CPU__DOT__ifu0__DOT__pmem_read__0__Vfuncout);
        vlSelf->inst = __Vfunc_ysyx_24100013_CPU__DOT__ifu0__DOT__pmem_read__0__Vfuncout;
    }
    vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immB 
        = ((0x1000U & (vlSelf->inst >> 0x13U)) | ((0x800U 
                                                   & (vlSelf->inst 
                                                      << 4U)) 
                                                  | ((0x7e0U 
                                                      & (vlSelf->inst 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (vlSelf->inst 
                                                           >> 7U)))));
    vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immJ 
        = (((- (IData)((vlSelf->inst >> 0x1fU))) << 0x15U) 
           | ((0x100000U & (vlSelf->inst >> 0xbU)) 
              | ((0xff000U & vlSelf->inst) | ((0x800U 
                                               & (vlSelf->inst 
                                                  >> 9U)) 
                                              | (0x7feU 
                                                 & (vlSelf->inst 
                                                    >> 0x14U))))));
    vlSelf->ysyx_24100013_CPU__DOT__src2 = ((0U == 
                                             (0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0x14U)))
                                             ? 0U : 
                                            vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf
                                            [(0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0x14U))]);
    if ((0x100073U == vlSelf->inst)) {
        Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__npc_trap_TOP();
    }
    Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__instruction_type_check_TOP(vlSelf->__Vfunc_ysyx_24100013_CPU__DOT__idu0__DOT__instruction_type_check__2__Vfuncout);
    vlSelf->ysyx_24100013_CPU__DOT__immtype = vlSelf->__Vfunc_ysyx_24100013_CPU__DOT__idu0__DOT__instruction_type_check__2__Vfuncout;
    vlSelf->ysyx_24100013_CPU__DOT__src1 = ((0U == 
                                             (0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0xfU)))
                                             ? 0U : 
                                            vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf
                                            [(0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0xfU))]);
}

VL_INLINE_OPT void Vysyx_24100013_CPU___024root___nba_comb__TOP__1(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___nba_comb__TOP__1\n"); );
    // Body
    vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi 
        = (vlSelf->ysyx_24100013_CPU__DOT__imm + vlSelf->ysyx_24100013_CPU__DOT__src1);
}

void Vysyx_24100013_CPU___024root___eval_nba(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_24100013_CPU___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vysyx_24100013_CPU___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vysyx_24100013_CPU___024root___nba_comb__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_24100013_CPU___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vysyx_24100013_CPU___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vysyx_24100013_CPU___024root___eval_triggers__act(Vysyx_24100013_CPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100013_CPU___024root___dump_triggers__act(Vysyx_24100013_CPU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100013_CPU___024root___dump_triggers__nba(Vysyx_24100013_CPU___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_24100013_CPU___024root___eval(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vysyx_24100013_CPU___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vysyx_24100013_CPU___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/eason/ysyx-workbench/npc/vsrc/ysyx_24100013_CPU.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vysyx_24100013_CPU___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vysyx_24100013_CPU___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/eason/ysyx-workbench/npc/vsrc/ysyx_24100013_CPU.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vysyx_24100013_CPU___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_24100013_CPU___024root___eval_debug_assertions(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
