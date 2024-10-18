module LFSR(
    input clk,
    input rst,
    input clear,
    output reg [7:0] x,
    output reg [6:0] bcd0,
    output reg [6:0] bcd1 
);
    reg x8;

    always @(posedge clk) begin
        if (rst) begin 
            x = 8'b00000011;
        end
        else begin
            x8 = x[4] ^ x[3] ^ x[2] ^ x[0];
            x = {x8, x[7:1]};
        end
    end

    bcd7seg seg0(
        .clear(clear),
        .b(x[7:4]),
        .h(bcd0)
    );

    bcd7seg seg1(
        .clear(clear),
        .b(x[3:0]),
        .h(bcd1)
    );


endmodule
