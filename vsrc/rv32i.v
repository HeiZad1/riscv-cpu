`include "RV32I_defines.v"

// RISC-V  processor
// 2024.2
// songwenfei999@gmail.com

// run 210
// Expect simulator to print "Simulation succeeded"
// when the value 25 (0x19) is written to address 100 (0x64)





module rv32i(
    input                               clock                        ,
    input                               reset                      ,
    input                               io_interrupt               ,

    output             [`XLEN-1: 0]     WriteData                  ,
    output             [`XLEN-1: 0]     DataAdr                    ,
    output                              MemWrite                   
    
    );                  

    wire               [`XLEN-1: 0]     PC                         ;
    wire               [`XLEN-1: 0]     Instr                      ;
    wire               [`XLEN-1: 0]     ReadData                   ;
    wire               [`XLEN-1: 0]     mask                       ;
    //wire               [`XLEN-1: 0]     index_instr                ;

    //assign                              index_instr = PC[7:2]       ;
  
  // instantiate processor and memories
  riscv rv(clk, reset, PC, Instr, MemWrite, DataAdr,
                       WriteData, mask,ReadData);
  //imem imem(PC, Instr);
  //dmem dmem(clk, MemWrite, DataAdr, WriteData, mask,ReadData);
endmodule

