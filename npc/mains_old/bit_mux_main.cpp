#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vbit_mux.h"
VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vbit_mux* top;

void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new Vbit_mux;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("dump.vcd");
}

void sim_exit(){
	step_and_dump_wave();
	tfp->close();
}

int main() {
	sim_init();

	top->y=0; top->x0=0; top->x1=0; top->x2=2; top->x3=3; step_and_dump_wave();
	top->y=1; top->x0=1; top->x1=3; top->x2=1; top->x3=2; step_and_dump_wave();
        top->y=2; top->x0=2; top->x1=3; top->x2=3; top->x3=0; step_and_dump_wave();
        top->y=3; top->x0=3; top->x1=2; top->x2=2; top->x3=1; step_and_dump_wave();
        top->y=0; top->x0=0; top->x1=1; top->x2=0; top->x3=2; step_and_dump_wave();
        top->y=1; top->x0=1; top->x1=3; top->x2=1; top->x3=0; step_and_dump_wave();
        top->y=2; top->x0=2; top->x1=2; top->x2=0; top->x3=3; step_and_dump_wave();
        top->y=3; top->x0=3; top->x1=0; top->x2=2; top->x3=1; step_and_dump_wave();
        top->y=0; top->x0=0; top->x1=0; top->x2=3; top->x3=2; step_and_dump_wave();


	sim_exit();
}
