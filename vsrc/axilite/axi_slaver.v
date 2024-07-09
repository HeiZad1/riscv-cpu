module axi_slaver(
        input                   ACLK,
        input                   ARESETN,

        output  reg   [31:0]         addr,
        input   [31:0]         read_data,
        output   [31:0]         write_data,
        output  reg   [31:0]         addr_w,
        output                  ren,

        //read addr channel
        input   [31:0]          ARADDR,
        //input   [:0]         ARCACHE,
        input                   ARVALID,
        //input                   ARPROT,
        output                  ARREADY,

        //read data channel
        output   [31:0]         RDATA, //Read Data (32-bit only).
        //output   [ 1:0]         RRESP,
        output    reg              RVALID,
        input                   RREADY,


         //write addr channel
         /* verilator lint_off UNDRIVEN */
        input  [31:0]           AWADDR,
        /* verilator lint_off UNDRIVEN */
        //input  [ 3:0]           AWPROT,
        input                   AWVALID,
        output                  AWREADY,


        //write data channel
        input  [31:0]         WDATA,
        //input  [ 3:0]         WSTRB,  //mask
        input                  WVALID,
        output                 WREADY,

        //Write Response Channel
        //output   [ 1:0]         BRESP,
        output   reg               BVALID,
        input                  BREADY
   );

       reg r_ARREADY;
    reg r_RVALID;
    reg r_AWREADY;
    reg r_WREADY;
    reg r_BVALID;

    // Assign internal signals to outputs
    assign ARREADY = r_ARREADY;
    assign AWREADY = r_AWREADY;
    assign WREADY = r_WREADY;
    assign RVALID = r_RVALID;

    // Read address handshake
    always @(posedge ACLK or posedge ARESETN) begin
        if (ARESETN) begin
            r_ARREADY <= 1'b0;
            addr <= 32'b0;
        end else if (ARVALID && !r_ARREADY) begin
            r_ARREADY <= 1'b1;
        end else if (ARVALID && r_ARREADY) begin
            r_ARREADY <= 1'b0;
            addr <= ARADDR;
        end else begin
            r_ARREADY <= r_ARREADY;
        end
    end 

    // Read data valid and data assignment
    always @(posedge ACLK or posedge ARESETN) begin
        if (ARESETN) begin
            r_RVALID <= 1'b0;
            RDATA <= 32'b0;
        end else if (r_RVALID & RREADY) begin
            r_RVALID <= 1'b0;
        end else if (ARVALID && r_ARREADY) begin
            r_RVALID <= 1'b1;
            RDATA <= read_data;
        end else begin
            r_RVALID <= r_RVALID;
            RDATA <= RDATA;
        end
    end

    // Read enable signal generation
    always @(posedge ACLK or posedge ARESETN) begin
        if (ARESETN) begin
            ren <= 1'b0;
        end else if (ARVALID && r_ARREADY) begin
            ren <= 1'b1;
        end else begin
            ren <= 1'b0;
        end
    end

    // Write address handshake
    always @(posedge ACLK or posedge ARESETN ) begin
        if (ARESETN) begin
            r_AWREADY <= 1'b0;
        end else if (AWVALID) begin
            r_AWREADY <= 1'b1;
        end else begin
            r_AWREADY <= r_AWREADY;
        end
    end

    // Write data handshake
    always @(posedge ACLK or posedge ARESETN) begin
        if (ARESETN) begin
            r_WREADY <= 1'b0;
        end else if (WVALID) begin
            r_WREADY <= 1'b1;
        end else begin
            r_WREADY <= r_WREADY;
        end
    end

    // Write data processing and response generation
    always @(posedge ACLK or posedge ARESETN) begin
        if (ARESETN) begin
            r_AWREADY <= 1'b0;
            r_BVALID <= 1'b0;
            r_WREADY <= 1'b0;
        end else if ((AWVALID & r_AWREADY) & (WREADY & WVALID)) begin
            r_AWREADY <= 1'b0;
            r_WREADY <= 1'b0;
            write_data <= WDATA;
            r_BVALID <= 1'b1;
            addr_w <= AWADDR;
        end else begin
            r_AWREADY <= r_AWREADY;
            r_BVALID <= r_BVALID;
            r_WREADY <= r_WREADY;
        end
    end

    // Write response valid
    always @(posedge ACLK or posedge ARESETN) begin
        if (ARESETN) begin
            r_BVALID <= 1'b0;
        end else if (r_BVALID & BREADY) begin
            r_BVALID <= 1'b0;
        end else begin
            r_BVALID <= r_BVALID;
        end
    end

endmodule



