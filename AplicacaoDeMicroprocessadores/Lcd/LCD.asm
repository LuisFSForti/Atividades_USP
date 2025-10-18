
_main:

;LCD.c,15 :: 		void main()
;LCD.c,20 :: 		TRISA.RA0 = 1;
	BSF         TRISA+0, 0 
;LCD.c,21 :: 		ADCON0 = 0B00000001;
	MOVLW       1
	MOVWF       ADCON0+0 
;LCD.c,22 :: 		ADCON1 = 0B00001110;
	MOVLW       14
	MOVWF       ADCON1+0 
;LCD.c,23 :: 		ADCON2 = 0B10010000;
	MOVLW       144
	MOVWF       ADCON2+0 
;LCD.c,25 :: 		Lcd_Init();
	CALL        _Lcd_Init+0, 0
;LCD.c,26 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;LCD.c,27 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;LCD.c,28 :: 		Lcd_Out(1, 1, "ADC: ");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_LCD+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_LCD+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;LCD.c,29 :: 		Lcd_Out(2, 1, "SEL0036........");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_LCD+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_LCD+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;LCD.c,31 :: 		while(1)
L_main0:
;LCD.c,33 :: 		ADCON0.GO_DONE = 1;
	BSF         ADCON0+0, 1 
;LCD.c,34 :: 		while(ADCON0.GO_DONE == 1) ;
L_main2:
	BTFSS       ADCON0+0, 1 
	GOTO        L_main3
	GOTO        L_main2
L_main3:
;LCD.c,36 :: 		ADC = ((ADRESH << 0) | ADRESL);
	MOVF        ADRESH+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVLW       0
	MOVWF       FARG_WordToStr_input+1 
	MOVF        ADRESL+0, 0 
	IORWF       FARG_WordToStr_input+0, 1 
	MOVLW       0
	IORWF       FARG_WordToStr_input+1, 1 
;LCD.c,38 :: 		WordToStr(ADC, Texto);
	MOVLW       main_Texto_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_Texto_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;LCD.c,39 :: 		LCD_Out(1, 5, Texto);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       5
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_Texto_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_Texto_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;LCD.c,40 :: 		Delay_ms(20);
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       221
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 1
	BRA         L_main4
	DECFSZ      R12, 1, 1
	BRA         L_main4
	NOP
	NOP
;LCD.c,41 :: 		}
	GOTO        L_main0
;LCD.c,42 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
