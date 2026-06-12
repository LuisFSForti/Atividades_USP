#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//Intervalos de cobertura de cada sprinkler
struct Intervalo
{
    double ini, fim;
};

int main()
{
    int N;
    float L, W;

    std::cin >> N >> L >> W;

    std::vector<Intervalo> intervalos;

    //Lê todos os sprinklers
    for (int i = 0; i < N; i++)
    {
        double x, r;
        std::cin >> x >> r;

        //Se o alcance dele é menor que a largura do jardim,
        //então ele é inútil
        if (2.0 * r <= W)
            continue;

        //----------------------- topo do jardim --------------
        //
        //
        //|----------d---------------|x|---------------d----------|
        //d é a distância que o sprinkler consegue cobrir toda a largura do jardim
        //Ou seja, é o ponto em X onde a hipotenusa entre ele e o topo do jardim é igual ao raio do sprinkler
        //r^2 = d^2 + (w/2)^2
        //d = sqrt(r^2 - (w/2)^2)
        double d = sqrt(r * r - (W / 2.0) * (W / 2.0));
        //Salva o intervalo que o sprinkler cobre
        intervalos.push_back({x - d, x + d});
    }

    //Ordena os sprinklers por ordem de quão longe alcança à esquerda, de forma crescente
    std::sort(intervalos.begin(), intervalos.end(),
              [](const Intervalo& a, const Intervalo& b)
              {
                  return a.ini < b.ini;
              });

    //Quanto do comprimento do jardim foi coberto
    double coberto = 0.0;
    int usados = 0;
    //Sprinkler atual
    int i = 0;
    //Quantos sprinklers
    int M = intervalos.size();

    //Enquanto não cobriu o jardim
    while (coberto < L)
    {
        //Quanto já foi coberto, da esquerda para a direita
        double melhor = coberto;

        //Enquanto o sprinkler estiver sobrepondo a área já coberta
        while (i < M && intervalos[i].ini <= coberto)
        {
            //Escolhe qual alcança mais à direita
            melhor = std::max(melhor, intervalos[i].fim);
            i++;
        }

        //Se não encontrou nenhum que alcançe mais à direita
        if (melhor == coberto)
        {
            //Retorna que não é possível cobrir o jardim com os
            //sprinklers fornecidos
            std::cout << -1 << '\n';
            return 0;
        }

        //Atualiza quanto já foi coberto
        coberto = melhor;
        //Salva que usou outro sprinkler
        usados++;
    }

    //Retorna quantos sprinklers serão necessários
    std::cout << usados << '\n';

    return 0;
}