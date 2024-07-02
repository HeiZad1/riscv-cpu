`include "RV32I_defines.v"

module controller(
    input                               clk,reset                  ,
    input              [   6: 0]        op                         ,
    input              [   2: 0]        funct3                     ,
    input                               funct7b5                   ,
    input                               ZeroE,l                    ,
    output             [   1: 0]        ResultSrcE                 ,
    output             [   1: 0]        ResultSrcW                 ,
    output             [   1: 0]        ResultSrcM                 ,
    output                              MemWriteM                  ,
    output                              PCSrcE, ALUSrcE,loadW,jarlW,//XINJIADE
    output                              RegWriteW, RegWriteM ,//?????
    output             [   2: 0]        ImmSrcD                    ,
    output             [   3: 0]        ALUControlE                ,
    output             [   1: 0]        SDypeSecM                  ,
    input                               FlushE                    );                    

    wire               [   1: 0]        ALUOp                      ;
    wire               [   1: 0]        ResultSrcD                 ;
    //wire               [   1: 0]        ResultSrcE                 ;
    //wire               [   1: 0]        ResultSrcM                 ;
    wire                                BranchD                    ;
    wire                                JumpD                      ;
    wire                                JumpE                      ;
    wire                                ALUSrcD                    ;
    wire                                BranchE                    ;
    wire                                jarlD                      ;
    wire                                jarlE                      ;
    wire                                jarlM                      ;
    wire               [   3: 0]        ALUControlD                ;
    wire               [   1: 0]        SDypeSec                   ;
    wire               [   1: 0]        SDypeSecE                  ;
    wire               [   2: 0]        funct3E                    ;
    wire                                RegWriteE                  ;
    wire                                RegWriteD                  ;
    wire                                MemWriteE                  ;
    wire                                MemWriteD                  ;
    wire                                loadD                      ;
    wire                                loadE                      ;
    wire                                loadM                      ;
    wire                                branchScr                  ;
	
	
    maindec md(op, ResultSrcD, MemWriteD, BranchD,
             ALUSrcD, RegWriteD, JumpD,loadD,jarlD, ImmSrcD, ALUOp);
  aludec    ad(op[5], funct3, funct7b5, ALUOp, ALUControlD);
  Blu       blu(funct3E,ZeroE,l,branchScr);
  sDypedec  SD(funct3,SDypeSec);
  //REGE
  
  floprs #( 1) Ereg9 (clk, reset, FlushE, RegWriteD, RegWriteE);
  floprs #( 2) Ereg10(clk, reset, FlushE , ResultSrcD, ResultSrcE);
  
  
  floprs #( 1) Ereg11(clk,  reset, FlushE, MemWriteD, MemWriteE);
  floprs #( 1) Ereg12(clk,  reset, FlushE, JumpD, JumpE);
  floprs #( 1) Ereg13(clk,  reset, FlushE, BranchD, BranchE);
  floprs #( 4) Ereg14(clk,  reset, FlushE, ALUControlD, ALUControlE);
  floprs #( 1) Ereg15(clk,  reset, FlushE, ALUSrcD, ALUSrcE);
  floprs #( 1) Ereg16(clk,  reset, FlushE, loadD, loadE);
  floprs #( 2) Ereg17(clk,  reset, FlushE, SDypeSec, SDypeSecE);
  floprs #( 3) Ereg18(clk,  reset, FlushE, funct3, funct3E);
  floprs #( 1) Ereg19(clk,  reset, FlushE, jarlD, jarlE);
  
  //REGM
  flopr #( 1) Mreg5 (clk, reset , RegWriteE, RegWriteM);
  flopr #( 2) Mreg6 (clk, reset , ResultSrcE, ResultSrcM);
  flopr #( 1) Mreg7 (clk, reset , MemWriteE, MemWriteM);
  flopr #( 1) Mreg8 (clk,  reset, loadE, loadM);
  flopr #( 2) Mreg9 (clk,  reset, SDypeSecE, SDypeSecM);
  flopr #( 1) Mreg10(clk,  reset, jarlE, jarlM);
  //REGW
  flopr #( 1) Wreg5 (clk, reset , RegWriteM, RegWriteW);
  flopr #( 2) Wreg6 (clk, reset , ResultSrcM, ResultSrcW);
  flopr #( 1) Wreg7 (clk,  reset, loadM, loadW);
  flopr #( 1) Wreg8 (clk,  reset, jarlM, jarlW);
  

    assign                              PCSrcE                    = (BranchE & branchScr) | JumpE | jarlW;
    //assign                              ResultSrcE0               = ResultSrcE[0];
endmodule

	
    




