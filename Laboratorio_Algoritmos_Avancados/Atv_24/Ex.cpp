#include <iostream>
#include <vector>
#include <math.h>

#define TAMANHO_TABULEIRO 9

struct CoordenadasGrid
{
    int x, y;
};

int CalcularSubGrid(CoordenadasGrid posicao)
{
    return (posicao.y/3)*3 + (posicao.x/3);
}

//A função do subgrid é facilitar a decisão de quais posições devem ser comparadas
//A subgrid 0 é o quadrante superior esquerdo, a subgrid 1 é o quadrante superior central, etc
std::vector<std::vector<CoordenadasGrid>> CriarSubGrids()
{
    std::vector<std::vector<CoordenadasGrid>> subGrids(TAMANHO_TABULEIRO, std::vector<CoordenadasGrid>(TAMANHO_TABULEIRO));

    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            int indiceDentro =
                (y % 3) * 3 +
                (x % 3);

            //Guarda, em cada posição da subgrid, as coordenadas que devem ser comparadas
            subGrids[CalcularSubGrid(CoordenadasGrid{ x, y })][indiceDentro] = { x, y };
        }
    }

    return subGrids;
}

bool ValidarPosicao(std::vector<std::vector<int>> &posicoesOcupadas, std::vector<std::vector<CoordenadasGrid>> &subGrids, CoordenadasGrid novaPosicao, int novoVal)
{
    //Todos na mesma linha
    for (int j = 0; j < TAMANHO_TABULEIRO; ++j)
    {
        if (posicoesOcupadas[novaPosicao.y][j] == novoVal)
            return false;
    }
    //Todos na mesma coluna
    for (int i = 0; i < TAMANHO_TABULEIRO; ++i)
    {
        if (posicoesOcupadas[i][novaPosicao.x] == novoVal)
            return false;
    }
    //Todos no mesmo subgrid
    for (CoordenadasGrid posicaoGrid : subGrids[CalcularSubGrid(novaPosicao)])
    {
        //Se compartilharem linha ou coluna, já foram processados nos ifs anteriroes
        if (posicaoGrid.x == novaPosicao.x || posicaoGrid.y == novaPosicao.y)
            continue;

        if (posicoesOcupadas[posicaoGrid.y][posicaoGrid.x] == novoVal)
            return false;
    }
    return true;
}

void SudokuRecursivo(std::vector<std::vector<int>> &posicoesOcupadas, std::vector<std::vector<CoordenadasGrid>> &subGrids, int &contagem, CoordenadasGrid posicao)
{
    //Como avança de linha em linha, se sair do tabuleiro é porque concluiu
    if (posicao.y == TAMANHO_TABULEIRO)
    {
        contagem++;
        return;
    }

    int proximoY = posicao.y;
    int proximoX = posicao.x + 1;
    if (proximoX == TAMANHO_TABULEIRO)
    {
        proximoX = 0;
        proximoY++;
    }

    //Se a posição for != 0, então ela é uma das posições pré-definidas e estáticas
    if (posicoesOcupadas[posicao.y][posicao.x] != 0)
    {
        //Chama a recursão e sai imediatamente
        SudokuRecursivo(posicoesOcupadas, subGrids, contagem, CoordenadasGrid { proximoX, proximoY });
        return;
    }

    //Para todos os valores possíveis
    for (int i = 1; i < 10; i++)
    {
        if (ValidarPosicao(posicoesOcupadas, subGrids, posicao, i))
        {
            posicoesOcupadas[posicao.y][posicao.x] = i;
            SudokuRecursivo(posicoesOcupadas, subGrids, contagem, CoordenadasGrid { proximoX, proximoY });
        }
    }
    //Quando terminar as análises, limpa a célula atual, para não afetar as análises do backtracking
    posicoesOcupadas[posicao.y][posicao.x] = 0;
}

int main()
{
    int nroOcupadas;
    std::vector<std::vector<int>> posicoes(TAMANHO_TABULEIRO, std::vector<int> (TAMANHO_TABULEIRO, 0));
    std::vector<std::vector<CoordenadasGrid>> subGrids = CriarSubGrids();

    std::cin >> nroOcupadas;

    //Pega os valores pré-definidos, estáticos
    for (int i = 0; i < nroOcupadas; ++i)
    {
        int x, y, val;
        std::cin >> y >> x >> val;

        x--;
        y--;

        posicoes[y][x] = val;
    }

    int contagem = 0;
    SudokuRecursivo(posicoes, subGrids, contagem, CoordenadasGrid{ 0, 0 });

    std::cout << contagem << std::endl;

    return 0;
}