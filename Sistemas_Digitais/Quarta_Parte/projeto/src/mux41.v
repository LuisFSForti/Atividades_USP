module mux41 #(parameter Size=8)
  (Y, S, A0, A1, A2, A3);

  	output [Size-1:0] Y; 
	input [1:0] S;
	input [Size-1:0] A0;
	input [Size-1:0] A1;
	input [Size-1:0] A2;
	input [Size-1:0] A3;

	//Se S[0] for 0, escolhe entre A2 e A0 (se S[1] for 1 ou 0, respectivamente)
	//Se S[0] for 1, escolhe entre A3 e A1 (se S[1] for 1 ou 0, respectivamente)
	assign Y = S[0] ? (S[1] ? A3 : A1) : (S[1] ? A2 : A0);

endmodule
