#Membros:
#Caue Sordi Paulino - 14564520
#Gustavo Curado Ribeiro - 14576732
#Lucien Rodrigues Franzen - 14554835
#Luis Filipe Silva Forti - 14592348

.data # diretiva p/ inicio do seg de dados
.align 2
	entrada: .word 0
	lista_comeco: .word 0
	lista_fim: .word 0	
	
.align 0 # alinha a memoria para armazenar string
	instrucoes: .asciz  "Para jogar digite pedra(1), papel(2) ou tesoura(3)\nPara finalizar digite 4\n"
	erro: .asciz  "\nERRO\n"

	mensagemVitoria: .asciz "Voce venceu!\n"
	mensagemEmpate: .asciz "Empate!\n"
	mensagemDerrota: .asciz "Voce perdeu!\n"

	mensagemLista: .asciz "\nJogadas efetuadas pelo computador:\n"
	mensagemPedra: .asciz "Pedra\n"
	mensagemPapel: .asciz "Papel\n"
	mensagemTesoura: .asciz "Tesoura\n"


.text # diretiva p/ inicio do segmento de texto
.globl main # diretiva p/ usar rotulo em outro prog.
.align 2 # alinha a memoria para armazenar as instrucoes de 32 bits

main: # rotulo para ponto de entrada no processo

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
	beq a0, t1, printa_Lista #Se a0 == t1 -> Printa o conte�do da lista e finaliza o c�digo
	sw a0, entrada, t2 #Salva em entrada a jogada
	
verificar_resultado:
	addi a7, x0, 42 # codigo do servico 42 (numero aleatorio)
	addi a0, x0, 719 #valor para o calculo do numero pseudoaleatorio (n�mero primo escolhido arbitrariamente)
	addi a1, x0, 3 #limite nao-inclusivo do aleatorio
	ecall # Chamada linux
	
	lw s1, entrada #t1 = entrada
	addi s2, a0, 1 #a0 esta entre 0 e 2 (inclusivo), entao soma-se 1

	add a0, zero, s2	#Salva em a0 o valor da jogada aleat�ria
	call adiciona_elemento  #Adiciona a jogada � lista
	
	beq s1, s2, jogador_empatou #Se empataram
	
	#Se nao empataram
	#Computador = x
	#Jogador = y
	#x < y -> Jogador ganha
		#Se x+1 == y ou se x-2 == y (tesoura(3) - 2 = 1)
	#x > y -> Computador ganha
	addi s3, s2, 1 #Soma 1
	addi s2, s3, -3 #Subtrai 3
	
	beq s1, s2, jogador_venceu #Se x+1 == y -> Jogador venceu
	beq s1, s3, jogador_venceu #Se x-2 == y -> Jogador venceu
	
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
	
printa_Lista:
	la s0, lista_comeco	#Se n�o houverem elementos na lista (lista_comeco==NULL), finaliza o programa
	lw s0, 0(s0)
	beq s0, zero, finalizar

	addi a7, zero, 4        #Printa a mensagem que antecede a listagem das jogadas aleat�rias
	la a0, mensagemLista
	ecall

#Loop que printa as jogadas armazenadas na lista
loop_print:
	lw t0, 0(s0) #Salva em t0 a jogada armazenada no elemento
	
	addi t1, zero, 1  #t1 = 1
	addi t2, zero, 2  #t2 = 2
	addi t3, zero, 3  #t3 = 3
	beq t0, t1, printa_pedra   #Caso a jogada do computador for 1, printa "Pedra"
	beq t0, t2, printa_papel   #Caso a jogada do computador for 2, printa "Papel"
	beq t0, t3, printa_tesoura #Caso a jogada do computador for 3, printa "Tesoura"

printa_pedra:
	addi a7, zero, 4     #Printa "Pedra"
	la a0, mensagemPedra
	ecall

	lw s0, 4(s0)  #Armazena em s0 o ponteiro do pr�ximo elemento
	bne s0, zero, loop_print #Se o pr�ximo elemento existir (s0 != NULL), continua o loop
	j finalizar

printa_papel:
	addi a7, zero, 4     #Printa "Papel"
	la a0, mensagemPapel
	ecall

	lw s0, 4(s0)  #Armazena em s0 o ponteiro do pr�ximo elemento
	bne s0, zero, loop_print #Se o pr�ximo elemento existir (s0 != NULL), continua o loop
	j finalizar

printa_tesoura:
	addi a7, zero, 4       #Printa "Tesoura"
	la a0, mensagemTesoura
	ecall

	lw s0, 4(s0)  #Armazena em s0 o ponteiro do pr�ximo elemento
	bne s0, zero, loop_print #Se o pr�ximo elemento existir (s0 != NULL), continua o loop

finalizar:
	addi a7, x0, 10 # codigo do servico que encerra
	ecall # chamada linux para terminar o programa



#Acrescenta um elemento ao final da lista e salva seu endere�o em "lista_fim".
#Se a lista estiver vazia, salva seu endere�o tamb�m em "lista_comeco".
#Input: a0 -> conte�do do elemento	 
#Estrutura de um elemento:
#	*4 bytes -> conte�do do elemento (o n�mero da jogada aleat�ria)
#	*4 bytes -> ponteiro para o pr�ximo elemento
adiciona_elemento:
	add t1, zero, a0 #Salva o conte�do do elemento em t1

	addi a7, zero, 9 #Aloca 8 bytes de mem�ria para o elemento
	addi a0, zero, 8
	ecall

	sw t1, 0(a0)         #Salva o conte�do do elemento na mem�ria
	addi t1, zero, 0  
	sw t1, 4(a0)         #Nulifica o espa�o que guarda a ponteiro do pr�ximo elemento
	add t1, zero, a0     #Salva o endere�o do elemento alocado em t1

	la t0, lista_comeco
	lw t0, 0(t0)             
	beq t0, zero, cria_lista  #Caso lista_comeco==NULL (lista vazia), cria a lista

	la t0, lista_fim  #Faz o pen�ltimo elemento da lista apontar para o elemento rec�m-alocado
	lw t0, 0(t0)
	sw t1, 4(t0)

	la t0, lista_fim  #Salva o endere�o do elemento alocado em lista_fim
	sw t1, 0(t0)

	j salva_fim

#Salva o endere�o do elemento tamb�m em "lista_comeco", caso a lista esteja vazia 
cria_lista:
	la t0, lista_comeco #Salva o endere�o do elemento alocado em lista_comeco
	sw t1, 0(t0)

#�ltimos detalhes para adicionar o elemento � lista
salva_fim:
	la t0, lista_fim  #Salva o endere�o do elemento alocado em lista_fim
	sw t1, 0(t0)

	ret #Retorna para o local onde a fun��o adiciona_elemento foi chamada
