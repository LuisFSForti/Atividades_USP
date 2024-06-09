`timescale 1 ns/100 ps

module ProcurarMenor #(parameter Size = 8) (output [Size-1:0] max, min, input [Size-1:0] a, b);
	wire g, l;
	juntarComparadores #(Size) Comp (g, l, a, b);
	Mux2x1 #(Size) muxMax (max, b, a, l);
	Mux2x1 #(Size) muxMin (min, a, b, l);
endmodule