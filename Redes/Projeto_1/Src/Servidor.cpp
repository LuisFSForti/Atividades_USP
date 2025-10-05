#include "Servidor.h"

Servidor::Servidor(std::string ipv4)
{
    //Enquanto não estiver perfeitamente funcional, define que não está aberto
    _stopAccepting = true;
    _servidorFechou = true;
    _mensagemClienteAtual = nullptr;

    //Cria um socket pro servidor
    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    //Se falhou
    if (_serverSocket < 0) {
        //Avisa o erro
        perror("socket failed");
        //Encerra o código
        throw std::runtime_error("Socket creation failed");
    }

    //Configura o endereço do socket
    sockaddr_in serverAdress{};
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(8080);
    serverAdress.sin_addr.s_addr = inet_addr(ipv4.c_str());

    //Tenta conectar o socket ao seu endereço
    if (bind(_serverSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress)) < 0) {
        //Se falhar, avisa o erro e encerra o código
        perror("bind failed");
        throw std::runtime_error("Bind failed");
    }

    //Cria o socket do servidor com um timeout
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(_serverSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(timeval)) < 0) 
    {
        //Se falhou em criar o timeout, avisa o erro e encerra o código
        perror("setsockopt failed");
        throw std::runtime_error("Timeout failed");
    }

    //Tenta iniciar a função de procurar clientes
    if (listen(_serverSocket, 1) < 0) 
    {
        //Se falhar, avisa o erro e encerra o código
        perror("listen failed");
        throw std::runtime_error("Listen failed");
    }

    //Com o socket corretamente configurado, inicia o servidor
    _servidorFechou = false;
    _stopAccepting = false;
    _socketClienteAtual = -1;

    //Com o socket feito, cria a thread de aceitar clientes
    _threadAccept = std::thread(&Servidor::AcceptClients, this);
}

Servidor::~Servidor()
{
    FecharServidor();
}

void Servidor::AcceptClients()
{
    //Enquanto puder procurar por clientes novos
    while(!_stopAccepting)
    {
        //Verifica se um cliente está tentando conectar
        int clientSocket = accept(_serverSocket, nullptr, nullptr);

        //Se houve um erro
        if (clientSocket < 0)
        {
            //Erro de timeout, apenas continua
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                //std::cout << "Accept timeout" << std::endl;
                continue;
            }
            //Algum erro de sinal
            else if(errno == EINTR) {
                //Avisa e continua, pois é temporário
                //perror("Signal blocking");
                continue;
            }
            //Erros fatais
            else if (errno == EBADF || errno == ENOTSOCK || errno == EINVAL) {
                //perror("Socket sutdown");
                _stopAccepting = true;
                break;
            }
            else
            {
                //Outros erros quaisquer
                perror("Accept failed");
                continue;
            }
        }

        //Se não houve erros

        //Avisa que fez uma nova conexão e com quem
        //std::cout << "Nova conexão: " << clientSocket << std::endl;

        //Espera a mensagem de confirmação do cliente
        char buffer[1024] = { 0 };
        recv(clientSocket, buffer, sizeof(buffer), 0);
        //std::cout << "Conectou! Mensagem do cliente: " << buffer << std::endl;

        {
            std::lock_guard<std::mutex> lock(_controle);

            //Cria uma thread pra ouvir o cliente
            _threadsConexoes.push_back({clientSocket, std::thread(&Servidor::CheckOnClient, this, clientSocket)});

            //Salva que um novo socket foi adicionado
            _clientsAccepted.push_back(clientSocket);
        }
    }
}

void Servidor::CheckOnClient(int clientSocket)
{
    //Buffer pra receber as mensagens
    char buffer[1024];

    //Cria um timeout pro socket
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    //Enquanto o servidor não tiver fechado
    while (!_servidorFechou)
    {
        //Sinal de retorno ao tentar receber mensagem do cliente
        int ret = recv(clientSocket, buffer, sizeof(buffer), 0);
        
        //ret > 0 -> mensagem recebida, ret == número de char recebidos
        if (ret > 0)
        {
            //Coloca um \0 no final pra deixar a string bem definida
            buffer[ret] = '\0';

            if(_socketClienteAtual == clientSocket)
            {
                std::lock_guard<std::mutex> lock(_controle);

                _mensagemClienteAtual = nlohmann::json::parse(buffer);
            }
        }
        //ret == 0 -> cliente fechou o socket corretamente
        else if (ret == 0) 
        {
            //std::cout << "Cliente " << clientSocket << " fechou a conexão!\n";
            {
                std::lock_guard<std::mutex> lock(_controle);

                if(std::find(_clientsClosed.begin(), _clientsClosed.end(), clientSocket) == _clientsClosed.end())
                {
                    _clientsClosed.push_back(clientSocket);
                }
            }

            break;
        }
        //Erros causados por timeout
        else if (errno == EAGAIN || errno == EWOULDBLOCK) {
            continue;
        }
        //Cliente fechou forçadamente
        else if(errno == ECONNRESET)
        {
            //std::cerr << "Cliente " << clientSocket << " fechou incorretamente: " << strerror(errno) << std::endl;
            {
                std::lock_guard<std::mutex> lock(_controle);

                if(std::find(_clientsClosed.begin(), _clientsClosed.end(), clientSocket) == _clientsClosed.end())
                {
                    _clientsClosed.push_back(clientSocket);
                }
            }
            break;
        }
        //Algum erro qualquer
        //Inclui erros de sinal ou socket incorreto.
        //Como a thread só é chamada em conexões válidas, assume-se que o erro é temporário
        else
        {
            //Avisa o erro
            perror("recv");            
        }
    }

    //Fecha a conexão
    close(clientSocket);
}

