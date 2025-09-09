	org 0000h

retorna:
	CLR P1.0
	ACALL delay
	SETB P1.0
	ACALL delay
	SJMP retorna

delay:
	MOV R0, #00000001b

loop1:
	MOV R1, #00000100b

loop2:
	DJNZ R1, loop2
	DJNZ R0, loop1
	RET

	end