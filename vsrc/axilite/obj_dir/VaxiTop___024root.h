// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VaxiTop.h for the primary calling header

#ifndef VERILATED_VAXITOP___024ROOT_H_
#define VERILATED_VAXITOP___024ROOT_H_  // guard

#include "verilated.h"


class VaxiTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VaxiTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(wen,0,0);
    VL_IN8(ren,0,0);
    VL_IN8(__pinNumber11,0,0);
    CData/*0:0*/ axiTop__DOT__s2m_WREADY;
    CData/*3:0*/ axiTop__DOT__AWPROT;
    CData/*0:0*/ axiTop__DOT__cpu2axi__DOT__r_ARVALID;
    CData/*0:0*/ axiTop__DOT__cpu2axi__DOT__r_AWVALID;
    CData/*0:0*/ axiTop__DOT__cpu2axi__DOT__r_BREADY;
    CData/*0:0*/ axiTop__DOT__cpu2axi__DOT__r_WVALID;
    CData/*0:0*/ axiTop__DOT__cpu2axi__DOT__r_WREADY;
    CData/*0:0*/ axiTop__DOT__cpu2axi__DOT__r_RREADY;
    CData/*0:0*/ axiTop__DOT__axi2mem__DOT__r_ARREADY;
    CData/*0:0*/ axiTop__DOT__axi2mem__DOT__r_ARVALID;
    CData/*0:0*/ axiTop__DOT__axi2mem__DOT__r_RVALID;
    CData/*0:0*/ axiTop__DOT__axi2mem__DOT__r_AWREADY;
    CData/*0:0*/ axiTop__DOT__axi2mem__DOT__r_WREADY;
    CData/*0:0*/ axiTop__DOT__axi2mem__DOT__r_BVALID;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(read_data_m,31,0);
    VL_IN(addr_m,31,0);
    VL_IN(write_data_m,31,0);
    VL_OUT(read_data_s,31,0);
    VL_OUT(addr_s,31,0);
    VL_OUT(write_data_s,31,0);
    IData/*31:0*/ axiTop__DOT__cpu2axi__DOT__r_WDATA;
    IData/*31:0*/ axiTop__DOT__cpu2axi__DOT__r_RDATA;
    IData/*31:0*/ axiTop__DOT__cpu2axi__DOT__r_AWADDR;
    IData/*31:0*/ axiTop__DOT__cpu2axi__DOT__r_ARADDR;
    IData/*31:0*/ axiTop__DOT__axi2mem__DOT__r_WDATA;
    IData/*31:0*/ axiTop__DOT__axi2mem__DOT__r_RDATA;
    IData/*31:0*/ axiTop__DOT__axi2mem__DOT__r_AWADDR;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VaxiTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VaxiTop___024root(VaxiTop__Syms* symsp, const char* v__name);
    ~VaxiTop___024root();
    VL_UNCOPYABLE(VaxiTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
