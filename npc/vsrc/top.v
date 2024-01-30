	module top(
	input a,
	input b,
	input [15:0] led,
	output f
	);
	assign f = a ^ b;
	endmodule
