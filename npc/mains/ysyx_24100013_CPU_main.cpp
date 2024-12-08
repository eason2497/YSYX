#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <Vysyx_24100013_CPU.h>
#include "verilated_vcd_c.h"
#include "verilated.h"
#include "svdpi.h"
#include "Vysyx_24100013_CPU__Dpi.h"
#include <getopt.h>
//#include "Vysyx_24100013_IDU__Dpi.h"

#define MEMBASE 0x80000000
#define MEMSIZE 0x8000000
#define PG_ALIGN __attribute((aligned(4096)))
//static uint32_t* pmem = NULL;

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vysyx_24100013_CPU * dut;
bool Ebreak = false;
char image_file[] = "dummy-riscv32e-npc.bin";
char *image = NULL;

static uint8_t pmem[MEMSIZE] PG_ALIGN = {};
//static uint32_t* pmem;

static const uint32_t img[] = {
	0b00000000011000000000001100010011,   
	0b00000000011100000000000100010011,
	0b00000000111000000000000010010011,
	0b00000000000100000000000001110011,   //ebreak
	0b00000000011100000000000110010011
};

const char inst_set_test[2][39] = {
	"??????? ????? ????? ??? ????? 11011 11",
	"??????? ????? ????? 000 ????? 11001 11"
};

const char *inst_set[] = {
	"??????? ????? ????? ??? ????? 11011 11",
	"??????? ????? ????? 000 ????? 11001 11",
	"??????? ????? ????? ??? ????? 00101 11",
	"??????? ????? ????? ??? ????? 01101 11",
	"??????? ????? ????? 000 ????? 00100 11"
};

const char *inst_name[] = {
	"jal",
	"jalr",
	"auipc",
	"lui",
	"addi"
};

const uint32_t inst_type[] = {
	0b101,
	0b001,
	0b100,
	0b100,
	0b001
};

int add(int a, int b) {
	return a + b;
}

void npc_trap() {
	printf("ebreak: ");
	printf("trap at 0x%x\n", dut->pc);
	Ebreak = true;
}

static inline void pattern_decode(const char *str, int len, uint64_t *key, uint64_t *mask, uint64_t *shift) {
	uint64_t __key = 0, __mask = 0, __shift = 0;
	for (int i = 0; i < len; i++) {
		char c = str[i]; 
		if (c != ' ') { 
			assert(c == '0' || c == '1' || c == '?'); 
			__key  = (__key  << 1) | (c == '1' ? 1 : 0); 
			__mask = (__mask << 1) | (c == '?' ? 0 : 1); 
			__shift = (c == '?' ? __shift + 1 : 0); 
		} 
	}
	*key = __key >> __shift;
	*mask = __mask >> __shift;
	*shift = __shift;
	/*
	if ((i) >= len) goto finish; 
	else { 
		char c = str[i]; 
		if (c != ' ') { 
			assert(c == '0' || c == '1' || c == '?'); 
			__key  = (__key  << 1) | (c == '1' ? 1 : 0); 
			__mask = (__mask << 1) | (c == '?' ? 0 : 1); 
			__shift = (c == '?' ? __shift + 1 : 0); 
		} 
	}
	finish:
		*key = __key >> __shift;
		*mask = __mask >> __shift;
		*shift = __shift;
	*/
}
/*
bool pattern_match(uint32_t inst, uint32_t target) {
	char input[32];
	sprintf(input, "%x");
	char *input = (char *)inst;
	char *comparision = (char *)target;
	for (int i = 0;i < 32;i++) {
		if (comparision[i] == '?') {
			continue;
		} else if (input[i] != comparision[i]) {
			return false;
		}
	}
	return true;
}
*/
int instruction_type_check() {
	//char target[] = "??????? ????? ????? ??? ????? 11011 11";
	int i = 0;
	int aSize = sizeof(inst_set) / sizeof(inst_set[0]);
	//printf("aSize = %d\n", aSize);
	while (i < aSize) {
		uint64_t key, mask, shift; 
		pattern_decode(inst_set[i], (strlen(inst_set[i])), &key, &mask, &shift);
		//printf("%ld", strlen(inst_set_test[i]));
		//printf("key = %ld  mask = %ld  shift = %ld\n", key, mask, shift);
		if ((((uint64_t)dut->inst >> shift) & mask) == key) {
			//printf("%s instruction matched  %d type\n", inst_name[i], inst_type[i]);
			return inst_type[i];
			break;
		}
		i++;
	}
	//assert(0);
	return 0;
}


uint32_t guest_to_host(uint32_t addr) { return addr - MEMBASE; }
uint8_t* guest_to_host_test(uint32_t addr) { return pmem + addr - MEMBASE; }
uint32_t host_to_guest(uint8_t *haddr) { return haddr - pmem + MEMBASE; }


