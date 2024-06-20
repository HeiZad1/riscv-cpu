// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrv32i.h for the primary calling header

#include "Vrv32i__pch.h"
#include "Vrv32i___024root.h"

void Vrv32i___024root___ico_sequent__TOP__0(Vrv32i___024root* vlSelf);

void Vrv32i___024root___eval_ico(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vrv32i___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__rv__DOT__dp__DOT__handle_ebreak_TOP();

VL_INLINE_OPT void Vrv32i___024root___ico_sequent__TOP__0(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___ico_sequent__TOP__0\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if ((0x100073U == vlSelf->rv32i__DOT__rv__DOT__InstrD)) {
            Vrv32i___024root____Vdpiimwrap_rv32i__DOT__rv__DOT__dp__DOT__handle_ebreak_TOP();
        }
    }
}

void Vrv32i___024root___eval_triggers__ico(Vrv32i___024root* vlSelf);

bool Vrv32i___024root___eval_phase__ico(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vrv32i___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vrv32i___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vrv32i___024root___eval_act(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_act\n"); );
}

void Vrv32i___024root___nba_sequent__TOP__0(Vrv32i___024root* vlSelf);
void Vrv32i___024root___nba_sequent__TOP__1(Vrv32i___024root* vlSelf);
void Vrv32i___024root___nba_sequent__TOP__2(Vrv32i___024root* vlSelf);
void Vrv32i___024root___nba_sequent__TOP__3(Vrv32i___024root* vlSelf);
void Vrv32i___024root___nba_comb__TOP__0(Vrv32i___024root* vlSelf);

void Vrv32i___024root___eval_nba(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vrv32i___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vrv32i___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vrv32i___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vrv32i___024root___nba_sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vrv32i___024root___nba_comb__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
}

void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__read_dmem_TOP(IData/*31:0*/ addr, IData/*31:0*/ &read_dmem__Vfuncrtn);
void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__write_dmem_TOP(IData/*31:0*/ addr, IData/*31:0*/ data);

VL_INLINE_OPT void Vrv32i___024root___nba_sequent__TOP__0(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vfunc_rv32i__DOT__dmem__DOT__read_dmem__3__Vfuncout;
    __Vfunc_rv32i__DOT__dmem__DOT__read_dmem__3__Vfuncout = 0;
    // Body
    vlSelf->__Vdlyvset__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0 = 0U;
    vlSelf->rv32i__DOT__dmem__DOT__unnamedblk1__DOT__masked_data 
        = ((([&]() {
                    Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__read_dmem_TOP(vlSelf->DataAdr, __Vfunc_rv32i__DOT__dmem__DOT__read_dmem__3__Vfuncout);
                }(), __Vfunc_rv32i__DOT__dmem__DOT__read_dmem__3__Vfuncout) 
            & (~ vlSelf->rv32i__DOT__mask)) | (vlSelf->WriteData 
                                               & vlSelf->rv32i__DOT__mask));
    if (vlSelf->MemWrite) {
        Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__write_dmem_TOP(vlSelf->DataAdr, vlSelf->rv32i__DOT__dmem__DOT__unnamedblk1__DOT__masked_data);
    }
    if (((IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteW) 
         & (0U != (IData)(vlSelf->rv32i__DOT__rv__DOT__RdW)))) {
        vlSelf->__Vdlyvval__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0 
            = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg;
        vlSelf->__Vdlyvset__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0 = 1U;
        vlSelf->__Vdlyvdim0__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0 
            = vlSelf->rv32i__DOT__rv__DOT__RdW;
    }
}

extern const VlUnpacked<CData/*0:0*/, 32> Vrv32i__ConstPool__TABLE_ha204d35e_0;

VL_INLINE_OPT void Vrv32i___024root___nba_sequent__TOP__1(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__BranchE = 
        (1U & ((~ (IData)(vlSelf->reset)) & ((~ (IData)(vlSelf->rv32i__DOT__rv__DOT__FlushE)) 
                                             & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                                >> 5U))));
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__JumpE = (1U 
                                                  & ((~ (IData)(vlSelf->reset)) 
                                                     & ((~ (IData)(vlSelf->rv32i__DOT__rv__DOT__FlushE)) 
                                                        & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                                           >> 2U))));
    vlSelf->rv32i__DOT__rv__DOT__ALUSrcE = (1U & ((~ (IData)(vlSelf->reset)) 
                                                  & ((~ (IData)(vlSelf->rv32i__DOT__rv__DOT__FlushE)) 
                                                     & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                                        >> 9U))));
    vlSelf->rv32i__DOT__rv__DOT__loadW = ((~ (IData)(vlSelf->reset)) 
                                          & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadM));
    vlSelf->rv32i__DOT__rv__DOT__jarlW = ((~ (IData)(vlSelf->reset)) 
                                          & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlM));
    vlSelf->MemWrite = ((~ (IData)(vlSelf->reset)) 
                        & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__MemWriteE));
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadM = ((~ (IData)(vlSelf->reset)) 
                                                  & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadE));
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlM = ((~ (IData)(vlSelf->reset)) 
                                                  & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlE));
    if (vlSelf->reset) {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataM = 0U;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE = 0U;
        vlSelf->rv32i__DOT__rv__DOT__ALUControlE = 0U;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ReadDataW = 0U;
        vlSelf->rv32i__DOT__rv__DOT__c__DOT__funct3E = 0U;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE = 0U;
        vlSelf->rv32i__DOT__rv__DOT__Rs1E = 0U;
        vlSelf->rv32i__DOT__rv__DOT__Rs2E = 0U;
        vlSelf->rv32i__DOT__rv__DOT__SDypeSecM = 0U;
        vlSelf->rv32i__DOT__rv__DOT__ResultSrcW = 0U;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4W = 0U;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW = 0U;
    } else {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataM 
            = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__WriteDataE;
        if (vlSelf->rv32i__DOT__rv__DOT__FlushE) {
            vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE = 0U;
            vlSelf->rv32i__DOT__rv__DOT__ALUControlE = 0U;
            vlSelf->rv32i__DOT__rv__DOT__c__DOT__funct3E = 0U;
            vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE = 0U;
            vlSelf->rv32i__DOT__rv__DOT__Rs1E = 0U;
            vlSelf->rv32i__DOT__rv__DOT__Rs2E = 0U;
        } else {
            vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE 
                = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtD;
            vlSelf->rv32i__DOT__rv__DOT__ALUControlE 
                = vlSelf->rv32i__DOT__rv__DOT__c__DOT__ALUControlD;
            vlSelf->rv32i__DOT__rv__DOT__c__DOT__funct3E 
                = (7U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                         >> 0xcU));
            vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE 
                = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCD;
            vlSelf->rv32i__DOT__rv__DOT__Rs1E = (0x1fU 
                                                 & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                    >> 0xfU));
            vlSelf->rv32i__DOT__rv__DOT__Rs2E = (0x1fU 
                                                 & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                    >> 0x14U));
        }
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ReadDataW 
            = vlSelf->rv32i__DOT__ReadData;
        vlSelf->rv32i__DOT__rv__DOT__SDypeSecM = vlSelf->rv32i__DOT__rv__DOT__c__DOT__SDypeSecE;
        vlSelf->rv32i__DOT__rv__DOT__ResultSrcW = vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcM;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4W 
            = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4M;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW 
            = vlSelf->DataAdr;
    }
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ResultW = 
        ((2U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ResultSrcW))
          ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4W
          : ((1U & (IData)(vlSelf->rv32i__DOT__rv__DOT__ResultSrcW))
              ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ReadDataW
              : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW));
    if (vlSelf->reset) {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD1E = 0U;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD2E = 0U;
    } else if (vlSelf->rv32i__DOT__rv__DOT__FlushE) {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD1E = 0U;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD2E = 0U;
    } else {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD1E 
            = (((IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteW) 
                & ((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                             >> 0xfU)) == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdW)))
                ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg
                : ((0U == (0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                    >> 0xfU))) ? 0U
                    : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf
                   [(0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                              >> 0xfU))]));
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__RD2E 
            = (((IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteW) 
                & ((0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                             >> 0x14U)) == (IData)(vlSelf->rv32i__DOT__rv__DOT__RdW)))
                ? vlSelf->rv32i__DOT__rv__DOT__dp__DOT__writeReg
                : ((0U == (0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                    >> 0x14U))) ? 0U
                    : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf
                   [(0x1fU & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                              >> 0x14U))]));
    }
    vlSelf->rv32i__DOT__rv__DOT__RegWriteW = ((~ (IData)(vlSelf->reset)) 
                                              & (IData)(vlSelf->rv32i__DOT__rv__DOT__RegWriteM));
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__MemWriteE 
        = (1U & ((~ (IData)(vlSelf->reset)) & ((~ (IData)(vlSelf->rv32i__DOT__rv__DOT__FlushE)) 
                                               & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                                  >> 8U))));
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__loadE = (1U 
                                                  & ((~ (IData)(vlSelf->reset)) 
                                                     & ((~ (IData)(vlSelf->rv32i__DOT__rv__DOT__FlushE)) 
                                                        & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                                                           >> 1U))));
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__jarlE = (1U 
                                                  & ((~ (IData)(vlSelf->reset)) 
                                                     & ((~ (IData)(vlSelf->rv32i__DOT__rv__DOT__FlushE)) 
                                                        & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls))));
    if (vlSelf->reset) {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCD = 0U;
        vlSelf->rv32i__DOT__rv__DOT__c__DOT__SDypeSecE = 0U;
        vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcM = 0U;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4M = 0U;
        vlSelf->DataAdr = 0U;
    } else {
        if (vlSelf->rv32i__DOT__rv__DOT__PCSrcE) {
            vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCD = 0U;
        } else if ((1U & (~ (IData)(vlSelf->rv32i__DOT__rv__DOT__stallD)))) {
            vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCD 
                = vlSelf->rv32i__DOT__PC;
        }
        vlSelf->rv32i__DOT__rv__DOT__c__DOT__SDypeSecE 
            = ((IData)(vlSelf->rv32i__DOT__rv__DOT__FlushE)
                ? 0U : ((0U == (7U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                      >> 0xcU))) ? 0U
                         : ((1U == (7U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                          >> 0xcU)))
                             ? 1U : ((2U == (7U & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                   >> 0xcU)))
                                      ? 2U : 0U))));
        vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcM 
            = vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcE;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4M 
            = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4E;
        vlSelf->DataAdr = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResult;
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
    if (vlSelf->reset) {
        vlSelf->rv32i__DOT__rv__DOT__RdW = 0U;
        vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcE = 0U;
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4E = 0U;
    } else {
        vlSelf->rv32i__DOT__rv__DOT__RdW = vlSelf->rv32i__DOT__rv__DOT__RdM;
        if (vlSelf->rv32i__DOT__rv__DOT__FlushE) {
            vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcE = 0U;
            vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4E = 0U;
        } else {
            vlSelf->rv32i__DOT__rv__DOT__c__DOT__ResultSrcE 
                = (3U & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
                         >> 6U));
            vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4E 
                = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4D;
        }
    }
    Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__read_dmem_TOP(vlSelf->DataAdr, vlSelf->__Vfunc_rv32i__DOT__dmem__DOT__read_dmem__2__Vfuncout);
    if (vlSelf->reset) {
        vlSelf->rv32i__DOT__rv__DOT__RdM = 0U;
        vlSelf->rv32i__DOT__rv__DOT__RdE = 0U;
    } else {
        vlSelf->rv32i__DOT__rv__DOT__RdM = vlSelf->rv32i__DOT__rv__DOT__RdE;
        vlSelf->rv32i__DOT__rv__DOT__RdE = ((IData)(vlSelf->rv32i__DOT__rv__DOT__FlushE)
                                             ? 0U : 
                                            (0x1fU 
                                             & (vlSelf->rv32i__DOT__rv__DOT__InstrD 
                                                >> 7U)));
    }
    vlSelf->rv32i__DOT__ReadData = vlSelf->__Vfunc_rv32i__DOT__dmem__DOT__read_dmem__2__Vfuncout;
    vlSelf->rv32i__DOT__rv__DOT__RegWriteM = ((~ (IData)(vlSelf->reset)) 
                                              & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__RegWriteE));
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__RegWriteE 
        = (((~ (IData)(vlSelf->reset)) & (~ (IData)(vlSelf->rv32i__DOT__rv__DOT__FlushE))) 
           & ((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls) 
              >> 0xdU));
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
}

