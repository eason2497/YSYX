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
    //wire[31:0] pc;
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

/*
    always@(posedge clk or rst) begin
        if (rst == 1) begin 
            pc <= 0;
            dnpc <= 0;
            inst <= 0;
        end
    end
*/
///*
ysyx_24100013_IFU ifu0 (
    .clk(clk),
    .rst(rst),
    //.dnpc(dnpc),
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
    //.wen(wen)
    .outputtype(immtype)
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
    .opcode(opcode),
    .imm(imm),
    .result(result),
    //.itype(itype),
    //.alu_select(funct3),
    .overflow(overflow),
    .zero(zero),
    .carry(carry),
    .dnpc(dnpc),
    .wen(wen)
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
);


endmodule
