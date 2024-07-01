module floprPC #(parameter WIDTH = 32)
              (input                     clk, reset,en,
               input         [WIDTH-1:0] d, 
               output  reg   [WIDTH-1:0] q);

  always @(posedge clk or posedge reset)
    if (reset)         q <= 32'H80000000;
    else if (en)       q <= d;
endmodule

