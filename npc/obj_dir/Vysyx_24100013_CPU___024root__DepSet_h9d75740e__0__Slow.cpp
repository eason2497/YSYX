// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24100013_CPU.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24100013_CPU___024root.h"

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___eval_static(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___eval_initial__TOP(Vysyx_24100013_CPU___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___eval_initial(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_initial\n"); );
    // Body
    Vysyx_24100013_CPU___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__inst = vlSelf->inst;
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___eval_initial__TOP(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[1U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[2U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[3U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[4U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[5U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[6U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[7U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[8U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[9U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0xaU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0xbU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0xcU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0xdU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0xeU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0xfU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x10U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x11U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x12U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x13U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x14U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x15U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x16U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x17U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x18U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x19U] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x1aU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x1bU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x1cU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x1dU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x1eU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0x1fU] = 0U;
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__i = 0x20U;
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___eval_final(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___eval_triggers__stl(Vysyx_24100013_CPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100013_CPU___024root___dump_triggers__stl(Vysyx_24100013_CPU___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vysyx_24100013_CPU___024root___eval_stl(Vysyx_24100013_CPU___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___eval_settle(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vysyx_24100013_CPU___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vysyx_24100013_CPU___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/eason/ysyx-workbench/npc/vsrc/ysyx_24100013_CPU.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vysyx_24100013_CPU___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100013_CPU___024root___dump_triggers__stl(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__npc_trap_TOP();
void Vysyx_24100013_CPU___024root____Vdpiimwrap_ysyx_24100013_CPU__DOT__idu0__DOT__instruction_type_check_TOP(IData/*31:0*/ &instruction_type_check__Vfuncrtn);

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___stl_sequent__TOP__0(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___stl_sequent__TOP__0\n"); );
    // Body
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
    vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__jal 
        = ((IData)(4U) + vlSelf->pc);
    vlSelf->ysyx_24100013_CPU__DOT__src2 = ((0U == 
                                             (0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0x14U)))
                                             ? 0U : 
                                            vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf
                                            [(0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0x14U))]);
    vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__auipc 
        = (vlSelf->pc + vlSelf->ysyx_24100013_CPU__DOT__imm);
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
    vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi 
        = (vlSelf->ysyx_24100013_CPU__DOT__imm + vlSelf->ysyx_24100013_CPU__DOT__src1);
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___eval_stl(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_24100013_CPU___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100013_CPU___024root___dump_triggers__act(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([changed] inst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24100013_CPU___024root___dump_triggers__nba(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([changed] inst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_24100013_CPU___024root___ctor_var_reset(Vysyx_24100013_CPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->dnpc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__overflow = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24100013_CPU__DOT__zero = VL_RAND_RESET_I(1);
    vlSelf->ysyx_24100013_CPU__DOT__src1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__src2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__immtype = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immB = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immJ = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__auipc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__jal = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_ysyx_24100013_CPU__DOT__idu0__DOT__instruction_type_check__2__Vfuncout = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__inst = VL_RAND_RESET_I(32);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
