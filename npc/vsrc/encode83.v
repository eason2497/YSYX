module encode83(x, en, y, in, bcd);
    input [7:0] x;
    input en;
    output reg [3:0] y;
    output reg in;
    output reg [6:0] bcd;
    integer i;

    always @(en or x) begin
        if (en) begin
            y <= 0;
            for(i = 0;i <= 7; i = i + 1) begin
                if (x[i] == 1) begin
                    y <= i[3:0];
                    in <= 1;
                end
            end
        end
        else begin
            y <= 0;
        end
    end

    bcd7seg seg0(
        .clear(~en),
        .b(y),
        .h(bcd)
    );

endmodule
