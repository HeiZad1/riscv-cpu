# Verilator Example Makefile
#===========================

# If you have Verilator installed globally, you can omit VERILATOR_ROOT
VERILATOR_ROOT ?= $(shell verilator --getenv VERILATOR_ROOT)

# Verilog and C++ source files
VSRCS = axi_master.v axi_slaver.v axiTop.v
CXX_SRCS = testAxi.cpp

# Top-level module
TOP_MODULE = axiTop

# Object directory
OBJ_DIR = obj_dir

# Verilator options
VERILATOR_FLAGS = -Wall --cc --trace --top-module $(TOP_MODULE)

# Default target
all: $(TOP_MODULE)

# Create object directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile Verilog and C++ sources with Verilator
$(OBJ_DIR)/V$(TOP_MODULE).mk: $(VSRCS) $(CXX_SRCS) | $(OBJ_DIR)
	$(VERILATOR_ROOT)/bin/verilator $(VERILATOR_FLAGS) $(VSRCS) --exe $(CXX_SRCS)

# Build the simulation executable
$(TOP_MODULE): $(OBJ_DIR)/V$(TOP_MODULE).mk
	make -j -C $(OBJ_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)

# Run the simulation
run: $(TOP_MODULE)
	./$(OBJ_DIR)/V$(TOP_MODULE)

# Clean up generated files
clean:
	rm -rf $(OBJ_DIR) waveform.vcd

.PHONY: all run clean
