#include <iostream>

int main()
{
    int nroPilhas, pilha;
    std::cin >> nroPilhas;

    /*
        Considere o XOR de todas as pilhas:
        xorTotal = a1 ^ a2 ^ ... ^ an

        Por exemplo:
        (1, 1) -> xor = 0 -> segundo jogador vence
        (2, 2) -> xor = 0 -> segundo jogador vence
        (1, 2) -> xor = 3 -> primeiro jogador vence
        (1, 1, 1) -> xor = 1 -> primeiro jogador vence

        Se xorTotal == 0, qualquer jogada fará o XOR ficar diferente de 0, garantindo a vitória do segundo
        Se xorTotal != 0, sempre existe uma jogada que transforma o XOR em 0, garantindo a vitória do primeiro
    */

    int res = 0;
    for (int i = 0; i < nroPilhas; ++i)
    {
        std::cin >> pilha;
        res ^= pilha;
    }

    if (res != 0)
        std::cout << "Primeiro" << std::endl;
    else
        std::cout << "Segundo" << std::endl;

    return 0;
}