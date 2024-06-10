//
// Verilog description for cell BN, 
// 06/10/24 10:02:53
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module BN ( max, min, a, b ) ;

    output [7:0]max ;
    output [7:0]min ;
    input [7:0]a ;
    input [7:0]b ;

    wire l;
    wire [0:0] \$dummy ;




    juntarComparadores_8 Comp (.g (\$dummy [0]), .l (l), .a ({a[7],a[6],a[5],
                         a[4],a[3],a[2],a[1],a[0]}), .b ({b[7],b[6],b[5],b[4],
                         b[3],b[2],b[1],b[0]})) ;
    MX2T0 ix7 (.X (min[0]), .A (a[0]), .B (b[0]), .S (l)) ;
    MX2T0 ix15 (.X (min[1]), .A (a[1]), .B (b[1]), .S (l)) ;
    MX2T0 ix23 (.X (min[2]), .A (a[2]), .B (b[2]), .S (l)) ;
    MX2T0 ix31 (.X (min[3]), .A (a[3]), .B (b[3]), .S (l)) ;
    MX2T0 ix39 (.X (min[4]), .A (a[4]), .B (b[4]), .S (l)) ;
    MX2T0 ix47 (.X (min[5]), .A (a[5]), .B (b[5]), .S (l)) ;
    MX2T0 ix55 (.X (min[6]), .A (a[6]), .B (b[6]), .S (l)) ;
    MX2T0 ix63 (.X (min[7]), .A (a[7]), .B (b[7]), .S (l)) ;
    MX2T0 ix71 (.X (max[0]), .A (b[0]), .B (a[0]), .S (l)) ;
    MX2T0 ix79 (.X (max[1]), .A (b[1]), .B (a[1]), .S (l)) ;
    MX2T0 ix87 (.X (max[2]), .A (b[2]), .B (a[2]), .S (l)) ;
    MX2T0 ix95 (.X (max[3]), .A (b[3]), .B (a[3]), .S (l)) ;
    MX2T0 ix103 (.X (max[4]), .A (b[4]), .B (a[4]), .S (l)) ;
    MX2T0 ix111 (.X (max[5]), .A (b[5]), .B (a[5]), .S (l)) ;
    MX2T0 ix119 (.X (max[6]), .A (b[6]), .B (a[6]), .S (l)) ;
    MX2T0 ix127 (.X (max[7]), .A (b[7]), .B (a[7]), .S (l)) ;
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


module juntarComparadores_8 ( g, l, a, b ) ;

    output g ;
    output l ;
    input [7:0]a ;
    input [7:0]b ;

    wire nx28, nx48, nx58, nx88, nx98, nx118, nx128, nx153, nx155, nx157, nx159, 
         nx161, nx163, nx165, nx167, nx169, nx171, nx173, nx175, nx177, nx179, 
         nx181, nx183, nx185, nx187, nx216, nx218;



    OAI3R2 ix139 (.X (l), .A1 (nx128), .A2 (a[0]), .A3 (nx185), .B (nx187)) ;
    OAI3R0 ix129 (.X (nx128), .A1 (nx98), .A2 (nx181), .A3 (b[1]), .B (nx183)) ;
    OAI3R0 ix99 (.X (nx98), .A1 (nx88), .A2 (a[2]), .A3 (nx177), .B (nx179)) ;
    OAI3R0 ix89 (.X (nx88), .A1 (nx58), .A2 (nx173), .A3 (b[3]), .B (nx175)) ;
    OAI3R0 ix59 (.X (nx58), .A1 (nx48), .A2 (a[4]), .A3 (nx169), .B (nx171)) ;
    OAI3R0 ix49 (.X (nx48), .A1 (nx28), .A2 (nx161), .A3 (b[5]), .B (nx163)) ;
    OAI1A0 ix29 (.X (nx28), .A1 (a[7]), .A2 (nx153), .B (nx155)) ;
    IV1N0 ix154 (.X (nx153), .A (b[7])) ;
    OAI3N0 ix156 (.X (nx155), .A1 (nx157), .A2 (b[7]), .B1 (nx159), .B2 (b[6])
           ) ;
    IV1N0 ix158 (.X (nx157), .A (a[7])) ;
    IV1N0 ix160 (.X (nx159), .A (a[6])) ;
    IV1N0 ix162 (.X (nx161), .A (a[5])) ;
    OAI3N0 ix166 (.X (nx165), .A1 (nx153), .A2 (a[7]), .B1 (a[6]), .B2 (nx167)
           ) ;
    IV1N0 ix168 (.X (nx167), .A (b[6])) ;
    IV1N0 ix170 (.X (nx169), .A (b[4])) ;
    AO3I0 ix172 (.X (nx171), .A1 (nx163), .A2 (nx161), .A3 (b[5]), .B (nx28)) ;
    IV1N0 ix174 (.X (nx173), .A (a[3])) ;
    AO3I0 ix176 (.X (nx175), .A1 (nx171), .A2 (a[4]), .A3 (nx169), .B (nx48)) ;
    IV1N0 ix178 (.X (nx177), .A (b[2])) ;
    AO3I0 ix180 (.X (nx179), .A1 (nx175), .A2 (nx173), .A3 (b[3]), .B (nx58)) ;
    IV1N0 ix182 (.X (nx181), .A (a[1])) ;
    AO3I0 ix184 (.X (nx183), .A1 (nx179), .A2 (a[2]), .A3 (nx177), .B (nx88)) ;
    IV1N0 ix186 (.X (nx185), .A (b[0])) ;
    AO3I0 ix188 (.X (nx187), .A1 (nx183), .A2 (nx181), .A3 (b[1]), .B (nx98)) ;
    OAI3R0 ix149 (.X (g), .A1 (nx118), .A2 (nx216), .A3 (b[0]), .B (nx218)) ;
    IV1N0 ix217 (.X (nx216), .A (a[0])) ;
    IV1N0 ix219 (.X (nx218), .A (nx128)) ;
    IV1N0 ix119 (.X (nx118), .A (nx187)) ;
    OA1R0 ix15 (.X (nx163), .A1 (nx157), .A2 (b[7]), .B (nx165)) ;
