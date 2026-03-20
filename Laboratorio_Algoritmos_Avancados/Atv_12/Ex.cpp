#include <iostream>
#include <vector>

struct LabAux
{
    char caractere;
    int nroRotasPossiveis;
};

int main()
{
    int tam;
    std::cin >> tam;

    //Pega a formatação do lago
    std::vector<std::vector<LabAux>> labirinto(tam);
    for (int i = 0; i < tam; ++i)
    {
        labirinto[i] = std::vector<LabAux>(tam);
        for (int j = 0; j < tam; ++j)
        {
            std::cin >> labirinto[i][j].caractere;
            labirinto[i][j].nroRotasPossiveis = 0;
        }
    }

    //Se a entrada ou a saída estiverem bloqueadas
    if (labirinto[0][0].caractere == '*' || labirinto[tam-1][tam-1].caractere == '*')
    {
        //Retorna que não há caminhos e encerra
        std::cout << "0" << std::endl;
        return 0;
    }

    //Se há caminhos possíveis
    //Então marca que há 1 rota possível para a entrada
    labirinto[0][0].nroRotasPossiveis = 1;

    //Na primeira linha, só pode vir da esquerda
    //Como o (0,0) já foi tratado, pode pular o j=0
    for (int j = 1; j < tam; ++j)
    {
        //Se for um obstáculo, então não há rotas possíveis até ele
        if (labirinto[0][j].caractere == '*')
            continue;
        
        //Todos serão igual ao da esquerda (0 ou 1)
        labirinto[0][j].nroRotasPossiveis = labirinto[0][j-1].nroRotasPossiveis;
    }

    //Na primeira coluna, só pode vir de cima
    //Como o (0,0) já foi tratado, pode pular o i=0
    for (int i = 1; i < tam; ++i)
    {
        //Se for um obstáculo, então não há rotas possíveis até ele
        if (labirinto[i][0].caractere == '*')
            continue;
        
        //Todos serão igual ao de cima (0 ou 1)
        labirinto[i][0].nroRotasPossiveis = labirinto[i-1][0].nroRotasPossiveis;
    }

    //Para todas as outras posições possíveis
    for (int i = 1; i < tam; ++i)
    {
        for (int j = 1; j < tam; ++j)
        {
            //Se for um obstáculo, então não há rotas possíveis até ele
            if (labirinto[i][j].caractere == '*')
                continue;

            //Soma o número de rotas possíveis acima e à esquerda
            //Desta forma esse número incrementa a cada passo
            labirinto[i][j].nroRotasPossiveis = labirinto[i-1][j].nroRotasPossiveis + labirinto[i][j-1].nroRotasPossiveis;
            //Modulação pedida pelo professor
            labirinto[i][j].nroRotasPossiveis %= 1000000007;
        }
    }

    //Imprime o total calculado na saída
    std::cout << labirinto[tam-1][tam-1].nroRotasPossiveis << std::endl;

    return 0;
}