extern const VlUnpacked<SData/*13:0*/, 128> Vrv32i__ConstPool__TABLE_h5f27bdaa_0;

VL_INLINE_OPT void Vrv32i___024root___nba_sequent__TOP__2(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (vlSelf->__Vdlyvset__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0) {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf[vlSelf->__Vdlyvdim0__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0] 
            = vlSelf->__Vdlyvval__rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf__v0;
    }
    if (vlSelf->rv32i__DOT__rv__DOT__PCSrcE) {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4D = 4U;
        vlSelf->rv32i__DOT__rv__DOT__InstrD = 0x13U;
    } else if ((1U & (~ (IData)(vlSelf->rv32i__DOT__rv__DOT__stallD)))) {
        vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCPlus4D 
            = ((IData)(4U) + vlSelf->rv32i__DOT__PC);
        vlSelf->rv32i__DOT__rv__DOT__InstrD = vlSelf->rv32i__DOT__Instr;
    }
    if ((1U & (~ (IData)(vlSelf->reset)))) {
        if ((0x100073U == vlSelf->rv32i__DOT__rv__DOT__InstrD)) {
            Vrv32i___024root____Vdpiimwrap_rv32i__DOT__rv__DOT__dp__DOT__handle_ebreak_TOP();
        }
    }
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__ad__DOT__RtypeSub 
        = (IData)((0x40000020U == (0x40000020U & vlSelf->rv32i__DOT__rv__DOT__InstrD)));
    vlSelf->__Vtableidx1 = (0x7fU & vlSelf->rv32i__DOT__rv__DOT__InstrD);
    vlSelf->rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls 
        = Vrv32i__ConstPool__TABLE_h5f27bdaa_0[vlSelf->__Vtableidx1];
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
}

