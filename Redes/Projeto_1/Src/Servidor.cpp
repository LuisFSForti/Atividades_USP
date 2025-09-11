#include "Servidor.h"

Servidor::Servidor(std::string ipv4)
{
    _stopAccepting = false;
    _servidorFechou = false;

    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (_serverSocket < 0) {
        perror("socket failed");
        throw std::runtime_error("Socket creation failed");
    }

    sockaddr_in serverAdress{};
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(8080);
    serverAdress.sin_addr.s_addr = inet_addr(ipv4.c_str());

    if (bind(_serverSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress)) < 0) {
        perror("bind failed");
        throw std::runtime_error("Bind failed");
    }

    _threadAccept = std::thread(&Servidor::AcceptClients, this);
}

Servidor::~Servidor()
{
    FecharServidor();
}

void Servidor::AcceptClients()
{
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(_serverSocket, SOL_SOCKET, SO_RCVTIMEO, 
        (const char*)&tv, sizeof(timeval)) < 0) 
    {
        perror("setsockopt failed");
    }

    if (listen(_serverSocket, 1) < 0) {
        _stopAccepting = true;
        perror("listen failed");
        return;
    }

    while(!_stopAccepting)
    {
        int clientSocket = accept(_serverSocket, nullptr, nullptr);

        if (clientSocket < 0)
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                std::cout << "Accept timeout" << std::endl;
                continue;  // go back to loop, check _stopAccepting
            }
            if(errno == EINTR) {
                perror("Signal blocking");
                continue; // interrupted by shutdown or signal
            }
            if (errno == EBADF || errno == ENOTSOCK || errno == EINVAL) {
                std::cout << "Socket sutdown" << std::endl;
                break;
            }

            perror("Accept failed");
            continue;
        }

        std::cout << "Nova conexão: " << clientSocket << std::endl;

        _controle.lock();
        _threadsConexoes.emplace_back(
            std::thread(&Servidor::CheckOnClient, this, clientSocket)
        );
        _controle.unlock();
    }
}

void Servidor::CheckOnClient(int clientSocket)
{
    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Conectou! " << buffer << std::endl;

    std::vector<Carta> teste;
    teste.emplace_back(Carta("A", ouros));
    teste.emplace_back(Carta("K", copas));
    teste.emplace_back(Carta("3", ouros));
    teste.emplace_back(Carta("6", paus));

    int n = teste.size();
    int i = 0;

    while(!_servidorFechou)
    {
        i++;
        i %= n;
        std::string message = teste.at(i).ToJson().dump();
        int ret = send(clientSocket, &message[0], message.length(), MSG_NOSIGNAL);

        if(ret == -1)
        {
            if(errno == EPIPE)
            {
                std::cout << "Cliente " << clientSocket << " fechou a conexão!" << std::endl;
                close(clientSocket);
                return;
            }
            else
            {
                perror("Send failed");
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(timeoutMensagens));
    }

    close(clientSocket);
}

void Servidor::FecharServidor()
{
    if(_servidorFechou)
        return;

    shutdown(_serverSocket, SHUT_RDWR);

    _stopAccepting = true;
    if(_threadAccept.joinable())
        _threadAccept.join();

    _servidorFechou = true;

    _controle.lock();
    for(int i = 0; i < (int)_threadsConexoes.size(); i++)
    {
        if(_threadsConexoes[i].joinable())
            _threadsConexoes[i].join();
    }
    _controle.unlock();

    close(_serverSocket);
}