void Servidor::SetClientAtual(int clientSocket)
{
    _socketClienteAtual = clientSocket;
}

void Servidor::SendClientMessage(int clientSocket, nlohmann::json msg)
{
    //Converte o json pra uma string
    std::string message = msg.dump();
    int ret = -1;

    do
    {
        //Tenta enviar a mensagem
        ret = send(clientSocket, &(message[0]), message.length(), MSG_NOSIGNAL);

        //Se houve um erro
        if(ret == -1)
        {
            //Erros no socket, assume-se que ele foi encerrado
            if(errno == EPIPE || errno == ENOTCONN || errno == EADDRNOTAVAIL
                || errno == ECONNREFUSED || errno == ETIMEDOUT)
            {
                //std::cout << "Cliente " << clientSocket << " fechou a conexão!" << std::endl;
                
                {
                    std::lock_guard<std::mutex> lock(_controle);

                    if(std::find(_clientsClosed.begin(), _clientsClosed.end(), clientSocket) == _clientsClosed.end())
                        _clientsClosed.push_back(clientSocket);
                }

                break;
            }
            else if(errno == EFAULT || errno == EMSGSIZE)
            {
                std::cout << "Mensagem com erro!" << std::endl;

                break;
            }
            else
            {
                perror("Send failed");
                //Espera um pouco
                std::this_thread::sleep_for(std::chrono::milliseconds(timeoutMensagens));
            }
        }
    } while(ret == -1);
}

void Servidor::BroadcastMessage(nlohmann::json msg)
{
    {
        //Trava o vetor
        std::lock_guard<std::mutex> lock(_controle);

        //Para cada cliente que vai mandar a mensagem
        for (const DadosSocket &clientSocket : _threadsConexoes)
        {
            SendClientMessage(clientSocket.socket, msg);
        }
    }
}

void Servidor::CloseDeadThreads()
{
    //Vetor temporário pras threads ativas
    std::vector<std::thread> threadsToJoin;
    {
        //Trava o vetor
        std::lock_guard<std::mutex> lock(_controle);

        //Para cada thread que precisa dar join
        for (int clientSocket : _clientsClosed) {
            //Pega a posição dela no vetor
            for(int i = 0; i < (int)_threadsConexoes.size(); i++)
            {
                if(_threadsConexoes[i].socket == clientSocket)
                {
                    //Salva no vetor temporário
                    threadsToJoin.push_back(std::move(_threadsConexoes[i].thread));

                    _threadsConexoes.erase(_threadsConexoes.begin() + i);
                }
            }            
        }

        //Limpa o vetor original
        _clientsClosed.clear();
    }

    //Chama join em todas as threads sem precisar do mutex
    for (auto &t : threadsToJoin) 
    {
        if (t.joinable())
            t.join();
    }
    threadsToJoin.clear();
}

nlohmann::json Servidor::GetClientMessage()
{
    nlohmann::json msg = _mensagemClienteAtual;
    _mensagemClienteAtual = nullptr;

    return msg;
}

void Servidor::StopAccpetingClients()
{
    //Define que deve parar de receber clientes
    _stopAccepting = true;
    
    if(_threadAccept.joinable())
        //Espera a thread encerrar
        _threadAccept.join();

    _clientsAccepted.clear();
}

void Servidor::FecharServidor()
{
    if(_servidorFechou)
        return;

    //Define que o servidor fechou
    _servidorFechou = true;

    //Fecha a conexão do socket do servidor
    shutdown(_serverSocket, SHUT_RDWR);

    //Manda parar de aceitar clientes
    StopAccpetingClients();

    //Vetor temporário pras threads ativas
    std::vector<std::thread> threadsToJoin;
    {
        //Trava o vetor
        std::lock_guard<std::mutex> lock(_controle);

        //Salva todas as threads que precisa dar join
        for (auto &t : _threadsConexoes) {
            threadsToJoin.push_back(std::move(t.thread));

            //Encerra o socket da thread, iniciando o processo
            shutdown(t.socket, SHUT_RDWR);
        }
        //Limpa o vetor original
        _threadsConexoes.clear();
    }

    //Chama join em todas as threads sem precisar do mutex
    for (auto &t : threadsToJoin) 
    {
        if (t.joinable())
            t.join();
    }
    threadsToJoin.clear();

    //Como todas as threads já foram terminada, basta limpar o vetor
    _clientsClosed.clear();

    //Fecha o socket do servidor
    close(_serverSocket);

    //Socket inválido
    _serverSocket = -1;

    std::cout << "ACABOU" << std::endl;
}

std::vector<int> Servidor::GetNewSockets()
{
    std::vector<int> sockets;
    {
        std::lock_guard<std::mutex> lock(_controle);
        sockets = _clientsAccepted;

        _clientsAccepted.clear();
    }

    return sockets;
}

std::vector<int> Servidor::GetClosedSockets()
{
    std::vector<int> sockets;
    {
        std::lock_guard<std::mutex> lock(_controle);
        sockets = _clientsClosed;
    }

    CloseDeadThreads();

    return sockets;
}

bool Servidor::ServerOpen()
{
    return !_servidorFechou;
}