#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include <nvboard.h>

static TOP_NAME dut;

void nvboard_bind_all_pins(Vtop* top);

int main(int argc, char** argv)
{

	nvboard_bind_all_pins(&dut);
	nvboard_init();
        Verilated::commandArgs(argc, argv);
        Vtop *top = new Vtop("top");
	while(!Verilated::gotFinish())
        {
        int a = rand() & 1;
        int b = rand() & 1;
        top->a = a;
        top->b = b;
        top->eval();
        printf("a = %d, b = %d, f = %d\n", a, b, top->f);
	nvboard_update();
        assert(top->f == (a ^ b));
        }
	nvboard_quit();
        delete top;
        return 0;
}

