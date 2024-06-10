//Luis Filipe Silva Forti - 14592348

`timescale 1 ns/100 ps

module ordenador #(parameter Size = 8) (output [Size-1:0] y8, y7, y6, y5, y4, y3, y2, y1, 
input [Size-1:0] x8, x7, x6, x5, x4, x3, x2, x1);

	wire [Size-1:0] linha1[4:0], linha8[4:0]; //Extremidade superior e inferior
	wire [Size-1:0] linha2[7:0], linha3[7:0], linha4[7:0], linha5[7:0], linha6[7:0], linha7[7:0]; //Meio

	assign linha1[0] = x1;
	assign linha2[0] = x2;
	assign linha3[0] = x3;
	assign linha4[0] = x4;
	assign linha5[0] = x5;
	assign linha6[0] = x6;
	assign linha7[0] = x7;
	assign linha8[0] = x8;
	
	genvar i;
	generate
	
		for (i = 0; i < 7; i = i + 1)
		begin: row
          if (i % 2 == 0)
				begin: rowp
               BN #(Size) bni1 (linha1[i/2+1], linha2[i+1], linha1[i/2], linha2[i]);
					BN #(Size) bni2 (linha3[i+1], linha4[i+1], linha3[i], linha4[i]);
					BN #(Size) bni3 (linha5[i+1], linha6[i+1], linha5[i], linha6[i]);
					BN #(Size) bni4 (linha7[i+1], linha8[i/2+1], linha7[i], linha8[i/2]);
				end
			else
				begin: rowi
					BN #(Size) bni1 (linha2[i+1], linha3[i+1], linha2[i], linha3[i]);
					BN #(Size) bni2 (linha4[i+1], linha5[i+1], linha4[i], linha5[i]);
					BN #(Size) bni3 (linha6[i+1], linha7[i+1], linha6[i], linha7[i]);
				end
		end
	endgenerate
	
	assign y1 = linha1[4];
	assign y2 = linha2[7];
	assign y3 = linha3[7];
	assign y4 = linha4[7];
	assign y5 = linha5[7];
	assign y6 = linha6[7];
	assign y7 = linha7[7];
	assign y8 = linha8[4];

endmodule