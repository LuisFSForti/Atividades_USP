//
// Verilog description for cell Decodificador24, 
// 07/04/24 17:35:26
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module Decodificador24 ( r, a1, en ) ;

    output [3:0]r ;
    input [1:0]a1 ;
    input en ;

    wire nx85, nx88, nx91;



    NR3R0 ix23 (.X (r[0]), .A1 (a1[1]), .A2 (nx85), .A3 (a1[0])) ;
    IV1N0 ix86 (.X (nx85), .A (en)) ;
    AN3T0 ix15 (.X (r[1]), .A1 (nx88), .A2 (en), .A3 (a1[0])) ;
    IV1N0 ix89 (.X (nx88), .A (a1[1])) ;
    AN3T0 ix9 (.X (r[2]), .A1 (a1[1]), .A2 (en), .A3 (nx91)) ;
    IV1N0 ix92 (.X (nx91), .A (a1[0])) ;
    AN3T0 ix3 (.X (r[3]), .A1 (a1[1]), .A2 (en), .A3 (a1[0])) ;
endmodule


module AN3T0 ( X, A1, A2, A3 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input A3 ;

    wire nx0;



    and (nx0, A1, A2) ;
    and (X, nx0, A3) ;
endmodule


module IV1N0 ( X, A ) ;

    output X ;
    input A ;




    assign X = ~A ;
endmodule


module NR3R0 ( X, A1, A2, A3 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input A3 ;

    wire NOT_A1, NOT_A2, nx4, NOT_A3;



    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (nx4, NOT_A1, NOT_A2) ;
    assign NOT_A3 = ~A3 ;
    and (X, nx4, NOT_A3) ;
endmodule

