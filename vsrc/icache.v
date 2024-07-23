module iCache #(parameter BLOCK_SIZE = 4,   // 块大小为4B
                parameter CACHE_BLOCKS = 16 // 共16个cache块
               ) (
                input wire clk,
                input wire reset,
                input wire [31:0] address,
                output reg [31:0] data_out,
                output reg hit
               );

    // 计算索引和标签
    localparam INDEX_BITS = $clog2(CACHE_BLOCKS);
    localparam OFFSET_BITS = $clog2(BLOCK_SIZE);
    localparam TAG_BITS = 32 - INDEX_BITS - OFFSET_BITS;

    // 定义缓存块结构
    typedef struct packed {
        logic valid;
        logic [TAG_BITS-1:0] tag;
        logic [31:0] data [BLOCK_SIZE/4-1:0];
    } cache_block_t;

    // 缓存阵列
    cache_block_t cache [CACHE_BLOCKS-1:0];

    // 变量
    logic [INDEX_BITS-1:0] index;
    logic [TAG_BITS-1:0] tag;
    logic [OFFSET_BITS-1:0] offset;

    // 初始化缓存
    initial begin
        for (int i = 0; i < CACHE_BLOCKS; i++) begin
            cache[i].valid = 0;
            cache[i].tag = 0;
        end
    end

    // 地址解析
    always_comb begin
        index = address[OFFSET_BITS+INDEX_BITS-1:OFFSET_BITS];
        tag = address[31:32-TAG_BITS];
        offset = address[OFFSET_BITS-1:0];
    end

    // 读取缓存
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < CACHE_BLOCKS; i++) begin
                cache[i].valid <= 0;
                cache[i].tag <= 0;
            end
        end else begin
            if (cache[index].valid && cache[index].tag == tag) begin
                hit <= 1;
                data_out <= cache[index].data[offset/4];
            end else begin
                hit <= 0;
                data_out <= 32'hX; // 未命中
            end
        end
    end
endmodule
