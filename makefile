# 默认目标
default: run

# 顶层模块名称
TOP ?= rv32i

# Verilog源文件目录
VERILOG_DIR = ./vsrc
CPP_DIR = ./csrc
INCLUDE_DIR = ./include
NEMU_DIR = ~/ysyx/ics2023/nemu/build
NEMU_INCLUDE_DIR = ~/ysyx/ics2023/nemu/include
CFLAGS = -fPIC 
LDFLAGS = -lreadline -L$(NEMU_DIR) -Wl,-rpath=$(NEMU_DIR) -Wl,-rpath-link=$(NEMU_DIR) $(NEMU_DIR)/riscv32-nemu-interpreter-so  
# Verilog源文件
VERILOG_SRCS = $(wildcard $(VERILOG_DIR)/*.v) $(wildcard $(VERILOG_DIR)/axilite/*.v)
CPP_SRCS = $(wildcard $(CPP_DIR)/*.cpp)

# 生成的对象文件目录
OBJ_DIR = obj_dir

# VCD file
VCD_FILE = $(TOP).vcd

# 包含路径
INCLUDE_DIRS = -I$(VERILOG_DIR) -I$(INCLUDE_DIR)

# 生成对象文件目录
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 编译生成的Makefile文件
$(OBJ_DIR)/V$(TOP).mk: $(VERILOG_SRCS) $(CPP_SRCS) | $(OBJ_DIR)
	verilator -Wall $(INCLUDE_DIRS) $(DEFINES) $(VERILOG_SRCS) --cc --exe $(CPP_SRCS) --CFLAGS "$(CFLAGS)" --LDFLAGS "  $(LDFLAGS)" --trace --top-module $(TOP)

# 编译目标
compile: $(OBJ_DIR)/V$(TOP).mk
	make -C $(OBJ_DIR) -f V$(TOP).mk

# 运行仿真
run: compile
	./$(OBJ_DIR)/V$(TOP) /home/swf/ysyx/ics2023/am-kernels/tests/cpu-tests/build/add-riscv32e-npc.bin

view: $(VCD_FILE)
	gtkwave $(VCD_FILE)

# 清理生成文件
clean:
	rm -rf $(OBJ_DIR)

# 伪目标
.PHONY: default compile clean run

