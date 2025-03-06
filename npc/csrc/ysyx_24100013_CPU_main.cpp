#include <ysyx_24100013_common.h>
#include <ysyx_24100013_difftest.h>
#include <Vysyx_24100013_CPU.h>
#include "verilated_vcd_c.h"
#include "verilated.h"
#include "svdpi.h"
#include "Vysyx_24100013_CPU__Dpi.h"
#include <getopt.h>
#include "ysyx_24100013_sdb.h"
#include "ysyx_24100013_memory.h"
//#include "Vysyx_24100013_IDU__Dpi.h"

//#define MEMBASE 0x80000000
//#define MEMSIZE 0x8000000
//static uint32_t* pmem = NULL;

#define R 0b000
#define I 0b001
#define S 0b010
#define B 0b011
#define U 0b100
#define J 0b101


extern "C" void init_disasm(const char *triple);
void display_iringbuf();
void trace_inst(uint32_t pc,  uint32_t inst);

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static Vysyx_24100013_CPU * dut;
bool Ebreak = false;
//char image_file[] = "dummy-riscv32e-npc.bin";
char *image_file = NULL;
char *diff_so_file = NULL;
int difftest_port = 1234;
char *elf = NULL;

//static uint8_t pmem[MEMSIZE] PG_ALIGN = {};
//static uint32_t* pmem;

NPCState npc_state = { .state = NPC_STOP };


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
	"??????? ????? ????? 000 ????? 00100 11",
	"0000000 ????? ????? 000 ????? 01100 11",
	"0100000 ????? ????? 000 ????? 01100 11",
	"0000001 ????? ????? 100 ????? 01100 11",
	//"0000001 ????? ????? 101 ????? 01100 11",
	"0000001 ????? ????? 000 ????? 01100 11",
	"0000001 ????? ????? 001 ????? 01100 11",
	"0000001 ????? ????? 110 ????? 01100 11",
	//"0000001 ????? ????? 111 ????? 01100 11"
	"000000? ????? ????? 001 ????? 00100 11",
	"000000? ????? ????? 101 ????? 00100 11",
	"010000? ????? ????? 101 ????? 00100 11",
	"0000000 ????? ????? 001 ????? 01100 11",
	"0000000 ????? ????? 101 ????? 01100 11",
	"0100000 ????? ????? 101 ????? 01100 11",
	"??????? ????? ????? 100 ????? 00000 11",
	"??????? ????? ????? 101 ????? 00000 11",
	"??????? ????? ????? 001 ????? 00000 11",
	"??????? ????? ????? 010 ????? 00000 11",
	"??????? ????? ????? 000 ????? 01000 11",
	"??????? ????? ????? 001 ????? 01000 11",
	"??????? ????? ????? 010 ????? 01000 11",
	"??????? ????? ????? 000 ????? 11000 11",
	"??????? ????? ????? 001 ????? 11000 11",
	"??????? ????? ????? 101 ????? 11000 11",
	"??????? ????? ????? 100 ????? 11000 11",
	"??????? ????? ????? 110 ????? 11000 11",
	"??????? ????? ????? 111 ????? 11000 11",
	"??????? ????? ????? 011 ????? 00100 11",
	"0000000 ????? ????? 011 ????? 01100 11",
	"0000000 ????? ????? 010 ????? 01100 11",
	"0000000 ????? ????? 100 ????? 01100 11",
	"0000000 ????? ????? 110 ????? 01100 11",
	"0000000 ????? ????? 111 ????? 01100 11",
	"??????? ????? ????? 100 ????? 00100 11",
	"??????? ????? ????? 110 ????? 00100 11",
	"??????? ????? ????? 111 ????? 00100 11",



};

const char *inst_name[] = {
	"jal",
	"jalr",
	"auipc",
	"lui",
	"addi",
	"add",
	"sub",
	"div",
	//"divu",
	"mul",
	"mulh",
	"rem",
	//"remu",
	"slli",
	"srli",
	"srai",
	"sll",
	"srl",
	"sra",
	"lbu",
	"lhu",
	"lh",
	"lw",
	"sb",
	"sh",
	"sw",
	"beq",
	"bne",
	"bge",
	"blt",
	"bltu",
	"bgeu",
	"sltiu",
	"sltu",
	"slt",
	"xor",
	"or",
	"and",
	"xori",
	"ori",
	"andi",

};

const uint32_t inst_type[] = {
	J,
	I,
	U,
	U,
	I,
	R,
	R,
	R,
	//R,
	R,
	R,
	R,
	//R，
	I,
	I,
	I,
	R,
	R,
	R,
	I,
	I,
	I,
	I,
	S,
	S,
	S,
	B,
	B,
	B,
	B,
	B,
	B,
	I,
	R,
	R,
	R,
	R,
	R,
	I,
	I,
	I,

};

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void init_disasm(const char *triple);


int add(int a, int b) {
	return a + b;
}

///*  
extern int register_scan(int);
void isa_reg_display() {
	svSetScope(svGetScopeFromName("TOP.ysyx_24100013_CPU.rf0"));
	int i = 0;
	for (i = 0; i < 32; i++) {
		printf("%3s = %x\n", regs[i], register_scan(i));
  		//register_scan(i);
	}
}
//*/

