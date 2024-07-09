`include "RV32I_defines.v"

// RISC-V  processor
// 2024.2
// songwenfei999@gmail.com

// run 210
// Expect simulator to print "Simulation succeeded"
// when the value 25 (0x19) is written to address 100 (0x64)





module rv32i(
    input                               clk                        ,
    input                               reset                      ,
    output             [`XLEN-1: 0]     WriteData                  ,
    output             [`XLEN-1: 0]     DataAdr                    ,
    output                              MemWrite                   
    
    );                  

    wire               [`XLEN-1: 0]     PC_m                         ;
    wire               [`XLEN-1: 0]     PC_s                         ;
    wire               [`XLEN-1: 0]     Instr_s                    ;
    wire               [`XLEN-1: 0]     Instr_m                    ;
    wire               [`XLEN-1: 0]     ReadData                   ;
    wire               [`XLEN-1: 0]     mask                       ;
    /* verilator lint_off UNUSEDSIGNAL */
    wire               [`XLEN-1: 0]     write_d;
    wire                                re;
    /* verilator lint_on UNUSEDSIGNAL */                       
    //wire               [`XLEN-1: 0]     index_instr                ;

    //assign                              index_instr = PC[7:2]       ;
  
  // instantiate processor and memories
  riscv rv(clk, reset, PC_m, Instr_m, MemWrite, DataAdr,
                       WriteData, mask,ReadData);
  imem imem(clk,re,PC_s, Instr_s);
  dmem dmem(clk, MemWrite, DataAdr, WriteData, mask,ReadData);
  axiTop axi(clk,reset,write_d,PC_m,32'b0,1'b0,1'b1,re,Instr_s,Instr_m,PC_s);
endmodule

