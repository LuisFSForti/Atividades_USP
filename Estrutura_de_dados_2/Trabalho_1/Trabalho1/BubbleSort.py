import time

entrada = input()

valores = []
valorAtual = 0

valores = [int(valor) for valor in entrada.split() if valor.isdigit()]

#tempo = time.time()

for i in range(0, len(valores)):
    for j in range(0, len(valores)):
        if valores[i] < valores[j]:
            aux = valores[i]
            valores[i] = valores[j]
            valores[j] = aux

#print(time.time() - tempo)

for valor in valores:
    print(valor, end = ' ')
