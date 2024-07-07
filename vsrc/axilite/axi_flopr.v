`include "RV32I_defines.v"

module axi_flopr #(parameter WIDTH = 32)
              (input                    clk, reset,conti
               input        [WIDTH-1:0] d1,d2 
               output reg [WIDTH-1:0] q);

  always @(posedge clk or posedge reset)
    if (reset) q <= d1;
    else if(conti) q <= d2 ;
    else       q <= q;
endmodule