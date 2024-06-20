module riscv_testbench;

  reg        clk;
  reg        reset;

  reg [31:0] WriteData, DataAdr;
  reg        MemWrite;

  // 实例化待测试的设备
  rv32i dut(clk, reset, WriteData, DataAdr, MemWrite);
  
  // 初始化测试
  initial begin
    reset = 1; #22; reset = 0;
  end

  // 产生时钟以执行测试
  always begin
    clk <= 1; #5; clk <= 0; #5;
  end

  // 检查结果
  always @(negedge clk) begin
    if (MemWrite) begin
      if (DataAdr === 100 && WriteData === 25) begin
        $display("Simulation succeeded");
        $stop;
      end else if (DataAdr !== 96) begin
        $display("Simulation failed");
        $stop;
      end
    end
  end
endmodule
