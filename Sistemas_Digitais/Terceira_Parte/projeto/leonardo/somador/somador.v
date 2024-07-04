`timescale 1 ns/100 ps

module somador #(parameter Size=8)
	       (output reg [Size-1:0] s, output reg co, input [Size-1:0] a, b, input ci, mode);

	always @(*) begin
		if (~mode)
			{co, s} = a + b + ci; //Soma os dois números "a", "b" e o carry-in "ci"
		else
			{co, s} = a - b + ci; //Subtrai o número "b" do "b" e soma o carry-in "ci"
	end
		

endmodule
