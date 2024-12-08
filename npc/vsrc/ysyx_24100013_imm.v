module ysyx_24100013_imm (
    input clk,
    input [31:0] inst,
    input [31:0] intputtype,
    output reg [31:0] imm,
    //output [31:0] immI,
    //output [31:0] immS,
    //output [31:0] immB,
    //output [31:0] immU,
    //output [31:0] immJ,
    output [2:0] itype
);
    //wire [31:0] record;
    ///*
    wire [31:0] immI;
    wire [31:0] immS;
    wire [31:0] immB;
    wire [31:0] immU;
    wire [31:0] immJ;
    //*/
    //wire [2:0] itype;
    //wire [31:0] test;
    //assign record = inst[31:0];
    assign itype = {intputtype[2:0]};
    assign immI = {{20{inst[31]}}, inst[31:20]};
    assign immS = {{20{1'b0}}, inst[31:25], inst[11:7]};
    assign immB = {{19{1'b0}}, inst[31], inst[7:7], inst[30:25], inst[11:8], {1'b0}};
    assign immU = {inst[31:12], {12{1'b0}}};
    assign immJ = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], {1'b0}};  //补充高12位时应与inst[31]一致


    //assign imm = immI;
    //00000000110100000000 00001 1101111
    /*
    MuxKeyWithDefault #(5, 3, 32) imm_mux (imm, intputtype[2:0], 32'b0, {  //好像是记录第一次值之后，inst不会被更新？
        3'b001, immI,
        3'b010, immS,
        3'b011, immB,
        3'b100, immU,
        3'b101, immJ
    });
    //*/
    
    //*
    always @(inst) begin
        case (itype)
            3'b001: imm = immI;
            3'b010: imm = immS;
            3'b011: imm = immB;
            3'b100: imm = immU;
            3'b101: imm = immJ;
            default: imm = 32'b0;
        endcase
        //$display("imm: %x", imm);
    end
    //*/
endmodule
