#include <iostream>
#include <vector>

struct LabAux
{
    long long nroPastilhas, acumuloPastilhas;
};

int main()
{
    int tamX, tamY;
    std::cin >> tamY >> tamX;

    //Pega os dados do labirinto
    std::vector<std::vector<LabAux>> labirinto (tamY);
    for (int i = 0; i < tamY; ++i)
    {
        labirinto[i] = std::vector<LabAux>(tamX);
        for (int j = 0; j < tamX; ++j)
        {
            std::cin >> labirinto[i][j].nroPastilhas;
            labirinto[i][j].acumuloPastilhas = 0;
        }
    }

    //Se a entrada ou a saída estiverem bloqueadas
    if (labirinto[0][0].nroPastilhas == -1 || labirinto[tamY-1][tamX-1].nroPastilhas == -1)
    {
        //Retorna que não há caminhos e encerra
        std::cout << "-1" << std::endl;
        return 0;
    }

    //Se há caminhos possíveis
    //Então marca que a entrada terá acúmulo igual ao seu valor
    labirinto[0][0].acumuloPastilhas = labirinto[0][0].nroPastilhas;

    //Na primeira linha, só pode vir da esquerda
    //Como o (0,0) já foi tratado, pode pular o j=0
    for (int j = 1; j < tamX; ++j)
    {
        //Se for um fantasma, então não há rotas possíveis até ele
        if (labirinto[0][j].nroPastilhas == -1)
        {
            labirinto[0][j].acumuloPastilhas = -1;
            continue;
        }
        
        //Se estiver bloqueada à esquerda, então esta posição está bloqueada
        if (labirinto[0][j-1].nroPastilhas == -1)
        {
            //Marca como bloqueada
            labirinto[0][j].nroPastilhas = -1;
            labirinto[0][j].acumuloPastilhas = -1;
        }
        //Se não estiver bloqueada
        else
        {
            //Adiciona ao acúmulo da linha
            labirinto[0][j].acumuloPastilhas = labirinto[0][j].nroPastilhas + labirinto[0][j-1].acumuloPastilhas;
        }
    }

    //Na primeira coluna, só pode vir de cima
    //Como o (0,0) já foi tratado, pode pular o i=0
    for (int i = 1; i < tamY; ++i)
    {
        //Se for um fantasma, então não há rotas possíveis até ele
        if (labirinto[i][0].nroPastilhas == -1)
        {
            labirinto[i][0].acumuloPastilhas = -1;
            continue;
        }
        
        //Se estiver bloqueada acima, então esta posição está bloqueada
        if (labirinto[i-1][0].nroPastilhas == -1)
        {
            //Marca que está bloqueada
            labirinto[i][0].nroPastilhas = -1;
            labirinto[i][0].acumuloPastilhas = -1;
        }
        //Se não estiver bloqueada
        else
        {
            //Adiciona ao acúmulo da linha
            labirinto[i][0].acumuloPastilhas = labirinto[i][0].nroPastilhas + labirinto[i-1][0].acumuloPastilhas;
        }
    }

    //Para todas as outras posições possíveis
    for (int i = 1; i < tamY; ++i)
    {
        for (int j = 1; j < tamX; ++j)
        {
            //Se for um fantasma, então não há rotas possíveis até ele
            if (labirinto[i][j].nroPastilhas == -1)
            {
                labirinto[i][j].acumuloPastilhas = -1;
                continue;
            }

            //Se acima e à esquerda estiverem bloqueadas, então esta posição também está bloqueada
            if (labirinto[i-1][j].nroPastilhas == -1 && labirinto[i][j-1].nroPastilhas == -1)
            {
                //Marca como bloqueada
                labirinto[i][j].nroPastilhas = -1;
                labirinto[i][j].acumuloPastilhas = -1;
            }
            //Se não estiver bloqueada
            else
            {
                //Verifica qual rota tem um acúmulo maior e adiciona seu próprio valor
                labirinto[i][j].acumuloPastilhas = labirinto[i][j].nroPastilhas + 
                                                std::max(labirinto[i-1][j].acumuloPastilhas, labirinto[i][j-1].acumuloPastilhas);
            }
        }
    }

    //Imprime o acúmulo resultante na saída
    std::cout << labirinto[tamY-1][tamX-1].acumuloPastilhas << std::endl;

    return 0;
}