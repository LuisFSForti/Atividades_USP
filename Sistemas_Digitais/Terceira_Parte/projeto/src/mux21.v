`timescale 1 ns/100 ps

module Mux21 #(parameter Size = 8)(output [Size-1:0]r, input [Size-1:0] a1, a0, input s);
	assign r = s ? a1 : a0;
endmodule