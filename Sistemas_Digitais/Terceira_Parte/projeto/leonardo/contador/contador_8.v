//
// Verilog description for cell contador, 
// 07/04/24 18:49:52
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module contador ( Q, clk, en, clr_n ) ;

    output [7:0]Q ;
    input clk ;
    input en ;
    input clr_n ;

    wire NOT_clk, nx123, nx124, nx125, nx126, nx127, nx128, nx129, NOT__2233;



    FD1I0 ti_reg_q (.Q (Q[0]), .XQ (nx123), .D (nx123), .CK (NOT_clk), .EN (en)
          , .CL (clr_n)) ;
    IV1N0 ix140 (.X (NOT_clk), .A (clk)) ;
    FD1I0 row_1_ti_reg_q (.Q (Q[1]), .XQ (nx124), .D (nx124), .CK (nx123), .EN (
          en), .CL (clr_n)) ;
    FD1I0 row_2_ti_reg_q (.Q (Q[2]), .XQ (nx125), .D (nx125), .CK (nx124), .EN (
          en), .CL (clr_n)) ;
    FD1I0 row_3_ti_reg_q (.Q (Q[3]), .XQ (nx126), .D (nx126), .CK (nx125), .EN (
          en), .CL (clr_n)) ;
    FD1I0 row_4_ti_reg_q (.Q (Q[4]), .XQ (nx127), .D (nx127), .CK (nx126), .EN (
          en), .CL (clr_n)) ;
    FD1I0 row_5_ti_reg_q (.Q (Q[5]), .XQ (nx128), .D (nx128), .CK (nx127), .EN (
          en), .CL (clr_n)) ;
    FD1I0 row_6_ti_reg_q (.Q (Q[6]), .XQ (nx129), .D (nx129), .CK (nx128), .EN (
          en), .CL (clr_n)) ;
    FD1I0 row_7_ti_reg_q (.Q (Q[7]), .XQ (NOT__2233), .D (NOT__2233), .CK (nx129
          ), .EN (en), .CL (clr_n)) ;
endmodule


module IV1N0 ( X, A ) ;

    output X ;
    input A ;




    assign X = ~A ;
endmodule


module FD1I0 ( Q, XQ, D, CK, EN, CL ) ;

    output Q ;
    output XQ ;
    input D ;
    input CK ;
    input EN ;
    input CL ;

    wire NOT_CL, nx4;



    assign NOT_CL = ~CL ;
    DFFERS ix3 (.set (nx4), .reset (NOT_CL), .in (D), .clk (CK), .ce (EN), .out (
           Q)) ;
    assign nx4 = 0 ;
    assign XQ = ~Q ;
endmodule


module DFFERS ( set, reset, in, clk, ce, out ) ;

    input set ;
    input reset ;
    input in ;
    input clk ;
    input ce ;
    output out ;
reg out; 
always @ (posedge set or posedge reset or posedge clk)
begin
    if (set) out = 1;
    else if (reset) out = 0;
    else begin
      if (ce)     out = in;
    end
end

endmodule

