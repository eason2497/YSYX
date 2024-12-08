module Muxtest (
    input [31:0] immI,
    input [31:0] immS,
    input [31:0] immB,
    input [31:0] immU,
    input [31:0] immJ,
    input [2:0] itype,
    output [31:0] imm
);

/*
MuxKey #(5, 3, 32) i3 (
    .out(imm), 
    .key(itype),
    .lut( {
        3'b001, immI,
        3'b010, 32'd2,
        3'b011, 32'd3,
        3'b100, 32'd4,
        3'b101, immJ
}));
//*/
endmodule
