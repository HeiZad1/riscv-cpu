`include "RV32I_defines.v"

// RISC-V  processor
// 2024.2
// songwenfei999@gmail.com

// run 210
// Expect simulator to print "Simulation succeeded"
// when the value 25 (0x19) is written to address 100 (0x64)





module rv32i(
    input                               clock                        ,
    input                               reset                      ,
    input                               io_interrupt               ,

    //output             [`XLEN-1: 0]     WriteData                  ,
    //output             [`XLEN-1: 0]     DataAdr                    ,
    //output                              MemWrite                   
    
    input                       io_master_awready           ,
    output                       io_master_awvalid           ,
    output      [ 3:0]                 io_master_awid              ,
    output      [31:0]                 io_master_awaddr            ,
    output      [ 7:0]                 io_master_awlen             ,
    output      [ 2:0]                 io_master_awsize            ,
    output      [ 1:0]                 io_master_awburst           ,

    input                       io_master_wready            ,
    output                      io_master_wvalid            ,
    output      [63:0]                 io_master_wdata             ,
    output      [7:0]                io_master_wstrb             ,
    output                       io_master_wlast             ,
    output                       io_master_bready            ,
    
    input                       io_master_bvalid            ,
    input      [ 3:0]                 io_master_bid               ,
    input      [ 1:0]                 io_master_bresp             ,
    input                       io_master_arready           ,

    output                       io_master_arvalid           ,
    output     [ 3:0]                  io_master_arid              ,
    output     [31:0]                  io_master_araddr            ,
    output     [ 7:0]                  io_master_arlen             ,
    output     [ 2:0]                  io_master_arsize            ,
    output     [ 1:0]                  io_master_arburst           ,
    output                       io_master_rready            ,

    input                       io_master_rvalid            ,
    input      [ 3:0]                 io_master_rid               ,
    input      [63:0]                 io_master_rdata             ,
    input      [ 1:0]                  io_master_rresp             ,
    input                       io_master_rlast             ,


    output                       io_slave_awready            ,
    input                       io_slave_awvalid            ,
    input     [ 3:0]                  io_slave_awid               ,
    input     [31:0]                  io_slave_awaddr             ,
    input     [ 7:0]                  io_slave_awlen              ,
    input     [ 2:0]                  io_slave_awsize             ,
    input     [ 1:0]                  io_slave_awburst            ,
    output                       io_slave_wready             ,
    input                       io_slave_wvalid             ,
    input     [63:0]                 io_slave_wdata              ,
    input     [ 7:0]                 io_slave_wstrb              ,
    input                       io_slave_wlast              ,
    input                       io_slave_bready             ,
    output                       io_slave_bvalid             ,
    output    [ 3:0]                   io_slave_bid                ,
    output    [ 1:0]                   io_slave_bresp             ,
    output                      io_slave_arready            ,
    input                       io_slave_arvalid            ,
    input     [ 3:0]                  io_slave_arid               ,
    input     [31:0]                  io_slave_araddr             ,
    input     [ 7:0]                 io_slave_arlen              ,
    input     [ 2:0]                  io_slave_arsize             ,
    input     [ 1:0]                  io_slave_arburst            ,
    input                       io_slave_rready             ,
    output                       io_slave_rvalid             ,
    output    [ 3:0]                   io_slave_rid                ,
    output    [63:0]                   io_slave_rdata              ,
    output    [ 1:0]                   io_slave_rresp              ,
    output                       io_slave_rlast              
  );	// src/CPU.scala:38:21
                      
    assign                              io_slave_awready = 1'b0;
    assign                              io_slave_wready  = 1'b0;
    assign                              io_slave_bvalid  = 1'b0;
    assign                              io_slave_arready = 1'b0;
    assign                             io_slave_bid   = 4'b0             ;
    assign                             io_slave_bresp  = 2'b0          ;
    assign                       io_slave_rvalid      = 1'b0            ;
    assign                             io_slave_rid   =4'b0             ;
    assign                             io_slave_rdata  =64'b0            ;
    assign                             io_slave_rresp  =2'b0            ;
    assign                       io_slave_rlast        = 1'b0             ;

    wire               [`XLEN-1: 0]     PC                         ;
    wire               [`XLEN-1: 0]     Instr                      ;
    wire               [`XLEN-1: 0]     ReadData                   ;
    wire               [`XLEN-1: 0]     DataAdr                   ;
    wire               [`XLEN-1: 0]     mask                       ;
    wire               [`XLEN-1: 0]     WriteData                   ;
    wire                                MemWrite                    ;

    wire                                io_master_awready_m           ; 
    wire                                io_master_awvalid_m           ; 
    wire               [31:0]                 io_master_awaddr_m            ; 
    wire               [ 3:0]                 io_master_awid_m              ;
    wire               [ 7:0]                 io_master_awlen_m             ; 
    wire               [ 2:0]                 io_master_awsize_m            ; 
    wire               [ 1:0]                 io_master_awburst_m           ; 
    wire                                io_master_wready_m            ; 
    wire                                io_master_wvalid_m            ; 
    wire               [63:0]                 io_master_wdata_m             ; 
    wire               [ 7:0]                 io_master_wstrb_m             ; 
    wire                                io_master_wlast_m             ; 
    wire                                io_master_bready_m            ; 
    wire                                io_master_bvalid_m            ; 
    wire               [ 1:0]                 io_master_bresp_m             ; 
    wire               [ 3:0]                 io_master_bid_m               ; 
    wire                                io_master_arready_m           ; 
    wire                                io_master_arvalid_m           ; 
    wire               [31:0]                 io_master_araddr_m            ; 
    wire               [ 3:0]                 io_master_arid_m              ; 
    wire               [ 7:0]                 io_master_arlen_m             ; 
    wire               [ 2:0]                 io_master_arsize_m            ; 
    wire               [ 1:0]                 io_master_arburst_m           ; 
    wire                                io_master_rready_m            ; 
    wire                                io_master_rvalid_m            ; 
    wire              [ 1:0]                  io_master_rresp_m             ; 
    wire              [63:0]                  io_master_rdata_m             ; 
    wire                                io_master_rlast_m             ; 
    wire              [ 3:0]                  io_master_rid_m               ; 

    wire                                io_master_awready_s           ; 
    wire                                io_master_awvalid_s           ; 
    wire              [31:0]                  io_master_awaddr_s            ; 
    wire              [ 3:0]                  io_master_awid_s              ;
    wire              [ 7:0]                  io_master_awlen_s             ; 
    wire              [ 2:0]                  io_master_awsize_s            ; 
    wire              [ 1:0]                  io_master_awburst_s           ; 
    wire                                io_master_wready_s            ; 
    wire                                io_master_wvalid_s            ; 
    wire              [63:0]                  io_master_wdata_s             ; 
    wire              [ 7:0]                  io_master_wstrb_s             ; 
    wire                                io_master_wlast_s             ; 
    wire                                io_master_bready_s            ; 
    wire                                io_master_bvalid_s            ; 
    wire              [ 1:0]                  io_master_bresp_s             ; 
    wire              [ 3:0]                  io_master_bid_s               ; 
    wire                                io_master_arready_s           ; 
    wire                                io_master_arvalid_s           ; 
    wire              [31:0]                  io_master_araddr_s            ; 
    wire              [ 3:0]                  io_master_arid_s              ; 
    wire              [ 7:0]                  io_master_arlen_s             ; 
    wire              [ 2:0]                  io_master_arsize_s            ; 
    wire              [ 1:0]                  io_master_arburst_s           ; 
    wire                                io_master_rready_s            ; 
    wire                                io_master_rvalid_s            ; 
    wire              [ 1:0]                  io_master_rresp_s             ; 
    wire              [63:0]                  io_master_rdata_s             ; 
    wire                                io_master_rlast_s             ; 
    wire              [ 3:0]                  io_master_rid_s               ; 
  // instantiate processor and memories
  riscv rv(clock, reset, PC, Instr, MemWrite, DataAdr,
                       WriteData, mask,ReadData);
  //imem imem(PC, Instr);
  //dmem dmem(clk, MemWrite, DataAdr, WriteData, mask,ReadData);
