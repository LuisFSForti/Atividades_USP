//
// Verilog description for cell ordenador, 
// 06/12/24 10:25:25
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module ordenador ( y8, y7, y6, y5, y4, y3, y2, y1, x8, x7, x6, x5, x4, x3, x2, 
                   x1 ) ;

    output [1:0]y8 ;
    output [1:0]y7 ;
    output [1:0]y6 ;
    output [1:0]y5 ;
    output [1:0]y4 ;
    output [1:0]y3 ;
    output [1:0]y2 ;
    output [1:0]y1 ;
    input [1:0]x8 ;
    input [1:0]x7 ;
    input [1:0]x6 ;
    input [1:0]x5 ;
    input [1:0]x4 ;
    input [1:0]x3 ;
    input [1:0]x2 ;
    input [1:0]x1 ;

    wire nx14, nx22, nx38, nx54, nx78, nx86, nx94, nx102, nx114, nx120, nx134, 
         nx142, nx150, nx166, nx186, nx206, nx214, nx226, nx234, nx246, nx254, 
         nx262, nx286, nx294, nx302, nx310, nx322, nx328, nx342, nx350, nx358, 
         nx366, nx374, nx390, nx410, nx430, nx438, nx450, nx458, nx470, nx478, 
         nx490, nx510, nx518, nx530, nx538, nx550, nx558, nx566, nx590, nx598, 
         nx606, nx614, nx626, nx632, nx646, nx654, nx662, nx670, nx678, nx686, 
         nx694, nx706, nx714, nx726, nx734, nx746, nx766, nx774, nx786, nx794, 
         nx806, nx814, nx826, nx846, nx854, nx866, nx874, nx886, nx894, nx902, 
         nx926, nx966, nx974, nx982, nx990, nx998, nx1010, nx1018, nx1030, 
         nx1038, nx1050, nx1070, nx1078, nx1090, nx1098, nx1110, nx1118, nx1126, 
         nx1150, nx1190, nx1198, nx1206, nx1218, nx1226, nx1238, nx1246, nx1254, 
         nx1278, nx331, nx333, nx337, nx341, nx345, nx347, nx349, nx351, nx353, 
         nx357, nx359, nx361, nx363, nx367, nx369, nx373, nx379, nx383, nx385, 
         nx387, nx389, nx391, nx395, nx397, nx401, nx407, nx409, nx413, nx415, 
         nx417, nx421, nx425, nx427, nx429, nx431, nx433, nx437, nx439, nx443, 
         nx451, nx453, nx457, nx459, nx465, nx467, nx471, nx477, nx485, nx487, 
         nx491, nx493, nx495, nx501, nx503, nx507, nx517, nx519, nx523, nx525, 
         nx527, nx537, nx539, nx543, nx545, nx549, nx551, nx555, nx559, nx563, 
         nx565, nx569, nx575, nx579, nx583, nx589, nx591, nx595, nx599, nx601, 
         nx607, nx611, nx615, nx625, nx627, nx631, nx633, nx635, nx641, nx643, 
         nx647, nx655, nx657, nx661, nx663, nx665, nx675, nx677, nx681, nx691, 
         nx695, nx701, nx709, nx713, nx715, nx721, nx723, nx727, nx739, nx741, 
         nx745, nx747, nx749, nx755, nx757, nx761, nx771, nx777, nx779, nx783, 
         nx787, nx789, nx795, nx797, nx801, nx805, nx827;



    MX2L0 ix1335 (.X (y1[0]), .A (nx331), .B (nx559), .S (nx1238)) ;
    MX2L0 ix334 (.X (nx333), .A (nx786), .B (nx794), .S (nx806)) ;
    MX2L0 ix787 (.X (nx786), .A (nx337), .B (nx417), .S (nx510)) ;
    MX2L0 ix338 (.X (nx337), .A (nx226), .B (nx234), .S (nx246)) ;
    MX2L0 ix227 (.X (nx226), .A (nx341), .B (nx353), .S (nx78)) ;
    MX2L0 ix342 (.X (nx341), .A (x8[0]), .B (x7[0]), .S (nx14)) ;
    OAI1A0 ix15 (.X (nx14), .A1 (x7[1]), .A2 (nx345), .B (nx347)) ;
    IV1N0 ix346 (.X (nx345), .A (x8[1])) ;
    OAI3N0 ix348 (.X (nx347), .A1 (x8[1]), .A2 (nx349), .B1 (x8[0]), .B2 (nx351)
           ) ;
    IV1N0 ix350 (.X (nx349), .A (x7[1])) ;
    IV1N0 ix352 (.X (nx351), .A (x7[0])) ;
    MX2L0 ix354 (.X (nx353), .A (x5[0]), .B (x6[0]), .S (nx38)) ;
    OAI1A0 ix39 (.X (nx38), .A1 (x5[1]), .A2 (nx357), .B (nx359)) ;
    IV1N0 ix358 (.X (nx357), .A (x6[1])) ;
    OAI3N0 ix360 (.X (nx359), .A1 (x6[1]), .A2 (nx361), .B1 (x6[0]), .B2 (nx363)
           ) ;
    IV1N0 ix362 (.X (nx361), .A (x5[1])) ;
    IV1N0 ix364 (.X (nx363), .A (x5[0])) ;
    AOA4I0 ix79 (.X (nx78), .A1 (x5[1]), .A2 (x6[1]), .B (nx367), .C (nx369)) ;
    NR2R0 ix368 (.X (nx367), .A1 (x8[1]), .A2 (x7[1])) ;
    OAI3N0 ix370 (.X (nx369), .A1 (nx54), .A2 (nx373), .B1 (nx22), .B2 (nx353)
           ) ;
    ND2N0 ix374 (.X (nx373), .A1 (x5[1]), .A2 (x6[1])) ;
    MX2L0 ix235 (.X (nx234), .A (nx379), .B (nx391), .S (nx206)) ;
    MX2L0 ix380 (.X (nx379), .A (x3[0]), .B (x4[0]), .S (nx166)) ;
    OAI1A0 ix167 (.X (nx166), .A1 (x3[1]), .A2 (nx383), .B (nx385)) ;
    IV1N0 ix384 (.X (nx383), .A (x4[1])) ;
    OAI3N0 ix386 (.X (nx385), .A1 (x4[1]), .A2 (nx387), .B1 (x4[0]), .B2 (nx389)
           ) ;
    IV1N0 ix388 (.X (nx387), .A (x3[1])) ;
    IV1N0 ix390 (.X (nx389), .A (x3[0])) ;
    MX2L0 ix392 (.X (nx391), .A (x6[0]), .B (x5[0]), .S (nx38)) ;
    AOA4I0 ix207 (.X (nx206), .A1 (x3[1]), .A2 (x4[1]), .B (nx395), .C (nx397)
           ) ;
    NR2R0 ix396 (.X (nx395), .A1 (x6[1]), .A2 (x5[1])) ;
    OAI3N0 ix398 (.X (nx397), .A1 (nx150), .A2 (nx401), .B1 (nx186), .B2 (nx379)
           ) ;
    ND2N0 ix402 (.X (nx401), .A1 (x3[1]), .A2 (x4[1])) ;
    OAI1A0 ix247 (.X (nx246), .A1 (nx214), .A2 (nx407), .B (nx409)) ;
    NR2R0 ix215 (.X (nx214), .A1 (nx401), .A2 (nx395)) ;
    OAI3N0 ix410 (.X (nx409), .A1 (nx142), .A2 (nx413), .B1 (nx226), .B2 (nx415)
           ) ;
    ND2N0 ix143 (.X (nx142), .A1 (nx367), .A2 (nx373)) ;
    MX2L0 ix418 (.X (nx417), .A (nx458), .B (nx450), .S (nx470)) ;
    MX2L0 ix459 (.X (nx458), .A (nx421), .B (nx433), .S (nx430)) ;
    MX2L0 ix422 (.X (nx421), .A (x1[0]), .B (x2[0]), .S (nx390)) ;
    OAI1A0 ix391 (.X (nx390), .A1 (x1[1]), .A2 (nx425), .B (nx427)) ;
    IV1N0 ix426 (.X (nx425), .A (x2[1])) ;
    OAI3N0 ix428 (.X (nx427), .A1 (x2[1]), .A2 (nx429), .B1 (x2[0]), .B2 (nx431)
           ) ;
    IV1N0 ix430 (.X (nx429), .A (x1[1])) ;
    IV1N0 ix432 (.X (nx431), .A (x1[0])) ;
    MX2L0 ix434 (.X (nx433), .A (x4[0]), .B (x3[0]), .S (nx166)) ;
    AOA4I0 ix431 (.X (nx430), .A1 (x1[1]), .A2 (x2[1]), .B (nx437), .C (nx439)
           ) ;
    NR2R0 ix438 (.X (nx437), .A1 (x4[1]), .A2 (x3[1])) ;
    OAI3N0 ix440 (.X (nx439), .A1 (nx374), .A2 (nx443), .B1 (nx410), .B2 (nx421)
           ) ;
    ND2N0 ix444 (.X (nx443), .A1 (x1[1]), .A2 (x2[1])) ;
    MX2L0 ix451 (.X (nx450), .A (nx391), .B (nx379), .S (nx206)) ;
    OAI1A0 ix471 (.X (nx470), .A1 (nx438), .A2 (nx451), .B (nx453)) ;
    NR2R0 ix439 (.X (nx438), .A1 (nx443), .A2 (nx437)) ;
    OAI3N0 ix454 (.X (nx453), .A1 (nx366), .A2 (nx457), .B1 (nx450), .B2 (nx459)
           ) ;
    ND2N0 ix367 (.X (nx366), .A1 (nx395), .A2 (nx401)) ;
    OAI1A0 ix511 (.X (nx510), .A1 (nx478), .A2 (nx465), .B (nx467)) ;
    NR2R0 ix466 (.X (nx465), .A1 (nx142), .A2 (nx214)) ;
    OAI3N0 ix468 (.X (nx467), .A1 (nx358), .A2 (nx471), .B1 (nx490), .B2 (nx417)
           ) ;
    ND2N0 ix472 (.X (nx471), .A1 (nx438), .A2 (nx366)) ;
    MX2L0 ix795 (.X (nx794), .A (nx477), .B (nx495), .S (nx766)) ;
    MX2L0 ix478 (.X (nx477), .A (nx714), .B (nx706), .S (nx726)) ;
    MX2L0 ix707 (.X (nx706), .A (nx433), .B (nx421), .S (nx430)) ;
    OAI3R1 ix727 (.X (nx726), .A1 (x2[1]), .A2 (x1[1]), .A3 (nx485), .B (nx487)
           ) ;
    OAI3N0 ix488 (.X (nx487), .A1 (nx686), .A2 (nx491), .B1 (nx706), .B2 (nx493)
           ) ;
    ND2N0 ix687 (.X (nx686), .A1 (nx437), .A2 (nx443)) ;
    NR2R0 ix492 (.X (nx491), .A1 (x2[1]), .A2 (x1[1])) ;
    MX2L0 ix494 (.X (nx493), .A (x2[0]), .B (x1[0]), .S (nx390)) ;
    MX2L0 ix496 (.X (nx495), .A (nx450), .B (nx458), .S (nx470)) ;
    OAI1A0 ix767 (.X (nx766), .A1 (nx734), .A2 (nx501), .B (nx503)) ;
    NR2R0 ix502 (.X (nx501), .A1 (nx366), .A2 (nx438)) ;
    OAI3N0 ix504 (.X (nx503), .A1 (nx678), .A2 (nx507), .B1 (nx746), .B2 (nx477)
           ) ;
    ND2N0 ix508 (.X (nx507), .A1 (nx694), .A2 (nx686)) ;
    OAI1A0 ix807 (.X (nx806), .A1 (nx774), .A2 (nx517), .B (nx519)) ;
    NR2R0 ix775 (.X (nx774), .A1 (nx507), .A2 (nx501)) ;
    OAI3N0 ix520 (.X (nx519), .A1 (nx670), .A2 (nx523), .B1 (nx786), .B2 (nx525)
           ) ;
    ND2N0 ix671 (.X (nx670), .A1 (nx465), .A2 (nx471)) ;
    MX2L0 ix528 (.X (nx527), .A (nx1018), .B (nx1010), .S (nx1030)) ;
    MX2L0 ix1011 (.X (nx1010), .A (nx495), .B (nx477), .S (nx766)) ;
    OAI1A0 ix1031 (.X (nx1030), .A1 (nx998), .A2 (nx537), .B (nx539)) ;
    ND2N0 ix999 (.X (nx998), .A1 (nx485), .A2 (nx491)) ;
    OAI3N0 ix540 (.X (nx539), .A1 (nx990), .A2 (nx543), .B1 (nx1010), .B2 (nx545
           )) ;
    ND2N0 ix991 (.X (nx990), .A1 (nx501), .A2 (nx507)) ;
    MX2L0 ix546 (.X (nx545), .A (nx706), .B (nx714), .S (nx726)) ;
    OAI1A0 ix1071 (.X (nx1070), .A1 (nx1038), .A2 (nx549), .B (nx551)) ;
    NR2R0 ix550 (.X (nx549), .A1 (nx670), .A2 (nx774)) ;
    OAI3N0 ix552 (.X (nx551), .A1 (nx982), .A2 (nx555), .B1 (nx1050), .B2 (nx527
           )) ;
    ND2N0 ix556 (.X (nx555), .A1 (nx998), .A2 (nx990)) ;
    MX2L0 ix560 (.X (nx559), .A (nx1010), .B (nx1018), .S (nx1030)) ;
    OAI1A0 ix1239 (.X (nx1238), .A1 (nx1206), .A2 (nx563), .B (nx565)) ;
    OAI3N0 ix566 (.X (nx565), .A1 (nx1198), .A2 (nx569), .B1 (nx1218), .B2 (
           nx559)) ;
    ND2N0 ix1199 (.X (nx1198), .A1 (nx549), .A2 (nx555)) ;
    NR2R0 ix570 (.X (nx569), .A1 (nx990), .A2 (nx998)) ;
    MX2L0 ix1219 (.X (nx1218), .A (nx333), .B (nx527), .S (nx1070)) ;
    ND2N0 ix1343 (.X (y1[1]), .A1 (nx563), .A2 (nx569)) ;
    MX2L0 ix1303 (.X (y2[0]), .A (nx575), .B (nx665), .S (nx1278)) ;
    MX2L0 ix576 (.X (nx575), .A (nx1090), .B (nx1098), .S (nx1110)) ;
    MX2L0 ix1091 (.X (nx1090), .A (nx579), .B (nx635), .S (nx846)) ;
    MX2L0 ix580 (.X (nx579), .A (nx530), .B (nx538), .S (nx550)) ;
    MX2L0 ix531 (.X (nx530), .A (nx583), .B (nx601), .S (nx286)) ;
    MX2L0 ix584 (.X (nx583), .A (nx86), .B (nx114), .S (nx589)) ;
    MX2L0 ix87 (.X (nx86), .A (nx353), .B (nx341), .S (nx78)) ;
    AO3I0 ix590 (.X (nx589), .A1 (nx591), .A2 (x7[1]), .A3 (x8[1]), .B (nx120)
          ) ;
    AO2L0 ix121 (.X (nx120), .A1 (nx595), .A2 (nx94), .B1 (nx86), .B2 (nx599)) ;
    ND2N0 ix596 (.X (nx595), .A1 (x7[1]), .A2 (x8[1])) ;
    NR2R0 ix95 (.X (nx94), .A1 (nx373), .A2 (nx367)) ;
    MX2L0 ix600 (.X (nx599), .A (x7[0]), .B (x8[0]), .S (nx14)) ;
    MX2L0 ix602 (.X (nx601), .A (nx234), .B (nx226), .S (nx246)) ;
    OAI1A0 ix287 (.X (nx286), .A1 (nx254), .A2 (nx607), .B (nx611)) ;
    NR2R0 ix608 (.X (nx607), .A1 (nx102), .A2 (nx94)) ;
    OAI3N0 ix612 (.X (nx611), .A1 (nx262), .A2 (nx615), .B1 (nx134), .B2 (nx601)
           ) ;
    ND2N0 ix616 (.X (nx615), .A1 (nx214), .A2 (nx142)) ;
    MX2L0 ix539 (.X (nx538), .A (nx417), .B (nx337), .S (nx510)) ;
    OAI1A0 ix551 (.X (nx550), .A1 (nx518), .A2 (nx625), .B (nx627)) ;
    NR2R0 ix519 (.X (nx518), .A1 (nx471), .A2 (nx465)) ;
    OAI3N0 ix628 (.X (nx627), .A1 (nx350), .A2 (nx631), .B1 (nx530), .B2 (nx633)
           ) ;
    ND2N0 ix351 (.X (nx350), .A1 (nx607), .A2 (nx615)) ;
    MX2L0 ix636 (.X (nx635), .A (nx794), .B (nx786), .S (nx806)) ;
    OAI1A0 ix847 (.X (nx846), .A1 (nx814), .A2 (nx641), .B (nx643)) ;
    NR2R0 ix642 (.X (nx641), .A1 (nx350), .A2 (nx518)) ;
    OAI3N0 ix644 (.X (nx643), .A1 (nx662), .A2 (nx647), .B1 (nx826), .B2 (nx635)
           ) ;
    ND2N0 ix648 (.X (nx647), .A1 (nx774), .A2 (nx670)) ;
    MX2L0 ix1099 (.X (nx1098), .A (nx527), .B (nx333), .S (nx1070)) ;
    OAI1A0 ix1111 (.X (nx1110), .A1 (nx1078), .A2 (nx655), .B (nx657)) ;
    NR2R0 ix1079 (.X (nx1078), .A1 (nx555), .A2 (nx549)) ;
    OAI3N0 ix658 (.X (nx657), .A1 (nx974), .A2 (nx661), .B1 (nx1090), .B2 (nx663
           )) ;
    ND2N0 ix975 (.X (nx974), .A1 (nx641), .A2 (nx647)) ;
    MX2L0 ix666 (.X (nx665), .A (nx1226), .B (nx1218), .S (nx1238)) ;
    OAI1A0 ix1279 (.X (nx1278), .A1 (nx1246), .A2 (nx675), .B (nx677)) ;
    NR2R0 ix676 (.X (nx675), .A1 (nx974), .A2 (nx1078)) ;
    OAI3N0 ix678 (.X (nx677), .A1 (nx1254), .A2 (nx681), .B1 (nx1190), .B2 (
           nx665)) ;
    ND2N0 ix682 (.X (nx681), .A1 (nx1206), .A2 (nx1198)) ;
    ND2N0 ix1311 (.X (y2[1]), .A1 (nx675), .A2 (nx681)) ;
    MX2L0 ix1287 (.X (y3[0]), .A (nx665), .B (nx575), .S (nx1278)) ;
    NR2R0 ix1295 (.X (y3[1]), .A1 (nx681), .A2 (nx675)) ;
    MX2L0 ix1175 (.X (y4[0]), .A (nx691), .B (nx749), .S (nx1150)) ;
    MX2L0 ix692 (.X (nx691), .A (nx866), .B (nx874), .S (nx886)) ;
    MX2L0 ix867 (.X (nx866), .A (nx695), .B (nx715), .S (nx590)) ;
    MX2L0 ix696 (.X (nx695), .A (nx294), .B (nx322), .S (nx701)) ;
    MX2L0 ix295 (.X (nx294), .A (nx601), .B (nx583), .S (nx286)) ;
    AO2L0 ix329 (.X (nx328), .A1 (nx709), .A2 (nx302), .B1 (nx294), .B2 (nx713)
          ) ;
    ND2N0 ix710 (.X (nx709), .A1 (nx94), .A2 (nx102)) ;
    NR2R0 ix303 (.X (nx302), .A1 (nx615), .A2 (nx607)) ;
    MX2L0 ix714 (.X (nx713), .A (nx114), .B (nx86), .S (nx589)) ;
    MX2L0 ix716 (.X (nx715), .A (nx538), .B (nx530), .S (nx550)) ;
    OAI1A0 ix591 (.X (nx590), .A1 (nx558), .A2 (nx721), .B (nx723)) ;
    NR2R0 ix722 (.X (nx721), .A1 (nx310), .A2 (nx302)) ;
    OAI3N0 ix724 (.X (nx723), .A1 (nx566), .A2 (nx727), .B1 (nx342), .B2 (nx715)
           ) ;
    ND2N0 ix728 (.X (nx727), .A1 (nx518), .A2 (nx350)) ;
    MX2L0 ix875 (.X (nx874), .A (nx635), .B (nx579), .S (nx846)) ;
    OAI1A0 ix887 (.X (nx886), .A1 (nx854), .A2 (nx739), .B (nx741)) ;
    NR2R0 ix855 (.X (nx854), .A1 (nx647), .A2 (nx641)) ;
    OAI3N0 ix742 (.X (nx741), .A1 (nx654), .A2 (nx745), .B1 (nx866), .B2 (nx747)
           ) ;
    ND2N0 ix655 (.X (nx654), .A1 (nx721), .A2 (nx727)) ;
    MX2L0 ix750 (.X (nx749), .A (nx1098), .B (nx1090), .S (nx1110)) ;
    OAI1A0 ix1151 (.X (nx1150), .A1 (nx1118), .A2 (nx755), .B (nx757)) ;
    NR2R0 ix756 (.X (nx755), .A1 (nx654), .A2 (nx854)) ;
    OAI3N0 ix758 (.X (nx757), .A1 (nx1126), .A2 (nx761), .B1 (nx966), .B2 (nx749
           )) ;
    ND2N0 ix762 (.X (nx761), .A1 (nx1078), .A2 (nx974)) ;
    ND2N0 ix1183 (.X (y4[1]), .A1 (nx755), .A2 (nx761)) ;
    MX2L0 ix1159 (.X (y5[0]), .A (nx749), .B (nx691), .S (nx1150)) ;
    NR2R0 ix1167 (.X (y5[1]), .A1 (nx761), .A2 (nx755)) ;
    MX2L0 ix951 (.X (y6[0]), .A (nx771), .B (nx789), .S (nx926)) ;
    MX2L0 ix772 (.X (nx771), .A (nx598), .B (nx626), .S (nx777)) ;
    MX2L0 ix599 (.X (nx598), .A (nx715), .B (nx695), .S (nx590)) ;
    AO1I0 ix778 (.X (nx777), .A1 (nx779), .A2 (nx614), .B (nx632)) ;
    AO2L0 ix633 (.X (nx632), .A1 (nx783), .A2 (nx606), .B1 (nx598), .B2 (nx787)
          ) ;
    ND2N0 ix784 (.X (nx783), .A1 (nx302), .A2 (nx310)) ;
    NR2R0 ix607 (.X (nx606), .A1 (nx727), .A2 (nx721)) ;
    MX2L0 ix788 (.X (nx787), .A (nx322), .B (nx294), .S (nx701)) ;
    MX2L0 ix790 (.X (nx789), .A (nx874), .B (nx866), .S (nx886)) ;
    OAI1A0 ix927 (.X (nx926), .A1 (nx894), .A2 (nx795), .B (nx797)) ;
    NR2R0 ix796 (.X (nx795), .A1 (nx614), .A2 (nx606)) ;
    OAI3N0 ix798 (.X (nx797), .A1 (nx902), .A2 (nx801), .B1 (nx646), .B2 (nx789)
           ) ;
    ND2N0 ix802 (.X (nx801), .A1 (nx854), .A2 (nx654)) ;
    ND2N0 ix959 (.X (y6[1]), .A1 (nx795), .A2 (nx801)) ;
    MX2L0 ix935 (.X (y7[0]), .A (nx789), .B (nx771), .S (nx926)) ;
    NR2R0 ix943 (.X (y7[1]), .A1 (nx801), .A2 (nx795)) ;
    MX2L0 ix1319 (.X (y8[0]), .A (nx787), .B (nx805), .S (nx777)) ;
    NR2R0 ix1327 (.X (y8[1]), .A1 (nx779), .A2 (nx783)) ;
    IV1N0 ix1255 (.X (nx1254), .A (nx675)) ;
    IV1N0 ix1247 (.X (nx1246), .A (nx681)) ;
    IV1N0 ix1227 (.X (nx1226), .A (nx559)) ;
    IV1N0 ix332 (.X (nx331), .A (nx1218)) ;
    IV1N0 ix1207 (.X (nx1206), .A (nx569)) ;
    IV1N0 ix564 (.X (nx563), .A (nx1198)) ;
    IV1N0 ix1191 (.X (nx1190), .A (nx575)) ;
    IV1N0 ix1127 (.X (nx1126), .A (nx755)) ;
    IV1N0 ix1119 (.X (nx1118), .A (nx761)) ;
    IV1N0 ix664 (.X (nx663), .A (nx1098)) ;
    IV1N0 ix662 (.X (nx661), .A (nx1078)) ;
    IV1N0 ix1051 (.X (nx1050), .A (nx333)) ;
    IV1N0 ix1039 (.X (nx1038), .A (nx555)) ;
    IV1N0 ix1019 (.X (nx1018), .A (nx545)) ;
    IV1N0 ix544 (.X (nx543), .A (nx998)) ;
    IV1N0 ix538 (.X (nx537), .A (nx990)) ;
    IV1N0 ix983 (.X (nx982), .A (nx549)) ;
    IV1N0 ix656 (.X (nx655), .A (nx974)) ;
    IV1N0 ix967 (.X (nx966), .A (nx691)) ;
    IV1N0 ix903 (.X (nx902), .A (nx795)) ;
    IV1N0 ix895 (.X (nx894), .A (nx801)) ;
    IV1N0 ix748 (.X (nx747), .A (nx874)) ;
    IV1N0 ix746 (.X (nx745), .A (nx854)) ;
    IV1N0 ix827 (.X (nx826), .A (nx579)) ;
    IV1N0 ix815 (.X (nx814), .A (nx647)) ;
    IV1N0 ix526 (.X (nx525), .A (nx794)) ;
    IV1N0 ix524 (.X (nx523), .A (nx774)) ;
    IV1N0 ix747 (.X (nx746), .A (nx495)) ;
    IV1N0 ix735 (.X (nx734), .A (nx507)) ;
    IV1N0 ix715 (.X (nx714), .A (nx493)) ;
    IV1N0 ix695 (.X (nx694), .A (nx491)) ;
    IV1N0 ix486 (.X (nx485), .A (nx686)) ;
    IV1N0 ix679 (.X (nx678), .A (nx501)) ;
    IV1N0 ix518 (.X (nx517), .A (nx670)) ;
    IV1N0 ix663 (.X (nx662), .A (nx641)) ;
    IV1N0 ix740 (.X (nx739), .A (nx654)) ;
    IV1N0 ix647 (.X (nx646), .A (nx771)) ;
    IV1N0 ix627 (.X (nx626), .A (nx787)) ;
    IV1N0 ix615 (.X (nx614), .A (nx783)) ;
    IV1N0 ix780 (.X (nx779), .A (nx606)) ;
    IV1N0 ix806 (.X (nx805), .A (nx598)) ;
    IV1N0 ix567 (.X (nx566), .A (nx721)) ;
    IV1N0 ix559 (.X (nx558), .A (nx727)) ;
    IV1N0 ix634 (.X (nx633), .A (nx538)) ;
    IV1N0 ix632 (.X (nx631), .A (nx518)) ;
    IV1N0 ix491 (.X (nx490), .A (nx337)) ;
    IV1N0 ix479 (.X (nx478), .A (nx471)) ;
    IV1N0 ix460 (.X (nx459), .A (nx458)) ;
    IV1N0 ix458 (.X (nx457), .A (nx438)) ;
    IV1N0 ix411 (.X (nx410), .A (nx433)) ;
    IV1N0 ix375 (.X (nx374), .A (nx437)) ;
    IV1N0 ix452 (.X (nx451), .A (nx366)) ;
    IV1N0 ix359 (.X (nx358), .A (nx465)) ;
    IV1N0 ix626 (.X (nx625), .A (nx350)) ;
    IV1N0 ix343 (.X (nx342), .A (nx695)) ;
    IV1N0 ix323 (.X (nx322), .A (nx713)) ;
    IV1N0 ix311 (.X (nx310), .A (nx709)) ;
    IV1N0 ix263 (.X (nx262), .A (nx607)) ;
    IV1N0 ix255 (.X (nx254), .A (nx615)) ;
    IV1N0 ix416 (.X (nx415), .A (nx234)) ;
    IV1N0 ix414 (.X (nx413), .A (nx214)) ;
    IV1N0 ix187 (.X (nx186), .A (nx391)) ;
    IV1N0 ix151 (.X (nx150), .A (nx395)) ;
    IV1N0 ix408 (.X (nx407), .A (nx142)) ;
    IV1N0 ix135 (.X (nx134), .A (nx583)) ;
    IV1N0 ix115 (.X (nx114), .A (nx599)) ;
    IV1N0 ix103 (.X (nx102), .A (nx595)) ;
    IV1N0 ix592 (.X (nx591), .A (nx94)) ;
    IV1N0 ix55 (.X (nx54), .A (nx367)) ;
    IV1N0 ix23 (.X (nx22), .A (nx341)) ;
    OA1R0 ix702 (.X (nx701), .A1 (nx302), .A2 (nx709), .B (nx827)) ;
    IV1N0 ix825 (.X (nx827), .A (nx328)) ;
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


