#include <iostream>
#include <vector>

int main()
{
    int nroMarcas;

    std::cin >> nroMarcas;

    std::vector<int> valores(nroMarcas);

    for(int i = 0; i < nroMarcas; ++i)
        std::cin >> valores[i];

    int nroPulos = 0, posicao = 0;
    //Enquanto não terminou os pulos
    while (posicao < nroMarcas-1)
    {
        //Se a posição atual não puder avançar (se caiu aqui, não haviam outras opções)
        //Alerta que é um salto impossível e sai
        if (valores[posicao] == 0)
        {
            std::cout << "Salto impossivel" << std::endl;
            return 0;
        }

        //Calcula a posição máxima que poderia alcançar daqui
        int puloMax = posicao + valores[posicao];
        //Para salvar o maior próximo salto possível e onde ele está
        int proxPuloMax = 0, proxPosicao;
        //Se o salto atual não encerraria o desafio
        if (puloMax < nroMarcas-1)
        {
            //Para cada posição depois da atual e até a máxima
            for (int i = posicao+1; i <= puloMax; ++i)
            {
                //Se o próximo salto iria mais longe que o próximo registrado
                if (i + valores[i] > proxPuloMax)
                {
                    //Salva o maior próximo salto
                    proxPuloMax = i + valores[i];
                    //Salva sua posição
                    proxPosicao = i;
                }
            }
        }
        //Se pode encerrar neste salto, salva que vai pular o máximo possível
        else
            proxPosicao = puloMax;

        //Aumenta o número de saltos
        nroPulos++;
        //Atualiza a posição
        posicao = proxPosicao;
    }
    std::cout << nroPulos << std::endl;

    return 0;
}