	module top_alu(
		input [3:0] in_a,
		input [3:0] in_b,
		input [2:0] sel,
		output reg out_c,
		output reg out_z,
		output reg of,
		output reg [3:0] out_res
	);
	alu alu0(
		.in_a(in_a),
		.in_b(in_b),
		.sel(sel),
		.out_c(out_c),
		.out_z(out_z),
		.of(of),
		.out_res(out_res)
	);
	endmodule
