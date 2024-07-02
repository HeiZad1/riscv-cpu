module dmem(input          clk, we,
            input   [31:0] a, 
            input   [31:0] wd,
			input   [31:0] write_mask,
            output  [31:0] rd);

  //reg [31:0] RAM[63:0];


  import "DPI-C" function int read_dmem(input int addr);
  import "DPI-C" function void write_imem(input int addr, input int data);

  //assign rd = RAM[a[31:2]]; // word aligned
    assign rd =  read_dmem(a);
  always @(posedge clk) begin
    //if (we) RAM[a[31:2]] <= (RAM[a[31:2]] & ~write_mask) | (wd & write_mask);
    //if (we) write_dmem(addr, wdata);
    int masked_data;
      masked_data =  (wd & write_mask);
      if (we) write_imem(a, masked_data);
  end
endmodule

