// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vencode83.h for the primary calling header

#ifndef VERILATED_VENCODE83___024ROOT_H_
#define VERILATED_VENCODE83___024ROOT_H_  // guard

#include "verilated.h"

class Vencode83__Syms;

class Vencode83___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(en,0,0);
    VL_IN8(x,7,0);
    VL_OUT8(y,3,0);
    VL_OUT8(in,0,0);
    VL_OUT8(bcd,6,0);
    CData/*0:0*/ __Vtrigrprev__TOP__en;
    CData/*7:0*/ __Vtrigrprev__TOP__x;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ encode83__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vencode83__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vencode83___024root(Vencode83__Syms* symsp, const char* v__name);
    ~Vencode83___024root();
    VL_UNCOPYABLE(Vencode83___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
