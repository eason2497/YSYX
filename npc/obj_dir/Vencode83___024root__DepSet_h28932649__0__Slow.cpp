// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode83.h for the primary calling header

#include "verilated.h"

#include "Vencode83___024root.h"

VL_ATTR_COLD void Vencode83___024root___eval_static(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vencode83___024root___eval_initial(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__en = vlSelf->en;
    vlSelf->__Vtrigrprev__TOP__x = vlSelf->x;
}

VL_ATTR_COLD void Vencode83___024root___eval_final(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vencode83___024root___eval_triggers__stl(Vencode83___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode83___024root___dump_triggers__stl(Vencode83___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vencode83___024root___eval_stl(Vencode83___024root* vlSelf);

VL_ATTR_COLD void Vencode83___024root___eval_settle(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vencode83___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vencode83___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/eason/ysyx-workbench/npc/vsrc/encode83.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vencode83___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode83___024root___dump_triggers__stl(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*6:0*/, 16> Vencode83__ConstPool__TABLE_hb2a417e2_0;

VL_ATTR_COLD void Vencode83___024root___stl_sequent__TOP__0(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = vlSelf->y;
    vlSelf->bcd = Vencode83__ConstPool__TABLE_hb2a417e2_0
        [__Vtableidx1];
}

VL_ATTR_COLD void Vencode83___024root___eval_stl(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vencode83___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode83___024root___dump_triggers__act(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([changed] en or [changed] x)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode83___024root___dump_triggers__nba(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([changed] en or [changed] x)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vencode83___024root___ctor_var_reset(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->x = VL_RAND_RESET_I(8);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->y = VL_RAND_RESET_I(4);
    vlSelf->in = VL_RAND_RESET_I(1);
    vlSelf->bcd = VL_RAND_RESET_I(7);
    vlSelf->encode83__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__en = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__x = VL_RAND_RESET_I(8);
    vlSelf->__VactDidInit = 0;
}
