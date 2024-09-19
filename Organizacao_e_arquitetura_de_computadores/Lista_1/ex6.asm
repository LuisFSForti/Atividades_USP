	.data
	.align 2
ptrString: .word 1
ptrCopia: .word 1
tam: .word 100

	.text
	.globl strcpy
	.align 2
strcpy:
	li a7, 9
	lw a0, tam
	ecall
	
	sw a0, ptrString, t1
	
	li a7, 9
	lw a0, tam
	ecall
	
	sw a0, ptrCopia, t1
	
	li a7, 8
	lw a0, ptrString
	lw a1, tam
	ecall
	
	lw t1, ptrString
	lw t2, ptrCopia
	li t3, 0
	
loop:
	addi t3, t3, 1
	lw t4, tam
	beq t3, t4, fimLoop	
	
	lw t4, 0(t1)
	beq x0, t4, fimLoop
	
	sw t4, 0(t2)
	
	addi t1, t1, 4
	addi t2, t2, 4
	
	j loop
	
fimLoop:
	sw x0, 0(t1)
	
imprimir:
	li a7, 4
	lw a0, ptrString
	ecall
	
encerrar:
	li a7, 10
	ecall
