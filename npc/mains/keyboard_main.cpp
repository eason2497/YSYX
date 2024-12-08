#include <nvboard.h>
#include <Vkeyboard.h>
#include "verilated.h"

static TOP_NAME dut;

void nvboard_bind_all_pins(Vkeyboard * top);

void single_cycle() {
	dut.clk = 1; dut.eval();
	dut.clk = 0; dut.eval();
	//dut.eval();
}

static void reset(int n) {
  dut.clrn = 0;
  while (n -- > 0) single_cycle();
  dut.clrn = 1;
}

int main(int argc, char** argv) {
	nvboard_bind_all_pins(&dut);
	nvboard_init();
	reset(1);

	while(1) {
		nvboard_update();
		single_cycle();
	}
	return 0;
}
