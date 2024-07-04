//
// Verilog description for cell registrador, 
// 07/04/24 17:31:29
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module registrador ( q, clk, en, rstn, d ) ;

    output [7:0]q ;
    input clk ;
    input en ;
    input rstn ;
    input [7:0]d ;

    wire NOT_clk;
    wire [7:0] \$dummy ;




    FD1I0 reg_q_0 (.Q (q[0]), .XQ (\$dummy [0]), .D (d[0]), .CK (NOT_clk), .EN (
          en), .CL (rstn)) ;
    IV1N0 ix196 (.X (NOT_clk), .A (clk)) ;
    FD1I0 reg_q_1 (.Q (q[1]), .XQ (\$dummy [1]), .D (d[1]), .CK (NOT_clk), .EN (
          en), .CL (rstn)) ;
    FD1I0 reg_q_2 (.Q (q[2]), .XQ (\$dummy [2]), .D (d[2]), .CK (NOT_clk), .EN (
          en), .CL (rstn)) ;
    FD1I0 reg_q_3 (.Q (q[3]), .XQ (\$dummy [3]), .D (d[3]), .CK (NOT_clk), .EN (
          en), .CL (rstn)) ;
    FD1I0 reg_q_4 (.Q (q[4]), .XQ (\$dummy [4]), .D (d[4]), .CK (NOT_clk), .EN (
          en), .CL (rstn)) ;
    FD1I0 reg_q_5 (.Q (q[5]), .XQ (\$dummy [5]), .D (d[5]), .CK (NOT_clk), .EN (
          en), .CL (rstn)) ;
    FD1I0 reg_q_6 (.Q (q[6]), .XQ (\$dummy [6]), .D (d[6]), .CK (NOT_clk), .EN (
          en), .CL (rstn)) ;
    FD1I0 reg_q_7 (.Q (q[7]), .XQ (\$dummy [7]), .D (d[7]), .CK (NOT_clk), .EN (
          en), .CL (rstn)) ;
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

