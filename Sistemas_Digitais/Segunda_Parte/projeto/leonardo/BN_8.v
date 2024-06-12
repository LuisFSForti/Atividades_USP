//
// Verilog description for cell ordenador, 
// 06/12/24 10:25:29
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module ordenador ( y8, y7, y6, y5, y4, y3, y2, y1, x8, x7, x6, x5, x4, x3, x2, 
                   x1 ) ;

    output [7:0]y8 ;
    output [7:0]y7 ;
    output [7:0]y6 ;
    output [7:0]y5 ;
    output [7:0]y4 ;
    output [7:0]y3 ;
    output [7:0]y2 ;
    output [7:0]y1 ;
    input [7:0]x8 ;
    input [7:0]x7 ;
    input [7:0]x6 ;
    input [7:0]x5 ;
    input [7:0]x4 ;
    input [7:0]x3 ;
    input [7:0]x2 ;
    input [7:0]x1 ;

    wire linha7_7__7, linha7_7__6, linha7_7__5, linha7_7__4, linha7_7__3, 
         linha7_7__2, linha7_7__1, linha7_7__0, linha7_6__7, linha7_6__6, 
         linha7_6__5, linha7_6__4, linha7_6__3, linha7_6__2, linha7_6__1, 
         linha7_6__0, linha7_5__7, linha7_5__6, linha7_5__5, linha7_5__4, 
         linha7_5__3, linha7_5__2, linha7_5__1, linha7_5__0, linha7_4__7, 
         linha7_4__6, linha7_4__5, linha7_4__4, linha7_4__3, linha7_4__2, 
         linha7_4__1, linha7_4__0, linha7_3__7, linha7_3__6, linha7_3__5, 
         linha7_3__4, linha7_3__3, linha7_3__2, linha7_3__1, linha7_3__0, 
         linha7_2__7, linha7_2__6, linha7_2__5, linha7_2__4, linha7_2__3, 
         linha7_2__2, linha7_2__1, linha7_2__0, linha7_1__7, linha7_1__6, 
         linha7_1__5, linha7_1__4, linha7_1__3, linha7_1__2, linha7_1__1, 
         linha7_1__0, linha6_7__7, linha6_7__6, linha6_7__5, linha6_7__4, 
         linha6_7__3, linha6_7__2, linha6_7__1, linha6_7__0, linha6_6__7, 
         linha6_6__6, linha6_6__5, linha6_6__4, linha6_6__3, linha6_6__2, 
         linha6_6__1, linha6_6__0, linha6_5__7, linha6_5__6, linha6_5__5, 
         linha6_5__4, linha6_5__3, linha6_5__2, linha6_5__1, linha6_5__0, 
         linha6_4__7, linha6_4__6, linha6_4__5, linha6_4__4, linha6_4__3, 
         linha6_4__2, linha6_4__1, linha6_4__0, linha6_3__7, linha6_3__6, 
         linha6_3__5, linha6_3__4, linha6_3__3, linha6_3__2, linha6_3__1, 
         linha6_3__0, linha6_2__7, linha6_2__6, linha6_2__5, linha6_2__4, 
         linha6_2__3, linha6_2__2, linha6_2__1, linha6_2__0, linha6_1__7, 
         linha6_1__6, linha6_1__5, linha6_1__4, linha6_1__3, linha6_1__2, 
         linha6_1__1, linha6_1__0, linha5_7__7, linha5_7__6, linha5_7__5, 
         linha5_7__4, linha5_7__3, linha5_7__2, linha5_7__1, linha5_7__0, 
         linha5_6__7, linha5_6__6, linha5_6__5, linha5_6__4, linha5_6__3, 
         linha5_6__2, linha5_6__1, linha5_6__0, linha5_5__7, linha5_5__6, 
         linha5_5__5, linha5_5__4, linha5_5__3, linha5_5__2, linha5_5__1, 
         linha5_5__0, linha5_4__7, linha5_4__6, linha5_4__5, linha5_4__4, 
         linha5_4__3, linha5_4__2, linha5_4__1, linha5_4__0, linha5_3__7, 
         linha5_3__6, linha5_3__5, linha5_3__4, linha5_3__3, linha5_3__2, 
         linha5_3__1, linha5_3__0, linha5_2__7, linha5_2__6, linha5_2__5, 
         linha5_2__4, linha5_2__3, linha5_2__2, linha5_2__1, linha5_2__0, 
         linha5_1__7, linha5_1__6, linha5_1__5, linha5_1__4, linha5_1__3, 
         linha5_1__2, linha5_1__1, linha5_1__0, linha4_7__7, linha4_7__6, 
         linha4_7__5, linha4_7__4, linha4_7__3, linha4_7__2, linha4_7__1, 
         linha4_7__0, linha4_6__7, linha4_6__6, linha4_6__5, linha4_6__4, 
         linha4_6__3, linha4_6__2, linha4_6__1, linha4_6__0, linha4_5__7, 
         linha4_5__6, linha4_5__5, linha4_5__4, linha4_5__3, linha4_5__2, 
         linha4_5__1, linha4_5__0, linha4_4__7, linha4_4__6, linha4_4__5, 
         linha4_4__4, linha4_4__3, linha4_4__2, linha4_4__1, linha4_4__0, 
         linha4_3__7, linha4_3__6, linha4_3__5, linha4_3__4, linha4_3__3, 
         linha4_3__2, linha4_3__1, linha4_3__0, linha4_2__7, linha4_2__6, 
         linha4_2__5, linha4_2__4, linha4_2__3, linha4_2__2, linha4_2__1, 
         linha4_2__0, linha4_1__7, linha4_1__6, linha4_1__5, linha4_1__4, 
         linha4_1__3, linha4_1__2, linha4_1__1, linha4_1__0, linha3_7__7, 
         linha3_7__6, linha3_7__5, linha3_7__4, linha3_7__3, linha3_7__2, 
         linha3_7__1, linha3_7__0, linha3_6__7, linha3_6__6, linha3_6__5, 
         linha3_6__4, linha3_6__3, linha3_6__2, linha3_6__1, linha3_6__0, 
         linha3_5__7, linha3_5__6, linha3_5__5, linha3_5__4, linha3_5__3, 
         linha3_5__2, linha3_5__1, linha3_5__0, linha3_4__7, linha3_4__6, 
         linha3_4__5, linha3_4__4, linha3_4__3, linha3_4__2, linha3_4__1, 
         linha3_4__0, linha3_3__7, linha3_3__6, linha3_3__5, linha3_3__4, 
         linha3_3__3, linha3_3__2, linha3_3__1, linha3_3__0, linha3_2__7, 
         linha3_2__6, linha3_2__5, linha3_2__4, linha3_2__3, linha3_2__2, 
         linha3_2__1, linha3_2__0, linha3_1__7, linha3_1__6, linha3_1__5, 
         linha3_1__4, linha3_1__3, linha3_1__2, linha3_1__1, linha3_1__0, 
         linha2_7__7, linha2_7__6, linha2_7__5, linha2_7__4, linha2_7__3, 
         linha2_7__2, linha2_7__1, linha2_7__0, linha2_6__7, linha2_6__6, 
         linha2_6__5, linha2_6__4, linha2_6__3, linha2_6__2, linha2_6__1, 
         linha2_6__0, linha2_5__7, linha2_5__6, linha2_5__5, linha2_5__4, 
         linha2_5__3, linha2_5__2, linha2_5__1, linha2_5__0, linha2_4__7, 
         linha2_4__6, linha2_4__5, linha2_4__4, linha2_4__3, linha2_4__2, 
         linha2_4__1, linha2_4__0, linha2_3__7, linha2_3__6, linha2_3__5, 
         linha2_3__4, linha2_3__3, linha2_3__2, linha2_3__1, linha2_3__0, 
         linha2_2__7, linha2_2__6, linha2_2__5, linha2_2__4, linha2_2__3, 
         linha2_2__2, linha2_2__1, linha2_2__0, linha2_1__7, linha2_1__6, 
         linha2_1__5, linha2_1__4, linha2_1__3, linha2_1__2, linha2_1__1, 
         linha2_1__0, linha8_3__7, linha8_3__6, linha8_3__5, linha8_3__4, 
         linha8_3__3, linha8_3__2, linha8_3__1, linha8_3__0, linha8_2__7, 
         linha8_2__6, linha8_2__5, linha8_2__4, linha8_2__3, linha8_2__2, 
         linha8_2__1, linha8_2__0, linha8_1__7, linha8_1__6, linha8_1__5, 
         linha8_1__4, linha8_1__3, linha8_1__2, linha8_1__1, linha8_1__0, 
         linha1_3__7, linha1_3__6, linha1_3__5, linha1_3__4, linha1_3__3, 
         linha1_3__2, linha1_3__1, linha1_3__0, linha1_2__7, linha1_2__6, 
         linha1_2__5, linha1_2__4, linha1_2__3, linha1_2__2, linha1_2__1, 
         linha1_2__0, linha1_1__7, linha1_1__6, linha1_1__5, linha1_1__4, 
         linha1_1__3, linha1_1__2, linha1_1__1, linha1_1__0, row_0_rowp_bni1_l, 
         row_0_rowp_bni2_l, row_0_rowp_bni3_l, row_0_rowp_bni4_l, 
         row_1_rowi_bni1_l, row_1_rowi_bni2_l, row_1_rowi_bni3_l, 
         row_2_rowp_bni1_l, row_2_rowp_bni2_l, row_2_rowp_bni3_l, 
         row_2_rowp_bni4_l, row_3_rowi_bni1_l, row_3_rowi_bni2_l, 
         row_3_rowi_bni3_l, row_4_rowp_bni1_l, row_4_rowp_bni2_l, 
         row_4_rowp_bni3_l, row_4_rowp_bni4_l, row_5_rowi_bni1_l, 
         row_5_rowi_bni2_l, row_5_rowi_bni3_l, row_6_rowp_bni1_l, 
         row_6_rowp_bni2_l, row_6_rowp_bni3_l, row_6_rowp_bni4_l, 
         row_7_rowi_bni1_l, row_7_rowi_bni2_l, row_7_rowi_bni3_l;
    wire [27:0] \$dummy ;




    juntarComparadores_8 row_0_rowp_bni1_Comp (.g (\$dummy [0]), .l (
                         row_0_rowp_bni1_l), .a ({x1[7],x1[6],x1[5],x1[4],x1[3],
                         x1[2],x1[1],x1[0]}), .b ({x2[7],x2[6],x2[5],x2[4],x2[3]
                         ,x2[2],x2[1],x2[0]})) ;
    juntarComparadores_8 row_0_rowp_bni2_Comp (.g (\$dummy [1]), .l (
                         row_0_rowp_bni2_l), .a ({x3[7],x3[6],x3[5],x3[4],x3[3],
                         x3[2],x3[1],x3[0]}), .b ({x4[7],x4[6],x4[5],x4[4],x4[3]
                         ,x4[2],x4[1],x4[0]})) ;
    juntarComparadores_8 row_0_rowp_bni3_Comp (.g (\$dummy [2]), .l (
                         row_0_rowp_bni3_l), .a ({x5[7],x5[6],x5[5],x5[4],x5[3],
                         x5[2],x5[1],x5[0]}), .b ({x6[7],x6[6],x6[5],x6[4],x6[3]
                         ,x6[2],x6[1],x6[0]})) ;
    juntarComparadores_8 row_0_rowp_bni4_Comp (.g (\$dummy [3]), .l (
                         row_0_rowp_bni4_l), .a ({x7[7],x7[6],x7[5],x7[4],x7[3],
                         x7[2],x7[1],x7[0]}), .b ({x8[7],x8[6],x8[5],x8[4],x8[3]
                         ,x8[2],x8[1],x8[0]})) ;
    juntarComparadores_8 row_1_rowi_bni1_Comp (.g (\$dummy [4]), .l (
                         row_1_rowi_bni1_l), .a ({linha2_1__7,linha2_1__6,
                         linha2_1__5,linha2_1__4,linha2_1__3,linha2_1__2,
                         linha2_1__1,linha2_1__0}), .b ({linha3_1__7,linha3_1__6
                         ,linha3_1__5,linha3_1__4,linha3_1__3,linha3_1__2,
                         linha3_1__1,linha3_1__0})) ;
    juntarComparadores_8 row_1_rowi_bni2_Comp (.g (\$dummy [5]), .l (
                         row_1_rowi_bni2_l), .a ({linha4_1__7,linha4_1__6,
                         linha4_1__5,linha4_1__4,linha4_1__3,linha4_1__2,
                         linha4_1__1,linha4_1__0}), .b ({linha5_1__7,linha5_1__6
                         ,linha5_1__5,linha5_1__4,linha5_1__3,linha5_1__2,
                         linha5_1__1,linha5_1__0})) ;
    juntarComparadores_8 row_1_rowi_bni3_Comp (.g (\$dummy [6]), .l (
                         row_1_rowi_bni3_l), .a ({linha6_1__7,linha6_1__6,
                         linha6_1__5,linha6_1__4,linha6_1__3,linha6_1__2,
                         linha6_1__1,linha6_1__0}), .b ({linha7_1__7,linha7_1__6
                         ,linha7_1__5,linha7_1__4,linha7_1__3,linha7_1__2,
                         linha7_1__1,linha7_1__0})) ;
    juntarComparadores_8 row_2_rowp_bni1_Comp (.g (\$dummy [7]), .l (
                         row_2_rowp_bni1_l), .a ({linha1_1__7,linha1_1__6,
                         linha1_1__5,linha1_1__4,linha1_1__3,linha1_1__2,
                         linha1_1__1,linha1_1__0}), .b ({linha2_2__7,linha2_2__6
                         ,linha2_2__5,linha2_2__4,linha2_2__3,linha2_2__2,
                         linha2_2__1,linha2_2__0})) ;
    juntarComparadores_8 row_2_rowp_bni2_Comp (.g (\$dummy [8]), .l (
                         row_2_rowp_bni2_l), .a ({linha3_2__7,linha3_2__6,
                         linha3_2__5,linha3_2__4,linha3_2__3,linha3_2__2,
                         linha3_2__1,linha3_2__0}), .b ({linha4_2__7,linha4_2__6
                         ,linha4_2__5,linha4_2__4,linha4_2__3,linha4_2__2,
                         linha4_2__1,linha4_2__0})) ;
    juntarComparadores_8 row_2_rowp_bni3_Comp (.g (\$dummy [9]), .l (
                         row_2_rowp_bni3_l), .a ({linha5_2__7,linha5_2__6,
                         linha5_2__5,linha5_2__4,linha5_2__3,linha5_2__2,
                         linha5_2__1,linha5_2__0}), .b ({linha6_2__7,linha6_2__6
                         ,linha6_2__5,linha6_2__4,linha6_2__3,linha6_2__2,
                         linha6_2__1,linha6_2__0})) ;
    juntarComparadores_8 row_2_rowp_bni4_Comp (.g (\$dummy [10]), .l (
                         row_2_rowp_bni4_l), .a ({linha7_2__7,linha7_2__6,
                         linha7_2__5,linha7_2__4,linha7_2__3,linha7_2__2,
                         linha7_2__1,linha7_2__0}), .b ({linha8_1__7,linha8_1__6
                         ,linha8_1__5,linha8_1__4,linha8_1__3,linha8_1__2,
                         linha8_1__1,linha8_1__0})) ;
    juntarComparadores_8 row_3_rowi_bni1_Comp (.g (\$dummy [11]), .l (
                         row_3_rowi_bni1_l), .a ({linha2_3__7,linha2_3__6,
                         linha2_3__5,linha2_3__4,linha2_3__3,linha2_3__2,
                         linha2_3__1,linha2_3__0}), .b ({linha3_3__7,linha3_3__6
                         ,linha3_3__5,linha3_3__4,linha3_3__3,linha3_3__2,
                         linha3_3__1,linha3_3__0})) ;
    juntarComparadores_8 row_3_rowi_bni2_Comp (.g (\$dummy [12]), .l (
                         row_3_rowi_bni2_l), .a ({linha4_3__7,linha4_3__6,
                         linha4_3__5,linha4_3__4,linha4_3__3,linha4_3__2,
                         linha4_3__1,linha4_3__0}), .b ({linha5_3__7,linha5_3__6
                         ,linha5_3__5,linha5_3__4,linha5_3__3,linha5_3__2,
                         linha5_3__1,linha5_3__0})) ;
    juntarComparadores_8 row_3_rowi_bni3_Comp (.g (\$dummy [13]), .l (
                         row_3_rowi_bni3_l), .a ({linha6_3__7,linha6_3__6,
                         linha6_3__5,linha6_3__4,linha6_3__3,linha6_3__2,
                         linha6_3__1,linha6_3__0}), .b ({linha7_3__7,linha7_3__6
                         ,linha7_3__5,linha7_3__4,linha7_3__3,linha7_3__2,
                         linha7_3__1,linha7_3__0})) ;
    juntarComparadores_8 row_4_rowp_bni1_Comp (.g (\$dummy [14]), .l (
                         row_4_rowp_bni1_l), .a ({linha1_2__7,linha1_2__6,
                         linha1_2__5,linha1_2__4,linha1_2__3,linha1_2__2,
                         linha1_2__1,linha1_2__0}), .b ({linha2_4__7,linha2_4__6
                         ,linha2_4__5,linha2_4__4,linha2_4__3,linha2_4__2,
                         linha2_4__1,linha2_4__0})) ;
    juntarComparadores_8 row_4_rowp_bni2_Comp (.g (\$dummy [15]), .l (
                         row_4_rowp_bni2_l), .a ({linha3_4__7,linha3_4__6,
                         linha3_4__5,linha3_4__4,linha3_4__3,linha3_4__2,
                         linha3_4__1,linha3_4__0}), .b ({linha4_4__7,linha4_4__6
                         ,linha4_4__5,linha4_4__4,linha4_4__3,linha4_4__2,
                         linha4_4__1,linha4_4__0})) ;
    juntarComparadores_8 row_4_rowp_bni3_Comp (.g (\$dummy [16]), .l (
                         row_4_rowp_bni3_l), .a ({linha5_4__7,linha5_4__6,
                         linha5_4__5,linha5_4__4,linha5_4__3,linha5_4__2,
                         linha5_4__1,linha5_4__0}), .b ({linha6_4__7,linha6_4__6
                         ,linha6_4__5,linha6_4__4,linha6_4__3,linha6_4__2,
                         linha6_4__1,linha6_4__0})) ;
    juntarComparadores_8 row_4_rowp_bni4_Comp (.g (\$dummy [17]), .l (
                         row_4_rowp_bni4_l), .a ({linha7_4__7,linha7_4__6,
                         linha7_4__5,linha7_4__4,linha7_4__3,linha7_4__2,
                         linha7_4__1,linha7_4__0}), .b ({linha8_2__7,linha8_2__6
                         ,linha8_2__5,linha8_2__4,linha8_2__3,linha8_2__2,
                         linha8_2__1,linha8_2__0})) ;
    juntarComparadores_8 row_5_rowi_bni1_Comp (.g (\$dummy [18]), .l (
                         row_5_rowi_bni1_l), .a ({linha2_5__7,linha2_5__6,
                         linha2_5__5,linha2_5__4,linha2_5__3,linha2_5__2,
                         linha2_5__1,linha2_5__0}), .b ({linha3_5__7,linha3_5__6
                         ,linha3_5__5,linha3_5__4,linha3_5__3,linha3_5__2,
                         linha3_5__1,linha3_5__0})) ;
    juntarComparadores_8 row_5_rowi_bni2_Comp (.g (\$dummy [19]), .l (
                         row_5_rowi_bni2_l), .a ({linha4_5__7,linha4_5__6,
                         linha4_5__5,linha4_5__4,linha4_5__3,linha4_5__2,
                         linha4_5__1,linha4_5__0}), .b ({linha5_5__7,linha5_5__6
                         ,linha5_5__5,linha5_5__4,linha5_5__3,linha5_5__2,
                         linha5_5__1,linha5_5__0})) ;
    juntarComparadores_8 row_5_rowi_bni3_Comp (.g (\$dummy [20]), .l (
                         row_5_rowi_bni3_l), .a ({linha6_5__7,linha6_5__6,
                         linha6_5__5,linha6_5__4,linha6_5__3,linha6_5__2,
                         linha6_5__1,linha6_5__0}), .b ({linha7_5__7,linha7_5__6
                         ,linha7_5__5,linha7_5__4,linha7_5__3,linha7_5__2,
                         linha7_5__1,linha7_5__0})) ;
    juntarComparadores_8 row_6_rowp_bni1_Comp (.g (\$dummy [21]), .l (
                         row_6_rowp_bni1_l), .a ({linha1_3__7,linha1_3__6,
                         linha1_3__5,linha1_3__4,linha1_3__3,linha1_3__2,
                         linha1_3__1,linha1_3__0}), .b ({linha2_6__7,linha2_6__6
                         ,linha2_6__5,linha2_6__4,linha2_6__3,linha2_6__2,
                         linha2_6__1,linha2_6__0})) ;
    juntarComparadores_8 row_6_rowp_bni2_Comp (.g (\$dummy [22]), .l (
                         row_6_rowp_bni2_l), .a ({linha3_6__7,linha3_6__6,
                         linha3_6__5,linha3_6__4,linha3_6__3,linha3_6__2,
                         linha3_6__1,linha3_6__0}), .b ({linha4_6__7,linha4_6__6
                         ,linha4_6__5,linha4_6__4,linha4_6__3,linha4_6__2,
                         linha4_6__1,linha4_6__0})) ;
    juntarComparadores_8 row_6_rowp_bni3_Comp (.g (\$dummy [23]), .l (
                         row_6_rowp_bni3_l), .a ({linha5_6__7,linha5_6__6,
                         linha5_6__5,linha5_6__4,linha5_6__3,linha5_6__2,
                         linha5_6__1,linha5_6__0}), .b ({linha6_6__7,linha6_6__6
                         ,linha6_6__5,linha6_6__4,linha6_6__3,linha6_6__2,
                         linha6_6__1,linha6_6__0})) ;
    juntarComparadores_8 row_6_rowp_bni4_Comp (.g (\$dummy [24]), .l (
                         row_6_rowp_bni4_l), .a ({linha7_6__7,linha7_6__6,
                         linha7_6__5,linha7_6__4,linha7_6__3,linha7_6__2,
                         linha7_6__1,linha7_6__0}), .b ({linha8_3__7,linha8_3__6
                         ,linha8_3__5,linha8_3__4,linha8_3__3,linha8_3__2,
                         linha8_3__1,linha8_3__0})) ;
    juntarComparadores_8 row_7_rowi_bni1_Comp (.g (\$dummy [25]), .l (
                         row_7_rowi_bni1_l), .a ({linha2_7__7,linha2_7__6,
                         linha2_7__5,linha2_7__4,linha2_7__3,linha2_7__2,
                         linha2_7__1,linha2_7__0}), .b ({linha3_7__7,linha3_7__6
                         ,linha3_7__5,linha3_7__4,linha3_7__3,linha3_7__2,
                         linha3_7__1,linha3_7__0})) ;
    juntarComparadores_8 row_7_rowi_bni2_Comp (.g (\$dummy [26]), .l (
                         row_7_rowi_bni2_l), .a ({linha4_7__7,linha4_7__6,
                         linha4_7__5,linha4_7__4,linha4_7__3,linha4_7__2,
                         linha4_7__1,linha4_7__0}), .b ({linha5_7__7,linha5_7__6
                         ,linha5_7__5,linha5_7__4,linha5_7__3,linha5_7__2,
                         linha5_7__1,linha5_7__0})) ;
    juntarComparadores_8 row_7_rowi_bni3_Comp (.g (\$dummy [27]), .l (
                         row_7_rowi_bni3_l), .a ({linha6_7__7,linha6_7__6,
                         linha6_7__5,linha6_7__4,linha6_7__3,linha6_7__2,
                         linha6_7__1,linha6_7__0}), .b ({linha7_7__7,linha7_7__6
                         ,linha7_7__5,linha7_7__4,linha7_7__3,linha7_7__2,
                         linha7_7__1,linha7_7__0})) ;
    MX2T0 ix271 (.X (linha1_1__0), .A (x2[0]), .B (x1[0]), .S (row_0_rowp_bni1_l
          )) ;
    MX2T0 ix567 (.X (linha1_1__1), .A (x2[1]), .B (x1[1]), .S (row_0_rowp_bni1_l
          )) ;
    MX2T0 ix863 (.X (linha1_1__2), .A (x2[2]), .B (x1[2]), .S (row_0_rowp_bni1_l
          )) ;
    MX2T0 ix1159 (.X (linha1_1__3), .A (x2[3]), .B (x1[3]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix1455 (.X (linha1_1__4), .A (x2[4]), .B (x1[4]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix1751 (.X (linha1_1__5), .A (x2[5]), .B (x1[5]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix2047 (.X (linha1_1__6), .A (x2[6]), .B (x1[6]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix2343 (.X (linha1_1__7), .A (x2[7]), .B (x1[7]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix2487 (.X (linha1_2__0), .A (linha2_2__0), .B (linha1_1__0), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix259 (.X (linha2_2__0), .A (linha3_1__0), .B (linha2_1__0), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix151 (.X (linha3_1__0), .A (x4[0]), .B (x3[0]), .S (row_0_rowp_bni2_l
          )) ;
    MX2T0 ix163 (.X (linha2_1__0), .A (x1[0]), .B (x2[0]), .S (row_0_rowp_bni1_l
          )) ;
    MX2T0 ix2559 (.X (linha1_2__1), .A (linha2_2__1), .B (linha1_1__1), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix555 (.X (linha2_2__1), .A (linha3_1__1), .B (linha2_1__1), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix447 (.X (linha3_1__1), .A (x4[1]), .B (x3[1]), .S (row_0_rowp_bni2_l
          )) ;
    MX2T0 ix459 (.X (linha2_1__1), .A (x1[1]), .B (x2[1]), .S (row_0_rowp_bni1_l
          )) ;
    MX2T0 ix2631 (.X (linha1_2__2), .A (linha2_2__2), .B (linha1_1__2), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix851 (.X (linha2_2__2), .A (linha3_1__2), .B (linha2_1__2), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix743 (.X (linha3_1__2), .A (x4[2]), .B (x3[2]), .S (row_0_rowp_bni2_l
          )) ;
    MX2T0 ix755 (.X (linha2_1__2), .A (x1[2]), .B (x2[2]), .S (row_0_rowp_bni1_l
          )) ;
    MX2T0 ix2703 (.X (linha1_2__3), .A (linha2_2__3), .B (linha1_1__3), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix1147 (.X (linha2_2__3), .A (linha3_1__3), .B (linha2_1__3), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix1039 (.X (linha3_1__3), .A (x4[3]), .B (x3[3]), .S (
          row_0_rowp_bni2_l)) ;
    MX2T0 ix1051 (.X (linha2_1__3), .A (x1[3]), .B (x2[3]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix2775 (.X (linha1_2__4), .A (linha2_2__4), .B (linha1_1__4), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix1443 (.X (linha2_2__4), .A (linha3_1__4), .B (linha2_1__4), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix1335 (.X (linha3_1__4), .A (x4[4]), .B (x3[4]), .S (
          row_0_rowp_bni2_l)) ;
    MX2T0 ix1347 (.X (linha2_1__4), .A (x1[4]), .B (x2[4]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix2847 (.X (linha1_2__5), .A (linha2_2__5), .B (linha1_1__5), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix1739 (.X (linha2_2__5), .A (linha3_1__5), .B (linha2_1__5), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix1631 (.X (linha3_1__5), .A (x4[5]), .B (x3[5]), .S (
          row_0_rowp_bni2_l)) ;
    MX2T0 ix1643 (.X (linha2_1__5), .A (x1[5]), .B (x2[5]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix2919 (.X (linha1_2__6), .A (linha2_2__6), .B (linha1_1__6), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix2035 (.X (linha2_2__6), .A (linha3_1__6), .B (linha2_1__6), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix1927 (.X (linha3_1__6), .A (x4[6]), .B (x3[6]), .S (
          row_0_rowp_bni2_l)) ;
    MX2T0 ix1939 (.X (linha2_1__6), .A (x1[6]), .B (x2[6]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix2991 (.X (linha1_2__7), .A (linha2_2__7), .B (linha1_1__7), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix2331 (.X (linha2_2__7), .A (linha3_1__7), .B (linha2_1__7), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix2223 (.X (linha3_1__7), .A (x4[7]), .B (x3[7]), .S (
          row_0_rowp_bni2_l)) ;
    MX2T0 ix2235 (.X (linha2_1__7), .A (x1[7]), .B (x2[7]), .S (
          row_0_rowp_bni1_l)) ;
    MX2T0 ix3103 (.X (linha1_3__0), .A (linha2_4__0), .B (linha1_2__0), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2475 (.X (linha2_4__0), .A (linha3_3__0), .B (linha2_3__0), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix247 (.X (linha3_3__0), .A (linha4_2__0), .B (linha3_2__0), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix139 (.X (linha4_2__0), .A (linha5_1__0), .B (linha4_1__0), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix63 (.X (linha5_1__0), .A (x6[0]), .B (x5[0]), .S (row_0_rowp_bni3_l)
          ) ;
    MX2T0 ix75 (.X (linha4_1__0), .A (x3[0]), .B (x4[0]), .S (row_0_rowp_bni2_l)
          ) ;
    MX2T0 ix167 (.X (linha3_2__0), .A (linha2_1__0), .B (linha3_1__0), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix275 (.X (linha2_3__0), .A (linha1_1__0), .B (linha2_2__0), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix3143 (.X (linha1_3__1), .A (linha2_4__1), .B (linha1_2__1), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2547 (.X (linha2_4__1), .A (linha3_3__1), .B (linha2_3__1), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix543 (.X (linha3_3__1), .A (linha4_2__1), .B (linha3_2__1), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix435 (.X (linha4_2__1), .A (linha5_1__1), .B (linha4_1__1), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix359 (.X (linha5_1__1), .A (x6[1]), .B (x5[1]), .S (row_0_rowp_bni3_l
          )) ;
    MX2T0 ix371 (.X (linha4_1__1), .A (x3[1]), .B (x4[1]), .S (row_0_rowp_bni2_l
          )) ;
    MX2T0 ix463 (.X (linha3_2__1), .A (linha2_1__1), .B (linha3_1__1), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix571 (.X (linha2_3__1), .A (linha1_1__1), .B (linha2_2__1), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix3183 (.X (linha1_3__2), .A (linha2_4__2), .B (linha1_2__2), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2619 (.X (linha2_4__2), .A (linha3_3__2), .B (linha2_3__2), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix839 (.X (linha3_3__2), .A (linha4_2__2), .B (linha3_2__2), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix731 (.X (linha4_2__2), .A (linha5_1__2), .B (linha4_1__2), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix655 (.X (linha5_1__2), .A (x6[2]), .B (x5[2]), .S (row_0_rowp_bni3_l
          )) ;
    MX2T0 ix667 (.X (linha4_1__2), .A (x3[2]), .B (x4[2]), .S (row_0_rowp_bni2_l
          )) ;
    MX2T0 ix759 (.X (linha3_2__2), .A (linha2_1__2), .B (linha3_1__2), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix867 (.X (linha2_3__2), .A (linha1_1__2), .B (linha2_2__2), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix3223 (.X (linha1_3__3), .A (linha2_4__3), .B (linha1_2__3), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2691 (.X (linha2_4__3), .A (linha3_3__3), .B (linha2_3__3), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix1135 (.X (linha3_3__3), .A (linha4_2__3), .B (linha3_2__3), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix1027 (.X (linha4_2__3), .A (linha5_1__3), .B (linha4_1__3), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix951 (.X (linha5_1__3), .A (x6[3]), .B (x5[3]), .S (row_0_rowp_bni3_l
          )) ;
    MX2T0 ix963 (.X (linha4_1__3), .A (x3[3]), .B (x4[3]), .S (row_0_rowp_bni2_l
          )) ;
    MX2T0 ix1055 (.X (linha3_2__3), .A (linha2_1__3), .B (linha3_1__3), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix1163 (.X (linha2_3__3), .A (linha1_1__3), .B (linha2_2__3), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix3263 (.X (linha1_3__4), .A (linha2_4__4), .B (linha1_2__4), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2763 (.X (linha2_4__4), .A (linha3_3__4), .B (linha2_3__4), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix1431 (.X (linha3_3__4), .A (linha4_2__4), .B (linha3_2__4), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix1323 (.X (linha4_2__4), .A (linha5_1__4), .B (linha4_1__4), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix1247 (.X (linha5_1__4), .A (x6[4]), .B (x5[4]), .S (
          row_0_rowp_bni3_l)) ;
    MX2T0 ix1259 (.X (linha4_1__4), .A (x3[4]), .B (x4[4]), .S (
          row_0_rowp_bni2_l)) ;
    MX2T0 ix1351 (.X (linha3_2__4), .A (linha2_1__4), .B (linha3_1__4), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix1459 (.X (linha2_3__4), .A (linha1_1__4), .B (linha2_2__4), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix3303 (.X (linha1_3__5), .A (linha2_4__5), .B (linha1_2__5), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2835 (.X (linha2_4__5), .A (linha3_3__5), .B (linha2_3__5), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix1727 (.X (linha3_3__5), .A (linha4_2__5), .B (linha3_2__5), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix1619 (.X (linha4_2__5), .A (linha5_1__5), .B (linha4_1__5), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix1543 (.X (linha5_1__5), .A (x6[5]), .B (x5[5]), .S (
          row_0_rowp_bni3_l)) ;
    MX2T0 ix1555 (.X (linha4_1__5), .A (x3[5]), .B (x4[5]), .S (
          row_0_rowp_bni2_l)) ;
    MX2T0 ix1647 (.X (linha3_2__5), .A (linha2_1__5), .B (linha3_1__5), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix1755 (.X (linha2_3__5), .A (linha1_1__5), .B (linha2_2__5), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix3343 (.X (linha1_3__6), .A (linha2_4__6), .B (linha1_2__6), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2907 (.X (linha2_4__6), .A (linha3_3__6), .B (linha2_3__6), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix2023 (.X (linha3_3__6), .A (linha4_2__6), .B (linha3_2__6), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix1915 (.X (linha4_2__6), .A (linha5_1__6), .B (linha4_1__6), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix1839 (.X (linha5_1__6), .A (x6[6]), .B (x5[6]), .S (
          row_0_rowp_bni3_l)) ;
    MX2T0 ix1851 (.X (linha4_1__6), .A (x3[6]), .B (x4[6]), .S (
          row_0_rowp_bni2_l)) ;
    MX2T0 ix1943 (.X (linha3_2__6), .A (linha2_1__6), .B (linha3_1__6), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix2051 (.X (linha2_3__6), .A (linha1_1__6), .B (linha2_2__6), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix3383 (.X (linha1_3__7), .A (linha2_4__7), .B (linha1_2__7), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2979 (.X (linha2_4__7), .A (linha3_3__7), .B (linha2_3__7), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix2319 (.X (linha3_3__7), .A (linha4_2__7), .B (linha3_2__7), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix2211 (.X (linha4_2__7), .A (linha5_1__7), .B (linha4_1__7), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix2135 (.X (linha5_1__7), .A (x6[7]), .B (x5[7]), .S (
          row_0_rowp_bni3_l)) ;
    MX2T0 ix2147 (.X (linha4_1__7), .A (x3[7]), .B (x4[7]), .S (
          row_0_rowp_bni2_l)) ;
    MX2T0 ix2239 (.X (linha3_2__7), .A (linha2_1__7), .B (linha3_1__7), .S (
          row_1_rowi_bni1_l)) ;
    MX2T0 ix2347 (.X (linha2_3__7), .A (linha1_1__7), .B (linha2_2__7), .S (
          row_2_rowp_bni1_l)) ;
    MX2T0 ix35 (.X (linha8_1__0), .A (x7[0]), .B (x8[0]), .S (row_0_rowp_bni4_l)
          ) ;
    MX2T0 ix331 (.X (linha8_1__1), .A (x7[1]), .B (x8[1]), .S (row_0_rowp_bni4_l
          )) ;
    MX2T0 ix627 (.X (linha8_1__2), .A (x7[2]), .B (x8[2]), .S (row_0_rowp_bni4_l
          )) ;
    MX2T0 ix923 (.X (linha8_1__3), .A (x7[3]), .B (x8[3]), .S (row_0_rowp_bni4_l
          )) ;
    MX2T0 ix1219 (.X (linha8_1__4), .A (x7[4]), .B (x8[4]), .S (
          row_0_rowp_bni4_l)) ;
    MX2T0 ix1515 (.X (linha8_1__5), .A (x7[5]), .B (x8[5]), .S (
          row_0_rowp_bni4_l)) ;
    MX2T0 ix1811 (.X (linha8_1__6), .A (x7[6]), .B (x8[6]), .S (
          row_0_rowp_bni4_l)) ;
    MX2T0 ix2107 (.X (linha8_1__7), .A (x7[7]), .B (x8[7]), .S (
          row_0_rowp_bni4_l)) ;
    MX2T0 ix99 (.X (linha8_2__0), .A (linha7_2__0), .B (linha8_1__0), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix23 (.X (linha7_2__0), .A (linha6_1__0), .B (linha7_1__0), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix19 (.X (linha6_1__0), .A (x5[0]), .B (x6[0]), .S (row_0_rowp_bni3_l)
          ) ;
    MX2T0 ix7 (.X (linha7_1__0), .A (x8[0]), .B (x7[0]), .S (row_0_rowp_bni4_l)
          ) ;
    MX2T0 ix395 (.X (linha8_2__1), .A (linha7_2__1), .B (linha8_1__1), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix319 (.X (linha7_2__1), .A (linha6_1__1), .B (linha7_1__1), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix315 (.X (linha6_1__1), .A (x5[1]), .B (x6[1]), .S (row_0_rowp_bni3_l
          )) ;
    MX2T0 ix303 (.X (linha7_1__1), .A (x8[1]), .B (x7[1]), .S (row_0_rowp_bni4_l
          )) ;
    MX2T0 ix691 (.X (linha8_2__2), .A (linha7_2__2), .B (linha8_1__2), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix615 (.X (linha7_2__2), .A (linha6_1__2), .B (linha7_1__2), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix611 (.X (linha6_1__2), .A (x5[2]), .B (x6[2]), .S (row_0_rowp_bni3_l
          )) ;
    MX2T0 ix599 (.X (linha7_1__2), .A (x8[2]), .B (x7[2]), .S (row_0_rowp_bni4_l
          )) ;
    MX2T0 ix987 (.X (linha8_2__3), .A (linha7_2__3), .B (linha8_1__3), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix911 (.X (linha7_2__3), .A (linha6_1__3), .B (linha7_1__3), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix907 (.X (linha6_1__3), .A (x5[3]), .B (x6[3]), .S (row_0_rowp_bni3_l
          )) ;
    MX2T0 ix895 (.X (linha7_1__3), .A (x8[3]), .B (x7[3]), .S (row_0_rowp_bni4_l
          )) ;
    MX2T0 ix1283 (.X (linha8_2__4), .A (linha7_2__4), .B (linha8_1__4), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix1207 (.X (linha7_2__4), .A (linha6_1__4), .B (linha7_1__4), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix1203 (.X (linha6_1__4), .A (x5[4]), .B (x6[4]), .S (
          row_0_rowp_bni3_l)) ;
    MX2T0 ix1191 (.X (linha7_1__4), .A (x8[4]), .B (x7[4]), .S (
          row_0_rowp_bni4_l)) ;
    MX2T0 ix1579 (.X (linha8_2__5), .A (linha7_2__5), .B (linha8_1__5), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix1503 (.X (linha7_2__5), .A (linha6_1__5), .B (linha7_1__5), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix1499 (.X (linha6_1__5), .A (x5[5]), .B (x6[5]), .S (
          row_0_rowp_bni3_l)) ;
    MX2T0 ix1487 (.X (linha7_1__5), .A (x8[5]), .B (x7[5]), .S (
          row_0_rowp_bni4_l)) ;
    MX2T0 ix1875 (.X (linha8_2__6), .A (linha7_2__6), .B (linha8_1__6), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix1799 (.X (linha7_2__6), .A (linha6_1__6), .B (linha7_1__6), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix1795 (.X (linha6_1__6), .A (x5[6]), .B (x6[6]), .S (
          row_0_rowp_bni3_l)) ;
    MX2T0 ix1783 (.X (linha7_1__6), .A (x8[6]), .B (x7[6]), .S (
          row_0_rowp_bni4_l)) ;
    MX2T0 ix2171 (.X (linha8_2__7), .A (linha7_2__7), .B (linha8_1__7), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix2095 (.X (linha7_2__7), .A (linha6_1__7), .B (linha7_1__7), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix2091 (.X (linha6_1__7), .A (x5[7]), .B (x6[7]), .S (
          row_0_rowp_bni3_l)) ;
    MX2T0 ix2079 (.X (linha7_1__7), .A (x8[7]), .B (x7[7]), .S (
          row_0_rowp_bni4_l)) ;
    MX2T0 ix195 (.X (linha8_3__0), .A (linha7_4__0), .B (linha8_2__0), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix87 (.X (linha7_4__0), .A (linha6_3__0), .B (linha7_3__0), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix83 (.X (linha6_3__0), .A (linha5_2__0), .B (linha6_2__0), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix79 (.X (linha5_2__0), .A (linha4_1__0), .B (linha5_1__0), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix51 (.X (linha6_2__0), .A (linha7_1__0), .B (linha6_1__0), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix39 (.X (linha7_3__0), .A (linha8_1__0), .B (linha7_2__0), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix491 (.X (linha8_3__1), .A (linha7_4__1), .B (linha8_2__1), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix383 (.X (linha7_4__1), .A (linha6_3__1), .B (linha7_3__1), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix379 (.X (linha6_3__1), .A (linha5_2__1), .B (linha6_2__1), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix375 (.X (linha5_2__1), .A (linha4_1__1), .B (linha5_1__1), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix347 (.X (linha6_2__1), .A (linha7_1__1), .B (linha6_1__1), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix335 (.X (linha7_3__1), .A (linha8_1__1), .B (linha7_2__1), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix787 (.X (linha8_3__2), .A (linha7_4__2), .B (linha8_2__2), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix679 (.X (linha7_4__2), .A (linha6_3__2), .B (linha7_3__2), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix675 (.X (linha6_3__2), .A (linha5_2__2), .B (linha6_2__2), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix671 (.X (linha5_2__2), .A (linha4_1__2), .B (linha5_1__2), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix643 (.X (linha6_2__2), .A (linha7_1__2), .B (linha6_1__2), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix631 (.X (linha7_3__2), .A (linha8_1__2), .B (linha7_2__2), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix1083 (.X (linha8_3__3), .A (linha7_4__3), .B (linha8_2__3), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix975 (.X (linha7_4__3), .A (linha6_3__3), .B (linha7_3__3), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix971 (.X (linha6_3__3), .A (linha5_2__3), .B (linha6_2__3), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix967 (.X (linha5_2__3), .A (linha4_1__3), .B (linha5_1__3), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix939 (.X (linha6_2__3), .A (linha7_1__3), .B (linha6_1__3), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix927 (.X (linha7_3__3), .A (linha8_1__3), .B (linha7_2__3), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix1379 (.X (linha8_3__4), .A (linha7_4__4), .B (linha8_2__4), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix1271 (.X (linha7_4__4), .A (linha6_3__4), .B (linha7_3__4), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix1267 (.X (linha6_3__4), .A (linha5_2__4), .B (linha6_2__4), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix1263 (.X (linha5_2__4), .A (linha4_1__4), .B (linha5_1__4), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix1235 (.X (linha6_2__4), .A (linha7_1__4), .B (linha6_1__4), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix1223 (.X (linha7_3__4), .A (linha8_1__4), .B (linha7_2__4), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix1675 (.X (linha8_3__5), .A (linha7_4__5), .B (linha8_2__5), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix1567 (.X (linha7_4__5), .A (linha6_3__5), .B (linha7_3__5), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix1563 (.X (linha6_3__5), .A (linha5_2__5), .B (linha6_2__5), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix1559 (.X (linha5_2__5), .A (linha4_1__5), .B (linha5_1__5), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix1531 (.X (linha6_2__5), .A (linha7_1__5), .B (linha6_1__5), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix1519 (.X (linha7_3__5), .A (linha8_1__5), .B (linha7_2__5), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix1971 (.X (linha8_3__6), .A (linha7_4__6), .B (linha8_2__6), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix1863 (.X (linha7_4__6), .A (linha6_3__6), .B (linha7_3__6), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix1859 (.X (linha6_3__6), .A (linha5_2__6), .B (linha6_2__6), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix1855 (.X (linha5_2__6), .A (linha4_1__6), .B (linha5_1__6), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix1827 (.X (linha6_2__6), .A (linha7_1__6), .B (linha6_1__6), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix1815 (.X (linha7_3__6), .A (linha8_1__6), .B (linha7_2__6), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix2267 (.X (linha8_3__7), .A (linha7_4__7), .B (linha8_2__7), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix2159 (.X (linha7_4__7), .A (linha6_3__7), .B (linha7_3__7), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix2155 (.X (linha6_3__7), .A (linha5_2__7), .B (linha6_2__7), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix2151 (.X (linha5_2__7), .A (linha4_1__7), .B (linha5_1__7), .S (
          row_1_rowi_bni2_l)) ;
    MX2T0 ix2123 (.X (linha6_2__7), .A (linha7_1__7), .B (linha6_1__7), .S (
          row_1_rowi_bni3_l)) ;
    MX2T0 ix2111 (.X (linha7_3__7), .A (linha8_1__7), .B (linha7_2__7), .S (
          row_2_rowp_bni4_l)) ;
    MX2T0 ix2491 (.X (linha2_5__0), .A (linha1_2__0), .B (linha2_4__0), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2563 (.X (linha2_5__1), .A (linha1_2__1), .B (linha2_4__1), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2635 (.X (linha2_5__2), .A (linha1_2__2), .B (linha2_4__2), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2707 (.X (linha2_5__3), .A (linha1_2__3), .B (linha2_4__3), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2779 (.X (linha2_5__4), .A (linha1_2__4), .B (linha2_4__4), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2851 (.X (linha2_5__5), .A (linha1_2__5), .B (linha2_4__5), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2923 (.X (linha2_5__6), .A (linha1_2__6), .B (linha2_4__6), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix2995 (.X (linha2_5__7), .A (linha1_2__7), .B (linha2_4__7), .S (
          row_4_rowp_bni1_l)) ;
    MX2T0 ix3091 (.X (linha2_6__0), .A (linha3_5__0), .B (linha2_5__0), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2463 (.X (linha3_5__0), .A (linha4_4__0), .B (linha3_4__0), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix235 (.X (linha4_4__0), .A (linha5_3__0), .B (linha4_3__0), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix127 (.X (linha5_3__0), .A (linha6_2__0), .B (linha5_2__0), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix171 (.X (linha4_3__0), .A (linha3_2__0), .B (linha4_2__0), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix279 (.X (linha3_4__0), .A (linha2_3__0), .B (linha3_3__0), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix3131 (.X (linha2_6__1), .A (linha3_5__1), .B (linha2_5__1), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2535 (.X (linha3_5__1), .A (linha4_4__1), .B (linha3_4__1), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix531 (.X (linha4_4__1), .A (linha5_3__1), .B (linha4_3__1), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix423 (.X (linha5_3__1), .A (linha6_2__1), .B (linha5_2__1), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix467 (.X (linha4_3__1), .A (linha3_2__1), .B (linha4_2__1), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix575 (.X (linha3_4__1), .A (linha2_3__1), .B (linha3_3__1), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix3171 (.X (linha2_6__2), .A (linha3_5__2), .B (linha2_5__2), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2607 (.X (linha3_5__2), .A (linha4_4__2), .B (linha3_4__2), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix827 (.X (linha4_4__2), .A (linha5_3__2), .B (linha4_3__2), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix719 (.X (linha5_3__2), .A (linha6_2__2), .B (linha5_2__2), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix763 (.X (linha4_3__2), .A (linha3_2__2), .B (linha4_2__2), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix871 (.X (linha3_4__2), .A (linha2_3__2), .B (linha3_3__2), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix3211 (.X (linha2_6__3), .A (linha3_5__3), .B (linha2_5__3), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2679 (.X (linha3_5__3), .A (linha4_4__3), .B (linha3_4__3), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix1123 (.X (linha4_4__3), .A (linha5_3__3), .B (linha4_3__3), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix1015 (.X (linha5_3__3), .A (linha6_2__3), .B (linha5_2__3), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix1059 (.X (linha4_3__3), .A (linha3_2__3), .B (linha4_2__3), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix1167 (.X (linha3_4__3), .A (linha2_3__3), .B (linha3_3__3), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix3251 (.X (linha2_6__4), .A (linha3_5__4), .B (linha2_5__4), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2751 (.X (linha3_5__4), .A (linha4_4__4), .B (linha3_4__4), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix1419 (.X (linha4_4__4), .A (linha5_3__4), .B (linha4_3__4), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix1311 (.X (linha5_3__4), .A (linha6_2__4), .B (linha5_2__4), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix1355 (.X (linha4_3__4), .A (linha3_2__4), .B (linha4_2__4), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix1463 (.X (linha3_4__4), .A (linha2_3__4), .B (linha3_3__4), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix3291 (.X (linha2_6__5), .A (linha3_5__5), .B (linha2_5__5), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2823 (.X (linha3_5__5), .A (linha4_4__5), .B (linha3_4__5), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix1715 (.X (linha4_4__5), .A (linha5_3__5), .B (linha4_3__5), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix1607 (.X (linha5_3__5), .A (linha6_2__5), .B (linha5_2__5), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix1651 (.X (linha4_3__5), .A (linha3_2__5), .B (linha4_2__5), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix1759 (.X (linha3_4__5), .A (linha2_3__5), .B (linha3_3__5), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix3331 (.X (linha2_6__6), .A (linha3_5__6), .B (linha2_5__6), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2895 (.X (linha3_5__6), .A (linha4_4__6), .B (linha3_4__6), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix2011 (.X (linha4_4__6), .A (linha5_3__6), .B (linha4_3__6), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix1903 (.X (linha5_3__6), .A (linha6_2__6), .B (linha5_2__6), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix1947 (.X (linha4_3__6), .A (linha3_2__6), .B (linha4_2__6), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix2055 (.X (linha3_4__6), .A (linha2_3__6), .B (linha3_3__6), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix3371 (.X (linha2_6__7), .A (linha3_5__7), .B (linha2_5__7), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2967 (.X (linha3_5__7), .A (linha4_4__7), .B (linha3_4__7), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix2307 (.X (linha4_4__7), .A (linha5_3__7), .B (linha4_3__7), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix2199 (.X (linha5_3__7), .A (linha6_2__7), .B (linha5_2__7), .S (
          row_2_rowp_bni3_l)) ;
    MX2T0 ix2243 (.X (linha4_3__7), .A (linha3_2__7), .B (linha4_2__7), .S (
          row_2_rowp_bni2_l)) ;
    MX2T0 ix2351 (.X (linha3_4__7), .A (linha2_3__7), .B (linha3_3__7), .S (
          row_3_rowi_bni1_l)) ;
    MX2T0 ix3107 (.X (linha2_7__0), .A (linha1_3__0), .B (linha2_6__0), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3147 (.X (linha2_7__1), .A (linha1_3__1), .B (linha2_6__1), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3187 (.X (linha2_7__2), .A (linha1_3__2), .B (linha2_6__2), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3227 (.X (linha2_7__3), .A (linha1_3__3), .B (linha2_6__3), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3267 (.X (linha2_7__4), .A (linha1_3__4), .B (linha2_6__4), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3307 (.X (linha2_7__5), .A (linha1_3__5), .B (linha2_6__5), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3347 (.X (linha2_7__6), .A (linha1_3__6), .B (linha2_6__6), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3387 (.X (linha2_7__7), .A (linha1_3__7), .B (linha2_6__7), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix2495 (.X (linha3_6__0), .A (linha2_5__0), .B (linha3_5__0), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2567 (.X (linha3_6__1), .A (linha2_5__1), .B (linha3_5__1), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2639 (.X (linha3_6__2), .A (linha2_5__2), .B (linha3_5__2), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2711 (.X (linha3_6__3), .A (linha2_5__3), .B (linha3_5__3), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2783 (.X (linha3_6__4), .A (linha2_5__4), .B (linha3_5__4), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2855 (.X (linha3_6__5), .A (linha2_5__5), .B (linha3_5__5), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2927 (.X (linha3_6__6), .A (linha2_5__6), .B (linha3_5__6), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix2999 (.X (linha3_6__7), .A (linha2_5__7), .B (linha3_5__7), .S (
          row_5_rowi_bni1_l)) ;
    MX2T0 ix3079 (.X (linha3_7__0), .A (linha4_6__0), .B (linha3_6__0), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2451 (.X (linha4_6__0), .A (linha5_5__0), .B (linha4_5__0), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix223 (.X (linha5_5__0), .A (linha6_4__0), .B (linha5_4__0), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix115 (.X (linha6_4__0), .A (linha7_3__0), .B (linha6_3__0), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix175 (.X (linha5_4__0), .A (linha4_3__0), .B (linha5_3__0), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix283 (.X (linha4_5__0), .A (linha3_4__0), .B (linha4_4__0), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix3119 (.X (linha3_7__1), .A (linha4_6__1), .B (linha3_6__1), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2523 (.X (linha4_6__1), .A (linha5_5__1), .B (linha4_5__1), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix519 (.X (linha5_5__1), .A (linha6_4__1), .B (linha5_4__1), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix411 (.X (linha6_4__1), .A (linha7_3__1), .B (linha6_3__1), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix471 (.X (linha5_4__1), .A (linha4_3__1), .B (linha5_3__1), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix579 (.X (linha4_5__1), .A (linha3_4__1), .B (linha4_4__1), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix3159 (.X (linha3_7__2), .A (linha4_6__2), .B (linha3_6__2), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2595 (.X (linha4_6__2), .A (linha5_5__2), .B (linha4_5__2), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix815 (.X (linha5_5__2), .A (linha6_4__2), .B (linha5_4__2), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix707 (.X (linha6_4__2), .A (linha7_3__2), .B (linha6_3__2), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix767 (.X (linha5_4__2), .A (linha4_3__2), .B (linha5_3__2), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix875 (.X (linha4_5__2), .A (linha3_4__2), .B (linha4_4__2), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix3199 (.X (linha3_7__3), .A (linha4_6__3), .B (linha3_6__3), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2667 (.X (linha4_6__3), .A (linha5_5__3), .B (linha4_5__3), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix1111 (.X (linha5_5__3), .A (linha6_4__3), .B (linha5_4__3), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix1003 (.X (linha6_4__3), .A (linha7_3__3), .B (linha6_3__3), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix1063 (.X (linha5_4__3), .A (linha4_3__3), .B (linha5_3__3), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix1171 (.X (linha4_5__3), .A (linha3_4__3), .B (linha4_4__3), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix3239 (.X (linha3_7__4), .A (linha4_6__4), .B (linha3_6__4), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2739 (.X (linha4_6__4), .A (linha5_5__4), .B (linha4_5__4), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix1407 (.X (linha5_5__4), .A (linha6_4__4), .B (linha5_4__4), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix1299 (.X (linha6_4__4), .A (linha7_3__4), .B (linha6_3__4), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix1359 (.X (linha5_4__4), .A (linha4_3__4), .B (linha5_3__4), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix1467 (.X (linha4_5__4), .A (linha3_4__4), .B (linha4_4__4), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix3279 (.X (linha3_7__5), .A (linha4_6__5), .B (linha3_6__5), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2811 (.X (linha4_6__5), .A (linha5_5__5), .B (linha4_5__5), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix1703 (.X (linha5_5__5), .A (linha6_4__5), .B (linha5_4__5), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix1595 (.X (linha6_4__5), .A (linha7_3__5), .B (linha6_3__5), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix1655 (.X (linha5_4__5), .A (linha4_3__5), .B (linha5_3__5), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix1763 (.X (linha4_5__5), .A (linha3_4__5), .B (linha4_4__5), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix3319 (.X (linha3_7__6), .A (linha4_6__6), .B (linha3_6__6), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2883 (.X (linha4_6__6), .A (linha5_5__6), .B (linha4_5__6), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix1999 (.X (linha5_5__6), .A (linha6_4__6), .B (linha5_4__6), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix1891 (.X (linha6_4__6), .A (linha7_3__6), .B (linha6_3__6), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix1951 (.X (linha5_4__6), .A (linha4_3__6), .B (linha5_3__6), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix2059 (.X (linha4_5__6), .A (linha3_4__6), .B (linha4_4__6), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix3359 (.X (linha3_7__7), .A (linha4_6__7), .B (linha3_6__7), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2955 (.X (linha4_6__7), .A (linha5_5__7), .B (linha4_5__7), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix2295 (.X (linha5_5__7), .A (linha6_4__7), .B (linha5_4__7), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix2187 (.X (linha6_4__7), .A (linha7_3__7), .B (linha6_3__7), .S (
          row_3_rowi_bni3_l)) ;
    MX2T0 ix2247 (.X (linha5_4__7), .A (linha4_3__7), .B (linha5_3__7), .S (
          row_3_rowi_bni2_l)) ;
    MX2T0 ix2355 (.X (linha4_5__7), .A (linha3_4__7), .B (linha4_4__7), .S (
          row_4_rowp_bni2_l)) ;
    MX2T0 ix2499 (.X (linha4_7__0), .A (linha3_6__0), .B (linha4_6__0), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2571 (.X (linha4_7__1), .A (linha3_6__1), .B (linha4_6__1), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2643 (.X (linha4_7__2), .A (linha3_6__2), .B (linha4_6__2), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2715 (.X (linha4_7__3), .A (linha3_6__3), .B (linha4_6__3), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2787 (.X (linha4_7__4), .A (linha3_6__4), .B (linha4_6__4), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2859 (.X (linha4_7__5), .A (linha3_6__5), .B (linha4_6__5), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix2931 (.X (linha4_7__6), .A (linha3_6__6), .B (linha4_6__6), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix3003 (.X (linha4_7__7), .A (linha3_6__7), .B (linha4_6__7), .S (
          row_6_rowp_bni2_l)) ;
    MX2T0 ix287 (.X (linha5_6__0), .A (linha4_5__0), .B (linha5_5__0), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix583 (.X (linha5_6__1), .A (linha4_5__1), .B (linha5_5__1), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix879 (.X (linha5_6__2), .A (linha4_5__2), .B (linha5_5__2), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix1175 (.X (linha5_6__3), .A (linha4_5__3), .B (linha5_5__3), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix1471 (.X (linha5_6__4), .A (linha4_5__4), .B (linha5_5__4), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix1767 (.X (linha5_6__5), .A (linha4_5__5), .B (linha5_5__5), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix2063 (.X (linha5_6__6), .A (linha4_5__6), .B (linha5_5__6), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix2359 (.X (linha5_6__7), .A (linha4_5__7), .B (linha5_5__7), .S (
          row_5_rowi_bni2_l)) ;
    MX2T0 ix2439 (.X (linha5_7__0), .A (linha6_6__0), .B (linha5_6__0), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix211 (.X (linha6_6__0), .A (linha7_5__0), .B (linha6_5__0), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix103 (.X (linha7_5__0), .A (linha8_2__0), .B (linha7_4__0), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix179 (.X (linha6_5__0), .A (linha5_4__0), .B (linha6_4__0), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix2511 (.X (linha5_7__1), .A (linha6_6__1), .B (linha5_6__1), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix507 (.X (linha6_6__1), .A (linha7_5__1), .B (linha6_5__1), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix399 (.X (linha7_5__1), .A (linha8_2__1), .B (linha7_4__1), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix475 (.X (linha6_5__1), .A (linha5_4__1), .B (linha6_4__1), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix2583 (.X (linha5_7__2), .A (linha6_6__2), .B (linha5_6__2), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix803 (.X (linha6_6__2), .A (linha7_5__2), .B (linha6_5__2), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix695 (.X (linha7_5__2), .A (linha8_2__2), .B (linha7_4__2), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix771 (.X (linha6_5__2), .A (linha5_4__2), .B (linha6_4__2), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix2655 (.X (linha5_7__3), .A (linha6_6__3), .B (linha5_6__3), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix1099 (.X (linha6_6__3), .A (linha7_5__3), .B (linha6_5__3), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix991 (.X (linha7_5__3), .A (linha8_2__3), .B (linha7_4__3), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix1067 (.X (linha6_5__3), .A (linha5_4__3), .B (linha6_4__3), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix2727 (.X (linha5_7__4), .A (linha6_6__4), .B (linha5_6__4), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix1395 (.X (linha6_6__4), .A (linha7_5__4), .B (linha6_5__4), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix1287 (.X (linha7_5__4), .A (linha8_2__4), .B (linha7_4__4), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix1363 (.X (linha6_5__4), .A (linha5_4__4), .B (linha6_4__4), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix2799 (.X (linha5_7__5), .A (linha6_6__5), .B (linha5_6__5), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix1691 (.X (linha6_6__5), .A (linha7_5__5), .B (linha6_5__5), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix1583 (.X (linha7_5__5), .A (linha8_2__5), .B (linha7_4__5), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix1659 (.X (linha6_5__5), .A (linha5_4__5), .B (linha6_4__5), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix2871 (.X (linha5_7__6), .A (linha6_6__6), .B (linha5_6__6), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix1987 (.X (linha6_6__6), .A (linha7_5__6), .B (linha6_5__6), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix1879 (.X (linha7_5__6), .A (linha8_2__6), .B (linha7_4__6), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix1955 (.X (linha6_5__6), .A (linha5_4__6), .B (linha6_4__6), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix2943 (.X (linha5_7__7), .A (linha6_6__7), .B (linha5_6__7), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix2283 (.X (linha6_6__7), .A (linha7_5__7), .B (linha6_5__7), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix2175 (.X (linha7_5__7), .A (linha8_2__7), .B (linha7_4__7), .S (
          row_4_rowp_bni4_l)) ;
    MX2T0 ix2251 (.X (linha6_5__7), .A (linha5_4__7), .B (linha6_4__7), .S (
          row_4_rowp_bni3_l)) ;
    MX2T0 ix291 (.X (linha6_7__0), .A (linha5_6__0), .B (linha6_6__0), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix587 (.X (linha6_7__1), .A (linha5_6__1), .B (linha6_6__1), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix883 (.X (linha6_7__2), .A (linha5_6__2), .B (linha6_6__2), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix1179 (.X (linha6_7__3), .A (linha5_6__3), .B (linha6_6__3), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix1475 (.X (linha6_7__4), .A (linha5_6__4), .B (linha6_6__4), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix1771 (.X (linha6_7__5), .A (linha5_6__5), .B (linha6_6__5), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix2067 (.X (linha6_7__6), .A (linha5_6__6), .B (linha6_6__6), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix2363 (.X (linha6_7__7), .A (linha5_6__7), .B (linha6_6__7), .S (
          row_6_rowp_bni3_l)) ;
    MX2T0 ix183 (.X (linha7_6__0), .A (linha6_5__0), .B (linha7_5__0), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix479 (.X (linha7_6__1), .A (linha6_5__1), .B (linha7_5__1), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix775 (.X (linha7_6__2), .A (linha6_5__2), .B (linha7_5__2), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix1071 (.X (linha7_6__3), .A (linha6_5__3), .B (linha7_5__3), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix1367 (.X (linha7_6__4), .A (linha6_5__4), .B (linha7_5__4), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix1663 (.X (linha7_6__5), .A (linha6_5__5), .B (linha7_5__5), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix1959 (.X (linha7_6__6), .A (linha6_5__6), .B (linha7_5__6), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix2255 (.X (linha7_6__7), .A (linha6_5__7), .B (linha7_5__7), .S (
          row_5_rowi_bni3_l)) ;
    MX2T0 ix199 (.X (linha7_7__0), .A (linha8_3__0), .B (linha7_6__0), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix495 (.X (linha7_7__1), .A (linha8_3__1), .B (linha7_6__1), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix791 (.X (linha7_7__2), .A (linha8_3__2), .B (linha7_6__2), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix1087 (.X (linha7_7__3), .A (linha8_3__3), .B (linha7_6__3), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix1383 (.X (linha7_7__4), .A (linha8_3__4), .B (linha7_6__4), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix1679 (.X (linha7_7__5), .A (linha8_3__5), .B (linha7_6__5), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix1975 (.X (linha7_7__6), .A (linha8_3__6), .B (linha7_6__6), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix2271 (.X (linha7_7__7), .A (linha8_3__7), .B (linha7_6__7), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix3527 (.X (y1[0]), .A (linha2_6__0), .B (linha1_3__0), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3535 (.X (y1[1]), .A (linha2_6__1), .B (linha1_3__1), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3543 (.X (y1[2]), .A (linha2_6__2), .B (linha1_3__2), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3551 (.X (y1[3]), .A (linha2_6__3), .B (linha1_3__3), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3559 (.X (y1[4]), .A (linha2_6__4), .B (linha1_3__4), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3567 (.X (y1[5]), .A (linha2_6__5), .B (linha1_3__5), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3575 (.X (y1[6]), .A (linha2_6__6), .B (linha1_3__6), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3583 (.X (y1[7]), .A (linha2_6__7), .B (linha1_3__7), .S (
          row_6_rowp_bni1_l)) ;
    MX2T0 ix3399 (.X (y2[0]), .A (linha3_7__0), .B (linha2_7__0), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3407 (.X (y2[1]), .A (linha3_7__1), .B (linha2_7__1), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3415 (.X (y2[2]), .A (linha3_7__2), .B (linha2_7__2), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3423 (.X (y2[3]), .A (linha3_7__3), .B (linha2_7__3), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3431 (.X (y2[4]), .A (linha3_7__4), .B (linha2_7__4), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3439 (.X (y2[5]), .A (linha3_7__5), .B (linha2_7__5), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3447 (.X (y2[6]), .A (linha3_7__6), .B (linha2_7__6), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3455 (.X (y2[7]), .A (linha3_7__7), .B (linha2_7__7), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3111 (.X (y3[0]), .A (linha2_7__0), .B (linha3_7__0), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3151 (.X (y3[1]), .A (linha2_7__1), .B (linha3_7__1), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3191 (.X (y3[2]), .A (linha2_7__2), .B (linha3_7__2), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3231 (.X (y3[3]), .A (linha2_7__3), .B (linha3_7__3), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3271 (.X (y3[4]), .A (linha2_7__4), .B (linha3_7__4), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3311 (.X (y3[5]), .A (linha2_7__5), .B (linha3_7__5), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3351 (.X (y3[6]), .A (linha2_7__6), .B (linha3_7__6), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3391 (.X (y3[7]), .A (linha2_7__7), .B (linha3_7__7), .S (
          row_7_rowi_bni1_l)) ;
    MX2T0 ix3015 (.X (y4[0]), .A (linha5_7__0), .B (linha4_7__0), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix3023 (.X (y4[1]), .A (linha5_7__1), .B (linha4_7__1), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix3031 (.X (y4[2]), .A (linha5_7__2), .B (linha4_7__2), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix3039 (.X (y4[3]), .A (linha5_7__3), .B (linha4_7__3), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix3047 (.X (y4[4]), .A (linha5_7__4), .B (linha4_7__4), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix3055 (.X (y4[5]), .A (linha5_7__5), .B (linha4_7__5), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix3063 (.X (y4[6]), .A (linha5_7__6), .B (linha4_7__6), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix3071 (.X (y4[7]), .A (linha5_7__7), .B (linha4_7__7), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix2503 (.X (y5[0]), .A (linha4_7__0), .B (linha5_7__0), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix2575 (.X (y5[1]), .A (linha4_7__1), .B (linha5_7__1), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix2647 (.X (y5[2]), .A (linha4_7__2), .B (linha5_7__2), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix2719 (.X (y5[3]), .A (linha4_7__3), .B (linha5_7__3), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix2791 (.X (y5[4]), .A (linha4_7__4), .B (linha5_7__4), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix2863 (.X (y5[5]), .A (linha4_7__5), .B (linha5_7__5), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix2935 (.X (y5[6]), .A (linha4_7__6), .B (linha5_7__6), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix3007 (.X (y5[7]), .A (linha4_7__7), .B (linha5_7__7), .S (
          row_7_rowi_bni2_l)) ;
    MX2T0 ix2375 (.X (y6[0]), .A (linha7_7__0), .B (linha6_7__0), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix2383 (.X (y6[1]), .A (linha7_7__1), .B (linha6_7__1), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix2391 (.X (y6[2]), .A (linha7_7__2), .B (linha6_7__2), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix2399 (.X (y6[3]), .A (linha7_7__3), .B (linha6_7__3), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix2407 (.X (y6[4]), .A (linha7_7__4), .B (linha6_7__4), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix2415 (.X (y6[5]), .A (linha7_7__5), .B (linha6_7__5), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix2423 (.X (y6[6]), .A (linha7_7__6), .B (linha6_7__6), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix2431 (.X (y6[7]), .A (linha7_7__7), .B (linha6_7__7), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix295 (.X (y7[0]), .A (linha6_7__0), .B (linha7_7__0), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix591 (.X (y7[1]), .A (linha6_7__1), .B (linha7_7__1), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix887 (.X (y7[2]), .A (linha6_7__2), .B (linha7_7__2), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix1183 (.X (y7[3]), .A (linha6_7__3), .B (linha7_7__3), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix1479 (.X (y7[4]), .A (linha6_7__4), .B (linha7_7__4), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix1775 (.X (y7[5]), .A (linha6_7__5), .B (linha7_7__5), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix2071 (.X (y7[6]), .A (linha6_7__6), .B (linha7_7__6), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix2367 (.X (y7[7]), .A (linha6_7__7), .B (linha7_7__7), .S (
          row_7_rowi_bni3_l)) ;
    MX2T0 ix3463 (.X (y8[0]), .A (linha7_6__0), .B (linha8_3__0), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix3471 (.X (y8[1]), .A (linha7_6__1), .B (linha8_3__1), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix3479 (.X (y8[2]), .A (linha7_6__2), .B (linha8_3__2), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix3487 (.X (y8[3]), .A (linha7_6__3), .B (linha8_3__3), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix3495 (.X (y8[4]), .A (linha7_6__4), .B (linha8_3__4), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix3503 (.X (y8[5]), .A (linha7_6__5), .B (linha8_3__5), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix3511 (.X (y8[6]), .A (linha7_6__6), .B (linha8_3__6), .S (
          row_6_rowp_bni4_l)) ;
    MX2T0 ix3519 (.X (y8[7]), .A (linha7_6__7), .B (linha8_3__7), .S (
          row_6_rowp_bni4_l)) ;
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

