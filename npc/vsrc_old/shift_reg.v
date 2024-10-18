module shift_reg(
	//input [7:0] din,
	input rst,
	input clk,
	input button,
	output reg [7:0] dout
);
	reg x8;
	always@(button) begin
		//if (din == 8'b00000000) begin
		//	#dout <= 8'b00000110;
		//end else begin
		if (rst) 
			dout <= 8'b00000110;
		else begin
			x8 <= dout[4] ^ dout[3] ^ dout[2] ^ dout[0];
			dout <= {x8, dout[7:1]};
		end
	end
endmodule
