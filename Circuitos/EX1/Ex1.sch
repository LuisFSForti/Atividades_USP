*version 9.1 3576986365
u 357
V? 2
I? 2
H? 2
G? 2
R? 7
? 9
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
pageloc 1 0 4589 
@status
n 0 124:03:22:15:01:35;1713808895 e 
s 0 124:03:22:15:03:19;1713808999 e 
*page 1 0 970 720 iA
@ports
port 6 GND_EARTH 460 340 h
@parts
part 5 G 500 300 u
a 0 u 0 0 0 10 hln 100 GAIN=1.5
a 0 s 11 0 10 34 hln 100 PART=G
a 0 a 0:13 0 0 0 hln 100 PKGREF=G1
a 1 ap 9 0 10 4 hln 100 REFDES=G1
part 351 r 300 330 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R6
a 0 ap 9 0 15 0 hln 100 REFDES=R6
part 2 VDC 340 250 v
a 1 u 13 0 -11 18 hcn 100 DC=48V
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
part 3 IDC 380 180 d
a 0 sp 11 0 0 50 hln 100 PART=IDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=I1
a 1 ap 9 0 20 10 hcn 100 REFDES=I1
a 1 u 13 0 -9 21 hcn 100 DC=6A
part 4 H 410 200 d
a 0 s 11 0 10 34 hln 100 PART=H
a 0 a 0:13 0 0 0 hln 100 PKGREF=H1
a 1 ap 9 0 10 4 hln 100 REFDES=H1
a 0 u 0 0 0 10 hln 100 GAIN=4
part 10 r 460 220 v
a 0 u 13 0 15 25 hln 100 VALUE=1
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
part 11 r 520 260 v
a 0 u 13 0 15 25 hln 100 VALUE=2
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R5
a 0 ap 9 0 15 0 hln 100 REFDES=R5
part 7 r 400 330 v
a 0 u 13 0 15 25 hln 100 VALUE=4
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 9 r 480 180 h
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
part 355 iMarker 300 330 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 6 20 hlb 100 LABEL=7
part 333 nodeMarker 400 290 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=R1:1
a 0 a 0 0 4 22 hlb 100 LABEL=4
part 356 nodeMarker 520 180 h
a 0 s 0 0 0 0 hln 100 PROBEVAR=
a 0 a 0 0 4 22 hlb 100 LABEL=8
@conn
w 299
a 0 up 0:33 0 0 0 hln 100 V=
s 300 340 300 330 304
s 270 340 300 340 302
s 400 200 270 200 298
s 270 200 270 340 300
a 0 up 0:33 0 272 270 hlt 100 V=
w 64
a 0 up 0:33 0 0 0 hln 100 V=
s 340 180 300 180 63
s 300 180 300 250 65
a 0 up 0:33 0 302 215 hlt 100 V=
s 340 250 300 250 67
s 300 250 300 290 352
w 59
a 0 up 0:33 0 0 0 hln 100 V=
s 410 240 410 250 284
s 460 290 460 250 56
a 0 up 0:33 0 462 270 hlt 100 V=
s 460 250 460 220 342
s 410 250 460 250 286
w 280
a 0 up 0:33 0 0 0 hln 100 V=
s 400 340 460 340 161
a 0 up 0:33 0 450 339 hct 100 V=
s 460 300 460 340 218
s 400 330 400 340 37
s 460 340 520 340 48
s 520 340 520 260 50
s 400 340 400 360 288
s 400 360 260 360 290
s 260 360 260 140 292
s 260 140 410 140 294
s 410 140 410 200 296
w 279
a 0 up 0:33 0 0 0 hln 100 V=
s 400 290 400 250 34
a 0 up 33 0 402 270 hlt 100 V=
s 400 250 380 250 36
s 400 240 400 250 282
w 324
a 0 up 0:33 0 0 0 hln 100 V=
s 500 300 550 300 323
s 550 300 550 150 325
a 0 up 0:33 0 552 225 hlt 100 V=
s 550 150 480 150 327
s 380 180 460 180 58
s 480 150 480 180 329
s 460 180 480 180 339
w 311
a 0 up 0:33 0 0 0 hln 100 V=
s 520 180 520 200 61
s 500 290 500 200 312
a 0 up 0:33 0 502 245 hlt 100 V=
s 520 200 520 220 320
s 500 200 520 200 318
@junction
j 300 250
+ w 64
+ w 64
j 520 260
+ p 11 1
+ w 280
j 460 340
+ w 280
+ w 280
j 400 250
+ w 279
+ w 279
j 400 340
+ w 280
+ w 280
j 460 340
+ s 6
+ w 280
j 460 250
+ w 59
+ w 59
j 460 300
+ p 5 3
+ w 280
j 460 290
+ p 5 4
+ w 59
j 500 290
+ p 5 2
+ w 311
j 500 300
+ p 5 1
+ w 324
j 520 220
+ p 11 2
+ w 311
j 520 200
+ w 311
+ w 311
j 300 330
+ p 351 1
+ w 299
j 300 290
+ p 351 2
+ w 64
j 300 330
+ p 355 pin1
+ p 351 1
j 300 330
+ p 355 pin1
+ w 299
j 380 250
+ p 2 -
+ w 279
j 340 250
+ p 2 +
+ w 64
j 380 180
+ p 3 +
+ w 324
j 340 180
+ p 3 -
+ w 64
j 400 240
+ p 4 4
+ w 279
j 410 240
+ p 4 3
+ w 59
j 410 200
+ p 4 1
+ w 280
j 400 200
+ p 4 2
+ w 299
j 460 180
+ p 10 2
+ w 324
j 460 220
+ p 10 1
+ w 59
j 480 180
+ p 9 1
+ w 324
j 520 180
+ p 9 2
+ w 311
j 400 290
+ p 7 2
+ w 279
j 400 330
+ p 7 1
+ w 280
j 400 290
+ p 333 pin1
+ p 7 2
j 400 290
+ p 333 pin1
+ w 279
j 520 180
+ p 356 pin1
+ p 9 2
j 520 180
+ p 356 pin1
+ w 311
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
