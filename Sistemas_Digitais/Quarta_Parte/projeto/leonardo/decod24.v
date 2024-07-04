`timescale 1 ns/100 ps

module decod24 (en, A, Y);

	input en;
	input [1:0] A;
	output [3:0] Y;

	assign Y[0] = (en) ? ~A[1] & ~A[0] : 1'b0; 
	assign Y[1] = (en) ? ~A[1] & A[0] : 1'b0; 
	assign Y[2] = (en) ? A[1] & ~A[0] : 1'b0; 
	assign Y[3] = (en) ? A[1] & A[0] : 1'b0; 

endmodule
