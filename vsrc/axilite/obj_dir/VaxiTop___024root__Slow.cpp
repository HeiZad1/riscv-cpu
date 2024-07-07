// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VaxiTop.h for the primary calling header

#include "VaxiTop__pch.h"
#include "VaxiTop__Syms.h"
#include "VaxiTop___024root.h"

void VaxiTop___024root___ctor_var_reset(VaxiTop___024root* vlSelf);

VaxiTop___024root::VaxiTop___024root(VaxiTop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VaxiTop___024root___ctor_var_reset(this);
}

void VaxiTop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VaxiTop___024root::~VaxiTop___024root() {
}
