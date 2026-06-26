#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int BuscaEmLargura(std::vector<std::vector<int>>& residual, int origem, int destino, std::vector<int>& parent) {
    int qtdCentros = residual.size();
    //Marca que nenhum centro possui parente ainda
    std::fill(parent.begin(), parent.end(), -1);

    //Fila da rota atual e sua capacidade máxima
    std::queue<std::pair<int,int>> q;
    //Adiciona a origem com capacidade máxima (infinita)
    q.push({origem, INT_MAX});
    //Valor especial para marcar que não existe nó prévio à origem
    parent[origem] = -2;

    //Enquanto ainda puder analisar uma rota
    while (!q.empty()) {
        //Pega o nó do topo da fila e sua capacidade
        int atual = q.front().first;
        int flow = q.front().second;
        //Remove da fila
        q.pop();

        //Verifica todas as rotas possíveis saindo do atual
        for (int v = 0; v < qtdCentros; v++) {
            //Se o próximo não tiver parente (já não foi analisado) e ainda tiver capacidade
            if (parent[v] == -1 && residual[atual][v] > 0) {
                //Marca a rota possível
                parent[v] = atual;
                //Deinfe qual a capacidade da rota, escolhendo a menor
                int newFlow = std::min(flow, residual[atual][v]);

                //Se é o destino, tem-se uma rota
                if (v == destino)
                    //Retorna que encontrou uma rota
                    return newFlow;

                //Se não fechou a rota, adiciona o nó atual à fila e avalia o próximo
                q.push({v, newFlow});
            }
        }
    }

    return 0;
}

int FluxoMax(std::vector<std::vector<int>>& capacidades, int origem, int destino) {
    int qtdCentros = capacidades.size();
    //Capacidades restantes
    std::vector<std::vector<int>> residual = capacidades;
    //Rota atual
    std::vector<int> parent(qtdCentros);

    //Fluxo máximo da rota atual e fluxo total calculado
    int newFlow, flow = 0;

    //Enquanto newFlow != 0
    while ((newFlow = BuscaEmLargura(residual, origem, destino, parent))) {
        flow += newFlow;

        int cur = destino;
        //Volta de 1 em 1 nos parentes até retornar à origem
        while (cur != origem) {
            int prev = parent[cur];
            residual[prev][cur] -= newFlow;
            residual[cur][prev] += newFlow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    int qtdCentros, qtdRotas, origem, destino;
    std::cin >> qtdCentros >> qtdRotas >> origem >> destino;

    //A entrada de dados começa em 1, mas as análises começam em 0
    origem--;
    destino--;

    std::vector<std::vector<int>> capacidades(qtdCentros, std::vector<int>(qtdCentros, 0));

    for (int i = 0; i < qtdRotas; i++) {
        int origAtual, destAtual, capacidade;
        std::cin >> origAtual >> destAtual >> capacidade;

        //A entrada de dados começa em 1, mas as análises começam em 0
        origAtual--;
        destAtual--;

        capacidades[origAtual][destAtual] += capacidade;
    }

    std::cout << FluxoMax(capacidades, origem, destino) << std::endl;

    return 0;
}