// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vysyx_24100013_CPU.h"
#include "Vysyx_24100013_CPU__Syms.h"
#include "verilated_vcd_c.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

Vysyx_24100013_CPU::Vysyx_24100013_CPU(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vysyx_24100013_CPU__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , inst{vlSymsp->TOP.inst}
    , pc{vlSymsp->TOP.pc}
    , dnpc{vlSymsp->TOP.dnpc}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vysyx_24100013_CPU::Vysyx_24100013_CPU(const char* _vcname__)
    : Vysyx_24100013_CPU(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vysyx_24100013_CPU::~Vysyx_24100013_CPU() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vysyx_24100013_CPU___024root___eval_debug_assertions(Vysyx_24100013_CPU___024root* vlSelf);
#endif  // VL_DEBUG
void Vysyx_24100013_CPU___024root___eval_static(Vysyx_24100013_CPU___024root* vlSelf);
void Vysyx_24100013_CPU___024root___eval_initial(Vysyx_24100013_CPU___024root* vlSelf);
void Vysyx_24100013_CPU___024root___eval_settle(Vysyx_24100013_CPU___024root* vlSelf);
void Vysyx_24100013_CPU___024root___eval(Vysyx_24100013_CPU___024root* vlSelf);

void Vysyx_24100013_CPU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vysyx_24100013_CPU::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vysyx_24100013_CPU___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vysyx_24100013_CPU___024root___eval_static(&(vlSymsp->TOP));
        Vysyx_24100013_CPU___024root___eval_initial(&(vlSymsp->TOP));
        Vysyx_24100013_CPU___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vysyx_24100013_CPU___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vysyx_24100013_CPU::eventsPending() { return false; }

uint64_t Vysyx_24100013_CPU::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vysyx_24100013_CPU::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vysyx_24100013_CPU___024root___eval_final(Vysyx_24100013_CPU___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24100013_CPU::final() {
    Vysyx_24100013_CPU___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vysyx_24100013_CPU::hierName() const { return vlSymsp->name(); }
const char* Vysyx_24100013_CPU::modelName() const { return "Vysyx_24100013_CPU"; }
unsigned Vysyx_24100013_CPU::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vysyx_24100013_CPU::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vysyx_24100013_CPU___024root__trace_init_top(Vysyx_24100013_CPU___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vysyx_24100013_CPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24100013_CPU___024root*>(voidSelf);
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vysyx_24100013_CPU___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root__trace_register(Vysyx_24100013_CPU___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vysyx_24100013_CPU::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vysyx_24100013_CPU::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vysyx_24100013_CPU___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
