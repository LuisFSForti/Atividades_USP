#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Conexoes
{
    //nosParentes = i para todo i inicialmente
    //alturaNo = 0 para todo i inicialmente
    //Ou seja, todo nó é parente dele mesmo e numa árvore de altura 0
    //Sempre que criar uma conexão, um nó vai se tornar parente do outro
    //Como múltiplos nós podem ter o mesmo parente, a árvore só cresce de altura se
    //unir duas árvores de mesmo tamanho
    //Ex: 1-2 com 3 (parente 1) só bifurcará 1-2 e 1-3, sem crescer
    //Mas 1-2 com 3-4 (parente 1) terá a bifurcação 1-2 e 1-3-4, fazendo a raiz 1 subir na altura
    //Se fosse 1-2 com 3-4-5 (parente 1), irá mudar a ordem e 3 será raiz, fazendo a bifurcação 3-4-5 e 3-1-2, mantendo a altura
    //Essa última manipulação pode acontecer porque as conexões são bidirecionais
    std::vector<int> nosParentes, alturaNo;

    Conexoes(int n)
    {
        nosParentes.resize(n);
        alturaNo.assign(n, 0);

        for (int i = 0; i < n; i++)
            nosParentes[i] = i;
    }

    //Procura a raiz da árvore com o nó x
    int EncontrarRaiz(int x)
    {
        //Se x é parente dele mesmo, então é a raiz
        if (nosParentes[x] == x)
            return x;

        //Se não for a raiz, procura a raiz do parente do atual
        return nosParentes[x] = EncontrarRaiz(nosParentes[x]);
    }

    //Para criar uma nova conexão
    bool CriarConexao(int a, int b)
    {
        //Pega as raízes de cada nó
        a = EncontrarRaiz(a);
        b = EncontrarRaiz(b);

        //Se ambos têm a mesma raíz, eles já estão indiretamente conectados
        if (a == b)
            //Retorna que não criou a conexão
            return false;

        //Deixa em 'a' a árvore mais alta
        if (alturaNo[a] < alturaNo[b])
            std::swap(a, b);

        nosParentes[b] = a;

        //Se as árvores tinham a mesma altura, então a raiz a aumentou de altura
        if (alturaNo[a] == alturaNo[b])
            alturaNo[a]++;

        return true;
    }
};

//Para ordenar as conexões por custo
struct Aresta
{
    int no1, no2;
    double dist;

    //Necessário para o std::sort
    bool operator<(const Aresta& other) const {
        return dist < other.dist;
    }
};

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int,int>> coordenadas(N);

    //Pega as coordenadas de todos os nós
    for (int i = 0; i < N; i++)
        std::cin >> coordenadas[i].first >> coordenadas[i].second;

    Conexoes conexoes(N);

    int M;
    std::cin >> M;

    //Pega as conexões pré-existentes
    for (int i = 0; i < M; i++)
    {
        int no1, no2;
        std::cin >> no1 >> no2;
        //-1 para começar em 0
        conexoes.CriarConexao(no1-1, no2-1);
    }

    std::vector<Aresta> distancias;

    //Saindo de todo nó
    for (int i = 0; i < N; i++)
    {
        //Chegando em todo nó depois dele
        //Não analisa os que vieram antes dele porque as conexões são bidirecionais,
        //então os que vieram antes dele foram analisados no i previamente
        for (int j = i + 1; j < N; j++)
        {
            //Calcula a distância entre eles e salva
            double dx = coordenadas[i].first - coordenadas[j].first;
            double dy = coordenadas[i].second - coordenadas[j].second;

            double dist = std::sqrt(dx * dx + dy * dy);

            distancias.push_back({i, j, dist});
        }
    }

    //Ordena as distâncias calculadas pepla ordem crescente de distância
    std::sort(distancias.begin(), distancias.end());

    double custoTotal = 0.0;

    //Para toda distância
    for (auto &dist : distancias) {
        //Tenta criar uma conexão entre eles
        //Se eles já forem conectados, direto ou indiretamente, então a conexão não é salva, pois não foi criada
        if (conexoes.CriarConexao(dist.no1, dist.no2)) {
            //Se foi criada, salva seu custo
            custoTotal += dist.dist;
        }
    }

    std::cout << std::fixed << std::setprecision(3) << custoTotal << std::endl;

    return 0;
}