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
        bufp->chgIData(oldp+0,(vlSelf->rv32i__DOT__write_d),32);
        bufp->chgIData(oldp+1,(vlSelf->rv32i__DOT__axi__DOT__s2m_RDATA),32);
        bufp->chgBit(oldp+2,(vlSelf->rv32i__DOT__axi__DOT__axi2mem__DOT__r_RVALID));
        bufp->chgBit(oldp+3,(vlSelf->rv32i__DOT__axi__DOT__cpu2axi__DOT__r_RREADY));
        bufp->chgIData(oldp+4,(vlSelf->rv32i__DOT__axi__DOT__cpu2axi__DOT__r_AWADDR),32);
        bufp->chgBit(oldp+5,(vlSelf->rv32i__DOT__axi__DOT__cpu2axi__DOT__r_AWVALID));
        bufp->chgBit(oldp+6,(vlSelf->rv32i__DOT__axi__DOT__axi2mem__DOT__r_AWREADY));
        bufp->chgIData(oldp+7,(vlSelf->rv32i__DOT__axi__DOT__addr_w),32);
        bufp->chgIData(oldp+8,(vlSelf->rv32i__DOT__axi__DOT__cpu2axi__DOT__r_WDATA),32);
        bufp->chgBit(oldp+9,(vlSelf->rv32i__DOT__axi__DOT__cpu2axi__DOT__r_WVALID));
        bufp->chgBit(oldp+10,(vlSelf->rv32i__DOT__axi__DOT__axi2mem__DOT__r_WREADY));
        bufp->chgBit(oldp+11,(vlSelf->rv32i__DOT__axi__DOT__cpu2axi__DOT__r_BREADY));
        bufp->chgBit(oldp+12,(vlSelf->rv32i__DOT__axi__DOT__axi2mem__DOT__r_BVALID));
        bufp->chgBit(oldp+13,(vlSelf->rv32i__DOT__rv__DOT__ALUSrcE));
        bufp->chgCData(oldp+14,(vlSelf->rv32i__DOT__rv__DOT__ResultSrcE),2);
        bufp->chgBit(oldp+15,(vlSelf->rv32i__DOT__rv__DOT__loadW));
        bufp->chgBit(oldp+16,(vlSelf->rv32i__DOT__rv__DOT__jarlW));
        bufp->chgCData(oldp+17,(vlSelf->rv32i__DOT__rv__DOT__ResultSrcW),2);
        bufp->chgCData(oldp+18,(vlSelf->rv32i__DOT__rv__DOT__ResultSrcM),2);
        bufp->chgCData(oldp+19,(vlSelf->rv32i__DOT__rv__DOT__ALUControlE),4);
        bufp->chgCData(oldp+20,(vlSelf->rv32i__DOT__rv__DOT__Rs1E),5);
        bufp->chgCData(oldp+21,(vlSelf->rv32i__DOT__rv__DOT__Rs2E),5);
        bufp->chgBit(oldp+22,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__JumpE));
        bufp->chgBit(oldp+23,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__BranchE));
        bufp->chgBit(oldp+24,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlE));
        bufp->chgBit(oldp+25,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlM));
        bufp->chgCData(oldp+26,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__funct3E),3);
        bufp->chgBit(oldp+27,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadE));
        bufp->chgBit(oldp+28,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadM));
        bufp->chgIData(oldp+29,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCTargetW),32);
        bufp->chgIData(oldp+30,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCTargetM),32);
        bufp->chgIData(oldp+31,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4E),32);
        bufp->chgIData(oldp+32,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4M),32);
        bufp->chgIData(oldp+33,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4W),32);
        bufp->chgIData(oldp+34,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE),32);
        bufp->chgIData(oldp+35,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW),32);
        bufp->chgIData(oldp+36,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataM),32);
        bufp->chgIData(oldp+37,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD1E),32);
        bufp->chgIData(oldp+38,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD2E),32);
        bufp->chgIData(oldp+39,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW),32);
        bufp->chgIData(oldp+40,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ReadDataW),32);
        bufp->chgCData(oldp+41,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__fun3E),3);
        bufp->chgCData(oldp+42,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__fun3M),3);
        bufp->chgCData(oldp+43,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__fun3W),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+44,(vlSelf->rv32i__DOT__Instr_s),32);
        bufp->chgIData(oldp+45,(vlSelf->rv32i__DOT__dmem__DOT__unnamedblk1__DOT__masked_data),32);
        bufp->chgIData(oldp+46,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4D),32);
        bufp->chgIData(oldp+47,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[0]),32);
        bufp->chgIData(oldp+48,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[1]),32);
        bufp->chgIData(oldp+49,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[2]),32);
        bufp->chgIData(oldp+50,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[3]),32);
        bufp->chgIData(oldp+51,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[4]),32);
        bufp->chgIData(oldp+52,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[5]),32);
        bufp->chgIData(oldp+53,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[6]),32);
        bufp->chgIData(oldp+54,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[7]),32);
        bufp->chgIData(oldp+55,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[8]),32);
        bufp->chgIData(oldp+56,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[9]),32);
        bufp->chgIData(oldp+57,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[10]),32);
        bufp->chgIData(oldp+58,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[11]),32);
        bufp->chgIData(oldp+59,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[12]),32);
        bufp->chgIData(oldp+60,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[13]),32);
        bufp->chgIData(oldp+61,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[14]),32);
        bufp->chgIData(oldp+62,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[15]),32);
        bufp->chgIData(oldp+63,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[16]),32);
        bufp->chgIData(oldp+64,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[17]),32);
        bufp->chgIData(oldp+65,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[18]),32);
        bufp->chgIData(oldp+66,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[19]),32);
        bufp->chgIData(oldp+67,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[20]),32);
        bufp->chgIData(oldp+68,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[21]),32);
        bufp->chgIData(oldp+69,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[22]),32);
        bufp->chgIData(oldp+70,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[23]),32);
        bufp->chgIData(oldp+71,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[24]),32);
        bufp->chgIData(oldp+72,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[25]),32);
        bufp->chgIData(oldp+73,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[26]),32);
        bufp->chgIData(oldp+74,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[27]),32);
        bufp->chgIData(oldp+75,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[28]),32);
        bufp->chgIData(oldp+76,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[29]),32);
        bufp->chgIData(oldp+77,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[30]),32);
        bufp->chgIData(oldp+78,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+79,(vlSelf->rv32i__DOT__PC_m),32);
        bufp->chgIData(oldp+80,(vlSelf->rv32i__DOT__axi__DOT__addr_r),32);
        bufp->chgIData(oldp+81,(vlSelf->rv32i__DOT__ReadData),32);
        bufp->chgBit(oldp+82,(vlSelf->rv32i__DOT__re));
        bufp->chgIData(oldp+83,(vlSelf->rv32i__DOT__axi__DOT__cpu2axi__DOT__r_ARADDR),32);
        bufp->chgBit(oldp+84,(vlSelf->rv32i__DOT__axi__DOT__cpu2axi__DOT__r_ARVALID));
        bufp->chgBit(oldp+85,(vlSelf->rv32i__DOT__axi__DOT__axi2mem__DOT__r_ARREADY));
        bufp->chgBit(oldp+86,(vlSelf->rv32i__DOT__rv__DOT__RegWriteW));
        bufp->chgBit(oldp+87,(vlSelf->rv32i__DOT__rv__DOT__RegWriteM));
        bufp->chgBit(oldp+88,((0U == vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult)));
        bufp->chgCData(oldp+89,(vlSelf->rv32i__DOT__rv__DOT__SDypeSecM),2);
        bufp->chgCData(oldp+90,(vlSelf->rv32i__DOT__rv__DOT__ForWordAE),2);
        bufp->chgCData(oldp+91,(vlSelf->rv32i__DOT__rv__DOT__ForWordBE),2);
        bufp->chgCData(oldp+92,(vlSelf->rv32i__DOT__rv__DOT__RdW),5);
        bufp->chgCData(oldp+93,(vlSelf->rv32i__DOT__rv__DOT__RdM),5);
        bufp->chgCData(oldp+94,(vlSelf->rv32i__DOT__rv__DOT__RdE),5);
        bufp->chgCData(oldp+95,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__SDypeSecE),2);
        bufp->chgBit(oldp+96,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__RegWriteE));
        bufp->chgBit(oldp+97,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__MemWriteE));
        bufp->chgBit(oldp+98,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__branchScr));
        bufp->chgIData(oldp+99,(((IData)(4U) + vlSelf->rv32i__DOT__PC_m)),32);
        bufp->chgIData(oldp+100,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCTargetE),32);
        bufp->chgIData(oldp+101,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCD),32);
        bufp->chgIData(oldp+102,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE),32);
        bufp->chgIData(oldp+103,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult),32);
        bufp->chgIData(oldp+104,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE),32);
        bufp->chgIData(oldp+105,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE),32);
        bufp->chgIData(oldp+106,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataE),32);
        bufp->chgIData(oldp+107,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgCData(oldp+108,((7U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                        >> 0xaU))),3);
        bufp->chgCData(oldp+109,((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+110,((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                           >> 0x14U))),5);
        bufp->chgIData(oldp+111,(vlSelf->rv32i__DOT__rv__DOT__InstrD),32);
        bufp->chgCData(oldp+112,((0x7fU & vlSelf->rv32i__DOT__rv__DOT__InstrD)),7);
        bufp->chgCData(oldp+113,((7U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                        >> 0xcU))),3);
        bufp->chgBit(oldp+114,((1U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                      >> 0x1eU))));
        bufp->chgCData(oldp+115,((3U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                        >> 3U))),2);
        bufp->chgCData(oldp+116,((3U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                        >> 6U))),2);
        bufp->chgBit(oldp+117,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                      >> 5U))));
        bufp->chgBit(oldp+118,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                      >> 2U))));
        bufp->chgBit(oldp+119,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                      >> 9U))));
        bufp->chgBit(oldp+120,((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls))));
        bufp->chgCData(oldp+121,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ALUControlD),4);
        bufp->chgCData(oldp+122,(((2U == (7U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                >> 0xcU)))
                                   ? 0U : ((1U == (7U 
                                                   & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                      >> 0xcU)))
                                            ? 1U : 
                                           ((0U == 
                                             (7U & 
                                              (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                               >> 0xcU)))
                                             ? 2U : 0U)))),2);
        bufp->chgBit(oldp+123,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                      >> 0xdU))));
        bufp->chgBit(oldp+124,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                      >> 8U))));
        bufp->chgBit(oldp+125,((1U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                      >> 1U))));
        bufp->chgBit(oldp+126,((1U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                      >> 5U))));
        bufp->chgBit(oldp+127,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ad__DOT__RtypeSub));
        bufp->chgSData(oldp+128,(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls),14);
        bufp->chgIData(oldp+129,(vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtD),32);
        bufp->chgCData(oldp+130,((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                           >> 7U))),5);
        bufp->chgIData(oldp+131,((vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                  >> 7U)),25);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgBit(oldp+132,(vlSelf->rv32i__DOT__rv__DOT__stallD));
        bufp->chgBit(oldp+133,(vlSelf->rv32i__DOT__rv__DOT__stallF));
        bufp->chgBit(oldp+134,(vlSelf->rv32i__DOT__rv__DOT__FlushE));
        bufp->chgBit(oldp+135,((1U & (~ (IData)(vlSelf->rv32i__DOT__rv__DOT__stallD)))));
        bufp->chgBit(oldp+136,((1U & (~ (IData)(vlSelf->rv32i__DOT__rv__DOT__stallF)))));
        bufp->chgBit(oldp+137,(vlSelf->rv32i__DOT__rv__DOT__hu__DOT__lwStall));
    }
    bufp->chgBit(oldp+138,(vlSelf->clk));
    bufp->chgBit(oldp+139,(vlSelf->reset));
    bufp->chgIData(oldp+140,(vlSelf->WriteData),32);
    bufp->chgIData(oldp+141,(vlSelf->DataAdr),32);
    bufp->chgBit(oldp+142,(vlSelf->MemWrite));
    bufp->chgIData(oldp+143,(vlSelf->rv32i__DOT__axi__DOT__cpu2axi__DOT__r_RDATA),32);
    bufp->chgIData(oldp+144,(((0U == (IData)(vlSelf->rv32i__DOT__rv__DOT__SDypeSecM))
                               ? 0xffffffffU : ((1U 
                                                 == (IData)(vlSelf->rv32i__DOT__rv__DOT__SDypeSecM))
                                                 ? 
                                                VL_SHIFTL_III(32,32,32, (IData)(0xffffU), 
                                                              VL_SHIFTL_III(32,32,32, 
                                                                            (1U 
                                                                             & (vlSelf->DataAdr 
                                                                                >> 1U)), 3U))
                                                 : 
                                                ((2U 
                                                  == (IData)(vlSelf->rv32i__DOT__rv__DOT__SDypeSecM))
                                                  ? 
                                                 VL_SHIFTL_III(32,32,32, (IData)(0xffU), 
                                                               VL_SHIFTL_III(32,32,32, 
                                                                             (3U 
                                                                              & vlSelf->DataAdr), 3U))
                                                  : 0U)))),32);
    bufp->chgBit(oldp+145,(vlSelf->rv32i__DOT__rv__DOT__PCSrcE));
    bufp->chgBit(oldp+146,(((1U == vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult) 
                            & ((IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE) 
                               >> 3U))));
    bufp->chgIData(oldp+147,(((IData)(vlSelf->rv32i__DOT__rv__DOT__PCSrcE)
                               ? ((IData)(vlSelf->rv32i__DOT__rv__DOT__jarlW)
                                   ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW
                                   : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCTargetE)
                               : ((IData)(4U) + vlSelf->rv32i__DOT__PC_m))),32);
    bufp->chgIData(oldp+148,(((IData)(vlSelf->rv32i__DOT__rv__DOT__jarlW)
                               ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW
                               : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCTargetE)),32);
    bufp->chgIData(oldp+149,((((IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteW) 
                               & ((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                            >> 0xfU)) 
                                  == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdW)))
                               ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg
                               : ((0U == (0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                   >> 0xfU)))
                                   ? 0U : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf
                                  [(0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                             >> 0xfU))]))),32);
    bufp->chgIData(oldp+150,((((IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteW) 
                               & ((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                            >> 0x14U)) 
                                  == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdW)))
                               ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg
                               : ((0U == (0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                   >> 0x14U)))
                                   ? 0U : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf
                                  [(0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                             >> 0x14U))]))),32);
    bufp->chgCData(oldp+151,((3U & vlSelf->DataAdr)),2);
    bufp->chgIData(oldp+152,(((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                               ? (~ vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)
                               : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)),32);
    bufp->chgIData(oldp+153,((vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                              + (((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                                   ? (~ vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)
                                   : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE) 
                                 + (1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))))),32);
    bufp->chgBit(oldp+154,((1U & (~ (IData)(vlSelf->clk)))));
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
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
