`include "RV32I_defines.v"
module adder(input  [`XLEN-1:0] a, b,
             output [`XLEN-1:0] y);

  assign y = a + b;
endmodule

