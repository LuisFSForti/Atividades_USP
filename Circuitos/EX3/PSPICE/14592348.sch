*version 9.1 171273444
u 597
V? 5
I? 6
R? 17
C? 5
L? 24
? 34
PRINT? 19
HB? 2
@libraries
@analysis
.AC 1 3 0
+0 1
+1 0.318
+2 0.318
.TRAN 1 0 0 0
+0 0.1s
+1 15
+2 0
+3 50ms
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
pageloc 1 0 15475 
@status
n 0 124:06:03:21:44:00;1720053840 e 
s 0 124:06:03:21:44:01;1720053841 e 
c 124:06:03:21:44:59;1720053899
*page 1 0 970 720 iA
@ports
port 446 gnd_earth 260 280 h
port 447 gnd_earth 660 280 h
port 448 gnd_earth 260 500 h
port 342 gnd_earth 570 430 h
port 517 gnd_earth 570 550 h
@parts
part 4 r 160 180 h
a 0 u 13 0 15 25 hln 100 VALUE=2
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 7 c 260 240 v
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
part 217 c 660 240 v
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C4
a 0 ap 9 0 15 0 hln 100 REFDES=C4
part 216 l 600 180 h
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L14
a 0 ap 9 0 15 0 hln 100 REFDES=L14
part 210 r 560 180 h
a 0 u 13 0 15 25 hln 100 VALUE=2
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R10
a 0 ap 9 0 15 0 hln 100 REFDES=R10
part 5 r 260 120 h
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
part 246 iprint 700 180 h
a 0 u 0 0 0 30 hcn 100 AC=YES
a 0 u 0 0 0 20 hlb 100 MAG=YES
a 0 u 0 0 0 30 hlb 100 PHASE=YES
a 0 u 0 0 0 10 hcn 100 TRAN=YES
a 0 sp 11 0 6 0 hlb 100 PART=iprint
a 0 a 0:13 0 0 0 hln 100 PKGREF=PRINT6
a 0 ap 0 0 30 0 hcn 100 REFDES=PRINT6
part 81 vsin 160 220 h
a 1 u 0 0 0 0 hcn 100 PHASE=90
a 1 u 0 0 0 0 hcn 100 AC=48
a 0 x 0:13 0 0 0 hln 100 PKGREF=V1
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=48
a 1 u 0 0 0 0 hcn 100 FREQ=0.318
a 1 xp 9 0 20 10 hcn 100 REFDES=V1
part 211 vsin 560 220 h
a 1 u 0 0 0 0 hcn 100 PHASE=90
a 1 u 0 0 0 0 hcn 100 AC=48
a 0 x 0:13 0 0 0 hln 100 PKGREF=V2
a 1 xp 9 0 20 10 hcn 100 REFDES=V2
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=48
a 1 u 0 0 0 0 hcn 100 FREQ=0.318
part 11 l 360 280 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L4
a 0 ap 9 0 15 0 hln 100 REFDES=L4
part 213 isin 810 200 h
a 1 u 0 0 0 0 hcn 100 PHASE=42
a 1 u 0 0 0 0 hcn 100 AC=3
a 1 u 0 0 0 0 hcn 100 IOFF=0
a 1 u 0 0 0 0 hcn 100 IAMPL=3
a 1 u 0 0 0 0 hcn 100 FREQ=0.318
a 0 a 0:13 0 0 0 hln 100 PKGREF=I5
a 1 ap 9 0 20 10 hcn 100 REFDES=I5
part 218 l 760 280 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L15
a 0 ap 9 0 15 0 hln 100 REFDES=L15
part 212 r 760 220 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R11
a 0 ap 9 0 15 0 hln 100 REFDES=R11
part 163 r 160 400 h
a 0 u 13 0 15 25 hln 100 VALUE=2
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R7
a 0 ap 9 0 15 0 hln 100 REFDES=R7
part 171 c 260 460 v
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C3
a 0 ap 9 0 15 0 hln 100 REFDES=C3
part 164 vsin 160 440 h
a 1 u 0 0 0 0 hcn 100 PHASE=90
a 1 u 0 0 0 0 hcn 100 AC=48
a 0 x 0:13 0 0 0 hln 100 PKGREF=V3
a 1 xp 9 0 20 10 hcn 100 REFDES=V3
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 VAMPL=48
a 1 u 0 0 0 0 hcn 100 FREQ=0.318
part 168 l 300 340 h
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L9
a 0 ap 9 0 15 0 hln 100 REFDES=L9
part 167 r 260 340 h
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R9
a 0 ap 9 0 15 0 hln 100 REFDES=R9
part 169 l 200 400 h
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L10
a 0 ap 9 0 15 0 hln 100 REFDES=L10
part 166 isin 410 410 h
a 1 u 0 0 0 0 hcn 100 PHASE=42
a 1 u 0 0 0 0 hcn 100 AC=3
a 1 u 0 0 0 0 hcn 100 IOFF=0
a 1 u 0 0 0 0 hcn 100 IAMPL=3
a 1 u 0 0 0 0 hcn 100 FREQ=0.318
a 0 a 0:13 0 0 0 hln 100 PKGREF=I4
a 1 ap 9 0 20 10 hcn 100 REFDES=I4
part 172 l 360 500 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L12
a 0 ap 9 0 15 0 hln 100 REFDES=L12
part 165 r 360 440 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R8
a 0 ap 9 0 15 0 hln 100 REFDES=R8
part 322 r 580 360 h
a 0 u 13 0 15 25 hln 100 VALUE=0.6098
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R15
a 0 ap 9 0 15 0 hln 100 REFDES=R15
part 323 L 640 360 h
a 0 u 13 0 15 25 hln 100 VALUE=0.2561
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L20
a 0 ap 9 0 15 0 hln 100 REFDES=L20
part 402 vsin 570 380 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V4
a 1 xp 9 0 20 10 hcn 100 REFDES=V4
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 FREQ=0.318
a 1 u 0 0 0 0 hcn 100 VAMPL=11.7429
a 1 u 0 0 0 0 hcn 100 AC=11.7429
a 1 u 0 0 0 0 hcn 100 PHASE=-7.736
part 514 r 580 480 h
a 0 u 13 0 15 25 hln 100 VALUE=0.6098
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R16
a 0 ap 9 0 15 0 hln 100 REFDES=R16
part 515 L 640 480 h
a 0 u 13 0 15 25 hln 100 VALUE=0.2561
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L23
a 0 ap 9 0 15 0 hln 100 REFDES=L23
part 516 vsin 570 500 h
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 FREQ=0.318
a 0 x 0:13 0 0 0 hln 100 PKGREF=V5
a 1 u 0 0 0 0 hcn 100 AC=8.075
a 1 u 0 0 0 0 hcn 100 VAMPL=8.075
a 1 u 0 0 0 0 hcn 100 PHASE=15.89
a 1 xp 9 0 20 10 hcn 100 REFDES=V5
part 253 Vprint2 280 400 h
a 0 u 0 0 0 30 hcn 100 AC=YES
a 0 u 0 0 0 20 hlb 100 MAG=YES
a 0 u 0 0 0 30 hlb 100 PHASE=YES
a 0 sp 0 0 0 40 hlb 100 PART=Vprint2
a 0 a 0:13 0 0 0 hln 100 PKGREF=PRINT10
a 0 ap 0 0 30 0 hcn 100 REFDES=PRINT10
part 214 r 660 120 h
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R12
a 0 ap 9 0 15 0 hln 100 REFDES=R12
part 215 l 700 120 h
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L13
a 0 ap 9 0 15 0 hln 100 REFDES=L13
part 10 l 300 120 h
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L3
a 0 ap 9 0 15 0 hln 100 REFDES=L3
part 86 isin 410 200 h
a 1 u 0 0 0 0 hcn 100 AC=3
a 1 u 0 0 0 0 hcn 100 IOFF=0
a 0 a 0:13 0 0 0 hln 100 PKGREF=I2
a 1 ap 9 0 20 10 hcn 100 REFDES=I2
a 1 u 0 0 0 0 hcn 100 IAMPL=3
a 1 u 0 0 0 0 hcn 100 FREQ=0.318
a 1 u 0 0 0 0 hcn 100 PHASE=42
part 513 L 710 490 d
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L22
a 0 ap 9 0 15 0 hln 100 REFDES=L22
part 324 L 710 370 d
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=L
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L21
a 0 ap 9 0 15 0 hln 100 REFDES=L21
part 6 r 360 220 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
part 8 l 200 180 h
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
a 0 ap 9 0 15 0 hln 100 REFDES=L1
part 9 l 280 180 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=L
a 0 xp 9 0 15 0 hln 100 REFDES=L
a 0 u 13 0 15 25 hln 100 VALUE=0.5
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
part 519 nodeMarker 710 490 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=L22:1
a 0 a 0 0 4 22 hlb 100 LABEL=20
part 518 iMarker 710 550 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=-I(L22)
a 0 a 0 0 6 20 hlb 100 LABEL=19
part 347 nodeMarker 710 370 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=L21:1
a 0 a 0 0 4 22 hlb 100 LABEL=20
part 344 iMarker 710 430 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=-I(L21)
a 0 a 0 0 6 20 hlb 100 LABEL=19
part 591 nodeMarker 340 180 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=31
part 592 nodeMarker 280 180 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=32
part 593 iMarker 340 180 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=33
@conn
w 182
a 0 up 0:33 0 0 0 hln 100 V=
s 560 220 560 180 181
a 0 up 33 0 562 201 hlt 100 V=
w 15
a 0 up 0:33 0 0 0 hln 100 V=
s 160 220 160 180 14
a 0 up 33 0 162 201 hlt 100 V=
w 225
a 0 sr 0 0 0 0 hln 100 LABEL=BN
a 0 up 0:33 0 0 0 hln 100 V=
s 660 180 700 180 227
a 0 sr 3 0 680 178 hcn 100 LABEL=BN
s 660 180 660 120 209
a 0 up 33 0 662 150 hlt 100 V=
s 660 210 660 180 205
a 0 up 33 0 662 151 hlt 100 V=
w 19
a 0 up 0:33 0 0 0 hln 100 V=
s 260 280 260 240 69
s 360 280 260 280 63
s 160 280 160 260 24
s 160 280 260 280 20
s 410 280 360 280 53
a 0 up 33 0 385 279 hct 100 V=
s 410 280 410 240 47
w 184
a 0 up 0:33 0 0 0 hln 100 V=
s 660 280 660 240 183
s 560 280 560 260 189
s 560 280 660 280 191
s 760 280 660 280 219
s 810 280 810 240 185
s 810 280 760 280 193
a 0 up 33 0 785 279 hct 100 V=
w 196
a 0 sr 0 0 0 0 hln 100 LABEL=AN
a 0 up 0:33 0 0 0 hln 100 V=
s 720 180 760 180 229
a 0 sr 3 0 740 178 hcn 100 LABEL=AN
s 760 180 760 120 195
a 0 up 33 0 762 151 hlt 100 V=
s 810 200 810 180 201
s 810 180 760 180 398
a 0 up 33 0 800 164 hct 100 V=
w 135
a 0 up 0:33 0 0 0 hln 100 V=
s 160 440 160 400 134
a 0 up 33 0 162 421 hlt 100 V=
w 137
a 0 up 0:33 0 0 0 hln 100 V=
s 160 500 260 500 146
s 160 500 160 480 144
s 260 500 360 500 445
s 260 500 260 460 136
s 410 500 360 500 142
a 0 up 33 0 385 499 hct 100 V=
s 410 500 410 450 140
w 330
a 0 up 0:33 0 0 0 hln 100 V=
s 620 360 640 360 329
a 0 up 33 0 630 359 hct 100 V=
w 326
a 0 up 0:33 0 0 0 hln 100 V=
s 570 380 570 360 325
a 0 up 33 0 532 370 hlt 100 V=
s 570 360 580 360 327
w 504
a 0 up 0:33 0 0 0 hln 100 V=
s 620 480 640 480 503
a 0 up 33 0 630 479 hct 100 V=
w 506
a 0 up 0:33 0 0 0 hln 100 V=
s 570 480 580 480 507
s 570 500 570 480 505
a 0 up 33 0 532 490 hlt 100 V=
w 156
a 0 sr 0:3 0 330 368 hcn 100 LABEL=AT
a 0 up 0:33 0 0 0 hln 100 V=
s 360 400 300 400 240
a 0 sr 3 0 330 398 hcn 100 LABEL=AT
s 360 400 360 340 155
a 0 up 33 0 362 371 hlt 100 V=
s 410 410 410 400 161
s 410 400 360 400 400
a 0 up 33 0 385 399 hct 100 V=
w 149
a 0 sr 0:3 0 270 368 hcn 100 LABEL=BT
a 0 up 0:33 0 0 0 hln 100 V=
s 280 400 260 400 152
a 0 sr 3 0 270 398 hcn 100 LABEL=BT
s 260 430 260 400 150
a 0 up 33 0 262 371 hlt 100 V=
s 260 400 260 340 154
a 0 up 33 0 262 370 hlt 100 V=
w 332
a 0 up 0:33 0 0 0 hln 100 V=
s 700 360 710 360 331
a 0 up 33 0 705 359 hct 100 V=
s 710 360 710 370 333
w 431
a 0 up 0:33 0 0 0 hln 100 V=
s 710 430 570 430 335
a 0 up 33 0 365 429 hct 100 V=
s 570 430 570 420 428
w 500
a 0 up 0:33 0 0 0 hln 100 V=
s 710 480 710 490 501
a 0 up 33 0 712 485 hlt 100 V=
s 700 480 710 480 499
a 0 up 33 0 705 479 hct 100 V=
w 521
a 0 up 0:33 0 0 0 hln 100 V=
s 570 550 570 540 511
s 710 550 570 550 509
a 0 up 33 0 355 549 hct 100 V=
w 573
a 0 up 0:33 0 0 0 hln 100 V=
s 260 180 260 120 16
a 0 up 33 0 262 151 hlt 100 V=
s 260 210 260 180 38
s 280 180 260 180 589
w 550
a 0 up 0:33 0 0 0 hln 100 V=
s 360 180 360 120 32
a 0 up 33 0 362 151 hlt 100 V=
s 410 200 410 180 28
s 410 180 360 180 396
s 360 180 340 180 584
@junction
j 300 120
+ p 5 2
+ p 10 1
j 260 120
+ p 5 1
+ w 573
j 260 180
+ p 8 2
+ w 573
j 260 210
+ p 7 2
+ w 573
j 200 180
+ p 8 1
+ p 4 2
j 160 180
+ p 4 1
+ w 15
j 560 180
+ p 210 1
+ w 182
j 700 120
+ p 215 1
+ p 214 2
j 600 180
+ p 216 1
+ p 210 2
j 760 220
+ p 218 2
+ p 212 1
j 660 120
+ p 214 1
+ w 225
j 660 180
+ p 216 2
+ w 225
j 660 210
+ p 217 2
+ w 225
j 700 180
+ p 246 1
+ w 225
j 560 220
+ p 211 +
+ w 182
j 200 400
+ p 163 2
+ p 169 1
j 300 340
+ p 168 1
+ p 167 2
j 360 440
+ p 172 2
+ p 165 1
j 160 400
+ p 163 1
+ w 135
j 160 440
+ p 164 +
+ w 135
j 260 400
+ p 169 2
+ w 149
j 260 430
+ p 171 2
+ w 149
j 260 340
+ p 167 1
+ w 149
j 710 430
+ p 324 2
+ p 344 pin1
j 710 370
+ p 324 1
+ p 347 pin1
j 700 360
+ p 323 2
+ w 332
j 710 370
+ p 324 1
+ w 332
j 710 370
+ p 347 pin1
+ w 332
j 620 360
+ p 322 2
+ w 330
j 640 360
+ p 323 1
+ w 330
j 570 380
+ p 402 +
+ w 326
j 580 360
+ p 322 1
+ w 326
j 710 430
+ p 324 2
+ w 431
j 570 430
+ s 342
+ w 431
j 710 430
+ p 344 pin1
+ w 431
j 570 420
+ p 402 -
+ w 431
j 710 550
+ p 513 2
+ p 518 pin1
j 710 490
+ p 513 1
+ p 519 pin1
j 580 480
+ p 514 1
+ w 506
j 570 500
+ p 516 +
+ w 506
j 620 480
+ p 514 2
+ w 504
j 640 480
+ p 515 1
+ w 504
j 710 490
+ p 513 1
+ w 500
j 710 490
+ p 519 pin1
+ w 500
j 700 480
+ p 515 2
+ w 500
j 360 400
+ p 165 2
+ w 156
j 360 340
+ p 168 2
+ w 156
j 410 450
+ p 166 -
+ w 137
j 410 410
+ p 166 +
+ w 156
j 260 500
+ s 448
+ w 137
j 160 480
+ p 164 -
+ w 137
j 360 500
+ p 172 1
+ w 137
j 260 460
+ p 171 1
+ w 137
j 660 280
+ w 184
+ w 184
j 560 260
+ p 211 -
+ w 184
j 660 240
+ p 217 1
+ w 184
j 760 280
+ p 218 1
+ w 184
j 660 280
+ s 447
+ w 184
j 760 180
+ p 212 2
+ w 196
j 760 120
+ p 215 2
+ w 196
j 720 180
+ p 246 2
+ w 196
j 360 220
+ p 11 2
+ p 6 1
j 570 550
+ s 517
+ w 521
j 570 540
+ p 516 -
+ w 521
j 710 550
+ p 513 2
+ w 521
j 710 550
+ p 518 pin1
+ w 521
j 260 240
+ p 7 1
+ w 19
j 360 280
+ p 11 1
+ w 19
j 260 280
+ w 19
+ w 19
j 260 280
+ s 446
+ w 19
j 160 220
+ p 81 +
+ w 15
j 160 260
+ p 81 -
+ w 19
j 810 240
+ p 213 -
+ w 184
j 810 200
+ p 213 +
+ w 196
j 410 240
+ p 86 -
+ w 19
j 280 400
+ p 253 1
+ w 149
j 300 400
+ p 253 2
+ w 156
j 280 180
+ p 9 1
+ w 573
j 340 180
+ p 591 pin1
+ p 9 2
j 280 180
+ p 592 pin1
+ p 9 1
j 280 180
+ p 592 pin1
+ w 573
j 340 180
+ p 593 pin1
+ p 9 2
j 360 120
+ p 10 2
+ w 550
j 360 180
+ p 6 2
+ w 550
j 410 200
+ p 86 +
+ w 550
j 340 180
+ p 9 2
+ w 550
j 340 180
+ p 591 pin1
+ w 550
j 340 180
+ p 593 pin1
+ w 550
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
