module mux41 #(parameter Size=8)
  (Y, S, A0, A1, A2, A3);

  	output [Size-1:0] Y; 
	input [1:0] S;
	input [Size-1:0] A0;
	input [Size-1:0] A1;
	input [Size-1:0] A2;
	input [Size-1:0] A3;

	assign Y = S[0] ? (S[1] ? A3 : A1) : (S[1] ? A2 : A0);

endmodule