endmodule


module OA1R0 ( X, A1, A2, B ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B ;

    wire nx0, nx2;



    and (nx0, A2, B) ;
    and (nx2, A1, B) ;
    or (X, nx0, nx2) ;
endmodule


module AO3I0 ( X, A1, A2, A3, B ) ;

    output X ;
    input A1 ;
    input A2 ;
    input A3 ;
    input B ;

    wire NOT_A3, NOT_B, nx4, NOT_A2, nx8, nx10, NOT_A1, nx14;



    assign NOT_A3 = ~A3 ;
    assign NOT_B = ~B ;
    and (nx4, NOT_A3, NOT_B) ;
    assign NOT_A2 = ~A2 ;
    and (nx8, NOT_A2, NOT_B) ;
    or (nx10, nx4, nx8) ;
    assign NOT_A1 = ~A1 ;
    and (nx14, NOT_A1, NOT_B) ;
    or (X, nx10, nx14) ;
endmodule


module OAI3N0 ( X, A1, A2, B1, B2 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B1 ;
    input B2 ;

    wire NOT_A1, NOT_A2, nx4, NOT_B2, nx8, NOT_B1;



    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (nx4, NOT_A1, NOT_A2) ;
    assign NOT_B2 = ~B2 ;
    or (nx8, nx4, NOT_B2) ;
    assign NOT_B1 = ~B1 ;
    or (X, nx8, NOT_B1) ;
endmodule


module IV1N0 ( X, A ) ;

    output X ;
    input A ;




    assign X = ~A ;
endmodule


module OAI1A0 ( X, A1, A2, B ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B ;

    wire NOT_A1, NOT_A2, nx4, NOT_B;



    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (nx4, NOT_A1, NOT_A2) ;
    assign NOT_B = ~B ;
    or (X, nx4, NOT_B) ;
endmodule


module OAI3R0 ( X, A1, A2, A3, B ) ;

    output X ;
    input A1 ;
    input A2 ;
    input A3 ;
    input B ;

    wire NOT_A1, NOT_A2, nx4, NOT_A3, nx8, NOT_B;



    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (nx4, NOT_A1, NOT_A2) ;
    assign NOT_A3 = ~A3 ;
    and (nx8, nx4, NOT_A3) ;
    assign NOT_B = ~B ;
    or (X, nx8, NOT_B) ;
endmodule


module OAI3R2 ( X, A1, A2, A3, B ) ;

    output X ;
    input A1 ;
    input A2 ;
    input A3 ;
    input B ;

    wire NOT_A1, NOT_A2, nx4, NOT_A3, nx8, NOT_B;



    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (nx4, NOT_A1, NOT_A2) ;
    assign NOT_A3 = ~A3 ;
    and (nx8, nx4, NOT_A3) ;
    assign NOT_B = ~B ;
    or (X, nx8, NOT_B) ;
endmodule

