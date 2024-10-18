module top(
  input clk,
  input rst,
  input ps2_clk,
  input ps2_data,
  output [3:0] press,
  output [3:0] bcd1,
  output [3:0] bcd2,
  output [6:0] seg0,
  output [6:0] seg1,
  output [6:0] seg2
);

ps2_keyboard inst(
    .clk(clk),
    .resetn(~rst),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .press(press),
    .bcd1(bcd1),
    .bcd2(bcd2)
);

bcdseg7 segment0(
	.bcd(bcd2),
	.seg(seg0)
);

bcdseg7 segment1(
	.bcd(bcd1),
	.seg(seg1)
);

bcdseg7 segment2(
        .bcd(press),
        .seg(seg2)
);

endmodule
