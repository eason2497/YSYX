#include <nvboard.h>
#include <VFSM_bin.h>
#include "verilated.h"

static TOP_NAME dut;

void nvboard_bind_all_pins(VFSM_bin * top);

void single_cycle() {
	//dut.clk = 0; dut.eval();
	//dut.clk = 1; dut.eval();
	dut.eval();
}


int main(int argc, char** argv) {
	nvboard_bind_all_pins(&dut);
	nvboard_init();
	//reset(10);

	while(1) {
		nvboard_update();
		single_cycle();
	}
	return 0;
}
