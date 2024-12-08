module ysyx_24100013_IDU (
    input clk,
    input [31:0] inst,
    output reg [4:0] rs1,
    output reg [4:0] rs2,
    output reg [4:0] rd,
    output reg [6:0] opcode,
    output reg [2:0] funct3,
    output reg [6:0] funct7,
    //output wen
    output reg [31:0] outputtype
);
    import "DPI-C" function void npc_trap();
    //import "DPI-C" function int add(input int a, input int b);
    import "DPI-C" function int instruction_type_check();
    ///*
    assign rs1 = {inst[19:15]};
    assign rs2 = {inst[24:20]};
    assign rd = {inst[11:7]}; 
    assign opcode = {inst[6:0]};
    assign funct3 = {inst[14:12]};
    assign funct7 = {inst[31:25]};
    //*/

    //assign wen = 0;
    //assign outputtype = 3'b000;
    
    always @(*) begin
        //$display("%d", instruction_type_check());
        /*
        rs1 <= {inst[19:15]};
        rs2 <= {inst[24:20]};
        rd <= {inst[11:7]}; 
        opcode <= {inst[6:0]};
        funct3 <= {inst[14:12]};
        funct7 <= {inst[31:25]};
        //*/
        if (inst == 32'h00100073) begin
            npc_trap();
        end
        outputtype = instruction_type_check();
    end
endmodule
