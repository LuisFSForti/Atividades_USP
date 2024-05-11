class Aluno:
    def __init__(self, dados):
        #Os dados de cada linha são passados como o vetor dados
        self._nota = float(dados[0])
        self._reprovacoes = int(dados[1])
        self._nome = dados[2]

    #Função para comparar dois alunos (self e outro)
    #Se positivo, self é o melhor aluno
    #Se negativo, outro é o melhor aluno
    def CompareTo(self, outro):
        #Se a nota de self for maior
        if self._nota > outro._nota:
            return 1
        else:
            #Se self for menor
            if self._nota < outro._nota:
                return -1
            #Se tiverem a mesma nota
            else:
                #Se self tiver menos reprovações
                if self._reprovacoes < outro._reprovacoes:
                    return 1
                else:
                    #Se outro tiver menos reprovações
                    if self._reprovacoes > outro._reprovacoes:
                        return -1

        #Se chegou nesse ponto, eles estão empatados
        #Se self vier primeiro alfabeticamente
        if self._nome < outro._nome:
            return 2
        #Se outro vier primeiro alfabeticamente
        else:
            return -2

    #Função utilizada para debugar o código, não foi usada na entrega final
    def Print(self):
        print(self._nome, "{:.2f}".format(self._nota), self._reprovacoes)

#Ordenação por selection sort
def SelectionSort(Alunos):
    #Para organizar cada casa
    for i in range(len(Alunos)):
        #Salva a casa inicial como a do melhor aluno
        ind = i
        #Para verificar cada casa entre a atual e a última
        for j in range(i, len(Alunos)):
            #Se o aluno for melhor
            if Alunos[ind].CompareTo(Alunos[j]) <= -1:
                #Salva onde ele está
                ind = j

        #Se achou um aluno melhor que o atual
        if ind != i:
        #Troca os alunos de lugar no vetor
            aux = Alunos[i]
            Alunos[i] = Alunos[ind]
            Alunos[ind] = aux

#Ordenação por MergeSort
def MergeSort(Alunos, comeco, fim):
    #Se está analizando uma única casa
    if comeco == fim:
        #Retorna a casa em forma de vetor
        return [Alunos[comeco]]

    #Metade da esquerda organizada
    aux1 = MergeSort(Alunos, comeco, comeco + int((fim-comeco)/2))
    #Metade da direita organizada
    aux2 = MergeSort(Alunos, comeco + int((fim-comeco)/2) + 1, fim)

    #Vetor organizado atual
    aux3 = []

    #Casa atual de cada vetor
    i, j = 0,0

    #Enquanto um dos vetores não tiver passado todos os seus valores
    while i < len(aux1) and j < len(aux2):
        #Se a casa atual de aux1 tem o melhor aluno
        if aux1[i].CompareTo(aux2[j]) >= 1:
            #Salva a casa atual de aux1
            aux3.append(aux1[i])
            i += 1
        #Se aux2 tiver o melhor aluno
        else:
            #Salva a casa atual de aux2
            aux3.append(aux2[j])
            j += 1

    #Adiciona os alunos que faltaram, como aux1 e aux2 já estão ordenados, basta adicionar à partir do último adicionado do vetor
    #Não importa a ordem que eles estão sendo incluidos, pois um deles não adicionará nenhum aluno
    aux3.extend(aux1[i:])
    aux3.extend(aux2[j:])

    #Retorna o vetor organizado, o qual será manipulado recusrivamente
    return aux3

#Qual o tipo de ordenação
tipo = int(input())
#Pega o número de candidatos e o número de bolsas disponíveis
nroCandidatos, nroBolsas = [int(i) for i in input().split()]

#Vetor dos alunos
Alunos = []

#Para ler todos
for i in range(nroCandidatos):
    #Linha atual
    aux = input()

    #Se o aluno tiver mais que 10 reprovações, ele é inválido
    if int(aux.split()[1]) <= 10:
        #Se for válido, salva seus dados
        Alunos.append(Aluno(aux.split()))
    #Se for inválido
    else:
        #Diminui o número de candidatos em 1
        nroCandidatos -= 1

#Chama o método de ordenação pedido
if tipo == 1:
    SelectionSort(Alunos)
else:
    Alunos = MergeSort(Alunos, 0, len(Alunos)-1)

#Se tiverem mais candidatos que bolsas
if nroCandidatos > nroBolsas:
    #Verifica se o último aluno dentro do limite de bolsas está empatado com o próximo
    while Alunos[nroBolsas-1].CompareTo(Alunos[nroBolsas]) == 2 or Alunos[nroBolsas-1].CompareTo(Alunos[nroBolsas]) == -2:
        #Se sim, cria mais uma bolsa para o aluno empatado
        nroBolsas += 1
        
#Se tiverem menos candidatos que bolsas
else:
    #Diminui o número de bolsas para a quantidade de candidatos
    nroBolsas = nroCandidatos

#Imprime o número de bolsas
print(nroBolsas)

#Imprime o nome de todos os alunos que ganharam bolsa, na ordem de prioridade
for i in range(nroBolsas):
    print(Alunos[i]._nome)
