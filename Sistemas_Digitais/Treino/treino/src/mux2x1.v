`timescale 1 ns/100 ps

module Mux2x1 #(parameter SIZE = 2)(output [SIZE-1:0]r, input [SIZE-1:0] a1, a0, input s);
	assign r = s ? a1 : a0;
endmodule