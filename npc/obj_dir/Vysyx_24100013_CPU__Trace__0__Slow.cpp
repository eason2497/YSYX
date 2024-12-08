// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_24100013_CPU__Syms.h"


VL_ATTR_COLD void Vysyx_24100013_CPU___024root__trace_init_sub__TOP__0(Vysyx_24100013_CPU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+43,"inst", false,-1, 31,0);
    tracep->declBus(c+44,"pc", false,-1, 31,0);
    tracep->declBus(c+45,"dnpc", false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_24100013_CPU ");
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+43,"inst", false,-1, 31,0);
    tracep->declBus(c+44,"pc", false,-1, 31,0);
    tracep->declBus(c+45,"dnpc", false,-1, 31,0);
    tracep->declBus(c+46,"rs1", false,-1, 4,0);
    tracep->declBus(c+47,"rs2", false,-1, 4,0);
    tracep->declBus(c+48,"rd", false,-1, 4,0);
    tracep->declBus(c+49,"funct3", false,-1, 2,0);
    tracep->declBus(c+50,"funct7", false,-1, 6,0);
    tracep->declBus(c+51,"opcode", false,-1, 6,0);
    tracep->declBit(c+61,"overflow", false,-1);
    tracep->declBit(c+62,"zero", false,-1);
    tracep->declBit(c+52,"carry", false,-1);
    tracep->declBit(c+63,"wen", false,-1);
    tracep->declBus(c+35,"src1", false,-1, 31,0);
    tracep->declBus(c+36,"src2", false,-1, 31,0);
    tracep->declBus(c+2,"result", false,-1, 31,0);
    tracep->declBus(c+37,"immtype", false,-1, 31,0);
    tracep->declBus(c+53,"imm", false,-1, 31,0);
    tracep->declBus(c+38,"itype", false,-1, 2,0);
    tracep->pushNamePrefix("alu0 ");
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+43,"inst", false,-1, 31,0);
    tracep->declBus(c+35,"src1", false,-1, 31,0);
    tracep->declBus(c+36,"src2", false,-1, 31,0);
    tracep->declBus(c+53,"imm", false,-1, 31,0);
    tracep->declBus(c+51,"opcode", false,-1, 6,0);
    tracep->declBus(c+44,"pc", false,-1, 31,0);
    tracep->declBus(c+2,"result", false,-1, 31,0);
    tracep->declBit(c+61,"overflow", false,-1);
    tracep->declBit(c+62,"zero", false,-1);
    tracep->declBit(c+52,"carry", false,-1);
    tracep->declBus(c+45,"dnpc", false,-1, 31,0);
    tracep->declBit(c+63,"wen", false,-1);
    tracep->declBus(c+54,"addi", false,-1, 31,0);
    tracep->declBus(c+53,"lui", false,-1, 31,0);
    tracep->declBus(c+55,"auipc", false,-1, 31,0);
    tracep->declBus(c+56,"jal", false,-1, 31,0);
    tracep->declBus(c+56,"jalr", false,-1, 31,0);
    tracep->declBus(c+55,"jal_record", false,-1, 31,0);
    tracep->declBus(c+57,"jalr_record", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("idu0 ");
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBus(c+43,"inst", false,-1, 31,0);
    tracep->declBus(c+46,"rs1", false,-1, 4,0);
    tracep->declBus(c+47,"rs2", false,-1, 4,0);
    tracep->declBus(c+48,"rd", false,-1, 4,0);
    tracep->declBus(c+51,"opcode", false,-1, 6,0);
    tracep->declBus(c+49,"funct3", false,-1, 2,0);
    tracep->declBus(c+50,"funct7", false,-1, 6,0);
    tracep->declBus(c+37,"outputtype", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu0 ");
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+44,"pc", false,-1, 31,0);
    tracep->declBus(c+43,"inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("imm0 ");
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBus(c+43,"inst", false,-1, 31,0);
    tracep->declBus(c+37,"intputtype", false,-1, 31,0);
    tracep->declBus(c+53,"imm", false,-1, 31,0);
    tracep->declBus(c+38,"itype", false,-1, 2,0);
    tracep->declBus(c+58,"immI", false,-1, 31,0);
    tracep->declBus(c+59,"immS", false,-1, 31,0);
    tracep->declBus(c+39,"immB", false,-1, 31,0);
    tracep->declBus(c+60,"immU", false,-1, 31,0);
    tracep->declBus(c+40,"immJ", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rf0 ");
    tracep->declBus(c+64,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+65,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBus(c+2,"wdata", false,-1, 31,0);
    tracep->declBus(c+48,"rd", false,-1, 4,0);
    tracep->declBus(c+46,"rs1", false,-1, 4,0);
    tracep->declBus(c+47,"rs2", false,-1, 4,0);
    tracep->declBit(c+63,"wen", false,-1);
    tracep->declBus(c+35,"src1", false,-1, 31,0);
    tracep->declBus(c+36,"src2", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+3+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root__trace_init_top(Vysyx_24100013_CPU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root__trace_init_top\n"); );
    // Body
    Vysyx_24100013_CPU___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_24100013_CPU___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_24100013_CPU___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_24100013_CPU___024root__trace_register(Vysyx_24100013_CPU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_24100013_CPU___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_24100013_CPU___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_24100013_CPU___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root__trace_full_sub_0(Vysyx_24100013_CPU___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_24100013_CPU___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_24100013_CPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24100013_CPU___024root*>(voidSelf);
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_24100013_CPU___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_24100013_CPU___024root__trace_full_sub_0(Vysyx_24100013_CPU___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_24100013_CPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24100013_CPU___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->ysyx_24100013_CPU__DOT__result),32);
    bufp->fullIData(oldp+3,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[0]),32);
    bufp->fullIData(oldp+4,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[1]),32);
    bufp->fullIData(oldp+5,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[2]),32);
    bufp->fullIData(oldp+6,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[3]),32);
    bufp->fullIData(oldp+7,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[4]),32);
    bufp->fullIData(oldp+8,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[5]),32);
    bufp->fullIData(oldp+9,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[6]),32);
    bufp->fullIData(oldp+10,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[7]),32);
    bufp->fullIData(oldp+11,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[8]),32);
    bufp->fullIData(oldp+12,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[9]),32);
    bufp->fullIData(oldp+13,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[10]),32);
    bufp->fullIData(oldp+14,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[11]),32);
    bufp->fullIData(oldp+15,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[12]),32);
    bufp->fullIData(oldp+16,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[13]),32);
    bufp->fullIData(oldp+17,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[14]),32);
    bufp->fullIData(oldp+18,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[15]),32);
    bufp->fullIData(oldp+19,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[16]),32);
    bufp->fullIData(oldp+20,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[17]),32);
    bufp->fullIData(oldp+21,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[18]),32);
    bufp->fullIData(oldp+22,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[19]),32);
    bufp->fullIData(oldp+23,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[20]),32);
    bufp->fullIData(oldp+24,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[21]),32);
    bufp->fullIData(oldp+25,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[22]),32);
    bufp->fullIData(oldp+26,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[23]),32);
    bufp->fullIData(oldp+27,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[24]),32);
    bufp->fullIData(oldp+28,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[25]),32);
    bufp->fullIData(oldp+29,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[26]),32);
    bufp->fullIData(oldp+30,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[27]),32);
    bufp->fullIData(oldp+31,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[28]),32);
    bufp->fullIData(oldp+32,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[29]),32);
    bufp->fullIData(oldp+33,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[30]),32);
    bufp->fullIData(oldp+34,(vlSelf->ysyx_24100013_CPU__DOT__rf0__DOT__rf[31]),32);
    bufp->fullIData(oldp+35,(vlSelf->ysyx_24100013_CPU__DOT__src1),32);
    bufp->fullIData(oldp+36,(vlSelf->ysyx_24100013_CPU__DOT__src2),32);
    bufp->fullIData(oldp+37,(vlSelf->ysyx_24100013_CPU__DOT__immtype),32);
    bufp->fullCData(oldp+38,((7U & vlSelf->ysyx_24100013_CPU__DOT__immtype)),3);
    bufp->fullIData(oldp+39,(vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immB),32);
    bufp->fullIData(oldp+40,(vlSelf->ysyx_24100013_CPU__DOT__imm0__DOT__immJ),32);
    bufp->fullBit(oldp+41,(vlSelf->clk));
    bufp->fullBit(oldp+42,(vlSelf->rst));
    bufp->fullIData(oldp+43,(vlSelf->inst),32);
    bufp->fullIData(oldp+44,(vlSelf->pc),32);
    bufp->fullIData(oldp+45,(vlSelf->dnpc),32);
    bufp->fullCData(oldp+46,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+47,((0x1fU & (vlSelf->inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+48,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+49,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullCData(oldp+50,((vlSelf->inst >> 0x19U)),7);
    bufp->fullCData(oldp+51,((0x7fU & vlSelf->inst)),7);
    bufp->fullBit(oldp+52,((1U & (IData)((1ULL & (((QData)((IData)(vlSelf->ysyx_24100013_CPU__DOT__src1)) 
                                                   + (QData)((IData)(vlSelf->ysyx_24100013_CPU__DOT__imm))) 
                                                  >> 0x20U))))));
    bufp->fullIData(oldp+53,(vlSelf->ysyx_24100013_CPU__DOT__imm),32);
    bufp->fullIData(oldp+54,(vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi),32);
    bufp->fullIData(oldp+55,(vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__auipc),32);
    bufp->fullIData(oldp+56,(((IData)(4U) + vlSelf->pc)),32);
    bufp->fullIData(oldp+57,((0xfffffffeU & vlSelf->ysyx_24100013_CPU__DOT__alu0__DOT__addi)),32);
    bufp->fullIData(oldp+58,((((- (IData)((vlSelf->inst 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->inst 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+59,(((0xfe0U & (vlSelf->inst 
                                         >> 0x14U)) 
                              | (0x1fU & (vlSelf->inst 
                                          >> 7U)))),32);
    bufp->fullIData(oldp+60,((0xfffff000U & vlSelf->inst)),32);
    bufp->fullBit(oldp+61,(vlSelf->ysyx_24100013_CPU__DOT__overflow));
    bufp->fullBit(oldp+62,(vlSelf->ysyx_24100013_CPU__DOT__zero));
    bufp->fullBit(oldp+63,(1U));
    bufp->fullIData(oldp+64,(5U),32);
    bufp->fullIData(oldp+65,(0x20U),32);
}
