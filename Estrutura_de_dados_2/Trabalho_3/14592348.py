def Hash(palavra, S, i, c1, c2):
    v = 0
    #Calcula o hash de "palavra" e salva em v
    for caracter in palavra:
        v += v*3 + ord(caracter)
        v = v % S

    #Lida com as colisões
    v = (v + c1 * i + c2 * i**2) % S

    return v

#Para salvar os dados de cada palavra
class Palavra:
    def __init__(self, palavra):
        self.palavra = palavra
        #Toda palavra começa com contagem 1
        self.contagem = 1

#Para lidar com o dicionário
class Dicionario:
    #Salva os dados iniciais e cria a tabela
    def __init__(self, c1, c2, S):
        self.c1 = c1
        self.c2 = c2
        self.S = S
        self.buckets = [None] * S

    #Para encontrar uma palavra
    def EncontrarPalavra(self, palavra):
        #Posição
        hash = -1
        #Número de colisões
        i = 0
        #Se ele não encontrar a palavra, mas encontrar "###", esta variável irá salvar
        #onde achou o primeiro espaço vago
        disponivel = -1

        #Loop infinito
        while True:
            #Calcula o hash da palavra, considerando colisões
            hash = Hash(palavra, self.S, i, self.c1, self.c2)
            #Se não há palavras no espaço
            if self.buckets[hash] == None:
                #Se não encontrou algum local com "###"
                if disponivel == -1:
                    #Retorna que não encontrou a palavra e a posição vazia
                    return -1, hash
                #Se encontrou "###"
                else:
                    #Retorna que não encontrou a palavra e a posição vaga
                    return -1, disponivel
            #Se o endereço não está vazio
            else:
                #Se for a palavra procurada
                if self.buckets[hash].palavra == palavra:
                    #Retorna que encontrou a palavra e a posição
                    return 1, hash
                #Se não for a palavra
                else:
                    #Se for a primeira vez que encontrou "###"
                    if self.buckets[hash].palavra ==  "###" and disponivel == -1:
                        #Salva a posição
                        disponivel = hash

                    #Como não encontrou a palavra e não é um espaço vazio, aumenta o número de colisões em 1
                    i += 1

    #Para inserir um conjunto de palavras
    def Inserir(self, palavras):
        #Para cada palavra
        for palavra in palavras:
            #Se encontrou e onde
            res, pos = self.EncontrarPalavra(palavra)
            #Se encontrou
            if res > 0:
                #Aumenta a contagem em 1
                self.buckets[pos].contagem += 1
            #Se não encontrou
            else:
                #Salva a nova palavra
                self.buckets[pos] = Palavra(palavra)

    #Para fazer as estatísticas das palavrvas
    def ContarDiferentes(self):
        diferentes = 0

        #Cria uma palavra com contagem negativa, para que qualquer outra palavra seja maior
        maior = Palavra('')
        maior.contagem = -1
        #Para cada endereço da tabela
        for aux in self.buckets:
            #Se não estiver vazio
            if aux != None:
                #Se não estiver vago
                if aux.palavra != "###":
                    #Salva que é uma palavra nova diferente
                    diferentes += 1
                    #Se tiver mais repetições que "maior"
                    if aux.contagem > maior.contagem:
                        maior = aux
                    #Se tiver mesma quantidade de repetições e vier primeiro alfabeticamente
                    elif aux.contagem == maior.contagem and aux.palavra < maior.palavra:
                        maior = aux

        print("foram encontradas", diferentes, "palavras diferentes")
        print("palavra mais frequente = ", maior.palavra, ", encontrada ", maior.contagem, " vezes", sep='')

    #Para pesquisar sobre um conjunto de palavras
    def EncontrarPalavras(self, palavras):
        #Para cada palavra
        for palavra in palavras:
            #Se encontrou e onde
            res, pos = self.EncontrarPalavra(palavra)
            #Se encontrou
            if res > 0:
                print(palavra, "encontrada", self.buckets[pos].contagem)
            #Se não encontrou
            else:
                print(palavra, "nao encontrada")

    #Para excluir um conjunto de palavras
    def ExcluirPalavras(self, palavras):
        #Para cada palavra
        for palavra in palavras:
            #Se encontrou e onde
            res, pos = self.EncontrarPalavra(palavra)
            #Se encontrou
            if res > 0:
                #Marca a posição como vaga
                self.buckets[pos] = Palavra("###")
                print(palavra, "removida")
            #Se não encontrou
            else:
                print(palavra, "nao encontrada")

    #Para imprimir todas as palavras e suas posições
    def Print(self):
        print("imprimindo tabela hash")
        #Para cada posição da tabela
        for i in range(self.S):
            #Se não estiver vazio
            if self.buckets[i] != None:
                #Se não estiver vago
                if self.buckets[i].palavra != "###":
                    #Imprime a palavra e sua posição
                    print(self.buckets[i].palavra, i)
        print("fim da tabela hash")

#/////Main/////

#Pega a primeira entrada
entrada = [int(palavra) for palavra in input().split(' ')]
#Cria o dicionário com C1, C2 e S passados em "entrada"
dic = Dicionario(entrada[1],entrada[2],entrada[0])

#Deixa a entrada com um valor neutro
entrada = -1

#Enquanto não for digitado o comando 0
while entrada != 0:
    #Pega o comando
    entrada = int(input())

    match entrada:
        #Se o comando for 1
        case 1:
            #Pega as palavras separadas por espaço
            palavras = input().split(' ')

            #Para corrigir bugs do Runcodes
            for i in range(len(palavras)):
                #Remove caracteres inválidos
                palavras[i] = palavras[i].replace('\r', '')
                palavras[i] = palavras[i].replace('\n', '')
                palavras[i] = palavras[i].replace(' ', '')
                
                #Se não houve mais um caracter
                if palavras[i] == '':
                    #Remove a posição
                    palavras.pop(i)

            #Insere as palavras no dicionário
            dic.Inserir(palavras)
            
        #Se o comando for 2
        case 2:
            #Imprime as estatísticas
            dic.ContarDiferentes()

        #Se o comando for 3
        case 3:
            palavras = []
            #Pega todas as palavras
            for i in range(int(input())):
                palavras.append(input())

            #Para corrigir bugs do Runcodes
            for i in range(len(palavras)):
                #Remove caracteres inválidos
                palavras[i] = palavras[i].replace('\r', '')
                palavras[i] = palavras[i].replace('\n', '')
                palavras[i] = palavras[i].replace(' ', '')
                
                #Se não houve mais um caracter
                if palavras[i] == '':
                    #Remove a posição
                    palavras.pop(i)

            #Procura as palavras e apresenta suas contagens
            dic.EncontrarPalavras(palavras)

        #Se o comando for 4
        case 4:
            palavras = []
            #Pega todas as palavras
            for i in range(int(input())):
                palavras.append(input())

            #Para corrigir bugs do Runcodes
            for i in range(len(palavras)):
                #Remove caracteres inválidos
                palavras[i] = palavras[i].replace('\r', '')
                palavras[i] = palavras[i].replace('\n', '')
                palavras[i] = palavras[i].replace(' ', '')
                
                #Se não houve mais um caracter
                if palavras[i] == '':
                    #Remove a posição
                    palavras.pop(i)

            #Procura as palavras e as exclui
            dic.ExcluirPalavras(palavras)

        #Se o comando for 5
        case 5:
            #Imprime todas as palavras e suas posições
            dic.Print()
        #Se o comando não for nnenhum dos outros números
        case _:
            #Continua o loop
            continue
