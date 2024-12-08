module alu(
    input [3:0] a,
    input [3:0] b,
    input [2:0] select,
    output reg [3:0] result,
    output reg c,
    output reg z,
    output reg overflow
);
    reg [3:0] temp_a;
    reg [3:0] temp_b;

    always @(select or a or b) begin
        c = 0;
        z = 0;
        overflow = 0;
        temp_a = 4'b0000;
        temp_b = 4'b0000; //为了避免latch发生应该使变量能在所有情况下都被赋值
        case(select)
            3'b000: begin 
                    {c, result} = a + b;
                    overflow = (a[3] == b[3]) && (result[3] != a[3]);
                    z = ~(|result);
                    end
            3'b001: begin    //目前这样会有延迟，显示结果会出现在下一个周期的时候
                             //已解决，需要注意的是阻塞赋值和非阻塞赋值不能同时使用
                    temp_b = ~b + 4'b0001;
                    {c, result} = a + temp_b;
                    overflow = (a[3] == temp_b[3]) && (result[3] != a[3]);
                    z = ~(|result);
                    end
            3'b010: result = ~a; // ~ is a bit-wise operator and retures the invert of the arguiment
                            // ! is a logical operator and returs a single bit.
            3'b011: result = a & b;
            3'b100: result = a | b;
            3'b101: result = a ^ b;
            3'b110: begin
                    if (a[3] == b[3] && a[3] == 1) begin
                        temp_a = ~a + 1'b1;
                        temp_b = ~b + 1'b1;
                        if (temp_a < temp_b) 
                            result = 1;
                        else
                            result = 0;                        
                    end
                    else if (a[3] == b[3] && a[3] == 0) begin
                        if (a < b) 
                            result = 1;
                        else
                            result = 0;
                    end
                    else if (a[3] == 1 && b[3] == 0)
                        result = 1;
                    else
                        result = 0;
                    end
            3'b111: begin 
                    if (a == b)
                        result = 1;
                    else
                        result = 0;
                    end
        endcase
    end

endmodule
