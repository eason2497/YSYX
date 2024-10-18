#include <nvboard.h>
#include <Vbarrel_register.h>
#include "verilated.h"

static TOP_NAME dut;

void nvboard_bind_all_pins(Vbarrel_register * top);

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
