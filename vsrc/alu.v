`include "RV32I_defines.v"

module alu(
            input   [`XLEN-1:0] a,
		        input   [`XLEN-1:0] b,
            input   [3:0]  alucontrol,
            output   reg [`XLEN-1:0] result,
            output         zero,
		        output		  l);

  wire [`XLEN-1:0] condinvb;
  wire [`XLEN-1:0] sum;
  //wire        			  v;              // overflow
  //wire        			  isAddSub;       // true when is add or subtract operation

  assign condinvb = alucontrol[0] ? ~b : b;
  assign sum = a + condinvb + {31'b0,alucontrol[0]};
  //assign isAddSub = ~alucontrol[2] & ~alucontrol[1] |
    //                ~alucontrol[1] & alucontrol[0];

  always @(*)
    case (alucontrol)
      4'b0000:  result = sum;         // add
      4'b0001:  result = sum;         // subtract
      4'b0010:  result = a & b;       // and
      4'b0011:  result = a | b;       // or
      4'b0100:  result = a ^ b;       // xor
      4'b1001:  result = ($signed(a) < $signed(b))?32'b1:32'b0; // slt 
      4'b0110:  result = a << b[4:0]; // sll
      4'b0111:  result = a >> b[4:0]; // srl
	    4'b1000:  result = (a < b)?32'b1:32'b0;//sltu
	    4'b0101:	result = a >>>b[4:0]; // sra
      default: result = 32'bx;
    endcase

  assign zero = (result == 32'b0);
  //assign v = ~(alucontrol[0] ^ a[31] ^ b[31]) & (a[31] ^ sum[31]) & isAddSub;
  assign l = (result == 32'b1)&alucontrol[3];
endmodule


