// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode83.h for the primary calling header

#include "verilated.h"

#include "Vencode83___024root.h"

void Vencode83___024root___eval_act(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*6:0*/, 16> Vencode83__ConstPool__TABLE_hb2a417e2_0;

VL_INLINE_OPT void Vencode83___024root___nba_sequent__TOP__0(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if (vlSelf->en) {
        vlSelf->encode83__DOT__i = 8U;
        if ((1U & (IData)(vlSelf->x))) {
            vlSelf->in = 1U;
        }
        if ((2U & (IData)(vlSelf->x))) {
            vlSelf->in = 1U;
        }
        if ((4U & (IData)(vlSelf->x))) {
            vlSelf->in = 1U;
        }
        if ((8U & (IData)(vlSelf->x))) {
            vlSelf->in = 1U;
        }
        if ((0x10U & (IData)(vlSelf->x))) {
            vlSelf->in = 1U;
        }
        if ((0x20U & (IData)(vlSelf->x))) {
            vlSelf->in = 1U;
        }
        if ((0x40U & (IData)(vlSelf->x))) {
            vlSelf->in = 1U;
        }
        vlSelf->y = 0U;
        if ((1U & (IData)(vlSelf->x))) {
            vlSelf->y = 0U;
        }
        if ((2U & (IData)(vlSelf->x))) {
            vlSelf->y = 1U;
        }
        if ((4U & (IData)(vlSelf->x))) {
            vlSelf->y = 2U;
        }
        if ((8U & (IData)(vlSelf->x))) {
            vlSelf->y = 3U;
        }
        if ((0x10U & (IData)(vlSelf->x))) {
            vlSelf->y = 4U;
        }
        if ((0x20U & (IData)(vlSelf->x))) {
            vlSelf->y = 5U;
        }
        if ((0x40U & (IData)(vlSelf->x))) {
            vlSelf->y = 6U;
        }
        if ((0x80U & (IData)(vlSelf->x))) {
            vlSelf->in = 1U;
            vlSelf->y = 7U;
        }
    } else {
        vlSelf->y = 0U;
    }
    __Vtableidx1 = vlSelf->y;
    vlSelf->bcd = Vencode83__ConstPool__TABLE_hb2a417e2_0
        [__Vtableidx1];
}

void Vencode83___024root___eval_nba(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vencode83___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vencode83___024root___eval_triggers__act(Vencode83___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode83___024root___dump_triggers__act(Vencode83___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode83___024root___dump_triggers__nba(Vencode83___024root* vlSelf);
#endif  // VL_DEBUG

void Vencode83___024root___eval(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
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
            Vencode83___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vencode83___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/eason/ysyx-workbench/npc/vsrc/encode83.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vencode83___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vencode83___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/eason/ysyx-workbench/npc/vsrc/encode83.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vencode83___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vencode83___024root___eval_debug_assertions(Vencode83___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode83___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
