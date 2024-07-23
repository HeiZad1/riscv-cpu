module maindec(
    input   [6:0] op,
    output             [   1: 0]        ResultSrcD                 ,
    output                              MemWriteD                  ,
    output                              BranchD, ALUSrcD           ,
    output                              RegWriteD, JumpD,load,jarl ,
    output                              MemRead                    ,
    output             [   2: 0]        ImmSrcD                    ,
    output             [   1: 0]        ALUOp                     );  

    reg                [  14: 0]        controls                   ;

  assign {RegWriteD, ImmSrcD, ALUSrcD, MemWriteD,
          ResultSrcD, BranchD, ALUOp, JumpD,load,jarl,MemRead} = controls;

  always@(*) begin
    case(op)
    // RegWrite_ImmSrc_ALUSrc_MemWrite_ResultSrc_Branch_ALUOp_Jump_load_JARL_MemRead
      7'b0000011: controls = 15'b1_000_1_0_01_0_00_0_1_0_1;           // lw
      7'b0100011: controls = 15'b0_001_1_1_00_0_00_0_0_0_0;           // sw
      7'b0110011: controls = 15'b1_xxx_0_0_00_0_10_0_0_0_0;           // R-type 
      7'b1100011: controls = 15'b0_010_0_0_00_1_01_0_0_0_0;           // beq
      7'b0010011: controls = 15'b1_000_1_0_00_0_10_0_0_0_0;           // I-type ALU
      7'b1101111: controls = 15'b1_011_0_0_10_0_00_1_0_0_0;           // jal  
      7'b1100111: controls = 15'b1_000_1_0_00_0_00_1_0_1_0;           // jarl
      7'b0110111: controls = 15'b1_100_1_0_00_0_00_0_0_0_0;           // LUI
      7'b0010111: controls = 15'b1_100_1_0_11_0_00_0_0_0_0;           // AUIPC
      default:    controls = 15'bx_xxx_x_x_xx_x_xx_x_x_x_0;           // non-implemented instruction
    endcase
end
endmodule


