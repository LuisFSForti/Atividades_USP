//
// Verilog description for cell ordenador, 
// 06/12/24 10:25:27
//
// LeonardoSpectrum Level 3, 2020a.2 
//


module ordenador ( y8, y7, y6, y5, y4, y3, y2, y1, x8, x7, x6, x5, x4, x3, x2, 
                   x1 ) ;

    output [3:0]y8 ;
    output [3:0]y7 ;
    output [3:0]y6 ;
    output [3:0]y5 ;
    output [3:0]y4 ;
    output [3:0]y3 ;
    output [3:0]y2 ;
    output [3:0]y1 ;
    input [3:0]x8 ;
    input [3:0]x7 ;
    input [3:0]x6 ;
    input [3:0]x5 ;
    input [3:0]x4 ;
    input [3:0]x3 ;
    input [3:0]x2 ;
    input [3:0]x1 ;

    wire nx14, nx22, nx34, nx42, nx58, nx66, nx78, nx86, nx94, nx102, nx110, 
         nx126, nx134, nx150, nx168, nx176, nx186, nx194, nx202, nx210, nx218, 
         nx234, nx242, nx248, nx266, nx272, nx286, nx294, nx302, nx310, nx326, 
         nx334, nx346, nx362, nx370, nx386, nx394, nx410, nx418, nx436, nx444, 
         nx454, nx462, nx470, nx486, nx494, nx510, nx518, nx526, nx536, nx544, 
         nx562, nx570, nx578, nx594, nx602, nx618, nx636, nx644, nx654, nx662, 
         nx670, nx678, nx686, nx702, nx710, nx716, nx734, nx740, nx754, nx762, 
         nx770, nx778, nx786, nx794, nx810, nx818, nx830, nx846, nx854, nx870, 
         nx878, nx894, nx902, nx920, nx928, nx938, nx946, nx954, nx970, nx978, 
         nx994, nx1002, nx1010, nx1020, nx1028, nx1046, nx1054, nx1070, nx1078, 
         nx1094, nx1102, nx1120, nx1128, nx1138, nx1146, nx1154, nx1170, nx1178, 
         nx1194, nx1202, nx1210, nx1220, nx1228, nx1246, nx1254, nx1262, nx1278, 
         nx1286, nx1302, nx1320, nx1328, nx1338, nx1346, nx1354, nx1362, nx1370, 
         nx1386, nx1394, nx1400, nx1418, nx1424, nx1438, nx1454, nx1462, nx1470, 
         nx1478, nx1486, nx1502, nx1510, nx1526, nx1534, nx1550, nx1558, nx1566, 
         nx1576, nx1584, nx1594, nx1602, nx1610, nx1626, nx1634, nx1650, nx1658, 
         nx1676, nx1686, nx1702, nx1710, nx1726, nx1734, nx1750, nx1758, nx1766, 
         nx1776, nx1784, nx1794, nx1810, nx1834, nx1840, nx1850, nx1858, nx1876, 
         nx1886, nx1902, nx1910, nx1926, nx1934, nx1950, nx1958, nx1966, nx1976, 
         nx1984, nx1994, nx2002, nx2010, nx2018, nx2034, nx2076, nx2086, nx2158, 
         nx2166, nx2174, nx2182, nx2198, nx2206, nx2222, nx2230, nx2246, nx2254, 
         nx2262, nx2272, nx2280, nx2290, nx2298, nx2306, nx2322, nx2330, nx2346, 
         nx2354, nx2372, nx2380, nx2398, nx2406, nx2422, nx2430, nx2446, nx2454, 
         nx2462, nx2472, nx2480, nx2490, nx2498, nx2506, nx2514, nx2530, nx2538, 
         nx2554, nx2572, nx2580, nx2654, nx2662, nx2670, nx2678, nx2686, nx2702, 
         nx2710, nx2726, nx2734, nx2742, nx2752, nx2762, nx2778, nx2786, nx2794, 
         nx2810, nx2818, nx2834, nx2852, nx2860, nx599, nx601, nx605, nx609, 
         nx613, nx615, nx619, nx621, nx623, nx625, nx627, nx631, nx633, nx637, 
         nx639, nx643, nx645, nx647, nx649, nx651, nx655, nx657, nx661, nx665, 
         nx671, nx675, nx677, nx683, nx687, nx693, nx695, nx699, nx701, nx705, 
         nx707, nx709, nx711, nx713, nx717, nx719, nx723, nx727, nx731, nx735, 
         nx737, nx743, nx747, nx751, nx755, nx759, nx765, nx767, nx769, nx771, 
         nx775, nx779, nx781, nx783, nx787, nx791, nx795, nx799, nx803, nx807, 
         nx811, nx813, nx817, nx825, nx827, nx831, nx835, nx843, nx847, nx849, 
         nx855, nx863, nx865, nx877, nx881, nx885, nx889, nx893, nx897, nx899, 
         nx903, nx907, nx913, nx915, nx921, nx923, nx927, nx929, nx933, nx935, 
         nx937, nx939, nx941, nx945, nx947, nx951, nx955, nx961, nx965, nx967, 
         nx973, nx977, nx981, nx985, nx989, nx993, nx995, nx997, nx999, nx1005, 
         nx1009, nx1011, nx1015, nx1019, nx1023, nx1029, nx1033, nx1035, nx1041, 
         nx1047, nx1051, nx1055, nx1059, nx1063, nx1065, nx1067, nx1069, nx1075, 
         nx1079, nx1081, nx1085, nx1089, nx1093, nx1101, nx1105, nx1107, nx1113, 
         nx1119, nx1121, nx1123, nx1127, nx1133, nx1137, nx1141, nx1145, nx1149, 
         nx1155, nx1161, nx1163, nx1171, nx1177, nx1183, nx1189, nx1193, nx1195, 
         nx1201, nx1203, nx1207, nx1211, nx1215, nx1219, nx1221, nx1227, nx1229, 
         nx1233, nx1237, nx1243, nx1251, nx1253, nx1261, nx1267, nx1271, nx1275, 
         nx1279, nx1283, nx1285, nx1287, nx1289, nx1295, nx1299, nx1301, nx1305, 
         nx1311, nx1315, nx1319, nx1325, nx1329, nx1331, nx1337, nx1343, nx1345, 
         nx1355, nx1359, nx1363, nx1367, nx1369, nx1371, nx1373, nx1379, nx1383, 
         nx1387, nx1391, nx1395, nx1401, nx1405, nx1407, nx1413, nx1419, nx1421, 
         nx1431, nx1443, nx1445, nx1451, nx1453, nx1459, nx1463, nx1467, nx1471, 
         nx1475, nx1479, nx1481, nx1487, nx1489, nx1493, nx1497, nx1503, nx1509, 
         nx1511, nx1519, nx1523, nx1527, nx1531, nx1535, nx1541, nx1543, nx1545, 
         nx1547, nx1553, nx1557, nx1559, nx1563, nx1567, nx1571, nx1577, nx1581, 
         nx1583, nx1589, nx1593, nx1595, nx1613, nx1619, nx1621, nx1625, nx1629, 
         nx1633, nx1637, nx1639, nx1645, nx1647, nx1653, nx1657, nx1661, nx1667, 
         nx1673, nx1675, nx1677, nx1683, nx1685, nx1691, nx1693, nx1697, nx1729;



    MX2L0 ix2967 (.X (y1[0]), .A (nx599), .B (nx1127), .S (nx2762)) ;
    MX2L0 ix602 (.X (nx601), .A (nx2254), .B (nx2262), .S (nx877)) ;
    MX2L0 ix2255 (.X (nx2254), .A (nx605), .B (nx787), .S (nx1686)) ;
    MX2L0 ix606 (.X (nx605), .A (nx1010), .B (nx1002), .S (nx751)) ;
    MX2L0 ix1011 (.X (nx1010), .A (nx609), .B (nx633), .S (nx657)) ;
    MX2L0 ix610 (.X (nx609), .A (x4[0]), .B (x3[0]), .S (nx346)) ;
    OAI2N2 ix347 (.X (nx346), .A1 (nx613), .A2 (nx615), .B1 (x3[3]), .B2 (nx631)
           ) ;
    IV1N0 ix614 (.X (nx613), .A (x4[3])) ;
    OAOI0 ix616 (.X (nx615), .A1 (nx326), .A2 (x4[2]), .B (nx627), .C (nx334)) ;
    OAI1A0 ix327 (.X (nx326), .A1 (x3[1]), .A2 (nx619), .B (nx621)) ;
    IV1N0 ix620 (.X (nx619), .A (x4[1])) ;
    OAI3N0 ix622 (.X (nx621), .A1 (x4[1]), .A2 (nx623), .B1 (x4[0]), .B2 (nx625)
           ) ;
    IV1N0 ix624 (.X (nx623), .A (x3[1])) ;
    IV1N0 ix626 (.X (nx625), .A (x3[0])) ;
    IV1N0 ix628 (.X (nx627), .A (x3[2])) ;
    AN2T0 ix335 (.X (nx334), .A1 (x4[2]), .A2 (nx326)) ;
    AN2T0 ix632 (.X (nx631), .A1 (nx615), .A2 (nx613)) ;
    MX2L0 ix634 (.X (nx633), .A (x1[0]), .B (x2[0]), .S (nx830)) ;
    OAI2N2 ix831 (.X (nx830), .A1 (nx637), .A2 (nx639), .B1 (x1[3]), .B2 (nx655)
           ) ;
    IV1N0 ix638 (.X (nx637), .A (x2[3])) ;
    OAOI0 ix640 (.X (nx639), .A1 (nx810), .A2 (x2[2]), .B (nx651), .C (nx818)) ;
    OAI1A0 ix811 (.X (nx810), .A1 (x1[1]), .A2 (nx643), .B (nx645)) ;
    IV1N0 ix644 (.X (nx643), .A (x2[1])) ;
    OAI3N0 ix646 (.X (nx645), .A1 (x2[1]), .A2 (nx647), .B1 (x2[0]), .B2 (nx649)
           ) ;
    IV1N0 ix648 (.X (nx647), .A (x1[1])) ;
    IV1N0 ix650 (.X (nx649), .A (x1[0])) ;
    IV1N0 ix652 (.X (nx651), .A (x1[2])) ;
    AN2T0 ix819 (.X (nx818), .A1 (x2[2]), .A2 (nx810)) ;
    AN2T0 ix656 (.X (nx655), .A1 (nx639), .A2 (nx637)) ;
    OAOI2 ix658 (.X (nx657), .A1 (nx920), .A2 (nx794), .B (nx687), .C (nx928)) ;
    OAI3N0 ix921 (.X (nx920), .A1 (nx661), .A2 (nx854), .B1 (nx665), .B2 (nx675)
           ) ;
    MX2L0 ix662 (.X (nx661), .A (x4[2]), .B (x3[2]), .S (nx346)) ;
    ND3N0 ix666 (.X (nx665), .A1 (nx894), .A2 (nx902), .A3 (nx633)) ;
    AO2I0 ix895 (.X (nx894), .A1 (nx878), .A2 (nx671), .B1 (nx854), .B2 (nx661)
          ) ;
    MX2L0 ix672 (.X (nx671), .A (x4[1]), .B (x3[1]), .S (nx346)) ;
    OAI3N0 ix676 (.X (nx675), .A1 (nx677), .A2 (nx846), .B1 (nx870), .B2 (nx683)
           ) ;
    MX2L0 ix678 (.X (nx677), .A (x1[2]), .B (x2[2]), .S (nx830)) ;
    MX2L0 ix684 (.X (nx683), .A (x1[1]), .B (x2[1]), .S (nx830)) ;
    ND2N0 ix688 (.X (nx687), .A1 (x1[3]), .A2 (x2[3])) ;
    OA1R0 ix929 (.X (nx928), .A1 (x4[3]), .A2 (x3[3]), .B (nx920)) ;
    MX2L0 ix1003 (.X (nx1002), .A (nx693), .B (nx695), .S (nx719)) ;
    MX2L0 ix694 (.X (nx693), .A (x3[0]), .B (x4[0]), .S (nx346)) ;
    MX2L0 ix696 (.X (nx695), .A (x6[0]), .B (x5[0]), .S (nx78)) ;
    OAI2N2 ix79 (.X (nx78), .A1 (nx699), .A2 (nx701), .B1 (x5[3]), .B2 (nx717)
           ) ;
    IV1N0 ix700 (.X (nx699), .A (x6[3])) ;
    OAOI0 ix702 (.X (nx701), .A1 (nx58), .A2 (x6[2]), .B (nx713), .C (nx66)) ;
    OAI1A0 ix59 (.X (nx58), .A1 (x5[1]), .A2 (nx705), .B (nx707)) ;
    IV1N0 ix706 (.X (nx705), .A (x6[1])) ;
    OAI3N0 ix708 (.X (nx707), .A1 (x6[1]), .A2 (nx709), .B1 (x6[0]), .B2 (nx711)
           ) ;
    IV1N0 ix710 (.X (nx709), .A (x5[1])) ;
    IV1N0 ix712 (.X (nx711), .A (x5[0])) ;
    IV1N0 ix714 (.X (nx713), .A (x5[2])) ;
    AN2T0 ix67 (.X (nx66), .A1 (x6[2]), .A2 (nx58)) ;
    AN2T0 ix718 (.X (nx717), .A1 (nx701), .A2 (nx699)) ;
    OAOI2 ix720 (.X (nx719), .A1 (nx436), .A2 (nx310), .B (nx747), .C (nx444)) ;
    OAI3N0 ix437 (.X (nx436), .A1 (nx723), .A2 (nx370), .B1 (nx727), .B2 (nx735)
           ) ;
    MX2L0 ix724 (.X (nx723), .A (x6[2]), .B (x5[2]), .S (nx78)) ;
    ND3N0 ix728 (.X (nx727), .A1 (nx410), .A2 (nx418), .A3 (nx693)) ;
    AO2I0 ix411 (.X (nx410), .A1 (nx394), .A2 (nx731), .B1 (nx370), .B2 (nx723)
          ) ;
    MX2L0 ix732 (.X (nx731), .A (x6[1]), .B (x5[1]), .S (nx78)) ;
    OAI3N0 ix736 (.X (nx735), .A1 (nx737), .A2 (nx362), .B1 (nx386), .B2 (nx743)
           ) ;
    MX2L0 ix738 (.X (nx737), .A (x3[2]), .B (x4[2]), .S (nx346)) ;
    MX2L0 ix744 (.X (nx743), .A (x3[1]), .B (x4[1]), .S (nx346)) ;
    ND2N0 ix748 (.X (nx747), .A1 (x3[3]), .A2 (x4[3])) ;
    OA1R0 ix445 (.X (nx444), .A1 (x6[3]), .A2 (x5[3]), .B (nx436)) ;
    OAOI2 ix752 (.X (nx751), .A1 (nx1020), .A2 (nx786), .B (nx781), .C (nx1028)
          ) ;
    OAI3N0 ix1021 (.X (nx1020), .A1 (nx755), .A2 (nx954), .B1 (nx759), .B2 (
           nx769)) ;
    MX2L0 ix955 (.X (nx954), .A (nx661), .B (nx677), .S (nx657)) ;
    ND3N0 ix760 (.X (nx759), .A1 (nx994), .A2 (nx1002), .A3 (nx767)) ;
    AO2I0 ix995 (.X (nx994), .A1 (nx978), .A2 (nx765), .B1 (nx954), .B2 (nx755)
          ) ;
    MX2L0 ix979 (.X (nx978), .A (nx671), .B (nx683), .S (nx657)) ;
    OAI3N0 ix770 (.X (nx769), .A1 (nx771), .A2 (nx946), .B1 (nx970), .B2 (nx775)
           ) ;
    MX2L0 ix947 (.X (nx946), .A (nx737), .B (nx723), .S (nx719)) ;
    MX2L0 ix971 (.X (nx970), .A (nx743), .B (nx731), .S (nx719)) ;
    ND2N0 ix787 (.X (nx786), .A1 (nx779), .A2 (nx747)) ;
    NR2R0 ix780 (.X (nx779), .A1 (x6[3]), .A2 (x5[3])) ;
    NR2R0 ix784 (.X (nx783), .A1 (x4[3]), .A2 (x3[3])) ;
    AN2T0 ix1029 (.X (nx1028), .A1 (nx786), .A2 (nx1020)) ;
    MX2L0 ix788 (.X (nx787), .A (nx1558), .B (nx1566), .S (nx791)) ;
    MX2L0 ix1559 (.X (nx1558), .A (nx633), .B (nx609), .S (nx657)) ;
    OAOI2 ix792 (.X (nx791), .A1 (nx1576), .A2 (nx1486), .B (nx817), .C (nx1584)
          ) ;
    OAI3N0 ix1577 (.X (nx1576), .A1 (nx795), .A2 (nx1510), .B1 (nx799), .B2 (
           nx813)) ;
    ND3N0 ix800 (.X (nx799), .A1 (nx1550), .A2 (nx1558), .A3 (nx811)) ;
    OA4R0 ix1551 (.X (nx1550), .A1 (nx803), .A2 (nx1526), .B1 (nx807), .B2 (
          nx1502)) ;
    MX2L0 ix804 (.X (nx803), .A (x2[1]), .B (x1[1]), .S (nx830)) ;
    MX2L0 ix1527 (.X (nx1526), .A (nx683), .B (nx671), .S (nx657)) ;
    MX2L0 ix808 (.X (nx807), .A (x2[2]), .B (x1[2]), .S (nx830)) ;
    MX2L0 ix1503 (.X (nx1502), .A (nx677), .B (nx661), .S (nx657)) ;
    MX2L0 ix812 (.X (nx811), .A (x2[0]), .B (x1[0]), .S (nx830)) ;
    OAI3N0 ix814 (.X (nx813), .A1 (nx807), .A2 (nx1502), .B1 (nx1526), .B2 (
           nx803)) ;
    ND2N0 ix1487 (.X (nx1486), .A1 (nx783), .A2 (nx687)) ;
    NR2R0 ix818 (.X (nx817), .A1 (x2[3]), .A2 (x1[3])) ;
    AN2T0 ix1585 (.X (nx1584), .A1 (nx1486), .A2 (nx1576)) ;
    OAI2N2 ix1687 (.X (nx1686), .A1 (nx1594), .A2 (nx827), .B1 (nx863), .B2 (
           nx865)) ;
    NR2R0 ix1595 (.X (nx1594), .A1 (nx817), .A2 (nx825)) ;
    NR2R0 ix828 (.X (nx827), .A1 (nx1676), .A2 (nx1478)) ;
    OAI3N0 ix1677 (.X (nx1676), .A1 (nx831), .A2 (nx1610), .B1 (nx835), .B2 (
           nx847)) ;
    MX2L0 ix832 (.X (nx831), .A (nx954), .B (nx946), .S (nx751)) ;
    ND3N0 ix836 (.X (nx835), .A1 (nx1650), .A2 (nx1658), .A3 (nx787)) ;
    AO2I0 ix1651 (.X (nx1650), .A1 (nx1634), .A2 (nx843), .B1 (nx1610), .B2 (
          nx831)) ;
    MX2L0 ix844 (.X (nx843), .A (nx978), .B (nx970), .S (nx751)) ;
    OAI3N0 ix848 (.X (nx847), .A1 (nx849), .A2 (nx1602), .B1 (nx1626), .B2 (
           nx855)) ;
    MX2L0 ix850 (.X (nx849), .A (nx1502), .B (nx1510), .S (nx791)) ;
    MX2L0 ix856 (.X (nx855), .A (nx1526), .B (nx1534), .S (nx791)) ;
    NR2R0 ix939 (.X (nx938), .A1 (nx687), .A2 (nx783)) ;
    NR2R0 ix864 (.X (nx863), .A1 (nx786), .A2 (nx938)) ;
    OAOI2 ix878 (.X (nx877), .A1 (nx2272), .A2 (nx2182), .B (nx903), .C (nx2280)
          ) ;
    OAI3N0 ix2273 (.X (nx2272), .A1 (nx881), .A2 (nx2206), .B1 (nx885), .B2 (
           nx899)) ;
    ND3N0 ix886 (.X (nx885), .A1 (nx2246), .A2 (nx2254), .A3 (nx897)) ;
    OA4R0 ix2247 (.X (nx2246), .A1 (nx889), .A2 (nx2222), .B1 (nx893), .B2 (
          nx2198)) ;
    MX2L0 ix890 (.X (nx889), .A (nx1534), .B (nx1526), .S (nx791)) ;
    MX2L0 ix2223 (.X (nx2222), .A (nx843), .B (nx855), .S (nx1686)) ;
    MX2L0 ix894 (.X (nx893), .A (nx1510), .B (nx1502), .S (nx791)) ;
    MX2L0 ix2199 (.X (nx2198), .A (nx831), .B (nx849), .S (nx1686)) ;
    MX2L0 ix898 (.X (nx897), .A (nx1566), .B (nx1558), .S (nx791)) ;
    OAI3N0 ix900 (.X (nx899), .A1 (nx893), .A2 (nx2198), .B1 (nx2222), .B2 (
           nx889)) ;
    NR3R1 ix904 (.X (nx903), .A1 (nx794), .A2 (x1[3]), .A3 (x2[3])) ;
    AN2T0 ix2281 (.X (nx2280), .A1 (nx2182), .A2 (nx2272)) ;
    MX2L0 ix908 (.X (nx907), .A (nx1766), .B (nx1758), .S (nx1051)) ;
    MX2L0 ix1767 (.X (nx1766), .A (nx787), .B (nx605), .S (nx1686)) ;
    MX2L0 ix1759 (.X (nx1758), .A (nx913), .B (nx915), .S (nx1015)) ;
    MX2L0 ix914 (.X (nx913), .A (nx1002), .B (nx1010), .S (nx751)) ;
    MX2L0 ix916 (.X (nx915), .A (nx526), .B (nx518), .S (nx981)) ;
    MX2L0 ix527 (.X (nx526), .A (nx695), .B (nx693), .S (nx719)) ;
    MX2L0 ix519 (.X (nx518), .A (nx921), .B (nx923), .S (nx947)) ;
    MX2L0 ix922 (.X (nx921), .A (x5[0]), .B (x6[0]), .S (nx78)) ;
    MX2L0 ix924 (.X (nx923), .A (x8[0]), .B (x7[0]), .S (nx34)) ;
    OAI2N2 ix35 (.X (nx34), .A1 (nx927), .A2 (nx929), .B1 (x7[3]), .B2 (nx945)
           ) ;
    IV1N0 ix928 (.X (nx927), .A (x8[3])) ;
    OAOI0 ix930 (.X (nx929), .A1 (nx14), .A2 (x8[2]), .B (nx941), .C (nx22)) ;
    OAI1A0 ix15 (.X (nx14), .A1 (x7[1]), .A2 (nx933), .B (nx935)) ;
    IV1N0 ix934 (.X (nx933), .A (x8[1])) ;
    OAI3N0 ix936 (.X (nx935), .A1 (x8[1]), .A2 (nx937), .B1 (x8[0]), .B2 (nx939)
           ) ;
    IV1N0 ix938 (.X (nx937), .A (x7[1])) ;
    IV1N0 ix940 (.X (nx939), .A (x7[0])) ;
    IV1N0 ix942 (.X (nx941), .A (x7[2])) ;
    AN2T0 ix23 (.X (nx22), .A1 (x8[2]), .A2 (nx14)) ;
    AN2T0 ix946 (.X (nx945), .A1 (nx929), .A2 (nx927)) ;
    OAOI2 ix948 (.X (nx947), .A1 (nx168), .A2 (nx94), .B (nx977), .C (nx176)) ;
    OAI3N0 ix169 (.X (nx168), .A1 (nx951), .A2 (nx110), .B1 (nx955), .B2 (nx965)
           ) ;
    MX2L0 ix952 (.X (nx951), .A (x8[2]), .B (x7[2]), .S (nx34)) ;
    ND3N0 ix956 (.X (nx955), .A1 (nx150), .A2 (nx42), .A3 (nx921)) ;
    AO2I0 ix151 (.X (nx150), .A1 (nx134), .A2 (nx961), .B1 (nx110), .B2 (nx951)
          ) ;
    MX2L0 ix962 (.X (nx961), .A (x8[1]), .B (x7[1]), .S (nx34)) ;
    OAI3N0 ix966 (.X (nx965), .A1 (nx967), .A2 (nx102), .B1 (nx126), .B2 (nx973)
           ) ;
    MX2L0 ix968 (.X (nx967), .A (x5[2]), .B (x6[2]), .S (nx78)) ;
    MX2L0 ix974 (.X (nx973), .A (x5[1]), .B (x6[1]), .S (nx78)) ;
    ND2N0 ix978 (.X (nx977), .A1 (x5[3]), .A2 (x6[3])) ;
    OA1R0 ix177 (.X (nx176), .A1 (x8[3]), .A2 (x7[3]), .B (nx168)) ;
    OAOI2 ix982 (.X (nx981), .A1 (nx536), .A2 (nx302), .B (nx1011), .C (nx544)
          ) ;
    OAI3N0 ix537 (.X (nx536), .A1 (nx985), .A2 (nx470), .B1 (nx989), .B2 (nx997)
           ) ;
    MX2L0 ix471 (.X (nx470), .A (nx723), .B (nx737), .S (nx719)) ;
    ND3N0 ix990 (.X (nx989), .A1 (nx510), .A2 (nx518), .A3 (nx995)) ;
    AO2I0 ix511 (.X (nx510), .A1 (nx494), .A2 (nx993), .B1 (nx470), .B2 (nx985)
          ) ;
    MX2L0 ix495 (.X (nx494), .A (nx731), .B (nx743), .S (nx719)) ;
    OAI3N0 ix998 (.X (nx997), .A1 (nx999), .A2 (nx462), .B1 (nx486), .B2 (nx1005
           )) ;
    MX2L0 ix463 (.X (nx462), .A (nx967), .B (nx951), .S (nx947)) ;
    MX2L0 ix487 (.X (nx486), .A (nx973), .B (nx961), .S (nx947)) ;
    ND2N0 ix303 (.X (nx302), .A1 (nx1009), .A2 (nx977)) ;
    NR2R0 ix1010 (.X (nx1009), .A1 (x8[3]), .A2 (x7[3])) ;
    AN2T0 ix545 (.X (nx544), .A1 (nx302), .A2 (nx536)) ;
    OAOI2 ix1016 (.X (nx1015), .A1 (nx1120), .A2 (nx778), .B (nx1047), .C (
          nx1128)) ;
    OAI3N0 ix1121 (.X (nx1120), .A1 (nx1019), .A2 (nx1054), .B1 (nx1023), .B2 (
           nx1033)) ;
    MX2L0 ix1020 (.X (nx1019), .A (nx470), .B (nx462), .S (nx981)) ;
    ND3N0 ix1024 (.X (nx1023), .A1 (nx1094), .A2 (nx1102), .A3 (nx913)) ;
    AO2I0 ix1095 (.X (nx1094), .A1 (nx1078), .A2 (nx1029), .B1 (nx1054), .B2 (
          nx1019)) ;
    MX2L0 ix1030 (.X (nx1029), .A (nx494), .B (nx486), .S (nx981)) ;
    OAI3N0 ix1034 (.X (nx1033), .A1 (nx1035), .A2 (nx1046), .B1 (nx1070), .B2 (
           nx1041)) ;
    MX2L0 ix1036 (.X (nx1035), .A (nx946), .B (nx954), .S (nx751)) ;
    MX2L0 ix1042 (.X (nx1041), .A (nx970), .B (nx978), .S (nx751)) ;
    NR2R0 ix455 (.X (nx454), .A1 (nx747), .A2 (nx779)) ;
    ND2N0 ix1048 (.X (nx1047), .A1 (nx938), .A2 (nx786)) ;
    AN2T0 ix1129 (.X (nx1128), .A1 (nx778), .A2 (nx1120)) ;
    OAOI2 ix1052 (.X (nx1051), .A1 (nx1776), .A2 (nx1470), .B (nx1081), .C (
          nx1784)) ;
    OAI3N0 ix1777 (.X (nx1776), .A1 (nx1055), .A2 (nx1710), .B1 (nx1059), .B2 (
           nx1067)) ;
    MX2L0 ix1711 (.X (nx1710), .A (nx849), .B (nx831), .S (nx1686)) ;
    ND3N0 ix1060 (.X (nx1059), .A1 (nx1750), .A2 (nx1758), .A3 (nx1065)) ;
    AO2I0 ix1751 (.X (nx1750), .A1 (nx1734), .A2 (nx1063), .B1 (nx1710), .B2 (
          nx1055)) ;
    MX2L0 ix1735 (.X (nx1734), .A (nx855), .B (nx843), .S (nx1686)) ;
    OAI3N0 ix1068 (.X (nx1067), .A1 (nx1069), .A2 (nx1702), .B1 (nx1726), .B2 (
           nx1075)) ;
    MX2L0 ix1703 (.X (nx1702), .A (nx1035), .B (nx1019), .S (nx1015)) ;
    MX2L0 ix1727 (.X (nx1726), .A (nx1041), .B (nx1029), .S (nx1015)) ;
    ND2N0 ix1471 (.X (nx1470), .A1 (nx1079), .A2 (nx1047)) ;
    NR2R0 ix1080 (.X (nx1079), .A1 (nx302), .A2 (nx454)) ;
    ND2N0 ix1082 (.X (nx1081), .A1 (nx1594), .A2 (nx1478)) ;
    AN2T0 ix1785 (.X (nx1784), .A1 (nx1470), .A2 (nx1776)) ;
    OAOI2 ix1086 (.X (nx1085), .A1 (nx2372), .A2 (nx2174), .B (nx1121), .C (
          nx2380)) ;
    OAI3N0 ix2373 (.X (nx2372), .A1 (nx1089), .A2 (nx2306), .B1 (nx1093), .B2 (
           nx1105)) ;
    MX2L0 ix1090 (.X (nx1089), .A (nx1710), .B (nx1702), .S (nx1051)) ;
    ND3N0 ix1094 (.X (nx1093), .A1 (nx2346), .A2 (nx2354), .A3 (nx601)) ;
    AO2I0 ix2347 (.X (nx2346), .A1 (nx2330), .A2 (nx1101), .B1 (nx2306), .B2 (
          nx1089)) ;
    MX2L0 ix1102 (.X (nx1101), .A (nx1734), .B (nx1726), .S (nx1051)) ;
    OAI3N0 ix1106 (.X (nx1105), .A1 (nx1107), .A2 (nx2298), .B1 (nx2322), .B2 (
           nx1113)) ;
    MX2L0 ix1108 (.X (nx1107), .A (nx2198), .B (nx2206), .S (nx877)) ;
    MX2L0 ix1114 (.X (nx1113), .A (nx2222), .B (nx2230), .S (nx877)) ;
    ND2N0 ix2175 (.X (nx2174), .A1 (nx1119), .A2 (nx1081)) ;
    NR2R0 ix1124 (.X (nx1123), .A1 (nx1478), .A2 (nx1594)) ;
    AN2T0 ix2381 (.X (nx2380), .A1 (nx2174), .A2 (nx2372)) ;
    MX2L0 ix1128 (.X (nx1127), .A (nx2262), .B (nx2254), .S (nx877)) ;
    OAI2N2 ix2763 (.X (nx2762), .A1 (nx2670), .A2 (nx1133), .B1 (nx1161), .B2 (
           nx1163)) ;
    ND2N0 ix2671 (.X (nx2670), .A1 (nx1123), .A2 (nx903)) ;
    NR2R0 ix1134 (.X (nx1133), .A1 (nx2752), .A2 (nx2662)) ;
    OAI3N0 ix2753 (.X (nx2752), .A1 (nx1137), .A2 (nx2686), .B1 (nx1141), .B2 (
           nx1155)) ;
    ND3N0 ix1142 (.X (nx1141), .A1 (nx2726), .A2 (nx2734), .A3 (nx1127)) ;
    OA4R0 ix2727 (.X (nx2726), .A1 (nx1145), .A2 (nx2702), .B1 (nx1149), .B2 (
          nx2678)) ;
    MX2L0 ix1146 (.X (nx1145), .A (nx2230), .B (nx2222), .S (nx877)) ;
    MX2L0 ix2703 (.X (nx2702), .A (nx1113), .B (nx1101), .S (nx1085)) ;
    MX2L0 ix1150 (.X (nx1149), .A (nx2206), .B (nx2198), .S (nx877)) ;
    MX2L0 ix2679 (.X (nx2678), .A (nx1107), .B (nx1089), .S (nx1085)) ;
    MX2L0 ix2735 (.X (nx2734), .A (nx601), .B (nx907), .S (nx1085)) ;
    OAI3N0 ix1156 (.X (nx1155), .A1 (nx1149), .A2 (nx2678), .B1 (nx2702), .B2 (
           nx1145)) ;
    NR2R0 ix2291 (.X (nx2290), .A1 (nx903), .A2 (nx1123)) ;
    NR2R0 ix1162 (.X (nx1161), .A1 (nx2174), .A2 (nx2290)) ;
    MX2L0 ix2975 (.X (y1[1]), .A (nx1171), .B (nx1145), .S (nx2762)) ;
    MX2L0 ix2983 (.X (y1[2]), .A (nx1137), .B (nx1149), .S (nx2762)) ;
    OR2T0 ix2991 (.X (y1[3]), .A1 (nx2662), .A2 (nx2670)) ;
    MX2L0 ix2903 (.X (y2[0]), .A (nx1177), .B (nx1183), .S (nx1387)) ;
    MX2L0 ix1178 (.X (nx1177), .A (nx2742), .B (nx2734), .S (nx2762)) ;
    MX2L0 ix1184 (.X (nx1183), .A (nx2462), .B (nx2454), .S (nx1355)) ;
    MX2L0 ix2463 (.X (nx2462), .A (nx907), .B (nx601), .S (nx1085)) ;
    MX2L0 ix2455 (.X (nx2454), .A (nx1189), .B (nx1305), .S (nx1886)) ;
    MX2L0 ix1190 (.X (nx1189), .A (nx1210), .B (nx1202), .S (nx1271)) ;
    MX2L0 ix1211 (.X (nx1210), .A (nx915), .B (nx913), .S (nx1015)) ;
    MX2L0 ix1203 (.X (nx1202), .A (nx1193), .B (nx1195), .S (nx1229)) ;
    MX2L0 ix1194 (.X (nx1193), .A (nx518), .B (nx526), .S (nx981)) ;
    MX2L0 ix1196 (.X (nx1195), .A (nx266), .B (nx186), .S (nx286)) ;
    MX2L0 ix187 (.X (nx186), .A (nx923), .B (nx921), .S (nx947)) ;
    OAI2N2 ix287 (.X (nx286), .A1 (nx1201), .A2 (nx1203), .B1 (nx194), .B2 (
           nx1227)) ;
    ND2N0 ix1202 (.X (nx1201), .A1 (x7[3]), .A2 (x8[3])) ;
    AO2L0 ix1204 (.X (nx1203), .A1 (nx210), .A2 (nx1207), .B1 (nx272), .B2 (
          nx248)) ;
    NR3R0 ix273 (.X (nx272), .A1 (nx1211), .A2 (nx186), .A3 (nx1221)) ;
    AO2A0 ix1212 (.X (nx1211), .A1 (nx242), .A2 (nx1215), .B1 (nx218), .B2 (
          nx1219)) ;
    MX2L0 ix243 (.X (nx242), .A (nx961), .B (nx973), .S (nx947)) ;
    MX2L0 ix1216 (.X (nx1215), .A (x7[1]), .B (x8[1]), .S (nx34)) ;
    MX2L0 ix219 (.X (nx218), .A (nx951), .B (nx967), .S (nx947)) ;
    MX2L0 ix1220 (.X (nx1219), .A (x7[2]), .B (x8[2]), .S (nx34)) ;
    MX2L0 ix1222 (.X (nx1221), .A (x7[0]), .B (x8[0]), .S (nx34)) ;
    AO2L0 ix249 (.X (nx248), .A1 (nx218), .A2 (nx1219), .B1 (nx1215), .B2 (nx242
          )) ;
    NR2R0 ix195 (.X (nx194), .A1 (nx977), .A2 (nx1009)) ;
    AN2T0 ix1228 (.X (nx1227), .A1 (nx1203), .A2 (nx1201)) ;
    OAOI2 ix1230 (.X (nx1229), .A1 (nx636), .A2 (nx562), .B (nx1267), .C (nx644)
          ) ;
    OAI3N0 ix637 (.X (nx636), .A1 (nx1233), .A2 (nx578), .B1 (nx1237), .B2 (
           nx1251)) ;
    MX2L0 ix1234 (.X (nx1233), .A (nx210), .B (nx218), .S (nx286)) ;
    ND3N0 ix1238 (.X (nx1237), .A1 (nx618), .A2 (nx294), .A3 (nx1193)) ;
    AO2I0 ix619 (.X (nx618), .A1 (nx602), .A2 (nx1243), .B1 (nx578), .B2 (nx1233
          )) ;
    MX2L0 ix1244 (.X (nx1243), .A (nx234), .B (nx242), .S (nx286)) ;
    OAI3N0 ix1252 (.X (nx1251), .A1 (nx1253), .A2 (nx570), .B1 (nx594), .B2 (
           nx1261)) ;
    MX2L0 ix1254 (.X (nx1253), .A (nx462), .B (nx470), .S (nx981)) ;
    MX2L0 ix1262 (.X (nx1261), .A (nx486), .B (nx494), .S (nx981)) ;
    ND2N0 ix1268 (.X (nx1267), .A1 (nx454), .A2 (nx302)) ;
    AN2T0 ix645 (.X (nx644), .A1 (nx562), .A2 (nx636)) ;
    OAOI2 ix1272 (.X (nx1271), .A1 (nx1220), .A2 (nx770), .B (nx1301), .C (
          nx1228)) ;
    OAI3N0 ix1221 (.X (nx1220), .A1 (nx1275), .A2 (nx1154), .B1 (nx1279), .B2 (
           nx1287)) ;
    MX2L0 ix1155 (.X (nx1154), .A (nx1019), .B (nx1035), .S (nx1015)) ;
    ND3N0 ix1280 (.X (nx1279), .A1 (nx1194), .A2 (nx1202), .A3 (nx1285)) ;
    AO2I0 ix1195 (.X (nx1194), .A1 (nx1178), .A2 (nx1283), .B1 (nx1154), .B2 (
          nx1275)) ;
    MX2L0 ix1179 (.X (nx1178), .A (nx1029), .B (nx1041), .S (nx1015)) ;
    OAI3N0 ix1288 (.X (nx1287), .A1 (nx1289), .A2 (nx1146), .B1 (nx1170), .B2 (
           nx1295)) ;
    MX2L0 ix1147 (.X (nx1146), .A (nx1253), .B (nx1233), .S (nx1229)) ;
    MX2L0 ix1171 (.X (nx1170), .A (nx1261), .B (nx1243), .S (nx1229)) ;
    ND2N0 ix771 (.X (nx770), .A1 (nx1299), .A2 (nx1267)) ;
    NR2R0 ix1300 (.X (nx1299), .A1 (nx202), .A2 (nx194)) ;
    AN2T0 ix1229 (.X (nx1228), .A1 (nx770), .A2 (nx1220)) ;
    MX2L0 ix1306 (.X (nx1305), .A (nx1758), .B (nx1766), .S (nx1051)) ;
    OAI2N2 ix1887 (.X (nx1886), .A1 (nx1794), .A2 (nx1311), .B1 (nx1343), .B2 (
           nx1345)) ;
    NR2R0 ix1795 (.X (nx1794), .A1 (nx1081), .A2 (nx1119)) ;
    NR2R0 ix1312 (.X (nx1311), .A1 (nx1876), .A2 (nx1462)) ;
    OAI3N0 ix1877 (.X (nx1876), .A1 (nx1315), .A2 (nx1810), .B1 (nx1319), .B2 (
           nx1329)) ;
    MX2L0 ix1316 (.X (nx1315), .A (nx1154), .B (nx1146), .S (nx1271)) ;
    ND3N0 ix1320 (.X (nx1319), .A1 (nx1850), .A2 (nx1858), .A3 (nx1305)) ;
    AO2I0 ix1851 (.X (nx1850), .A1 (nx1834), .A2 (nx1325), .B1 (nx1810), .B2 (
          nx1315)) ;
    MX2L0 ix1326 (.X (nx1325), .A (nx1178), .B (nx1170), .S (nx1271)) ;
    MX2L0 ix1332 (.X (nx1331), .A (nx1702), .B (nx1710), .S (nx1051)) ;
    MX2L0 ix1338 (.X (nx1337), .A (nx1726), .B (nx1734), .S (nx1051)) ;
    NR2R0 ix1139 (.X (nx1138), .A1 (nx1047), .A2 (nx1079)) ;
    NR2R0 ix1344 (.X (nx1343), .A1 (nx770), .A2 (nx1138)) ;
    AO2L0 ix1841 (.X (nx1840), .A1 (nx1810), .A2 (nx1315), .B1 (nx1325), .B2 (
          nx1834)) ;
    OAOI2 ix1356 (.X (nx1355), .A1 (nx2472), .A2 (nx2166), .B (nx1383), .C (
          nx2480)) ;
    OAI3N0 ix2473 (.X (nx2472), .A1 (nx1359), .A2 (nx2406), .B1 (nx1363), .B2 (
           nx1371)) ;
    MX2L0 ix2407 (.X (nx2406), .A (nx1089), .B (nx1107), .S (nx1085)) ;
    ND3N0 ix1364 (.X (nx1363), .A1 (nx2446), .A2 (nx2454), .A3 (nx1369)) ;
    AO2I0 ix2447 (.X (nx2446), .A1 (nx2430), .A2 (nx1367), .B1 (nx2406), .B2 (
          nx1359)) ;
    MX2L0 ix2431 (.X (nx2430), .A (nx1101), .B (nx1113), .S (nx1085)) ;
    OAI3N0 ix1372 (.X (nx1371), .A1 (nx1373), .A2 (nx2398), .B1 (nx2422), .B2 (
           nx1379)) ;
    MX2L0 ix2399 (.X (nx2398), .A (nx1315), .B (nx1331), .S (nx1886)) ;
    MX2L0 ix2423 (.X (nx2422), .A (nx1325), .B (nx1337), .S (nx1886)) ;
    ND2N0 ix1384 (.X (nx1383), .A1 (nx2290), .A2 (nx2174)) ;
    AN2T0 ix2481 (.X (nx2480), .A1 (nx2166), .A2 (nx2472)) ;
    OAOI2 ix1388 (.X (nx1387), .A1 (nx2852), .A2 (nx2778), .B (nx1421), .C (
          nx2860)) ;
    OAI3N0 ix2853 (.X (nx2852), .A1 (nx1391), .A2 (nx2794), .B1 (nx1395), .B2 (
           nx1405)) ;
    MX2L0 ix1392 (.X (nx1391), .A (nx2406), .B (nx2398), .S (nx1355)) ;
    ND3N0 ix1396 (.X (nx1395), .A1 (nx2834), .A2 (nx2654), .A3 (nx1177)) ;
    AO2I0 ix2835 (.X (nx2834), .A1 (nx2818), .A2 (nx1401), .B1 (nx2794), .B2 (
          nx1391)) ;
    MX2L0 ix1402 (.X (nx1401), .A (nx2430), .B (nx2422), .S (nx1355)) ;
    OAI3N0 ix1406 (.X (nx1405), .A1 (nx1407), .A2 (nx2786), .B1 (nx2810), .B2 (
           nx1413)) ;
    MX2L0 ix1408 (.X (nx1407), .A (nx2686), .B (nx2678), .S (nx2762)) ;
    MX2L0 ix1414 (.X (nx1413), .A (nx2710), .B (nx2702), .S (nx2762)) ;
    ND2N0 ix2779 (.X (nx2778), .A1 (nx1419), .A2 (nx1383)) ;
    NR2R0 ix1420 (.X (nx1419), .A1 (nx1462), .A2 (nx1794)) ;
    ND2N0 ix1422 (.X (nx1421), .A1 (nx2670), .A2 (nx2662)) ;
    AN2T0 ix2861 (.X (nx2860), .A1 (nx2778), .A2 (nx2852)) ;
    MX2L0 ix2911 (.X (y2[1]), .A (nx1413), .B (nx1401), .S (nx1387)) ;
    MX2L0 ix2919 (.X (y2[2]), .A (nx1407), .B (nx1391), .S (nx1387)) ;
    ND2N0 ix2927 (.X (y2[3]), .A1 (nx1431), .A2 (nx1421)) ;
    MX2L0 ix2871 (.X (y3[0]), .A (nx1183), .B (nx1177), .S (nx1387)) ;
    MX2L0 ix2879 (.X (y3[1]), .A (nx1401), .B (nx1413), .S (nx1387)) ;
    MX2L0 ix2887 (.X (y3[2]), .A (nx1391), .B (nx1407), .S (nx1387)) ;
    NR2R0 ix2895 (.X (y3[3]), .A1 (nx1421), .A2 (nx1431)) ;
    MX2L0 ix2623 (.X (y4[0]), .A (nx1443), .B (nx1445), .S (nx1563)) ;
    MX2L0 ix1444 (.X (nx1443), .A (nx2454), .B (nx2462), .S (nx1355)) ;
    MX2L0 ix1446 (.X (nx1445), .A (nx1966), .B (nx1958), .S (nx1527)) ;
    MX2L0 ix1967 (.X (nx1966), .A (nx1305), .B (nx1189), .S (nx1886)) ;
    MX2L0 ix1959 (.X (nx1958), .A (nx1451), .B (nx1453), .S (nx1489)) ;
    MX2L0 ix1452 (.X (nx1451), .A (nx1202), .B (nx1210), .S (nx1271)) ;
    MX2L0 ix1454 (.X (nx1453), .A (nx734), .B (nx654), .S (nx754)) ;
    MX2L0 ix655 (.X (nx654), .A (nx1195), .B (nx1193), .S (nx1229)) ;
    OAI2N2 ix755 (.X (nx754), .A1 (nx1459), .A2 (nx1463), .B1 (nx662), .B2 (
           nx1487)) ;
    ND3N0 ix1460 (.X (nx1459), .A1 (nx86), .A2 (x8[3]), .A3 (x7[3])) ;
    AO2L0 ix1464 (.X (nx1463), .A1 (nx678), .A2 (nx1467), .B1 (nx740), .B2 (
          nx716)) ;
    NR3R0 ix741 (.X (nx740), .A1 (nx1471), .A2 (nx654), .A3 (nx1481)) ;
    AO2A0 ix1472 (.X (nx1471), .A1 (nx710), .A2 (nx1475), .B1 (nx686), .B2 (
          nx1479)) ;
    MX2L0 ix711 (.X (nx710), .A (nx1243), .B (nx1261), .S (nx1229)) ;
    MX2L0 ix1476 (.X (nx1475), .A (nx242), .B (nx234), .S (nx286)) ;
    MX2L0 ix687 (.X (nx686), .A (nx1233), .B (nx1253), .S (nx1229)) ;
    MX2L0 ix1480 (.X (nx1479), .A (nx218), .B (nx210), .S (nx286)) ;
    MX2L0 ix1482 (.X (nx1481), .A (nx186), .B (nx266), .S (nx286)) ;
    AO2L0 ix717 (.X (nx716), .A1 (nx686), .A2 (nx1479), .B1 (nx1475), .B2 (nx710
          )) ;
    NR2R0 ix663 (.X (nx662), .A1 (nx1267), .A2 (nx1299)) ;
    AN2T0 ix1488 (.X (nx1487), .A1 (nx1463), .A2 (nx1459)) ;
    OAOI2 ix1490 (.X (nx1489), .A1 (nx1320), .A2 (nx1246), .B (nx1523), .C (
          nx1328)) ;
    OAI3N0 ix1321 (.X (nx1320), .A1 (nx1493), .A2 (nx1262), .B1 (nx1497), .B2 (
           nx1509)) ;
    MX2L0 ix1494 (.X (nx1493), .A (nx678), .B (nx686), .S (nx754)) ;
    ND3N0 ix1498 (.X (nx1497), .A1 (nx1302), .A2 (nx762), .A3 (nx1451)) ;
    AO2I0 ix1303 (.X (nx1302), .A1 (nx1286), .A2 (nx1503), .B1 (nx1262), .B2 (
          nx1493)) ;
    MX2L0 ix1504 (.X (nx1503), .A (nx702), .B (nx710), .S (nx754)) ;
    OAI3N0 ix1510 (.X (nx1509), .A1 (nx1511), .A2 (nx1254), .B1 (nx1278), .B2 (
           nx1519)) ;
    MX2L0 ix1512 (.X (nx1511), .A (nx1146), .B (nx1154), .S (nx1271)) ;
    MX2L0 ix1520 (.X (nx1519), .A (nx1170), .B (nx1178), .S (nx1271)) ;
    ND2N0 ix1524 (.X (nx1523), .A1 (nx1138), .A2 (nx770)) ;
    AN2T0 ix1329 (.X (nx1328), .A1 (nx1246), .A2 (nx1320)) ;
    OAOI2 ix1528 (.X (nx1527), .A1 (nx1976), .A2 (nx1454), .B (nx1559), .C (
          nx1984)) ;
    OAI3N0 ix1977 (.X (nx1976), .A1 (nx1531), .A2 (nx1910), .B1 (nx1535), .B2 (
           nx1545)) ;
    MX2L0 ix1911 (.X (nx1910), .A (nx1331), .B (nx1315), .S (nx1886)) ;
    ND3N0 ix1536 (.X (nx1535), .A1 (nx1950), .A2 (nx1958), .A3 (nx1543)) ;
    AO2I0 ix1951 (.X (nx1950), .A1 (nx1934), .A2 (nx1541), .B1 (nx1910), .B2 (
          nx1531)) ;
    MX2L0 ix1935 (.X (nx1934), .A (nx1337), .B (nx1325), .S (nx1886)) ;
    OAI3N0 ix1546 (.X (nx1545), .A1 (nx1547), .A2 (nx1902), .B1 (nx1926), .B2 (
           nx1553)) ;
    MX2L0 ix1903 (.X (nx1902), .A (nx1511), .B (nx1493), .S (nx1489)) ;
    MX2L0 ix1927 (.X (nx1926), .A (nx1519), .B (nx1503), .S (nx1489)) ;
    ND2N0 ix1455 (.X (nx1454), .A1 (nx1557), .A2 (nx1523)) ;
    NR2R0 ix1558 (.X (nx1557), .A1 (nx670), .A2 (nx662)) ;
    ND2N0 ix1560 (.X (nx1559), .A1 (nx1794), .A2 (nx1462)) ;
    AN2T0 ix1985 (.X (nx1984), .A1 (nx1454), .A2 (nx1976)) ;
    OAOI2 ix1564 (.X (nx1563), .A1 (nx2572), .A2 (nx2498), .B (nx1595), .C (
          nx2580)) ;
    OAI3N0 ix2573 (.X (nx2572), .A1 (nx1567), .A2 (nx2514), .B1 (nx1571), .B2 (
           nx1581)) ;
    MX2L0 ix1568 (.X (nx1567), .A (nx1910), .B (nx1902), .S (nx1527)) ;
    ND3N0 ix1572 (.X (nx1571), .A1 (nx2554), .A2 (nx2158), .A3 (nx1443)) ;
    AO2I0 ix2555 (.X (nx2554), .A1 (nx2538), .A2 (nx1577), .B1 (nx2514), .B2 (
          nx1567)) ;
    MX2L0 ix1578 (.X (nx1577), .A (nx1934), .B (nx1926), .S (nx1527)) ;
    OAI3N0 ix1582 (.X (nx1581), .A1 (nx1583), .A2 (nx2506), .B1 (nx2530), .B2 (
           nx1589)) ;
    MX2L0 ix1584 (.X (nx1583), .A (nx2398), .B (nx2406), .S (nx1355)) ;
    MX2L0 ix1590 (.X (nx1589), .A (nx2422), .B (nx2430), .S (nx1355)) ;
    ND2N0 ix2499 (.X (nx2498), .A1 (nx1593), .A2 (nx1559)) ;
    AN2T0 ix2581 (.X (nx2580), .A1 (nx2498), .A2 (nx2572)) ;
    MX2L0 ix2631 (.X (y4[1]), .A (nx1589), .B (nx1577), .S (nx1563)) ;
    MX2L0 ix2639 (.X (y4[2]), .A (nx1583), .B (nx1567), .S (nx1563)) ;
    OR2T0 ix2647 (.X (y4[3]), .A1 (nx2498), .A2 (nx2490)) ;
    NR2R0 ix2491 (.X (nx2490), .A1 (nx1383), .A2 (nx1419)) ;
    MX2L0 ix2591 (.X (y5[0]), .A (nx1445), .B (nx1443), .S (nx1563)) ;
    MX2L0 ix2599 (.X (y5[1]), .A (nx1577), .B (nx1589), .S (nx1563)) ;
    MX2L0 ix2607 (.X (y5[2]), .A (nx1567), .B (nx1583), .S (nx1563)) ;
    AN2T0 ix2615 (.X (y5[3]), .A1 (nx2490), .A2 (nx2498)) ;
    MX2L0 ix2127 (.X (y6[0]), .A (nx1613), .B (nx1647), .S (nx2086)) ;
    MX2L0 ix1614 (.X (nx1613), .A (nx1418), .B (nx1338), .S (nx1438)) ;
    MX2L0 ix1339 (.X (nx1338), .A (nx1453), .B (nx1451), .S (nx1489)) ;
    OAI2N2 ix1439 (.X (nx1438), .A1 (nx1619), .A2 (nx1621), .B1 (nx1346), .B2 (
           nx1645)) ;
    ND2N0 ix1620 (.X (nx1619), .A1 (nx662), .A2 (nx670)) ;
    AO2L0 ix1622 (.X (nx1621), .A1 (nx1362), .A2 (nx1625), .B1 (nx1424), .B2 (
          nx1400)) ;
    NR3R0 ix1425 (.X (nx1424), .A1 (nx1629), .A2 (nx1338), .A3 (nx1639)) ;
    AO2A0 ix1630 (.X (nx1629), .A1 (nx1394), .A2 (nx1633), .B1 (nx1370), .B2 (
          nx1637)) ;
    MX2L0 ix1395 (.X (nx1394), .A (nx1503), .B (nx1519), .S (nx1489)) ;
    MX2L0 ix1634 (.X (nx1633), .A (nx710), .B (nx702), .S (nx754)) ;
    MX2L0 ix1371 (.X (nx1370), .A (nx1493), .B (nx1511), .S (nx1489)) ;
    MX2L0 ix1638 (.X (nx1637), .A (nx686), .B (nx678), .S (nx754)) ;
    MX2L0 ix1640 (.X (nx1639), .A (nx654), .B (nx734), .S (nx754)) ;
    AO2L0 ix1401 (.X (nx1400), .A1 (nx1370), .A2 (nx1637), .B1 (nx1633), .B2 (
          nx1394)) ;
    NR2R0 ix1347 (.X (nx1346), .A1 (nx1523), .A2 (nx1557)) ;
    AN2T0 ix1646 (.X (nx1645), .A1 (nx1621), .A2 (nx1619)) ;
    MX2L0 ix1648 (.X (nx1647), .A (nx1958), .B (nx1966), .S (nx1527)) ;
    OAI2N2 ix2087 (.X (nx2086), .A1 (nx1994), .A2 (nx1653), .B1 (nx1691), .B2 (
           nx1693)) ;
    NR2R0 ix1995 (.X (nx1994), .A1 (nx1559), .A2 (nx1593)) ;
    NR2R0 ix1654 (.X (nx1653), .A1 (nx2076), .A2 (nx2002)) ;
    OAI3N0 ix2077 (.X (nx2076), .A1 (nx1657), .A2 (nx2018), .B1 (nx1661), .B2 (
           nx1675)) ;
    MX2L0 ix1658 (.X (nx1657), .A (nx1362), .B (nx1370), .S (nx1438)) ;
    MX2L0 ix1668 (.X (nx1667), .A (nx1386), .B (nx1394), .S (nx1438)) ;
    OAI3N0 ix1676 (.X (nx1675), .A1 (nx1677), .A2 (nx2010), .B1 (nx2034), .B2 (
           nx1685)) ;
    MX2L0 ix1678 (.X (nx1677), .A (nx1902), .B (nx1910), .S (nx1527)) ;
    MX2L0 ix1686 (.X (nx1685), .A (nx1926), .B (nx1934), .S (nx1527)) ;
    NR2R0 ix1692 (.X (nx1691), .A1 (nx1354), .A2 (nx1346)) ;
    OAI2N0 ix1698 (.X (nx1697), .A1 (nx1685), .A2 (nx2034), .B1 (nx1677), .B2 (
           nx2010)) ;
    MX2L0 ix2135 (.X (y6[1]), .A (nx1667), .B (nx1685), .S (nx2086)) ;
    MX2L0 ix2143 (.X (y6[2]), .A (nx1657), .B (nx1677), .S (nx2086)) ;
    OR2T0 ix2151 (.X (y6[3]), .A1 (nx2002), .A2 (nx1994)) ;
    MX2L0 ix2095 (.X (y7[0]), .A (nx1647), .B (nx1613), .S (nx2086)) ;
    MX2L0 ix2103 (.X (y7[1]), .A (nx1685), .B (nx1667), .S (nx2086)) ;
    MX2L0 ix2111 (.X (y7[2]), .A (nx1677), .B (nx1657), .S (nx2086)) ;
    AN2T0 ix2119 (.X (y7[3]), .A1 (nx1994), .A2 (nx2002)) ;
    MX2L0 ix2935 (.X (y8[0]), .A (nx1673), .B (nx1639), .S (nx1438)) ;
    MX2L0 ix2943 (.X (y8[1]), .A (nx1683), .B (nx1633), .S (nx1438)) ;
    MX2L0 ix2951 (.X (y8[2]), .A (nx1625), .B (nx1637), .S (nx1438)) ;
    AN2T0 ix2959 (.X (y8[3]), .A1 (nx1346), .A2 (nx1354)) ;
    IV1N0 ix2819 (.X (nx2818), .A (nx1413)) ;
    IV1N0 ix2811 (.X (nx2810), .A (nx1401)) ;
    IV1N0 ix2795 (.X (nx2794), .A (nx1407)) ;
    IV1N0 ix2787 (.X (nx2786), .A (nx1391)) ;
    IV1N0 ix1432 (.X (nx1431), .A (nx2778)) ;
    IV1N0 ix1164 (.X (nx1163), .A (nx2752)) ;
    IV1N0 ix2743 (.X (nx2742), .A (nx1127)) ;
    IV1N0 ix600 (.X (nx599), .A (nx2734)) ;
    IV1N0 ix2711 (.X (nx2710), .A (nx1145)) ;
    IV1N0 ix1172 (.X (nx1171), .A (nx2702)) ;
    IV1N0 ix2687 (.X (nx2686), .A (nx1149)) ;
    IV1N0 ix1138 (.X (nx1137), .A (nx2678)) ;
    IV1N0 ix2663 (.X (nx2662), .A (nx1161)) ;
    IV1N0 ix2655 (.X (nx2654), .A (nx1183)) ;
    IV1N0 ix2539 (.X (nx2538), .A (nx1589)) ;
    IV1N0 ix2531 (.X (nx2530), .A (nx1577)) ;
    IV1N0 ix2515 (.X (nx2514), .A (nx1583)) ;
    IV1N0 ix2507 (.X (nx2506), .A (nx1567)) ;
    IV1N0 ix1596 (.X (nx1595), .A (nx2490)) ;
    IV1N0 ix1370 (.X (nx1369), .A (nx2462)) ;
    IV1N0 ix1380 (.X (nx1379), .A (nx2430)) ;
    IV1N0 ix1368 (.X (nx1367), .A (nx2422)) ;
    IV1N0 ix1374 (.X (nx1373), .A (nx2406)) ;
    IV1N0 ix1360 (.X (nx1359), .A (nx2398)) ;
    IV1N0 ix2355 (.X (nx2354), .A (nx907)) ;
    IV1N0 ix2331 (.X (nx2330), .A (nx1113)) ;
    IV1N0 ix2323 (.X (nx2322), .A (nx1101)) ;
    IV1N0 ix2307 (.X (nx2306), .A (nx1107)) ;
    IV1N0 ix2299 (.X (nx2298), .A (nx1089)) ;
    IV1N0 ix1122 (.X (nx1121), .A (nx2290)) ;
    IV1N0 ix2263 (.X (nx2262), .A (nx897)) ;
    IV1N0 ix2231 (.X (nx2230), .A (nx889)) ;
    IV1N0 ix2207 (.X (nx2206), .A (nx893)) ;
    IV1N0 ix882 (.X (nx881), .A (nx2198)) ;
    IV1N0 ix2183 (.X (nx2182), .A (nx1123)) ;
    IV1N0 ix2167 (.X (nx2166), .A (nx1419)) ;
    IV1N0 ix2159 (.X (nx2158), .A (nx1445)) ;
    IV1N0 ix1694 (.X (nx1693), .A (nx2076)) ;
    IV1N0 ix2035 (.X (nx2034), .A (nx1667)) ;
    IV1N0 ix2019 (.X (nx2018), .A (nx1677)) ;
    IV1N0 ix2011 (.X (nx2010), .A (nx1657)) ;
    IV1N0 ix2003 (.X (nx2002), .A (nx1691)) ;
    IV1N0 ix1544 (.X (nx1543), .A (nx1966)) ;
    IV1N0 ix1554 (.X (nx1553), .A (nx1934)) ;
    IV1N0 ix1542 (.X (nx1541), .A (nx1926)) ;
    IV1N0 ix1548 (.X (nx1547), .A (nx1910)) ;
    IV1N0 ix1532 (.X (nx1531), .A (nx1902)) ;
    IV1N0 ix1346 (.X (nx1345), .A (nx1876)) ;
    IV1N0 ix1859 (.X (nx1858), .A (nx1189)) ;
    IV1N0 ix1330 (.X (nx1329), .A (nx1840)) ;
    IV1N0 ix1835 (.X (nx1834), .A (nx1337)) ;
    IV1N0 ix1811 (.X (nx1810), .A (nx1331)) ;
    IV1N0 ix1066 (.X (nx1065), .A (nx1766)) ;
    IV1N0 ix1076 (.X (nx1075), .A (nx1734)) ;
    IV1N0 ix1064 (.X (nx1063), .A (nx1726)) ;
    IV1N0 ix1070 (.X (nx1069), .A (nx1710)) ;
    IV1N0 ix1056 (.X (nx1055), .A (nx1702)) ;
    IV1N0 ix866 (.X (nx865), .A (nx1676)) ;
    IV1N0 ix1659 (.X (nx1658), .A (nx605)) ;
    IV1N0 ix1635 (.X (nx1634), .A (nx855)) ;
    IV1N0 ix1627 (.X (nx1626), .A (nx843)) ;
    IV1N0 ix1611 (.X (nx1610), .A (nx849)) ;
    IV1N0 ix1603 (.X (nx1602), .A (nx831)) ;
    IV1N0 ix1567 (.X (nx1566), .A (nx811)) ;
    IV1N0 ix1535 (.X (nx1534), .A (nx803)) ;
    IV1N0 ix1511 (.X (nx1510), .A (nx807)) ;
    IV1N0 ix796 (.X (nx795), .A (nx1502)) ;
    IV1N0 ix826 (.X (nx825), .A (nx1486)) ;
    IV1N0 ix1479 (.X (nx1478), .A (nx863)) ;
    IV1N0 ix1120 (.X (nx1119), .A (nx1470)) ;
    IV1N0 ix1463 (.X (nx1462), .A (nx1343)) ;
    IV1N0 ix1594 (.X (nx1593), .A (nx1454)) ;
    IV1N0 ix1419 (.X (nx1418), .A (nx1639)) ;
    IV1N0 ix1684 (.X (nx1683), .A (nx1394)) ;
    IV1N0 ix1387 (.X (nx1386), .A (nx1633)) ;
    IV1N0 ix1626 (.X (nx1625), .A (nx1370)) ;
    IV1N0 ix1363 (.X (nx1362), .A (nx1637)) ;
    IV1N0 ix1355 (.X (nx1354), .A (nx1619)) ;
    IV1N0 ix1674 (.X (nx1673), .A (nx1338)) ;
    IV1N0 ix1287 (.X (nx1286), .A (nx1519)) ;
    IV1N0 ix1279 (.X (nx1278), .A (nx1503)) ;
    IV1N0 ix1263 (.X (nx1262), .A (nx1511)) ;
    IV1N0 ix1255 (.X (nx1254), .A (nx1493)) ;
    IV1N0 ix1247 (.X (nx1246), .A (nx1557)) ;
    IV1N0 ix1286 (.X (nx1285), .A (nx1210)) ;
    IV1N0 ix1296 (.X (nx1295), .A (nx1178)) ;
    IV1N0 ix1284 (.X (nx1283), .A (nx1170)) ;
    IV1N0 ix1290 (.X (nx1289), .A (nx1154)) ;
    IV1N0 ix1276 (.X (nx1275), .A (nx1146)) ;
    IV1N0 ix1302 (.X (nx1301), .A (nx1138)) ;
    IV1N0 ix1103 (.X (nx1102), .A (nx915)) ;
    IV1N0 ix1079 (.X (nx1078), .A (nx1041)) ;
    IV1N0 ix1071 (.X (nx1070), .A (nx1029)) ;
    IV1N0 ix1055 (.X (nx1054), .A (nx1035)) ;
    IV1N0 ix1047 (.X (nx1046), .A (nx1019)) ;
    IV1N0 ix768 (.X (nx767), .A (nx1010)) ;
    IV1N0 ix776 (.X (nx775), .A (nx978)) ;
    IV1N0 ix766 (.X (nx765), .A (nx970)) ;
    IV1N0 ix772 (.X (nx771), .A (nx954)) ;
    IV1N0 ix756 (.X (nx755), .A (nx946)) ;
    IV1N0 ix782 (.X (nx781), .A (nx938)) ;
    IV1N0 ix903 (.X (nx902), .A (nx609)) ;
    IV1N0 ix879 (.X (nx878), .A (nx683)) ;
    IV1N0 ix871 (.X (nx870), .A (nx671)) ;
    IV1N0 ix855 (.X (nx854), .A (nx677)) ;
    IV1N0 ix847 (.X (nx846), .A (nx661)) ;
    IV1N0 ix795 (.X (nx794), .A (nx783)) ;
    IV1N0 ix779 (.X (nx778), .A (nx1079)) ;
    IV1N0 ix763 (.X (nx762), .A (nx1453)) ;
    IV1N0 ix735 (.X (nx734), .A (nx1481)) ;
    IV1N0 ix703 (.X (nx702), .A (nx1475)) ;
    IV1N0 ix1468 (.X (nx1467), .A (nx686)) ;
    IV1N0 ix679 (.X (nx678), .A (nx1479)) ;
    IV1N0 ix671 (.X (nx670), .A (nx1459)) ;
    IV1N0 ix603 (.X (nx602), .A (nx1261)) ;
    IV1N0 ix595 (.X (nx594), .A (nx1243)) ;
    IV1N0 ix579 (.X (nx578), .A (nx1253)) ;
    IV1N0 ix571 (.X (nx570), .A (nx1233)) ;
    IV1N0 ix563 (.X (nx562), .A (nx1299)) ;
    IV1N0 ix996 (.X (nx995), .A (nx526)) ;
    IV1N0 ix1006 (.X (nx1005), .A (nx494)) ;
    IV1N0 ix994 (.X (nx993), .A (nx486)) ;
    IV1N0 ix1000 (.X (nx999), .A (nx470)) ;
    IV1N0 ix986 (.X (nx985), .A (nx462)) ;
    IV1N0 ix1012 (.X (nx1011), .A (nx454)) ;
    IV1N0 ix419 (.X (nx418), .A (nx695)) ;
    IV1N0 ix395 (.X (nx394), .A (nx743)) ;
    IV1N0 ix387 (.X (nx386), .A (nx731)) ;
    IV1N0 ix371 (.X (nx370), .A (nx737)) ;
    IV1N0 ix363 (.X (nx362), .A (nx723)) ;
    IV1N0 ix311 (.X (nx310), .A (nx779)) ;
    IV1N0 ix295 (.X (nx294), .A (nx1195)) ;
    IV1N0 ix267 (.X (nx266), .A (nx1221)) ;
    IV1N0 ix235 (.X (nx234), .A (nx1215)) ;
    IV1N0 ix1208 (.X (nx1207), .A (nx218)) ;
    IV1N0 ix211 (.X (nx210), .A (nx1219)) ;
    IV1N0 ix203 (.X (nx202), .A (nx1201)) ;
    IV1N0 ix135 (.X (nx134), .A (nx973)) ;
    IV1N0 ix127 (.X (nx126), .A (nx961)) ;
    IV1N0 ix111 (.X (nx110), .A (nx967)) ;
    IV1N0 ix103 (.X (nx102), .A (nx951)) ;
    IV1N0 ix95 (.X (nx94), .A (nx1009)) ;
    IV1N0 ix87 (.X (nx86), .A (nx977)) ;
    IV1N0 ix43 (.X (nx42), .A (nx923)) ;
    OR3T0 ix1662 (.X (nx1661), .A1 (nx1697), .A2 (nx1613), .A3 (nx1729)) ;
    IV1N0 ix1728 (.X (nx1729), .A (nx1647)) ;
