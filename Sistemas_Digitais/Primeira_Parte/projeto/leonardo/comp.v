`timescale 1 ns/100 ps

module Comparador (output G, L, input a, b, g, l);
	assign G = g | (~l & (a & ~b));
	assign L = l | (~g & (~a & b));
endmodule

module juntarComparadores #(parameter Size = 8) (output g, l, input [Size-1:0] a, b);
	wire [Size:0] gi, li;
	assign gi[Size] = 0, li[Size] = 0;
	
	genvar i;
	
	generate
		for (i = 0; i < Size; i = i + 1)
		begin: row
			Comparador ui (gi[i], li[i], a[i], b[i], gi[i+1], li[i+1]);
		end
	endgenerate
	
	assign g = gi[0], l = li[0];
endmodule