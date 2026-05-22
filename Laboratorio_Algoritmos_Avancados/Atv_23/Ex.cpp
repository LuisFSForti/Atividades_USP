#include <iostream>
#include <vector>

#define MARGEM_FLOAT 0.00001

struct Posicao
{
    int x, y;
};

bool ValidarPosicao(std::vector<Posicao> &posicoesAteAgora, Posicao novaPosicao)
{
    for (Posicao posicaoAtual : posicoesAteAgora)
    {
        //Na mesma coluna
        if (posicaoAtual.x == novaPosicao.x)
        {
            return false;
        }
        //Na mesma linha
        if (posicaoAtual.y == novaPosicao.y)
        {
            return false;
        }
        //Se coeficienteAngular == 1, então eles estão na mesma diagonal
        float coeficienteAngular = std::abs((float)(posicaoAtual.y - novaPosicao.y)/(float)(posicaoAtual.x - novaPosicao.x));
        if (1.0 - MARGEM_FLOAT <= coeficienteAngular && coeficienteAngular <= 1.0 + MARGEM_FLOAT)
        {
            return false;
        }
    }
    return true;
}

void RainhasRecursivo(std::vector<Posicao> &posicoesAteAgora, std::vector<Posicao> &primeiraSolucao, int &contagem, int N, int yAtual)
{
    //Casos impossíveis
    if (N == 2 || N == 3)
        return;

    //Se saiu do tabuleiro, então completou o desafio
    if (yAtual == N)
    {
        if (contagem == 0)
        {
            primeiraSolucao = std::vector<Posicao>(posicoesAteAgora);
        }
        contagem++;
        return;
    }

    //Para todas as colunas da linha
    for (int i = 0; i < N; ++i)
    {
        Posicao novaPosicao = Posicao { i, yAtual };

        //Se for válida
        if (ValidarPosicao(posicoesAteAgora, novaPosicao))
        {
            //Adiciona ao caminho atual
            posicoesAteAgora.push_back(novaPosicao);
            //Avança pra próxima linha
            RainhasRecursivo(posicoesAteAgora, primeiraSolucao, contagem, N, yAtual+1);
            //Independentemente se concluiu com sucesso ou não, remove da pilha para testar a próxima posição
            posicoesAteAgora.erase(posicoesAteAgora.end());
        }
    }
}

int main()
{
    while (true)
    {
        int N;
        std::cin >> N;

        //Encerra o código no tabuleiro de tamanho N == 0
        if (N == 0)
            break;

        std::vector<Posicao> caminho, primeiraSolucao;
        int contagem = 0;

        RainhasRecursivo(caminho, primeiraSolucao, contagem, N, 0);

        std::cout << "[" << N << "," << contagem << "]" << std::endl;
        if (contagem > 0)
        {
            for (Posicao posicaoAtual : primeiraSolucao)
            {
                std::cout << (posicaoAtual.x+1) << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "sem solucao" << std::endl;
        }
    }
}