// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VaxiTop.h for the primary calling header

#include "VaxiTop__pch.h"
#include "VaxiTop___024root.h"

VL_ATTR_COLD void VaxiTop___024root___eval_static(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_static\n"); );
}

VL_ATTR_COLD void VaxiTop___024root___eval_initial(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void VaxiTop___024root___eval_final(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VaxiTop___024root___dump_triggers__stl(VaxiTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VaxiTop___024root___eval_phase__stl(VaxiTop___024root* vlSelf);

VL_ATTR_COLD void VaxiTop___024root___eval_settle(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VaxiTop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("axiTop.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VaxiTop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VaxiTop___024root___dump_triggers__stl(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VaxiTop___024root___stl_sequent__TOP__0(VaxiTop___024root* vlSelf);

VL_ATTR_COLD void VaxiTop___024root___eval_stl(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VaxiTop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VaxiTop___024root___stl_sequent__TOP__0(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->read_data_m = vlSelf->axiTop__DOT__cpu2axi__DOT__r_RDATA;
    vlSelf->axiTop__DOT__m2s_ARVALID = vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID;
    vlSelf->axiTop__DOT__s2m_WREADY = vlSelf->axiTop__DOT__axi2mem__DOT__r_WREADY;
    vlSelf->addr_s = ((IData)(vlSelf->wen) ? ((IData)(vlSelf->ren)
                                               ? 0U
                                               : vlSelf->axiTop__DOT__addr_r)
                       : ((IData)(vlSelf->ren) ? vlSelf->axiTop__DOT__addr_w
                           : 0U));
}

VL_ATTR_COLD void VaxiTop___024root___eval_triggers__stl(VaxiTop___024root* vlSelf);

VL_ATTR_COLD bool VaxiTop___024root___eval_phase__stl(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VaxiTop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VaxiTop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VaxiTop___024root___dump_triggers__ico(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ vlSelf->__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VaxiTop___024root___dump_triggers__act(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VaxiTop___024root___dump_triggers__nba(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VaxiTop___024root___ctor_var_reset(VaxiTop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VaxiTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaxiTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->read_data_m = VL_RAND_RESET_I(32);
    vlSelf->addr_m = VL_RAND_RESET_I(32);
    vlSelf->write_data_m = VL_RAND_RESET_I(32);
    vlSelf->wen = VL_RAND_RESET_I(1);
    vlSelf->ren = VL_RAND_RESET_I(1);
    vlSelf->read_data_s = VL_RAND_RESET_I(32);
    vlSelf->addr_s = VL_RAND_RESET_I(32);
    vlSelf->write_data_s = VL_RAND_RESET_I(32);
    vlSelf->axiTop__DOT__m2s_ARVALID = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__addr_w = VL_RAND_RESET_I(32);
    vlSelf->axiTop__DOT__addr_r = VL_RAND_RESET_I(32);
    vlSelf->axiTop__DOT__s2m_WREADY = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARVALID = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_WDATA = VL_RAND_RESET_I(32);
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_RDATA = VL_RAND_RESET_I(32);
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWADDR = VL_RAND_RESET_I(32);
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_AWVALID = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_ARADDR = VL_RAND_RESET_I(32);
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_BREADY = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_WVALID = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__cpu2axi__DOT__r_RREADY = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__axi2mem__DOT__r_ARREADY = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__axi2mem__DOT__r_RDATA = VL_RAND_RESET_I(32);
    vlSelf->axiTop__DOT__axi2mem__DOT__r_RVALID = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__axi2mem__DOT__r_AWREADY = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__axi2mem__DOT__r_BVALID = VL_RAND_RESET_I(1);
    vlSelf->axiTop__DOT__axi2mem__DOT__r_WREADY = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
