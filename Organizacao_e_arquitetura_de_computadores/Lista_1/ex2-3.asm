	.data
	.align 2
inicio: .word 1
soma: .word 0

	.text
	.globl somarNros
	.align 2
	
somarNros:
	li a7, 9
	li a0, 8
	ecall
	
	li t2, -1
	sw t2, 4(a0)
	sw a0, inicio, t1
	mv t1, a0
	
lerNros:
	li a7, 5
	ecall
	
	beq a0, x0, iniciarSoma
	
	sw a0, 0(t1)

	li a7, 9
	li a0, 8
	ecall
	
	li t2, -1
	sw t2, 4(a0)
	sw a0, 4(t1)
	
	mv t1, a0
	j lerNros
	
iniciarSoma:
	lw t1, inicio
	
somar:
	lw t2, 4(t1)
	li t3, -1
	beq t2, t3, imprimir
	
	lw t2, 0(t1)
	lw t3, soma
	add t3, t3, t2
	sw t3, soma, t2
	lw t2, 4(t1)
	mv t1, t2
	
	j somar
	
	
imprimir:
	li a7, 1
	lw a0, soma
	ecall
	
finalizar:
	li a7, 10
	ecall