module registrador #(parameter Size=8)
   (output reg [Size-1:0] q, input clk, en, rstn, input [Size-1:0] d);

	//Quando clk ou rstn forem 0
	always @ (negedge clk or negedge rstn)
		//Se rstn for 0, reinicia o registrador
		if (~rstn)
         		q = 0;
		else begin
			//Se rstn for 1 e en for 1
			if (en)
				//Registra o dado passado
				q = d;
		end

endmodule
