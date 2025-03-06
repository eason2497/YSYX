module ysyx_24100013_Result_Sel (
    input clk,
    input [31:0] alu_result,
    input [31:0] branch_result,
    input alu_wen,
    input branch_wen,
    output reg wen,
    output reg [31:0] result
);
    always@(*) begin
        wen = 0;
        if (alu_wen == 1) begin
            result = alu_result;
            wen = 1;
        end else if (branch_wen == 1) begin
            result = branch_result;
            wen = 1;
        end else begin
            result = 32'b0;
        end
    end
endmodule

