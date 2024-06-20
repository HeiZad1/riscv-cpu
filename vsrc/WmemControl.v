module WmemControl(input   		[`XLEN-1:0] WriteDataM,
				   input   		[1:0]  WDypesrc,
				   input   		[1:0] a,
				   output  reg	[`XLEN-1:0] write_mask,
				   output  reg  [`XLEN-1:0] WData);
 
  always@(*) begin
    case(WDypesrc)  
      2'b00:    begin  // Sw
				WData = WriteDataM;
			    write_mask = 32'hFFFFFFFF;	
				end				
      2'b01:    begin  // Sh  
				WData  = WriteDataM << (8 * {2'b0, a[1]}); 
                write_mask = 32'h0000FFFF << (8 * {2'b0, a[1]}); 
				end
      2'b10:    begin  // sb
				WData = WriteDataM << (8 * a[1:0]);
                write_mask = 32'h000000FF << (8 * a[1:0]); 
				end
        
      default: begin
				WData = `XLEN'bx; // undefined
				write_mask = `XLEN'bx; // undefined
      end
    endcase  
	end	
endmodule







