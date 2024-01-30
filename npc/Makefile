TOPNAME = light
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

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
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
             	--top-module $(TOPNAME) $^ \
                $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
                --Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))
	# verilator -MMD --build --cc -O3 --x-assgin fast --x-initial fast --noassert --trace \
	#--top-module top top.v bcd7seg.v sim_main.cpp auto_bind.cpp \
	#-CFLAGS -I -DTOP_NAME="\"VTOP\"" -LDFLAGS -lSDL2 -lSDL2_image \
	#--Mdir ./build/obj_dir --exe -o ./build/top
	#--top-module top 指定顶层文件名 --Mdir 将生成的文件都放入obj_dir目录中 --exe -o ./build/top 产生可执行文件并指定



all:
	@echo "Write this Makefile by your self."

run: $(BIN)
	@$^

sim:	*.cpp *.v
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator --cc --exe --build -j 0 -Wall ./csrc/*.cpp ./vsrc/top.v
	make -C obj_dir -f Vtop.mk Vtop ./nvboard.a $(addprefix -LDFLAGS, $(LDFLAGS))

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run

include ../Makefile
