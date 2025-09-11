#include <cstring>
#include <iostream>
#include <csignal>

#include "Servidor.h"
#include "Cliente.h"
#include "Carta.h"

Servidor* servidorGlobal = nullptr;

//Pra quando der cntrl+C no console ele fechar o servidor adequadamente
void signalHandler(int signum) {
    std::cout << "Signal " << signum << " received, shutting down server..." << std::endl;
    if (servidorGlobal)
        servidorGlobal->FecharServidor();
    std::_Exit(0); // exit immediately after cleanup
}

int main()
{
    std::signal(SIGINT, signalHandler);

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

        servidorGlobal = &servidor;

        std::string lixo;
        std::cin >> lixo;
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