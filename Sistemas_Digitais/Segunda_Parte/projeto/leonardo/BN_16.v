//
// Verilog description for cell ordenador, 
// 06/12/24 10:25:31
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module ordenador ( y8, y7, y6, y5, y4, y3, y2, y1, x8, x7, x6, x5, x4, x3, x2, 
                   x1 ) ;

    output [15:0]y8 ;
    output [15:0]y7 ;
    output [15:0]y6 ;
    output [15:0]y5 ;
    output [15:0]y4 ;
    output [15:0]y3 ;
    output [15:0]y2 ;
    output [15:0]y1 ;
    input [15:0]x8 ;
    input [15:0]x7 ;
    input [15:0]x6 ;
    input [15:0]x5 ;
    input [15:0]x4 ;
    input [15:0]x3 ;
    input [15:0]x2 ;
    input [15:0]x1 ;

    wire linha7_7__15, linha7_7__14, linha7_7__13, linha7_7__12, linha7_7__11, 
         linha7_7__10, linha7_7__9, linha7_7__8, linha7_7__7, linha7_7__6, 
         linha7_7__5, linha7_7__4, linha7_7__3, linha7_7__2, linha7_7__1, 
         linha7_7__0, linha7_6__15, linha7_6__14, linha7_6__13, linha7_6__12, 
         linha7_6__11, linha7_6__10, linha7_6__9, linha7_6__8, linha7_6__7, 
         linha7_6__6, linha7_6__5, linha7_6__4, linha7_6__3, linha7_6__2, 
         linha7_6__1, linha7_6__0, linha7_5__15, linha7_5__14, linha7_5__13, 
         linha7_5__12, linha7_5__11, linha7_5__10, linha7_5__9, linha7_5__8, 
         linha7_5__7, linha7_5__6, linha7_5__5, linha7_5__4, linha7_5__3, 
         linha7_5__2, linha7_5__1, linha7_5__0, linha7_4__15, linha7_4__14, 
         linha7_4__13, linha7_4__12, linha7_4__11, linha7_4__10, linha7_4__9, 
         linha7_4__8, linha7_4__7, linha7_4__6, linha7_4__5, linha7_4__4, 
         linha7_4__3, linha7_4__2, linha7_4__1, linha7_4__0, linha7_3__15, 
         linha7_3__14, linha7_3__13, linha7_3__12, linha7_3__11, linha7_3__10, 
         linha7_3__9, linha7_3__8, linha7_3__7, linha7_3__6, linha7_3__5, 
         linha7_3__4, linha7_3__3, linha7_3__2, linha7_3__1, linha7_3__0, 
         linha7_2__15, linha7_2__14, linha7_2__13, linha7_2__12, linha7_2__11, 
         linha7_2__10, linha7_2__9, linha7_2__8, linha7_2__7, linha7_2__6, 
         linha7_2__5, linha7_2__4, linha7_2__3, linha7_2__2, linha7_2__1, 
         linha7_2__0, linha7_1__15, linha7_1__14, linha7_1__13, linha7_1__12, 
         linha7_1__11, linha7_1__10, linha7_1__9, linha7_1__8, linha7_1__7, 
         linha7_1__6, linha7_1__5, linha7_1__4, linha7_1__3, linha7_1__2, 
         linha7_1__1, linha7_1__0, linha6_7__15, linha6_7__14, linha6_7__13, 
         linha6_7__12, linha6_7__11, linha6_7__10, linha6_7__9, linha6_7__8, 
         linha6_7__7, linha6_7__6, linha6_7__5, linha6_7__4, linha6_7__3, 
         linha6_7__2, linha6_7__1, linha6_7__0, linha6_6__15, linha6_6__14, 
         linha6_6__13, linha6_6__12, linha6_6__11, linha6_6__10, linha6_6__9, 
         linha6_6__8, linha6_6__7, linha6_6__6, linha6_6__5, linha6_6__4, 
         linha6_6__3, linha6_6__2, linha6_6__1, linha6_6__0, linha6_5__15, 
         linha6_5__14, linha6_5__13, linha6_5__12, linha6_5__11, linha6_5__10, 
         linha6_5__9, linha6_5__8, linha6_5__7, linha6_5__6, linha6_5__5, 
         linha6_5__4, linha6_5__3, linha6_5__2, linha6_5__1, linha6_5__0, 
         linha6_4__15, linha6_4__14, linha6_4__13, linha6_4__12, linha6_4__11, 
         linha6_4__10, linha6_4__9, linha6_4__8, linha6_4__7, linha6_4__6, 
         linha6_4__5, linha6_4__4, linha6_4__3, linha6_4__2, linha6_4__1, 
         linha6_4__0, linha6_3__15, linha6_3__14, linha6_3__13, linha6_3__12, 
         linha6_3__11, linha6_3__10, linha6_3__9, linha6_3__8, linha6_3__7, 
         linha6_3__6, linha6_3__5, linha6_3__4, linha6_3__3, linha6_3__2, 
         linha6_3__1, linha6_3__0, linha6_2__15, linha6_2__14, linha6_2__13, 
         linha6_2__12, linha6_2__11, linha6_2__10, linha6_2__9, linha6_2__8, 
         linha6_2__7, linha6_2__6, linha6_2__5, linha6_2__4, linha6_2__3, 
         linha6_2__2, linha6_2__1, linha6_2__0, linha6_1__15, linha6_1__14, 
         linha6_1__13, linha6_1__12, linha6_1__11, linha6_1__10, linha6_1__9, 
         linha6_1__8, linha6_1__7, linha6_1__6, linha6_1__5, linha6_1__4, 
         linha6_1__3, linha6_1__2, linha6_1__1, linha6_1__0, linha5_7__15, 
         linha5_7__14, linha5_7__13, linha5_7__12, linha5_7__11, linha5_7__10, 
         linha5_7__9, linha5_7__8, linha5_7__7, linha5_7__6, linha5_7__5, 
         linha5_7__4, linha5_7__3, linha5_7__2, linha5_7__1, linha5_7__0, 
         linha5_6__15, linha5_6__14, linha5_6__13, linha5_6__12, linha5_6__11, 
         linha5_6__10, linha5_6__9, linha5_6__8, linha5_6__7, linha5_6__6, 
         linha5_6__5, linha5_6__4, linha5_6__3, linha5_6__2, linha5_6__1, 
         linha5_6__0, linha5_5__15, linha5_5__14, linha5_5__13, linha5_5__12, 
         linha5_5__11, linha5_5__10, linha5_5__9, linha5_5__8, linha5_5__7, 
         linha5_5__6, linha5_5__5, linha5_5__4, linha5_5__3, linha5_5__2, 
         linha5_5__1, linha5_5__0, linha5_4__15, linha5_4__14, linha5_4__13, 
         linha5_4__12, linha5_4__11, linha5_4__10, linha5_4__9, linha5_4__8, 
         linha5_4__7, linha5_4__6, linha5_4__5, linha5_4__4, linha5_4__3, 
         linha5_4__2, linha5_4__1, linha5_4__0, linha5_3__15, linha5_3__14, 
         linha5_3__13, linha5_3__12, linha5_3__11, linha5_3__10, linha5_3__9, 
         linha5_3__8, linha5_3__7, linha5_3__6, linha5_3__5, linha5_3__4, 
         linha5_3__3, linha5_3__2, linha5_3__1, linha5_3__0, linha5_2__15, 
         linha5_2__14, linha5_2__13, linha5_2__12, linha5_2__11, linha5_2__10, 
         linha5_2__9, linha5_2__8, linha5_2__7, linha5_2__6, linha5_2__5, 
         linha5_2__4, linha5_2__3, linha5_2__2, linha5_2__1, linha5_2__0, 
         linha5_1__15, linha5_1__14, linha5_1__13, linha5_1__12, linha5_1__11, 
         linha5_1__10, linha5_1__9, linha5_1__8, linha5_1__7, linha5_1__6, 
         linha5_1__5, linha5_1__4, linha5_1__3, linha5_1__2, linha5_1__1, 
         linha5_1__0, linha4_7__15, linha4_7__14, linha4_7__13, linha4_7__12, 
         linha4_7__11, linha4_7__10, linha4_7__9, linha4_7__8, linha4_7__7, 
         linha4_7__6, linha4_7__5, linha4_7__4, linha4_7__3, linha4_7__2, 
         linha4_7__1, linha4_7__0, linha4_6__15, linha4_6__14, linha4_6__13, 
         linha4_6__12, linha4_6__11, linha4_6__10, linha4_6__9, linha4_6__8, 
         linha4_6__7, linha4_6__6, linha4_6__5, linha4_6__4, linha4_6__3, 
         linha4_6__2, linha4_6__1, linha4_6__0, linha4_5__15, linha4_5__14, 
         linha4_5__13, linha4_5__12, linha4_5__11, linha4_5__10, linha4_5__9, 
         linha4_5__8, linha4_5__7, linha4_5__6, linha4_5__5, linha4_5__4, 
         linha4_5__3, linha4_5__2, linha4_5__1, linha4_5__0, linha4_4__15, 
         linha4_4__14, linha4_4__13, linha4_4__12, linha4_4__11, linha4_4__10, 
         linha4_4__9, linha4_4__8, linha4_4__7, linha4_4__6, linha4_4__5, 
         linha4_4__4, linha4_4__3, linha4_4__2, linha4_4__1, linha4_4__0, 
         linha4_3__15, linha4_3__14, linha4_3__13, linha4_3__12, linha4_3__11, 
         linha4_3__10, linha4_3__9, linha4_3__8, linha4_3__7, linha4_3__6, 
         linha4_3__5, linha4_3__4, linha4_3__3, linha4_3__2, linha4_3__1, 
         linha4_3__0, linha4_2__15, linha4_2__14, linha4_2__13, linha4_2__12, 
         linha4_2__11, linha4_2__10, linha4_2__9, linha4_2__8, linha4_2__7, 
         linha4_2__6, linha4_2__5, linha4_2__4, linha4_2__3, linha4_2__2, 
         linha4_2__1, linha4_2__0, linha4_1__15, linha4_1__14, linha4_1__13, 
         linha4_1__12, linha4_1__11, linha4_1__10, linha4_1__9, linha4_1__8, 
         linha4_1__7, linha4_1__6, linha4_1__5, linha4_1__4, linha4_1__3, 
         linha4_1__2, linha4_1__1, linha4_1__0, linha3_7__15, linha3_7__14, 
         linha3_7__13, linha3_7__12, linha3_7__11, linha3_7__10, linha3_7__9, 
         linha3_7__8, linha3_7__7, linha3_7__6, linha3_7__5, linha3_7__4, 
         linha3_7__3, linha3_7__2, linha3_7__1, linha3_7__0, linha3_6__15, 
         linha3_6__14, linha3_6__13, linha3_6__12, linha3_6__11, linha3_6__10, 
         linha3_6__9, linha3_6__8, linha3_6__7, linha3_6__6, linha3_6__5, 
         linha3_6__4, linha3_6__3, linha3_6__2, linha3_6__1, linha3_6__0, 
         linha3_5__15, linha3_5__14, linha3_5__13, linha3_5__12, linha3_5__11, 
         linha3_5__10, linha3_5__9, linha3_5__8, linha3_5__7, linha3_5__6, 
         linha3_5__5, linha3_5__4, linha3_5__3, linha3_5__2, linha3_5__1, 
         linha3_5__0, linha3_4__15, linha3_4__14, linha3_4__13, linha3_4__12, 
         linha3_4__11, linha3_4__10, linha3_4__9, linha3_4__8, linha3_4__7, 
         linha3_4__6, linha3_4__5, linha3_4__4, linha3_4__3, linha3_4__2, 
         linha3_4__1, linha3_4__0, linha3_3__15, linha3_3__14, linha3_3__13, 
         linha3_3__12, linha3_3__11, linha3_3__10, linha3_3__9, linha3_3__8, 
         linha3_3__7, linha3_3__6, linha3_3__5, linha3_3__4, linha3_3__3, 
         linha3_3__2, linha3_3__1, linha3_3__0, linha3_2__15, linha3_2__14, 
         linha3_2__13, linha3_2__12, linha3_2__11, linha3_2__10, linha3_2__9, 
         linha3_2__8, linha3_2__7, linha3_2__6, linha3_2__5, linha3_2__4, 
         linha3_2__3, linha3_2__2, linha3_2__1, linha3_2__0, linha3_1__15, 
         linha3_1__14, linha3_1__13, linha3_1__12, linha3_1__11, linha3_1__10, 
         linha3_1__9, linha3_1__8, linha3_1__7, linha3_1__6, linha3_1__5, 
         linha3_1__4, linha3_1__3, linha3_1__2, linha3_1__1, linha3_1__0, 
         linha2_7__15, linha2_7__14, linha2_7__13, linha2_7__12, linha2_7__11, 
         linha2_7__10, linha2_7__9, linha2_7__8, linha2_7__7, linha2_7__6, 
         linha2_7__5, linha2_7__4, linha2_7__3, linha2_7__2, linha2_7__1, 
         linha2_7__0, linha2_6__15, linha2_6__14, linha2_6__13, linha2_6__12, 
         linha2_6__11, linha2_6__10, linha2_6__9, linha2_6__8, linha2_6__7, 
         linha2_6__6, linha2_6__5, linha2_6__4, linha2_6__3, linha2_6__2, 
         linha2_6__1, linha2_6__0, linha2_5__15, linha2_5__14, linha2_5__13, 
         linha2_5__12, linha2_5__11, linha2_5__10, linha2_5__9, linha2_5__8, 
         linha2_5__7, linha2_5__6, linha2_5__5, linha2_5__4, linha2_5__3, 
         linha2_5__2, linha2_5__1, linha2_5__0, linha2_4__15, linha2_4__14, 
         linha2_4__13, linha2_4__12, linha2_4__11, linha2_4__10, linha2_4__9, 
         linha2_4__8, linha2_4__7, linha2_4__6, linha2_4__5, linha2_4__4, 
         linha2_4__3, linha2_4__2, linha2_4__1, linha2_4__0, linha2_3__15, 
         linha2_3__14, linha2_3__13, linha2_3__12, linha2_3__11, linha2_3__10, 
         linha2_3__9, linha2_3__8, linha2_3__7, linha2_3__6, linha2_3__5, 
         linha2_3__4, linha2_3__3, linha2_3__2, linha2_3__1, linha2_3__0, 
         linha2_2__15, linha2_2__14, linha2_2__13, linha2_2__12, linha2_2__11, 
         linha2_2__10, linha2_2__9, linha2_2__8, linha2_2__7, linha2_2__6, 
         linha2_2__5, linha2_2__4, linha2_2__3, linha2_2__2, linha2_2__1, 
         linha2_2__0, linha2_1__15, linha2_1__14, linha2_1__13, linha2_1__12, 
         linha2_1__11, linha2_1__10, linha2_1__9, linha2_1__8, linha2_1__7, 
         linha2_1__6, linha2_1__5, linha2_1__4, linha2_1__3, linha2_1__2, 
         linha2_1__1, linha2_1__0, linha8_3__15, linha8_3__14, linha8_3__13, 
         linha8_3__12, linha8_3__11, linha8_3__10, linha8_3__9, linha8_3__8, 
         linha8_3__7, linha8_3__6, linha8_3__5, linha8_3__4, linha8_3__3, 
         linha8_3__2, linha8_3__1, linha8_3__0, linha8_2__15, linha8_2__14, 
         linha8_2__13, linha8_2__12, linha8_2__11, linha8_2__10, linha8_2__9, 
         linha8_2__8, linha8_2__7, linha8_2__6, linha8_2__5, linha8_2__4, 
         linha8_2__3, linha8_2__2, linha8_2__1, linha8_2__0, linha8_1__15, 
         linha8_1__14, linha8_1__13, linha8_1__12, linha8_1__11, linha8_1__10, 
         linha8_1__9, linha8_1__8, linha8_1__7, linha8_1__6, linha8_1__5, 
         linha8_1__4, linha8_1__3, linha8_1__2, linha8_1__1, linha8_1__0, 
         linha1_3__15, linha1_3__14, linha1_3__13, linha1_3__12, linha1_3__11, 
         linha1_3__10, linha1_3__9, linha1_3__8, linha1_3__7, linha1_3__6, 
         linha1_3__5, linha1_3__4, linha1_3__3, linha1_3__2, linha1_3__1, 
         linha1_3__0, linha1_2__15, linha1_2__14, linha1_2__13, linha1_2__12, 
         linha1_2__11, linha1_2__10, linha1_2__9, linha1_2__8, linha1_2__7, 
         linha1_2__6, linha1_2__5, linha1_2__4, linha1_2__3, linha1_2__2, 
         linha1_2__1, linha1_2__0, linha1_1__15, linha1_1__14, linha1_1__13, 
         linha1_1__12, linha1_1__11, linha1_1__10, linha1_1__9, linha1_1__8, 
         linha1_1__7, linha1_1__6, linha1_1__5, linha1_1__4, linha1_1__3, 
         linha1_1__2, linha1_1__1, linha1_1__0;



    BN_16 row_0_rowp_bni1 (.max ({linha1_1__15,linha1_1__14,linha1_1__13,
          linha1_1__12,linha1_1__11,linha1_1__10,linha1_1__9,linha1_1__8,
          linha1_1__7,linha1_1__6,linha1_1__5,linha1_1__4,linha1_1__3,
          linha1_1__2,linha1_1__1,linha1_1__0}), .min ({linha2_1__15,
          linha2_1__14,linha2_1__13,linha2_1__12,linha2_1__11,linha2_1__10,
          linha2_1__9,linha2_1__8,linha2_1__7,linha2_1__6,linha2_1__5,
          linha2_1__4,linha2_1__3,linha2_1__2,linha2_1__1,linha2_1__0}), .a ({
          x1[15],x1[14],x1[13],x1[12],x1[11],x1[10],x1[9],x1[8],x1[7],x1[6],
          x1[5],x1[4],x1[3],x1[2],x1[1],x1[0]}), .b ({x2[15],x2[14],x2[13],
          x2[12],x2[11],x2[10],x2[9],x2[8],x2[7],x2[6],x2[5],x2[4],x2[3],x2[2],
          x2[1],x2[0]})) ;
    BN_16 row_0_rowp_bni2 (.max ({linha3_1__15,linha3_1__14,linha3_1__13,
          linha3_1__12,linha3_1__11,linha3_1__10,linha3_1__9,linha3_1__8,
          linha3_1__7,linha3_1__6,linha3_1__5,linha3_1__4,linha3_1__3,
          linha3_1__2,linha3_1__1,linha3_1__0}), .min ({linha4_1__15,
          linha4_1__14,linha4_1__13,linha4_1__12,linha4_1__11,linha4_1__10,
          linha4_1__9,linha4_1__8,linha4_1__7,linha4_1__6,linha4_1__5,
          linha4_1__4,linha4_1__3,linha4_1__2,linha4_1__1,linha4_1__0}), .a ({
          x3[15],x3[14],x3[13],x3[12],x3[11],x3[10],x3[9],x3[8],x3[7],x3[6],
          x3[5],x3[4],x3[3],x3[2],x3[1],x3[0]}), .b ({x4[15],x4[14],x4[13],
          x4[12],x4[11],x4[10],x4[9],x4[8],x4[7],x4[6],x4[5],x4[4],x4[3],x4[2],
          x4[1],x4[0]})) ;
    BN_16 row_0_rowp_bni3 (.max ({linha5_1__15,linha5_1__14,linha5_1__13,
          linha5_1__12,linha5_1__11,linha5_1__10,linha5_1__9,linha5_1__8,
          linha5_1__7,linha5_1__6,linha5_1__5,linha5_1__4,linha5_1__3,
          linha5_1__2,linha5_1__1,linha5_1__0}), .min ({linha6_1__15,
          linha6_1__14,linha6_1__13,linha6_1__12,linha6_1__11,linha6_1__10,
          linha6_1__9,linha6_1__8,linha6_1__7,linha6_1__6,linha6_1__5,
          linha6_1__4,linha6_1__3,linha6_1__2,linha6_1__1,linha6_1__0}), .a ({
          x5[15],x5[14],x5[13],x5[12],x5[11],x5[10],x5[9],x5[8],x5[7],x5[6],
          x5[5],x5[4],x5[3],x5[2],x5[1],x5[0]}), .b ({x6[15],x6[14],x6[13],
          x6[12],x6[11],x6[10],x6[9],x6[8],x6[7],x6[6],x6[5],x6[4],x6[3],x6[2],
          x6[1],x6[0]})) ;
    BN_16 row_0_rowp_bni4 (.max ({linha7_1__15,linha7_1__14,linha7_1__13,
          linha7_1__12,linha7_1__11,linha7_1__10,linha7_1__9,linha7_1__8,
          linha7_1__7,linha7_1__6,linha7_1__5,linha7_1__4,linha7_1__3,
          linha7_1__2,linha7_1__1,linha7_1__0}), .min ({linha8_1__15,
          linha8_1__14,linha8_1__13,linha8_1__12,linha8_1__11,linha8_1__10,
          linha8_1__9,linha8_1__8,linha8_1__7,linha8_1__6,linha8_1__5,
          linha8_1__4,linha8_1__3,linha8_1__2,linha8_1__1,linha8_1__0}), .a ({
          x7[15],x7[14],x7[13],x7[12],x7[11],x7[10],x7[9],x7[8],x7[7],x7[6],
          x7[5],x7[4],x7[3],x7[2],x7[1],x7[0]}), .b ({x8[15],x8[14],x8[13],
          x8[12],x8[11],x8[10],x8[9],x8[8],x8[7],x8[6],x8[5],x8[4],x8[3],x8[2],
          x8[1],x8[0]})) ;
    BN_16 row_1_rowi_bni1 (.max ({linha2_2__15,linha2_2__14,linha2_2__13,
          linha2_2__12,linha2_2__11,linha2_2__10,linha2_2__9,linha2_2__8,
          linha2_2__7,linha2_2__6,linha2_2__5,linha2_2__4,linha2_2__3,
          linha2_2__2,linha2_2__1,linha2_2__0}), .min ({linha3_2__15,
          linha3_2__14,linha3_2__13,linha3_2__12,linha3_2__11,linha3_2__10,
          linha3_2__9,linha3_2__8,linha3_2__7,linha3_2__6,linha3_2__5,
          linha3_2__4,linha3_2__3,linha3_2__2,linha3_2__1,linha3_2__0}), .a ({
          linha2_1__15,linha2_1__14,linha2_1__13,linha2_1__12,linha2_1__11,
          linha2_1__10,linha2_1__9,linha2_1__8,linha2_1__7,linha2_1__6,
          linha2_1__5,linha2_1__4,linha2_1__3,linha2_1__2,linha2_1__1,
          linha2_1__0}), .b ({linha3_1__15,linha3_1__14,linha3_1__13,
          linha3_1__12,linha3_1__11,linha3_1__10,linha3_1__9,linha3_1__8,
          linha3_1__7,linha3_1__6,linha3_1__5,linha3_1__4,linha3_1__3,
          linha3_1__2,linha3_1__1,linha3_1__0})) ;
    BN_16 row_1_rowi_bni2 (.max ({linha4_2__15,linha4_2__14,linha4_2__13,
          linha4_2__12,linha4_2__11,linha4_2__10,linha4_2__9,linha4_2__8,
          linha4_2__7,linha4_2__6,linha4_2__5,linha4_2__4,linha4_2__3,
          linha4_2__2,linha4_2__1,linha4_2__0}), .min ({linha5_2__15,
          linha5_2__14,linha5_2__13,linha5_2__12,linha5_2__11,linha5_2__10,
          linha5_2__9,linha5_2__8,linha5_2__7,linha5_2__6,linha5_2__5,
          linha5_2__4,linha5_2__3,linha5_2__2,linha5_2__1,linha5_2__0}), .a ({
          linha4_1__15,linha4_1__14,linha4_1__13,linha4_1__12,linha4_1__11,
          linha4_1__10,linha4_1__9,linha4_1__8,linha4_1__7,linha4_1__6,
          linha4_1__5,linha4_1__4,linha4_1__3,linha4_1__2,linha4_1__1,
          linha4_1__0}), .b ({linha5_1__15,linha5_1__14,linha5_1__13,
          linha5_1__12,linha5_1__11,linha5_1__10,linha5_1__9,linha5_1__8,
          linha5_1__7,linha5_1__6,linha5_1__5,linha5_1__4,linha5_1__3,
          linha5_1__2,linha5_1__1,linha5_1__0})) ;
    BN_16 row_1_rowi_bni3 (.max ({linha6_2__15,linha6_2__14,linha6_2__13,
          linha6_2__12,linha6_2__11,linha6_2__10,linha6_2__9,linha6_2__8,
          linha6_2__7,linha6_2__6,linha6_2__5,linha6_2__4,linha6_2__3,
          linha6_2__2,linha6_2__1,linha6_2__0}), .min ({linha7_2__15,
          linha7_2__14,linha7_2__13,linha7_2__12,linha7_2__11,linha7_2__10,
          linha7_2__9,linha7_2__8,linha7_2__7,linha7_2__6,linha7_2__5,
          linha7_2__4,linha7_2__3,linha7_2__2,linha7_2__1,linha7_2__0}), .a ({
          linha6_1__15,linha6_1__14,linha6_1__13,linha6_1__12,linha6_1__11,
          linha6_1__10,linha6_1__9,linha6_1__8,linha6_1__7,linha6_1__6,
          linha6_1__5,linha6_1__4,linha6_1__3,linha6_1__2,linha6_1__1,
          linha6_1__0}), .b ({linha7_1__15,linha7_1__14,linha7_1__13,
          linha7_1__12,linha7_1__11,linha7_1__10,linha7_1__9,linha7_1__8,
          linha7_1__7,linha7_1__6,linha7_1__5,linha7_1__4,linha7_1__3,
          linha7_1__2,linha7_1__1,linha7_1__0})) ;
    BN_16 row_2_rowp_bni1 (.max ({linha1_2__15,linha1_2__14,linha1_2__13,
          linha1_2__12,linha1_2__11,linha1_2__10,linha1_2__9,linha1_2__8,
          linha1_2__7,linha1_2__6,linha1_2__5,linha1_2__4,linha1_2__3,
          linha1_2__2,linha1_2__1,linha1_2__0}), .min ({linha2_3__15,
          linha2_3__14,linha2_3__13,linha2_3__12,linha2_3__11,linha2_3__10,
          linha2_3__9,linha2_3__8,linha2_3__7,linha2_3__6,linha2_3__5,
          linha2_3__4,linha2_3__3,linha2_3__2,linha2_3__1,linha2_3__0}), .a ({
          linha1_1__15,linha1_1__14,linha1_1__13,linha1_1__12,linha1_1__11,
          linha1_1__10,linha1_1__9,linha1_1__8,linha1_1__7,linha1_1__6,
          linha1_1__5,linha1_1__4,linha1_1__3,linha1_1__2,linha1_1__1,
          linha1_1__0}), .b ({linha2_2__15,linha2_2__14,linha2_2__13,
          linha2_2__12,linha2_2__11,linha2_2__10,linha2_2__9,linha2_2__8,
          linha2_2__7,linha2_2__6,linha2_2__5,linha2_2__4,linha2_2__3,
          linha2_2__2,linha2_2__1,linha2_2__0})) ;
    BN_16 row_2_rowp_bni2 (.max ({linha3_3__15,linha3_3__14,linha3_3__13,
          linha3_3__12,linha3_3__11,linha3_3__10,linha3_3__9,linha3_3__8,
          linha3_3__7,linha3_3__6,linha3_3__5,linha3_3__4,linha3_3__3,
          linha3_3__2,linha3_3__1,linha3_3__0}), .min ({linha4_3__15,
          linha4_3__14,linha4_3__13,linha4_3__12,linha4_3__11,linha4_3__10,
          linha4_3__9,linha4_3__8,linha4_3__7,linha4_3__6,linha4_3__5,
          linha4_3__4,linha4_3__3,linha4_3__2,linha4_3__1,linha4_3__0}), .a ({
          linha3_2__15,linha3_2__14,linha3_2__13,linha3_2__12,linha3_2__11,
          linha3_2__10,linha3_2__9,linha3_2__8,linha3_2__7,linha3_2__6,
          linha3_2__5,linha3_2__4,linha3_2__3,linha3_2__2,linha3_2__1,
          linha3_2__0}), .b ({linha4_2__15,linha4_2__14,linha4_2__13,
          linha4_2__12,linha4_2__11,linha4_2__10,linha4_2__9,linha4_2__8,
          linha4_2__7,linha4_2__6,linha4_2__5,linha4_2__4,linha4_2__3,
          linha4_2__2,linha4_2__1,linha4_2__0})) ;
    BN_16 row_2_rowp_bni3 (.max ({linha5_3__15,linha5_3__14,linha5_3__13,
          linha5_3__12,linha5_3__11,linha5_3__10,linha5_3__9,linha5_3__8,
          linha5_3__7,linha5_3__6,linha5_3__5,linha5_3__4,linha5_3__3,
          linha5_3__2,linha5_3__1,linha5_3__0}), .min ({linha6_3__15,
          linha6_3__14,linha6_3__13,linha6_3__12,linha6_3__11,linha6_3__10,
          linha6_3__9,linha6_3__8,linha6_3__7,linha6_3__6,linha6_3__5,
          linha6_3__4,linha6_3__3,linha6_3__2,linha6_3__1,linha6_3__0}), .a ({
          linha5_2__15,linha5_2__14,linha5_2__13,linha5_2__12,linha5_2__11,
          linha5_2__10,linha5_2__9,linha5_2__8,linha5_2__7,linha5_2__6,
          linha5_2__5,linha5_2__4,linha5_2__3,linha5_2__2,linha5_2__1,
          linha5_2__0}), .b ({linha6_2__15,linha6_2__14,linha6_2__13,
          linha6_2__12,linha6_2__11,linha6_2__10,linha6_2__9,linha6_2__8,
          linha6_2__7,linha6_2__6,linha6_2__5,linha6_2__4,linha6_2__3,
          linha6_2__2,linha6_2__1,linha6_2__0})) ;
    BN_16 row_2_rowp_bni4 (.max ({linha7_3__15,linha7_3__14,linha7_3__13,
          linha7_3__12,linha7_3__11,linha7_3__10,linha7_3__9,linha7_3__8,
          linha7_3__7,linha7_3__6,linha7_3__5,linha7_3__4,linha7_3__3,
          linha7_3__2,linha7_3__1,linha7_3__0}), .min ({linha8_2__15,
          linha8_2__14,linha8_2__13,linha8_2__12,linha8_2__11,linha8_2__10,
          linha8_2__9,linha8_2__8,linha8_2__7,linha8_2__6,linha8_2__5,
          linha8_2__4,linha8_2__3,linha8_2__2,linha8_2__1,linha8_2__0}), .a ({
          linha7_2__15,linha7_2__14,linha7_2__13,linha7_2__12,linha7_2__11,
          linha7_2__10,linha7_2__9,linha7_2__8,linha7_2__7,linha7_2__6,
          linha7_2__5,linha7_2__4,linha7_2__3,linha7_2__2,linha7_2__1,
          linha7_2__0}), .b ({linha8_1__15,linha8_1__14,linha8_1__13,
          linha8_1__12,linha8_1__11,linha8_1__10,linha8_1__9,linha8_1__8,
          linha8_1__7,linha8_1__6,linha8_1__5,linha8_1__4,linha8_1__3,
          linha8_1__2,linha8_1__1,linha8_1__0})) ;
    BN_16 row_3_rowi_bni1 (.max ({linha2_4__15,linha2_4__14,linha2_4__13,
          linha2_4__12,linha2_4__11,linha2_4__10,linha2_4__9,linha2_4__8,
          linha2_4__7,linha2_4__6,linha2_4__5,linha2_4__4,linha2_4__3,
          linha2_4__2,linha2_4__1,linha2_4__0}), .min ({linha3_4__15,
          linha3_4__14,linha3_4__13,linha3_4__12,linha3_4__11,linha3_4__10,
          linha3_4__9,linha3_4__8,linha3_4__7,linha3_4__6,linha3_4__5,
          linha3_4__4,linha3_4__3,linha3_4__2,linha3_4__1,linha3_4__0}), .a ({
          linha2_3__15,linha2_3__14,linha2_3__13,linha2_3__12,linha2_3__11,
          linha2_3__10,linha2_3__9,linha2_3__8,linha2_3__7,linha2_3__6,
          linha2_3__5,linha2_3__4,linha2_3__3,linha2_3__2,linha2_3__1,
          linha2_3__0}), .b ({linha3_3__15,linha3_3__14,linha3_3__13,
          linha3_3__12,linha3_3__11,linha3_3__10,linha3_3__9,linha3_3__8,
          linha3_3__7,linha3_3__6,linha3_3__5,linha3_3__4,linha3_3__3,
          linha3_3__2,linha3_3__1,linha3_3__0})) ;
    BN_16 row_3_rowi_bni2 (.max ({linha4_4__15,linha4_4__14,linha4_4__13,
          linha4_4__12,linha4_4__11,linha4_4__10,linha4_4__9,linha4_4__8,
          linha4_4__7,linha4_4__6,linha4_4__5,linha4_4__4,linha4_4__3,
          linha4_4__2,linha4_4__1,linha4_4__0}), .min ({linha5_4__15,
          linha5_4__14,linha5_4__13,linha5_4__12,linha5_4__11,linha5_4__10,
          linha5_4__9,linha5_4__8,linha5_4__7,linha5_4__6,linha5_4__5,
          linha5_4__4,linha5_4__3,linha5_4__2,linha5_4__1,linha5_4__0}), .a ({
          linha4_3__15,linha4_3__14,linha4_3__13,linha4_3__12,linha4_3__11,
          linha4_3__10,linha4_3__9,linha4_3__8,linha4_3__7,linha4_3__6,
          linha4_3__5,linha4_3__4,linha4_3__3,linha4_3__2,linha4_3__1,
          linha4_3__0}), .b ({linha5_3__15,linha5_3__14,linha5_3__13,
          linha5_3__12,linha5_3__11,linha5_3__10,linha5_3__9,linha5_3__8,
          linha5_3__7,linha5_3__6,linha5_3__5,linha5_3__4,linha5_3__3,
          linha5_3__2,linha5_3__1,linha5_3__0})) ;
    BN_16 row_3_rowi_bni3 (.max ({linha6_4__15,linha6_4__14,linha6_4__13,
          linha6_4__12,linha6_4__11,linha6_4__10,linha6_4__9,linha6_4__8,
          linha6_4__7,linha6_4__6,linha6_4__5,linha6_4__4,linha6_4__3,
          linha6_4__2,linha6_4__1,linha6_4__0}), .min ({linha7_4__15,
          linha7_4__14,linha7_4__13,linha7_4__12,linha7_4__11,linha7_4__10,
          linha7_4__9,linha7_4__8,linha7_4__7,linha7_4__6,linha7_4__5,
          linha7_4__4,linha7_4__3,linha7_4__2,linha7_4__1,linha7_4__0}), .a ({
          linha6_3__15,linha6_3__14,linha6_3__13,linha6_3__12,linha6_3__11,
          linha6_3__10,linha6_3__9,linha6_3__8,linha6_3__7,linha6_3__6,
          linha6_3__5,linha6_3__4,linha6_3__3,linha6_3__2,linha6_3__1,
          linha6_3__0}), .b ({linha7_3__15,linha7_3__14,linha7_3__13,
          linha7_3__12,linha7_3__11,linha7_3__10,linha7_3__9,linha7_3__8,
          linha7_3__7,linha7_3__6,linha7_3__5,linha7_3__4,linha7_3__3,
          linha7_3__2,linha7_3__1,linha7_3__0})) ;
    BN_16 row_4_rowp_bni1 (.max ({linha1_3__15,linha1_3__14,linha1_3__13,
          linha1_3__12,linha1_3__11,linha1_3__10,linha1_3__9,linha1_3__8,
          linha1_3__7,linha1_3__6,linha1_3__5,linha1_3__4,linha1_3__3,
          linha1_3__2,linha1_3__1,linha1_3__0}), .min ({linha2_5__15,
          linha2_5__14,linha2_5__13,linha2_5__12,linha2_5__11,linha2_5__10,
          linha2_5__9,linha2_5__8,linha2_5__7,linha2_5__6,linha2_5__5,
          linha2_5__4,linha2_5__3,linha2_5__2,linha2_5__1,linha2_5__0}), .a ({
          linha1_2__15,linha1_2__14,linha1_2__13,linha1_2__12,linha1_2__11,
          linha1_2__10,linha1_2__9,linha1_2__8,linha1_2__7,linha1_2__6,
          linha1_2__5,linha1_2__4,linha1_2__3,linha1_2__2,linha1_2__1,
          linha1_2__0}), .b ({linha2_4__15,linha2_4__14,linha2_4__13,
          linha2_4__12,linha2_4__11,linha2_4__10,linha2_4__9,linha2_4__8,
          linha2_4__7,linha2_4__6,linha2_4__5,linha2_4__4,linha2_4__3,
          linha2_4__2,linha2_4__1,linha2_4__0})) ;
    BN_16 row_4_rowp_bni2 (.max ({linha3_5__15,linha3_5__14,linha3_5__13,
          linha3_5__12,linha3_5__11,linha3_5__10,linha3_5__9,linha3_5__8,
          linha3_5__7,linha3_5__6,linha3_5__5,linha3_5__4,linha3_5__3,
          linha3_5__2,linha3_5__1,linha3_5__0}), .min ({linha4_5__15,
          linha4_5__14,linha4_5__13,linha4_5__12,linha4_5__11,linha4_5__10,
          linha4_5__9,linha4_5__8,linha4_5__7,linha4_5__6,linha4_5__5,
          linha4_5__4,linha4_5__3,linha4_5__2,linha4_5__1,linha4_5__0}), .a ({
          linha3_4__15,linha3_4__14,linha3_4__13,linha3_4__12,linha3_4__11,
          linha3_4__10,linha3_4__9,linha3_4__8,linha3_4__7,linha3_4__6,
          linha3_4__5,linha3_4__4,linha3_4__3,linha3_4__2,linha3_4__1,
          linha3_4__0}), .b ({linha4_4__15,linha4_4__14,linha4_4__13,
          linha4_4__12,linha4_4__11,linha4_4__10,linha4_4__9,linha4_4__8,
          linha4_4__7,linha4_4__6,linha4_4__5,linha4_4__4,linha4_4__3,
          linha4_4__2,linha4_4__1,linha4_4__0})) ;
    BN_16 row_4_rowp_bni3 (.max ({linha5_5__15,linha5_5__14,linha5_5__13,
          linha5_5__12,linha5_5__11,linha5_5__10,linha5_5__9,linha5_5__8,
          linha5_5__7,linha5_5__6,linha5_5__5,linha5_5__4,linha5_5__3,
          linha5_5__2,linha5_5__1,linha5_5__0}), .min ({linha6_5__15,
          linha6_5__14,linha6_5__13,linha6_5__12,linha6_5__11,linha6_5__10,
          linha6_5__9,linha6_5__8,linha6_5__7,linha6_5__6,linha6_5__5,
          linha6_5__4,linha6_5__3,linha6_5__2,linha6_5__1,linha6_5__0}), .a ({
          linha5_4__15,linha5_4__14,linha5_4__13,linha5_4__12,linha5_4__11,
          linha5_4__10,linha5_4__9,linha5_4__8,linha5_4__7,linha5_4__6,
          linha5_4__5,linha5_4__4,linha5_4__3,linha5_4__2,linha5_4__1,
          linha5_4__0}), .b ({linha6_4__15,linha6_4__14,linha6_4__13,
          linha6_4__12,linha6_4__11,linha6_4__10,linha6_4__9,linha6_4__8,
          linha6_4__7,linha6_4__6,linha6_4__5,linha6_4__4,linha6_4__3,
          linha6_4__2,linha6_4__1,linha6_4__0})) ;
    BN_16 row_4_rowp_bni4 (.max ({linha7_5__15,linha7_5__14,linha7_5__13,
          linha7_5__12,linha7_5__11,linha7_5__10,linha7_5__9,linha7_5__8,
          linha7_5__7,linha7_5__6,linha7_5__5,linha7_5__4,linha7_5__3,
          linha7_5__2,linha7_5__1,linha7_5__0}), .min ({linha8_3__15,
          linha8_3__14,linha8_3__13,linha8_3__12,linha8_3__11,linha8_3__10,
          linha8_3__9,linha8_3__8,linha8_3__7,linha8_3__6,linha8_3__5,
          linha8_3__4,linha8_3__3,linha8_3__2,linha8_3__1,linha8_3__0}), .a ({
          linha7_4__15,linha7_4__14,linha7_4__13,linha7_4__12,linha7_4__11,
          linha7_4__10,linha7_4__9,linha7_4__8,linha7_4__7,linha7_4__6,
          linha7_4__5,linha7_4__4,linha7_4__3,linha7_4__2,linha7_4__1,
          linha7_4__0}), .b ({linha8_2__15,linha8_2__14,linha8_2__13,
          linha8_2__12,linha8_2__11,linha8_2__10,linha8_2__9,linha8_2__8,
          linha8_2__7,linha8_2__6,linha8_2__5,linha8_2__4,linha8_2__3,
          linha8_2__2,linha8_2__1,linha8_2__0})) ;
    BN_16 row_5_rowi_bni1 (.max ({linha2_6__15,linha2_6__14,linha2_6__13,
          linha2_6__12,linha2_6__11,linha2_6__10,linha2_6__9,linha2_6__8,
          linha2_6__7,linha2_6__6,linha2_6__5,linha2_6__4,linha2_6__3,
          linha2_6__2,linha2_6__1,linha2_6__0}), .min ({linha3_6__15,
          linha3_6__14,linha3_6__13,linha3_6__12,linha3_6__11,linha3_6__10,
          linha3_6__9,linha3_6__8,linha3_6__7,linha3_6__6,linha3_6__5,
          linha3_6__4,linha3_6__3,linha3_6__2,linha3_6__1,linha3_6__0}), .a ({
          linha2_5__15,linha2_5__14,linha2_5__13,linha2_5__12,linha2_5__11,
          linha2_5__10,linha2_5__9,linha2_5__8,linha2_5__7,linha2_5__6,
          linha2_5__5,linha2_5__4,linha2_5__3,linha2_5__2,linha2_5__1,
          linha2_5__0}), .b ({linha3_5__15,linha3_5__14,linha3_5__13,
          linha3_5__12,linha3_5__11,linha3_5__10,linha3_5__9,linha3_5__8,
          linha3_5__7,linha3_5__6,linha3_5__5,linha3_5__4,linha3_5__3,
          linha3_5__2,linha3_5__1,linha3_5__0})) ;
    BN_16 row_5_rowi_bni2 (.max ({linha4_6__15,linha4_6__14,linha4_6__13,
          linha4_6__12,linha4_6__11,linha4_6__10,linha4_6__9,linha4_6__8,
          linha4_6__7,linha4_6__6,linha4_6__5,linha4_6__4,linha4_6__3,
          linha4_6__2,linha4_6__1,linha4_6__0}), .min ({linha5_6__15,
          linha5_6__14,linha5_6__13,linha5_6__12,linha5_6__11,linha5_6__10,
          linha5_6__9,linha5_6__8,linha5_6__7,linha5_6__6,linha5_6__5,
          linha5_6__4,linha5_6__3,linha5_6__2,linha5_6__1,linha5_6__0}), .a ({
          linha4_5__15,linha4_5__14,linha4_5__13,linha4_5__12,linha4_5__11,
          linha4_5__10,linha4_5__9,linha4_5__8,linha4_5__7,linha4_5__6,
          linha4_5__5,linha4_5__4,linha4_5__3,linha4_5__2,linha4_5__1,
          linha4_5__0}), .b ({linha5_5__15,linha5_5__14,linha5_5__13,
          linha5_5__12,linha5_5__11,linha5_5__10,linha5_5__9,linha5_5__8,
          linha5_5__7,linha5_5__6,linha5_5__5,linha5_5__4,linha5_5__3,
          linha5_5__2,linha5_5__1,linha5_5__0})) ;
    BN_16 row_5_rowi_bni3 (.max ({linha6_6__15,linha6_6__14,linha6_6__13,
          linha6_6__12,linha6_6__11,linha6_6__10,linha6_6__9,linha6_6__8,
          linha6_6__7,linha6_6__6,linha6_6__5,linha6_6__4,linha6_6__3,
          linha6_6__2,linha6_6__1,linha6_6__0}), .min ({linha7_6__15,
          linha7_6__14,linha7_6__13,linha7_6__12,linha7_6__11,linha7_6__10,
          linha7_6__9,linha7_6__8,linha7_6__7,linha7_6__6,linha7_6__5,
          linha7_6__4,linha7_6__3,linha7_6__2,linha7_6__1,linha7_6__0}), .a ({
          linha6_5__15,linha6_5__14,linha6_5__13,linha6_5__12,linha6_5__11,
          linha6_5__10,linha6_5__9,linha6_5__8,linha6_5__7,linha6_5__6,
          linha6_5__5,linha6_5__4,linha6_5__3,linha6_5__2,linha6_5__1,
          linha6_5__0}), .b ({linha7_5__15,linha7_5__14,linha7_5__13,
          linha7_5__12,linha7_5__11,linha7_5__10,linha7_5__9,linha7_5__8,
          linha7_5__7,linha7_5__6,linha7_5__5,linha7_5__4,linha7_5__3,
          linha7_5__2,linha7_5__1,linha7_5__0})) ;
    BN_16 row_6_rowp_bni1 (.max ({y1[15],y1[14],y1[13],y1[12],y1[11],y1[10],
          y1[9],y1[8],y1[7],y1[6],y1[5],y1[4],y1[3],y1[2],y1[1],y1[0]}), .min ({
          linha2_7__15,linha2_7__14,linha2_7__13,linha2_7__12,linha2_7__11,
          linha2_7__10,linha2_7__9,linha2_7__8,linha2_7__7,linha2_7__6,
          linha2_7__5,linha2_7__4,linha2_7__3,linha2_7__2,linha2_7__1,
          linha2_7__0}), .a ({linha1_3__15,linha1_3__14,linha1_3__13,
          linha1_3__12,linha1_3__11,linha1_3__10,linha1_3__9,linha1_3__8,
          linha1_3__7,linha1_3__6,linha1_3__5,linha1_3__4,linha1_3__3,
          linha1_3__2,linha1_3__1,linha1_3__0}), .b ({linha2_6__15,linha2_6__14,
          linha2_6__13,linha2_6__12,linha2_6__11,linha2_6__10,linha2_6__9,
          linha2_6__8,linha2_6__7,linha2_6__6,linha2_6__5,linha2_6__4,
          linha2_6__3,linha2_6__2,linha2_6__1,linha2_6__0})) ;
    BN_16 row_6_rowp_bni2 (.max ({linha3_7__15,linha3_7__14,linha3_7__13,
          linha3_7__12,linha3_7__11,linha3_7__10,linha3_7__9,linha3_7__8,
          linha3_7__7,linha3_7__6,linha3_7__5,linha3_7__4,linha3_7__3,
          linha3_7__2,linha3_7__1,linha3_7__0}), .min ({linha4_7__15,
          linha4_7__14,linha4_7__13,linha4_7__12,linha4_7__11,linha4_7__10,
          linha4_7__9,linha4_7__8,linha4_7__7,linha4_7__6,linha4_7__5,
          linha4_7__4,linha4_7__3,linha4_7__2,linha4_7__1,linha4_7__0}), .a ({
          linha3_6__15,linha3_6__14,linha3_6__13,linha3_6__12,linha3_6__11,
          linha3_6__10,linha3_6__9,linha3_6__8,linha3_6__7,linha3_6__6,
          linha3_6__5,linha3_6__4,linha3_6__3,linha3_6__2,linha3_6__1,
          linha3_6__0}), .b ({linha4_6__15,linha4_6__14,linha4_6__13,
          linha4_6__12,linha4_6__11,linha4_6__10,linha4_6__9,linha4_6__8,
          linha4_6__7,linha4_6__6,linha4_6__5,linha4_6__4,linha4_6__3,
          linha4_6__2,linha4_6__1,linha4_6__0})) ;
    BN_16 row_6_rowp_bni3 (.max ({linha5_7__15,linha5_7__14,linha5_7__13,
          linha5_7__12,linha5_7__11,linha5_7__10,linha5_7__9,linha5_7__8,
          linha5_7__7,linha5_7__6,linha5_7__5,linha5_7__4,linha5_7__3,
          linha5_7__2,linha5_7__1,linha5_7__0}), .min ({linha6_7__15,
          linha6_7__14,linha6_7__13,linha6_7__12,linha6_7__11,linha6_7__10,
          linha6_7__9,linha6_7__8,linha6_7__7,linha6_7__6,linha6_7__5,
          linha6_7__4,linha6_7__3,linha6_7__2,linha6_7__1,linha6_7__0}), .a ({
          linha5_6__15,linha5_6__14,linha5_6__13,linha5_6__12,linha5_6__11,
          linha5_6__10,linha5_6__9,linha5_6__8,linha5_6__7,linha5_6__6,
          linha5_6__5,linha5_6__4,linha5_6__3,linha5_6__2,linha5_6__1,
          linha5_6__0}), .b ({linha6_6__15,linha6_6__14,linha6_6__13,
          linha6_6__12,linha6_6__11,linha6_6__10,linha6_6__9,linha6_6__8,
          linha6_6__7,linha6_6__6,linha6_6__5,linha6_6__4,linha6_6__3,
          linha6_6__2,linha6_6__1,linha6_6__0})) ;
    BN_16 row_6_rowp_bni4 (.max ({linha7_7__15,linha7_7__14,linha7_7__13,
          linha7_7__12,linha7_7__11,linha7_7__10,linha7_7__9,linha7_7__8,
          linha7_7__7,linha7_7__6,linha7_7__5,linha7_7__4,linha7_7__3,
          linha7_7__2,linha7_7__1,linha7_7__0}), .min ({y8[15],y8[14],y8[13],
          y8[12],y8[11],y8[10],y8[9],y8[8],y8[7],y8[6],y8[5],y8[4],y8[3],y8[2],
          y8[1],y8[0]}), .a ({linha7_6__15,linha7_6__14,linha7_6__13,
          linha7_6__12,linha7_6__11,linha7_6__10,linha7_6__9,linha7_6__8,
          linha7_6__7,linha7_6__6,linha7_6__5,linha7_6__4,linha7_6__3,
          linha7_6__2,linha7_6__1,linha7_6__0}), .b ({linha8_3__15,linha8_3__14,
          linha8_3__13,linha8_3__12,linha8_3__11,linha8_3__10,linha8_3__9,
          linha8_3__8,linha8_3__7,linha8_3__6,linha8_3__5,linha8_3__4,
          linha8_3__3,linha8_3__2,linha8_3__1,linha8_3__0})) ;
    BN_16 row_7_rowi_bni1 (.max ({y2[15],y2[14],y2[13],y2[12],y2[11],y2[10],
          y2[9],y2[8],y2[7],y2[6],y2[5],y2[4],y2[3],y2[2],y2[1],y2[0]}), .min ({
          y3[15],y3[14],y3[13],y3[12],y3[11],y3[10],y3[9],y3[8],y3[7],y3[6],
          y3[5],y3[4],y3[3],y3[2],y3[1],y3[0]}), .a ({linha2_7__15,linha2_7__14,
          linha2_7__13,linha2_7__12,linha2_7__11,linha2_7__10,linha2_7__9,
          linha2_7__8,linha2_7__7,linha2_7__6,linha2_7__5,linha2_7__4,
          linha2_7__3,linha2_7__2,linha2_7__1,linha2_7__0}), .b ({linha3_7__15,
          linha3_7__14,linha3_7__13,linha3_7__12,linha3_7__11,linha3_7__10,
          linha3_7__9,linha3_7__8,linha3_7__7,linha3_7__6,linha3_7__5,
          linha3_7__4,linha3_7__3,linha3_7__2,linha3_7__1,linha3_7__0})) ;
    BN_16 row_7_rowi_bni2 (.max ({y4[15],y4[14],y4[13],y4[12],y4[11],y4[10],
          y4[9],y4[8],y4[7],y4[6],y4[5],y4[4],y4[3],y4[2],y4[1],y4[0]}), .min ({
          y5[15],y5[14],y5[13],y5[12],y5[11],y5[10],y5[9],y5[8],y5[7],y5[6],
          y5[5],y5[4],y5[3],y5[2],y5[1],y5[0]}), .a ({linha4_7__15,linha4_7__14,
          linha4_7__13,linha4_7__12,linha4_7__11,linha4_7__10,linha4_7__9,
          linha4_7__8,linha4_7__7,linha4_7__6,linha4_7__5,linha4_7__4,
          linha4_7__3,linha4_7__2,linha4_7__1,linha4_7__0}), .b ({linha5_7__15,
          linha5_7__14,linha5_7__13,linha5_7__12,linha5_7__11,linha5_7__10,
          linha5_7__9,linha5_7__8,linha5_7__7,linha5_7__6,linha5_7__5,
          linha5_7__4,linha5_7__3,linha5_7__2,linha5_7__1,linha5_7__0})) ;
    BN_16 row_7_rowi_bni3 (.max ({y6[15],y6[14],y6[13],y6[12],y6[11],y6[10],
          y6[9],y6[8],y6[7],y6[6],y6[5],y6[4],y6[3],y6[2],y6[1],y6[0]}), .min ({
          y7[15],y7[14],y7[13],y7[12],y7[11],y7[10],y7[9],y7[8],y7[7],y7[6],
          y7[5],y7[4],y7[3],y7[2],y7[1],y7[0]}), .a ({linha6_7__15,linha6_7__14,
          linha6_7__13,linha6_7__12,linha6_7__11,linha6_7__10,linha6_7__9,
          linha6_7__8,linha6_7__7,linha6_7__6,linha6_7__5,linha6_7__4,
          linha6_7__3,linha6_7__2,linha6_7__1,linha6_7__0}), .b ({linha7_7__15,
          linha7_7__14,linha7_7__13,linha7_7__12,linha7_7__11,linha7_7__10,
          linha7_7__9,linha7_7__8,linha7_7__7,linha7_7__6,linha7_7__5,
          linha7_7__4,linha7_7__3,linha7_7__2,linha7_7__1,linha7_7__0})) ;
