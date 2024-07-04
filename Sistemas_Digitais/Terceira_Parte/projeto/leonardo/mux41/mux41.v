`timescale 1 ns/100 ps

module Mux41 #(parameter Size = 8)(output [Size-1:0]r, input [Size-1:0] a3, a2, a1, a0, input s1, s0);
	wire [Size:0] r1, r2;
	
	Mux21 #(Size) m1 (r1, a1, a0, s0);
	Mux21 #(Size) m2 (r2, a3, a2, s0);
	Mux21 #(Size) m3 (r, r2, r1, s1);
endmodule