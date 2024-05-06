class Aluno:
    def __init__(self, dados):
        self._nota = float(dados[0])
        self._reprovacoes = float(dados[1])
        self._nome = dados[2]

    def CompareTo(self, outro):
        if self._reprovacoes >= 10:
            if outro._reprovacoes < 10:
                return -1

        if outro._reprovacoes >= 10:
            if self._reprovacoes < 10:
                return 1

        if self._nota > outro._nota:
            return 1
        else:
            if self._nota < outro._nota:
                return -1
            else:
                if self._reprovacoes < outro._reprovacoes:
                    return 1
                else:
                    if self._reprovacoes > outro._reprovacoes:
                        return -1

        if self._nome < outro._nome:
            return 2
        else:
            return -2

    def Print(self):
        print(self._nome, self._nota, self._reprovacoes)

def SelectionSort(Alunos):
    for i in range(len(Alunos)):
        ind = i
        for j in range(i, len(Alunos)):
            if Alunos[ind].CompareTo(Alunos[j]) <= -1:
                ind = j

        aux = Alunos[i]
        Alunos[i] = Alunos[ind]
        Alunos[ind] = aux

def MergeSort(Alunos, comeco, fim):
    if comeco == fim:
        return [Alunos[comeco]]

    aux1 = MergeSort(Alunos, comeco, comeco + int((fim-comeco)/2))
    aux2 = MergeSort(Alunos, comeco + int((fim-comeco)/2) + 1, fim)

    aux3 = []

    i, j = 0,0

    while i < len(aux1) or j < len(aux2):
        if i == len(aux1):
            aux3.append(aux2[j])
            j += 1
            continue

        if j == len(aux2):
            aux3.append(aux1[i])
            i += 1
            continue
        
        if aux1[i].CompareTo(aux2[j]) >= 1:
            aux3.append(aux1[i])
            i += 1
        else:
            aux3.append(aux2[j])
            j += 1

    return aux3

tipo = int(input())
nroCandidatos, nroBolsas = [int(i) for i in input().split()]

if nroCandidatos < nroBolsas:
    nroBolsas = nroCandidatos

Alunos = []

for i in range(nroCandidatos):
    aux = input()
    Alunos.append(Aluno(aux.split()))

if tipo == 1:
    SelectionSort(Alunos)
else:
    Alunos = MergeSort(Alunos, 0, len(Alunos)-1)

if nroCandidatos > nroBolsas:
    if Alunos[nroBolsas-1].CompareTo(Alunos[nroBolsas]) == 2 or Alunos[nroBolsas-1].CompareTo(Alunos[nroBolsas]) == -2:
        nroBolsas += 1
    
print(nroBolsas)

for i in range(nroBolsas):
    print(Alunos[i]._nome)
