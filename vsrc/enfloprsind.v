module enfloprsind #(parameter WIDTH = 8)
              (input                    clk, reset,clr,en,
               input        [WIDTH-1:0] d, 
               output reg   [WIDTH-1:0] q);

  always @(posedge clk )
    if (reset)         q <= 0;
	else if(clr)		q <= `NOP;
    else if (en)       q <= d;
endmodule

