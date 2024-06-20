// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrv32i.h for the primary calling header

#include "Vrv32i__pch.h"
#include "Vrv32i___024root.h"

VL_ATTR_COLD void Vrv32i___024root___eval_static(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vrv32i___024root___eval_initial__TOP(Vrv32i___024root* vlSelf);

VL_ATTR_COLD void Vrv32i___024root___eval_initial(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_initial\n"); );
    // Body
    Vrv32i___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
}

VL_ATTR_COLD void Vrv32i___024root___eval_initial__TOP(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[0U] = 0U;
}

VL_ATTR_COLD void Vrv32i___024root___eval_final(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__stl(Vrv32i___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vrv32i___024root___eval_phase__stl(Vrv32i___024root* vlSelf);

VL_ATTR_COLD void Vrv32i___024root___eval_settle(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_settle\n"); );
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
            Vrv32i___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/rv32i.v", 15, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vrv32i___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__stl(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vrv32i___024root___stl_sequent__TOP__0(Vrv32i___024root* vlSelf);

VL_ATTR_COLD void Vrv32i___024root___eval_stl(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vrv32i___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__rv__DOT__dp__DOT__handle_ebreak_TOP();
void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__imem__DOT__read_imem_TOP(IData/*31:0*/ addr, IData/*31:0*/ &read_imem__Vfuncrtn);
void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__read_dmem_TOP(IData/*31:0*/ addr, IData/*31:0*/ &read_dmem__Vfuncrtn);
extern const VlUnpacked<SData/*13:0*/, 128> Vrv32i__ConstPool__TABLE_h5f27bdaa_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vrv32i__ConstPool__TABLE_ha204d35e_0;

VL_ATTR_COLD void Vrv32i___024root___stl_sequent__TOP__0(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___stl_sequent__TOP__0\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if ((0x100073U == vlSelf->rv32i__DOT__rv__DOT__InstrD)) {
            Vrv32i___024root____Vdpiimwrap_rv32i__DOT__rv__DOT__dp__DOT__handle_ebreak_TOP();
        }
    }
    if ((0U == (IData)(vlSelf->rv32i__DOT__rv__DOT__SDypeSecM))) {
        vlSelf->rv32i__DOT__mask = 0xffffffffU;
        vlSelf->WriteData = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataM;
    } else if ((1U == (IData)(vlSelf->rv32i__DOT__rv__DOT__SDypeSecM))) {
        vlSelf->rv32i__DOT__mask = VL_SHIFTL_III(32,32,32, (IData)(0xffffU), 
                                                 VL_SHIFTL_III(32,32,32, 
                                                               (1U 
                                                                & (vlSelf->DataAdr 
                                                                   >> 1U)), 3U));
        vlSelf->WriteData = VL_SHIFTL_III(32,32,32, vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataM, 
                                          VL_SHIFTL_III(32,32,32, 
                                                        (1U 
                                                         & (vlSelf->DataAdr 
                                                            >> 1U)), 3U));
    } else if ((2U == (IData)(vlSelf->rv32i__DOT__rv__DOT__SDypeSecM))) {
        vlSelf->rv32i__DOT__mask = VL_SHIFTL_III(32,32,32, (IData)(0xffU), 
                                                 VL_SHIFTL_III(32,32,32, 
                                                               (3U 
                                                                & vlSelf->DataAdr), 3U));
        vlSelf->WriteData = VL_SHIFTL_III(32,32,32, vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataM, 
                                          VL_SHIFTL_III(32,32,32, 
                                                        (3U 
                                                         & vlSelf->DataAdr), 3U));
    } else {
        vlSelf->rv32i__DOT__mask = 0U;
        vlSelf->WriteData = 0U;
    }
    Vrv32i___024root____Vdpiimwrap_rv32i__DOT__imem__DOT__read_imem_TOP(vlSelf->rv32i__DOT__PC, vlSelf->__Vfunc_rv32i__DOT__imem__DOT__read_imem__1__Vfuncout);
    vlSelf->rv32i__DOT__Instr = vlSelf->__Vfunc_rv32i__DOT__imem__DOT__read_imem__1__Vfuncout;
    Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__read_dmem_TOP(vlSelf->DataAdr, vlSelf->__Vfunc_rv32i__DOT__dmem__DOT__read_dmem__2__Vfuncout);
    vlSelf->rv32i__DOT__ReadData = vlSelf->__Vfunc_rv32i__DOT__dmem__DOT__read_dmem__2__Vfuncout;
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__ad__DOT__RtypeSub 
        = (IData)((0x40000020U == (0x40000020U & vlSelf->rv32i__DOT__rv__DOT__InstrD)));
    vlSelf->__Vtableidx1 = (0x7fU & vlSelf->rv32i__DOT__rv__DOT__InstrD);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls 
        = Vrv32i__ConstPool__TABLE_h5f27bdaa_0[vlSelf->__Vtableidx1];
    vlSelf->rv32i__DOT__rv__DOT__ForWordAE = (((((IData)(vlSelf->rv32i__DOT__rv__DOT__Rs1E) 
                                                 == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdM)) 
                                                & (IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteM)) 
                                               & (0U 
                                                  != (IData)(vlSelf->rv32i__DOT__rv__DOT__Rs1E)))
                                               ? 2U
                                               : ((
                                                   (((IData)(vlSelf->rv32i__DOT__rv__DOT__Rs1E) 
                                                     == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdW)) 
                                                    & (IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteW)) 
                                                   & (0U 
                                                      != (IData)(vlSelf->rv32i__DOT__rv__DOT__Rs1E)))
                                                   ? 1U
                                                   : 0U));
    vlSelf->rv32i__DOT__rv__DOT__ForWordBE = (((((IData)(vlSelf->rv32i__DOT__rv__DOT__Rs2E) 
                                                 == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdM)) 
                                                & (IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteM)) 
                                               & (0U 
                                                  != (IData)(vlSelf->rv32i__DOT__rv__DOT__Rs2E)))
                                               ? 2U
                                               : ((
                                                   (((IData)(vlSelf->rv32i__DOT__rv__DOT__Rs2E) 
                                                     == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdW)) 
                                                    & (IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteW)) 
                                                   & (0U 
                                                      != (IData)(vlSelf->rv32i__DOT__rv__DOT__Rs2E)))
                                                   ? 1U
                                                   : 0U));
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW = 
        ((2U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ResultSrcW))
          ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4W
          : ((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ResultSrcW))
              ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ReadDataW
              : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW));
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtD = 
        ((0x1000U & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls))
          ? ((0x800U & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls))
              ? 0U : ((0x400U & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls))
                       ? 0U : (0xfffff000U & vlSelf->rv32i__DOT__rv__DOT__InstrD)))
          : ((0x800U & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls))
              ? ((0x400U & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls))
                  ? (((- (IData)((vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                  >> 0x1fU))) << 0x14U) 
                     | ((0xff000U & vlSelf->rv32i__DOT__rv__DOT__InstrD) 
                        | ((0x800U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                      >> 9U)) | (0x7feU 
                                                 & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                    >> 0x14U)))))
                  : (((- (IData)((vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                  >> 0x1fU))) << 0xcU) 
                     | ((0x800U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                   << 4U)) | ((0x7e0U 
                                               & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                    >> 7U))))))
              : ((0x400U & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls))
                  ? (((- (IData)((vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                  >> 0x1fU))) << 0xcU) 
                     | ((0xfe0U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                    >> 7U))))
                  : (((- (IData)((vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                  >> 0x1fU))) << 0xcU) 
                     | (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                        >> 0x14U)))));
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__ALUControlD 
        = ((0U == (3U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                         >> 3U))) ? 0U : ((1U == (3U 
                                                  & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                                     >> 3U)))
                                           ? ((0x4000U 
                                               & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                               ? ((0x2000U 
                                                   & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                    ? 2U
                                                    : 3U)
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                    ? 0U
                                                    : 4U))
                                               : ((0x2000U 
                                                   & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                    ? 8U
                                                    : 0U)
                                                   : 1U))
                                           : ((0x4000U 
                                               & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                               ? ((0x2000U 
                                                   & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                    ? 2U
                                                    : 3U)
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                    ? 
                                                   ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ad__DOT__RtypeSub)
                                                     ? 5U
                                                     : 7U)
                                                    : 4U))
                                               : ((0x2000U 
                                                   & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                    ? 8U
                                                    : 9U)
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                                                    ? 6U
                                                    : 
                                                   ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ad__DOT__RtypeSub)
                                                     ? 1U
                                                     : 0U))))));
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg 
        = ((IData)(vlSelf->rv32i__DOT__rv__DOT__loadW)
            ? ((0x4000U & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                ? ((0x2000U & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                    ? 0U : ((0x1000U & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                             ? (0xffffU & vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW)
                             : (0xffU & vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW)))
                : ((0x2000U & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                    ? ((0x1000U & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                        ? 0U : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW)
                    : ((0x1000U & vlSelf->rv32i__DOT__rv__DOT__InstrD)
                        ? (((- (IData)((1U & (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW))
                        : (((- (IData)((1U & (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW)))))
            : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE = (
                                                   (2U 
                                                    & (IData)(vlSelf->rv32i__DOT__rv__DOT__ForWordAE))
                                                    ? vlSelf->DataAdr
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->rv32i__DOT__rv__DOT__ForWordAE))
                                                     ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW
                                                     : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD1E));
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataE 
        = ((2U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ForWordBE))
            ? vlSelf->DataAdr : ((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ForWordBE))
                                  ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW
                                  : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD2E));
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE = ((IData)(vlSelf->rv32i__DOT__rv__DOT__ALUSrcE)
                                                    ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE
                                                    : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataE);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult 
        = ((8U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
            ? ((4U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                ? 0U : ((2U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                         ? 0U : ((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                                  ? (VL_LTS_III(32, vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE, vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)
                                      ? 1U : 0U) : 
                                 ((vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                                   < vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)
                                   ? 1U : 0U)))) : 
           ((4U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
             ? ((2U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                 ? ((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                     ? (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                        >> (0x1fU & vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE))
                     : (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                        << (0x1fU & vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)))
                 : ((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                     ? (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                        >> (0x1fU & vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE))
                     : (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                        ^ vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)))
             : ((2U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                 ? ((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                     ? (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                        | vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)
                     : (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                        & vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE))
                 : (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE 
                    + (((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))
                         ? (~ vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE)
                         : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE) 
                       + (1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE)))))));
    vlSelf->__Vtableidx2 = (((0U == vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult) 
                             << 4U) | ((0xfffffff8U 
                                        & (((1U == vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult) 
                                            << 3U) 
                                           & (IData)(vlSelf->rv32i__DOT__rv__DOT__ALUControlE))) 
                                       | (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__funct3E)));
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__branchScr 
        = Vrv32i__ConstPool__TABLE_ha204d35e_0[vlSelf->__Vtableidx2];
    vlSelf->rv32i__DOT__rv__DOT__PCSrcE = (((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__BranchE) 
                                            & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__branchScr)) 
                                           | (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__JumpE));
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCFNext = 
        ((IData)(vlSelf->rv32i__DOT__rv__DOT__PCSrcE)
          ? ((IData)(vlSelf->rv32i__DOT__rv__DOT__jarlW)
              ? (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE 
                 + vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE)
              : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW)
          : ((IData)(4U) + vlSelf->rv32i__DOT__PC));
    vlSelf->rv32i__DOT__rv__DOT__hu__DOT__lwStall = 
        ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcE) 
         & (((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                       >> 0xfU)) == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdE)) 
            | ((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                         >> 0x14U)) == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdE))));
    vlSelf->rv32i__DOT__rv__DOT__FlushE = ((IData)(vlSelf->rv32i__DOT__rv__DOT__hu__DOT__lwStall) 
                                           | (IData)(vlSelf->rv32i__DOT__rv__DOT__PCSrcE));
    vlSelf->rv32i__DOT__rv__DOT__stallD = vlSelf->rv32i__DOT__rv__DOT__hu__DOT__lwStall;
    vlSelf->rv32i__DOT__rv__DOT__stallF = vlSelf->rv32i__DOT__rv__DOT__hu__DOT__lwStall;
}

VL_ATTR_COLD void Vrv32i___024root___eval_triggers__stl(Vrv32i___024root* vlSelf);

VL_ATTR_COLD bool Vrv32i___024root___eval_phase__stl(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vrv32i___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vrv32i___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__ico(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__act(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__nba(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vrv32i___024root___ctor_var_reset(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->WriteData = VL_RAND_RESET_I(32);
    vlSelf->DataAdr = VL_RAND_RESET_I(32);
    vlSelf->MemWrite = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__Instr = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__ReadData = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__mask = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__ALUSrcE = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__RegWriteW = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__RegWriteM = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__stallD = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__stallF = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__FlushE = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__loadW = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__jarlW = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__PCSrcE = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__ResultSrcW = VL_RAND_RESET_I(2);
    vlSelf->rv32i__DOT__rv__DOT__ALUControlE = VL_RAND_RESET_I(4);
    vlSelf->rv32i__DOT__rv__DOT__SDypeSecM = VL_RAND_RESET_I(2);
    vlSelf->rv32i__DOT__rv__DOT__ForWordAE = VL_RAND_RESET_I(2);
    vlSelf->rv32i__DOT__rv__DOT__ForWordBE = VL_RAND_RESET_I(2);
    vlSelf->rv32i__DOT__rv__DOT__RdW = VL_RAND_RESET_I(5);
    vlSelf->rv32i__DOT__rv__DOT__RdM = VL_RAND_RESET_I(5);
    vlSelf->rv32i__DOT__rv__DOT__RdE = VL_RAND_RESET_I(5);
    vlSelf->rv32i__DOT__rv__DOT__Rs1E = VL_RAND_RESET_I(5);
    vlSelf->rv32i__DOT__rv__DOT__Rs2E = VL_RAND_RESET_I(5);
    vlSelf->rv32i__DOT__rv__DOT__InstrD = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcE = VL_RAND_RESET_I(2);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcM = VL_RAND_RESET_I(2);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__JumpE = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__BranchE = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlE = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlM = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__ALUControlD = VL_RAND_RESET_I(4);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__SDypeSecE = VL_RAND_RESET_I(2);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__funct3E = VL_RAND_RESET_I(3);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__RegWriteE = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__MemWriteE = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadE = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadM = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__branchScr = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls = VL_RAND_RESET_I(14);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__ad__DOT__RtypeSub = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCFNext = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCD = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4D = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4E = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4M = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4W = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtD = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataM = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcAE = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__SrcBE = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD1E = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD2E = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataE = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ReadDataW = VL_RAND_RESET_I(32);
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->rv32i__DOT__rv__DOT__hu__DOT__lwStall = VL_RAND_RESET_I(1);
    vlSelf->rv32i__DOT__dmem__DOT__unnamedblk1__DOT__masked_data = 0;
    vlSelf->__Vfunc_rv32i__DOT__imem__DOT__read_imem__1__Vfuncout = 0;
    vlSelf->__Vfunc_rv32i__DOT__dmem__DOT__read_dmem__2__Vfuncout = 0;
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtableidx2 = 0;
    vlSelf->__Vdlyvdim0__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0 = 0;
    vlSelf->__Vdlyvval__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0 = VL_RAND_RESET_I(32);
    vlSelf->__Vdlyvset__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
