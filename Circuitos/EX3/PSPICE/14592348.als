* Schematics Aliases *

.ALIASES
R_R1            R1(1=$N_0002 2=$N_0001 )
C_C1            C1(1=0 2=$N_0003 )
C_C4            C4(1=0 2=BN )
L_L14           L14(1=$N_0004 2=BN )
R_R10           R10(1=$N_0005 2=$N_0004 )
R_R2            R2(1=$N_0003 2=$N_0006 )
V_PRINT6          PRINT6(1=BN 2=AN )

V_V1            V1(+=$N_0002 -=0 )
V_V2            V2(+=$N_0005 -=0 )
L_L4            L4(1=0 2=$N_0007 )
L_L15           L15(1=0 2=$N_0008 )
R_R11           R11(1=$N_0008 2=AN )
R_R7            R7(1=$N_0010 2=$N_0009 )
C_C3            C3(1=0 2=BT )
V_V3            V3(+=$N_0010 -=0 )
L_L9            L9(1=$N_0011 2=AT )
R_R9            R9(1=BT 2=$N_0011 )
L_L10           L10(1=$N_0009 2=BT )
L_L12           L12(1=0 2=$N_0012 )
R_R8            R8(1=$N_0012 2=AT )
R_R15           R15(1=$N_0014 2=$N_0013 )
L_L20           L20(1=$N_0013 2=$N_0015 )
V_V4            V4(+=$N_0014 -=0 )
R_R12           R12(1=BN 2=$N_0016 )
L_L13           L13(1=$N_0016 2=AN )
L_L3            L3(1=$N_0006 2=$N_0017 )
L_L21           L21(1=$N_0015 2=0 )
R_R3            R3(1=$N_0007 2=$N_0017 )
L_L1            L1(1=$N_0001 2=$N_0003 )
L_L             L(1=$N_0003 2=$N_0017 )
I_I2            I2(+=0 -=$N_0017 )
I_I5            I5(+=0 -=AN )
I_I4            I4(+=0 -=AT )
_    _(BN=BN)
_    _(AN=AN)
_    _(BT=BT)
_    _(AT=AT)
.ENDALIASES

