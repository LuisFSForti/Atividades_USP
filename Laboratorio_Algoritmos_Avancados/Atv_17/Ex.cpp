#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007;

//Globais para economizar memória na recursão
int N, M;
std::vector<int> blusa_para_pessoas[101];
long long memo[101][1 << 15];

//Função recursiva para calcular as combinações
long long CalcularCombinacoes(int blusa_id, int mask) {
    //Se todas as pessoas tiverem uma blusa, então mask == todos os bits 1
    if (mask == (1 << N) - 1) {
        //Retorna que foi encontrada uma combinação
        return 1;
    }
    
    //Se acabaram as roupas e alguem ainda não estiver vestido
    if (blusa_id > 100) {
        //Retorna que é uma combinação inválida/incompleta
        return 0;
    }

    //Se estiver numa situação com os mesmos convidados vestidos e a roupa atual
    //Então todas as combinações à partir deste ponto já foram calculadas
    if (memo[blusa_id][mask] != -1) {
        //Retorna o valor calculado
        return memo[blusa_id][mask];
    }

    //Passa a próxima roupa
    //Esta função por si só não faz nada, mas ela avança pelas roupas que nenhum convidado tem
    long long res = CalcularCombinacoes(blusa_id + 1, mask) % MOD;

    //Para toda pessoa que pode usar a roupa atual
    //Aqui que a chamada acima é importante, pois a anterior avança pelas que não se enquadram aqui
    for (int pessoa : blusa_para_pessoas[blusa_id]) {
        //Se a pessoa não estiver já vestida
        if (!(mask & (1 << pessoa))) {
            //Passa a próxima roupa e marca que a pessoa atual está vestida
            res = (res + CalcularCombinacoes(blusa_id + 1, mask | (1 << pessoa))) % MOD;
        }
    }

    //Salva o número de combinações calculado para os atuais convidados vestidos
    //e partindo da roupa atual
    return memo[blusa_id][mask] = res;
}

int main() {
    //Pega o número de convidados e tamanho da coleção de outono
    std::cin >> N >> M;

    //Pega as coleções de cada pessoa
    for (int i = 0; i < N; ++i) {
        //Número de roupas
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int id_blusa;
            std::cin >> id_blusa;
            //Adiciona que o convidado i tem a roupa id_blusa
            blusa_para_pessoas[id_blusa].push_back(i);
        }
    }

    //Preenche a tabela memo inteira com -1 (inteiramente bits 1)
    memset(memo, -1, sizeof(memo));

    //Inicia com a primeira roupa, com todos os convidados sem blusas
    std::cout << CalcularCombinacoes(1, 0) << std::endl;

    return 0;
}