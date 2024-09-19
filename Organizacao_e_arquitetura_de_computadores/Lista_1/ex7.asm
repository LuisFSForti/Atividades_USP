	.data
	.align 2
ptrStr1: .word 1
ptrStr2: .word 1
tam: .word 100

	.text
	.globl strcmp
	.align 2
strcmp:
	li a7, 9
	lw a0, tam
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
loop:
	addi t3, t3, 1
	lw t4, tam
	beq t3, t4, iguais
	
	lb t4, 0(t1)
	lb t5, 0(t2)
	
	bgt t4, t5, maior
	blt t4, t5, menor
	
	addi t1, t1, 1
	addi t2, t2, 1

	j loop
	
iguais:
	li a0, 0
	j imprimir
	
maior:
	li a0, 1
	j imprimir
	
menor:
	li a0, -1
	j imprimir
	
imprimir:
	li a7, 1
	ecall
	
encerrar:
	li a7, 10
	ecall