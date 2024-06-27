#=================Dinâmico======================#
def AlgoritmoDinamico(itens, mochila):
    #Cria a matriz que vai armazenar as melhores possibilidades
    z = [[-1e5 for i in range(mochila+1)] for j in range(len(itens)+1)]

    #Para cada caso (sem itens + cada item)
    for i in range(len(itens)+1):
        #Para cada carga (0 até a máxima da mochila)
        for w in range(mochila+1):
            #Se for o caso 0 ou se a carga permitida for 0
            if i == 0 or w == 0:
                #Salva como 0 e aumenta a carga permitida
                z[i][w] = 0
                continue

            #Define que a melhor opção é igual ao do caso anterior
            z[i][w] = z[i-1][w]
            #Se a carga permitida for maior que a do item atual
            if w >= itens[i-1][0]:
                #Verifica qual opção é melhor:
                #A do caso anterior (que está salva na posição atual)
                #ou o valor do item atual + o resultado do caso anterior com a carga restante disponível
                z[i][w] = max(z[i-1][w], itens[i-1][1] + z[i-1][w - itens[i-1][0]])

    #Para verificar quais foram os itens escolhidos
    i, w = len(itens), mochila
    escolhidos = []

    #Enquanto não tiverem acabado os casos
    while i > 0:
        #Se o caso anterior para a mesma carga for diferente
        if z[i][w] != z[i-1][w]:
            #Salva que o item atual foi escolhido
            escolhidos.append(i-1)
            #Diminui a carga restante pelo peso do item atual
            w -= itens[i-1][0]
        #Volta um caso
        i -= 1

    #Retorna o valor máximo obtido e com quais itens (em ordem)
    return(z[len(itens)][mochila], sorted(escolhidos))

#=================Guloso======================#

def AlgoritmoGuloso(itens, mochila):
    #Calcula as razões
    razoes = [item[1] / item[0] for item in itens]
    #Junta todas as informações
    dados = [[razoes[i], itens[i][0], itens[i][1]] for i in range(len(itens))]
    #Reordena em ordem decrescente para as razões e ordem crescente para os pesos
    dados = sorted(dados, key=lambda x: (x[0], -x[1]), reverse=True)

    #Peso total, valor total, itens escolhidos
    peso = 0
    valor = 0
    escolhidos = []
    #Para cada item (na ordem das razões)
    for item in dados:
        #Se o peso, com o item atual, for maior que a carga disponível da mochila
        if peso + item[1] > mochila:
            #Retorna os resultados obtidos
            return valor, escolhidos

        #Se houver espaço para o item
        #Adiciona seu peso e seu valor
        peso += item[1]
        valor += item[2]
        #Adiciona ao escolhidos o indíce do item atual
        #As informações do item (peso e valor) estão nas posições 1 e 2 de item
        escolhidos.append(itens.index(item[1:3]))

#=================Main======================#
#Pega o limite da mochila e a quantidade de itens
entrada = input().split()
limiteMochila, qtdItens = int(entrada[0]), int(entrada[1])

#Pega os itens
itens = []
for i in range(qtdItens):
    itens.append([int(num) for num in input().split()])

#Dinâmico
valorD, escolhidosD = AlgoritmoDinamico(itens.copy(), limiteMochila)
#Imprime os resultados obtidos pelo dinâmico
for item in escolhidosD:
    print(item, end = ' ')
print()

#Guloso
valorG, escolhidosG = AlgoritmoGuloso(itens.copy(), limiteMochila)
#Imprime os resultados obtidos pelo guloso
for item in escolhidosG:
    print(item, end=' ')
print()

#Imprime ambos os valores totais obtidos e a proporção do guloso
print(valorD, valorG)
print("%.2f" % (valorG/valorD * 100))
