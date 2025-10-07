#include <cstring>
#include <iostream>
#include <csignal>

#include "Servidor.h"
#include "Cliente.h"
#include "Carta.h"
#include "Baralho.h"
#include "Jogador.h"
#include "GerenciadorJogo.h"

Servidor* servidorGlobal = nullptr;

//Pra quando der cntrl+C no console ele fechar o servidor adequadamente
void signalHandler(int signum) {
    std::cout << "Signal " << signum << " received, shutting down server..." << std::endl;
    if (servidorGlobal)
        servidorGlobal->FecharServidor();
    std::_Exit(0); // exit immediately after cleanup
}

//Verifica se o usuário digitou algo e apertou enter
bool InputAvailable() 
{
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    int ret = select(STDIN_FILENO + 1, &readfds, nullptr, nullptr, &tv);
    return (ret > 0 && FD_ISSET(STDIN_FILENO, &readfds));
}

int main()
{
    /*std::signal(SIGINT, signalHandler);

    std::cout << "Escolha o modo de host: \n1 - Dealer\n2 - Jogador" << std::endl;

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

        servidorGlobal = new Servidor(ipv4);

        std::vector<DadosJogador> jogadores;
        Baralho baralho;
        int fichasIniciais = 1000;

        std::cout << "Digite 'Iniciar' e pressione [Enter] para começar o jogo!" << std::endl;
        while (servidorGlobal->ServerOpen()) {
            for(int newSocket : servidorGlobal->GetNewSockets())
            {
                jogadores.push_back({ newSocket, Jogador(baralho.PegarCarta(), baralho.PegarCarta(), fichasIniciais) });
                std::cout << "Jogador " << jogadores.size() << " entrou!" << std::endl;
            }

            for(int closedSocket : servidorGlobal->GetClosedSockets())
            {
                for(int i = 0; i < (int)jogadores.size(); i++)
                {
                    if(jogadores[i].socket == closedSocket)
                    {
                        jogadores.erase(jogadores.begin() + i);
                        std::cout << "Jogador " << i+1 << " desconectou!" << std::endl;
                        break;
                    }
                }
            }

            if (InputAvailable()) {
                std::cout << "E" << std::endl;
                std::string input;
                
                getline(std::cin, input);

                if(input == "Iniciar")
                {
                    servidorGlobal->StopAccpetingClients();
                    break;
                }
            }

            // Small sleep so we don't busy-wait
            usleep(100000);
        }

        servidorGlobal->SendClientMessage(jogadores[0].socket, jogadores[0].jogador.ToJson());

        while(true)
            ;

        servidorGlobal->FecharServidor();

        delete servidorGlobal;
    }
    else
    {
        std::cout << "Digite o endereço IPV4 do servidor: ";
        std::string ipv4;
        std::cin >> ipv4;

        Cliente cliente(ipv4);
        Jogador jogador;
        
        while (cliente.ConnectionOpen()) {
            nlohmann::json msg = cliente.GetServerMessage();
            if(!msg.is_null())
            {
                if(msg["Cod"] == "Jogador")
                {
                    jogador = Jogador(msg);
                    std::cout << jogador << std::endl;
                    
                    break;
                }
            }

            if (InputAvailable()) {
                std::string input;

                getline(std::cin, input);

                break;
            }

            // Small sleep so we don't busy-wait
            usleep(100000);
        }

        cliente.FecharCliente();
    }*/

    return 0;
}