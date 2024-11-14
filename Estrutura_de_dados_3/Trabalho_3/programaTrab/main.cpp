#include <iostream>
#include <fstream>

#include "Dinossauro.h"
#include "ListaDeAdjacencias.h"

int main()
{
    //std::fstream arq("binario1.bin", std::ios::in|std::ios::out|std::ios::binary);

    int cod;
    std::string endereco;

    std::cin >> cod >> endereco;

    switch(cod)
    {
    case 10:
        std::fstream arq(endereco, std::ios::in|std::ios::binary);

        if(!arq.is_open())
        {
            return 0;
        }

        ListaDeAdjacencias lista(arq);
        std::cout << lista;

        arq.close();
        break;

    }

    return 0;
}
