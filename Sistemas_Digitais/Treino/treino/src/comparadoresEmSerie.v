`timescale 1 ns/100 ps

module juntarComparadores #(parameter SIZE = 8) (output g, l, input [SIZE-1:0] a, b);
	wire [SIZE:0] gi, li;
	assign gi[SIZE] = 0, li[SIZE] = 0;
	
	genvar i;
	
	generate
		for (i = 0; i < SIZE; i = i + 1)
		begin: row
			Comparador ui (gi[i], li[i], a[i], b[i], gi[i+1], li[i+1]);
		end
	endgenerate
	
	assign g = gi[0], l = li[0];
endmodule