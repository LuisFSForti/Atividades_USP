#include <iostream>

int main()
{
    int valor;
    std::cin >> valor;

    /*
        N = 1 -> não existem divisores próprios positivos, então o primeiro perde.
        N = 2 -> pode remover 1, deixando N = 1 para o adversário. Logo o primeiro ganha.

        Se N é ímpar, todos os seus divisores próprios também são ímpares.
        Então N <- N - d -> ímpar - ímpar = par
        Ou seja, toda jogada a partir de um número ímpar leva para um número par.

        Se N é par, sempre podemos escolher d = 1 (1 divide qualquer número).
        Então N <- N - 1 -> par - 1 = ímpar

        De um número par existe uma jogada para um número ímpar.
        De um número ímpar todas as jogadas levam para números pares.

        Como N = 1 (ímpar) é a posição perdedora:
        Todos os pares são posições vencedoras.
        Todos os ímpares são posições perdedoras.

        N par   -> primeiro jogador vence
        N ímpar -> segundo jogador vence
    */
    if (valor % 2 == 0)
        std::cout << "Primeiro" << std::endl;
    else
        std::cout << "Segundo" << std::endl;

    return 0;
}