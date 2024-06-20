`include "RV32I_defines.v"

module regfile(input          clk,
               input          we3, 
               input   [`RFIDX_WIDTH-1:0] a1, 
			   input   [`RFIDX_WIDTH-1:0] a2,
			   input   [`RFIDX_WIDTH-1:0] a3, 
               input   [`XLEN-1:0] wd3, 
               output  [`XLEN-1:0] rd1, 
			   output  [`XLEN-1:0] rd2
         );

  reg [`XLEN-1:0] rf[`RFREG_NUM-1:0];
  // three ported register file
  // read two ports combinationally (A1/RD1, A2/RD2)
  // write third port on rising edge of clock (A3/WD3/WE3)
  // register 0 hardwired to 0
  initial rf[0] = 0;

  always @(negedge clk)
    if (we3 & (a3 !=0)) rf[a3] <= wd3;	
  assign rd1 = ((we3 && (a1 == a3)) ? wd3 : (a1 != 0) ? rf[a1] : 0);
  assign rd2 = ((we3 && (a2 == a3)) ? wd3 : (a2 != 0) ? rf[a2] : 0);
	 
    
endmodule

