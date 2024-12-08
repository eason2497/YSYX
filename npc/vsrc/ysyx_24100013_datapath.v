module ysyx_24100013_datapath (
    input [31:0] src1,
    input [31:0] src2,
    input [31:0] result,
    output [31:0] regval1,
    output [31:0] regval2,
    output [31:0] wresult
);
    assign regval1 = src1;
    assign regval2 = src2;
    assign wresult = result;

endmodule
