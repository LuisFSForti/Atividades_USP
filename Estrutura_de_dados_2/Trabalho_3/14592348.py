def Hash(palavra, S, i, c1, c2):
    v = 0
    for caracter in palavra:
        v += v*3 + ord(caracter)
        v = (v + c1 * i + c2 * i**2) % S

    return v

class Palavra:
    def __init__(self, palavra):
        self.palavra = palavra
        self.contagem = 1

class Dicionario:
    def __init__(self, c1, c2, S):
        self.c1 = c1
        self.c2 = c2
        self.S = S
        self.buckets = [None] * S
        #print(self.buckets)

    def EncontrarPalavra(self, palavra):
        hash = -1
        i = 0
        while hash == -1:
            hash = Hash(palavra, self.S, i, self.c1, self.c2)
            if self.buckets[hash] == None:
                return -1, hash
            else:
                if self.buckets[hash].palavra == palavra:
                    return 1, hash
                else:
                    hash = -1
                    i += 1

    def Inserir(self, palavras):
        for palavra in palavras:
            res, pos = self.EncontrarPalavra(palavra)
            if res > 0:
                self.buckets[pos].contagem += 1
            else:
                self.buckets[pos] = Palavra(palavra)

    def ContarDiferentes(self):
        diferentes = 0
        maior = Palavra('zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz')
        maior.contagem = -1
        for aux in self.buckets:
            if aux != None:
                if aux.palavra != "###":
                    diferentes += 1
                    if aux.contagem > maior.contagem:
                        maior = aux
                    elif aux.contagem == maior.contagem and aux.palavra < maior.palavra:
                        maior = aux

        print("foram encontradas ", diferentes, " palavras diferentes")
        print("palavra mais frequente = ", maior.palavra, ", encontrada ", maior.contagem, " vezes", sep='')

    def EncontrarPalavras(self, palavras):
        for palavra in palavras:
            res, pos = self.EncontrarPalavra(palavra)
            if res > 0:
                print(palavra, "encontrada ", self.buckets[pos].contagem)
            else:
                print(palavra, "nao encontrada")

    def ExcluirPalavras(self, palavras):
        for palavra in palavras:
            res, pos = self.EncontrarPalavra(palavra)
            if res > 0:
                self.buckets[pos] = Palavra("###")
                print(palavra, "removida")
            else:
                print(palavra, "nao removida")

    def Print(self):
        for i in range(self.S):
            if self.buckets[i] != None:
                print(i, self.buckets[i].palavra, self.buckets[i].contagem)
            else:
                print(i, None)

entrada = [int(palavra) for palavra in input().split(' ')]
dic = Dicionario(entrada[1],entrada[2],entrada[0])

entrada = -1

while entrada != 0:
    entrada = int(input())

    match entrada:
        case 1:
            dic.Inserir(input().split(' '))
        case 2:
            dic.ContarDiferentes()
        case 3:
            palavras = []
            for i in range(int(input())):
                palavras.append(input())

            dic.EncontrarPalavras(palavras)
        case 4:
            palavras = []
            for i in range(int(input())):
                palavras.append(input())

            dic.ExcluirPalavras(palavras)
        case _:
            continue
