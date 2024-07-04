`timescale 1 ns/100 ps

module registrador #(parameter Size=8)
   (output reg [Size-1:0] q, input clk, en, rstn, input [Size-1:0] d);

	always @ (negedge clk or negedge rstn)
		if (~rstn)
         		q = 0;
		else begin
			if (en)
				q = d;
		end

endmodule
