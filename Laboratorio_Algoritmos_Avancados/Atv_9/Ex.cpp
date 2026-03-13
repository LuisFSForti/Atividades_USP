#include <iostream>
#include <vector>

int main()
{
    int nroGomos;

    std::cin >> nroGomos;

    //Para facilitar, adiciona 1 posição no começo dos vetores,
    //que representa uma partição com 0 gomos
    //dp salva o valor de cada possível número de gomos
    std::vector<int> valoresGomos(nroGomos+1, 0), dp(nroGomos+1, 0);

    //Salva o valor de cada partição pelo número de gomos
    //Começa no i = 1 pois uma partição com 0 gomos vale 0
    for (int i = 1; i < nroGomos; ++i)
        std::cin >> valoresGomos[i];

    //Para cada possível combinação de gomos
    for(int i = 1; i <= nroGomos; ++i)
    {
        //Para cada possível combinação com número menor de gomos
        for(int j = 1; j <= i; ++j)
        {
            //Compara qual é maior:
            //O valor atual, definido em outra iteração
            //O valor da partição atual + o valor da partição restante
            dp[i] = std::max(dp[i], valoresGomos[j] + dp[i-j]);
        }
    }

    std::cout << dp[nroGomos] << std::endl;

    return 0;
}