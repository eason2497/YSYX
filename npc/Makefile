-include $(NPC_HOME)/include/config/auto.conf
-include $(NPC_HOME)/include/config/auto.conf.cmd


TOPNAME = ysyx_24100013_CPU
NXDC_FILES = constr/top.nxdc
INC_PATH ?= $(abspath ./include)

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
                                -O3 --x-assign fast --x-initial fast --noassert --trace


BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@


# project source
MAINS = $(shell find $(abspath ./mains) -name "*.cpp")
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

#CSRCS += $(SRC_AUTO_BIND)

include $(NVBOARD_HOME)/scripts/nvboard.mk

FILELIST_MK = $(shell find -L ./csrc -name "filelist.mk")
include $(FILELIST_MK)

#DIFF_REF_SO = -d $(abspath $(NEMU_HOME)/build/riscv32-nemu-interpreter-so)

# rules for verilator
LIBS ?= 
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image -lreadline $(LIBS)

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) -j 4 $(VERILATOR_CFLAGS) \
             	--top-module $(TOPNAME) $^ \
                $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
				$(addprefix -I, $(INCFLAGS)) \
                --Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN)) \
	# verilator -MMD --build --cc -O3 --x-assgin fast --x-initial fast --noassert --trace \
	#--top-module top top.v bcd7seg.v main.cpp auto_bind.cpp \
	#-CFLAGS -I -DTOP_NAME="\"VTOP\"" -LDFLAGS -lSDL2 -lSDL2_image \
	#--Mdir ./build/obj_dir --exe -o ./build/top
	#--top-module top 指定顶层文件名 --Mdir 将生成的文件都放入obj_dir目录中 --exe -o ./build/top 产生可执行文件并指定


IMG ?=


simulator: $(CSRCS) $(VSRCS)       #--build使得verilator自动build
	rm -rf ./obj_dir
	verilator -exe $(VERILATOR_CFLAGS) -j 4 --trace --top-module \
		ysyx_24100013_CPU $(VSRCS) $(CSRCS) $(addprefix -LDFLAGS , $(LDFLAGS))
	
BINARY = $(BUILD_DIR)/Vysyx_24100013_CPU

NPC_EXEC := $(BIN) $(FLAGS) $(IMG) 

compile: 
	make -C $(NPC_HOME)/obj_dir -j4 -f V$(TOPNAME).mk V$(TOPNAME)

all:
	@echo "Write this Makefile by your self."

run: $(NPC_EXEC) $(BIN) $(IMG)
	$(call git_commit, "sim RTL") 
	$(NPC_EXEC)

sim: simulator $(MAINS) $(VSRCS) $(IMG)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	$(BINARY) $(IMG)

test:
	echo $(CXXFLAGS)
	echo $(FILELIST_MK)
	echo $(LIBS)
	echo $(CONFIG_ITRACE)
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(abspath ./obj_dir)

.PHONY: default all clean run

include ../Makefile

include ./scripts/config.mk