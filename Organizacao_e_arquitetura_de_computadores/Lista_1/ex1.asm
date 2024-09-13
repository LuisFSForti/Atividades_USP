	.data
	.align 2
num: .word 7, 5, 2, 1, 1, 3, 4 #vetor de dados
MAX: .word 7 #quantidade de dados

	.align 1
espaco: .asciz ", "

	.text
	.globl BubbleSort
	.align 2
BubbleSort:
	lw s2, MAX #s2 = MAX
	addi s2, s2, -1 #s2 = MAX-1
	li s0, 0 #i = 0
fori:
	bgt s0, s2, forPrint #if i > Max-1 -> sai do for
	
	mv s1, s2 #s1 = MAX - 1
	forj:
		addi s3, s0, 1 #S4 = i + 1
		blt s1, s3, fimFori #if j < i+1 -> sai do for
		
		la t1, num #t1 = &num
		li a0, 4 #a0 = 4
		addi s4, s1, -1 #s4 = j-1
		mul a1, a0, s4 #a1 = (j-1)*4
		
		add t1, t1, a1 #&t1 = &t1[j-1]
		lw a2, 0(t1) #a2 = num[j-1]
		addi t1, t1, 4 #&t1 = &t1[j]
		lw a3, 0(t1) #a3 = num[j]
		
		ble a2, a3 fimForj #if num[j-1] <= num[j] -> pula pro fim do loop
		#a2 tem a funcao do aux
		addi t1, t1, -4 #&t1 = &t1[j-1]
		sw a3, 0(t1) #num[j-1] = num[j]
		addi t1, t1, 4 #&t1 = &t1[j]
		sw a2, 0(t1) #num[j] = num[j-1]
		
	fimForj:
		addi s1, s1, -1 #j--
		j forj #Loop do j
fimFori:
	addi s0, s0, 1 #i++
	j fori #Loop do i
forPrint:
	li s0, 0 #i = 0
	la t1, num #t1 = &num
	loop:
		bgt s0, s2, encerrar #if i > MAX-1 -> encerrar
		
		li a7, 1 #a7 = 1 -> ecall de print de inteiro
		lw a0, 0(t1) #a0 = num[i]
		ecall #print inteiro no a0
		
		li a7, 4 #a7 = 4 -> ecall de print de string
		la a0, espaco #a0 = &espaco
		ecall #print string de espacamento
		
		addi t1, t1, 4 #&t1 = &t1[i+1]
		addi s0, s0, 1 #i++
		j loop #Loop de impressao
encerrar:
	li a7, 10 #a7 = 10 -> ecall de exit
	ecall #exit