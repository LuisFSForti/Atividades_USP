class Aluno:
    def __init__(self, dados):
        self._nota = float(dados[0])
        self._reprovacoes = float(dados[1])
        self._nome = dados[2]

    def Compare(self, outro):
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

        return 0

tipo = int(input())
nroCandidatos, nroBolsas = [int(i) for i in input().split()]

Alunos = []

for i in range(nroCandidatos):
    aux = input()
    Alunos.append(Aluno(aux.split()))
