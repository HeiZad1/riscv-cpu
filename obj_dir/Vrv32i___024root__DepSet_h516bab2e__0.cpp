// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrv32i.h for the primary calling header

#include "Vrv32i__pch.h"
#include "Vrv32i__Syms.h"
#include "Vrv32i___024root.h"

extern "C" void handle_ebreak();

VL_INLINE_OPT void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__rv__DOT__dp__DOT__handle_ebreak_TOP() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root____Vdpiimwrap_rv32i__DOT__rv__DOT__dp__DOT__handle_ebreak_TOP\n"); );
    // Body
    handle_ebreak();
}

extern "C" int read_imem(int addr);

VL_INLINE_OPT void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__imem__DOT__read_imem_TOP(IData/*31:0*/ addr, IData/*31:0*/ &read_imem__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root____Vdpiimwrap_rv32i__DOT__imem__DOT__read_imem_TOP\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int read_imem__Vfuncrtn__Vcvt;
    read_imem__Vfuncrtn__Vcvt = read_imem(addr__Vcvt);
    read_imem__Vfuncrtn = read_imem__Vfuncrtn__Vcvt;
}

extern "C" int read_dmem(int addr);

VL_INLINE_OPT void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__read_dmem_TOP(IData/*31:0*/ addr, IData/*31:0*/ &read_dmem__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__read_dmem_TOP\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int read_dmem__Vfuncrtn__Vcvt;
    read_dmem__Vfuncrtn__Vcvt = read_dmem(addr__Vcvt);
    read_dmem__Vfuncrtn = read_dmem__Vfuncrtn__Vcvt;
}

extern "C" void write_dmem(int addr, int data);

VL_INLINE_OPT void Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__write_dmem_TOP(IData/*31:0*/ addr, IData/*31:0*/ data) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root____Vdpiimwrap_rv32i__DOT__dmem__DOT__write_dmem_TOP\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int data__Vcvt;
    for (size_t data__Vidx = 0; data__Vidx < 1; ++data__Vidx) data__Vcvt = data;
    write_dmem(addr__Vcvt, data__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__ico(Vrv32i___024root* vlSelf);
#endif  // VL_DEBUG

void Vrv32i___024root___eval_triggers__ico(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrv32i___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__act(Vrv32i___024root* vlSelf);
#endif  // VL_DEBUG

void Vrv32i___024root___eval_triggers__act(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((IData)(vlSelf->reset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__reset__0)))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrv32i___024root___dump_triggers__act(vlSelf);
    }
#endif
}
