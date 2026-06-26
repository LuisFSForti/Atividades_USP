#include <iostream>
#include <vector>
#include <algorithm>

struct Manutencao
{
    long long inicio;
    long long fim;
    long long prioridade;
};

struct Estado
{
    long long quantidade;
    long long prioridade;
};

bool Melhor(const Estado &a, const Estado &b)
{
    if (a.quantidade != b.quantidade)
        return a.quantidade > b.quantidade;

    return a.prioridade > b.prioridade;
}

int main()
{
    int qtdMaxManutencoes;
    std::cin >> qtdMaxManutencoes;

    std::vector<Manutencao> manutencoes(qtdMaxManutencoes);

    for (int i = 0; i < qtdMaxManutencoes; i++)
    {
        std::cin >> manutencoes[i].inicio
                 >> manutencoes[i].fim
                 >> manutencoes[i].prioridade;
    }

    std::sort(manutencoes.begin(), manutencoes.end(),
        [](const Manutencao &a, const Manutencao &b)
        {
            if (a.fim != b.fim)
                return a.fim < b.fim;

            return a.inicio < b.inicio;
        }
    );

    std::vector<long long> fins(qtdMaxManutencoes);

    for (int i = 0; i < qtdMaxManutencoes; i++)
        fins[i] = manutencoes[i].fim;

    std::vector<Estado> dp(qtdMaxManutencoes + 1);
    dp[0] = {0, 0};

    for (int i = 1; i <= qtdMaxManutencoes; i++)
    {
        //Quantas manutenções tem fim <= à manutenção analisada na iteração
        //Ou seja, quantas manutenções podem ter sido feitas antes da manutenção atual começar
        int indice =
            std::upper_bound(fins.begin(), fins.end(), manutencoes[i - 1].inicio)
            - fins.begin();

        //Se fizer a manutenção atual
        //dp[indice] representa o estado calculado anteriormente de máxima com a quantidade de manutenções de indice
        Estado escolher;
        //Define que a quantidade vai aumentar em 1
        escolher.quantidade = dp[indice].quantidade + 1;
        //Define a prioridade atual calculada
        escolher.prioridade = dp[indice].prioridade + manutencoes[i - 1].prioridade;

        //Se não fizer a manutenção atual
        Estado naoEscolher = dp[i - 1];

        //Define qual é a melhor opção
        if (Melhor(escolher, naoEscolher))
            dp[i] = escolher;
        else
            dp[i] = naoEscolher;
    }

    std::cout << dp[qtdMaxManutencoes].quantidade << " " << dp[qtdMaxManutencoes].prioridade << '\n';

    return 0;
}