	.data
	.align 2
ptrStr1: .word 1
ptrStr2: .word 1
tam: .word 100

	.text
	.globl strcat
	.align 2
strcat:
	li a7, 9
	lw a0, tam
	li t1, 2
	mul a0, a0, t1
	ecall
	
	sw a0, ptrStr1, t1
	
	li a7, 9
	lw a0, tam
	ecall
	
	sw a0, ptrStr2, t1
	
	li a7, 8
	lw a0, ptrStr1
	lw a1, tam
	ecall
	
	li a7, 8
	lw a0, ptrStr2
	lw a1, tam
	ecall
	
	lw t1, ptrStr1
	lw t2, ptrStr2
	mv t3, x0
	
loop1:
	lb t4, 0(t1)
	beq t4, x0, loop2
	li t5, 10
	beq t4, t5, loop2
	
	addi t1, t1, 1
	j loop1
	
loop2:
	addi t3, t3, 1
	lw t4, tam
	beq t3, t4, imprimir
	
	lb t4, 0(t2)
	sb t4, 0(t1)
	
	addi t1, t1, 1
	addi t2, t2, 1
	
	j loop2
	
imprimir:
	li a7, 4
	lw a0, ptrStr1
	ecall
	
encerrar:
	li a7, 10
	ecall