#include <common.h>
#include <elf.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_INST_TO_RECORD 16
# define ELF_RELOC_ERR -1

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

typedef struct {
  word_t pc;
  uint32_t inst;
} record;

typedef struct {
	Elf32_Shdr strtab;
	Elf32_Shdr symtab;
} ftrace;

typedef struct {
	char name[32];
	unsigned char info;
	paddr_t value;
	uint32_t size;
} functionname;

typedef struct call_record {
	paddr_t pc;
	struct call_record *next;
	int depth;
} callRecord;

record iringbuf[MAX_INST_TO_RECORD];
word_t addr_record[128];
Elf32_Shdr section_table;
functionname symbol_list[32];
callRecord *call_record_head = NULL;
int calldepth = 0;
int FUNC_Num = 0;

int current = 0;
int current_addr = 0;

void trace_inst(word_t pc,  uint32_t inst) {
    iringbuf[current].pc = pc;
    iringbuf[current].inst = inst;
    current = (current + 1) % MAX_INST_TO_RECORD;
}

void display_iringbuf() {
    int i;
    int cur = current;
    char buf[128];
    char *ptr;
    for (i = 0; i < cur;i++) {
      ptr = buf;
      ptr += sprintf(buf, "%s " FMT_WORD ": %08x     ", (i+1) % MAX_INST_TO_RECORD == cur ? "    -->" : "       ", iringbuf[i].pc, iringbuf[i].inst);
      disassemble(ptr, buf + sizeof(buf) - ptr, iringbuf[i].pc, (uint8_t *)&iringbuf[i].inst, 4);
      printf("%s\n", buf);
    }
}

void mtrace_read(paddr_t addr, int len) {
  printf("Paddr read  at " FMT_PADDR " len = %d\n", addr, len);
}

void mtrace_write(paddr_t addr, int len, word_t data) {
  printf("Paddr write at " FMT_PADDR " len = %d  " "data =" FMT_WORD "\n", addr, len, data);
}

bool elf_check_file(Elf32_Ehdr *hdr) {
	if(!hdr) return false;
	if(hdr->e_ident[EI_MAG0] != ELFMAG0) {
		printf("ELF Header EI_MAG0 incorrect.\n");
		return false;
	}
	if(hdr->e_ident[EI_MAG1] != ELFMAG1) {
		printf("ELF Header EI_MAG1 incorrect.\n");
		return false;
	}
	if(hdr->e_ident[EI_MAG2] != ELFMAG2) {
		printf("ELF Header EI_MAG2 incorrect.\n");
		return false;
	}
	if(hdr->e_ident[EI_MAG3] != ELFMAG3) {
		printf("ELF Header EI_MAG3 incorrect.\n");
		return false;
	}
	return true;
}

bool elf_check_supported(Elf32_Ehdr *hdr) {
	if(!elf_check_file(hdr)) {
		printf("Invalid ELF File.\n");
		return false;
	}
	if(hdr->e_ident[EI_CLASS] != ELFCLASS32) {
		printf("Unsupported ELF File Class.\n");
		return false;
	}
	if(hdr->e_ident[EI_DATA] != ELFDATA2LSB) {
		printf("Unsupported ELF File byte order.\n");
		return false;
	}
	if(hdr->e_type != ET_REL && hdr->e_type != ET_EXEC) {
		printf("Unsupported ELF File type.\n");
		return false;
	}
	return true;
}

