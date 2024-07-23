module axi_arbiter (
    input wire clk,
    input wire reset,

    // CPU1接口
    input wire cpu1_awvalid,
    output reg cpu1_awready,
    input wire [31:0] cpu1_awaddr,
    input wire [3:0] cpu1_awid,
    input wire [7:0] cpu1_awlen,
    input wire [2:0] cpu1_awsize,
    input wire [1:0] cpu1_awburst,
    input wire cpu1_wvalid,
    output reg cpu1_wready,
    input wire [63:0] cpu1_wdata,
    input wire [7:0] cpu1_wstrb,
    input wire cpu1_wlast,
    output reg cpu1_bvalid,
    input wire cpu1_bready,
    output reg [1:0] cpu1_bresp,
    output reg [3:0] cpu1_bid,
    input wire cpu1_arvalid,
    output reg cpu1_arready,
    input wire [31:0] cpu1_araddr,
    input wire [3:0] cpu1_arid,
    input wire [7:0] cpu1_arlen,
    input wire [2:0] cpu1_arsize,
    input wire [1:0] cpu1_arburst,
    output reg cpu1_rvalid,
    input wire cpu1_rready,
    output reg [63:0] cpu1_rdata,
    output reg [1:0] cpu1_rresp,
    output reg cpu1_rlast,
    output reg [3:0] cpu1_rid,

    // CPU2接口
    input wire cpu2_awvalid,
    output reg cpu2_awready,
    input wire [31:0] cpu2_awaddr,
    input wire [3:0] cpu2_awid,
    input wire [7:0] cpu2_awlen,
    input wire [2:0] cpu2_awsize,
    input wire [1:0] cpu2_awburst,
    input wire cpu2_wvalid,
    output reg cpu2_wready,
    input wire [63:0] cpu2_wdata,
    input wire [7:0] cpu2_wstrb,
    input wire cpu2_wlast,
    output reg cpu2_bvalid,
    input wire cpu2_bready,
    output reg [1:0] cpu2_bresp,
    output reg [3:0] cpu2_bid,
    input wire cpu2_arvalid,
    output reg cpu2_arready,
    input wire [31:0] cpu2_araddr,
    input wire [3:0] cpu2_arid,
    input wire [7:0] cpu2_arlen,
    input wire [2:0] cpu2_arsize,
    input wire [1:0] cpu2_arburst,
    output reg cpu2_rvalid,
    input wire cpu2_rready,
    output reg [63:0] cpu2_rdata,
    output reg [1:0] cpu2_rresp,
    output reg cpu2_rlast,
    output reg [3:0] cpu2_rid,

    // xbar接口
    output reg xbar_awvalid,
    input wire xbar_awready,
    output reg [31:0] xbar_awaddr,
    output reg [3:0] xbar_awid,
    output reg [7:0] xbar_awlen,
    output reg [2:0] xbar_awsize,
    output reg [1:0] xbar_awburst,
    output reg xbar_wvalid,
    input wire xbar_wready,
    output reg [63:0] xbar_wdata,
    output reg [7:0] xbar_wstrb,
    output reg xbar_wlast,
    input wire xbar_bvalid,
    output reg xbar_bready,
    input wire [1:0] xbar_bresp,
    input wire [3:0] xbar_bid,
    output reg xbar_arvalid,
    input wire xbar_arready,
    output reg [31:0] xbar_araddr,
    output reg [3:0] xbar_arid,
    output reg [7:0] xbar_arlen,
    output reg [2:0] xbar_arsize,
    output reg [1:0] xbar_arburst,
    input wire xbar_rvalid,
    output reg xbar_rready,
    input wire [63:0] xbar_rdata,
    input wire [1:0] xbar_rresp,
    input wire xbar_rlast,
    input wire [3:0] xbar_rid
);
    // 状态定义
    reg [1:0] state;
    parameter IDLE = 2'b00, CPU1 = 2'b01, CPU2 = 2'b10;

    always @(posedge clk ) begin
        if (reset) begin
            state <= IDLE;
            // 重置所有输出信号
            cpu1_awready <= 0;
            cpu1_wready <= 0;
            cpu1_bvalid <= 0;
            cpu1_arready <= 0;
            cpu1_rvalid <= 0;
            cpu1_rdata <= 0;
            cpu1_rresp <= 0;
            cpu1_rlast <= 0;
            cpu1_rid <= 0;
            cpu2_awready <= 0;
            cpu2_wready <= 0;
            cpu2_bvalid <= 0;
            cpu2_arready <= 0;
            cpu2_rvalid <= 0;
            cpu2_rdata <= 0;
            cpu2_rresp <= 0;
            cpu2_rlast <= 0;
            cpu2_rid <= 0;
            xbar_awvalid <= 0;
            xbar_awaddr <= 0;
            xbar_awid <= 0;
            xbar_awlen <= 0;
            xbar_awsize <= 0;
            xbar_awburst <= 0;
            xbar_wvalid <= 0;
            xbar_wdata <= 0;
            xbar_wstrb <= 0;
            xbar_wlast <= 0;
            xbar_bready <= 0;
            xbar_arvalid <= 0;
            xbar_araddr <= 0;
            xbar_arid <= 0;
            xbar_arlen <= 0;
            xbar_arsize <= 0;
            xbar_arburst <= 0;
            xbar_rready <= 0;
        end else begin
            case (state)
                IDLE: begin
                    // 优先级选择 CPU1 > CPU2
                    cpu1_rvalid <= 0;
                    xbar_rready <= 0;
                    cpu1_rlast <= 0;
                    if (cpu2_arvalid) begin
                        state <= CPU2;
                        cpu2_arready <= 1;
                        xbar_arvalid <= 1;
                        xbar_araddr <= cpu2_araddr;
                        xbar_arid <= cpu2_arid;
                        xbar_arlen <= cpu2_arlen;
                        xbar_arsize <= cpu2_arsize;
                        xbar_arburst <= cpu2_arburst;
                    end else if (cpu2_awvalid) begin
                        state <= CPU2;
                        cpu2_awready <= 1;
                        xbar_awvalid <= 1;
                        xbar_awaddr <= cpu2_awaddr;
                        xbar_awid <= cpu2_awid;
                        xbar_awlen <= cpu2_awlen;
                        xbar_awsize <= cpu2_awsize;
                        xbar_awburst <= cpu2_awburst;
                    end if (cpu1_arvalid) begin
                        state <= CPU1;
                        cpu1_arready <= xbar_arready;
                        xbar_arvalid <= 1;
                        xbar_araddr <= cpu1_araddr;
                        xbar_arid <= cpu1_arid;
                        xbar_arlen <= cpu1_arlen;
                        xbar_arsize <= cpu1_arsize;
                        xbar_arburst <= cpu1_arburst;
                    end else if (cpu1_awvalid) begin
                        state <= CPU1;
                        cpu1_awready <= 1;
                        xbar_awvalid <= 1;
                        xbar_awaddr <= cpu1_awaddr;
                        xbar_awid <= cpu1_awid;
                        xbar_awlen <= cpu1_awlen;
                        xbar_awsize <= cpu1_awsize;
                        xbar_awburst <= cpu1_awburst;
                    
                    end else begin
                        state <= IDLE;
                    end
                end
                CPU1: begin
                    // 处理CPU1的读写请求

 
                    if (cpu1_arvalid && xbar_arready) begin
                        xbar_arvalid <= 0;
                        cpu1_arready <= 0;
                        xbar_araddr  <= 0;
                        state <= CPU1;
                    end else if (cpu1_awvalid && xbar_awready) begin
                        xbar_awvalid <= 0;
                        cpu1_awready <= 0;
                        if (cpu1_wvalid) begin
                            xbar_wvalid <= 1;
                            xbar_wdata <= cpu1_wdata;
                            xbar_wstrb <= cpu1_wstrb;
                            xbar_wlast <= cpu1_wlast;
                            cpu1_wready <= 1;
                        end
                    end else if (cpu1_wvalid && xbar_wready) begin
                        xbar_wvalid <= 0;
                        cpu1_wready <= 0;
                        cpu1_bvalid <= xbar_bvalid;
                        cpu1_bresp <= xbar_bresp;
                        cpu1_bid <= xbar_bid;
                        if (cpu1_bready) begin
                            xbar_bready <= 1;
                        end else begin
                            xbar_bready <= 0;
                        end
                        state <= IDLE;
                    end else begin
                        state <= CPU1;
                    end
                    if (xbar_rvalid) begin
                        cpu1_rvalid <= 1;
                        cpu1_rdata <= xbar_rdata;
                        cpu1_rresp <= xbar_rresp;
                        cpu1_rlast <= 1;
                        cpu1_rid <= xbar_rid;
                        if (cpu1_rready) begin
                            xbar_rready <= 1;
                            state <= IDLE;
                        end else begin
                            xbar_rready <= 0;
                            state <= CPU1;
                        end

                    end else begin
                        xbar_rready <= 0;
                        state <= CPU1;
                    end
                end
                CPU2: begin
                    // 处理CPU2的读写请求
                    if (cpu2_arvalid && xbar_arready) begin
                        xbar_arvalid <= 0;
                        cpu2_arready <= 0;
                        state <= IDLE;
                    end else if (cpu2_awvalid && xbar_awready) begin
                        xbar_awvalid <= 0;
                        cpu2_awready <= 0;
                        if (cpu2_wvalid) begin
                            xbar_wvalid <= 1;
                            xbar_wdata <= cpu2_wdata;
                            xbar_wstrb <= cpu2_wstrb;
                            xbar_wlast <= cpu2_wlast;
                            cpu2_wready <= 1;
                        end
                    end else if (cpu2_wvalid && xbar_wready) begin
                        xbar_wvalid <= 0;
                        cpu2_wready <= 0;
                        cpu2_bvalid <= xbar_bvalid;
                        cpu2_bresp <= xbar_bresp;
                        cpu2_bid <= xbar_bid;
                        if (cpu2_bready) begin
                            xbar_bready <= 1;
                        end else begin
                            xbar_bready <= 0;
                        end
                        state <= IDLE;
                    end else begin
                        state <= CPU2;
                    end
                    if (xbar_rvalid) begin
                        cpu2_rvalid <= 1;
                        cpu2_rdata <= xbar_rdata;
                        cpu2_rresp <= xbar_rresp;
                        cpu2_rlast <= xbar_rlast;
                        cpu2_rid <= xbar_rid;
                        if (cpu2_rready) begin
                            xbar_rready <= 1;
                        end else begin
                            xbar_rready <= 0;
                        end
                        state <= IDLE;
                    end else begin
                        state <= CPU2;
                    end
                end
                default: state <=IDLE;
            endcase
        end
    end
endmodule
