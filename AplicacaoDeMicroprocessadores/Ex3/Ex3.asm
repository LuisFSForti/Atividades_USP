
_main:

;Ex3.c,17 :: 		void main()
;Ex3.c,30 :: 		char labelADC[] = "ADC: ";
	MOVLW       ?ICSmain_labelADC_L0+0
	MOVWF       TBLPTRL+0 
	MOVLW       hi_addr(?ICSmain_labelADC_L0+0)
	MOVWF       TBLPTRL+1 
	MOVLW       higher_addr(?ICSmain_labelADC_L0+0)
	MOVWF       TBLPTRL+2 
	MOVLW       main_labelADC_L0+0
	MOVWF       FSR1L+0 
	MOVLW       hi_addr(main_labelADC_L0+0)
	MOVWF       FSR1L+1 
	MOVLW       23
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
;Ex3.c,34 :: 		TRISA.RA0 = 1;
	BSF         TRISA+0, 0 
;Ex3.c,36 :: 		ADCON0 = 0B00000001;
	MOVLW       1
	MOVWF       ADCON0+0 
;Ex3.c,38 :: 		ADCON1 = 0B00001110;
	MOVLW       14
	MOVWF       ADCON1+0 
;Ex3.c,39 :: 		ADCON2 = 0B10010000;
	MOVLW       144
	MOVWF       ADCON2+0 
;Ex3.c,41 :: 		Lcd_Init();
	CALL        _Lcd_Init+0, 0
;Ex3.c,42 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;Ex3.c,43 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;Ex3.c,44 :: 		Lcd_Out(1, 1, labelADC);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_labelADC_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_labelADC_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Ex3.c,45 :: 		Lcd_Out(2, 1, labelCurso);
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_labelCurso_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_labelCurso_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Ex3.c,47 :: 		while(1)
L_main0:
;Ex3.c,50 :: 		ADCON0.GO_DONE = 1;
	BSF         ADCON0+0, 1 
;Ex3.c,52 :: 		while(ADCON0.GO_DONE == 1) ;
L_main2:
	BTFSS       ADCON0+0, 1 
	GOTO        L_main3
	GOTO        L_main2
L_main3:
;Ex3.c,62 :: 		ADC = ((ADRESH << 8) | ADRESL);
	MOVF        ADRESH+0, 0 
	MOVWF       R1 
	CLRF        R0 
	MOVF        ADRESL+0, 0 
	IORWF       R0, 1 
	MOVLW       0
	IORWF       R1, 1 
;Ex3.c,66 :: 		tensao = (ADC * 5.0) / 1023.0;
	CALL        _word2double+0, 0
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       32
	MOVWF       R6 
	MOVLW       129
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	MOVLW       0
	MOVWF       R4 
	MOVLW       192
	MOVWF       R5 
	MOVLW       127
	MOVWF       R6 
	MOVLW       136
	MOVWF       R7 
	CALL        _Div_32x32_FP+0, 0
	MOVF        R0, 0 
	MOVWF       FLOC__main+0 
	MOVF        R1, 0 
	MOVWF       FLOC__main+1 
	MOVF        R2, 0 
	MOVWF       FLOC__main+2 
	MOVF        R3, 0 
	MOVWF       FLOC__main+3 
	MOVF        FLOC__main+0, 0 
	MOVWF       R0 
	MOVF        FLOC__main+1, 0 
	MOVWF       R1 
	MOVF        FLOC__main+2, 0 
	MOVWF       R2 
	MOVF        FLOC__main+3, 0 
	MOVWF       R3 
	CALL        _double2int+0, 0
;Ex3.c,68 :: 		tensaoInteira = tensao;
	MOVF        R0, 0 
	MOVWF       main_tensaoInteira_L0+0 
	MOVF        R1, 0 
	MOVWF       main_tensaoInteira_L0+1 
;Ex3.c,69 :: 		tensaoDecimal = (tensao - tensaoInteira) * 1000;
	CALL        _int2double+0, 0
	MOVF        R0, 0 
	MOVWF       R4 
	MOVF        R1, 0 
	MOVWF       R5 
	MOVF        R2, 0 
	MOVWF       R6 
	MOVF        R3, 0 
	MOVWF       R7 
	MOVF        FLOC__main+0, 0 
	MOVWF       R0 
	MOVF        FLOC__main+1, 0 
	MOVWF       R1 
	MOVF        FLOC__main+2, 0 
	MOVWF       R2 
	MOVF        FLOC__main+3, 0 
	MOVWF       R3 
	CALL        _Sub_32x32_FP+0, 0
	MOVLW       0
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       122
	MOVWF       R6 
	MOVLW       136
	MOVWF       R7 
	CALL        _Mul_32x32_FP+0, 0
	CALL        _double2int+0, 0
	MOVF        R0, 0 
	MOVWF       main_tensaoDecimal_L0+0 
	MOVF        R1, 0 
	MOVWF       main_tensaoDecimal_L0+1 
;Ex3.c,72 :: 		WordToStr(tensaoDecimal, Texto);
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       main_Texto_L0+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(main_Texto_L0+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;Ex3.c,75 :: 		if (tensaoDecimal < 100)
	MOVLW       128
	XORWF       main_tensaoDecimal_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main8
	MOVLW       100
	SUBWF       main_tensaoDecimal_L0+0, 0 
L__main8:
	BTFSC       STATUS+0, 0 
	GOTO        L_main4
;Ex3.c,77 :: 		Texto[2] = '0';
	MOVLW       48
	MOVWF       main_Texto_L0+2 
;Ex3.c,79 :: 		if (tensaoDecimal < 10)
	MOVLW       128
	XORWF       main_tensaoDecimal_L0+1, 0 
	MOVWF       R0 
	MOVLW       128
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main9
	MOVLW       10
	SUBWF       main_tensaoDecimal_L0+0, 0 
L__main9:
	BTFSC       STATUS+0, 0 
	GOTO        L_main5
;Ex3.c,80 :: 		Texto[3] = '0';
	MOVLW       48
	MOVWF       main_Texto_L0+3 
L_main5:
;Ex3.c,81 :: 		}
L_main4:
;Ex3.c,83 :: 		Texto[1] = '.';
	MOVLW       46
	MOVWF       main_Texto_L0+1 
;Ex3.c,85 :: 		Texto[0] = tensaoInteira + '0';
	MOVLW       48
	ADDWF       main_tensaoInteira_L0+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       main_Texto_L0+0 
;Ex3.c,87 :: 		LCD_Out(1, 12, Texto);
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       12
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       main_Texto_L0+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(main_Texto_L0+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;Ex3.c,90 :: 		Delay_ms(20);
	MOVLW       130
	MOVWF       R12, 0
	MOVLW       221
	MOVWF       R13, 0
L_main6:
	DECFSZ      R13, 1, 1
	BRA         L_main6
	DECFSZ      R12, 1, 1
	BRA         L_main6
	NOP
	NOP
;Ex3.c,91 :: 		}
	GOTO        L_main0
;Ex3.c,92 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
