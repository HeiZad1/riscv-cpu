module imem(input   [31:0] a,
            output  [31:0] rd);

  //reg [31:0] RAM[63:0];
  import "DPI-C" function int read_imem(input int addr);

  //initial
      //$readmemh("riscvtest.txt",RAM);

  //assign rd = RAM[a[7:2]]; // word aligned
  assign rd = read_imem(a);
endmodule


