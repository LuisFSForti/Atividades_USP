#include "Cliente.h"

Cliente::Cliente(std::string ipv4)
{
    _clienteFechou = false;
    _servidorFechou = false;

    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(8080);
    serverAdress.sin_addr.s_addr = inet_addr(ipv4.c_str());

    connect(_serverSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress));

    const char* message = "Conexão feita";
    send(_serverSocket, message, strlen(message), 0);

    _threadConexao = std::thread(&Cliente::CheckOnServer, this);
}

Cliente::~Cliente()
{
    FecharCliente();
}

void Cliente::CheckOnServer()
{
    char buffer[1024];

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    setsockopt(_serverSocket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    while (!_clienteFechou) {
        int ret = recv(_serverSocket, buffer, sizeof(buffer), 0);
        
        if (ret > 0) {
            buffer[ret] = '\0';

            Carta test(nlohmann::json::parse(buffer));

            std::cout << "Mensagem do servidor: " << test << std::endl;
        } else if (ret == 0) {
            std::cout << "Servidor fechou a conexão!\n";
            _servidorFechou = true;
            close(_serverSocket);
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
    if(_clienteFechou)
        return;

    _clienteFechou = true;

    if(_threadConexao.joinable())
        _threadConexao.join();

    if(!_servidorFechou)
        close(_serverSocket);
}