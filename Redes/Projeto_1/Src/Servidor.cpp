#include "Servidor.h"

Servidor::Servidor(std::string ipv4)
{
    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(8080);
    serverAdress.sin_addr.s_addr = inet_addr(ipv4.c_str());

    bind(_serverSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress));

    listen(_serverSocket, 1);

    int clientSocket = accept(_serverSocket, nullptr, nullptr);

    std::cout << clientSocket << std::endl;

    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Conectou!" << buffer << std::endl;
}

void Servidor::FecharServidor()
{
    close(_serverSocket);
}