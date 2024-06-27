*version 9.1 565281380
u 86
V? 4
I? 2
R? 4
C? 2
L? 5
? 5
@libraries
@analysis
.AC 0 3 0
+0 1
+1 0.318
+2 0.318
.TRAN 1 0 0 0
+0 10us
+1 1
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
pageloc 1 0 4180 
@status
n 0 124:05:27:17:22:06;1719519726 e 
s 0 124:05:27:17:22:58;1719519778 e 
c 124:05:27:17:23:12;1719519792
*page 1 0 970 720 iA
@ports
port 55 gnd_earth 260 280 h
@parts
part 4 r 160 180 h
a 0 u 13 0 15 25 hln 100 VALUE=2
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 5 r 260 120 h
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
part 10 l 300 120 h
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L3
a 0 ap 9 0 15 0 hln 100 REFDES=L3
part 11 l 360 280 v
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L4
a 0 ap 9 0 15 0 hln 100 REFDES=L4
a 0 u 13 0 15 25 hln 100 VALUE=2
part 7 c 260 240 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=c
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=C1
a 0 ap 9 0 15 0 hln 100 REFDES=C1
part 81 vsin 160 220 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=V1
a 1 u 0 0 0 0 hcn 100 VOFF=0
a 1 u 0 0 0 0 hcn 100 PHASE=0
a 1 u 0 0 0 0 hcn 100 VAMPL=48
a 1 u 0 0 0 0 hcn 100 FREQ=0.318
a 1 xp 9 0 20 10 hcn 100 REFDES=V1
part 8 l 200 180 h
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L1
a 0 ap 9 0 15 0 hln 100 REFDES=L1
part 6 r 360 220 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
part 9 l 280 180 h
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=l
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=L2012C
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=L2
a 0 ap 9 0 15 0 hln 100 REFDES=L2
part 3 IAC 470 200 h
a 1 u 0 0 0 0 hcn 100 DC=0A
a 0 u 13 0 -8 22 hcn 100 ACMAG=3A
a 0 u 0:13 0 0 20 hcn 100 ACPHASE=-48
a 0 sp 0:11 0 0 50 hln 100 PART=IAC
a 0 a 0:13 0 0 0 hln 100 PKGREF=I1
a 1 ap 9 0 20 10 hcn 100 REFDES=I1
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
part 84 nodeMarker 340 180 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=3
part 85 nodeMarker 280 180 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=4
@conn
w 15
a 0 sr 0 0 0 0 hln 100 LABEL=P1
a 0 up 0:33 0 0 0 hln 100 V=
s 160 220 160 180 14
a 0 sr 3 0 162 200 hln 100 LABEL=P1
a 0 up 33 0 162 201 hlt 100 V=
w 19
a 0 up 0:33 0 0 0 hln 100 V=
s 260 280 260 240 69
s 470 280 360 280 53
a 0 up 33 0 415 279 hct 100 V=
s 470 280 470 240 47
s 360 280 260 280 63
s 160 280 160 260 24
s 160 280 260 280 20
w 29
a 0 sr 0 0 0 0 hln 100 LABEL=P3
a 0 up 0:33 0 0 0 hln 100 V=
s 360 180 360 120 32
a 0 sr 3 0 362 150 hln 100 LABEL=P3
a 0 up 33 0 362 151 hlt 100 V=
s 470 180 360 180 30
s 360 180 340 180 34
s 470 200 470 180 28
w 17
a 0 sr 0 0 0 0 hln 100 LABEL=P2
a 0 up 0:33 0 0 0 hln 100 V=
s 260 180 260 120 16
a 0 sr 3 0 262 150 hln 100 LABEL=P2
a 0 up 33 0 262 151 hlt 100 V=
s 280 180 260 180 36
s 260 210 260 180 38
@junction
j 300 120
+ p 5 2
+ p 10 1
j 260 120
+ p 5 1
+ w 17
j 260 180
+ p 8 2
+ w 17
j 360 120
+ p 10 2
+ w 29
j 340 180
+ p 9 2
+ w 29
j 280 180
+ p 9 1
+ w 17
j 260 210
+ p 7 2
+ w 17
j 200 180
+ p 8 1
+ p 4 2
j 160 180
+ p 4 1
+ w 15
j 360 180
+ p 6 2
+ w 29
j 260 240
+ p 7 1
+ w 19
j 360 220
+ p 11 2
+ p 6 1
j 360 280
+ p 11 1
+ w 19
j 260 280
+ w 19
+ w 19
j 260 280
+ s 55
+ w 19
j 340 180
+ p 84 pin1
+ p 9 2
j 340 180
+ p 84 pin1
+ w 29
j 280 180
+ p 85 pin1
+ p 9 1
j 280 180
+ p 85 pin1
+ w 17
j 470 200
+ p 3 +
+ w 29
j 470 240
+ p 3 -
+ w 19
j 160 220
+ p 81 +
+ w 15
j 160 260
+ p 81 -
+ w 19
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
