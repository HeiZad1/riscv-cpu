# 默认目标
default: run

# 顶层模块名称
TOP ?= ysyxSoCFull

# Verilog源文件目录
VERILOG_DIR = ./vsrc
VERILOG_DIR_soc = $(HOME)/ysyx/ics2023/ysyxSoC/perip
SCR_SoC_DIR = $(HOME)/ysyx/ics2023/ysyxSoC/perip/vga
CPP_DIR = ./csrc
INCLUDE_DIR = ./include
INCLUDE_DIR_soc1 = $(HOME)/ysyx/ics2023/ysyxSoC/perip/uart16550/rtl
INCLUDE_DIR_soc2 = $(HOME)/ysyx/ics2023/ysyxSoC/perip/spi/rtl
NEMU_DIR = ~/ysyx/ics2023/nemu/build
NEMU_INCLUDE_DIR = ~/ysyx/ics2023/nemu/include
CFLAGS = -fPIC
LDFLAGS = -lreadline -L$(NEMU_DIR) -Wl,-rpath=$(NEMU_DIR) -Wl,-rpath-link=$(NEMU_DIR) $(NEMU_DIR)/riscv32-nemu-interpreter-so  
# Verilog源文件
VERILOG_SRCS = $(wildcard $(VERILOG_DIR)/*.v) 
VERILOG_SRCS += $(shell find $(VERILOG_DIR_soc)/ -name "*.v")
#CPP_SRCS = ./csrc/soc_sim.cpp
CPP_SRCS = $(wildcard $(CPP_DIR)/*.cpp)

# 生成的对象文件目录
OBJ_DIR = obj_dir

# VCD file
VCD_FILE = $(TOP).vcd

# 包含路径
INCLUDE_DIRS = -I$(VERILOG_DIR) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR_soc1) -I$(INCLUDE_DIR_soc2) 

# 生成对象文件目录
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 编译生成的Makefile文件
$(OBJ_DIR)/V$(TOP).mk: $(VERILOG_SRCS) $(CPP_SRCS) | $(OBJ_DIR)
	verilator --timescale "1ns/1ns" --timing  -Wall $(INCLUDE_DIRS) $(DEFINES) $(VERILOG_SRCS) --cc --exe $(CPP_SRCS) -Wno-PINCONNECTEMPTY -Wno-UNUSED -Wno-DECLFILENAME --CFLAGS "$(CFLAGS)" --LDFLAGS "  $(LDFLAGS)" --trace --top-module $(TOP) 

# 编译目标
compile: $(OBJ_DIR)/V$(TOP).mk
	make -C $(OBJ_DIR) -f V$(TOP).mk

# 运行仿真
run: compile
	./$(OBJ_DIR)/V$(TOP) /home/swf/ysyx/ics2023/am-kernels/tests/cpu-tests/build/dummy-riscv32e-soc.bin

view: $(VCD_FILE)
	gtkwave $(VCD_FILE)

# 清理生成文件
clean:
	rm -rf $(OBJ_DIR)

# 伪目标
.PHONY: default compile clean run

