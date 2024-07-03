module muxUnit(
            input  [7:0]         vrd1,
            input  [7:0]         vrd2,
            input  [7:0]         vrd3,
            input  [7:0]         vrd4,
            output  [7:0]         vrd1_o,
            output  [7:0]         vrd2_o,
            output  [7:0]         vrd3_o,
            output  [7:0]         vrd4_o

);
    import "DPI-C" function void rram(
        input  int vrd1,
        input  int vrd2,
        input  int vrd3,
        input  int vrd4,
        output int vrd1_o,
        output int vrd2_o,
        output int vrd3_o,
        output int vrd4_o,
    );
    reg [7:0] outputreg[`PUREG_NUM-1:0];
    always*(posedge clk)begin
        rram(vrd1,vrd2,vrd3,vrd4,vrd1_o,vrd2_o,vrd3_o,vrd4_o);
    end
    endmodule