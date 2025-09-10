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

        if (ipv4.empty()) {
            std::cerr << "Erro: endereço IPV4 vazio!\n";
            return 1; // or loop until valid
        }

        Servidor servidor(ipv4);

        std::string lixo;
        std::cin >> lixo;

        servidor.FecharServidor();
    }
    else
    {
        std::cout << "Digite o endereço IPV4 que do servidor: ";
        std::string ipv4;
        std::cin >> ipv4;

        Cliente cliente(ipv4);

        std::string lixo;
        std::cin >> lixo;

        cliente.FecharCliente();
    }

    return 0;
}