#include "Cliente.h"

Cliente::Cliente(std::string ipv4)
{
    _clienteFechou = true;

    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(8080);
    serverAdress.sin_addr.s_addr = inet_addr(ipv4.c_str());

    if (connect(_serverSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress)) < 0) {
        perror("Connect failed");
        throw std::runtime_error("Failed to connect to server");
    }

    const char* message = "Conexão feita!";
    send(_serverSocket, message, strlen(message), 0);

    _clienteFechou = false;

    _threadConexao = std::thread(&Cliente::CheckOnServer, this);
}

Cliente::~Cliente()
{
    FecharCliente();
}

void Cliente::CheckOnServer()
{
    //Buffer pra receber as mensagens
    char buffer[1024];

    //Cria um timeout pro socket
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    setsockopt(_serverSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    //Enquanto o cliente não tiver fechado
    while (!_clienteFechou)
    {
        //Sinal de retorno ao tentar receber mensagem do servidor
        int ret = recv(_serverSocket, buffer, sizeof(buffer), 0);
        
        //ret > 0 -> mensagem recebida, ret == número de char recebidos
        if (ret > 0)
        {
            //Para deixar a string bem definida
            buffer[ret] = '\0';

            //Como múltiplos jsons podem chegar de uma vez, precisa separá-los
            std::string entrada = buffer;
            int contagemChaves = 0;
            int comecoJsonAtual = 0;
            for (size_t i = 0; i < entrada.size(); ++i) 
            {
                if (entrada[i] == '{') 
                {
                    if (contagemChaves == 0) 
                        comecoJsonAtual = i; // start of JSON

                    contagemChaves++;
                }
                else if (entrada[i] == '}') 
                {
                    contagemChaves--;
                    if (contagemChaves == 0)
                    {
                        std::string jsonAtual = entrada.substr(comecoJsonAtual, i - comecoJsonAtual + 1);
                        
                        {
                            std::lock_guard<std::mutex> lock(_controle);

                            _mensagensServidor.push_back(nlohmann::json::parse(jsonAtual));
                        }
                    }
                }
            }
        }
        //ret == 0 -> servidor fechou o socket corretamente
        else if (ret == 0) 
        {
            std::cout << "Servidor fechou a conexão!\n";
            break;
        }
        //Erros causados por timeout
        else if (errno == EAGAIN || errno == EWOULDBLOCK) {
            continue;
        }
        //Algum erro qualquer
        //Inclui erros de sinal ou socket incorreto.
        //Como a thread só é chamada em conexões válidas, assume-se que o erro é temporário
        else
        {
            //Avisa o erro
            //perror("recv");

            //Server fechou forçadamente
            if(errno == ECONNRESET)
                break;
        }
    }

    //Fecha a conexão
    close(_serverSocket);
    _clienteFechou = true;
}

void Cliente::SendServerMessage(nlohmann::json msg)
{
    std::string message = msg.dump();
    int ret = -1;

    do
    {
        ret = send(_serverSocket, &(message[0]), message.length(), MSG_NOSIGNAL);

        //Se houve um erro
        if(ret == -1)
        {
            //Erros no socket, assume-se que ele foi encerrado
            if(errno == EPIPE || errno == ENOTCONN || errno == EADDRNOTAVAIL
                || errno == ECONNREFUSED || errno == ETIMEDOUT)
            {
                std::cout << "Servidor " << _serverSocket << " fechou a conexão!" << std::endl;
                
                //Fecha a conexão
                close(_serverSocket);
                _clienteFechou = true;

                break;
            }
            else if(errno == EFAULT || errno == EMSGSIZE)
            {
                std::cout << "Mensagem com erro!" << std::endl;

                break;
            }
            else
            {
                //perror("Send failed");
                //Espera um pouco
                std::this_thread::sleep_for(std::chrono::milliseconds(timeoutMensagens));
            }
        }
    } while(ret == -1);
}

nlohmann::json Cliente::GetServerMessage()
{
    nlohmann::json msg;
    {
        std::lock_guard<std::mutex> lock(_controle);

        if(_mensagensServidor.size() <= 0)
            return nlohmann::json();

        msg = _mensagensServidor[0];
        _mensagensServidor.erase(_mensagensServidor.begin());
    }

    return msg;
}

void Cliente::FecharCliente()
{
    _clienteFechou = true;

    if(_threadConexao.joinable())
        _threadConexao.join();
}

bool Cliente::ConnectionOpen()
{
    return !_clienteFechou;
}