uint32_t pmem_read(uint32_t vaddr, uint32_t* pmem) {
  	uint32_t paddr = guest_to_host(vaddr);
	if (paddr / 4 >= 14) { // Check against img size
        fprintf(stderr, "Invalid memory read at address: 0x%X\n", vaddr);
        exit(EXIT_FAILURE);
    }
  	return pmem[paddr/4];
}

uint32_t host_read(void *addr, int len) {  //根据byte转换addr指针类型
  	switch (len) {
    	case 1: return *(uint8_t  *)addr;
		case 2: return *(uint16_t *)addr;
		case 4: return *(uint32_t *)addr;
		case 8: return *(uint64_t *)addr;
		default: return 0;
  	}
}

extern "C" uint32_t pmem_read(uint32_t addr, int len) {
  uint32_t ret = host_read(guest_to_host_test(addr), len);
  return ret;
}

uint32_t* init_mem(size_t size) {
	//dut->pc = MEMBASE;
	//assert(0);
	//memset(pmem, rand(), MEMBASE);
	
	uint32_t* mem = (uint32_t*)malloc(size * sizeof(uint32_t));
	if (mem == NULL) {
		assert(0 && "Memory allocation failed");
	}
	memcpy(mem, img, sizeof(img));
	//memcpy(guest_to_host(MEMBASE), img, sizeof(img));
	printf("init\n");
	return mem;
}

void init_mem() {
	memcpy(pmem, img, sizeof(img));
	printf("init\n");
}

void parse_args(int argc, char *argv[]) {
	image = argv[1];
	printf("Loaded image address is %s\n", image);
	//assert(0);
}

size_t load_img() {
	if (image == NULL) {
		printf("No image is given. Default image loaded.\n");
		return 4096;
	}
	//FILE *fp = fopen("/home/eason/ysyx-workbench/npc/dummy-riscv32e-npc.bin", "rb");
	FILE *fp = fopen(image, "rb");
	printf("Reading image file......\n");
	assert(fp);
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
  	printf("The image is %s, size = %ld\n", image_file, size);
  	fseek(fp, 0, SEEK_SET);
  	int ret = fread(pmem, size, 1, fp);
  	assert(ret == 1);
  	fclose(fp);
  	return size;
}

void step_and_dump_wave(){
  //dut->eval();
  	tfp->dump(contextp->time());
  	contextp->timeInc(1);
}

void single_cycle() {
	dut->clk = 0; dut->eval(); step_and_dump_wave();
	//dut->inst = pmem_read(dut->pc, 4);
	//dut->pc = dut->dnpc + 4;
	//if (dut->rst == 0 && dut->pc == 0) {
	//	dut->pc = MEMBASE;
	//	dut->dnpc = MEMBASE;
	//}
	dut->clk = 1; dut->eval(); step_and_dump_wave();
}

static void reset(int n) {
	dut->rst = 1;
	while (n -- > 0) single_cycle();
	dut->rst = 0;
}

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	dut = new Vysyx_24100013_CPU;
	contextp->traceEverOn(true);
	dut->trace(tfp, 5);
	tfp->open("dump.vcd");
}

void segmentation_fault(){
	printf("Segmentation fault\n");
	step_and_dump_wave();
	tfp->close();
	assert(0);
}

int main(int argc, char *argv[]) {
	//scanf("dummy-riscv32e-npc.bin", program_path);
	//uint32_t* mem = init_mem(6);
	init_mem();
	parse_args(argc, argv);
	long size = load_img();
	//load_img();
	printf("mem size: %ld mem init\n", size);
	sim_init();
	printf("sim init\n");
	reset(1);
	//dut->pc = MEMBASE;
	//dut->dnpc = MEMBASE;
	//reset(10);
	/*
	while(!Ebreak) {
		dut->inst = pmem_read(dut->pc, 4);
		printf("current inst: 0x%x    current pc: 0x%x\n", dut->inst, dut->pc);
		single_cycle();
		step_and_dump_wave();
		dut->pc = dut->pc + 4;
	}
	*/
	int i = 0;

	while (!Ebreak) {
		//dut->inst = pmem_read(dut->pc, 4);
		//instruction_type_check(dut->inst);
		single_cycle();
		//printf("current inst: 0x%08x    current pc: 0x%08x\n", dut->inst, dut->pc - 4);
		//printf("current inst: 0x%08x\n", dut->inst);
		//printf("pc: %x   dnpc: %x  imm: %x\n", dut->pc, dut->dnpc, dut->imm);
		//dut->pc = dut->dnpc + 4;
		//printf("pc: %x   dnpc: %x\n", dut->pc, dut->dnpc);
		//i++;
	}
	tfp->close();
	//free(pmem);
	return 0;
}
