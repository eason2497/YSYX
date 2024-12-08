// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_24100013_CPU__Syms.h"


void Vysyx_24100013_CPU___024root__trace_chg_sub_0(Vysyx_24100013_CPU___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_24100013_CPU___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_24100013_CPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24100013_CPU___024root*>(voidSelf);
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_24100013_CPU___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_24100013_CPU___024root__trace_chg_sub_0(Vysyx_24100013_CPU___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+1,(vlSelf->ysyx_24100013_CPU__DOT__result),32);
        bufp->chgIData(oldp+2,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0]),32);
        bufp->chgIData(oldp+3,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[1]),32);
        bufp->chgIData(oldp+4,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[2]),32);
        bufp->chgIData(oldp+5,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[3]),32);
        bufp->chgIData(oldp+6,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[4]),32);
        bufp->chgIData(oldp+7,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[5]),32);
        bufp->chgIData(oldp+8,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[6]),32);
        bufp->chgIData(oldp+9,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[7]),32);
        bufp->chgIData(oldp+10,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[8]),32);
        bufp->chgIData(oldp+11,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[9]),32);
        bufp->chgIData(oldp+12,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[10]),32);
        bufp->chgIData(oldp+13,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[11]),32);
        bufp->chgIData(oldp+14,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[12]),32);
        bufp->chgIData(oldp+15,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[13]),32);
        bufp->chgIData(oldp+16,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[14]),32);
        bufp->chgIData(oldp+17,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[15]),32);
        bufp->chgIData(oldp+18,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[16]),32);
        bufp->chgIData(oldp+19,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[17]),32);
        bufp->chgIData(oldp+20,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[18]),32);
        bufp->chgIData(oldp+21,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[19]),32);
        bufp->chgIData(oldp+22,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[20]),32);
        bufp->chgIData(oldp+23,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[21]),32);
        bufp->chgIData(oldp+24,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[22]),32);
        bufp->chgIData(oldp+25,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[23]),32);
        bufp->chgIData(oldp+26,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[24]),32);
        bufp->chgIData(oldp+27,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[25]),32);
        bufp->chgIData(oldp+28,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[26]),32);
        bufp->chgIData(oldp+29,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[27]),32);
        bufp->chgIData(oldp+30,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[28]),32);
        bufp->chgIData(oldp+31,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[29]),32);
        bufp->chgIData(oldp+32,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[30]),32);
        bufp->chgIData(oldp+33,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+34,(vlSelf->ysyx_24100013_CPU__DOT__src1),32);
        bufp->chgIData(oldp+35,(vlSelf->ysyx_24100013_CPU__DOT__src2),32);
        bufp->chgIData(oldp+36,(vlSelf->ysyx_24100013_CPU__DOT__immtype),32);
        bufp->chgCData(oldp+37,((7U & vlSelf->ysyx_24100013_CPU__DOT__immtype)),3);
        bufp->chgIData(oldp+38,(vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immB),32);
        bufp->chgIData(oldp+39,(vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immJ),32);
    }
    bufp->chgBit(oldp+40,(vlSelf->clk));
    bufp->chgBit(oldp+41,(vlSelf->rst));
    bufp->chgIData(oldp+42,(vlSelf->inst),32);
    bufp->chgIData(oldp+43,(vlSelf->pc),32);
    bufp->chgIData(oldp+44,(vlSelf->dnpc),32);
    bufp->chgCData(oldp+45,((0x1fU & (vlSelf->inst 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+46,((0x1fU & (vlSelf->inst 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+47,((0x1fU & (vlSelf->inst 
                                      >> 7U))),5);
    bufp->chgCData(oldp+48,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->chgCData(oldp+49,((vlSelf->inst >> 0x19U)),7);
    bufp->chgCData(oldp+50,((0x7fU & vlSelf->inst)),7);
    bufp->chgBit(oldp+51,((1U & (IData)((1ULL & (((QData)((IData)(vlSelf->ysyx_24100013_CPU__DOT__src1)) 
                                                  + (QData)((IData)(vlSelf->ysyx_24100013_CPU__DOT__imm))) 
                                                 >> 0x20U))))));
    bufp->chgIData(oldp+52,(vlSelf->ysyx_24100013_CPU__DOT__imm),32);
    bufp->chgIData(oldp+53,(vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi),32);
    bufp->chgIData(oldp+54,(vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__auipc),32);
    bufp->chgIData(oldp+55,(((IData)(4U) + vlSelf->pc)),32);
    bufp->chgIData(oldp+56,((0xfffffffeU & vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi)),32);
    bufp->chgIData(oldp+57,((((- (IData)((vlSelf->inst 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelf->inst 
                                          >> 0x14U))),32);
    bufp->chgIData(oldp+58,(((0xfe0U & (vlSelf->inst 
                                        >> 0x14U)) 
                             | (0x1fU & (vlSelf->inst 
                                         >> 7U)))),32);
    bufp->chgIData(oldp+59,((0xfffff000U & vlSelf->inst)),32);
}

void Vysyx_24100013_CPU___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root__trace_cleanup\n"); );
    // Init
    Vysyx_24100013_CPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24100013_CPU___024root*>(voidSelf);
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
