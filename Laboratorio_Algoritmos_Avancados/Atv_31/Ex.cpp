#include <iostream>

int main()
{
    int qtdPedras;
    
    std::cin >> qtdPedras;

    /*
        Analisando para qtdPedras <= 4:
        == 1 -> primeiro jogador retira 1 pedra e ganha
        == 2 -> primeiro jogador retira 2 pedras e ganha
        == 3 -> primeiro jogador retira 3 pedras e ganha
        == 4 -> primeiro jogador retira qualquer número de pedras e o segundo retira o restante pra ganhar

        Ou seja:
        1 == primeiro
        2 == primeiro
        3 == primeiro
        4 == segundo

        Para qtdPedras > 4, a análise se mantém:
        5 pedras == 4 + 1 -> primeiro jogador retira 1 e o segundo fica com 4, garantindo a vitória
        19 pedras == 4*4 + 3 -> primeiro jogador retira 3 e o segundo fica com múltiplo de 4, garantindo a vitória

        Ou seja:
        se qtdPedras for múltiplo de 4, o segundo ganha
        senão, o primeiro ganha
    */

    if (qtdPedras % 4 == 0)
        std::cout << "Segundo" << std::endl;
    else
        std::cout << "Primeiro" << std::endl;

    return 0;
}