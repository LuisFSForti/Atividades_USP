*version 9.1 4240016417
u 81
R? 6
H? 2
G? 2
V? 2
I? 2
? 4
@libraries
@analysis
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
pageloc 1 0 4265 
@status
n 0 124:03:26:18:36:40;1714167400 e 
s 0 124:03:26:18:37:10;1714167430 e 
*page 1 0 970 720 iA
@ports
port 15 GND_EARTH 350 290 h
@parts
part 8 G 390 270 u
a 0 u 0 0 0 10 hln 100 GAIN=1.5
a 0 s 11 0 10 34 hln 100 PART=G
a 0 a 0:13 0 0 0 hln 100 PKGREF=G1
a 1 ap 9 0 10 4 hln 100 REFDES=G1
part 2 r 350 200 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 7 H 330 190 d
a 0 u 0 0 0 10 hln 100 GAIN=4
a 0 s 11 0 10 34 hln 100 PART=H
a 0 a 0:13 0 0 0 hln 100 PKGREF=H1
a 1 ap 9 0 10 4 hln 100 REFDES=H1
part 6 r 240 290 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R5
a 0 ap 9 0 15 0 hln 100 REFDES=R5
part 5 r 420 250 v
a 0 u 13 0 15 25 hln 100 VALUE=2
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
part 9 VDC 240 230 v
a 1 u 13 0 -6 38 hcn 100 DC=48V
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
part 10 idc 280 160 d
a 0 a 0:13 0 0 0 hln 100 PKGREF=I1
a 1 ap 9 0 20 10 hcn 100 REFDES=I1
a 1 u 13 0 -9 21 hcn 100 DC=6A
part 3 r 300 290 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=4
part 4 r 380 160 h
a 0 u 13 0 15 25 hln 100 VALUE=5
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 12
a 0 sr 0 0 0 0 hln 100 LABEL=N1
a 0 up 0:33 0 0 0 hln 100 V=
s 240 230 240 160 11
a 0 sr 3 0 242 189 hln 100 LABEL=N1
a 0 up 33 0 242 195 hlt 100 V=
s 240 230 240 250 13
w 28
a 0 sr 0 0 0 0 hln 100 LABEL=N2
a 0 up 0:33 0 0 0 hln 100 V=
s 350 160 280 160 27
a 0 sr 3 0 340 158 hcn 100 LABEL=N2
s 380 160 350 160 29
s 390 270 450 270 44
s 450 270 450 140 46
a 0 up 33 0 302 150 hlt 100 V=
s 450 140 380 140 48
s 380 140 380 160 50
w 33
a 0 sr 0 0 0 0 hln 100 LABEL=N5
a 0 up 0:33 0 0 0 hln 100 V=
s 420 160 420 210 32
a 0 sr 3 0 422 185 hln 100 LABEL=N5
s 390 260 440 260 52
s 440 260 440 150 54
a 0 up 33 0 392 190 hlt 100 V=
s 440 150 420 150 56
s 420 150 420 160 58
w 61
a 0 sr 0 0 0 0 hln 100 LABEL=N6
a 0 up 0:33 0 0 0 hln 100 V=
s 230 290 240 290 64
a 0 sr 3 0 235 288 hcn 100 LABEL=N6
s 320 190 230 190 60
s 230 190 230 290 62
a 0 up 33 0 367 295 hlt 100 V=
w 67
a 0 up 0:33 0 0 0 hln 100 V=
s 330 190 330 180 66
s 330 180 220 180 68
s 220 180 220 300 70
a 0 up 33 0 247 285 hlt 100 V=
s 220 300 300 300 72
s 300 290 350 290 36
s 350 290 350 270 38
s 350 290 420 290 40
s 420 290 420 250 42
s 300 300 300 290 74
w 17
a 0 sr 0 0 0 0 hln 100 LABEL=N3
a 0 up 0:33 0 0 0 hln 100 V=
s 280 230 300 230 16
a 0 sr 3 0 290 228 hcn 100 LABEL=N3
s 300 230 300 250 18
s 300 230 320 230 20
a 0 up 33 0 315 234 hct 100 V=
w 23
a 0 sr 0 0 0 0 hln 100 LABEL=N4
a 0 up 0:33 0 0 0 hln 100 V=
s 350 260 350 230 34
a 0 sr 3 0 352 239 hln 100 LABEL=N4
a 0 up 33 0 327 255 hlt 100 V=
s 330 230 350 230 22
s 350 230 350 200 24
@junction
j 330 230
+ p 7 3
+ w 23
j 350 260
+ p 8 4
+ w 23
j 350 230
+ w 23
+ w 23
j 240 230
+ p 9 +
+ w 12
j 350 200
+ p 2 1
+ w 23
j 350 160
+ p 2 2
+ w 28
j 390 270
+ p 8 1
+ w 28
j 420 210
+ p 5 2
+ w 33
j 390 260
+ p 8 2
+ w 33
j 380 160
+ p 4 1
+ w 28
j 420 160
+ p 4 2
+ w 33
j 240 160
+ p 10 -
+ w 12
j 280 160
+ p 10 +
+ w 28
j 280 230
+ p 9 -
+ w 17
j 300 250
+ p 3 2
+ w 17
j 320 230
+ p 7 4
+ w 17
j 300 230
+ w 17
+ w 17
j 240 250
+ p 6 2
+ w 12
j 330 190
+ p 7 1
+ w 67
j 300 290
+ p 3 1
+ w 67
j 350 270
+ p 8 3
+ w 67
j 350 290
+ w 67
+ w 67
j 420 250
+ p 5 1
+ w 67
j 350 290
+ s 15
+ w 67
j 320 190
+ p 7 2
+ w 61
j 240 290
+ p 6 1
+ w 61
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
