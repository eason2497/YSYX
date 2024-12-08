module ysyx_24100013_IFU (
    input clk,
    input rst,
    input [31:0] pc,
    //input [31:0] dnpc,
    output reg [31:0] inst
    //output reg [31:0] pmem [31:0]
);
//import "DPI-C" function chandle init_mem(int size);
//import "DPI-C" function [31:0] guest_to_host( [31:0] addr);

import "DPI-C" function int unsigned pmem_read( int unsigned addr, int len);

    always @(posedge clk) begin
        if (rst == 1) begin
            inst <= 32'b0;
            //pc = 32'h80000000;
        end
        else begin
            //$display("pc = 0x%x", pc);
            inst <= pmem_read(pc, 4);
            //pc = dnpc;
            //$display("pc = 0x%x", pc);
        end
    end
    //assign pc = pc + 4;

endmodule
