`include "RV32I_defines.v"
module riscv(	   input        		 clk, reset,
                   output   [`XLEN-1:0]  PCF,
                   input    [`XLEN-1:0]  Instr,
                   output         		 MemWrite,
                   output   [`XLEN-1:0]  ALUResultM,
                   //output   [5:0]        DataAdrR,
				   output   [`XLEN-1:0]	 WriteData,
				   output   [`XLEN-1:0]	 mask,
                   input    [`XLEN-1:0]  ReadData
                    );

  wire       			  ALUSrcE;
  wire		 			  RegWriteW;
  wire		 			  RegWriteM;
  //wire		 			  JumpE;
  wire		 			  Zero;
  wire		 			  stallD;
  wire		 			  stallF;
  wire		 			  FlushD;
  wire		 			  FlushE;
  wire		 			  ResultSrcE0;
  wire		 			  loadW;
  wire		 			  less;
  wire		 			  jarlW;
  wire					  PCSrcE;
  wire [1:0] 			  ResultSrcW;
  wire [2:0] 			  ImmSrcD;//！！
  wire [3:0] 			  ALUControlE;
  wire [1:0] 			  SDypeSecM;//!!
  wire [1:0] 			  ForWordAE;
  wire [1:0] 			  ForWordBE;
  wire [`RFIDX_WIDTH-1:0] RdW;
  wire [`RFIDX_WIDTH-1:0] RdM;
  wire [`RFIDX_WIDTH-1:0] RdE;
  wire [`RFIDX_WIDTH-1:0] Rs1D;
  wire [`RFIDX_WIDTH-1:0] Rs2D;
  wire [`RFIDX_WIDTH-1:0] Rs1E;
  wire [`RFIDX_WIDTH-1:0] Rs2E;
  /* verilator lint_off UNUSEDSIGNAL */
  wire [`XLEN-1:0] 		  InstrD;
  /* verilator lint_off UNUSEDSIGNAL */
  //wire [5:0]              DataAdrR;
  //wire [`XLEN-1:0]        ALUResultM;
  //assign                  DataAdrR=ALUResultM[7:2];


  controller c(clk,reset,InstrD[6:0], InstrD[14:12], InstrD[30], Zero,less,ResultSrcE0,
               ResultSrcW, MemWrite, PCSrcE,
               ALUSrcE, loadW,jarlW,RegWriteW, RegWriteM,
               ImmSrcD, ALUControlE,SDypeSecM,FlushE);
  datapath dp(clk, reset, ResultSrcW, PCSrcE,
              ALUSrcE, RegWriteW,loadW,jarlW,
              ImmSrcD, ALUControlE,SDypeSecM,
              Zero,less, PCF, Instr,
              ALUResultM,WriteData, ReadData,
			  stallD,stallF,FlushD,FlushE,ForWordAE,ForWordBE,
			  RdW,RdM,RdE,
			  Rs1D,Rs2D,Rs1E,Rs2E,InstrD,mask
			  );
			  
  HazardUnit hu(RegWriteW,RegWriteM,RdW,RdM,RdE,
			    ResultSrcE0,PCSrcE,  
			    Rs1E,Rs2E,Rs1D,Rs2D,
			    ForWordAE,ForWordBE,
				FlushE,FlushD,stallF,stallD
				);
endmodule