uint32_t isa_reg_str2val(const char *s, bool *success) {
	svSetScope(svGetScopeFromName("TOP.ysyx_24100013_CPU.rf0"));
	for (int i = 0; i < 32; i++) {
		if (strcmp(regs[i], s) == 0) {
			return register_scan(i);
		}
	}
	return 0;
}

int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {"elf"      , required_argument, NULL, 'e'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1) {  //添加-b实现batchmode
    Log("run\n");                                                               //e后面的冒号很重要，代表了输入的值
    switch (o) {
      case 'b': break;//sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      //case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 'e': elf = NULL;
        #ifdef CONFIG_FTRACE
          if (CONFIG_FTRACE) {elf = optarg;}
        #endif
        break;
      case 1: image_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-e,--elf_file=FILE            parse ELF file\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}



void npc_trap(int halt_ret) {           //nemu使用的NEMUTRAP并通过指定register的数值给halt_ret赋值
	printf("ebreak: ");
	printf("trap at 0x%x\n", dut->pc);
	Ebreak = true;
	npc_state.state = NPC_END;
	npc_state.halt_pc = dut->pc;
	npc_state.halt_ret = halt_ret;
	//register_scan();
	//printf("npc_halt_pc: %x, npc_halt_ret: %d\n", npc_state.halt_pc, npc_state.halt_ret);
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

int instruction_type_check() {
	int i = 0;
	int aSize = sizeof(inst_set) / sizeof(inst_set[0]);
	while (i < aSize) {
		uint64_t key, mask, shift; 
		pattern_decode(inst_set[i], (strlen(inst_set[i])), &key, &mask, &shift);
		if ((((uint64_t)dut->inst >> shift) & mask) == key) {
			//printf("%s instruction matched  %d type\n", inst_name[i], inst_type[i]);
			return inst_type[i];
			break;
		}
		i++;
	}
	return 999;
}

int instruction_check() {
	int i = 0;
	int aSize = sizeof(inst_set) / sizeof(inst_set[0]);
	while (i < aSize) {
		uint64_t key, mask, shift; 
		pattern_decode(inst_set[i], (strlen(inst_set[i])), &key, &mask, &shift);
		if ((((uint64_t)dut->inst >> shift) & mask) == key) {
			//printf("%s instruction matched  %d type\n", inst_name[i], inst_type[i]);
			//printf("instruction type %s\n", inst_name[i]);
			return i;
			break;
		}
		i++;
	}
	return 999;
}

uint32_t* init_mem(size_t size) {
	
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
/*
void parse_args(int argc, char *argv[]) {
	image = argv[1];
	printf("Loaded image address is %s\n", image);
	//assert(0);
}
*/
size_t load_img() {
	if (image_file == NULL) {
		printf("No image is given. Default image loaded.\n");
		return 4096;
	}
	//FILE *fp = fopen("/home/eason/ysyx-workbench/npc/dummy-riscv32e-npc.bin", "rb");
	FILE *fp = fopen(image_file, "rb");
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
	dut->clk = 1; dut->eval(); step_and_dump_wave();
}

void execute(uint64_t n) {
	for (; n > 0; n--) {
		single_cycle();
		#ifdef CONFIG_ITRACE
			if (CONFIG_ITRACE) {trace_inst(dut->pc, dut->inst);}
		#endif
		if (!Ebreak) {
			printf("current inst: 0x%08x    current pc: 0x%08x\n", dut->inst, dut->pc);
		}
		if (npc_state.state != NPC_RUNNING) break;
	}
}

void cpu_exec(uint64_t n) {
	switch (npc_state.state) {
		case NPC_END: case NPC_ABORT:
		printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
		//return;
		break;
		default: npc_state.state = NPC_RUNNING;
  	}

	execute(n);

	switch (npc_state.state) {
			case NPC_RUNNING: npc_state.state = NPC_STOP; break;

			case NPC_END: case NPC_ABORT:
				printf("npc: %s at pc = %x\n",
					(npc_state.state == NPC_ABORT ? "ABORT":
					(npc_state.halt_ret == 0 ? "HIT GOOD TRAP" : "HIT BAD TRAP")), npc_state.halt_pc);
			case NPC_QUIT: ;//printf("NPC_QUIT\n");
	}
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
	tfp->open("./build/dump.vcd");
}

void segmentation_fault(){
	printf("Segmentation fault\n");
	step_and_dump_wave();
	tfp->close();
	display_iringbuf();
	npc_state.state = NPC_ABORT;
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
	init_sdb();
	#ifdef CONFIG_ITRACE
		if (CONFIG_ITRACE) {
			printf("init_disasm\n");
			init_disasm("riscv32");
		}
	#endif
	//init_difftest(diff_so_file, size, difftest_port);
	reset(1);
	sdb_mainloop();
	display_iringbuf();
	//isa_reg_display();
	tfp->close();
	//free(pmem);
	return 0;
}