endmodule


module BN_16 ( max, min, a, b ) ;

    output [15:0]max ;
    output [15:0]min ;
    input [15:0]a ;
    input [15:0]b ;

    wire l, nx265;
    wire [0:0] \$dummy ;




    juntarComparadores_16 Comp (.g (\$dummy [0]), .l (l), .a ({a[15],a[14],a[13]
                          ,a[12],a[11],a[10],a[9],a[8],a[7],a[6],a[5],a[4],a[3],
                          a[2],a[1],a[0]}), .b ({b[15],b[14],b[13],b[12],b[11],
                          b[10],b[9],b[8],b[7],b[6],b[5],b[4],b[3],b[2],b[1],
                          b[0]})) ;
    MX2T0 ix7 (.X (min[0]), .A (a[0]), .B (b[0]), .S (nx265)) ;
    MX2T0 ix15 (.X (min[1]), .A (a[1]), .B (b[1]), .S (nx265)) ;
    MX2T0 ix23 (.X (min[2]), .A (a[2]), .B (b[2]), .S (nx265)) ;
    MX2T0 ix31 (.X (min[3]), .A (a[3]), .B (b[3]), .S (nx265)) ;
    MX2T0 ix39 (.X (min[4]), .A (a[4]), .B (b[4]), .S (nx265)) ;
    MX2T0 ix47 (.X (min[5]), .A (a[5]), .B (b[5]), .S (nx265)) ;
    MX2T0 ix55 (.X (min[6]), .A (a[6]), .B (b[6]), .S (nx265)) ;
    MX2T0 ix63 (.X (min[7]), .A (a[7]), .B (b[7]), .S (nx265)) ;
    MX2T0 ix71 (.X (min[8]), .A (a[8]), .B (b[8]), .S (nx265)) ;
    MX2T0 ix79 (.X (min[9]), .A (a[9]), .B (b[9]), .S (nx265)) ;
    MX2T0 ix87 (.X (min[10]), .A (a[10]), .B (b[10]), .S (nx265)) ;
    MX2T0 ix95 (.X (min[11]), .A (a[11]), .B (b[11]), .S (nx265)) ;
    MX2T0 ix103 (.X (min[12]), .A (a[12]), .B (b[12]), .S (nx265)) ;
    MX2T0 ix111 (.X (min[13]), .A (a[13]), .B (b[13]), .S (nx265)) ;
    MX2T0 ix119 (.X (min[14]), .A (a[14]), .B (b[14]), .S (nx265)) ;
    MX2T0 ix127 (.X (min[15]), .A (a[15]), .B (b[15]), .S (nx265)) ;
    MX2T0 ix135 (.X (max[0]), .A (b[0]), .B (a[0]), .S (nx265)) ;
    MX2T0 ix143 (.X (max[1]), .A (b[1]), .B (a[1]), .S (nx265)) ;
    MX2T0 ix151 (.X (max[2]), .A (b[2]), .B (a[2]), .S (nx265)) ;
    MX2T0 ix159 (.X (max[3]), .A (b[3]), .B (a[3]), .S (nx265)) ;
    MX2T0 ix167 (.X (max[4]), .A (b[4]), .B (a[4]), .S (nx265)) ;
    MX2T0 ix175 (.X (max[5]), .A (b[5]), .B (a[5]), .S (nx265)) ;
    MX2T0 ix183 (.X (max[6]), .A (b[6]), .B (a[6]), .S (nx265)) ;
    MX2T0 ix191 (.X (max[7]), .A (b[7]), .B (a[7]), .S (nx265)) ;
    MX2T0 ix199 (.X (max[8]), .A (b[8]), .B (a[8]), .S (nx265)) ;
    MX2T0 ix207 (.X (max[9]), .A (b[9]), .B (a[9]), .S (nx265)) ;
    MX2T0 ix215 (.X (max[10]), .A (b[10]), .B (a[10]), .S (nx265)) ;
    MX2T0 ix223 (.X (max[11]), .A (b[11]), .B (a[11]), .S (nx265)) ;
    MX2T0 ix231 (.X (max[12]), .A (b[12]), .B (a[12]), .S (nx265)) ;
    MX2T0 ix239 (.X (max[13]), .A (b[13]), .B (a[13]), .S (nx265)) ;
    MX2T0 ix247 (.X (max[14]), .A (b[14]), .B (a[14]), .S (nx265)) ;
    MX2T0 ix255 (.X (max[15]), .A (b[15]), .B (a[15]), .S (nx265)) ;
    AN1V1 ix264 (.X (nx265), .A (l)) ;
