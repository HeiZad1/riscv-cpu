module aludec(input              opb5,
    input              [   2: 0]        funct3                     ,
    input                               funct7b5                   ,
    input              [   1: 0]        ALUOp                      ,
    output reg         [   3: 0]        ALUControl                );  

    wire                                RtypeSub,RtypeSra          ;
    assign                              RtypeSub                  = funct7b5 & opb5;// TRUE for R-type subtract instruction
    assign                              RtypeSra                  = funct7b5 & opb5;

  always@(*) begin
    case(ALUOp)
      2'b00:                ALUControl = 4'b0000;                   // addition
      2'b01:   case(funct3)                                         // B-type ALU 
                 3'b000:    ALUControl = 4'b0001;                   // BEQ
                 3'b001:    ALUControl = 4'b0001;                   // BNE
                 3'b011:    ALUControl = 4'b1000;                   // BLT
                 3'b100:    ALUControl = 4'b0100;                   // BGE
                 3'b110:    ALUControl = 4'b0011;                   // BLTU
                 3'b111:    ALUControl = 4'b0010;                   // BGEU
                 default:   ALUControl = 4'bxxxx;                   // ???
               endcase
      default: case(funct3)                                         // R-type or I-type ALU
                 3'b000:  if (RtypeSub)
                            ALUControl = 4'b0001;                   // sub
                          else
                            ALUControl = 4'b0000;                   // add, addi
                 3'b001:    ALUControl = 4'b0110;                   // sll, slli
                 3'b010:    ALUControl = 4'b1001;                   // slt, slti
                 3'b011:    ALUControl = 4'b1000;                   // sltu,sltui
                 3'b100:    ALUControl = 4'b0100;                   // xor, xori
                 3'b110:    ALUControl = 4'b0011;                   // or, ori
                 3'b101:  if (RtypeSra)
                            ALUControl = 4'b0101;                   // sra, srai
                          else
                            ALUControl = 4'b0111;                   // srl, srli
                 3'b111:    ALUControl = 4'b0010;                   // and, andi	
                 default:   ALUControl = 4'bxxxx;                   // ???
               endcase
    endcase
    end
endmodule

