module ps2_keyboard(clk,clrn,ps2_clk,ps2_data,data,
                    ready,nextdata_n,overflow);
    input clk,clrn,ps2_clk,ps2_data;
    output reg nextdata_n;
    output reg [7:0] data;
    output reg ready;
    output reg overflow;     // fifo overflow
    //output reg [7:0] pressed;
    // internal signal, for test
    reg [9:0] buffer;        // ps2_data bits
    reg [7:0] fifo[7:0];     // data fifo
    reg [2:0] w_ptr,r_ptr;   // fifo write and read pointers
    reg [3:0] count;  // count ps2_data bits
    // detect falling edge of ps2_clk
    reg [2:0] ps2_clk_sync;

    reg lock;

    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk}; //记录最新的clk信号
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1]; //赋值sampling，如果历史信号是由1变0,那么
                                                        //sampling便等于1,并开始接收数据

    always @(posedge clk) begin
        if (clrn == 0) begin // reset
            count <= 0; w_ptr <= 0; r_ptr <= 0; overflow <= 0; ready<= 0; nextdata_n <= 0;
        end
        else begin
            if ( ready ) begin // read to output next data
                if(nextdata_n == 1'b0) //read next data
                begin
                    r_ptr <= r_ptr + 3'b1;
                    if(w_ptr==(r_ptr+1'b1)) //empty
                        ready <= 1'b0;
                end
            end

            if (sampling) begin
                if (count == 4'd10) begin
                    if ((buffer[0] == 0) &&  // start bit
                        (ps2_data)       &&  // stop bit
                        (^buffer[9:1])) begin      // odd  parity
                        fifo[w_ptr] <= buffer[8:1];  // kbd scan code
                        $display("receive %x", buffer[8:1]);
                        w_ptr <= w_ptr+3'b1;
                        ready <= 1'b1;
                        nextdata_n <= 1'b0;
                        overflow <= overflow | (r_ptr == (w_ptr + 3'b1));
                    end
                    count <= 0;     // for next
                end 
                else begin                      //低位在前，由0到7一个个记录
                    buffer[count] <= ps2_data;  //store ps2_data 当count没到10的时候一直读新的ps2_data
                    count <= count + 3'b1;
                end
            end
        end
    end
    assign data = fifo[r_ptr]; //always set output data

endmodule