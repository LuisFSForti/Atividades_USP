`timescale 1 ns/100 ps

module bin2gray (output G2, G1, G0, input b2, b1, b0);
	assign G2 = b2;
	assign G1 = b2 ^ b1;
	assign G0 = b1 ^ b0;
endmodule