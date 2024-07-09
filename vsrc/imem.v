module imem(
            input          clk,re,
            input      [31:0] a,
            output reg [31:0] rd);

  //reg [31:0] RAM[63:0];
  import "DPI-C" function int read_imem(input int addr);

  //initial
      //$readmemh("riscvtest.txt",RAM);

  //assign rd = RAM[a[7:2]]; // word aligned
  
  always @(posedge clk) begin
    if (re) rd <= read_imem(a);
  end
  //assign rd = read_imem(a);
endmodule


