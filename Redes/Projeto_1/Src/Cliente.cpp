#include "Cliente.h"

Cliente::Cliente(std::string ipv4)
{
    _clienteFechou = false;
    _servidorFechou = false;

    _clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(8080);
    serverAdress.sin_addr.s_addr = inet_addr(ipv4.c_str());

    connect(_clientSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress));

    const char* message = "Ola";
    send(_clientSocket, message, strlen(message), 0);

    _threadConexao = std::thread(&Cliente::CheckOnServer, this);
}

void Cliente::CheckOnServer()
{
    char buffer[1024];

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    setsockopt(_clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    while (!_clienteFechou) {
        int bytes = recv(_clientSocket, buffer, sizeof(buffer), 0);
        
        if (bytes > 0) {
            buffer[bytes] = '\0';
            std::cout << "Mensagem do servidor: " << buffer << std::endl;
        } else if (bytes == 0) {
            std::cout << "Servidor fechou a conexão!\n";
            close(_clientSocket);
            break;
        } else {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                //Tempo de espera máximo ocorreu
                continue;
            } else {
                perror("recv");
                break;
            }
        }
    }
}

void Cliente::FecharCliente()
{
    _clienteFechou = true;

    if(_threadConexao.joinable())
        _threadConexao.join();

    if(!_servidorFechou)
        close(_clientSocket);
}