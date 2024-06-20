module Blu( 
    input              [   2: 0]        funct3                     ,
    input                               l                          ,
    input                               Zero                       ,
    output reg                          conti                       
            );
			
			
    always@(*) begin
        case(funct3)
                 3'b000:    conti = Zero;                           // BEQ
                 3'b001:    conti = ~Zero;                          // BNE
                 3'b011:    conti = l;                              // BLT
                 3'b100:    conti = ~l;                             // BGE
                 3'b110:    conti = l;                              // BLTU
                 3'b111:    conti = Zero;                           // BGEU
                 default:   conti = 1'b0;                           // ???
        endcase
        end
endmodule

