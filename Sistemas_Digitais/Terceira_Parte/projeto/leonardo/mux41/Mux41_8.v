//
// Verilog description for cell Mux41, 
// 07/04/24 17:33:15
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module Mux41 ( r, a3, a2, a1, a0, s1, s0 ) ;

    output [7:0]r ;
    input [7:0]a3 ;
    input [7:0]a2 ;
    input [7:0]a1 ;
    input [7:0]a0 ;
    input s1 ;
    input s0 ;

    wire nx2, nx8, nx18, nx22, nx280, nx285, nx288, nx291, nx294, nx297, nx300, 
         nx303, nx306, nx309;



    IV1N0 ix29 (.X (r[0]), .A (nx280)) ;
    AO8L0 ix281 (.X (nx280), .A1 (a3[0]), .A2 (nx22), .B1 (a0[0]), .B2 (nx18), .C1 (
          a1[0]), .C2 (nx8), .D1 (a2[0]), .D2 (nx2)) ;
    AN2T0 ix23 (.X (nx22), .A1 (s1), .A2 (s0)) ;
    NR2R1 ix19 (.X (nx18), .A1 (s1), .A2 (s0)) ;
    NR2R1 ix9 (.X (nx8), .A1 (s1), .A2 (nx285)) ;
    IV1N0 ix286 (.X (nx285), .A (s0)) ;
    NR2R1 ix3 (.X (nx2), .A1 (nx288), .A2 (s0)) ;
    IV1N0 ix289 (.X (nx288), .A (s1)) ;
    IV1N0 ix43 (.X (r[1]), .A (nx291)) ;
    AO8L0 ix292 (.X (nx291), .A1 (a3[1]), .A2 (nx22), .B1 (a0[1]), .B2 (nx18), .C1 (
          a1[1]), .C2 (nx8), .D1 (a2[1]), .D2 (nx2)) ;
    IV1N0 ix57 (.X (r[2]), .A (nx294)) ;
    AO8L0 ix295 (.X (nx294), .A1 (a3[2]), .A2 (nx22), .B1 (a0[2]), .B2 (nx18), .C1 (
          a1[2]), .C2 (nx8), .D1 (a2[2]), .D2 (nx2)) ;
    IV1N0 ix71 (.X (r[3]), .A (nx297)) ;
    AO8L0 ix298 (.X (nx297), .A1 (a3[3]), .A2 (nx22), .B1 (a0[3]), .B2 (nx18), .C1 (
          a1[3]), .C2 (nx8), .D1 (a2[3]), .D2 (nx2)) ;
    IV1N0 ix85 (.X (r[4]), .A (nx300)) ;
    AO8L0 ix301 (.X (nx300), .A1 (a3[4]), .A2 (nx22), .B1 (a0[4]), .B2 (nx18), .C1 (
          a1[4]), .C2 (nx8), .D1 (a2[4]), .D2 (nx2)) ;
    IV1N0 ix99 (.X (r[5]), .A (nx303)) ;
    AO8L0 ix304 (.X (nx303), .A1 (a3[5]), .A2 (nx22), .B1 (a0[5]), .B2 (nx18), .C1 (
          a1[5]), .C2 (nx8), .D1 (a2[5]), .D2 (nx2)) ;
    IV1N0 ix113 (.X (r[6]), .A (nx306)) ;
    AO8L0 ix307 (.X (nx306), .A1 (a3[6]), .A2 (nx22), .B1 (a0[6]), .B2 (nx18), .C1 (
          a1[6]), .C2 (nx8), .D1 (a2[6]), .D2 (nx2)) ;
    IV1N0 ix127 (.X (r[7]), .A (nx309)) ;
    AO8L0 ix310 (.X (nx309), .A1 (a3[7]), .A2 (nx22), .B1 (a0[7]), .B2 (nx18), .C1 (
          a1[7]), .C2 (nx8), .D1 (a2[7]), .D2 (nx2)) ;
endmodule


module NR2R1 ( X, A1, A2 ) ;

    output X ;
    input A1 ;
    input A2 ;

    wire NOT_A1, NOT_A2;



    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (X, NOT_A1, NOT_A2) ;
endmodule


module AN2T0 ( X, A1, A2 ) ;

    output X ;
    input A1 ;
    input A2 ;




    and (X, A1, A2) ;
endmodule


