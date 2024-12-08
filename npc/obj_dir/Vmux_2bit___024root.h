// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmux_2bit.h for the primary calling header

#ifndef VERILATED_VMUX_2BIT___024ROOT_H_
#define VERILATED_VMUX_2BIT___024ROOT_H_  // guard

#include "verilated.h"

class Vmux_2bit__Syms;

class Vmux_2bit___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(x0,1,0);
    VL_IN8(x1,1,0);
    VL_IN8(x2,1,0);
    VL_IN8(x3,1,0);
    VL_IN8(y,1,0);
    VL_OUT8(f,1,0);
    CData/*1:0*/ mux_2bit__DOT__i0__DOT__i0__DOT__lut_out;
    CData/*0:0*/ mux_2bit__DOT__i0__DOT__i0__DOT__hit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*3:0*/, 4> mux_2bit__DOT__i0__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*1:0*/, 4> mux_2bit__DOT__i0__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*1:0*/, 4> mux_2bit__DOT__i0__DOT__i0__DOT__data_list;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmux_2bit__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmux_2bit___024root(Vmux_2bit__Syms* symsp, const char* v__name);
    ~Vmux_2bit___024root();
    VL_UNCOPYABLE(Vmux_2bit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
