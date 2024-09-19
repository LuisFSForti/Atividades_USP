	.data
	.align 2
ptrStr: .word 1
ptrRev: .word 1
tam: .word 100

	.text
	.globl rev
	.align 2
rev:
	li a7, 9
	lw a0, tam
	ecall
	
	sw a0, ptrStr, t1
	
	li a7, 9
	lw a0, tam
	ecall
	
	sw a0, ptrRev, t1
	
	li a7, 8
	lw a0, ptrStr
	lw a1, tam
	ecall
	
	lw t1, ptrStr
	lw t2, ptrRev
	lw t3, ptrStr
	
	lw t4, tam
	addi t1, t1, -1
	add t1, t1, t4
	
encontrarFim:
	lb t4, 0(t1)
	bne t4, x0, loop
	
	beq t3, t1, imprimir
	
	addi t1, t1, -1
	j encontrarFim
	
loop:
	lb t4, 0(t1)
	sb t4, 0(t2)
	
	beq t3, t1, imprimir
	
	addi t1, t1, -1
	addi t2, t2, 1
	
	j loop
	
imprimir:
	li a7, 4
	lw a0, ptrRev
	ecall
	
encerrar:
	li a7, 10
	ecall
