module enfloprspc4 #(parameter WIDTH = 8)
              (input                    clk, reset,clr,en,
               input        [WIDTH-1:0] d, 
               output reg   [WIDTH-1:0] q);

  always @(posedge clk )
    if (reset)         q <= `RESET_PC;
	else if(clr)		q <= `RESET_PC;
    else if (en)       q <= d;
endmodule

