// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbutton.h for the primary calling header

#include "verilated.h"

#include "Vbutton__Syms.h"
#include "Vbutton___024root.h"

void Vbutton___024root___ctor_var_reset(Vbutton___024root* vlSelf);

Vbutton___024root::Vbutton___024root(Vbutton__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vbutton___024root___ctor_var_reset(this);
}

void Vbutton___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vbutton___024root::~Vbutton___024root() {
}
