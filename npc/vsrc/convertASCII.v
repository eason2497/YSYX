module convertASCII (
    input [7:0] code,
    output reg [7:0] ascii
);
    always @(code) begin
        case(code)
            8'h15: ascii = 8'd113;
            8'h1d: ascii = 8'd119;
            8'h24: ascii = 8'd101;
            8'h2d: ascii = 8'd114;
            8'h2c: ascii = 8'd116;
            8'h35: ascii = 8'd121;
            8'h3c: ascii = 8'd117;
            8'h43: ascii = 8'd105;
            8'h44: ascii = 8'd111;
            8'h4d: ascii = 8'd112;
            8'h54: ascii = 8'd91;
            8'h5b: ascii = 8'd93;
            8'h1c: ascii = 8'd97;
            8'h1b: ascii = 8'd115;
            8'h23: ascii = 8'd100;
            8'h2b: ascii = 8'd102;
            8'h34: ascii = 8'd103;
            8'h33: ascii = 8'd104;
            8'h3b: ascii = 8'd106;
            8'h42: ascii = 8'd107;
            8'h4b: ascii = 8'd108;
            8'h4c: ascii = 8'd59;
            8'h52: ascii = 8'd39;
            8'h1a: ascii = 8'd122;
            8'h22: ascii = 8'd120;
            8'h21: ascii = 8'd99;
            8'h2a: ascii = 8'd118;
            8'h32: ascii = 8'd98;
            8'h31: ascii = 8'd110;
            8'h3a: ascii = 8'd109;
            8'h41: ascii = 8'd44;
            8'h49: ascii = 8'd46;
            8'h4a: ascii = 8'd47;
            8'h16: ascii = 8'd49;
            8'h1e: ascii = 8'd50;
            8'h26: ascii = 8'd51;
            8'h25: ascii = 8'd52;
            8'h2e: ascii = 8'd53;
            8'h36: ascii = 8'd54;
            8'h3d: ascii = 8'd55;
            8'h3e: ascii = 8'd56;
            8'h46: ascii = 8'd57;
            8'h45: ascii = 8'd48;
            default: ascii = 0;
        endcase
    end
endmodule
