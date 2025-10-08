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
    std::signal(SIGINT, signalHandler);

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
        GerenciadorJogo gerenciador(servidorGlobal);

        bool jogando = true;
        while(jogando)
        {
            std::cout << "========================================================================" << std::endl;
            std::cout << "\nDigite 'Iniciar' e pressione [Enter] para começar o jogo!" << std::endl;
            std::cout << "Digite 'Encerrar' e pressione [Enter] para terminar o jogo!\n" << std::endl;

            while (servidorGlobal->ServerOpen()) 
            {
                gerenciador.VerificarNovosJogadores();
                gerenciador.VerificarJogadoresFechados();

                if (InputAvailable()) {
                    std::string input;
                    
                    getline(std::cin, input);

                    if(input == "Iniciar")
                    {
                        gerenciador.JogarPartida();
                        break;
                    }
                    else if(input == "Encerrar")
                    {
                        jogando = false;
                        break;
                    }
                }

                usleep(100000);
            }
        }
        servidorGlobal->FecharServidor();

        delete servidorGlobal;
    }
    else
    {
        std::cout << "Digite o endereço IPV4 do servidor: ";
        std::string ipv4;
        std::cin >> ipv4;

        std::cout << "Qual é o seu nome?" << std::endl;
        std::string nomeJogador;

        while(nomeJogador == "")
            getline(std::cin, nomeJogador);

        Cliente cliente(ipv4);
        
        //Como o único input do jogador com o jogo é pra apostar, basta um bool
        bool jogoEsperandoInput = false;
        int valorMinimo = 0;
        //Dados do jogador, incluindo a mão dele na rodada
        Jogador jogador;
        //A mesa da rodada
        std::vector<Carta> mesa;
        while (cliente.ConnectionOpen()) 
        {
            nlohmann::json msg = cliente.GetServerMessage();
            if(!msg.is_null())
            {
                //Servidor conectou e está pedindo o nome do jogador
                if(msg[codigo] == codPedirNome)
                {
                    msg.clear();
                    msg[codigo] = codFornecerNome;
                    msg[codAtributoNomeJogador] = nomeJogador;

                    cliente.SendServerMessage(msg);
                }
                //Servidor está mandando um jogador, sinal de que éstá iniciando a rodada
                else if(msg[codigo] == codJogador)
                {
                    jogador = Jogador(msg);
                    mesa.clear();
                }
                //Se está recebendo uma carta, então a mesa virou uma carta
                else if(msg[codigo] == codCarta)
                {
                    //Adiciona a carta à mesa
                    mesa.push_back(Carta(msg));
                }
                //Se o jogador for um dos blinds
                else if(msg[codigo] == codSmall || msg[codigo] == codBig)
                {
                    jogador.Apostar(msg[codAtributoValor].get<int>());
                }
                else if(msg[codigo] == codGanho)
                {
                    jogador.Coletar(msg[codAtributoValor].get<int>());
                }
                else if(msg[codigo] == codComunicacao)
                {
                    std::cout << "========================================================================"
                                << std::endl << std::endl << std::endl;

                    std::cout << "Mesa:" << std::endl;
                    for(Carta car : mesa)
                        std::cout << car << std::endl;

                    std::cout << "\nSua mão: " << std::endl;
                    for(int i = 0; i < 2; i++)
                        std::cout << jogador.GetMao()[i] << std::endl;

                    std::cout << std::endl << std::endl;

                    std::cout << "Jogadores:" << std::endl;

                    for (auto& [nome, fichas] : msg[codTabelaFichasRestantes].items()) {
                        std::cout << nome << ": " << fichas << std::endl;
                    }

                    std::cout << "Maior aposta é de " << msg[codMaiorAposta][codAtributoNomeJogador]
                            << " com " << msg[codMaiorAposta][codAtributoValor] << std::endl;

                    std::cout << "A mesa está com " << msg[codValorPote] << std::endl;

                    std::cout << msg[codAtributoMensagem] << std::endl << std::endl;
                }
                else if(msg[codigo] == codComunicacaoDesconectou || msg[codigo] == codComunicacaoFinalizacao)
                {
                    std::cout << msg[codAtributoMensagem] << std::endl << std::endl;
                }
                else if(msg[codigo] == codPedirAposta)
                {
                    jogoEsperandoInput = true;
                    valorMinimo = msg[codAtributoValor].get<int>();

                    if(valorMinimo > jogador.GetFichas())
                    {
                        std::cout << "Faça sua aposta:\n" 
                            << "0 = Fold\n" << "1 = All-In\n" << std::endl;
                    }
                    else
                    {
                        std::cout << "Faça sua aposta:\n" 
                            << "0 = Fold\n" << "1 = Call (" << valorMinimo << ")\n";

                        std::cout << "\n\n" << valorMinimo << " - " << jogador.GetFichas() << std::endl << std::endl << std::endl;
                        if(valorMinimo < jogador.GetFichas())
                            std::cout << "Outro número = valor à apostar (mínimo de " << valorMinimo << ")\n";

                        std::cout << std::endl;
                    }
                }
            }

            if (InputAvailable()) {
                std::string input;

                getline(std::cin, input);

                if(jogoEsperandoInput && input != "")
                {
                    int escolha;
                    try
                    {
                        escolha = std::stoi(input);
                    }
                     catch (const std::invalid_argument& e) {
                        std::cout << "Digite um número!" << std::endl;
                        continue;
                    } catch (const std::out_of_range& e) {
                        std::cout << "Número fora do alcance de inteiros!" << std::endl;
                        continue;
                    }

                    if(valorMinimo > jogador.GetFichas())
                    {
                        switch (escolha)
                        {
                        //Fold
                        case 0:
                            msg.clear();
                            msg[codigo] = codFold;
                            cliente.SendServerMessage(msg);

                            jogoEsperandoInput = false;
                            break;
                        
                        //All-in
                        case 1:
                            msg.clear();
                            msg[codigo] = codAposta;
                            msg[codAtributoValor] = jogador.GetFichas();
                            cliente.SendServerMessage(msg);
                            jogador.Apostar(jogador.GetFichas());

                            jogoEsperandoInput = false;
                            break;

                        default:
                            std::cout << "Digite uma escolha válida!" << std::endl;
                            break;
                        }
                    }
                    else
                    {
                        switch (escolha)
                        {
                        //Fold
                        case 0:
                            msg.clear();
                            msg[codigo] = codFold;
                            cliente.SendServerMessage(msg);

                            jogoEsperandoInput = false;
                            break;
                        
                        //Call
                        case 1:
                            msg.clear();
                            msg[codigo] = codAposta;
                            msg[codAtributoValor] = valorMinimo;
                            cliente.SendServerMessage(msg);
                            jogador.Apostar(valorMinimo);

                            jogoEsperandoInput = false;
                            break;

                        default:
                            if(valorMinimo > escolha || escolha > jogador.GetFichas())
                            {
                                std::cout << "Digite uma escolha válida!" << std::endl;   
                                break;
                            }
                            else
                            {
                                msg.clear();
                                msg[codigo] = codAposta;
                                msg[codAtributoValor] = escolha;
                                cliente.SendServerMessage(msg);
                                jogador.Apostar(escolha + valorMinimo);

                                jogoEsperandoInput = false;

                                break;
                            }
                        }
                    }
                }
            }

            usleep(100000);
        }

        cliente.FecharCliente();
    }

    return 0;
}