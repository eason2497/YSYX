module ysyx_24100013_RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
    input clk,
    input [DATA_WIDTH-1:0] wdata,
    input [ADDR_WIDTH-1:0] rd,
    input [ADDR_WIDTH-1:0] rs1,
    input [ADDR_WIDTH-1:0] rs2,
    input wen,
    output [DATA_WIDTH-1:0] src1,
    output [DATA_WIDTH-1:0] src2
);

    reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
    integer i;
    ///*
    initial begin
      for (i = 0; i < 2**ADDR_WIDTH; i = i + 1) begin
        rf[i] = 0;
      end
    end
    //*/

    assign src1 = (rs1 != 5'b0) ? rf[rs1] : 32'b0;
    assign src2 = (rs2 != 5'b0) ? rf[rs2] : 32'b0;
       
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
