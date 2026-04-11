#include <iostream>
#include <vector>
#include <stack>

void dfs_iterativo(int inicio, const std::vector<std::vector<int>>& rotas, std::vector<bool>& visitado) {
    //Pilha dos nós que foram passados
    std::stack<int> pilha;
    pilha.push(inicio);

    //Enquanto ainda não analisou a pilha toda (e, portanto, o grafo todo)
    while (!pilha.empty()) {
        //Pega o nó de origem
        int no = pilha.top();
        //Tira ele da pilha
        pilha.pop();

        //Se o nó ainda não foi visitado
        if (!visitado[no]) {
            //Marca que foi visitado
            visitado[no] = true;

            //Para cada vizinho do nó atual
            for (int vizinho : rotas[no]) {
                //Se ele não foi visitado
                if (!visitado[vizinho]) {
                    //Adiciona ele à pilha
                    pilha.push(vizinho);
                }
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> rotas(n), rotasT(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;

        rotas[a].push_back(b);
        rotasT[b].push_back(a);
    }

    std::vector<bool> visitado(n, false);

    //Faz a análise com a matriz original
    dfs_iterativo(0, rotas, visitado);

    for (bool v : visitado) {
        //Se algum local não foi visitado
        if (!v) 
        {
            //Não é fortemente conexo
            std::cout << "NAO" << std::endl;
            return 0;
        }
    }

    //Reinicia os dados visitados
    fill(visitado.begin(), visitado.end(), false);

    //Repete a análise, mas com o gráfico transposto
    dfs_iterativo(0, rotasT, visitado);

    for (bool v : visitado) {
        //Se algum local não foi visitado
        if (!v) 
        {
            //Não é fortemente conexo
            std::cout << "NAO" << std::endl;
            return 0;
        }
    }

    //Se todos os locais foram visitados ida e volta, então é fortemente conexo
    std::cout << "SIM\n";
    return 0;
}