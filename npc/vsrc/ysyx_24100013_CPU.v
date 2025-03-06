module ysyx_24100013_CPU (
    input clk,
    input rst,
    output reg [31:0] inst,
    output reg [31:0] pc,
    //output [31:0] imm,
    //output [31:0] immI,
    //output [31:0] immS,
    //output [31:0] immB,
    //output [31:0] immU,
    //output [31:0] immJ,
    output reg [31:0] dnpc
    //output [31:0] result
    
);

import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

    //reg [31:0] pc;
    //wire[31:0] inst;
    wire[4:0] rs1;
    wire[4:0] rs2;
    wire[4:0] rd;
    wire[2:0] funct3;
    wire[6:0] funct7;
    wire[6:0] opcode;
    wire overflow;
    wire zero;
    wire carry;
    wire wen;
    wire valid;
    //wire regwen;
    wire [31:0] src1;
    wire [31:0] src2;
    reg [31:0] result;
    //reg [31:0] pmem [31:0];
    //wire [31:0] regval1;
    //wire [31:0] regval2;
    //wire [31:0] wresult;
    wire [31:0] immtype;
    reg [31:0] imm;
    //wire [31:0] immI;
    //wire [31:0] immS;
    //wire [31:0] immB;
    //wire [31:0] immU;
    //wire [31:0] immJ;
    wire [2:0] itype;
    wire [31:0] a0;
    reg [31:0] instruction;

    //reg [31:0] rdata;           //和regfile的区别是可以当前周期使用与更新
    wire [31:0] raddr;
    wire [31:0] len;
    wire [31:0] waddr;
    wire [31:0] writedata;
    wire [7:0] wmask;
    wire jal_valid;
    wire jalr_valid;
    wire branch_valid;
    wire [31:0] branch_result;
    wire [31:0] alu_result;
    wire alu_wen;
    wire branch_wen;

    always @(*) begin
        if (valid) begin
            //rdata = pmem_read(raddr, len);   
            //$display("raddr = %x, rdata = %d",raddr, rdata);
            if (wen) begin 
                //pmem_write(waddr, wdata, wmask);
            end
        end
        else begin
            //rdata = 0;
        end
    end

ysyx_24100013_pc_update pc_update0 (
    .clk(clk),
    .dnpc(dnpc),
    .jal_valid(jal_valid),
    .jalr_valid(jalr_valid),
    .branch_valid(branch_valid),
    .src1(src1),
    .imm(imm),
    .next_pc(pc)
);


ysyx_24100013_IFU ifu0 (
    .clk(clk),
    .rst(rst),
    .dnpc(dnpc),
    .pc(pc),
    .inst(inst)
    //.pmem(pmem)
);
//*/


ysyx_24100013_IDU idu0 (
    .clk(clk),
    .inst(inst),
    .rs1(rs1),
    .rs2(rs2),
    .rd(rd),
    .funct3(funct3),
    .funct7(funct7),
    .opcode(opcode),
    .instruction(instruction),
    .a0(a0),
    //.wen(wen)
    .outputtype(immtype)
);

ysyx_24100013_BPU bpu0 (
    .clk(clk),
    .pc(pc),
    .inst(inst),
    .src1(src1),
    .src2(src2),
    .instruction(instruction),
    .imm(imm),
    .dnpc(dnpc),
    .branch_wen(branch_wen),
    .jal_valid(jal_valid),
    .jalr_valid(jalr_valid),
    .branch_valid(branch_valid),
    .branch_result(branch_result)
);

ysyx_24100013_imm imm0 (
    .clk(clk),
    .inst(inst),
    .intputtype(immtype),
    //.immI(immI),
    //.immB(immB),
    //.immJ(immJ),
    //.immS(immS),
    //.immU(immU),
    .itype(itype),
    .imm(imm)
);
/*
Muxtest test0 (
    .immI(immI),
    .immB(immB),
    .immJ(immJ),
    .immS(immS),
    .immU(immU),
    .itype(itype),
    .imm(imm)
);
//*/
ysyx_24100013_alu alu0 (
    .clk(clk),
    .rst(rst),
    .pc(pc),
    .inst(inst),
    .src1(src1),
    .src2(src2),
    .instruction(instruction),
    //.opcode(opcode),
    .imm(imm),
    .alu_result(alu_result),
    //.itype(itype),
    //.alu_select(funct3),
    .overflow(overflow),
    .zero(zero),
    .carry(carry),
    .dnpc(dnpc),
    .alu_wen(alu_wen),
    .valid(valid),
    //.rdata(rdata),
    .raddr(raddr),
    .wdata(writedata),
    .waddr(waddr),
    .wmask(wmask),
    .len(len)
);

ysyx_24100013_Result_Sel rsel0(
    .clk(clk),
    .alu_result(alu_result),
    .branch_result(branch_result),
    .alu_wen(alu_wen),
    .branch_wen(branch_wen),
    .wen(wen),
    .result(result)
);

/*
ysyx_24100013_datapath datapath0 (
    .src1(src1),
    .src2(src2),
    .result(result),
    .regval1(regval1),
    .regval2(regval2),
    .wresult(wresult)
);
*/

ysyx_24100013_RegisterFile #(5, 32) rf0(
    .clk(clk),
    .rd(rd),
    .rs1(rs1),
    .rs2(rs2),
    .src1(src1),
    .src2(src2),
    .wdata(result),
    .wen(wen)
    //.a0(a0)
);


endmodule
