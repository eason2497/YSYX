	module top_encode(
	input [7:0] sw,
	input en,
	output reg  [2:0] led,
	output reg indicate,
	output reg [6:0] seg
	);

	wire [2:0] w;

	assign led = w;
	
	encoder83 encode(
		.x(sw),
		.en(en),
		.y(w),
		.indicate(indicate)
	);

	bcdseg7 seg0(
		.bcd({1'b0, w}),
		.seg(seg)
	);

	endmodule
