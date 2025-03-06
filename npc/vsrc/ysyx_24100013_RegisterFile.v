module ysyx_24100013_RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
    input clk,
    input [DATA_WIDTH-1:0] wdata,
    input [ADDR_WIDTH-1:0] rd,
    input [ADDR_WIDTH-1:0] rs1,
    input [ADDR_WIDTH-1:0] rs2,
    input wen,
    output [DATA_WIDTH-1:0] src1,
    output [DATA_WIDTH-1:0] src2
    //output [31:0] a0
);

import "DPI-C" function int unsigned pmem_read(input int unsigned addr, input int len);
import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

export "DPI-C" function register_scan;

    reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
    integer i;
    
    function int register_scan(int i);
        //$display("%x", rf[i]);
        return rf[i];
    endfunction
    ///*
    initial begin
      for (i = 0; i < 2**ADDR_WIDTH; i = i + 1) begin
        rf[i] = 0;
      end
    end
    //*/

    assign src1 = (rs1 != 5'b0) ? rf[rs1] : 32'b0;
    assign src2 = (rs2 != 5'b0) ? rf[rs2] : 32'b0;
    //assign a0 = rf[10];
       
    always @(posedge clk) begin
      if (wen) begin
        rf[rd] <= wdata;
        //$display("wdata = 0x%x  rd = %d\n", wdata, rd);
        //$display("ra = 0x%x\n", rf[1]);
        //$display("sp = 0x%x\n", rf[2]);
      end
      //for (i = 0; i < 2**ADDR_WIDTH; i = i + 1) begin
        //$display("rf[%d]: %x", i, rf[i]);
      //end
    end 

endmodule
