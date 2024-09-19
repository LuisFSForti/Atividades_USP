	.data
	.align 2
qtd: .word 0
soma: .word 0
	
	.text
	.globl somarNumeros
	.align 2

somarNumeros:
	li a7, 5
	ecall
	
	beq a0, x0, somar
	
	addi sp, sp, -4
	sw a0, 0(sp)
	lw t1, qtd
	addi t1, t1, 1
	sw t1, qtd, t2
	
	j somarNumeros
	
somar:
	lw t1, soma
	lw t2, 0(sp)
	
	add t1, t1, t2
	sw t1, soma, t2
	
	addi sp, sp, 4
	
	lw t1, qtd
	addi t1, t1, -1
	sw t1, qtd, t2
	
	beq t1, x0, imprimir
	j somar
	
imprimir:
	li a7, 1
	lw a0, soma
	ecall
	
encerrar:
	li a7, 10
	ecall