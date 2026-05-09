#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1000000007LL;

struct Fenwick
{
    //A árvore de Fenwick é uma estrutura que permite calcular somas de prefixos em O(log n).

    //Ela armazena somas parciais em seus nós, onde cada nó representa um intervalo do vetor.
    //Alguns nós guardam apenas um valor, enquanto outros guardam a soma de conjuntos maiores.

    //Quando um valor é atualizado, todos os intervalos que contêm esse valor também são atualizados.
    //Assim, as consultas futuras podem reutilizar essas somas já prontas, evitando recalcular tudo.

    //Exemplo:
    //idx 4 guarda a soma do intervalo [1, 2, 3, 4]
    //Então, ao calcular uma soma maior, podemos reutilizar diretamente esse conjunto.

    //Cada nó i representa um intervalo que termina em i e tem tamanho
    //(i & -i)
    //Esta operação encontra o menor bit ligado do índice,
    //o que faz com que os tamanhos dos blocos sejam potências de 2.

    //Exemplo:
    //idx 12 = 1100
    //12 & -12 = 0100 = 4
    //Então o nó 12 guarda um intervalo de tamanho 4.

    //Como os blocos possuem tamanhos em potências de 2, qualquer prefixo pode ser dividido em poucos blocos,
    //permitindo consultas e atualizações em O(log n).
    std::vector<long long> valores;
    int n;

    Fenwick(int tamanho)
    {
        n = tamanho;
        //Poderia fazer uma árvore que começasse no idx 0, mas as operações bit-wise ficam menos intuitivas
        valores.assign(n + 1, 0);
    }

    //Adiciona ao valor de um prefixo e dos seus dependentes
    void Adicionar(int idx, long long val)
    {
        //Enquanto estiver dentro dos limites da árvore
        while (idx <= n)
        {
            //Atualiza o valor no prefixo atual
            valores[idx] = (valores[idx] + val) % MOD;
            //Calcula o idx do próximo nó dependente
            idx += idx & -idx;
        }
    }

    //Calcula a soma do prefixo e de todos os seus anteriores
    long long Somar(int idx)
    {
        long long soma = 0;

        while (idx > 0)
        {
            soma = (soma + valores[idx]) % MOD;
            //Como todo bloco tem tamanho (idx & -idx), diminuir esse valor leva ao próximo prefixo que já não está sendo considerado
            idx -= idx & -idx;
        }

        return soma;
    }
};

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> a(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }

    //Copia os valores e os ordena
    std::vector<int> valores = a;
    std::sort(valores.begin(), valores.end());

    //Remove todos os valores repetidos
    valores.erase(
        std::unique(valores.begin(), valores.end()),
        valores.end()
    );

    //Troca os valores de a[i] pelos seus prefixos, necessário para a árvore de Fenwick
    //Então [100 50 100 20] vira [3 2 3 1]
    for (int i = 0; i < N; i++)
    {
        a[i] = std::lower_bound(
            valores.begin(),
            valores.end(),
            a[i]
        ) - valores.begin() + 1;
    }

    Fenwick arvore((int)valores.size());

    long long resposta = 0;

    //Para todo valor passado
    for (int i = 0; i < N; i++)
    {
        //O total de combinações possíveis terminadas em a[i] é igual a 1 + somatório(combinacoes(a[j])), com j < i e a[j] < a[i]
        //Como a árvore está somando apenas os valores menores que o passado, ela faz o somatório
        //Então basta somar 1
        long long combinacoesAtuais = (1 + arvore.Somar(a[i] - 1)) % MOD;

        //Aumenta o número de combinações possíveis do prefixo
        arvore.Adicionar(a[i], combinacoesAtuais);

        resposta = (resposta + combinacoesAtuais) % MOD;
    }

    std::cout << resposta << std::endl;

    return 0;
}