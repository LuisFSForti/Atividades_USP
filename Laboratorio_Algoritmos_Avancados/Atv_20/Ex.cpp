#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

#define N_MAX 2001

//Visita grafo original, acumulando do mais profundo pro mais raso
void dfs1(int u, std::vector<int> grafo[], bool visitados[], std::stack<int>& ordem) {
    //Marca que o nó atual foi visitado
    visitados[u] = true;
    //Para todos os que ele confia
    for (int v : grafo[u]) {
        //Se já não foi visitado
        if (!visitados[v])
            //Chama recursivamente
            dfs1(v, grafo, visitados, ordem);
    }
    //Depoi de adicionar todas as rotas, adiciona ele à ordem
    ordem.push(u);
}

//Encontra uma componente fortemente conexa
void dfs2(int u, std::vector<int> grafoT[], bool visitados[], std::vector<int>& componenteConexoAtual) {
    //Marca que o nó foi visitado
    visitados[u] = true;
    //Adiciona o nó ao componente atual
    componenteConexoAtual.push_back(u);
    //Para todos que ele confia
    for (int v : grafoT[u]) {
        //Se já não foi visitado
        if (!visitados[v])
            //Chama recursivamente
            dfs2(v, grafoT, visitados, componenteConexoAtual);
    }
}

int main() {
    int N, M;
    bool visitados[N_MAX];
    std::stack<int> ordem;
    std::vector<int> componenteConexoAtual;
    std::vector<int> grafo[N_MAX], grafoT[N_MAX];

    //Lê o número de usuários e a quantidade de casos testes
    while (std::cin >> N >> M) {
        //Se forem 00, encerra o loop
        if (N == 0 && M == 0) break;

        //Limpa as listas
        for (int i = 1; i <= N; i++) {
            grafo[i].clear();
            grafoT[i].clear();
            visitados[i] = false;
        }
        while (!ordem.empty()) 
            ordem.pop();

        //Lê as conexões
        for (int i = 0; i < M; i++) {
            int u, v, r;
            std::cin >> u >> v >> r;

            grafo[u].push_back(v);
            grafoT[v].push_back(u);

            //Se for confiança mútua
            if (r == 2) {
                grafo[v].push_back(u);
                grafoT[u].push_back(v);
            }
        }

        //Faz a análise por profundidade
        for (int i = 1; i <= N; i++) {
            if (!visitados[i])
                dfs1(i, grafo, visitados, ordem);
        }

        //Limpa a lista dos visitados
        std::memset(visitados, false, sizeof(visitados));

        //Lista dos componentes encontrados
        std::vector<std::vector<int>> componentesConexos;

        //Análise dos componentes conexos
        while (!ordem.empty()) {
            //Pega o nó no topo (o mais profundo)
            int u = ordem.top();
            //Tira ele da pilha
            ordem.pop();

            //Se o nó não foi visitado
            if (!visitados[u]) {
                //Limpa o último componente analisado
                componenteConexoAtual.clear();
                //Faz a análise de conexão usando o grafo transposto
                dfs2(u, grafoT, visitados, componenteConexoAtual);
                //Adiciona o componente atual à lista de componentes encontrados
                componentesConexos.push_back(componenteConexoAtual);
            }
        }

        //Se só tiver um componente, então o grafo é fortemente conexo
        if ((int)componentesConexos.size() == 1) {
            std::cout << "confianca total\n";
            continue;
        }

        //Se tiver mais de um componente

        //Ordena os nós dos componentes pelo indíce
        for (auto &c : componentesConexos) {
            std::sort(c.begin(), c.end());
        }

        //Ordena os componentes pelo menor nó
        std::sort(componentesConexos.begin(), componentesConexos.end(),
            [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[0] < b[0];
            });

        //Imprime o resultado
        for (int i = 0; i < (int)componentesConexos.size(); i++) {
            std::cout << "[" << i + 1 << "," << componentesConexos[i].size() << "]";
        }
        std::cout << "\n";
    }

    return 0;
}