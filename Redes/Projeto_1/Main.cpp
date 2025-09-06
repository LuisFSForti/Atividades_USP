#include <cstring>
#include <iostream>

#include "Servidor.h"
#include "Cliente.h"

int main()
{
    std::cout << "Escolha o modo de host: \n1 - Servidor\n2 - Cliente" << std::endl;

    int escolha;

    std::cin >> escolha;

    if(escolha == 1)
    {
        std::cout << "Digite o endereço IPV4 que o servidor deve usar: ";
        std::string ipv4;
        std::cin >> ipv4;

        Servidor* servidor = new Servidor(ipv4);
        free(servidor);
    }
    else
    {
        std::cout << "Digite o endereço IPV4 que do servidor: ";
        std::string ipv4;
        std::cin >> ipv4;

        Cliente* cliente = new Cliente(ipv4);
        free(cliente);
    }

    return 0;
}