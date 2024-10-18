// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux_2bit.h for the primary calling header

#include "verilated.h"

#include "Vmux_2bit__Syms.h"
#include "Vmux_2bit___024root.h"

void Vmux_2bit___024root___ctor_var_reset(Vmux_2bit___024root* vlSelf);

Vmux_2bit___024root::Vmux_2bit___024root(Vmux_2bit__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmux_2bit___024root___ctor_var_reset(this);
}

void Vmux_2bit___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmux_2bit___024root::~Vmux_2bit___024root() {
}
