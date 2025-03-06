module ysyx_24100013_pc_update(
    input clk,
    input [31:0] dnpc,
    input jal_valid,
    input jalr_valid,
    input branch_valid,
    input [31:0] src1,
    input [31:0] imm,
    output reg [31:0] next_pc
);

    always@(posedge clk) begin
        if (jalr_valid) begin
            next_pc = src1 + imm & {~32'b1};
        end else if (jal_valid | branch_valid) begin
            next_pc = dnpc + imm;
        end else begin
            next_pc = dnpc + 4;
        end
    end

endmodule