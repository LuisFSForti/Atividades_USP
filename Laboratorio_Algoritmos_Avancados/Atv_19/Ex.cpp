#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <functional>

const int MODULO = 1000000007;

struct Resultado {
    long long preco;
    int qtdCaminhos;
    int minArestas;
    int maxArestas;
};

Resultado dijkstra(int nroCidades, const std::vector<std::vector<std::pair<int,int>>> &rotas) {
    //Valores encontrados
    std::vector<long long> precos(nroCidades, std::numeric_limits<long long>::max());
    std::vector<int> nroRotas(nroCidades, 0);
    std::vector<int> nroVoosMin(nroCidades, std::numeric_limits<int>::max());
    std::vector<int> nroVoosMax(nroCidades, 0);

    //Lista prioritária -> menor custo primeiro
    std::priority_queue<
        //Fila de tuplas
        std::pair<long long,int>,
        //Armazenada em vetor
        std::vector<std::pair<long long,int>>,
        //Ordenada crescentemente
        std::greater<std::pair<long long,int>>
    > filaPrioridade;

    //Valores se saísse da cidade incial (ou seja, dela pra ela mesma)
    precos[0] = 0;
    nroRotas[0] = 1;
    nroVoosMin[0] = 0;
    nroVoosMax[0] = 0;

    //Inicia com: da cidade inicial pra ela mesma, o peso é o {peso, destino}
    filaPrioridade.push({0, 0});

    //Enquanto a fila não estiver vazia
    while (!filaPrioridade.empty()) {
        //Pega a primeira rota da fila (a mais barata)
        std::pair<long long,int> current = filaPrioridade.top();
        //Tira ela da fila
        filaPrioridade.pop();

        long long preco = current.first;
        int no = current.second;

        //Se o preço da rota for maior que o preço mais barato para o nó já calculado
        if (preco > precos[no]) continue;

        //Para cada rota à partir da cidade de destino
        for (const std::pair<int,int> &edge : rotas[no]) {
            //Pega o nó destino e o preço da rota
            int noDest = edge.first;
            int precoDest = edge.second;

            //Se o preço da rota + o preço acumulado for menor que o preço total calculado previamente
            if (precos[no] + precoDest < precos[noDest]) {
                //Atualiza o preço
                precos[noDest] = precos[no] + precoDest;
                //Atualiza o número de rotas que podem chegar no destino como o número que chega no atual
                nroRotas[noDest] = nroRotas[no];
                //Aumenta o número de voos minímos e máximos para chegar no destino em relação ao número para chegar no atual
                nroVoosMin[noDest] = nroVoosMin[no] + 1;
                nroVoosMax[noDest] = nroVoosMax[no] + 1;
                //Adiciona a rota à fila prioritária
                filaPrioridade.push({precos[noDest], noDest});
            }
            //Se o preço for igual
            else if (precos[no] + precoDest == precos[noDest]) {
                //Define que todas as rotas que chegam no atual chegam no destino pelo mesmo preço
                nroRotas[noDest] = (nroRotas[noDest] + nroRotas[no]) % MODULO;
                //Escolhe o número de voos minímos e máximos dentre o atual e o já calculado para o destino
                nroVoosMin[noDest] = std::min(nroVoosMin[noDest], nroVoosMin[no] + 1);
                nroVoosMax[noDest] = std::max(nroVoosMax[noDest], nroVoosMax[no] + 1);
            }
        }
    }

    //Pega o resultado do nó final, a cidade de destino final
    Resultado res;
    res.preco = precos[nroCidades-1];
    res.qtdCaminhos = nroRotas[nroCidades-1];
    res.minArestas = nroVoosMin[nroCidades-1];
    res.maxArestas = nroVoosMax[nroCidades-1];

    return res;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int,int>>> adj(n, std::vector<std::pair<int,int>>());

    //Lê os dados das rotas
    int a, b, w;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b >> w;
        adj[a-1].push_back({b-1, w});
    }

    //Calcula o resultado
    Resultado res = dijkstra(n, adj);

    //Imprime o resultado
    std::cout << res.preco << " "
              << res.qtdCaminhos << " "
              << res.minArestas << " "
              << res.maxArestas << std::endl;

    return 0;
}