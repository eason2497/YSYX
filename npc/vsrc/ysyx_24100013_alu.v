module ysyx_24100013_alu (
    input clk,
    input rst,
    input [31:0] inst,
    input [31:0] src1,
    input [31:0] src2,
    input [31:0] imm,
    //input [6:0] opcode,
    input [31:0] instruction,
    //input [31:0] rdata,
    //input [2:0] itype,
    //input [2:0] alu_select,
    input reg [31:0] pc,
    output reg [31:0] alu_result,
    output overflow,
    output zero,
    output carry,
    output reg [31:0] dnpc,
    output [31:0] raddr,
    output [31:0] len,
    output [31:0] waddr,
    output [31:0] wdata,
    output [7:0] wmask,
    output alu_wen,
    output valid
);
import "DPI-C" function void segmentation_fault();
import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

    //reg [16 * 8 - 1: 0] instruction;
    wire[31:0] addi;
    wire[31:0] add;
    wire[31:0] sub;
    wire[31:0] div;
    wire[31:0] divu;
    wire[31:0] mul;
    wire[31:0] mulh;
    wire[31:0] rem;
    wire[31:0] remu;
    wire[31:0] slli;
    wire[31:0] srli;
    wire[31:0] srai;
    wire[31:0] sll;
    wire[31:0] srl;
    wire[31:0] sra;
    wire[31:0] xor_;
    wire[31:0] or_;
    wire[31:0] and_;
    wire[31:0] xori;
    wire[31:0] ori;
    wire[31:0] andi;
    wire[31:0] lui;
    wire[31:0] auipc;
    wire[31:0] jal;
    wire[31:0] jalr;
    wire[31:0] jal_record;
    wire[31:0] jalr_record;
    //assign instruction = "Hello";
    assign jal = pc + 4;  //本该是pc+4， 但是下面dnpc会再加导致出错，所以这里就不加了
    assign jalr = pc + 4;
    assign lui = imm;
    assign auipc = imm + pc;
    assign addi = src1 + imm;
    assign add = src1 + src2;
    assign sub = src1 - src2;
    assign div = src1 / src2;
    //assign divu = signed src1 / signed src2;
    assign mul = src1 * src2;
    //assign mulh = ;
    //assign rem = signed src1 % signed src2;
    //assign remu = src1 % src2;
    assign slli = src1 << imm;
    assign srli = src1 >> imm;
    assign srai = $signed(src1) >>> imm[5:0];
    assign sll = src1 << src2;
    assign srl = src1 >> src2;
    assign sra = $signed(src1) >>> src2;
    assign xor_ = src1 ^ src2;
    assign or_ = src2 | src2;
    assign and_ = src1 & src2;
    assign xori = src1 ^ imm;
    assign ori = src1 ^ imm;
    assign andi = src1 & imm;
    assign jal_record = pc + imm;
    assign jalr_record = src1 + imm & {~32'b1};
    assign {carry, addi} = src1 + imm; //这里碰到一个错误是由于没有正确解析负数导致的错误
    
    //assign overflow = (src1[31] == imm[31]) && (result[31] != src1[31]);
    //assign zero = ~(|result);

    //assign result = addi;
    //assign alu_wen = 1;
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
                                                //wen现在需要设置好，不然会把错误的值存入registerfile
    always @(*) begin
        if (rst == 1) begin
            alu_result = 0;
            //pc = 32'h80000000 - 4;
            //dnpc = 32'h80000000 - 4;
        end
        else begin
                alu_wen = 0;
                valid = 0;
                case(instruction)
                    32'd2: begin
                        alu_result = auipc;
                        alu_wen = 1;
                    end
                    32'd3: begin
                        alu_result = lui;
                        alu_wen = 1;
                    end
                    32'd4: begin
                        alu_result = addi;
                        alu_wen = 1;
                    end
                    32'd5: begin
                        alu_result = add;
                        alu_wen = 1;
                    end
                    32'd11: begin
                        alu_result = slli;
                        alu_wen = 1;
                    end
                    32'd12: begin
                        alu_result = srli;
                        alu_wen = 1;
                    end
                    32'd13: begin
                        alu_result = srai;
                        alu_wen = 1;
                    end
                    32'd14: begin
                        alu_result = sll;
                        alu_wen = 1;
                    end
                    32'd15: begin
                        alu_result = srl;
                        alu_wen = 1;
                    end
                    32'd16: begin
                        alu_result = sra;
                        alu_wen = 1;
                    end
                    32'd17: begin
                        valid = 1;
                        raddr = src1 + imm;
                        len = 1;
                        if (raddr < 32'h80000000 || raddr > 32'h88000000) begin segmentation_fault(); end
                        alu_result = pmem_read(raddr, len);
                        alu_wen = 1;
                    end
                    32'd18: begin
                        valid = 1;
                        raddr = src1 + imm;
                        len = 2;
                        if (raddr < 32'h80000000 || raddr > 32'h88000000) begin segmentation_fault(); end
                        alu_result = pmem_read(raddr, len);
                        alu_wen = 1;
                    end
                    32'd19: begin
                        valid = 1;
                        raddr = src1 + imm;
                        len = 2;
                        if (raddr < 32'h80000000 || raddr > 32'h88000000) begin segmentation_fault(); end
                        alu_result = pmem_read(raddr, len);
                        alu_wen = 1;
                    end
                    32'd20: begin            //lw
                        valid = 1;
                        raddr = src1 + imm;
                        len = 4;
                        if (raddr < 32'h80000000 || raddr > 32'h88000000) begin segmentation_fault(); end
                        //$display("raddr = %x, rdata = %x", raddr, result);
                        alu_result = pmem_read(raddr, len);
                        alu_wen = 1;
                        //$display("raddr = %x, rdata = %x", raddr, result);
                    end
                    32'd21: begin
                        valid = 1;
                        waddr = src1 + imm;
                        wdata = src2;
                        wmask = 8'h1;
                        pmem_write(waddr, wdata, wmask);
                    end
                    32'd22: begin
                        valid = 1;
                        waddr = src1 + imm;
                        wdata = src2;
                        wmask = 8'h3;
                        pmem_write(waddr, wdata, wmask);
                    end
                    32'd23: begin
                        valid = 1;
                        waddr = src1 + imm;
                        wdata = src2;
                        wmask = 8'hf;
                        pmem_write(waddr, wdata, wmask);
                        //$display("src1 = %x, waddr = %x, wdata = %x", src1, waddr, wdata);
                    end
                    ///*
                    32'd30: begin
                        //$display("src1 = %x", src1);
                        if (src1 < imm) begin
                            alu_result = 32'b1;
                            //$display("alu_result = %x", alu_result);
                        end else begin
                            alu_result = 32'b0;
                        end
                        alu_wen = 1;
                    end
                    /*
                    32'd31: begin
                        if (src1 < src2) begin
                            alu_result = 1;
                        end else begin
                            alu_result = 0;
                        end
                    end
                    32'd32: begin
                        if ($signed(src1) < $signed(src2)) begin
                            alu_result = 1;
                        end else begin
                            alu_result = 0;
                        end
                    end
                    /*
                    32'd33: begin
                        alu_result = xor_;
                    end
                    32'd34: begin
                        alu_result = or_;
                    end
                    32'd35: begin
                        alu_result = and_;
                    end
                    32'd36: begin
                        alu_result = xori;
                    end
                    32'd37: begin
                        alu_result = ori;
                    end
                    32'd38: begin
                        alu_result = andi;
                    end
                    */
                    default: begin
                        alu_result = 32'b0;
                    end
                endcase
                //pc = dnpc;
            //end
        end
    end
 //*/   

endmodule



