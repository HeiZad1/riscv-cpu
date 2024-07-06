module axi_master(
        input wire              ACLK,
        input                   ARESETN,
        input       [31:0]      read_address,
        input                   write_start,
        input                   read_start,
        output  reg [31:0]         read_data,
        input    [31:0]         write_data,

        //read addr channel
        output   reg [31:0]         ARADDR,
        //input   [:0]         ARCACHE,
        output    reg              ARVALID,
        output                  ARPROT,
        input                   ARREADY,

        //read data channel
        input   [31:0]         RDATA, //Read Data (32-bit only).
        input   [ 1:0]         RRESP,
        input                  RVALID,
        output                 RREADY,


        //write addr channel
        output reg [31:0]         AWADDR,
        output  [ 3:0]         AWPROT,
        output    reg             AWVALID,
        input                  AWREADY,


        //write data channel
        output reg [31:0]         WDATA,
        output reg [ 3:0]         WSTRB,  //mask
        output  reg                WVALID,
        output   reg               WREADY,

        //Write Response Channel
        input   [ 1:0]         BRESP,
        input                  BVALID,
        output   reg              BREADY
   );
   
        //reg                     r_read_start;
        //reg                     r_write_start;
        //reg                     r_ARREADY;
        reg                     r_ARVALID;
        reg     [31:0]          r_WDATA;
        //reg                     r_RVALID;
        reg                     r_AWADDR;
        reg                     r_AWVALID;
        reg     [ 3:0]          r_WSTRB;
        reg                     r_ARADDR;
        reg                     r_BREADY;
        reg                     r_WVALID;
        reg                     r_WREADY;


        //assign                 ARREADY = r_ARREADY;
        assign                 ARVALID = r_ARVALID;
        assign                 WDATA = r_WDATA;
        assign                 read_data = r_RDATA;
        //assign                 RVALID = r_RVALID;
        assign                 RREADY = r_RREADY;
        assign                  ARADDR=   r_ARADDR;
        assign                  RVALID=   r_RVALID;
        assign                  AWADDR=   r_AWADDR;
        assign                   AWVALID=  r_AWVALID;
        assign                    WSTRB= r_WSTRB;
        assign                    BREADY= r_BREADY;
        assign                     WVALID = r_WVALID;
        assign                     WREADY = r_WREADY;

    
    //gen ARVALID
    always (posedge ACLK) begin
        if(ARESETN) begin
            r_ARVALID <= 1'b0;
            r_ARADDR  <= 32'b0;
            r_RREADY  <= 1'b0;
        end else if(read_start) begin    
            r_ARADDR <= read_address;       
            r_ARVALID <= 1'b1;
            r_RREADY  <= 1'b1;
        end else begin
            r_ARVALID <= r_ARVALID;
            r_ARADDR  <= r_ARADDR;
            r_RREADY  <= r_RREADY;
        end
    end
    //
    


        //logic addr shake hand
    always (posedge ACLK) begin
        if(ARESETN) 
            r_ARVALID <= 1'b0;
        else if(ARREADY & r_ARVALID)
            r_ARVALID <= 1'b0;
        else
            r_ARVALID <= r_ARVALID;
    end

    always (posedge ACLK) begin
        if(ARESETN) 
            r_RREADY <= 1'b0;
        else if(r_RREADY & RVALID)
            r_RREADY <= 1'b0;
            
        else
            r_RREADY <= r_RREADY;   //??
    end  

     always (posedge ACLK) begin
        if(ARESETN ) begin
                r_RREADY <= 1'b0;
                r_RDATA  <= 32'b0;
        end else if(RVALID) begin
                r_RREADY <= 1'b1;
                r_RDATA <=  RDATA;
        end else begin
                r_RREADY <= r_RREADY;
               r_RDATA <=  r_RDATA;
        end
    end
    
     always (posedge ACLK) begin
        if(ARESETN) 
            r_RREADY <= 1'b0;
        else if(r_RREADY & ARVALID)
            r_RREADY <= 1'b0;
        else
            r_RREADY <= r_RREADY;   //??
    end
    //axi_flopr#(1) gen_ARVALID(ACLK,ARESETN,1'b0,,ARVALID);




    //write logic
    always (posedge ACLK) begin
        if(ARESETN) begin
            r_WDATA  <=32'b0;
            r_AWADDR  <= 32'b0;
            r_AWVALID<= 1'b0;
            r_BREADY <= 1'b0;
            r_WVALID <= 1'b0;
        end else if(write_start)   begin
            r_WDATA  <=write_data;
            r_WVALID <= 1'b1;
            r_AWADDR <= read_address;
            r_AWVALID <= 1'b1;
            r_BREADY <= 1'b1;
        end else begin
            r_WDATA  <=r_WDATA  ;
            r_WVALID <= r_WVALID;
            r_AWADDR  <= r_AWADDR;
            r_AWVALID <= r_AWVALID;
            r_BREADY <= r_BREADY;
        end
    end

    always (posedge ACLK) begin
        if(ARESETN) begin
            r_WVALID <= 1'b0;
            r_AWVALID<= 1'b0;
        end else if((r_AWVALID & AWREADY)&(WREADY & r_WVALID)) begin
            r_WVALID <= 1'b0;
            r_AWVALID<= 1'b0;
        end else begin
            r_WVALID <= r_WVALID;
            r_WREADY <= r_WREADY;   
        end
    end
    

    always (posedge ACLK) begin
        if(ARESETN) begin
            r_BREADY <= 1'b0;
                    end
        else if(BVALID & r_BREADY)  begin
            r_BREADY <= 1'b0;
        end
        else begin
            r_BREADY <= r_BREADY;
        end
    end
endmodule

