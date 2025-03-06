module ysyx_24100013_BPU (
    input clk,
    input [31:0] inst,
    input [31:0] src1,
    input [31:0] src2,
    input [31:0] imm,
    input [31:0] instruction,
    input reg [31:0] pc,
    output reg [31:0] dnpc,
    output branch_wen,
    output jal_valid,
    output jalr_valid,
    output branch_valid,
    output reg [31:0] branch_result
);

import "DPI-C" function void segmentation_fault();
import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    
    wire [31:0] jal_record;
    wire [31:0] jalr_record;

    assign jal_record = pc + imm;
    assign jalr_record = src1 + imm & {~32'b1};

    always@(*) begin
        jal_valid = 0;
        jalr_valid = 0;
        branch_valid = 0;
        branch_wen = 0;
        case(instruction)
            32'd0: begin
                //$display("jal_record = %x", jal_record);
                if (jal_record < 32'h80000000 || jal_record > 32'h88000000) begin segmentation_fault(); end
                branch_result = pc + 4;
                jal_valid = 1;
                branch_wen = 1;
                //$display("src1: %x", src1);
                //$display("Jump dnpc: %x jal_record: %x", dnpc, jal_record);
            end
            32'd1: begin
                //$display("jalr_record = %x, src1 = %x, imm = %x", jalr_record, src1, imm);
                if (jalr_record < 32'h80000000 || jalr_record > 32'h88000000) begin segmentation_fault(); end
                branch_result = pc + 4;
                jalr_valid = 1;
                branch_wen = 1;
                //$display("src1: %x", src1);
                //$display("Jump dnpc: %x jalr_record: %x", dnpc, jalr_record);
            end
            32'd24: begin
                if (src1 == src2) begin
                    branch_valid = 1;
                end
            end
            32'd25: begin
                if (src1 != src2) begin
                    //$display("src1 = 5x, src2 = %x", src1, src2);
                    //$display("new_pc = %x, old_pc = %x, imm = %x", pc + imm, pc, imm);
                    branch_valid = 1;
                end
            end
            32'd26: begin
                if ($signed(src1) >= $signed(src2)) begin
                    branch_valid = 1;
                end
            end
            32'd27: begin
                if ($signed(src1) < $signed(src2)) begin
                    branch_valid = 1;
                end
            end
            32'd28: begin
                if (src1 < src2) begin 
                    branch_valid = 1;
                end
            end
            32'd29: begin
                if (src1 >= src2) begin
                    branch_valid = 1; 
                end
            end
            default: begin
                branch_result = 32'b0;
            end
        endcase
    end

endmodule
