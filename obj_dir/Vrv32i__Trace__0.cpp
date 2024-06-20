// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrv32i__Syms.h"


void Vrv32i___024root__trace_chg_0_sub_0(Vrv32i___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vrv32i___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root__trace_chg_0\n"); );
    // Init
    Vrv32i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrv32i___024root*>(voidSelf);
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vrv32i___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vrv32i___024root__trace_chg_0_sub_0(Vrv32i___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->rv32i__DOT__ReadData),32);
        bufp->chgIData(oldp+1,(vlSelf->rv32i__DOT__mask),32);
        bufp->chgBit(oldp+2,(vlSelf->rv32i__DOT__rv__DOT__ALUSrcE));
        bufp->chgBit(oldp+3,(vlSelf->rv32i__DOT__rv__DOT__RegWriteW));
        bufp->chgBit(oldp+4,(vlSelf->rv32i__DOT__rv__DOT__RegWriteM));
        bufp->chgBit(oldp+5,((0U == vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult)));
        bufp->chgBit(oldp+6,((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcE))));
        bufp->chgBit(oldp+7,(vlSelf->rv32i__DOT__rv__DOT__loadW));
        bufp->chgBit(oldp+8,(((1U == vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult) 
                              & ((IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE) 
                                 >> 3U))));
        bufp->chgBit(oldp+9,(vlSelf->rv32i__DOT__rv__DOT__jarlW));
        bufp->chgCData(oldp+10,(vlSelf->rv32i__DOT__rv__DOT__ResultSrcW),2);
        bufp->chgCData(oldp+11,(vlSelf->rv32i__DOT__rv__DOT__ALUControlE),4);
        bufp->chgCData(oldp+12,(vlSelf->rv32i__DOT__rv__DOT__SDypeSecM),2);
        bufp->chgCData(oldp+13,(vlSelf->rv32i__DOT__rv__DOT__ForWordAE),2);
        bufp->chgCData(oldp+14,(vlSelf->rv32i__DOT__rv__DOT__ForWordBE),2);
        bufp->chgCData(oldp+15,(vlSelf->rv32i__DOT__rv__DOT__RdW),5);
        bufp->chgCData(oldp+16,(vlSelf->rv32i__DOT__rv__DOT__RdM),5);
        bufp->chgCData(oldp+17,(vlSelf->rv32i__DOT__rv__DOT__RdE),5);
        bufp->chgCData(oldp+18,(vlSelf->rv32i__DOT__rv__DOT__Rs1E),5);
        bufp->chgCData(oldp+19,(vlSelf->rv32i__DOT__rv__DOT__Rs2E),5);
        bufp->chgCData(oldp+20,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcE),2);
        bufp->chgCData(oldp+21,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcM),2);
        bufp->chgBit(oldp+22,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__JumpE));
        bufp->chgBit(oldp+23,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__BranchE));
        bufp->chgBit(oldp+24,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlE));
        bufp->chgBit(oldp+25,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlM));
        bufp->chgCData(oldp+26,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__SDypeSecE),2);
        bufp->chgCData(oldp+27,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__funct3E),3);
        bufp->chgBit(oldp+28,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__RegWriteE));
        bufp->chgBit(oldp+29,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__MemWriteE));
        bufp->chgBit(oldp+30,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadE));
        bufp->chgBit(oldp+31,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadM));
        bufp->chgBit(oldp+32,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__branchScr));
        bufp->chgIData(oldp+33,((vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE 
                                 + vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE)),32);
        bufp->chgIData(oldp+34,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCD),32);
        bufp->chgIData(oldp+35,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE),32);
        bufp->chgIData(oldp+36,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4E),32);
        bufp->chgIData(oldp+37,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4M),32);
        bufp->chgIData(oldp+38,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4W),32);
        bufp->chgIData(oldp+39,(((IData)(vlSelf->rv32i__DOT__rv__DOT__jarlW)
                                  ? (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE 
                                     + vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE)
                                  : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW)),32);
        bufp->chgIData(oldp+40,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE),32);
        bufp->chgIData(oldp+41,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult),32);
        bufp->chgIData(oldp+42,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW),32);
        bufp->chgIData(oldp+43,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataM),32);
        bufp->chgIData(oldp+44,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE),32);
        bufp->chgIData(oldp+45,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE),32);
        bufp->chgIData(oldp+46,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD1E),32);
        bufp->chgIData(oldp+47,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD2E),32);
        bufp->chgIData(oldp+48,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW),32);
        bufp->chgIData(oldp+49,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataE),32);
        bufp->chgIData(oldp+50,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ReadDataW),32);
        bufp->chgIData(oldp+51,(((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                                  ? (~ vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)
                                  : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)),32);
        bufp->chgIData(oldp+52,((vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                                 + (((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                                      ? (~ vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)
                                      : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE) 
                                    + (1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))))),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+53,((7U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                       >> 0xaU))),3);
        bufp->chgCData(oldp+54,((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+55,((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                          >> 0x14U))),5);
        bufp->chgIData(oldp+56,(vlSelf->rv32i__DOT__rv__DOT__InstrD),32);
        bufp->chgCData(oldp+57,((0x7fU & vlSelf->rv32i__DOT__rv__DOT__InstrD)),7);
        bufp->chgCData(oldp+58,((7U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+59,((1U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                     >> 0x1eU))));
        bufp->chgCData(oldp+60,((3U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                       >> 3U))),2);
        bufp->chgCData(oldp+61,((3U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                       >> 6U))),2);
        bufp->chgBit(oldp+62,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                     >> 5U))));
        bufp->chgBit(oldp+63,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                     >> 2U))));
        bufp->chgBit(oldp+64,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                     >> 9U))));
        bufp->chgBit(oldp+65,((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls))));
        bufp->chgCData(oldp+66,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ALUControlD),4);
        bufp->chgCData(oldp+67,(((0U == (7U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                               >> 0xcU)))
                                  ? 0U : ((1U == (7U 
                                                  & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                     >> 0xcU)))
                                           ? 1U : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                        >> 0xcU)))
                                                    ? 2U
                                                    : 0U)))),2);
        bufp->chgBit(oldp+68,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                     >> 0xdU))));
        bufp->chgBit(oldp+69,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                     >> 8U))));
        bufp->chgBit(oldp+70,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                     >> 1U))));
        bufp->chgBit(oldp+71,((1U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                     >> 5U))));
        bufp->chgBit(oldp+72,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ad__DOT__RtypeSub));
        bufp->chgSData(oldp+73,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls),14);
        bufp->chgIData(oldp+74,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4D),32);
        bufp->chgIData(oldp+75,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtD),32);
        bufp->chgCData(oldp+76,((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                          >> 7U))),5);
        bufp->chgIData(oldp+77,((vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                 >> 7U)),25);
        bufp->chgIData(oldp+78,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[0]),32);
        bufp->chgIData(oldp+79,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[1]),32);
        bufp->chgIData(oldp+80,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[2]),32);
        bufp->chgIData(oldp+81,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[3]),32);
        bufp->chgIData(oldp+82,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[4]),32);
        bufp->chgIData(oldp+83,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[5]),32);
        bufp->chgIData(oldp+84,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[6]),32);
        bufp->chgIData(oldp+85,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[7]),32);
        bufp->chgIData(oldp+86,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[8]),32);
        bufp->chgIData(oldp+87,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[9]),32);
        bufp->chgIData(oldp+88,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[10]),32);
        bufp->chgIData(oldp+89,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[11]),32);
        bufp->chgIData(oldp+90,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[12]),32);
        bufp->chgIData(oldp+91,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[13]),32);
        bufp->chgIData(oldp+92,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[14]),32);
        bufp->chgIData(oldp+93,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[15]),32);
        bufp->chgIData(oldp+94,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[16]),32);
        bufp->chgIData(oldp+95,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[17]),32);
        bufp->chgIData(oldp+96,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[18]),32);
        bufp->chgIData(oldp+97,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[19]),32);
        bufp->chgIData(oldp+98,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[20]),32);
        bufp->chgIData(oldp+99,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[21]),32);
        bufp->chgIData(oldp+100,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[22]),32);
        bufp->chgIData(oldp+101,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[23]),32);
        bufp->chgIData(oldp+102,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[24]),32);
        bufp->chgIData(oldp+103,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[25]),32);
        bufp->chgIData(oldp+104,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[26]),32);
        bufp->chgIData(oldp+105,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[27]),32);
        bufp->chgIData(oldp+106,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[28]),32);
        bufp->chgIData(oldp+107,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[29]),32);
        bufp->chgIData(oldp+108,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[30]),32);
        bufp->chgIData(oldp+109,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+110,(vlSelf->rv32i__DOT__PC),32);
        bufp->chgIData(oldp+111,(vlSelf->rv32i__DOT__Instr),32);
        bufp->chgBit(oldp+112,(vlSelf->rv32i__DOT__rv__DOT__PCSrcE));
        bufp->chgIData(oldp+113,(((IData)(4U) + vlSelf->rv32i__DOT__PC)),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgBit(oldp+114,(vlSelf->rv32i__DOT__rv__DOT__stallD));
        bufp->chgBit(oldp+115,(vlSelf->rv32i__DOT__rv__DOT__stallF));
        bufp->chgBit(oldp+116,(vlSelf->rv32i__DOT__rv__DOT__FlushE));
        bufp->chgIData(oldp+117,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg),32);
        bufp->chgBit(oldp+118,((1U & (~ (IData)(vlSelf->rv32i__DOT__rv__DOT__stallD)))));
        bufp->chgBit(oldp+119,((1U & (~ (IData)(vlSelf->rv32i__DOT__rv__DOT__stallF)))));
        bufp->chgBit(oldp+120,(vlSelf->rv32i__DOT__rv__DOT__hu__DOT__lwStall));
    }
    bufp->chgBit(oldp+121,(vlSelf->clk));
    bufp->chgBit(oldp+122,(vlSelf->reset));
    bufp->chgIData(oldp+123,(vlSelf->WriteData),32);
    bufp->chgIData(oldp+124,(vlSelf->DataAdr),32);
    bufp->chgBit(oldp+125,(vlSelf->MemWrite));
    bufp->chgIData(oldp+126,(vlSelf->rv32i__DOT__dmem__DOT__unnamedblk1__DOT__masked_data),32);
    bufp->chgIData(oldp+127,(((IData)(vlSelf->rv32i__DOT__rv__DOT__PCSrcE)
                               ? ((IData)(vlSelf->rv32i__DOT__rv__DOT__jarlW)
                                   ? (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE 
                                      + vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE)
                                   : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW)
                               : ((IData)(4U) + vlSelf->rv32i__DOT__PC))),32);
    bufp->chgIData(oldp+128,((((IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteW) 
                               & ((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                            >> 0xfU)) 
                                  == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdW)))
                               ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg
                               : ((0U == (0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                   >> 0xfU)))
                                   ? 0U : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf
                                  [(0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                             >> 0xfU))]))),32);
    bufp->chgIData(oldp+129,((((IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteW) 
                               & ((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                            >> 0x14U)) 
                                  == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdW)))
                               ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg
                               : ((0U == (0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                   >> 0x14U)))
                                   ? 0U : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf
                                  [(0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                             >> 0x14U))]))),32);
    bufp->chgCData(oldp+130,((3U & vlSelf->DataAdr)),2);
    bufp->chgBit(oldp+131,((1U & (~ (IData)(vlSelf->clk)))));
}

void Vrv32i___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root__trace_cleanup\n"); );
    // Init
    Vrv32i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrv32i___024root*>(voidSelf);
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
