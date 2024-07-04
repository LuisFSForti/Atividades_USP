//
// Verilog description for cell Mux21, 
// 07/04/24 17:34:19
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module Mux21 ( r, a1, a0, s ) ;

    output [7:0]r ;
    input [7:0]a1 ;
    input [7:0]a0 ;
    input s ;




    MX2T0 ix7 (.X (r[0]), .A (a1[0]), .B (a0[0]), .S (s)) ;
    MX2T0 ix15 (.X (r[1]), .A (a1[1]), .B (a0[1]), .S (s)) ;
    MX2T0 ix23 (.X (r[2]), .A (a1[2]), .B (a0[2]), .S (s)) ;
    MX2T0 ix31 (.X (r[3]), .A (a1[3]), .B (a0[3]), .S (s)) ;
    MX2T0 ix39 (.X (r[4]), .A (a1[4]), .B (a0[4]), .S (s)) ;
    MX2T0 ix47 (.X (r[5]), .A (a1[5]), .B (a0[5]), .S (s)) ;
    MX2T0 ix55 (.X (r[6]), .A (a1[6]), .B (a0[6]), .S (s)) ;
    MX2T0 ix63 (.X (r[7]), .A (a1[7]), .B (a0[7]), .S (s)) ;
endmodule


module MX2T0 ( X, A, B, S ) ;

    output X ;
    input A ;
    input B ;
    input S ;

    wire NOT_S, nx2, nx4;



    assign NOT_S = ~S ;
    and (nx2, B, NOT_S) ;
    and (nx4, A, S) ;
    or (X, nx2, nx4) ;
endmodule

