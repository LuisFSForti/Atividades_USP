`timescale 1 ns/100 ps

module banco_de_registradores #(parameter Size=8)
	(output [Size-1:0] rd1, rd2, input clk, clr_n, we, input [Size-1:0] wd, input [1:0] a1, a2);

	//Resultados do decodificador
	wire [3:0] Y;
	//Resultados dos registradores
	wire [Size-1:0] A3, A2, A1, A0;
	
	//Decodifica a entrada a1
	decod24 Decod (we, a1, Y);
	
	//Registra a entrada wd nos registradores chamados pelo decodificador
	registrador #(Size) R1 (A3, clk, Y[3], clr_n, wd);
	registrador #(Size) R2 (A2, clk, Y[2], clr_n, wd);
	registrador #(Size) R3 (A1, clk, Y[1], clr_n, wd);
	registrador #(Size) R4 (A0, clk, Y[0], clr_n, wd);
	
	//Chama 2 mux, o primeiro utilizando a entrada a2 como chave de escolha
	//o segundo utilizando a entrada a1
	//Ambos escolhem dentre as mesmas entradas, que são as saídas dos registradores
	mux41 #(Size) mux1 (rd2, a2, A0, A1, A2, A3);
	mux41 #(Size) mux2 (rd1, a1, A0, A1, A2, A3);

endmodule