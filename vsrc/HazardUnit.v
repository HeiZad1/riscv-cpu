module HazardUnit(
					input  	 				RegWriteW,RegWriteM,
					input    		[4:0]	rdw,rdm,rde,
					input    				ResultSrcE0,PCsrc,
					input    		[4:0]	rs1e,rs2e,rs1d,rs2d,
					output   reg	[1:0]   forwardae,forwardbe,
					output   reg			flushe,flushd,
					output   reg			stallf,stalld);
					
	reg   lwStall;
					
	always@(*) begin
	lwStall = 0;
	if  (((rs1e == rdm) & RegWriteM) & (rs1e != 0)) 
		forwardae = 2'b10;
	else if
		(((rs1e == rdw) & RegWriteW) & (rs1e != 0)) 
		forwardae = 2'b01;
	else 
		forwardae = 2'b00;
	
	if  (((rs2e == rdm) & RegWriteM) & (rs2e != 0)) 
		forwardbe = 2'b10;
	else if
		(((rs2e == rdw) & RegWriteW) & (rs2e != 0)) 
		forwardbe = 2'b01;
	else 
		forwardbe = 2'b00;
	
		lwStall = ResultSrcE0 && ((rs1d == rde) || (rs2d == rde)) ;
		flushd = PCsrc;
		flushe = lwStall || PCsrc;
		
			stalld = lwStall;
			stallf = lwStall;
			
		
		

	
		end
		
	
		
	
endmodule