AXI_FULL_M_module axi_m_if(
  .M_AXI_ACLK     (clock)           ,
  .M_AXI_ARESETN  (reset)           ,
  .addr           (PC)           ,
  .read_data      (Instr)           ,
  .write_data     (),             
  .M_AXI_AWREADY  (io_master_awready_m )           ,
  .M_AXI_AWVALID  (io_master_awvalid_m)           ,
  .M_AXI_AWADDR   (io_master_awaddr_m)           ,
  .M_AXI_AWID     (io_master_awid_m)           ,
  .M_AXI_AWLEN    (io_master_awlen_m)           ,
  .M_AXI_AWSIZE   (io_master_awsize_m)           ,
  .M_AXI_AWBURST  (io_master_awburst_m)           ,
  .M_AXI_WREADY   (io_master_wready_m)           ,
  .M_AXI_WVALID   (io_master_wvalid_m)           ,
  .M_AXI_WDATA    (io_master_wdata_m)           ,
  .M_AXI_WSTRB    (io_master_wstrb_m)           ,
  .M_AXI_WLAST    (io_master_wlast_m)           ,
  .M_AXI_BREADY   (io_master_bready_m)           ,
  .M_AXI_BVALID   (io_master_bvalid_m)           ,
  .M_AXI_BRESP    (io_master_bresp_m)           ,
  .M_AXI_BID      (io_master_bid_m)           ,
  .M_AXI_ARREADY  (io_master_arready_m )           ,
  .M_AXI_ARVALID  (io_master_arvalid_m)           ,
  .M_AXI_ARADDR   (io_master_araddr_m)           ,
  .M_AXI_ARID     (io_master_arid_m)           ,
  .M_AXI_ARLEN    (io_master_arlen_m)           ,
  .M_AXI_ARSIZE   (io_master_arsize_m)           ,
  .M_AXI_ARBURST  (io_master_arburst_m)           ,
  .M_AXI_RREADY   (io_master_rready_m)           ,
  .M_AXI_RVALID   (io_master_rvalid_m)           ,
  .M_AXI_RRESP    (io_master_rresp_m)           ,
  .M_AXI_RDATA    (io_master_rdata_m)           ,
  .M_AXI_RLAST    (io_master_rlast_m)           ,
  .M_AXI_RID      (io_master_rid_m)            
  );

  AXI_FULL_M_module axi_m_we(
  .M_AXI_ACLK     (clock)           ,
  .M_AXI_ARESETN  (reset)           ,
  .addr           (DataAdr)           ,
  .read_data      (ReadData)           ,
  .write_data     (WriteData),             
  .M_AXI_AWREADY  (io_master_awready_s )           ,
  .M_AXI_AWVALID  (io_master_awvalid_s)           ,
  .M_AXI_AWADDR   (io_master_awaddr_s)           ,
  .M_AXI_AWID     (io_master_awid_s)           ,
  .M_AXI_AWLEN    (io_master_awlen_s)           ,
  .M_AXI_AWSIZE   (io_master_awsize_s)           ,
  .M_AXI_AWBURST  (io_master_awburst_s)           ,
  .M_AXI_WREADY   (io_master_wready_s)           ,
  .M_AXI_WVALID   (io_master_wvalid_s)           ,
  .M_AXI_WDATA    (io_master_wdata_s)           ,
  .M_AXI_WSTRB    (io_master_wstrb_s)           ,
  .M_AXI_WLAST    (io_master_wlast_s)           ,
  .M_AXI_BREADY   (io_master_bready_s)           ,
  .M_AXI_BVALID   (io_master_bvalid_s)           ,
  .M_AXI_BRESP    (io_master_bresp_s)           ,
  .M_AXI_BID      (io_master_bid_s)           ,
  .M_AXI_ARREADY  (io_master_arready_s)           ,
  .M_AXI_ARVALID  (io_master_arvalid_s)           ,
  .M_AXI_ARADDR   (io_master_araddr_s)           ,
  .M_AXI_ARID     (io_master_arid_s)           ,
  .M_AXI_ARLEN    (io_master_arlen_s)           ,
  .M_AXI_ARSIZE   (io_master_arsize_s)           ,
  .M_AXI_ARBURST  (io_master_arburst_s)           ,
  .M_AXI_RREADY   (io_master_rready_s)           ,
  .M_AXI_RVALID   (io_master_rvalid_s)           ,
  .M_AXI_RRESP    (io_master_rresp_s)           ,
  .M_AXI_RDATA    (io_master_rdata_s)           ,
  .M_AXI_RLAST    (io_master_rlast_s)           ,
  .M_AXI_RID      (io_master_rid_s)            
  );



