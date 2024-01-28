// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbutton.h"
#include "Vbutton__Syms.h"

//============================================================
// Constructors

Vbutton::Vbutton(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbutton__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , f{vlSymsp->TOP.f}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vbutton::Vbutton(const char* _vcname__)
    : Vbutton(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbutton::~Vbutton() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vbutton___024root___eval_debug_assertions(Vbutton___024root* vlSelf);
#endif  // VL_DEBUG
void Vbutton___024root___eval_static(Vbutton___024root* vlSelf);
void Vbutton___024root___eval_initial(Vbutton___024root* vlSelf);
void Vbutton___024root___eval_settle(Vbutton___024root* vlSelf);
void Vbutton___024root___eval(Vbutton___024root* vlSelf);

void Vbutton::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbutton::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbutton___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vbutton___024root___eval_static(&(vlSymsp->TOP));
        Vbutton___024root___eval_initial(&(vlSymsp->TOP));
        Vbutton___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vbutton___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vbutton::eventsPending() { return false; }

uint64_t Vbutton::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vbutton::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vbutton___024root___eval_final(Vbutton___024root* vlSelf);

VL_ATTR_COLD void Vbutton::final() {
    Vbutton___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbutton::hierName() const { return vlSymsp->name(); }
const char* Vbutton::modelName() const { return "Vbutton"; }
unsigned Vbutton::threads() const { return 1; }
