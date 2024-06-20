# 默认目标
default: run

# 顶层模块名称
TOP ?= rv32i

# Verilog源文件目录
VERILOG_DIR = ./vsrc
CPP_DIR = ./csrc
INCLUDE_DIR = ./include

# Verilog源文件
VERILOG_SRCS = $(wildcard $(VERILOG_DIR)/*.v)
CPP_SRCS = $(wildcard $(CPP_DIR)/*.cpp)

# 生成的对象文件目录
OBJ_DIR = obj_dir

# 包含路径
INCLUDE_DIRS = -I$(VERILOG_DIR) -I$(INCLUDE_DIR)

# 宏定义
DEFINES = -DVL_TIME_PRECISION="-12" -D'XLEN=32'

# 生成对象文件目录
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 编译生成的Makefile文件
$(OBJ_DIR)/V$(TOP).mk: $(VERILOG_SRCS) $(CPP_SRCS) | $(OBJ_DIR)
	verilator -Wall $(INCLUDE_DIRS) $(DEFINES) $(VERILOG_SRCS) --cc --exe $(CPP_SRCS) --CFLAGS "-fPIC" --trace --top-module $(TOP)

# 编译目标
compile: $(OBJ_DIR)/V$(TOP).mk
	make -C $(OBJ_DIR) -f V$(TOP).mk

# 运行仿真
run: compile
	$(OBJ_DIR)/V$(TOP)

# 清理生成文件
clean:
	rm -rf $(OBJ_DIR)

# 伪目标
.PHONY: default compile clean run
