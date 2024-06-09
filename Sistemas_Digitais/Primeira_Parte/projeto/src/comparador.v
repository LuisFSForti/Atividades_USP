`timescale 1 ns/100 ps

module Comparador (output G, L, input a, b, g, l);
	assign G = g | (~l & (a & ~b));
	assign L = l | (~g & (~a & b));
endmodule