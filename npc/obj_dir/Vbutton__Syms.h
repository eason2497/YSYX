// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBUTTON__SYMS_H_
#define VERILATED_VBUTTON__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vbutton.h"

// INCLUDE MODULE CLASSES
#include "Vbutton___024root.h"

// SYMS CLASS (contains all model state)
class Vbutton__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vbutton* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vbutton___024root              TOP;

    // CONSTRUCTORS
    Vbutton__Syms(VerilatedContext* contextp, const char* namep, Vbutton* modelp);
    ~Vbutton__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
