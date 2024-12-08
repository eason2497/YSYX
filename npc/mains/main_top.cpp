#include <nvboard.h>
#include <Vtop.h>
#include "verilated.h"

static TOP_NAME dut;

void nvboard_bind_all_pins(Vtop* top);

void single_cycle() {
	dut.clk = 0; dut.eval();
	dut.clk = 1; dut.eval();
	//dut.eval();
}

static void reset(int n) {
  dut.rst = 1;
  while (n -- > 0) single_cycle();
  dut.rst = 0;
}

int main(int argc, char** argv) {
	nvboard_bind_all_pins(&dut);
	nvboard_init();
	reset(10);

	while(1) {
		nvboard_update();
		single_cycle();
	}
	return 0;
}
