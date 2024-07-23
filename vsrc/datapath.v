// riscvsingle.sv

// RISC-V single-cycle processor
// From Section 7.6 of Digital Design & Computer Architecture
// 27 April 2020
// David_Harris@hmc.edu 
// Sarah.Harris@unlv.edu

// run 210
// Expect simulator to print "Simulation succeeded"
// when the value 25 (0x19) is written to address 100 (0x64)

// Single-cycle implementation of RISC-V (RV32I)
// User-level Instruction Set Architecture V2.2 (May 7, 2017)
// Implements a subset of the base integer instructions:
//    lw, sw
//    add, sub, and, or, slt, 
//    addi, andi, ori, slti
//    beq
//    jal
// Exceptions, traps, and interrupts not implemented
// little-endian memory

// 31 32-bit registers x1-x31, x0 hardwired to 0
// R-Type instructions
//   add, sub, and, or, slt ,xor
//   INSTR rd, rs1, rs2
//   Instr[31:25] = funct7 (funct7b5 & opb5 = 1 for sub, 0 for others)
//   Instr[24:20] = rs2
//   Instr[19:15] = rs1
//   Instr[14:12] = funct3
//   Instr[11:7]  = rd
//   Instr[6:0]   = opcode
// I-Type Instructions
//   lw, I-type ALU (addi, andi, ori, slti)
//   lw:         INSTR rd, imm(rs1)
//   I-type ALU: INSTR rd, rs1, imm (12-bit signed)
//   Instr[31:20] = imm[11:0]
//   Instr[24:20] = rs2
//   Instr[19:15] = rs1
//   Instr[14:12] = funct3
//   Instr[11:7]  = rd
//   Instr[6:0]   = opcode
// S-Type Instruction
//   sw rs2, imm(rs1) (store rs2 into address specified by rs1 + immm)
//   Instr[31:25] = imm[11:5] (offset[11:5])
//   Instr[24:20] = rs2 (src)
//   Instr[19:15] = rs1 (base)
//   Instr[14:12] = funct3
//   Instr[11:7]  = imm[4:0]  (offset[4:0])
//   Instr[6:0]   = opcode
// B-Type Instruction
//   beq rs1, rs2, imm (PCTarget = PC + (signed imm x 2))
//   Instr[31:25] = imm[12], imm[10:5]
//   Instr[24:20] = rs2
//   Instr[19:15] = rs1
//   Instr[14:12] = funct3
//   Instr[11:7]  = imm[4:1], imm[11]
//   Instr[6:0]   = opcode
// J-Type Instruction
//   jal rd, imm  (signed imm is multiplied by 2 and added to PC, rd = PC+4)
//   Instr[31:12] = imm[20], imm[10:1], imm[11], imm[19:12]
//   Instr[11:7]  = rd
//   Instr[6:0]   = opcode
// u-Type Instruction
//	 lui          
//	 Instr[31:12] = imm[31:12]
//   Instr[11:7]  = rd
//   Instr[6:0]   = opcode


//   Instruction  opcode    funct3    funct7
//   add          0110011   000       0000000
//   sub          0110011   000       0100000
//   and          0110011   111       0000000
//   or           0110011   110       0000000
//   slt          0110011   010       0000000
//   sll          0110011   001       0000000
//   addi         0010011   000       immediate
//   andi         0010011   111       immediate
//   ori          0010011   110       immediate
//   slti         0010011   010       immediate
//   beq          1100011   000       immediate
//   lw	          0000011   010       immediate
//   sw           0100011   010       immediate
//   jal          1101111   immediate immediate
//   lui          0110111   immediate imm
//   xor          0110011   100       0000000




