#include <iostream>
#include <vector>

int main()
{
    int nroCasos;
    std::cin >> nroCasos;

    //Para cada caso teste
    for (int i = 0; i < nroCasos; ++i)
    {
        int tamX, tamY;
        std::cin >> tamY >> tamX;

        //Variáveis para o cálculo do retângulo
        //Como os pontos relevantes são apenas o mais alto, o mais à esquerda e o mais à direita
        //não há necessidade de armazenar a parede toda, apenas iterar em cima do mais recente
        char tintaPonto;
        int respingoMaisAlto = tamY;
        int respingoMaisEsquerda = tamX, respingoMaisDireita = -1;

        for (int j = 0; j < tamY; ++j)
        {
            for (int k = 0; k < tamX; ++k)
            {
                std::cin >> tintaPonto;

                //Se for tinta preta
                if (tintaPonto == 'B')
                {
                    //Verifica a posição do ponto em relação aos critérios
                    if (respingoMaisAlto > j)
                        respingoMaisAlto = j;
                    if (respingoMaisEsquerda > k)
                        respingoMaisEsquerda = k;
                    if (respingoMaisDireita < k)
                        respingoMaisDireita = k;
                }
            }
        }

        //Se o respingo mais alto estiver em tamY, então não há respingos (o loop para em tamY-1)
        if (respingoMaisAlto == tamY)
            std::cout << "0 0" << std::endl;
        //Se tiverem respingos
        else
            //Imprime o tamanho do retângulo
            std::cout << (tamY - respingoMaisAlto) << " " << (respingoMaisDireita - respingoMaisEsquerda + 1) << std::endl;
    }
}