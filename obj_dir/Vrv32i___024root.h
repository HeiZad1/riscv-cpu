// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vrv32i.h for the primary calling header

#ifndef VERILATED_VRV32I___024ROOT_H_
#define VERILATED_VRV32I___024ROOT_H_  // guard

#include "verilated.h"


class Vrv32i__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vrv32i___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(MemWrite,0,0);
        CData/*0:0*/ rv32i__DOT__re;
        CData/*0:0*/ rv32i__DOT__rv__DOT__ALUSrcE;
        CData/*0:0*/ rv32i__DOT__rv__DOT__RegWriteW;
        CData/*0:0*/ rv32i__DOT__rv__DOT__RegWriteM;
        CData/*0:0*/ rv32i__DOT__rv__DOT__stallD;
        CData/*0:0*/ rv32i__DOT__rv__DOT__stallF;
        CData/*0:0*/ rv32i__DOT__rv__DOT__FlushE;
        CData/*1:0*/ rv32i__DOT__rv__DOT__ResultSrcE;
        CData/*0:0*/ rv32i__DOT__rv__DOT__loadW;
        CData/*0:0*/ rv32i__DOT__rv__DOT__jarlW;
        CData/*0:0*/ rv32i__DOT__rv__DOT__PCSrcE;
        CData/*1:0*/ rv32i__DOT__rv__DOT__ResultSrcW;
        CData/*1:0*/ rv32i__DOT__rv__DOT__ResultSrcM;
        CData/*3:0*/ rv32i__DOT__rv__DOT__ALUControlE;
        CData/*1:0*/ rv32i__DOT__rv__DOT__SDypeSecM;
        CData/*1:0*/ rv32i__DOT__rv__DOT__ForWordAE;
        CData/*1:0*/ rv32i__DOT__rv__DOT__ForWordBE;
        CData/*4:0*/ rv32i__DOT__rv__DOT__RdW;
        CData/*4:0*/ rv32i__DOT__rv__DOT__RdM;
        CData/*4:0*/ rv32i__DOT__rv__DOT__RdE;
        CData/*4:0*/ rv32i__DOT__rv__DOT__Rs1E;
        CData/*4:0*/ rv32i__DOT__rv__DOT__Rs2E;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__JumpE;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__BranchE;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__jarlE;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__jarlM;
        CData/*3:0*/ rv32i__DOT__rv__DOT__c__DOT__ALUControlD;
        CData/*1:0*/ rv32i__DOT__rv__DOT__c__DOT__SDypeSecE;
        CData/*2:0*/ rv32i__DOT__rv__DOT__c__DOT__funct3E;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__RegWriteE;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__MemWriteE;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__loadE;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__loadM;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__branchScr;
        CData/*0:0*/ rv32i__DOT__rv__DOT__c__DOT__ad__DOT__RtypeSub;
        CData/*2:0*/ rv32i__DOT__rv__DOT__dp__DOT__fun3E;
        CData/*2:0*/ rv32i__DOT__rv__DOT__dp__DOT__fun3M;
        CData/*2:0*/ rv32i__DOT__rv__DOT__dp__DOT__fun3W;
        CData/*0:0*/ rv32i__DOT__rv__DOT__hu__DOT__lwStall;
        CData/*0:0*/ rv32i__DOT__axi__DOT__s2m_WREADY;
        CData/*0:0*/ rv32i__DOT__axi__DOT__s2m_BVALID;
        CData/*0:0*/ rv32i__DOT__axi__DOT__cpu2axi__DOT__r_ARVALID;
        CData/*0:0*/ rv32i__DOT__axi__DOT__cpu2axi__DOT__r_AWVALID;
        CData/*0:0*/ rv32i__DOT__axi__DOT__cpu2axi__DOT__r_BREADY;
        CData/*0:0*/ rv32i__DOT__axi__DOT__cpu2axi__DOT__r_WVALID;
        CData/*0:0*/ rv32i__DOT__axi__DOT__cpu2axi__DOT__r_RREADY;
        CData/*0:0*/ rv32i__DOT__axi__DOT__axi2mem__DOT__r_ARREADY;
        CData/*0:0*/ rv32i__DOT__axi__DOT__axi2mem__DOT__r_RVALID;
        CData/*0:0*/ rv32i__DOT__axi__DOT__axi2mem__DOT__r_AWREADY;
        CData/*0:0*/ rv32i__DOT__axi__DOT__axi2mem__DOT__r_WREADY;
        CData/*0:0*/ rv32i__DOT__axi__DOT__axi2mem__DOT__r_BVALID;
        CData/*6:0*/ __Vtableidx1;
        CData/*4:0*/ __Vtableidx2;
        CData/*0:0*/ __Vdly__rv32i__DOT__axi__DOT__axi2mem__DOT__r_ARREADY;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __VactContinue;
        SData/*13:0*/ rv32i__DOT__rv__DOT__c__DOT__md__DOT__controls;
        VL_OUT(WriteData,31,0);
        VL_OUT(DataAdr,31,0);
    };
    struct {
        IData/*31:0*/ rv32i__DOT__PC_m;
        IData/*31:0*/ rv32i__DOT__Instr_s;
        IData/*31:0*/ rv32i__DOT__ReadData;
        IData/*31:0*/ rv32i__DOT__write_d;
        IData/*31:0*/ rv32i__DOT__rv__DOT__InstrD;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCFNext;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCTargetE;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCTargetW;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCTargetM;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCD;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCPlus4D;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCE;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCPlus4E;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCPlus4M;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__PCPlus4W;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__ImmExtD;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__ImmExtE;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__ALUResult;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__ALUResultW;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__WriteDataM;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__SrcAE;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__SrcBE;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__RD1E;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__RD2E;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__ResultW;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__WriteDataE;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__ReadDataW;
        IData/*31:0*/ rv32i__DOT__rv__DOT__dp__DOT__writeReg;
        IData/*31:0*/ rv32i__DOT__dmem__DOT__unnamedblk1__DOT__masked_data;
        IData/*31:0*/ rv32i__DOT__axi__DOT__s2m_RDATA;
        IData/*31:0*/ rv32i__DOT__axi__DOT__addr_w;
        IData/*31:0*/ rv32i__DOT__axi__DOT__addr_r;
        IData/*31:0*/ rv32i__DOT__axi__DOT__cpu2axi__DOT__r_WDATA;
        IData/*31:0*/ rv32i__DOT__axi__DOT__cpu2axi__DOT__r_RDATA;
        IData/*31:0*/ rv32i__DOT__axi__DOT__cpu2axi__DOT__r_AWADDR;
        IData/*31:0*/ rv32i__DOT__axi__DOT__cpu2axi__DOT__r_ARADDR;
        IData/*31:0*/ __Vfunc_rv32i__DOT__dmem__DOT__read_dmem__3__Vfuncout;
        IData/*31:0*/ __Vdly__rv32i__DOT__axi__DOT__cpu2axi__DOT__r_RDATA;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32> rv32i__DOT__rv__DOT__dp__DOT__rff__DOT__rf;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vrv32i__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vrv32i___024root(Vrv32i__Syms* symsp, const char* v__name);
    ~Vrv32i___024root();
    VL_UNCOPYABLE(Vrv32i___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
