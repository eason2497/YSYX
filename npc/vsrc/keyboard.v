module keyboard (
    input clk,
    input clrn,
    input ps2_clk,
    input ps2_data,
    output reg nextdata_n,
    output reg clearSEG = 1,
    output reg ready,
    output reg overflow,
    output reg [7:0] data,
    output reg [7:0] last_data,
    output reg [7:0] display,
    output reg [7:0] pressed,
    output reg [7:0] ascii,
    output reg [6:0] bcd0,
    output reg [6:0] bcd1,
    output reg [6:0] bcd2,
    output reg [6:0] bcd3,
    output reg [6:0] bcd4,
    output reg [6:0] bcd5
);
    reg checkRepeated = 0;
    reg break_code = 0;

    always @(posedge clk) begin
        if (ready) begin
            if (data == 8'hf0) begin    //记录断码并清除显示
                break_code <= 1;
                clearSEG <= 1;
            end
            else begin
                if (break_code == 1) begin   //断码后的一位也不作于记录按键总数
                    clearSEG <= 1;
                    break_code <= 0;
                    checkRepeated <= 0;
                end
                else if (break_code == 0) begin
                    if (~checkRepeated || data != last_data) begin //当按键一直按住时，不会增加计数
                        pressed <= pressed + 7'b1;
                        last_data <= data;
                        checkRepeated <= 1;
                        display <= data;
                        clearSEG <= 0;
                    end
                end
            end
        end
    end

    ps2_keyboard key0 (
        .clk(clk),
        .clrn(clrn),
        .ps2_clk(ps2_clk),
        .ps2_data(ps2_data),
        .nextdata_n(nextdata_n),
        .data(data),
        .ready(ready),
        .overflow(overflow)
    );

    convertASCII convert0 (
        .code(display),
        .ascii(ascii)
    );

    bcd7seg seg5(
        .clear(0),
        .b(pressed[7:4]),
        .h(bcd5)
    );

    bcd7seg seg4(
        .clear(0),
        .b(pressed[3:0]),
        .h(bcd4)
    );

    bcd7seg seg3(
        .clear(clearSEG),
        .b(ascii[7:4]),
        .h(bcd3)
    );

    bcd7seg seg2(
        .clear(clearSEG),
        .b(ascii[3:0]),
        .h(bcd2)
    );

    bcd7seg seg1(
        .clear(clearSEG),
        .b(display[7:4]),
        .h(bcd1)
    );

    bcd7seg seg0(
        .clear(clearSEG),
        .b(display[3:0]),
        .h(bcd0)
    );

endmodule


