`timescale 1 ns/100 ps

module teste(output [2:0]r, input [2:0]i);
	wire g2, g1, g0;
	bin2gray t1 (g2, g1, g0, i[2], i[1], i[0]);
	gray2bin t2 (r[2], r[1], r[0], g2, g1, g0);
endmodule