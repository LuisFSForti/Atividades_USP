#include <iostream>
#include <vector>

struct LagoAux
{
    long long nroMilho, acumuloMilho;
};

int main()
{
    int tamX, tamY;
    std::cin >> tamY >> tamX;

    //Pega os dados do lago
    std::vector<std::vector<LagoAux>> lago (tamY);
    for (int i = 0; i < tamY; ++i)
    {
        lago[i] = std::vector<LagoAux>(tamX);
        for (int j = 0; j < tamX; ++j)
        {
            std::cin >> lago[i][j].nroMilho;
            lago[i][j].acumuloMilho = 0;
        }
    }

    //Se a entrada ou a saída estiverem bloqueadas
    if (lago[0][0].nroMilho == -1 || lago[tamY-1][tamX-1].nroMilho == -1)
    {
        //Retorna que não há caminhos e encerra
        std::cout << "-1" << std::endl;
        return 0;
    }

    //Se há caminhos possíveis
    //Então marca que a entrada terá acúmulo igual ao seu valor
    lago[0][0].acumuloMilho = lago[0][0].nroMilho;

    //Na primeira linha, só pode vir da esquerda
    //Como o (0,0) já foi tratado, pode pular o j=0
    for (int j = 1; j < tamX; ++j)
    {
        //Se esta posição estiver bloqueada
        if (lago[0][j].nroMilho == -1)
        {
            lago[0][j].acumuloMilho = -1;
            continue;
        }

        //Se estiver bloqueada à esquerda, então está bloqueada
        //Como é a primeira linha, ele não pode vir da direita
        if (lago[0][j-1].nroMilho == -1)
        {
            //Marca como bloqueada
            lago[0][j].nroMilho = -1;
            lago[0][j].acumuloMilho = -1;
        }
        //Se não estiver bloqueada
        else
        {
            //Adiciona ao acúmulo da linha
            lago[0][j].acumuloMilho = lago[0][j].nroMilho + lago[0][j-1].acumuloMilho;
        }
    }

    //Para todas as outras posições
    for (int i = 1; i < tamY; ++i)
    {
        //Vetores auxiliares
        std::vector<long long> vindoDeCima(tamX);
        std::vector<long long> vindoDaEsquerda(tamX);
        std::vector<long long> vindoDaDireita(tamX);
        
        //Calcula quais seriam os acúmulos se visse de cima
        for (int j = 0; j < tamX; ++j)
        {
            //Se a posição estiver bloqueada
            if (lago[i][j].nroMilho == -1)
            {
                vindoDeCima[j] = -1;
                continue;
            }

            //Se a de cima não estiver bloqueada, calcula o acúmulo
            if (lago[i-1][j].acumuloMilho >= 0)
                vindoDeCima[j] = lago[i][j].nroMilho + lago[i-1][j].acumuloMilho;
            //Se estiver, então esta também está
            else
                vindoDeCima[j] = -1;
        }
        //Calcula os acúmulos se viesse da esquerda
        for (int j = 0; j < tamX; ++j)
        {
            //Se a posição estiver bloqueada
            if (lago[i][j].nroMilho == -1)
            {
                vindoDaEsquerda[j] = -1;
                continue;
            }

            //Se for a da esquerda, então ela só pode ter vindo de cima
            if (j == 0)
            {
                vindoDaEsquerda[j] = vindoDeCima[j];
            }
            //As restantes
            else
            {
                //Se estiver bloqueada pela esquerda e por cima, então está bloqueada
                if (vindoDaEsquerda[j-1] == -1 && vindoDeCima[j] == -1)
                    vindoDaEsquerda[j] = -1;
                //Se não estiver, calcula o maior acúmulo
                else
                    //Como as bloqueadas são -1, o máximo garante que pegará a rota permitida
                    vindoDaEsquerda[j] = std::max(lago[i][j].nroMilho + vindoDaEsquerda[j-1], vindoDeCima[j]);
            }
        }
        //Calcula os acúmulos se viesse da direita
        for (int j = tamX-1; j >= 0; --j)
        {
            //Se a posição estiver bloqueada
            if (lago[i][j].nroMilho == -1)
            {
                vindoDaDireita[j] = -1;
                continue;
            }

            //Se for a da direita, então só pode ter vindo de cima
            if (j == tamX-1)
            {
                vindoDaDireita[j] = vindoDeCima[j];
            }
            //As restantes
            else
            {
                //Se estiver bloqueada pela direita e por cima, então está bloqueada
                if (vindoDaDireita[j+1] == -1 && vindoDeCima[j] == -1)
                    vindoDaDireita[j] = -1;
                //Se não estiver, calcula o maior acúmulo
                else
                    //Como as bloqueadas são -1, o máximo garante que pegará a rota permitida
                    vindoDaDireita[j] = std::max(lago[i][j].nroMilho + vindoDaDireita[j+1], vindoDeCima[j]);
            }
        }
        //Para cada posição da linha
        for (int j = 0; j < tamX; ++j)
        {
            //Se estiver bloqueada
            if (lago[i][j].nroMilho == -1)
            {
                lago[i][j].acumuloMilho = -1;
                continue;
            }

            //Se não estiver, salva o máximo dentre os caclculados
            lago[i][j].acumuloMilho = std::max(vindoDeCima[j], std::max(vindoDaEsquerda[j], vindoDaDireita[j]));
        }
    }

    //Imprime o acúmulo resultante na saída
    std::cout << lago[tamY-1][tamX-1].acumuloMilho << std::endl;

    return 0;
}