void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__imem__DOT__read_imem_TOP(IData/*31:0*/ addr, IData/*31:0*/ &read_imem__Vfuncrtn);

VL_INLINE_OPT void Vrv32i___024root___nba_sequent__TOP__3(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->rv32i__DOT__rv__DOT__PCSrcE = (((IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__BranchE) 
                                            & (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__branchScr)) 
                                           | (IData)(vlSelf->rv32i__DOT__rv__DOT__c__DOT__JumpE));
    if (vlSelf->reset) {
        vlSelf->rv32i__DOT__PC = 0U;
    } else if ((1U & (~ (IData)(vlSelf->rv32i__DOT__rv__DOT__stallF)))) {
        vlSelf->rv32i__DOT__PC = vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCFNext;
    }
    Vrv32i___024root____Vdpiimwrap_rv32i__DOT__imem__DOT__read_imem_TOP(vlSelf->rv32i__DOT__PC, vlSelf->__Vfunc_rv32i__DOT__imem__DOT__read_imem__1__Vfuncout);
    vlSelf->rv32i__DOT__Instr = vlSelf->__Vfunc_rv32i__DOT__imem__DOT__read_imem__1__Vfuncout;
    vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCFNext = 
        ((IData)(vlSelf->rv32i__DOT__rv__DOT__PCSrcE)
          ? ((IData)(vlSelf->rv32i__DOT__rv__DOT__jarlW)
              ? (vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ImmExtE 
                 + vlSelf->rv32i__DOT__rv__DOT__dp__DOT__PCE)
              : vlSelf->rv32i__DOT__rv__DOT__dp__DOT__ALUResultW)
          : ((IData)(4U) + vlSelf->rv32i__DOT__PC));
}

VL_INLINE_OPT void Vrv32i___024root___nba_comb__TOP__0(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___nba_comb__TOP__0\n"); );
    // Body
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

void Vrv32i___024root___eval_triggers__act(Vrv32i___024root* vlSelf);

bool Vrv32i___024root___eval_phase__act(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vrv32i___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vrv32i___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vrv32i___024root___eval_phase__nba(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vrv32i___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__ico(Vrv32i___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__nba(Vrv32i___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__act(Vrv32i___024root* vlSelf);
#endif  // VL_DEBUG

void Vrv32i___024root___eval(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval\n"); );
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
            Vrv32i___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("vsrc/rv32i.v", 15, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vrv32i___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vrv32i___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/rv32i.v", 15, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vrv32i___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vsrc/rv32i.v", 15, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vrv32i___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vrv32i___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vrv32i___024root___eval_debug_assertions(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