module AO8L0 ( X, A1, A2, B1, B2, C1, C2, D1, D2 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B1 ;
    input B2 ;
    input C1 ;
    input C2 ;
    input D1 ;
    input D2 ;

    wire NOT_A2, NOT_B2, nx4, NOT_C2, nx8, NOT_D2, nx12, NOT_A1, nx16, nx18, 
         nx20, nx22, NOT_B1, nx26, nx28, nx30, nx32, nx34, nx36, nx38, nx40, 
         nx42, NOT_C1, nx46, nx48, nx50, nx52, nx54, nx56, nx58, nx60, nx62, 
         nx64, nx66, nx68, nx70, nx72, nx74, nx76, nx78, NOT_D1, nx82, nx84, 
         nx86, nx88, nx90, nx92, nx94, nx96, nx98, nx100, nx102, nx104, nx106, 
         nx108, nx110, nx112, nx114, nx116, nx118, nx120, nx122, nx124, nx126, 
         nx128, nx130, nx132, nx134, nx136, nx138;



    assign NOT_A2 = ~A2 ;
    assign NOT_B2 = ~B2 ;
    and (nx4, NOT_A2, NOT_B2) ;
    assign NOT_C2 = ~C2 ;
    and (nx8, nx4, NOT_C2) ;
    assign NOT_D2 = ~D2 ;
    and (nx12, nx8, NOT_D2) ;
    assign NOT_A1 = ~A1 ;
    and (nx16, NOT_A1, NOT_B2) ;
    and (nx18, nx16, NOT_C2) ;
    and (nx20, nx18, NOT_D2) ;
    or (nx22, nx12, nx20) ;
    assign NOT_B1 = ~B1 ;
    and (nx26, NOT_A2, NOT_B1) ;
    and (nx28, nx26, NOT_C2) ;
    and (nx30, nx28, NOT_D2) ;
    or (nx32, nx22, nx30) ;
    and (nx34, NOT_A1, NOT_B1) ;
    and (nx36, nx34, NOT_C2) ;
    and (nx38, nx36, NOT_D2) ;
    or (nx40, nx32, nx38) ;
    and (nx42, NOT_A2, NOT_B2) ;
    assign NOT_C1 = ~C1 ;
    and (nx46, nx42, NOT_C1) ;
    and (nx48, nx46, NOT_D2) ;
    or (nx50, nx40, nx48) ;
    and (nx52, NOT_A1, NOT_B2) ;
    and (nx54, nx52, NOT_C1) ;
    and (nx56, nx54, NOT_D2) ;
    or (nx58, nx50, nx56) ;
    and (nx60, NOT_A2, NOT_B1) ;
    and (nx62, nx60, NOT_C1) ;
    and (nx64, nx62, NOT_D2) ;
    or (nx66, nx58, nx64) ;
    and (nx68, NOT_A1, NOT_B1) ;
    and (nx70, nx68, NOT_C1) ;
    and (nx72, nx70, NOT_D2) ;
    or (nx74, nx66, nx72) ;
    and (nx76, NOT_A2, NOT_B2) ;
    and (nx78, nx76, NOT_C2) ;
    assign NOT_D1 = ~D1 ;
    and (nx82, nx78, NOT_D1) ;
    or (nx84, nx74, nx82) ;
    and (nx86, NOT_A1, NOT_B2) ;
    and (nx88, nx86, NOT_C2) ;
    and (nx90, nx88, NOT_D1) ;
    or (nx92, nx84, nx90) ;
    and (nx94, NOT_A2, NOT_B1) ;
    and (nx96, nx94, NOT_C2) ;
    and (nx98, nx96, NOT_D1) ;
    or (nx100, nx92, nx98) ;
    and (nx102, NOT_A1, NOT_B1) ;
    and (nx104, nx102, NOT_C2) ;
    and (nx106, nx104, NOT_D1) ;
    or (nx108, nx100, nx106) ;
    and (nx110, NOT_A2, NOT_B2) ;
    and (nx112, nx110, NOT_C1) ;
    and (nx114, nx112, NOT_D1) ;
    or (nx116, nx108, nx114) ;
    and (nx118, NOT_A1, NOT_B2) ;
    and (nx120, nx118, NOT_C1) ;
    and (nx122, nx120, NOT_D1) ;
    or (nx124, nx116, nx122) ;
    and (nx126, NOT_A2, NOT_B1) ;
    and (nx128, nx126, NOT_C1) ;
    and (nx130, nx128, NOT_D1) ;
    or (nx132, nx124, nx130) ;
    and (nx134, NOT_A1, NOT_B1) ;
    and (nx136, nx134, NOT_C1) ;
    and (nx138, nx136, NOT_D1) ;
    or (X, nx132, nx138) ;
endmodule


module IV1N0 ( X, A ) ;

    output X ;
    input A ;




    assign X = ~A ;
endmodule