endmodule


module OR3T0 ( X, A1, A2, A3 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input A3 ;

    wire nx0;



    or (nx0, A3, A2) ;
    or (X, nx0, A1) ;
endmodule


module OAI2N0 ( X, A1, A2, B1, B2 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B1 ;
    input B2 ;

    wire NOT_B1, NOT_B2, nx4, NOT_A1, NOT_A2, nx10;



    assign NOT_B1 = ~B1 ;
    assign NOT_B2 = ~B2 ;
    and (nx4, NOT_B1, NOT_B2) ;
    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (nx10, NOT_A1, NOT_A2) ;
    or (X, nx4, nx10) ;
endmodule


module AO2A0 ( X, A1, A2, B1, B2 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B1 ;
    input B2 ;

    wire nx0, nx2;



    and (nx0, B1, B2) ;
    and (nx2, A1, A2) ;
    or (X, nx0, nx2) ;
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


module OR2T0 ( X, A1, A2 ) ;

    output X ;
    input A1 ;
    input A2 ;




    or (X, A2, A1) ;
endmodule


module NR3R1 ( X, A1, A2, A3 ) ;

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


module OA4R0 ( X, A1, A2, B1, B2 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B1 ;
    input B2 ;

    wire nx0, nx2, nx4, nx6, nx8, nx10;



    and (nx0, A2, B2) ;
    and (nx2, A1, B2) ;
    or (nx4, nx0, nx2) ;
    and (nx6, A2, B1) ;
    or (nx8, nx4, nx6) ;
    and (nx10, A1, B1) ;
    or (X, nx8, nx10) ;
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


module ND2N0 ( X, A1, A2 ) ;

    output X ;
    input A1 ;
    input A2 ;

    wire NOT_A2, NOT_A1;



    assign NOT_A2 = ~A2 ;
    assign NOT_A1 = ~A1 ;
    or (X, NOT_A2, NOT_A1) ;
endmodule


module AO2I0 ( X, A1, A2, B1, B2 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B1 ;
    input B2 ;

    wire NOT_A2, NOT_B2, nx4, NOT_A1, nx8, nx10, NOT_B1, nx14, nx16, nx18;



    assign NOT_A2 = ~A2 ;
    assign NOT_B2 = ~B2 ;
    and (nx4, NOT_A2, NOT_B2) ;
    assign NOT_A1 = ~A1 ;
    and (nx8, NOT_A1, NOT_B2) ;
    or (nx10, nx4, nx8) ;
    assign NOT_B1 = ~B1 ;
    and (nx14, NOT_A2, NOT_B1) ;
    or (nx16, nx10, nx14) ;
    and (nx18, NOT_A1, NOT_B1) ;
    or (X, nx16, nx18) ;
endmodule


module ND3N0 ( X, A1, A2, A3 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input A3 ;

    wire NOT_A3, NOT_A2, nx4, NOT_A1;



    assign NOT_A3 = ~A3 ;
    assign NOT_A2 = ~A2 ;
    or (nx4, NOT_A3, NOT_A2) ;
    assign NOT_A1 = ~A1 ;
    or (X, nx4, NOT_A1) ;
endmodule


module OAOI2 ( X, A1, A2, B, C ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B ;
    input C ;

    wire NOT_A1, NOT_A2, nx4, NOT_C, nx8, NOT_B, nx12;



    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (nx4, NOT_A1, NOT_A2) ;
    assign NOT_C = ~C ;
    and (nx8, nx4, NOT_C) ;
    assign NOT_B = ~B ;
    and (nx12, NOT_B, NOT_C) ;
    or (X, nx8, nx12) ;
endmodule


module AN2T0 ( X, A1, A2 ) ;

    output X ;
    input A1 ;
    input A2 ;




    and (X, A1, A2) ;
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


module OAOI0 ( X, A1, A2, B, C ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B ;
    input C ;

    wire NOT_A1, NOT_A2, nx4, NOT_C, nx8, NOT_B, nx12;



    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (nx4, NOT_A1, NOT_A2) ;
    assign NOT_C = ~C ;
    and (nx8, nx4, NOT_C) ;
    assign NOT_B = ~B ;
    and (nx12, NOT_B, NOT_C) ;
    or (X, nx8, nx12) ;
endmodule


module IV1N0 ( X, A ) ;

    output X ;
    input A ;




    assign X = ~A ;
endmodule


module OAI2N2 ( X, A1, A2, B1, B2 ) ;

    output X ;
    input A1 ;
    input A2 ;
    input B1 ;
    input B2 ;

    wire NOT_B1, NOT_B2, nx4, NOT_A1, NOT_A2, nx10;



    assign NOT_B1 = ~B1 ;
    assign NOT_B2 = ~B2 ;
    and (nx4, NOT_B1, NOT_B2) ;
    assign NOT_A1 = ~A1 ;
    assign NOT_A2 = ~A2 ;
    and (nx10, NOT_A1, NOT_A2) ;
    or (X, nx4, nx10) ;
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