axi_arbiter u_axi_arbiter(
	.clk          	( clock              ),
	.reset        	( reset              ),
	.cpu1_awvalid 	( io_master_awvalid_m  ),
	.cpu1_awready 	( io_master_awready_m  ),
	.cpu1_awaddr  	( io_master_awaddr_m  ),
	.cpu1_awid    	( io_master_awid_m  ),
	.cpu1_awlen   	( io_master_awlen_m  ),
	.cpu1_awsize  	( io_master_awsize_m  ),
	.cpu1_awburst 	( io_master_awburst_m  ),
	.cpu1_wvalid  	( io_master_wvalid_m  ),
	.cpu1_wready  	( io_master_wready_m  ),
	.cpu1_wdata   	( io_master_wdata_m  ),
	.cpu1_wstrb   	( io_master_wstrb_m  ),
	.cpu1_wlast   	( io_master_wlast_m  ),
	.cpu1_bvalid  	( io_master_bvalid_m  ),
	.cpu1_bready  	( io_master_bready_m  ),
	.cpu1_bresp   	( io_master_bresp_m  ),
	.cpu1_bid     	( io_master_bid_m  ),
	.cpu1_arvalid 	( io_master_arvalid_m  ),
	.cpu1_arready 	( io_master_arready_m  ),
	.cpu1_araddr  	( io_master_araddr_m  ),
	.cpu1_arid    	( io_master_arid_m  ),
	.cpu1_arlen   	( io_master_arlen_m  ),
	.cpu1_arsize  	( io_master_arsize_m  ),
	.cpu1_arburst 	( io_master_arburst_m  ),
	.cpu1_rvalid  	( io_master_rvalid_m  ),
	.cpu1_rready  	( io_master_rready_m  ),
	.cpu1_rdata   	( io_master_rdata_m  ),
	.cpu1_rresp   	( io_master_rresp_m  ),
	.cpu1_rlast   	( io_master_rlast_m  ),
	.cpu1_rid     	( io_master_rid_m  ),

	.cpu2_awvalid 	( io_master_awvalid_s  ),
	.cpu2_awready 	( io_master_awready_s  ),
	.cpu2_awaddr  	( io_master_awaddr_s  ),
	.cpu2_awid    	( io_master_awid_s  ),
	.cpu2_awlen   	( io_master_awlen_s  ),
	.cpu2_awsize  	( io_master_awsize_s  ),
	.cpu2_awburst 	( io_master_awburst_s  ),
	.cpu2_wvalid  	( io_master_wvalid_s  ),
	.cpu2_wready  	( io_master_wready_s  ),
	.cpu2_wdata   	( io_master_wdata_s  ),
	.cpu2_wstrb   	( io_master_wstrb_s  ),
	.cpu2_wlast   	( io_master_wlast_s  ),
	.cpu2_bvalid  	( io_master_bvalid_s  ),
	.cpu2_bready  	( io_master_bready_s  ),
	.cpu2_bresp   	( io_master_bresp_s  ),
	.cpu2_bid     	( io_master_bid_s  ),
	.cpu2_arvalid 	( io_master_arvalid_s  ),
	.cpu2_arready 	( io_master_arready_s  ),
	.cpu2_araddr  	( io_master_araddr_s  ),
	.cpu2_arid    	( io_master_arid_s  ),
	.cpu2_arlen   	( io_master_arlen_s  ),
	.cpu2_arsize  	( io_master_arsize_s  ),
	.cpu2_arburst 	( io_master_arburst_s  ),
	.cpu2_rvalid  	( io_master_rvalid_s  ),
	.cpu2_rready  	( io_master_rready_s  ),
	.cpu2_rdata   	( io_master_rdata_s  ),
	.cpu2_rresp   	( io_master_rresp_s  ),
	.cpu2_rlast   	( io_master_rlast_s  ),
	.cpu2_rid     	( io_master_rid_s  ),

	.xbar_awvalid 	( io_master_awvalid  ),
	.xbar_awready 	( io_master_awready  ),
	.xbar_awaddr  	( io_master_awaddr   ),
	.xbar_awid    	( io_master_awid     ),
	.xbar_awlen   	( io_master_awlen    ),
	.xbar_awsize  	( io_master_awsize   ),
	.xbar_awburst 	( io_master_awburst  ),
	.xbar_wvalid  	( io_master_wvalid   ),
	.xbar_wready  	( io_master_wready   ),
	.xbar_wdata   	( io_master_wdata    ),//
	.xbar_wstrb   	( io_master_wstrb    ),
	.xbar_wlast   	( io_master_wlast    ),
	.xbar_bvalid  	( io_master_bvalid   ),
	.xbar_bready  	( io_master_bready   ),
	.xbar_bresp   	( io_master_bresp    ),
	.xbar_bid     	( io_master_bid      ),
	.xbar_arvalid 	( io_master_arvalid  ),
	.xbar_arready 	( io_master_arready  ),
	.xbar_araddr  	( io_master_araddr   ),
	.xbar_arid    	( io_master_arid     ),
	.xbar_arlen   	( io_master_arlen    ),
	.xbar_arsize  	( io_master_arsize   ),
	.xbar_arburst 	( io_master_arburst  ),
	.xbar_rvalid  	( io_master_rvalid   ),
	.xbar_rready  	( io_master_rready   ),
	.xbar_rdata   	( io_master_rdata    ),//
	.xbar_rresp   	( io_master_rresp    ),
	.xbar_rlast   	( io_master_rlast    ),
	.xbar_rid     	( io_master_rid      )
);

endmodule

