module axi_slaver(
        input                   ACLK,
        input                   ARESETN,

        output  reg   [31:0]         addr,
        input   [31:0]         read_data,
        output   [31:0]         write_data,

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
        input  [31:0]           AWADDR,
        input  [ 3:0]           AWPROT,
        input                   AWVALID,
        output                  AWREADY,


        //write data channel
        input  [31:0]         WDATA,
        //input  [ 3:0]         WSTRB,  //mask
        input                  WVALID,
        input                  WREADY,

        //Write Response Channel
        //output   [ 1:0]         BRESP,
        output   reg               BVALID,
        input                  BREADY
   );

        reg                     r_ARREADY;
        reg                     r_ARVALID;
        reg     [31:0]          r_WDATA;
        reg     [31:0]          r_RDATA;
        reg                     r_RVALID;
        reg                     r_AWREADY;
        //reg                     r_WVALID;
        reg                     r_WREADY;
        reg     [31:0]          r_AWADDR;
        reg                     r_BVALID;

        //assign                 addr = ARADDR;
        assign                 ARREADY = r_ARREADY;
        //assign                 ARVALID = r_ARVALID;
        //assign                 WDATA = r_WDATA;
        assign                 RDATA = r_RDATA;
        assign                 RVALID = r_RVALID;
        assign                 AWREADY = r_AWREADY;
        //assign                 WVALID =  r_WVALID;
        //assign                 WREADY = r_WREADY;
        //assign                 AWADDR =  r_AWADDR;
        assign                 BVALID =   r_BVALID;
        assign                  RRESP = 2'b00;

        //gen ARREADY
        
    always@(posedge ACLK) begin
        if(ARESETN) 
                r_ARREADY <= 1'b0;
        else if(ARVALID)
                r_ARREADY <= 1'b1;
        else 
                r_ARREADY <= r_ARREADY;

    end

    

        //logic shake hand
    always@(posedge ACLK) begin
        if(ARESETN) begin
            r_ARREADY <= 1'b0;
        end
        else if(ARVALID & r_ARREADY)  begin//addr jiaru
            r_ARREADY <= 1'b0;
            addr <= ARADDR;
        end
        else begin
            r_ARREADY <= r_ARREADY;
        end
    end   

    always@(posedge ACLK) begin
        if(ARESETN) begin
            r_RVALID <= 1'b0;
            r_RDATA <= 32'b0;
        end else if(ARVALID & r_ARREADY) begin//??
            r_RVALID <= 1'b1;
            r_RDATA <= read_data;
        end else begin
            r_RVALID <= r_RVALID;
            r_RDATA <= r_RDATA;
        end   //??
    end    

    always@(posedge ACLK) begin
        if(ARESETN) 
            r_RVALID <= 1'b0;
        else if(RREADY & r_RVALID)
            r_RVALID <= 1'b1;
        else
            r_RVALID <= r_RVALID;   //??
    end

    //axi_flopr #(1) gen_ARVALID



        //write logic
    always@(posedge ACLK) begin
        if(ARESETN) begin
                r_AWREADY <= 1'b0;
        end else if(ARVALID) begin
                r_AWREADY <= 1'b1;
        end else begin
                r_AWREADY <= r_AWREADY;
        end
    end

    always@(posedge ACLK) begin
        if(ARESETN) begin
                r_WREADY <= 1'b0;
        end else if(WVALID) begin
                r_WREADY <= 1'b1;
        end else begin
                r_WREADY <= r_WREADY;
        end
    end


    always@(posedge ACLK) begin
        if(ARESETN) begin
            r_ARREADY <= 1'b0;
            r_WDATA <= 32'b0;
            r_BVALID <= 1'b0;
            r_AWADDR <= 32'b0;

        end
        else if((AWVALID & r_AWREADY)&(WREADY & WVALID))  begin
            r_AWREADY <= 1'b0;
            r_WREADY <= 1'b0;
            write_data <= r_WDATA;
            r_BVALID <= 1'b1;
            addr<= r_AWADDR; 
        end
        else begin
            r_AWREADY <= r_AWREADY;
            r_WDATA <= r_WDATA;
            r_BVALID <= r_BVALID;
            r_WREADY <= r_WREADY;
            r_AWADDR <= r_AWADDR;
        end
    end 

    always@(posedge ACLK) begin
        if(ARESETN) begin
            r_BVALID <= 1'b0;
            
        end
        else if(r_BVALID & BREADY)  begin
            r_BVALID <= 1'b0;
            //BRESP <= 2'b00;
        end
        else begin
            r_BVALID <= r_BVALID;
            //BRESP <= 2'b10;
        end
    end 

    
endmodule

