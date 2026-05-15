#include <iostream>
#include <vector>
#include <string>

std::vector<int> CriarKMP(const std::string& substring)
{
    int m = substring.size();
    //Cria o vetor com 0 em todas as posições
    std::vector<int> kmp(m, 0);

    //Começa em i = 1 porque a posição i=0 é sempre 0 (pois precisa ser um prefixo próprio, não pode ser o subpadrão inteiro)
    int i = 1;
    int tamanho = 0;

    //tamanho marca o tamanho do prefixo atual (ou seja, aponta pro último caractere do prefixo)
    //i marca o final do subpadrão atual (ou seja, o final do sufixo)
    //O objetivo é armazenar em KMP[i] qual o maior prefixo que é igual ao sufixo que termina em i
    //Assim, se der match/missmatch na posição i, então sabe-se que os últimos KMP[i] caracteres são válidos para a próxima leitura

    while (i < m)
    {
        //Se o prefixo for igual ao sufixo
        if (substring[tamanho] == substring[i])
        {
            //Salva o tamanho do prefixo e avança
            tamanho++;
            kmp[i] = tamanho;
            i++;
        }
        //Se não forem iguais
        else
        {
            //Se o prefixo já tinha tamanho
            if (tamanho != 0)
            {
                //Muda para o próximo prefixo menor e não avança o sufixo
                tamanho = kmp[tamanho - 1];
            }
            //Se não tinha um prefixo válido
            else
            {
                //Então o sufixo atual não tem um prefixo válido
                kmp[i] = 0;
                //Avança o sufixo
                i++;
            }
        }
    }

    return kmp;
}

int main()
{
    std::string texto, substring;

    std::cin >> texto >> substring;

    int n = texto.size();
    int m = substring.size();

    std::vector<int> kmp = CriarKMP(substring);

    int i = 0;
    int j = 0;
    int ocorrencias = 0;

    while (i < n)
    {
        //Se o caractere coincidiu com a sequência da substring
        if (texto[i] == substring[j])
        {
            //Então a substring e o texto avançam
            i++;
            j++;
        }

        //Se j == m, então encontrou a substring
        if (j == m)
        {
            //Aumenta as ocorrências
            ocorrencias++;
            //Verifica quantos dos últimos caracteres podem ser considerados válidos pra nova leitura
            //Ou seja, quantos caracteres do sufixo atual são também prefixo
            j = kmp[j - 1];
        }
        //Se não encontrou a substring
        //Se não acabou o texto e os caracteres não coincidiram
        else if (i < n && texto[i] != substring[j])
        {
            //Se j for diferente de 0, ou seja, alguns caracteres foram validados
            if (j != 0)
            {
                //Verifica quantos dos últimos caracteres podem ser considerados válidos pra nova leitura
                //Ou seja, quantos caracteres do sufixo atual são também prefixo
                j = kmp[j - 1];
            }
            //Se j for 0, então nada foi validado ainda
            else
            {
                //Então só avança o texto
                i++;
            }
        }
    }

    std::cout << ocorrencias << std::endl;

    return 0;
}