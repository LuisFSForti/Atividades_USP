	.data
	.align 2
num: .word 5, 3, 2, 5, 6, 7, 3, 4, 12, 14, 9, 2, 5, 0, 1, -15, 14, -13 #vetor a ser somado
qtd: .word 18 #quantidade de itens

	.align 1
separador: .asciz ", "
saida: .asciz "\nSoma dos valores = "

	.text
	.globl SomaVetor
	.align 2
SomaVetor:
	la t1, num #t1 = &num
	li t2, 0 #i = 0
	lw t3, qtd #t3 = quantidade de valores
	mv t4, x0 #t4 = 0 -> este vai ser o resultado final
	
loop:
	bge t2, t3, resultados #if t2 >= t3 -> resultados
	
	lw t5, 0(t1) #t5 = num[i]
	add t4, t4, t5 #t4 += num[i]
	addi t1, t1, 4 #&num = &num[i+1]
	
	li a7, 1 #a7 = 1 -> ecall de print de inteiro
	mv a0, t5 #a0 = num[i]
	ecall #print inteiro a0
	
	li a7, 4 #a7 = 11 -> ecall de print de string
	la a0, separador #a0 = &separador
	ecall #imprime string a0
	
	addi t2, t2, 1 #i++
	j loop #volta pro comeco do loop

resultados:
	li a7, 4 #a7 = 4 -> ecall de print de string
	la a0, saida #a0 = &saida
	ecall #imprime string a0
	
	li a7, 1 #a7 = 1 -> ecall de print de inteiro
	mv a0, t4 #a0 = t4 -> soma final
	ecall #imprime inteiro a0

encerrar:
	li a7, 10 #a7 = 10 -> ecall de exit
	ecall #exit