module ysyx_24100013_alu (
    input clk,
    input rst,
    input [31:0] inst,
    input [31:0] src1,
    input [31:0] src2,
    input [31:0] imm,
    input [6:0] opcode,
    //input [2:0] itype,
    //input [2:0] alu_select,
    output reg [31:0] pc,
    output reg [31:0] result,
    output overflow,
    output zero,
    output carry,
    output reg [31:0] dnpc,
    output wen
);
import "DPI-C" function void segmentation_fault();

    wire[31:0] addi;
    wire[31:0] lui;
    wire[31:0] auipc;
    wire[31:0] jal;
    wire[31:0] jalr;
    wire[31:0] jal_record;
    wire[31:0] jalr_record;
    assign jal = pc + 4;  //本该是pc+4， 但是下面dnpc会再加导致出错，所以这里就不加了
    assign jalr = pc + 4;
    assign lui = imm;
    assign auipc = imm + pc;
    assign jal_record = pc + imm;
    assign jalr_record = src1 + imm & {~32'b1};
    assign {carry, addi} = src1 + imm; //这里碰到一个错误是由于没有正确解析负数导致的错误
    
    //assign overflow = (src1[31] == imm[31]) && (result[31] != src1[31]);
    //assign zero = ~(|result);

    //assign result = addi;
    assign wen = 1;
    /*
    MuxKey #(5, 7, 32) i1 (result, opcode, {
        7'b0010011, addi,
        7'b0110111, lui,
        7'b0010111, auipc,
        7'b1101111, jal,
        7'b1100111, jalr
    });
    ///*
    MuxKey #(5, 7, 32) i2 (dnpc, opcode, {
        7'b0010011, pc,
        7'b0110111, pc,
        7'b0010111, pc,
        7'b1101111, jal_record,
        7'b1100111, jalr_record
    });
//*/
///*                                                                           把mv inst实现一下试试
    always @(posedge clk) begin
        if (rst == 1) begin
            result = 0;
            pc = 32'h80000000 - 4;
            dnpc = 32'h80000000 - 4;
        end
        else begin
        //$display(".............alu............");
            case(opcode)
                7'b1101111: begin
                    if (jal_record < 32'h80000000 || jal_record > 32'h88000000) begin segmentation_fault(); end
                    dnpc = jal_record;
                    result = jal;
                    //$display("src1: %x", src1);
                    //$display("Jump dnpc: %x jal_record: %x", dnpc, jal_record);
                    end
                7'b1100111: begin
                    if (jalr_record < 32'h80000000 || jalr_record > 32'h88000000) begin segmentation_fault(); end
                    dnpc = jalr_record;
                    result = jalr;
                    //$display("src1: %x", src1);
                    //$display("Jump dnpc: %x jalr_record: %x", dnpc, jalr_record);
                    end
                7'b0010011: begin
                    result = addi;
                    dnpc = pc + 4;
                    end
                7'b0110111: begin
                    result = lui;
                    dnpc = pc + 4;
                    end
                7'b0010111: begin
                    result = auipc;
                    dnpc = pc + 4;
                    end
                default: begin
                    dnpc = pc + 4;
                    result = 32'b0;
                    end
            endcase
            pc = dnpc;
        end
    end
 //*/   

endmodule



