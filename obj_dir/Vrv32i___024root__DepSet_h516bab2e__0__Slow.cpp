// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrv32i.h for the primary calling header

#include "Vrv32i__pch.h"
#include "Vrv32i__Syms.h"
#include "Vrv32i___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrv32i___024root___dump_triggers__stl(Vrv32i___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vrv32i___024root___eval_triggers__stl(Vrv32i___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrv32i___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
