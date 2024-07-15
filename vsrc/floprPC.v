module floprPC #(parameter WIDTH = 32)
              (input                     clk, reset,en,
               input         [WIDTH-1:0] d, 
               output  reg   [WIDTH-1:0] q);

  always @(posedge clk )
    if (reset)         q <= 32'H20000000;
    else if (en)       q <= d;
endmodule

