`timescale 1 ns/100 ps

module priority_encoder (output A1, A0, GS, EO, input x3, x2, x1, x0);
	assign A1 = x3 | ~x2;
	assign A0 = x3 | x2 & x1;
	assign GS = (x3 | x2 |x1 | x0);
	assign EO = ~(x3 | x2 |x1 | x0);
endmodule