`timescale 1 ns/100 ps

module tff(output reg q, output qb, input clk, en, clr_n, t);

	always @ (negedge clk or negedge clr_n)
		if (~clr_n)
			q = 1'b0;
		else begin
			if (en)
				q = t ^ q;
		end

	assign qb = ~q;

endmodule


module contador #(parameter Size = 8) (output [Size-1:0] Q, input clk, en, clr_n);

  	wire [Size:0] w;
	wire Id;

	assign Id = 1'b1;
  
	tff ti (.q(w[0]), .clk(clk), .en(en), .clr_n(clr_n), .t(Id));
  
	genvar i;
		generate
	
			for (i = 1; i < Size; i = i + 1)
				begin: row
					tff ti (.q(w[i]), .clk(w[i-1]), .en(en), .clr_n(clr_n), .t(Id));
				end
		endgenerate

	assign Q = w;

endmodule