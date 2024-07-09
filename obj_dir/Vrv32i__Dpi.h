// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VRV32I__DPI_H_
#define VERILATED_VRV32I__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at vsrc/datapath.v:177:34
    extern void handle_ebreak();
    // DPI import at vsrc/datapath.v:176:34
    extern void itrace(int PCF, int PCD, int PCE, int INF, int IND);
    // DPI import at vsrc/dmem.v:10:31
    extern int read_dmem(int addr);
    // DPI import at vsrc/imem.v:7:31
    extern int read_imem(int addr);
    // DPI import at vsrc/dmem.v:11:32
    extern void write_imem(int addr, int data);

#ifdef __cplusplus
}
#endif

#endif  // guard
