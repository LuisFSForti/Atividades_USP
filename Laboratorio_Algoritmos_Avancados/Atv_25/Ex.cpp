#include <iostream>

int main()
{
    int qtdValores, qtd3, qtd5, qtd15;

    std::cin >> qtdValores;

    qtd3 = qtdValores/3;
    qtd5 = qtdValores/5;
    qtd15 = qtdValores/15;

    std::cout << qtd3 << " " << qtd5 << " " << qtd15 << std::endl;
}