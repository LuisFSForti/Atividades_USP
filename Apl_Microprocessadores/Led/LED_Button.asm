
_main:

;LED_Button.c,1 :: 		void main()
;LED_Button.c,3 :: 		TRISC.RC0 = 1;
	BSF         TRISC+0, 0 
;LED_Button.c,4 :: 		PORTC.RC0 = 1;
	BSF         PORTC+0, 0 
;LED_Button.c,6 :: 		TRISD.RD1 = 0;
	BCF         TRISD+0, 1 
;LED_Button.c,7 :: 		PORTD.RD1 = 0;
	BCF         PORTD+0, 1 
;LED_Button.c,9 :: 		while(1)
L_main0:
;LED_Button.c,11 :: 		if(PORTC.RC0 == 0)
	BTFSC       PORTC+0, 0 
	GOTO        L_main2
;LED_Button.c,13 :: 		LATD.RD1 = 1;
	BSF         LATD+0, 1 
;LED_Button.c,14 :: 		Delay_ms(300);
	MOVLW       8
	MOVWF       R11, 0
	MOVLW       157
	MOVWF       R12, 0
	MOVLW       5
	MOVWF       R13, 0
L_main3:
	DECFSZ      R13, 1, 1
	BRA         L_main3
	DECFSZ      R12, 1, 1
	BRA         L_main3
	DECFSZ      R11, 1, 1
	BRA         L_main3
	NOP
	NOP
;LED_Button.c,15 :: 		}
	GOTO        L_main4
L_main2:
;LED_Button.c,18 :: 		LATD.RD1 = 0;
	BCF         LATD+0, 1 
;LED_Button.c,19 :: 		}
L_main4:
;LED_Button.c,20 :: 		}
	GOTO        L_main0
;LED_Button.c,21 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
