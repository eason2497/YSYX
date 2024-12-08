#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VFSM_bin.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VFSM_bin* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new VFSM_bin;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("dump.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}
int main() {
  top->clk = 0;
  int count = 0;
  sim_init();
  while (!contextp->gotFinish()){
	count++;
	contextp->timeInc(1);
	top->clk = !(top->clk);
	top->in = 1;
	top->eval();
	tfp->dump(contextp->time());
	if (count > 50){
	  break;
	}

  }

  sim_exit();
}


