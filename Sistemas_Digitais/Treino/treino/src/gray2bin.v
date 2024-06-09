`timescale 1 ns/100 ps

module gray2bin (output B2, B1, B0, input g2, g1, g0);
	assign B2 = g2;
	assign B1 = g2 ^ g1;
	assign B0 = g2 ^ g1 ^ g0;

endmodule