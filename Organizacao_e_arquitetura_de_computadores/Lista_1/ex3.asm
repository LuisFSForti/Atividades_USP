	.data
	.align 2
tam: .word 100 #tamanho maximo
	
	.text
	.globl InverteString
	.align 2
InverteString:
	li a7, 9 #a7 = 9 -> ecall para alocar memoria
	lw a0, tam #a0 = tam
	addi a0, a0, 1 #a0 = tam+1 (para considerar o \0)
	ecall #ecall aloca em a0 tam bytes
	
	mv s0, a0 #s0 = &a0 -> texto original
	
	li a7, 9 #a7 = 9 -> ecall para alocar memoria
	lw a0, tam #a0 = tam
	addi a0, a0, 1 #a0 = tam+1 (para considerar o \0)
	ecall #ecall aloca em a0 tam bytes
	
	mv s1, a0 #s1 = &a0 -> texto invertido
	
	li a7, 8 #a7 = 8 -> ecall de ler string
	mv a0, s0 #a0 = &original
	lw a1, tam #a1 = tam
	addi a1, a1, 1 #a1 = tam+1 (para considerar o \0)
	ecall #ecall le a1 bytes e salva em s0 (original)
	
	mv t0, x0 #i = 0
	mv t1, s0 #t1 = &original
	lb t2, 0(t1) #t2 = original[i]
	li t3, 0 #t3 = 0 = \0
	li t4, 10 #t4 = 10 = \n
	
contagemCaracteres:
	beq t2, t3, comecarInversao #if original[i] == \0 -> comecarInversao
	beq t2, t4, comecarInversao #if original[i] == \n -> comecarInversao
	
	addi t1, t1, 1 #original = &original[i+1]
	lb t2, 0(t1) #t2 = original[i+1]
	addi t0, t0, 1 #i++
	
	j contagemCaracteres #volta pro comeco do loop	
	
comecarInversao:
	mv t1, t0 #t1 = i = qtd digitada
	addi t1, t1, -1 #t1 = qtd digitada-1 (desconsiderar \0 e \n)
	
	li t0, 0 #i = 0
	mv t2, s0 #t2 = &original
	mv t3, s1 #t3 = &invertida
	
	add t3, t3, t1 #t3 = &invertida[qtd digiada-1]
	
loopInversao:
	bgt t0, t1, imprimirInvertido #if i >= qtd digitada -1 -> imprimirInvertido
	
	lb t4, 0(t2) #t4 = original[i]
	sb t4, 0(t3) #inveritod[i] = t4
	
	addi t2, t2, 1 #t2 = &original[i+1]
	addi t3, t3, -1 #t3 = &invertida[i-1]
	
	addi t0, t0, 1 #i++
	j loopInversao #volta pro comeco do loop
	
imprimirInvertido:
	lw a0, tam #a0 = tam
	addi a0, a0, -1 #a0 = tam - 1
	
	bgt a0, t1, semEnter #if a0 > t1 -> semEnter

	comEnter:
		li a7, 11 #a7 = 11 -> ecall de imprimir caractere
		li a0, 10 #a0 = \n
		ecall #ecall imprime caractere a0

	semEnter:
		li a7, 4 #a7 = 4 -> ecall de imprimir string
		mv a0, s1 #a0 = &invertida
		ecall #ecall imprime string a0

encerrar:
	li a7, 10 #a7 = 10 -> ecall de exit
	ecall #exit