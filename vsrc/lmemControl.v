`include "RV32I_defines.v"

module lmemControl(input   		[`XLEN-1:0] ResultW,
				   input   		[2:0]  		funct3,
				   input    	   			load,
				   output  reg  [`XLEN-1:0] lData);
 
  always@(*) begin
  if(load) begin
    case(funct3) 
               // lb 
      3'b000:   lData = {{24{ResultW[7]}},ResultW[ 7:0]};
               // lh
      3'b001:   lData = {{16{ResultW[15]}},ResultW[15:0]}; 
			   // lw
	  3'b010:   lData = ResultW;
               // lbu
      3'b100:   lData = {{24{1'b0}},ResultW[ 7:0]}; 
			   // lhu
      3'b101:   lData = {{16{1'b0}},ResultW[15:0]};
        
      default: lData = `XLEN'bx; // undefined
    endcase
	end else  begin
		lData = ResultW;
		end
	end
endmodule



