`timescale 1 ns/100 ps

module Decodificador24 (output [3:0]r, input[1:0] a1, input en);
	assign r[0] = en & (~(a1[1] | a1[0]));
	assign r[1] = en & (~a1[1] & a1[0]);
	assign r[2] = en & (a1[1] & ~a1[0]);
	assign r[3] = en & (a1[1] & a1[0]);	
endmodule