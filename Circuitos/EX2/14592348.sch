*version 9.1 468315377
u 169
V? 7
R? 5
C? 3
L? 2
PRINT? 13
? 4
@libraries
@analysis
.AC 1 3 0
+0 1
+1 30.55
+2 30.55
.TRAN 0 0 0 0
+0 0.01
+1 120
+3 0.01
.OP 0 
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 4993 
@status
n 0 124:04:23:12:18:40;1716477520 e 
s 2832 124:04:23:12:18:40;1716477520 e 
*page 1 0 970 720 iA
@ports
port 10 GND_EARTH 140 260 h
@parts
part 83 vac 140 210 h
a 0 u 13 0 -9 23 hcn 100 ACMAG=7V
a 0 u 0 0 0 20 hcn 100 ACPHASE=0
a 0 sp 0 0 0 50 hln 100 PART=vac
a 0 a 0:13 0 0 0 hln 100 PKGREF=V6
a 1 ap 9 0 20 10 hcn 100 REFDES=V6
part 3 r 160 90 h
a 0 u 13 0 15 25 hln 100 VALUE=8
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 9 l 500 260 v
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
a 0 ap 9 0 15 0 hln 100 REFDES=L1
part 6 r 460 90 h
a 0 u 13 0 15 25 hln 100 VALUE=5
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
part 4 r 290 260 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=48
part 5 r 390 260 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
a 0 u 13 0 15 25 hln 100 VALUE=24
part 7 c 210 90 h
a 0 u 13 0 15 25 hln 100 VALUE=40m
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
part 8 c 330 90 h
a 0 u 13 0 15 25 hln 100 VALUE=20m
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C2
a 0 ap 9 0 15 0 hln 100 REFDES=C2
part 167 VPRINT1 290 90 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=PRINTV1
a 0 xp 0 0 30 0 hcn 100 REFDES=PRINTV1
a 0 u 0 0 0 30 hcn 100 AC=YES
a 0 u 0 0 0 20 hlb 100 MAG=YES
a 0 u 0 0 0 30 hlb 100 PHASE=YES
a 0 sp 0 0 0 40 hlb 100 PART=VPRINT1
part 120 IPRINT 290 120 d
a 0 x 0:13 0 0 0 hln 100 PKGREF=PRINTI1
a 0 xp 0 0 30 0 hcn 100 REFDES=PRINTI1
a 0 u 0 0 0 30 hcn 100 AC=YES
a 0 u 0 0 0 20 hlb 100 MAG=YES
a 0 u 0 0 0 30 hlb 100 PHASE=YES
a 0 sp 11 0 6 0 hlb 100 PART=IPRINT
part 121 IPRINT 390 120 d
a 0 x 0:13 0 0 0 hln 100 PKGREF=PRINTI2
a 0 xp 0 0 30 0 hcn 100 REFDES=PRINTI2
a 0 u 0 0 0 30 hcn 100 AC=YES
a 0 u 0 0 0 20 hlb 100 MAG=YES
a 0 u 0 0 0 30 hlb 100 PHASE=YES
a 0 sp 11 0 6 0 hlb 100 PART=IPRINT
part 103 IPRINT 440 90 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=PRINTI3
a 0 xp 0 0 30 0 hcn 100 REFDES=PRINTI3
a 0 u 0 0 0 30 hcn 100 AC=YES
a 0 u 0 0 0 20 hlb 100 MAG=YES
a 0 u 0 0 0 30 hlb 100 PHASE=YES
a 0 sp 11 0 6 0 hlb 100 PART=IPRINT
part 168 VPRINT1 390 90 h
a 0 u 0 0 0 30 hcn 100 AC=YES
a 0 u 0 0 0 30 hlb 100 PHASE=YES
a 0 u 0 0 0 20 hlb 100 MAG=YES
a 0 x 0:13 0 0 0 hln 100 PKGREF=PRINTV2
a 0 xp 0 0 30 0 hcn 100 REFDES=PRINTV2
a 0 sp 0 0 0 40 hlb 100 PART=VPRINT1
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
@conn
w 16
a 0 up 0:33 0 0 0 hln 100 V=
s 140 210 140 90 15
s 140 90 160 90 17
a 0 up 33 0 150 89 hct 100 V=
w 96
a 0 up 0:33 0 0 0 hln 100 V=
s 210 90 200 90 94
a 0 up 33 0 205 89 hct 100 V=
w 43
a 0 up 0:33 0 0 0 hln 100 V=
s 500 90 500 200 44
a 0 up 33 0 515 89 hct 100 V=
w 47
a 0 up 0:33 0 0 0 hln 100 V=
s 140 260 140 250 48
s 500 260 390 260 118
a 0 up 33 0 210 259 hct 100 V=
s 290 260 140 260 146
s 390 260 290 260 148
w 160
a 0 up 0:33 0 0 0 hln 100 V=
s 290 140 290 220 155
a 0 up 33 0 292 180 hlt 100 V=
w 166
a 0 up 0:33 0 0 0 hln 100 V=
s 390 140 390 220 161
a 0 up 33 0 392 180 hlt 100 V=
w 151
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0 0 0 0 hln 100 LABEL=N1
s 290 90 290 120 124
a 0 sr 3 0 292 105 hln 100 LABEL=N1
s 240 90 290 90 122
a 0 up 33 0 265 89 hct 100 V=
s 330 90 290 90 126
w 153
a 0 up 0:33 0 0 0 hln 100 V=
a 0 sr 0 0 0 0 hln 100 LABEL=N2
s 390 90 390 120 131
a 0 sr 3 0 392 105 hln 100 LABEL=N2
s 360 90 390 90 129
s 390 90 440 90 133
a 0 up 33 0 415 89 hct 100 V=
@junction
j 140 250
+ p 83 -
+ w 47
j 140 210
+ p 83 +
+ w 16
j 160 90
+ p 3 1
+ w 16
j 210 90
+ p 7 1
+ w 96
j 200 90
+ p 3 2
+ w 96
j 500 260
+ p 9 1
+ w 47
j 500 200
+ p 9 2
+ w 43
j 500 90
+ p 6 2
+ w 43
j 460 90
+ p 103 2
+ p 6 1
j 290 90
+ w 151
+ w 151
j 390 90
+ w 153
+ w 153
j 140 260
+ s 10
+ w 47
j 290 260
+ p 4 1
+ w 47
j 390 260
+ p 5 1
+ w 47
j 290 220
+ p 4 2
+ w 160
j 390 220
+ p 5 2
+ w 166
j 240 90
+ p 7 2
+ w 151
j 330 90
+ p 8 1
+ w 151
j 390 140
+ p 121 2
+ w 166
j 360 90
+ p 8 2
+ w 153
j 440 90
+ p 103 1
+ w 153
j 390 120
+ p 121 1
+ w 153
j 290 140
+ p 120 2
+ w 160
j 290 120
+ p 120 1
+ w 151
j 290 90
+ p 167 1
+ w 151
j 390 90
+ p 168 1
+ w 153
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