`include "RV32I_defines.v"





module datapath(input                  clk,
    input                               reset                      ,
    input              [   1: 0]        ResultSrc                  ,
    input                               PCSrc                      ,
    input                               ALUSrc                     ,
    input                               RegWrite                   ,
    input                               loadW                      ,
    input                               jarlW                      ,
    input              [   2: 0]        ImmSrc                     ,
    input              [   3: 0]        ALUControl                 ,
    input              [   1: 0]        SDypeSecM                  ,
    output                              Zero                       ,
    output                              l                          ,
    output             [`XLEN-1: 0]     PCF                        ,
    input              [`XLEN-1: 0]     Instr                      ,
    output             [`XLEN-1: 0]     ALUResultM                 ,
    output             [`XLEN-1: 0]     WriteData                  ,
    input              [`XLEN-1: 0]     ReadData                   ,
    input                               stallD                     ,
    input                               stallF                     ,
    input                               FlushD                     ,
    input                               FlushE                     ,
    input              [   1: 0]        ForWordAE                  ,
    input              [   1: 0]        ForWordBE                  ,

    output             [   4: 0]        RdW                        ,
    output             [   4: 0]        RdM                        ,
    output             [   4: 0]        RdE                        ,
    output             [   4: 0]        Rs1D                       ,
    output             [   4: 0]        Rs2D                       ,
    output             [   4: 0]        Rs1E                       ,
    output             [   4: 0]        Rs2E                       ,
    output             [`XLEN-1: 0]     InstrD                     ,
    output             [`XLEN-1: 0]     mask                       
                );
    
    

    wire               [`XLEN-1: 0]     PCFNext                    ;
    wire               [`XLEN-1: 0]     PCPlus4F                   ;
    wire               [`XLEN-1: 0]     PCTargetE                  ;
    wire [`XLEN-1:0] PCTargetW;
    wire [`XLEN-1:0] PCTargetM;
    wire               [`XLEN-1: 0]     PCD                        ;
    wire               [`XLEN-1: 0]     PCPlus4D                   ;
    wire               [`XLEN-1: 0]     PCE                        ;
    wire               [`XLEN-1: 0]     PCPlus4E                   ;
    wire               [`XLEN-1: 0]     PCPlus4M                   ;
    wire               [`XLEN-1: 0]     PCPlus4W                   ;
    wire               [`XLEN-1: 0]     PCJamp                     ;
    wire               [`XLEN-1: 0]     ImmExtD                    ;
    wire               [`XLEN-1: 0]     ImmExtE                    ;
    wire               [`XLEN-1: 0]     ALUResult                  ;
    wire               [`XLEN-1: 0]     ALUResultW                 ;
    wire               [`XLEN-1: 0]     WriteDataM                 ;
    wire               [`XLEN-1: 0]     SrcAE                      ;
    wire               [`XLEN-1: 0]     SrcBE                      ;
    wire               [`XLEN-1: 0]     RD1D                       ;
    wire               [`XLEN-1: 0]     RD2D                       ;
    wire               [`XLEN-1: 0]     RD1E                       ;
    wire               [`XLEN-1: 0]     RD2E                       ;
    wire               [   4: 0]        RdD                        ;//?>??
    wire               [`XLEN-1: 0]     ResultW                    ;
    wire               [`XLEN-1: 0]     WriteDataE                 ;
    wire               [`XLEN-1: 0]     ReadDataW                  ;
    wire               [`XLEN-1: 0]     writeReg                   ;
    wire                [1:0]           offset                      ;
    wire                [2:0]            fun3D                     ;
    wire                [2:0]            fun3E                     ;
    wire                [2:0]            fun3M                     ;
    wire                [2:0]            fun3W                     ;

    assign                              Rs1D                      = InstrD[19:15];
    assign                              Rs2D                      = InstrD[24:20];
    assign                              RdD                       = InstrD[11: 7];
    assign                              offset                    = ALUResultM[1:0];
    assign                              fun3D                     = InstrD[14:12];
    import "DPI-C" function void itrace(input int PCF, input int PCD,input int PCE,input int INF,input int IND);
    import "DPI-C" function void handle_ebreak();
  // next PC logic
  floprPC #(`XLEN)  pcreg(clk, reset, ~stallF,PCFNext, PCF);
  adder             pcadd4(PCF, 32'd4, PCPlus4F);
  adder             pcaddbranch(PCE, ImmExtE, PCTargetE);
  mux2 #(`XLEN)        pcmux (PCPlus4F,PCJamp , PCSrc, PCFNext);
  mux2 #(`XLEN)        pcmux2( PCTargetE,ALUResultW, jarlW,PCJamp );
 
  // register file logic
  regfile     rff(~clk, RegWrite, InstrD[19:15], InstrD[24:20], 
                 RdW, writeReg,RD1D ,RD2D );
  extend      ext(InstrD[31:7], ImmSrc, ImmExtD);
 // mux2 #(`XLEN)    fwdmux(RD2, ResultW,ForWordD , RD2D);
  lmemControl lc(ResultW,fun3W,loadW,writeReg);
  WmemControl wc(WriteDataM,SDypeSecM,offset,mask,WriteData);
  
  

  // ALU logic
  mux4 #(`XLEN)  srcAmux(RD1E, ResultW , ALUResultM, PCTargetM,ForWordAE, SrcAE);
  mux3 #(`XLEN)  srcBmux(RD2E, ResultW, ALUResultM, ForWordBE, WriteDataE);
  mux2 #(`XLEN)  srcbmux(WriteDataE, ImmExtE, ALUSrc, SrcBE);
  alu              alu(SrcAE, SrcBE, ALUControl, ALUResult, Zero,l);//ALUResult输出端口
  
  
  // regD
    enfloprsind #(`XLEN) Dreg1(clk, 1'b0 ,FlushD, ~stallD,Instr, InstrD);
    enfloprspc4 #(`XLEN)    Dreg2(clk,  reset,FlushD , ~stallD,PCF, PCD);
    enfloprspc4 #(`XLEN) Dreg3(clk, 1'b0 ,FlushD, ~stallD,PCPlus4F, PCPlus4D);
    
	
	//regE  为i了适应地形能加入en
    floprs #(`XLEN) Ereg1(clk, reset, FlushE,             PCD, PCE);
    floprs #( `RFIDX_WIDTH) Ereg2(clk,  reset, FlushE,    Rs1D, Rs1E);
    floprs #( `RFIDX_WIDTH) Ereg3(clk, reset, FlushE,     Rs2D, Rs2E);
    floprs #( `RFIDX_WIDTH) Ereg4(clk,  reset, FlushE,    RdD, RdE );
    floprs #(`XLEN) Ereg5(clk,  reset, FlushE,            ImmExtD, ImmExtE);
    floprs #(`XLEN) Ereg6(clk,  reset, FlushE,            PCPlus4D, PCPlus4E);
    floprs #(`XLEN) Ereg7(clk,  reset, FlushE,            RD2D , RD2E);
    floprs #(`XLEN) Ereg8(clk,  reset, FlushE,            RD1D, RD1E);
    floprs #(3)     Ereg_FUN3(clk,  reset, FlushE,        fun3D, fun3E);
	
	//regM
    flopr #(`XLEN) Mreg1 (clk, reset ,            ALUResult, ALUResultM);
    flopr #(`XLEN) Mreg2 (clk, reset ,            WriteDataE,WriteDataM);
    flopr #( `RFIDX_WIDTH) Mreg3 (clk, reset ,    RdE, RdM);
    flopr #(`XLEN) Mreg4 (clk, reset ,            PCPlus4E, PCPlus4M);
	flopr #(`XLEN) Mreg11(clk, reset ,            PCTargetE, PCTargetM);
    flopr #(3)     Mreg_FUN3(clk, reset ,         fun3E, fun3M);
	
	//RegW
    flopr #(`XLEN) Wreg1(clk, reset ,   ALUResultM, ALUResultW);
    flopr #(`XLEN) Wreg2(clk, reset , ReadData, ReadDataW);
    flopr #( `RFIDX_WIDTH) Wreg3(clk, reset , RdM, RdW);
    flopr #(`XLEN) Wreg4(clk, reset , PCPlus4M, PCPlus4W);
	flopr #(`XLEN) Wreg9(clk, reset , PCTargetM, PCTargetW);
    flopr #(3) Wreg_FUN3(clk, reset , fun3M, fun3W);
	
	//RES
    mux4 #(`XLEN)  resultmux(ALUResultW, ReadDataW, PCPlus4W,PCTargetW, ResultSrc, ResultW);
    
	
    
        
    always@(posedge clk) begin
        itrace(PCF,PCD,PCE,Instr,InstrD);
        handle_ebreak();
    end
endmodule














