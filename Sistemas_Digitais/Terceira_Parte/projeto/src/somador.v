`timescale 1 ns/100 ps

module add_1bit (output s, cout, input a, b, cin);
   assign s = a ^ b ^ cin;
   assign cout = (a & b) | (a & cin) | (b & cin);
endmodule

module add_nbit #(parameter Size=8) (output [Size-1:0] s, output co, input [Size-1:0] a, b, input ci);
   wire [Size:0] c;
	
   assign c[0] = ci;
	
   add_1bit u[Size-1:0] (s[Size-1:0], c[Size:1], a[Size-1:0], b[Size-1:0], c[Size-1:0]);
	
   assign co = c[Size];
endmodule
