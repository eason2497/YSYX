module barrel_register (
    input [7:0] din,
    input [2:0] shamt,
    input LR,   //LR = 1 left LR = 0 right
    input AL,   //AL = 1 arithmetic, AL = 0 logical
    output reg [7:0] dout
);

    always @(*) begin
        if (LR == 1) begin
            case(shamt)
                3'b000: dout = din;
                3'b001: dout = din << 1;
                3'b010: dout = din << 2;
                3'b011: dout = din << 3;
                3'b100: dout = din << 4;
                3'b101: dout = din << 5;
                3'b110: dout = din << 6;
                3'b111: dout = din << 7;
            endcase
        end
        else begin
            if (AL == 1) begin 
                case(shamt)
                    3'b000: dout = din;
                    3'b001: dout = {{1{din[7]}}, din[7:1]};
                    3'b010: dout = {{2{din[7]}}, din[7:2]};
                    3'b011: dout = {{3{din[7]}}, din[7:3]};
                    3'b100: dout = {{4{din[7]}}, din[7:4]};
                    3'b101: dout = {{5{din[7]}}, din[7:5]};
                    3'b110: dout = {{6{din[7]}}, din[7:6]};
                    3'b111: dout = {{7{din[7]}}, din[7]};
                endcase
            end
            else begin
                case(shamt)
                    3'b000: dout = din;
                    3'b001: dout = din >> 1;
                    3'b010: dout = din >> 2;
                    3'b011: dout = din >> 3;
                    3'b100: dout = din >> 4;
                    3'b101: dout = din >> 5;
                    3'b110: dout = din >> 6;
                    3'b111: dout = din >> 7;
                endcase
            end
        end
    end
endmodule
