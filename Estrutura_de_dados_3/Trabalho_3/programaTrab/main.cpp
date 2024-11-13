#include <iostream>
#include <fstream>

#include "Dinossauro.h"

int main()
{
    std::fstream teste("binario1.bin", std::ios::in|std::ios::binary|std::ios::ate);

    if(!teste.is_open())
    {
        return 0;
    }

    std::cout << teste.tellg() << std::endl;
    teste.seekg(1600 + 160);
    std::cout << teste.tellg() << std::endl;

    Dinossauro dino(teste);

    std::cout << dino;

    std::fstream teste2("teste.bin", std::ios::out|std::ios::binary|std::ios::ate);
    dino.SalvarDinossauro(teste2);

    teste.close();
    teste2.close();

    return 0;
}
