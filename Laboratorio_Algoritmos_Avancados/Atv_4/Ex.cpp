#include <iostream>
#include <algorithm>

int main()
{
    //Crescimento mínimo e crescimento mensal
    int h, crescMes[12];

    //Pega o valor mínimo
    std::cin >> h;

    //Pega o valor de cada mês
    for (int i = 0; i < 12; ++i)
    {
        std::cin >> crescMes[i];
    }

    //Se não tem que crescer, sai antecipadamente
    if (h <= 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    //Ordena do maior pro menor
    std::sort(crescMes, crescMes + 12, std::greater<int>());
    int crescTotal = 0;

    //Para cada mês
    for(int i = 0; i < 12; ++i)
    {
        //Calcula o crescimento total
        crescTotal += crescMes[i];

        //Verifica se atingiu o mínimo
        if (crescTotal >= h)
        {
            //Se sim, imprime o número de meses e sai do loop
            std::cout << i+1 << std::endl;
            break;
        }
    }

    //Se não atingiu o mínimo, imprime que não é possível
    if (crescTotal < h)
        std::cout << "nao cresce" << std::endl;

    return 0;
}