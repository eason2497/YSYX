// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24100013_CPU.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_24100013_CPU__Syms.h"
#include "Vysyx_24100013_CPU___024root.h"

void Vysyx_24100013_CPU___024root___ctor_var_reset(Vysyx_24100013_CPU___024root* vlSelf);

Vysyx_24100013_CPU___024root::Vysyx_24100013_CPU___024root(Vysyx_24100013_CPU__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vysyx_24100013_CPU___024root___ctor_var_reset(this);
}

void Vysyx_24100013_CPU___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vysyx_24100013_CPU___024root::~Vysyx_24100013_CPU___024root() {
}