endmodule


module AN1V1 ( X, A ) ;

    output X ;
    input A ;




    assign X = A ;
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


module juntarComparadores_16 ( g, l, a, b ) ;

    output g ;
    output l ;
    input [15:0]a ;
    input [15:0]b ;

    wire nx28, nx48, nx58, nx88, nx98, nx128, nx138, nx168, nx178, nx208, nx218, 
         nx248, nx258, nx288, nx267, nx269, nx271, nx273, nx275, nx277, nx279, 
         nx281, nx283, nx285, nx287, nx289, nx291, nx293, nx295, nx297, nx299, 
         nx301, nx303, nx305, nx307, nx309, nx311, nx313, nx315, nx317, nx319, 
         nx321, nx323, nx325, nx327, nx329, nx331, nx333, nx336;



    OAI3R0 ix299 (.X (l), .A1 (nx288), .A2 (a[0]), .A3 (nx331), .B (nx333)) ;
    OAI3R0 ix289 (.X (nx288), .A1 (nx258), .A2 (nx327), .A3 (b[1]), .B (nx329)
           ) ;
    OAI3R0 ix259 (.X (nx258), .A1 (nx248), .A2 (a[2]), .A3 (nx323), .B (nx325)
           ) ;
    OAI3R0 ix249 (.X (nx248), .A1 (nx218), .A2 (nx319), .A3 (b[3]), .B (nx321)
           ) ;
    OAI3R0 ix219 (.X (nx218), .A1 (nx208), .A2 (a[4]), .A3 (nx315), .B (nx317)
           ) ;
    OAI3R0 ix209 (.X (nx208), .A1 (nx178), .A2 (nx311), .A3 (b[5]), .B (nx313)
           ) ;
    OAI3R0 ix179 (.X (nx178), .A1 (nx168), .A2 (a[6]), .A3 (nx307), .B (nx309)
           ) ;
    OAI3R0 ix169 (.X (nx168), .A1 (nx138), .A2 (nx303), .A3 (b[7]), .B (nx305)
           ) ;
    OAI3R0 ix139 (.X (nx138), .A1 (nx128), .A2 (a[8]), .A3 (nx299), .B (nx301)
           ) ;
    OAI3R0 ix129 (.X (nx128), .A1 (nx98), .A2 (nx295), .A3 (b[9]), .B (nx297)) ;
    OAI3R0 ix99 (.X (nx98), .A1 (nx88), .A2 (a[10]), .A3 (nx291), .B (nx293)) ;
    OAI3R0 ix89 (.X (nx88), .A1 (nx58), .A2 (nx287), .A3 (b[11]), .B (nx289)) ;
    OAI3R0 ix59 (.X (nx58), .A1 (nx48), .A2 (a[12]), .A3 (nx283), .B (nx285)) ;
    OAI3R0 ix49 (.X (nx48), .A1 (nx28), .A2 (nx275), .A3 (b[13]), .B (nx277)) ;
    OAI1A0 ix29 (.X (nx28), .A1 (a[15]), .A2 (nx267), .B (nx269)) ;
    IV1N0 ix268 (.X (nx267), .A (b[15])) ;
    OAI3N0 ix270 (.X (nx269), .A1 (nx271), .A2 (b[15]), .B1 (nx273), .B2 (b[14])
           ) ;
    IV1N0 ix272 (.X (nx271), .A (a[15])) ;
    IV1N0 ix274 (.X (nx273), .A (a[14])) ;
    IV1N0 ix276 (.X (nx275), .A (a[13])) ;
    OA1R0 ix278 (.X (nx277), .A1 (nx271), .A2 (b[15]), .B (nx279)) ;
    OAI3N0 ix280 (.X (nx279), .A1 (nx267), .A2 (a[15]), .B1 (a[14]), .B2 (nx281)
           ) ;
    IV1N0 ix282 (.X (nx281), .A (b[14])) ;
    IV1N0 ix284 (.X (nx283), .A (b[12])) ;
    AO3I0 ix286 (.X (nx285), .A1 (nx277), .A2 (nx275), .A3 (b[13]), .B (nx28)) ;
    IV1N0 ix288 (.X (nx287), .A (a[11])) ;
    AO3I0 ix290 (.X (nx289), .A1 (nx285), .A2 (a[12]), .A3 (nx283), .B (nx48)) ;
    IV1N0 ix292 (.X (nx291), .A (b[10])) ;
    AO3I0 ix294 (.X (nx293), .A1 (nx289), .A2 (nx287), .A3 (b[11]), .B (nx58)) ;
    IV1N0 ix296 (.X (nx295), .A (a[9])) ;
    AO3I0 ix298 (.X (nx297), .A1 (nx293), .A2 (a[10]), .A3 (nx291), .B (nx88)) ;
    IV1N0 ix300 (.X (nx299), .A (b[8])) ;
    AO3I0 ix302 (.X (nx301), .A1 (nx297), .A2 (nx295), .A3 (b[9]), .B (nx98)) ;
    IV1N0 ix304 (.X (nx303), .A (a[7])) ;
    AO3I0 ix306 (.X (nx305), .A1 (nx301), .A2 (a[8]), .A3 (nx299), .B (nx128)) ;
    IV1N0 ix308 (.X (nx307), .A (b[6])) ;
    AO3I0 ix310 (.X (nx309), .A1 (nx305), .A2 (nx303), .A3 (b[7]), .B (nx138)) ;
    IV1N0 ix312 (.X (nx311), .A (a[5])) ;
    AO3I0 ix314 (.X (nx313), .A1 (nx309), .A2 (a[6]), .A3 (nx307), .B (nx168)) ;
    IV1N0 ix316 (.X (nx315), .A (b[4])) ;
    AO3I0 ix318 (.X (nx317), .A1 (nx313), .A2 (nx311), .A3 (b[5]), .B (nx178)) ;
    IV1N0 ix320 (.X (nx319), .A (a[3])) ;
    AO3I0 ix322 (.X (nx321), .A1 (nx317), .A2 (a[4]), .A3 (nx315), .B (nx208)) ;
    IV1N0 ix324 (.X (nx323), .A (b[2])) ;
    AO3I0 ix326 (.X (nx325), .A1 (nx321), .A2 (nx319), .A3 (b[3]), .B (nx218)) ;
    IV1N0 ix328 (.X (nx327), .A (a[1])) ;
    AO3I0 ix330 (.X (nx329), .A1 (nx325), .A2 (a[2]), .A3 (nx323), .B (nx248)) ;
    IV1N0 ix332 (.X (nx331), .A (b[0])) ;
    AO3I0 ix334 (.X (nx333), .A1 (nx329), .A2 (nx327), .A3 (b[1]), .B (nx258)) ;
    IV1N0 ix309 (.X (g), .A (nx336)) ;
    AO3I0 ix337 (.X (nx336), .A1 (nx333), .A2 (a[0]), .A3 (nx331), .B (nx288)) ;
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