static ftrace getTables(Elf32_Ehdr *hdr, int fd) {
	int i;
	//size_t j;
	Elf32_Shdr s;
	char * sectNames = NULL;
	ftrace table;
	bool strtable_lock = false;
	printf("Num of sections: %d\n", hdr->e_shnum);
	//fseek(ElfFile, hdr->e_shoff + hdr->e_shstrndx * hdr->e_shentsize, SEEK_SET);
    //j = fread(&s, 1, sizeof(s), ElfFile);
	lseek(fd, (off_t)hdr->e_shoff + hdr->e_shstrndx * hdr->e_shentsize, SEEK_SET);
	assert(read(fd, &s, sizeof(s)) == sizeof(s));
    sectNames = malloc(s.sh_size);
    //fseek(ElfFile, s.sh_offset, SEEK_SET);
    //j = fread(sectNames, 1, s.sh_size, ElfFile);
	lseek(fd, (off_t)s.sh_offset, SEEK_SET);
	assert(read(fd, sectNames, s.sh_size) == s.sh_size);
	printf("0 %s\n", sectNames);
	for (i = 0;i < hdr->e_shnum;i++) {
		char * name = "";
		//fseek(ElfFile, hdr->e_shoff + i * sizeof(s), SEEK_SET);
		//j = fread(&s, 1, sizeof(s), ElfFile);
		lseek(fd, (off_t)hdr->e_shoff + i * sizeof(s), SEEK_SET);
		assert(read(fd, &s, sizeof(s)) == sizeof(s));
		if (s.sh_name) {
			name = sectNames + s.sh_name;
			printf("%i %-30s     %x     %x\n", i, name, s.sh_offset, s.sh_size);
		}
		if (s.sh_type == SHT_STRTAB && !strtable_lock) {
			table.strtab = s;
			strtable_lock = true;
		} else if (s.sh_type == SHT_SYMTAB) {
			table.symtab = s;
		}
	}
	return table;
}

static void printSym(Elf32_Ehdr *hdr, Elf32_Shdr symtab, Elf32_Shdr strtab, int fd) {
	//size_t j;
	Elf32_Sym symbol;
	char stringtable[strtab.sh_size];
	char *name;
	off_t current_Offset = symtab.sh_offset;
	int symtab_entries = symtab.sh_size / symtab.sh_entsize;
	printf("%d entries\n", symtab_entries);
	//stringtable = malloc(strtab.sh_size);
	//fseek(ElfFile, (off_t)strtab.sh_offset, SEEK_SET);
	//j = fread(stringtable, 46, sizeof(strtab.sh_size), ElfFile);  //不清楚为什么改成46之后不会乱码
	lseek(fd, (off_t)strtab.sh_offset, SEEK_SET);
	assert(read(fd, stringtable, strtab.sh_size) == strtab.sh_size);
	printf("FUNC from the symbol table\n");
	for (int i = 0;i < symtab_entries;i++) {
		//fseek(ElfFile, current_Offset, SEEK_SET);
		//j = fread(&symbol, 1, sizeof(symbol), ElfFile);
		lseek(fd, current_Offset, SEEK_SET);
		assert(read(fd, &symbol, sizeof(symbol)) == sizeof(symbol));
		name = stringtable + symbol.st_name;
		//printf("value: %08x   name: %d %s\n", symbol.st_value, symbol.st_name, name);
		if (ELF32_ST_TYPE(symbol.st_info) == STT_FUNC) {
			printf("TYPE: FUNC  ");
			printf("value: %08x   name: %-8d %s\n", symbol.st_value, symbol.st_name, name);
			symbol_list[FUNC_Num].info = symbol.st_info;
			symbol_list[FUNC_Num].value = symbol.st_value;
			memset(symbol_list[FUNC_Num].name, 0, 32);
		 	strcpy(symbol_list[FUNC_Num].name, name);
			symbol_list[FUNC_Num].size = symbol.st_size;
			FUNC_Num++;
		}
		current_Offset += symtab.sh_entsize;
	}
}

