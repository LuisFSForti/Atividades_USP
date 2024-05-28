def Hash(palavra, S, i, c1, c2):
    v = 0
    for caracter in palavra:
        v += v*3 + ord(caracter)
        v = v % S

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

    def EncontrarPalavra(self, palavra):
        hash = -1
        i = 0
        disponivel = -1
        while hash == -1:
            hash = Hash(palavra, self.S, i, self.c1, self.c2)
            if self.buckets[hash] == None:
                if disponivel == -1:
                    return -1, hash
                else:
                    return -1, disponivel
            else:
                if self.buckets[hash].palavra == palavra:
                    return 1, hash
                else:
                    if self.buckets[hash].palavra ==  "###" and disponivel == -1:
                        disponivel = hash
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
        maior = Palavra('')
        maior.contagem = -1
        for aux in self.buckets:
            if aux != None:
                if aux.palavra != "###":
                    diferentes += 1
                    if aux.contagem > maior.contagem:
                        maior = aux
                    elif aux.contagem == maior.contagem and aux.palavra < maior.palavra:
                        maior = aux

        print("foram encontradas", diferentes, "palavras diferentes")
        print("palavra mais frequente = ", maior.palavra, ", encontrada ", maior.contagem, " vezes", sep='')

    def EncontrarPalavras(self, palavras):
        for palavra in palavras:
            res, pos = self.EncontrarPalavra(palavra)
            if res > 0:
                print(palavra, "encontrada", self.buckets[pos].contagem)
            else:
                print(palavra, "nao encontrada")

    def EncontrarPalavras2(self, palavras):
        f = open("teste.txt", "w")
        for palavra in palavras:
            res, pos = self.EncontrarPalavra(palavra)
            if res > 0:
                f.write(palavra + " encontrada " + str(self.buckets[pos].contagem) + "\n")
            else:
                f.write(palavra + " nao encontrada\n")
        f.close()

    def ExcluirPalavras(self, palavras):
        f = open("teste.txt", "w")
        for palavra in palavras:
            res, pos = self.EncontrarPalavra(palavra)
            if res > 0:
                self.buckets[pos] = Palavra("###")
                print(palavra, " removida")
            else:
                print(palavra, " nao encontrada")

    def ExcluirPalavras2(self, palavras):
        f = open("teste.txt", "a")
        for palavra in palavras:
            res, pos = self.EncontrarPalavra(palavra)
            if res > 0:
                self.buckets[pos] = Palavra("###")
                f.write(palavra + " removida\n")
            else:
                f.write(palavra + " nao encontrada\n")

        f.close()

    def Print(self):
        print("imprimindo tabela hash")
        for i in range(self.S):
            if self.buckets[i] != None:
                if self.buckets[i].palavra != "###":
                    print(self.buckets[i].palavra, i)
        print("fim da tabela hash")

entrada = [int(palavra) for palavra in input().split(' ')]
dic = Dicionario(entrada[1],entrada[2],entrada[0])

entrada = -1

while entrada != 0:
    entrada = int(input())

    match entrada:
        case 1:
            palavras = input().split(' ')
            
            for i in range(len(palavras)):
                palavras[i] = palavras[i].replace('\r', '')
                if palavras[i] == '':
                    palavras.pop(i)
            
            dic.Inserir(palavras)
        case 2:
            dic.ContarDiferentes()
        case 3:
            palavras = []
            for i in range(int(input())):
                palavras.append(input())

            for i in range(len(palavras)):
                palavras[i] = palavras[i].replace('\r', '')

            #dic.EncontrarPalavras(palavras)
            dic.EncontrarPalavras2(palavras)
        case 4:
            palavras = []
            for i in range(int(input())):
                palavras.append(input())

            for i in range(len(palavras)):
                palavras[i] = palavras[i].replace('\r', '')

            #dic.ExcluirPalavras(palavras)
            dic.ExcluirPalavras2(palavras)
        case 5:
            dic.Print()
        case _:
            continue
