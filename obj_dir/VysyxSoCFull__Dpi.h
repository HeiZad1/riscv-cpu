// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYXSOCFULL__DPI_H_
#define VERILATED_VYSYXSOCFULL__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/swf/ysyx/ics2023/ysyxSoC/perip/flash/flash_cmd.v:1:30
    extern void flash_read(int addr, int* data);
    // DPI import at vsrc/datapath.v:177:34
    extern void handle_ebreak();
    // DPI import at vsrc/datapath.v:176:34
    extern void itrace(int PCF, int PCD, int PCE, int INF, int IND);
    // DPI import at vsrc/ysyxSoCFull.v:4735:30
    extern void mrom_read(int raddr, int* rdata);

#ifdef __cplusplus
}
#endif

#endif  // guard
