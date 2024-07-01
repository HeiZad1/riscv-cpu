module sDypedec(
    input              [   2: 0]        funct3                     ,
    output reg         [   1: 0]        SDypeSec                  );  

  

  always@(*) begin
    
     case(funct3)
        
               // Sw 
        3'b010:   SDypeSec = 2'b00;
               // Sh
        3'b001:   SDypeSec = 2'b01;
               // Sb
        3'b000:   SDypeSec = 2'b10;
			   
        
      default: SDypeSec = 2'bxx;                                    // undefined
     endcase
    end
endmodule

