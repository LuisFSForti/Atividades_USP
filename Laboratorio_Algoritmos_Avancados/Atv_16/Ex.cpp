#include <iostream>
#include <vector>

int main()
{
    int nroBaloes;
    std::cin >> nroBaloes;

    std::vector<int> baloes(nroBaloes+2, 1);
    for (int i = 1; i < nroBaloes+1; ++i)
        std::cin >> baloes[i];

    //Linhas e colunas extras facilitam para calcular o total futuramente,
    //pois tira a necessidade de ifs para verificar se há valores à esquerda ou abaixo
    std::vector<std::vector<int>> valores(nroBaloes+2, std::vector<int>(nroBaloes+2, 0));

    //Largura da análise atual
    for (int largura = 1; largura < nroBaloes+2; ++largura)
    {
        //Para cada posição permitida (sempre é o mais à esquerda da largura)
        for (int i = 1; i < nroBaloes - largura + 2; ++i)
        {
            //Calcula a posição mais à direita da largura, dada a posição atual
            int aux = i + largura - 1;
            //Para cada posição até o fim da largura
            for (int j = i; j < aux+1; ++j)
            {
                //Calcula a pontuação se a posição atual (k) for o último balão estourado
                //Ou seja, o à esquerda da largura, ele e o à direita da largura
                int pontos = baloes[i-1] * baloes[j] * baloes[aux+1];
                //Soma com os valores dos seus adjacentes previamente calculados
                //Ou seja, soma com os valores se os demais tivessem sido estourados antes
                int total = valores[i][j-1] + valores[j+1][aux] + pontos;
                //Se for maior que o último valor salvo, o atualiza
                valores[i][aux] = std::max(valores[i][aux], total);
            }
            //Como aux sempre aumenta e o i tem um limite cada vez menor,
            //serão calculadas primeiro as posições [i][i], criando a diagonal principal
            //Depois serão calculadas apenas as posições superiores à diagonal, tendo
            //o resultado final no canto superior direito [1][nroBaloes]
        }
    }

    //Imprime o valor máximo calculado
    std::cout << valores[1][nroBaloes] << std::endl;

    return 0;
}