module top_shift_reg(
	//input [7:0] din,
	input rst,
	input clk,
	input button,
	output reg [7:0] dout,
	output reg [6:0] seg0,
	output reg [6:0] seg1
);
	//assign dout = 8'b00001101;
	shift_reg sr(
		//.din(din),
		.rst(rst),
		.clk(clk),
		.button(button),
		.dout(dout)
	);
	bcdseg7 bcd0(
		.bcd(dout[3:0]),
		.seg(seg0)
	);
	bcdseg7 bcd1(
		.bcd(dout[7:4]),
		.seg(seg1)
	);

endmodule
