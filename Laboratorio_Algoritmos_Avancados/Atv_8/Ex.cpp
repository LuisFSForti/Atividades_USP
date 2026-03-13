#include <iostream>
#include <vector>

#define INT_GRANDE 1000000000

int main()
{
    int nroCasos, valor, nroMoedas;

    std::cin >> nroCasos;

    //Para cada caso teste
    for (int i = 0; i < nroCasos; ++i)
    {
        std::cin >> valor;
        std::cin >> nroMoedas;

        //Salva os valores das moedas
        std::vector<int> moedas(nroMoedas);
        for (int j = 0; j < nroMoedas; ++j)
        {
            std::cin >> moedas[j];
        }

        //Para a programação dinâmica, serão armazenados os 
        //trocos possíveis para todos os valores até o objetivo
        //valor+1 para considerar o troco 0
        //Salva todas as opções como um número grande, para ser substituído
        std::vector<int> trocosPossiveis(valor+1, INT_GRANDE);
        //Troco 0 = 0 moedas
        trocosPossiveis[0] = 0;

        //Para cada valor
        for (int j = 1; j < valor+1; ++j)
        {
            //Para cada moeda
            for (int k = 0; k < nroMoedas; ++k)
            {
                //Se a moeda for troco exato
                if (moedas[k] == j)
                {
                    //Salva que requer apenas 1 moeda
                    trocosPossiveis[j] = 1;
                }
                //Se a moeda for menor que o valor (se ela pode ser usada como troco)
                else if (moedas[k] < j)
                {
                    //Verifica qual o menor número de moedas:
                    //O número atual, definido em outra iteração
                    //O número de moedas que foi usado para valor-moeda, +1 para considerar a adição da moeda atual
                    //Desta forma, prevalece a combinação com menor número
                    trocosPossiveis[j] = std::min(trocosPossiveis[j], trocosPossiveis[j - moedas[k]] + 1);
                }
            }
        }

        std::cout << trocosPossiveis[valor] << std::endl;
    }

    return 0;
}