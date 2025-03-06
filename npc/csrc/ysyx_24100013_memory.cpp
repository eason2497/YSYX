#include <Vysyx_24100013_CPU.h>
#include "verilated_vcd_c.h"
#include "svdpi.h"
#include <ysyx_24100013_sdb.h>
#include <ysyx_24100013_memory.h>


void mtrace_read(uint32_t addr, int len);
void mtrace_write(uint32_t addr, int len, uint32_t data);


uint8_t pmem[MEMSIZE] PG_ALIGN = {};

uint8_t* guest_to_host(uint32_t addr) { return pmem + addr - MEMBASE; }
uint32_t host_to_guest(uint8_t *haddr) { return haddr - pmem + MEMBASE; }

uint32_t host_read(void *addr, int len) {  //根据byte转换addr指针类型
  	switch (len) {
    	case 1: return *(uint8_t  *)addr;
		case 2: return *(uint16_t *)addr;
		case 4: return *(uint32_t *)addr;
		case 8: return *(uint64_t *)addr;
		default: return 0;
  	}
}

void host_write(void *addr, int len, uint32_t data) {
	switch (len) {
		case 1: *(uint8_t  *)addr = data; return;
		case 2: *(uint16_t *)addr = data; return;
		case 4: *(uint32_t *)addr = data; return;
		case 8: *(uint64_t *)addr = data; return;
		default: assert(0);
	}
}

//extern "C" uint32_t pmem_read(uint32_t addr, int len) {
extern "C" uint32_t pmem_read(uint32_t addr, int len) {
	//uint32_t ret = *(uint32_t*) guest_to_host(addr);
	#ifdef CONFIG_MTRACE
    	if (CONFIG_MTRACE) {mtrace_read(addr, len);}
  	#endif
  	uint32_t ret = host_read(guest_to_host(addr), len);
  	return ret;
}

extern "C" void pmem_write(uint32_t waddr, uint32_t wdata, char wmask) {
	// 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  	// `wmask`中每比特表示`wdata`中1个字节的掩码,
  	// 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
	#ifdef CONFIG_MTRACE
    	if (CONFIG_MTRACE) {mtrace_write(waddr, 4, wdata);}
  	#endif
	switch (wmask) {
		case 0x1:
			host_write(guest_to_host(waddr), 1, wdata);
			break;
		case 0x3:
			host_write(guest_to_host(waddr), 2, wdata);
			break;
		case 0xf:
			host_write(guest_to_host(waddr), 4, wdata);
			break;
		default: Log("Invalid write");
	}

}