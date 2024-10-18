#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Valu.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Valu* top;

void step_and_dump_wave(){
        top->eval();
        contextp->timeInc(1);
        tfp->dump(contextp->time());
}

void sim_init(){
        contextp = new VerilatedContext;
        tfp = new VerilatedVcdC;
        top = new Valu;
        contextp->traceEverOn(true);
        top->trace(tfp, 0);
        tfp->open("dump.vcd");
}

void sim_exit(){
        step_and_dump_wave();
        tfp->close();
}

int main(){
	sim_init();
        
        top->sel = 0b000; top->in_a = 0b0001; top->in_b = 0b0010; step_and_dump_wave();
	top->sel = 0b001; top->in_a = 0b0001; top->in_b = 0b0010; step_and_dump_wave();
        sim_exit();
}
