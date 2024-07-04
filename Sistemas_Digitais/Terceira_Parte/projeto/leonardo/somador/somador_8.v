//
// Verilog description for cell somador, 
// 07/04/24 17:30:42
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module somador ( s, co, a, b, ci, mode ) ;

    output [7:0]s ;
    output co ;
    input [7:0]a ;
    input [7:0]b ;
    input ci ;
    input mode ;

    wire r_7, r_6, r_5, r_4, r_3, r_2, r_1, r_0, a_7__dup_259, a_6__dup_260, 
         a_5__dup_261, a_4__dup_262, a_3__dup_263, a_2__dup_264, a_1__dup_265, 
         a_0__dup_266, b_7__dup_267, b_6__dup_268, b_5__dup_269, b_4__dup_270, 
         b_3__dup_271, b_2__dup_272, b_1__dup_273, b_0__dup_274, cout_dup_291, 
         nx2_dup_0, modgen_add_0_blk_carry_1, modgen_add_0_c_1, 
         modgen_add_0_c_1__dup_37, NOT_b_7, NOT_b_6, NOT_b_5, NOT_b_4, NOT_b_3, 
         NOT_b_2, NOT_b_1, NOT_b_0, modgen_sub_2_blk_carry_1, modgen_sub_2_c_1, 
         modgen_sub_2_c_1__dup_52, PWR, nx2, nx334;



    FA2A0 modgen_add_0_D0_I0_dup_170 (.S1 (s[0]), .S2 (s[1]), .CO (
          modgen_add_0_c_1), .A1 (a_0__dup_266), .A2 (a_1__dup_265), .B1 (
          b_0__dup_274), .B2 (b_1__dup_273), .CI (ci)) ;
    FA2A0 modgen_add_0_D0_I0_dup_171 (.S1 (s[2]), .S2 (s[3]), .CO (
          modgen_add_0_blk_carry_1), .A1 (a_2__dup_264), .A2 (a_3__dup_263), .B1 (
          b_2__dup_272), .B2 (b_3__dup_271), .CI (modgen_add_0_c_1)) ;
    FA2A0 modgen_add_0_D0_I0_dup_172 (.S1 (s[4]), .S2 (s[5]), .CO (
          modgen_add_0_c_1__dup_37), .A1 (a_4__dup_262), .A2 (a_5__dup_261), .B1 (
          b_4__dup_270), .B2 (b_5__dup_269), .CI (modgen_add_0_blk_carry_1)) ;
    FA2A0 modgen_add_0_D0_I0_dup_173 (.S1 (s[6]), .S2 (s[7]), .CO (nx2_dup_0), .A1 (
          a_6__dup_260), .A2 (a_7__dup_259), .B1 (b_6__dup_268), .B2 (
          b_7__dup_267), .CI (modgen_add_0_c_1__dup_37)) ;
    FA2A0 modgen_sub_2_D0_I0 (.S1 (r_0), .S2 (r_1), .CO (modgen_sub_2_c_1), .A1 (
          a[0]), .A2 (a[1]), .B1 (NOT_b_0), .B2 (NOT_b_1), .CI (PWR)) ;
    FA2A0 modgen_sub_2_D0_I0_dup_188 (.S1 (r_2), .S2 (r_3), .CO (
          modgen_sub_2_blk_carry_1), .A1 (a[2]), .A2 (a[3]), .B1 (NOT_b_2), .B2 (
          NOT_b_3), .CI (modgen_sub_2_c_1)) ;
    FA2A0 modgen_sub_2_D0_I0_dup_189 (.S1 (r_4), .S2 (r_5), .CO (
          modgen_sub_2_c_1__dup_52), .A1 (a[4]), .A2 (a[5]), .B1 (NOT_b_4), .B2 (
          NOT_b_5), .CI (modgen_sub_2_blk_carry_1)) ;
    FA2A0 modgen_sub_2_D0_I0_dup_190 (.S1 (r_6), .S2 (r_7), .CO (cout_dup_291), 
          .A1 (a[6]), .A2 (a[7]), .B1 (NOT_b_6), .B2 (NOT_b_7), .CI (
          modgen_sub_2_c_1__dup_52)) ;
    CONZ1 ix298 (.X (PWR)) ;
    XR2T0 ix5 (.X (co), .A1 (nx2_dup_0), .A2 (nx2)) ;
    NR2R0 ix3 (.X (nx2), .A1 (cout_dup_291), .A2 (nx334)) ;
    IV1N1 ix335 (.X (nx334), .A (mode)) ;
    AN2T0 ix25 (.X (b_0__dup_274), .A1 (b[0]), .A2 (nx334)) ;
    AN2T0 ix29 (.X (b_1__dup_273), .A1 (b[1]), .A2 (nx334)) ;
    AN2T0 ix33 (.X (b_2__dup_272), .A1 (b[2]), .A2 (nx334)) ;
    AN2T0 ix37 (.X (b_3__dup_271), .A1 (b[3]), .A2 (nx334)) ;
    AN2T0 ix41 (.X (b_4__dup_270), .A1 (b[4]), .A2 (nx334)) ;
    AN2T0 ix45 (.X (b_5__dup_269), .A1 (b[5]), .A2 (nx334)) ;
    AN2T0 ix49 (.X (b_6__dup_268), .A1 (b[6]), .A2 (nx334)) ;
    AN2T0 ix53 (.X (b_7__dup_267), .A1 (b[7]), .A2 (nx334)) ;
    MX2T0 ix61 (.X (a_0__dup_266), .A (r_0), .B (a[0]), .S (mode)) ;
    MX2T0 ix69 (.X (a_1__dup_265), .A (r_1), .B (a[1]), .S (mode)) ;
    MX2T0 ix77 (.X (a_2__dup_264), .A (r_2), .B (a[2]), .S (mode)) ;
    MX2T0 ix85 (.X (a_3__dup_263), .A (r_3), .B (a[3]), .S (mode)) ;
    MX2T0 ix93 (.X (a_4__dup_262), .A (r_4), .B (a[4]), .S (mode)) ;
    MX2T0 ix101 (.X (a_5__dup_261), .A (r_5), .B (a[5]), .S (mode)) ;
    MX2T0 ix109 (.X (a_6__dup_260), .A (r_6), .B (a[6]), .S (mode)) ;
    MX2T0 ix117 (.X (a_7__dup_259), .A (r_7), .B (a[7]), .S (mode)) ;
    IV1N0 ix353 (.X (NOT_b_0), .A (b[0])) ;
    IV1N0 ix355 (.X (NOT_b_1), .A (b[1])) ;
    IV1N0 ix357 (.X (NOT_b_2), .A (b[2])) ;
    IV1N0 ix359 (.X (NOT_b_3), .A (b[3])) ;
    IV1N0 ix361 (.X (NOT_b_4), .A (b[4])) ;
    IV1N0 ix363 (.X (NOT_b_5), .A (b[5])) ;
    IV1N0 ix365 (.X (NOT_b_6), .A (b[6])) ;
    IV1N0 ix367 (.X (NOT_b_7), .A (b[7])) ;
