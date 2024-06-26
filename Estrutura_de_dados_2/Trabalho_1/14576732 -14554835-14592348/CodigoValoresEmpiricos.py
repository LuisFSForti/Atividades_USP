#Luís Filipe Silva Forti 14592348
#Lucien Rodrigues Franzen 14554835
#Gustavo Curado Ribeiro 14576732

import time
import copy

#Elimiar o primeiro número, pois não é necessário
entrada = input()
#Ler a sequência numérica
entrada = input()

#Separa a sequência e salva
original = [int(valor) for valor in entrada.split() if valor.isdigit()]

media = 0
for k in range(10):
    #Cria uma cópia dos valores, para que os valores originais não sejam
    #alterados
    valores = copy.deepcopy(original)
    #Código para a análise empírica
    tempo = time.time()

    #Para passar por todas as casas
    for i in range(0, len(valores)):
        #Para verificar todas as casas não-organizadas
        for j in range(i+1, len(valores)):
            #Se o valor da casa j for menor que o valor da casa i
            if valores[i] > valores[j]:
                #Salva o valor da casa i
                aux = valores[i]
                #Substitui pelo valor da casa j
                valores[i] = valores[j]
                #Salva o valor da casa i em j
                valores[j] = aux
                #Dessa forma, sempre que aparecer um valor menor que o valor em i,
                #ele irá trocar de lugar, organizando em forma crescente

    #Adiciona o tempo gasto
    media += time.time() - tempo

#Diz qual foi a média de tempo gasto
print(media/10)
