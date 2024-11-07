`include "RV32I_defines.v"
module Vregfile(
            input                       clk,
            input   [1:0]               vwe, 
            input   [`RFIDX_WIDTH-1:0]  va1, 
			input   [`RFIDX_WIDTH-1:0]  va2,
			input   [`RFIDX_WIDTH-1:0]  va3,
            input   [`RFIDX_WIDTH-1:0]  va4,
            input   [`RFIDX_WIDTH-1:0]  va5,
            input   [`RFIDX_WIDTH-1:0]  va6,
            //input   [`RFIDX_WIDTH-1:0] va7,
            //input   [`RFIDX_WIDTH-1:0] va8, 
            input   [`XLEN_VEC-1-1:0]         vwd1, 
            input   [`XLEN_VEC-1:0]         vwd2,
            //input   [`XLEN-1:0] vwd3,
            //input   [`XLEN-1:0] vwd4,
            output  [`XLEN_VEC-1:0]         vrd1,
            output  [`XLEN_VEC-1:0]         vrd2,
            output  [`XLEN_VEC-1:0]         vrd3,
            output  [`XLEN_VEC-1:0]         vrd4,
            //output  [`XLEN-1:0] vrd5,
            //output  [`XLEN-1:0] vrd6,
            //output  [`XLEN-1:0] vrd7, 
			//output  [`XLEN-1:0] vrd8

) ;
    reg [`XLEN_VEC-1:0] vrf[`RFREG_NUM-1:0];
always @(negedge clk) begin
    if (vwe[0] & (va5 !=0)) vrf[va5] <= vwd1;
    if (vwe[1] & (va6 !=0)) vrf[va6] <= vwd2;	

end
  assign vrd1 = ( (va1 != 0) ? vrf[va1] : 0);
  assign vrd2 = ( (va2 != 0) ? vrf[va2] : 0);
  assign vrd3 = ( (va3 != 0) ? vrf[va3] : 0);
  assign vrd4 = ( (va4 != 0) ? vrf[va4] : 0);
  //assign vrd5 = ( (va5 != 0) ? vrf[va5] : 0);
  //assign vrd6 = ( (va6 != 0) ? vrf[va6] : 0);
  //assign vrd7 = ( (va7 != 0) ? vrf[va7] : 0);
  //assign vrd8 = ( (va8 != 0) ? vrf[va8] : 0);
endmodule