endmodule


module IV1N0 ( X, A ) ;

    output X ;
    input A ;




    assign X = ~A ;
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


module AN2T0 ( X, A1, A2 ) ;

    output X ;
    input A1 ;
    input A2 ;




    and (X, A1, A2) ;
endmodule


module IV1N1 ( X, A ) ;

    output X ;
    input A ;




    assign X = ~A ;
endmodule


module NR2R0 ( X, A1, A2 ) ;

    output X ;
    input A1 ;
    input A2 ;

    wire NOT_A1, NOT_A2;



    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (X, NOT_A1, NOT_A2) ;
endmodule


module XR2T0 ( X, A1, A2 ) ;

    output X ;
    input A1 ;
    input A2 ;




    xor (X, A1, A2) ;
endmodule


module CONZ1 ( X ) ;

    output X ;




    assign X = 1 ;
endmodule


module FA2A0 ( S1, S2, CO, A1, A2, B1, B2, CI ) ;

    output S1 ;
    output S2 ;
    output CO ;
    input A1 ;
    input A2 ;
    input B1 ;
    input B2 ;
    input CI ;

    wire NOT_B1, nx2, NOT_CI, nx6, NOT_A1, nx10, nx12, nx14, nx16, nx18, nx20, 
         nx22, nx24, nx28, nx30, NOT_B2, nx34, nx36, nx38, nx40, nx42, nx44, 
         nx46, nx48, NOT_A2, nx52, nx54, nx56, nx58, nx60, nx62, nx64, nx66, 
         nx68, nx70, nx72, nx74, nx76, nx78, nx80, nx82, nx84, nx86, nx88, nx90, 
         nx92, nx94, nx96, nx98, nx100, nx102, nx104, nx106, nx108, nx110, nx112, 
         nx114, nx116, nx118, nx120, nx122, nx124, nx126, nx128, nx132, nx134, 
         nx136, nx138, nx140, nx142, nx144, nx146, nx148, nx150, nx152, nx154, 
         nx156, nx158, nx160, nx162, nx164, nx166;



    assign NOT_B1 = ~B1 ;
    and (nx2, A1, NOT_B1) ;
    assign NOT_CI = ~CI ;
    and (nx6, nx2, NOT_CI) ;
    assign NOT_A1 = ~A1 ;
    and (nx10, NOT_A1, B1) ;
    and (nx12, nx10, NOT_CI) ;
    or (nx14, nx6, nx12) ;
    and (nx16, NOT_A1, NOT_B1) ;
    and (nx18, nx16, CI) ;
    or (nx20, nx14, nx18) ;
    and (nx22, A1, B1) ;
    and (nx24, nx22, CI) ;
    or (S1, nx20, nx24) ;
    assign nx28 = ~B1 ;
    and (nx30, A2, nx28) ;
    assign NOT_B2 = ~B2 ;
    and (nx34, nx30, NOT_B2) ;
    assign nx36 = ~CI ;
    and (nx38, nx34, nx36) ;
    assign nx40 = ~A1 ;
    and (nx42, nx40, A2) ;
    and (nx44, nx42, NOT_B2) ;
    and (nx46, nx44, nx36) ;
    or (nx48, nx38, nx46) ;
    assign NOT_A2 = ~A2 ;
    and (nx52, NOT_A2, nx28) ;
    and (nx54, nx52, B2) ;
    and (nx56, nx54, nx36) ;
    or (nx58, nx48, nx56) ;
    and (nx60, nx40, NOT_A2) ;
    and (nx62, nx60, B2) ;
    and (nx64, nx62, nx36) ;
    or (nx66, nx58, nx64) ;
    and (nx68, NOT_A2, B1) ;
    and (nx70, nx68, NOT_B2) ;
    and (nx72, nx70, CI) ;
    or (nx74, nx66, nx72) ;
    and (nx76, A1, NOT_A2) ;
    and (nx78, nx76, NOT_B2) ;
    and (nx80, nx78, CI) ;
    or (nx82, nx74, nx80) ;
    and (nx84, A2, B1) ;
    and (nx86, nx84, B2) ;
    and (nx88, nx86, CI) ;
    or (nx90, nx82, nx88) ;
    and (nx92, A1, A2) ;
    and (nx94, nx92, B2) ;
    and (nx96, nx94, CI) ;
    or (nx98, nx90, nx96) ;
    and (nx100, nx40, A2) ;
    and (nx102, nx100, nx28) ;
    and (nx104, nx102, NOT_B2) ;
    or (nx106, nx98, nx104) ;
    and (nx108, A1, NOT_A2) ;
    and (nx110, nx108, B1) ;
    and (nx112, nx110, NOT_B2) ;
    or (nx114, nx106, nx112) ;
    and (nx116, nx40, NOT_A2) ;
    and (nx118, nx116, nx28) ;
    and (nx120, nx118, B2) ;
    or (nx122, nx114, nx120) ;
    and (nx124, A1, A2) ;
    and (nx126, nx124, B1) ;
    and (nx128, nx126, B2) ;
    or (S2, nx122, nx128) ;
    and (nx132, B1, B2) ;
    and (nx134, nx132, CI) ;
    and (nx136, A1, B2) ;
    and (nx138, nx136, CI) ;
    or (nx140, nx134, nx138) ;
    and (nx142, A2, B1) ;
    and (nx144, nx142, CI) ;
    or (nx146, nx140, nx144) ;
    and (nx148, A1, A2) ;
    and (nx150, nx148, CI) ;
    or (nx152, nx146, nx150) ;
    and (nx154, A1, B1) ;
    and (nx156, nx154, B2) ;
    or (nx158, nx152, nx156) ;
    and (nx160, A1, A2) ;
    and (nx162, nx160, B1) ;
    or (nx164, nx158, nx162) ;
    and (nx166, A2, B2) ;
    or (CO, nx164, nx166) ;
endmodule

