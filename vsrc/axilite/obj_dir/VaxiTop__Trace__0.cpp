// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VaxiTop__Syms.h"


void VaxiTop___024root__trace_chg_0_sub_0(VaxiTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VaxiTop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root__trace_chg_0\n"); );
    // Init
    VaxiTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VaxiTop___024root*>(voidSelf);
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VaxiTop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VaxiTop___024root__trace_chg_0_sub_0(VaxiTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARADDR),32);
        bufp->chgBit(oldp+1,(vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID));
        bufp->chgBit(oldp+2,(vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY));
        bufp->chgIData(oldp+3,(vlSelf->axiTop__DOT__axi2mem__DOT__r_RDATA),32);
        bufp->chgBit(oldp+4,(vlSelf->axiTop__DOT__axi2mem__DOT__r_RVALID));
        bufp->chgBit(oldp+5,(vlSelf->axiTop__DOT__cpu2axi__DOT__r_RREADY));
        bufp->chgIData(oldp+6,(vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWADDR),32);
        bufp->chgBit(oldp+7,(vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWVALID));
        bufp->chgBit(oldp+8,(vlSelf->axiTop__DOT__axi2mem__DOT__r_AWREADY));
        bufp->chgIData(oldp+9,(vlSelf->axiTop__DOT__addr_w),32);
        bufp->chgIData(oldp+10,(vlSelf->axiTop__DOT__addr_r),32);
        bufp->chgIData(oldp+11,(vlSelf->axiTop__DOT__cpu2axi__DOT__r_WDATA),32);
        bufp->chgBit(oldp+12,(vlSelf->axiTop__DOT__cpu2axi__DOT__r_WVALID));
        bufp->chgBit(oldp+13,(vlSelf->axiTop__DOT__axi2mem__DOT__r_WREADY));
        bufp->chgBit(oldp+14,(vlSelf->axiTop__DOT__axi2mem__DOT__r_BVALID));
        bufp->chgBit(oldp+15,(vlSelf->axiTop__DOT__cpu2axi__DOT__r_BREADY));
        bufp->chgIData(oldp+16,(vlSelf->axiTop__DOT__cpu2axi__DOT__r_RDATA),32);
    }
    bufp->chgBit(oldp+17,(vlSelf->clk));
    bufp->chgBit(oldp+18,(vlSelf->rst));
    bufp->chgIData(oldp+19,(vlSelf->read_data_m),32);
    bufp->chgIData(oldp+20,(vlSelf->addr_m),32);
    bufp->chgIData(oldp+21,(vlSelf->write_data_m),32);
    bufp->chgBit(oldp+22,(vlSelf->wen));
    bufp->chgBit(oldp+23,(vlSelf->ren));
    bufp->chgIData(oldp+24,(vlSelf->read_data_s),32);
    bufp->chgIData(oldp+25,(vlSelf->addr_s),32);
    bufp->chgIData(oldp+26,(vlSelf->write_data_s),32);
    bufp->chgCData(oldp+27,((((IData)(vlSelf->wen) 
                              << 1U) | (IData)(vlSelf->ren))),2);
}

void VaxiTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root__trace_cleanup\n"); );
    // Init
    VaxiTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VaxiTop___024root*>(voidSelf);
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
