module shift_reg (
    input [7:0] D,
    input clk,
    input [2:0] select,
    output reg [7:0] Q
);
    always @(podedge) begin
        case(select)
            3'b000: Q = 0;
            3'b001: Q = D;
            3'b010: Q = {1'b0, Q[7:1]};  //Q >> 1
            3'b011: Q = {Q[6:0], 1'b0};  //Q << 1
            3'b100: Q = {Q[7], Q[7:1]};
            3'b101: Q = {D[7], Q[7:1]};
            3'b110: Q = {Q[0], Q[7:1]};
            3'b111: Q = {Q[6:0], Q[7]};
        endcase
    end
endmodule
