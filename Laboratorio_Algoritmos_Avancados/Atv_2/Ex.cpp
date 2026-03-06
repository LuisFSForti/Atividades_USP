#include <iostream>

int main()
{
    int nroCasos = 0, X = 0, Y = 0;

    std::cin >> nroCasos;
    //Para cada caso
    for (int i = 0; i < nroCasos; ++i)
    {
        //Salva o número de cada moeda
        std::cin >> X;
        std::cin >> Y;

        //Existem 2 condições: X == 0 e X != 0
        //Se X != 0, então se X não for par, a soma é ímpar e indivisível por 2
        //Se X == 0, então Y deve ser par para poder dividir igualamente

        if (X != 0)
        {
            if (X % 2 == 0)
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
        }
        else
        {
            if (Y % 2 == 0)
                std::cout << "YES" << std::endl;
            else
                std::cout << "NO" << std::endl;
        }
    }

    return 0;
}