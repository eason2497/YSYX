module alu (
	input [3:0] in_a,
        input [3:0] in_b,
	input [2:0] sel,
	output reg out_c,
	output reg out_z,
	output reg of,
	output reg [3:0] out_res
);
	//reg [3:0]a = 4'b0000;
 	//reg [3:0]b = 4'b0000;
        //assign a = in_a[3] ? {in_a[3], ~in_a[2:0] + 1} : in_a;
        //assign b = in_b[3] ? {in_b[3], ~in_b[2:0] + 1} : in_b;
	always@(sel) begin
		//a <= in_a[3] ? {in_a[3], ~in_a[2:0] + 1'b1} : in_a;
 		//b <= in_b[3] ? {in_b[3], ~in_b[2:0] + 1'b1} : in_b;   
		case(sel)
			3'b000: begin 
					out_res <= in_a + in_b;
					out_z <= ~{|out_res};
					of <= (in_a[3] ^ in_b[3]) == out_res[3] ? 0 : 1;
				end
			3'b001: begin 
					out_res <= in_a - in_b;
					out_z <= ~{|out_res};
					of <= (in_a[3] ^ in_b[3]) == out_res[3] ? 0 : 1;
				end
			3'b010: out_res <= ~(in_a);
			3'b011: out_res <= in_a & in_b;
			3'b100: out_res <= in_a | in_b;
			3'b101: out_res <= in_a ^ in_b;
			3'b110: if (in_a == 0 && in_b == 0) begin
					out_res <= (in_a < in_b) ? 1 : 0;
				end else if (in_a == 1 && in_b == 1) begin
						out_res <= (in_a[2:0] > in_b[2:0]) ? 1 : 0;
				end else if (in_a == 0 && in_b == 1) begin
					out_res <= 0;
				end else if (in_a == 1 && in_b == 0) begin
					out_res <= 1;
				end
			3'b111: out_res <= (in_a == in_b) ? 1 : 0;
		endcase

	end
	//task check;
	//	input [3:0] results;
	//	input resultof, resultc, resultz;
	//	begin
	//		if (outputs != results)
	//		begin
	//			$display("Error:x=%h, ctrl=%b, s should be %h,get %h", inputa, inputb, inputaluop, results, outputs);
	//		end
	//	end
	//endtask
endmodule
