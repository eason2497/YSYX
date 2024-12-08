// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24100013_CPU.h for the primary calling header

#ifndef VERILATED_VYSYX_24100013_CPU___024ROOT_H_
#define VERILATED_VYSYX_24100013_CPU___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_24100013_CPU__Syms;

class Vysyx_24100013_CPU___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ ysyx_24100013_CPU__DOT__overflow;
    CData/*0:0*/ ysyx_24100013_CPU__DOT__zero;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    VL_OUT(inst,31,0);
    VL_OUT(pc,31,0);
    VL_OUT(dnpc,31,0);
    IData/*31:0*/ ysyx_24100013_CPU__DOT__src1;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__src2;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__result;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__immtype;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__imm;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__imm0__DOT__immB;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__imm0__DOT__immJ;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__alu0__DOT__addi;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__alu0__DOT__auipc;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__alu0__DOT__jal;
    IData/*31:0*/ ysyx_24100013_CPU__DOT__rf0__DOT__i;
    IData/*31:0*/ __Vfunc_ysyx_24100013_CPU__DOT__idu0__DOT__instruction_type_check__2__Vfuncout;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __Vtrigrprev__TOP__inst;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> ysyx_24100013_CPU__DOT__rf0__DOT__rf;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_24100013_CPU__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_24100013_CPU___024root(Vysyx_24100013_CPU__Syms* symsp, const char* v__name);
    ~Vysyx_24100013_CPU___024root();
    VL_UNCOPYABLE(Vysyx_24100013_CPU___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