module AO1I0 ( X, A1, A2, B ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B ;

    wire NOT_A2, NOT_B, nx4, NOT_A1, nx8;



    assign NOT_A2 = ~A2 ;
    assign NOT_B = ~B ;
    and (nx4, NOT_A2, NOT_B) ;
    assign NOT_A1 = ~A1 ;
    and (nx8, NOT_A1, NOT_B) ;
    or (X, nx4, nx8) ;
endmodule


module AO2L0 ( X, A1, A2, B1, B2 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B1 ;
    input B2 ;

    wire NOT_A2, NOT_B1, nx4, NOT_B2, nx8, NOT_A1, nx12, nx14;



    assign NOT_A2 = ~A2 ;
    assign NOT_B1 = ~B1 ;
    and (nx4, NOT_A2, NOT_B1) ;
    assign NOT_B2 = ~B2 ;
    and (nx8, nx4, NOT_B2) ;
    assign NOT_A1 = ~A1 ;
    and (nx12, NOT_A1, NOT_B1) ;
    and (nx14, nx12, NOT_B2) ;
    or (X, nx8, nx14) ;
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


module OAI3R1 ( X, A1, A2, A3, B ) ;

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


module ND2N0 ( X, A1, A2 ) ;

    output X ;
    input A1 ;
    input A2 ;

    wire NOT_A2, NOT_A1;



    assign NOT_A2 = ~A2 ;
    assign NOT_A1 = ~A1 ;
    or (X, NOT_A2, NOT_A1) ;
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


module AOA4I0 ( X, A1, A2, B, C ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B ;
    input C ;

    wire NOT_A2, NOT_B, nx4, NOT_A1, nx8, nx10, NOT_C;



    assign NOT_A2 = ~A2 ;
    assign NOT_B = ~B ;
    and (nx4, NOT_A2, NOT_B) ;
    assign NOT_A1 = ~A1 ;
    and (nx8, NOT_A1, NOT_B) ;
    or (nx10, nx4, nx8) ;
    assign NOT_C = ~C ;
    or (X, nx10, NOT_C) ;
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


module MX2L0 ( X, A, B, S ) ;

    output X ;
    input A ;
    input B ;
    input S ;

    wire NOT_B, NOT_S, nx4, NOT_A, nx8;



    assign NOT_B = ~B ;
    assign NOT_S = ~S ;
    and (nx4, NOT_B, NOT_S) ;
    assign NOT_A = ~A ;
    and (nx8, NOT_A, S) ;
    or (X, nx4, nx8) ;
endmodule

