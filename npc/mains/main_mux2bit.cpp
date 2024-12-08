#include <nvboard.h>
#include <Vmux_2bit.h>
#include "verilated.h"

static TOP_NAME dut;

void nvboard_bind_all_pins(Vmux_2bit* top);

void single_cycle() {
	dut.eval();
}

int main(int argc, char** argv) {
	nvboard_bind_all_pins(&dut);
	nvboard_init();

	while(1) {
		nvboard_update();
		single_cycle();
	}
	return 0;
}
