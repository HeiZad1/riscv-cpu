module axiTop(
    input                           clk,
    input                           rst,
    output   [31:0]                 read_data_m,
    input    [31:0]                 addr_m,
    input    [31:0]                 write_data_m,
    input                           wen,
    input                           ren,
    //input    [31:0]                 mask, 

    output   [31:0]                 read_data_s,
    output   [31:0]                 addr_s,
    output   [31:0]                 write_data_s,

);
    wire         [31:0]             m2s_ARADDR;
    wire                            m2s_ARVALID;
    wire                            s2m_ARREADY;
    wire         [31:0]             s2m_RDATA;
    wire                            s2m_RVALID;
    wire                            m2s_RREADY;
    wire         [31:0]             m2s_AWADDR;
    wire                            m2s_AWVALID;
    wire                            s2m_AWREADY;

    wire         [31:0]             m2s_WDATA;
    wire                            m2s_WVALID;
    wire                            s2m_WREADY;
    //wire         [3:0]              s2m_BRESP;
    //wire                            s2m_BVALID;
    wire                            m2s_BREADY;
    wire        [ 3:0]              AWPROT;



axi_master  cpu2axi(
    .ACLK(clk),
    .ARESETN(rst),
    .read_address(addr_m),
    .write_start(wen),
    .read_start(ren),
    .read_data(read_data_m),
    .write_data(write_data_m),

        //read addr channel
    .ARADDR(m2s_ARADDR),
        //input   [:0]         ARCACHE,
    .ARVALID(m2s_ARVALID),
    //.ARPROT(1'b0),
    .ARREADY(s2m_ARREADY),

        //read data channel
    .RDATA(s2m_RDATA), //Read Data (32-bit only).
    //.RRESP(2'b00),
    .RVALID(s2m_RVALID),
    .RREADY(m2s_RREADY),


        //write addr channel
    .AWADDR(m2s_AWADDR),
    .AWPROT(AWPROT),
    .AWVALID(m2s_AWVALID),
    .AWREADY(s2m_AWREADY),


        //write data channel
    .WDATA(m2s_WDATA),
    //.WSTRB(4'b0000) , //mask
    .WVALID(m2s_WVALID),
    .WREADY(s2m_WREADY),

        //Write Response Channel
    //.BRESP(s2m_BRESP),
    .BVALID(s2m_BVALID),
    .BREADY(m2s_BREADY)
   );

   // outports wire



axi_slaver  axi2mem(
    .ACLK(clk),
    .ARESETN(rst),
    .addr(addr_s),
    .read_data(read_data_s),
    .write_data(write_data_s),

        //read addr channel
    .ARADDR(m2s_ARADDR),
        //input   [:0]         ARCACHE,
    .ARVALID(m2s_ARVALID),
    //.ARPROT(1'b0),
    .ARREADY(s2m_ARREADY),

        //read data channel
    .RDATA(s2m_RDATA), //Read Data (32-bit only).
    //.RRESP(2'b00),
    .RVALID(s2m_RVALID),
    .RREADY(m2s_RREADY),


        //write addr channel
    .AWADDR(m2s_AWADDR),
    .AWPROT(AWPROT),
    .AWVALID(m2s_AWVALID),
    .AWREADY(s2m_AWREADY),


        //write data channel
    .WDATA(m2s_WDATA),
    //.WSTRB(4'b0000) , //mask
    .WVALID(m2s_WVALID),
    .WREADY(s2m_WREADY),

        //Write Response Channel
    //.BRESP(s2m_BRESP),
    .BVALID(s2m_BVALID),
    .BREADY(m2s_BREADY)
   );

endmodule

