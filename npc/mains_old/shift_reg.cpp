#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vshift_reg.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vshift_reg* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vshift_reg;
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
  top->din = 0b00001101;
  for (int i = 0;i < 255;i++){
	//top->clk = 0;
  	step_and_dump_wave();
  	//top->clk = 1;
	step_and_dump_wave();
	top->din = top->dout;
  }
  sim_exit();
}


