	.data # diretiva p/ inicio do seg de dados
	.align 2
entrada: .word 0
	
	.align 0 # alinha a memoria para armazenar string
instrucoes: .asciz  "Para jogar digite pedra(1), papel(2) ou tesoura(3)\nPara finalizar digite 4\n"
erro: .asciz  "\nERRO\n"

mensagemVitoria: .asciz "Voce venceu!\n"
mensagemEmpate: .asciz "Empate!\n"
mensagemDerrota: .asciz "Voce perdeu!\n"

	.text # diretiva p/ inicio do segmento de texto
	.globl main # diretiva p/ usar rotulo em outro prog.
main: # rotulo para ponto de entrada no processo
	.align 2 # alinha a memoria para armazenar as instrucoes de 32 bits

ler_jogada:
	#Fornece as intrucoes
	addi a7, x0, 4 # codigo do servico 4 (impressao de string)
	la a0, instrucoes # endereco do 1o byte da string
	ecall # Chamada linux
      
	#Recebe a jogada
	addi a7, x0, 5 # codigo do servico 5 (leitura de int)
	ecall # Chamada linux
	
verificar_entrada:
	#Confere se foi um numero valido
	addi t1, x0, 1 #t1 = 1
	blt a0, t1, aviso_erro #Se a0 < t1 -> ERRO
	addi t1, x0, 4 #t1 = 4
	bgt a0, t1, aviso_erro #Se a0 > t1 -> ERRO
	beq a0, t1, finalizar #Se a0 == t1 -> Finalizar o codigo
	sw a0, entrada, t2 #Salva em entrada a jogada
	
verificar_resultado:
	addi a7, x0, 42 # codigo do servico 42 (numero aleatorio)
	addi a0, x0, 719 #valor para o calculo do numero pseudoaleatorio (número primo escolhido arbitrariamente)
	addi a1, x0, 3 #limite nao-inclusivo do aleatorio
	ecall # Chamada linux
	
	lw t1, entrada #t1 = entrada
	addi t2, a0, 1 #a0 esta entre 0 e 2 (inclusivo), entao soma-se 1
	
	beq t1, t2, jogador_empatou #Se empataram
	
	#Se nao empataram
	#Computador = x
	#Jogador = y
	#x < y -> Jogador ganha
		#Se x+1 == y ou se x-2 == y (tesoura(3) - 2 = 1)
	#x > y -> Computador ganha
	addi t3, t2, 1 #Soma 1
	addi t2, t3, -3 #Subtrai 3
	
	beq t1, t2, jogador_venceu #Se x+1 == y -> Jogador venceu
	beq t1, t3, jogador_venceu #Se x-2 == y -> Jogador venceu
	
	j jogador_perdeu #Se o jogador perdeu
	
jogador_venceu:
	addi a7, x0, 4 # codigo do servico 4 (impressao de string)
	la a0, mensagemVitoria # endereco do 1o byte da string
	ecall # Chamada linux
	j ler_jogada

jogador_empatou:
	addi a7, x0, 4 # codigo do servico 4 (impressao de string)
	la a0, mensagemEmpate # endereco do 1o byte da string
	ecall # Chamada linux
	j ler_jogada
	
jogador_perdeu:
	addi a7, x0, 4 # codigo do servico 4 (impressao de string)
	la a0, mensagemDerrota # endereco do 1o byte da string
	ecall # Chamada linux
	j ler_jogada
    
aviso_erro:
	#Para qualquer possivel erro, chamar essa funcao
	addi a7, x0, 4 # codigo do servico 4 (impressao de string)
	la a0, erro # endereco do 1o byte da string
	ecall # Chamada linux
	
	j ler_jogada
	
finalizar:
	addi a7, x0, 10 # codigo do servico que encerra
	ecall # chamada linux para terminar o programa