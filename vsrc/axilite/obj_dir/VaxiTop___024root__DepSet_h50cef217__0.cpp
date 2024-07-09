// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VaxiTop.h for the primary calling header

#include "VaxiTop__pch.h"
#include "VaxiTop___024root.h"

void VaxiTop___024root___ico_sequent__TOP__0(VaxiTop___024root* vlSelf);

void VaxiTop___024root___eval_ico(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VaxiTop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VaxiTop___024root___ico_sequent__TOP__0(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->addr_s = ((IData)(vlSelf->wen) ? ((IData)(vlSelf->ren)
                                               ? 0U
                                               : vlSelf->axiTop__DOT__addr_r)
                       : ((IData)(vlSelf->ren) ? vlSelf->axiTop__DOT__addr_w
                           : 0U));
}

void VaxiTop___024root___eval_triggers__ico(VaxiTop___024root* vlSelf);

bool VaxiTop___024root___eval_phase__ico(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VaxiTop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VaxiTop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VaxiTop___024root___eval_act(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_act\n"); );
}

void VaxiTop___024root___nba_sequent__TOP__0(VaxiTop___024root* vlSelf);

void VaxiTop___024root___eval_nba(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VaxiTop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VaxiTop___024root___nba_sequent__TOP__0(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARADDR;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARADDR = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARVALID;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARVALID = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__cpu2axi__DOT__r_RREADY;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_RREADY = 0;
    IData/*31:0*/ __Vdly__axiTop__DOT__cpu2axi__DOT__r_WDATA;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_WDATA = 0;
    IData/*31:0*/ __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWADDR;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWADDR = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWVALID;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWVALID = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__cpu2axi__DOT__r_BREADY;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_BREADY = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__cpu2axi__DOT__r_WVALID;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_WVALID = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__axi2mem__DOT__r_ARREADY;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_ARREADY = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__axi2mem__DOT__r_RVALID;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_RVALID = 0;
    IData/*31:0*/ __Vdly__axiTop__DOT__axi2mem__DOT__r_RDATA;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_RDATA = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__axi2mem__DOT__r_AWREADY;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_AWREADY = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__axi2mem__DOT__r_WREADY;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_WREADY = 0;
    CData/*0:0*/ __Vdly__axiTop__DOT__axi2mem__DOT__r_BVALID;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_BVALID = 0;
    // Body
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARADDR = vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARADDR;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_WDATA = vlSelf->axiTop__DOT__cpu2axi__DOT__r_WDATA;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWADDR = vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWADDR;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_ARREADY = vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_RREADY = vlSelf->axiTop__DOT__cpu2axi__DOT__r_RREADY;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_RDATA = vlSelf->axiTop__DOT__axi2mem__DOT__r_RDATA;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_RVALID = vlSelf->axiTop__DOT__axi2mem__DOT__r_RVALID;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARVALID = vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_BREADY = vlSelf->axiTop__DOT__cpu2axi__DOT__r_BREADY;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_WVALID = vlSelf->axiTop__DOT__cpu2axi__DOT__r_WVALID;
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWVALID = vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWVALID;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_BVALID = vlSelf->axiTop__DOT__axi2mem__DOT__r_BVALID;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_AWREADY = vlSelf->axiTop__DOT__axi2mem__DOT__r_AWREADY;
    __Vdly__axiTop__DOT__axi2mem__DOT__r_WREADY = vlSelf->axiTop__DOT__axi2mem__DOT__r_WREADY;
    if (vlSelf->rst) {
        __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARADDR = 0U;
        __Vdly__axiTop__DOT__cpu2axi__DOT__r_WDATA = 0U;
        __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWADDR = 0U;
        vlSelf->axiTop__DOT__cpu2axi__DOT__r_RDATA = 0U;
        __Vdly__axiTop__DOT__cpu2axi__DOT__r_RREADY = 0U;
    } else {
        __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARADDR 
            = ((IData)(vlSelf->ren) ? vlSelf->addr_m
                : vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARADDR);
        if (vlSelf->wen) {
            __Vdly__axiTop__DOT__cpu2axi__DOT__r_WDATA 
                = vlSelf->write_data_m;
            __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWADDR 
                = vlSelf->addr_m;
        } else {
            __Vdly__axiTop__DOT__cpu2axi__DOT__r_WDATA 
                = vlSelf->axiTop__DOT__cpu2axi__DOT__r_WDATA;
            __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWADDR 
                = vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWADDR;
        }
        vlSelf->axiTop__DOT__cpu2axi__DOT__r_RDATA 
            = ((IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_RVALID)
                ? vlSelf->axiTop__DOT__axi2mem__DOT__r_RDATA
                : vlSelf->axiTop__DOT__cpu2axi__DOT__r_RDATA);
    }
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_RREADY = ((IData)(vlSelf->ren) 
                                                   | ((~ 
                                                       ((IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY) 
                                                        & (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID))) 
                                                      & (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_RREADY)));
    if (vlSelf->rst) {
        __Vdly__axiTop__DOT__axi2mem__DOT__r_RVALID = 0U;
        __Vdly__axiTop__DOT__axi2mem__DOT__r_RDATA = 0U;
        __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARVALID = 0U;
    } else if (((IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_RVALID) 
                & (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_RREADY))) {
        __Vdly__axiTop__DOT__axi2mem__DOT__r_RVALID = 0U;
    } else if (((IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID) 
                & (IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY))) {
        __Vdly__axiTop__DOT__axi2mem__DOT__r_RVALID = 1U;
        __Vdly__axiTop__DOT__axi2mem__DOT__r_RDATA 
            = vlSelf->read_data_s;
    } else {
        __Vdly__axiTop__DOT__axi2mem__DOT__r_RVALID 
            = vlSelf->axiTop__DOT__axi2mem__DOT__r_RVALID;
        __Vdly__axiTop__DOT__axi2mem__DOT__r_RDATA 
            = vlSelf->axiTop__DOT__axi2mem__DOT__r_RDATA;
    }
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARVALID = 
        ((IData)(vlSelf->ren) | ((~ ((IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY) 
                                     & (IData)(vlSelf->axiTop__DOT__m2s_ARVALID))) 
                                 & (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID)));
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_BREADY = (
                                                   (1U 
                                                    & (~ (IData)(vlSelf->rst))) 
                                                   && ((1U 
                                                        & (~ 
                                                           ((IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_BVALID) 
                                                            & (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_BREADY)))) 
                                                       && (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_BREADY)));
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_BREADY = (
                                                   (1U 
                                                    & (~ (IData)(vlSelf->rst))) 
                                                   && ((IData)(vlSelf->wen) 
                                                       || (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_BREADY)));
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_WVALID = (
                                                   (1U 
                                                    & (~ (IData)(vlSelf->rst))) 
                                                   && ((IData)(vlSelf->wen) 
                                                       || (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_WVALID)));
    __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWVALID = 
        ((1U & (~ (IData)(vlSelf->rst))) && ((IData)(vlSelf->wen) 
                                             || (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWVALID)));
    __Vdly__axiTop__DOT__axi2mem__DOT__r_BVALID = (
                                                   (1U 
                                                    & (~ (IData)(vlSelf->rst))) 
                                                   && ((1U 
                                                        & (~ 
                                                           ((IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_BVALID) 
                                                            & (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_BREADY)))) 
                                                       && (IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_BVALID)));
    __Vdly__axiTop__DOT__axi2mem__DOT__r_AWREADY = 
        ((1U & (~ (IData)(vlSelf->rst))) && ((IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWVALID) 
                                             || (IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_AWREADY)));
    __Vdly__axiTop__DOT__axi2mem__DOT__r_WREADY = (
                                                   (1U 
                                                    & (~ (IData)(vlSelf->rst))) 
                                                   && ((IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_WVALID) 
                                                       || (IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_WREADY)));
    if (vlSelf->rst) {
        __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWVALID = 0U;
        __Vdly__axiTop__DOT__axi2mem__DOT__r_ARREADY = 0U;
        vlSelf->axiTop__DOT__addr_r = 0U;
        __Vdly__axiTop__DOT__axi2mem__DOT__r_AWREADY = 0U;
        __Vdly__axiTop__DOT__axi2mem__DOT__r_BVALID = 0U;
        __Vdly__axiTop__DOT__axi2mem__DOT__r_WREADY = 0U;
        __Vdly__axiTop__DOT__axi2mem__DOT__r_WREADY = 0U;
    } else {
        if ((((IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWVALID) 
              & (IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_AWREADY)) 
             & ((IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_WREADY) 
                & (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_WVALID)))) {
            __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWVALID = 0U;
        } else {
            __Vdly__axiTop__DOT__cpu2axi__DOT__r_WVALID 
                = vlSelf->axiTop__DOT__cpu2axi__DOT__r_WVALID;
        }
        if (((IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID) 
             & (~ (IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY)))) {
            __Vdly__axiTop__DOT__axi2mem__DOT__r_ARREADY = 1U;
        } else if (((IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID) 
                    & (IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY))) {
            __Vdly__axiTop__DOT__axi2mem__DOT__r_ARREADY = 0U;
            vlSelf->axiTop__DOT__addr_r = vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARADDR;
        } else {
            __Vdly__axiTop__DOT__axi2mem__DOT__r_ARREADY 
                = vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY;
        }
        if ((((IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWVALID) 
              & (IData)(vlSelf->axiTop__DOT__axi2mem__DOT__r_AWREADY)) 
             & ((IData)(vlSelf->axiTop__DOT__s2m_WREADY) 
                & (IData)(vlSelf->axiTop__DOT__cpu2axi__DOT__r_WVALID)))) {
            __Vdly__axiTop__DOT__axi2mem__DOT__r_AWREADY = 0U;
            __Vdly__axiTop__DOT__axi2mem__DOT__r_WREADY = 0U;
            vlSelf->write_data_s = vlSelf->axiTop__DOT__cpu2axi__DOT__r_WDATA;
            __Vdly__axiTop__DOT__axi2mem__DOT__r_BVALID = 1U;
            vlSelf->axiTop__DOT__addr_w = vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWADDR;
        } else {
            __Vdly__axiTop__DOT__axi2mem__DOT__r_AWREADY 
                = vlSelf->axiTop__DOT__axi2mem__DOT__r_AWREADY;
            __Vdly__axiTop__DOT__axi2mem__DOT__r_BVALID 
                = vlSelf->axiTop__DOT__axi2mem__DOT__r_BVALID;
            __Vdly__axiTop__DOT__axi2mem__DOT__r_WREADY 
                = vlSelf->axiTop__DOT__axi2mem__DOT__r_WREADY;
        }
    }
    vlSelf->axiTop__DOT__axi2mem__DOT__r_RVALID = __Vdly__axiTop__DOT__axi2mem__DOT__r_RVALID;
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_RREADY = __Vdly__axiTop__DOT__cpu2axi__DOT__r_RREADY;
    vlSelf->axiTop__DOT__axi2mem__DOT__r_RDATA = __Vdly__axiTop__DOT__axi2mem__DOT__r_RDATA;
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_BREADY = __Vdly__axiTop__DOT__cpu2axi__DOT__r_BREADY;
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARADDR = __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARADDR;
    vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY = __Vdly__axiTop__DOT__axi2mem__DOT__r_ARREADY;
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID = __Vdly__axiTop__DOT__cpu2axi__DOT__r_ARVALID;
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_WDATA = __Vdly__axiTop__DOT__cpu2axi__DOT__r_WDATA;
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWADDR = __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWADDR;
    vlSelf->axiTop__DOT__axi2mem__DOT__r_AWREADY = __Vdly__axiTop__DOT__axi2mem__DOT__r_AWREADY;
    vlSelf->axiTop__DOT__axi2mem__DOT__r_BVALID = __Vdly__axiTop__DOT__axi2mem__DOT__r_BVALID;
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWVALID = __Vdly__axiTop__DOT__cpu2axi__DOT__r_AWVALID;
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_WVALID = __Vdly__axiTop__DOT__cpu2axi__DOT__r_WVALID;
    vlSelf->axiTop__DOT__axi2mem__DOT__r_WREADY = __Vdly__axiTop__DOT__axi2mem__DOT__r_WREADY;
    vlSelf->read_data_m = vlSelf->axiTop__DOT__cpu2axi__DOT__r_RDATA;
    vlSelf->axiTop__DOT__m2s_ARVALID = vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID;
    vlSelf->axiTop__DOT__s2m_WREADY = vlSelf->axiTop__DOT__axi2mem__DOT__r_WREADY;
    vlSelf->addr_s = ((IData)(vlSelf->wen) ? ((IData)(vlSelf->ren)
                                               ? 0U
                                               : vlSelf->axiTop__DOT__addr_r)
                       : ((IData)(vlSelf->ren) ? vlSelf->axiTop__DOT__addr_w
                           : 0U));
}

void VaxiTop___024root___eval_triggers__act(VaxiTop___024root* vlSelf);

bool VaxiTop___024root___eval_phase__act(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VaxiTop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VaxiTop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VaxiTop___024root___eval_phase__nba(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VaxiTop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VaxiTop___024root___dump_triggers__ico(VaxiTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VaxiTop___024root___dump_triggers__nba(VaxiTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VaxiTop___024root___dump_triggers__act(VaxiTop___024root* vlSelf);
#endif  // VL_DEBUG

void VaxiTop___024root___eval(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VaxiTop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("axiTop.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VaxiTop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VaxiTop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("axiTop.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VaxiTop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("axiTop.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VaxiTop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VaxiTop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VaxiTop___024root___eval_debug_assertions(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->wen & 0xfeU))) {
        Verilated::overWidthError("wen");}
    if (VL_UNLIKELY((vlSelf->ren & 0xfeU))) {
        Verilated::overWidthError("ren");}
}
#endif  // VL_DEBUG