void readELF() {
	int fd;
	//size_t j;
	//FILE * ElfFile = NULL;
	Elf32_Ehdr hdr;
	ftrace table;
	//Elf32_Shdr *strtab;
	//Elf32_Shdr *symtab;
	//ElfFile = fopen("/home/eason/ysyx-workbench/am-kernels/tests/cpu-tests/build/add-riscv32-nemu.elf", "r");
	fd = open("/home/eason/ysyx-workbench/am-kernels/tests/cpu-tests/build/add-riscv32-nemu.elf", O_RDONLY);
	if (fd < 0) {
		printf("Elf File open error\n");
		assert(0);
	}
	//j = fread(&hdr, 1, sizeof(hdr), ElfFile);
	assert(read(fd, &hdr, sizeof(Elf32_Ehdr)));
	if (elf_check_file(&hdr) && elf_check_supported(&hdr)) {
		table = getTables(&hdr, fd);
	}
	//printf("%x, %x\n", table.strtab.sh_size, table.strtab.sh_entsize);
	//printf("%x, %x\n", table.symtab.sh_size, table.symtab.sh_entsize);
	printSym(&hdr, table.symtab, table.strtab, fd);
	//fclose(ElfFile);
	close(fd);
}

void init_call_record(){
	call_record_head = (callRecord *)malloc(sizeof(callRecord));
	call_record_head->pc = 0;
	call_record_head->next = NULL;
}

void insert_call_record(paddr_t pc, int depth){
	callRecord *node = (callRecord *)malloc(sizeof(callRecord));
	node->pc = pc;
	node->depth = depth;
	node->next = call_record_head;   			//拔头
	call_record_head = node;
}

void remove_call_record(){
	callRecord *node = call_record_head;        //拔头
	call_record_head = call_record_head->next;
	free(node);
}

void parseELF(char *elf_path) {
	int fd;
	Elf32_Ehdr hdr;
	ftrace table;
	//printf("%s\n", elf_path);
	Log("%s", elf_path);
	fd = open(elf_path, O_RDONLY);
	if (fd < 0) {
		printf("Elf File open error\n");
		assert(0);
	}
	assert(read(fd, &hdr, sizeof(Elf32_Ehdr)));
	if (elf_check_file(&hdr) && elf_check_supported(&hdr)) {
		table = getTables(&hdr, fd);
	}
	printSym(&hdr, table.symtab, table.strtab, fd);
	for (int i = 0;i < FUNC_Num;i++){
		printf("%s\n", symbol_list[i].name);
	}
	init_call_record();
	close(fd);
}

int searchSymbol(paddr_t pc, bool check_return){
	for (int i = 0;i < FUNC_Num;i++) {
		if (check_return) {
			if (symbol_list[i].value <= pc && pc < symbol_list[i].value + symbol_list[i].size) {  //查看pc是否落在FUNC之间
				return i;
			}
		} else {
			if (symbol_list[i].value == pc) {
				return i;
			}
		}
	}
	return -1;
}

void function_call(paddr_t pc, paddr_t dnpc){
	int searchidx = searchSymbol(dnpc, false);
	printf("%x         call [%s@0x%x]\n", pc, searchidx >= 0 ? symbol_list[searchidx].name : "???", symbol_list[searchidx].value);
	/*
	for(int i = 0;i < FUNC_Num;i++) {
		//printf("%x    %x\n", symbol_list[i].value, dnpc);
		if (symbol_list[i].value == dnpc) {
			printf("%x         call [%s@0x%x]\n", pc, symbol_list[i].name, symbol_list[i].value);
			break;
		}
	}
	*/
	insert_call_record(pc, calldepth);
	calldepth++;
}

void function_return(paddr_t pc){
	int searchidx = searchSymbol(pc, true);
	printf("%x         ret [%s]\n", pc, searchidx >= 0 ? symbol_list[searchidx].name : "???"); 
	/*
	for(int i = 0;i < FUNC_Num;i++) {
		if (symbol_list[i].value <= pc && pc < symbol_list[i].value + symbol_list[i].size) {  //查看pc是否落在FUNC之间
			printf("%x         ret [%s]\n", pc, symbol_list[i].name); 
		}
	}
	
	callRecord *node = call_record_head->next;
	if (node != NULL) {
		if (node->depth == calldepth - 1){
			//paddr_t ret_addr = node->pc;
			remove_call_record();
			//function_return(ret_addr);
		}
	}
	*/
	remove_call_record();
	calldepth--;
}