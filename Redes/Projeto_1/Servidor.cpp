#include "Servidor.h"

Servidor::Servidor(std::string ipv4)
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(8080);
    serverAdress.sin_addr.s_addr = inet_addr(ipv4.c_str());

    bind(serverSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress));

    listen(serverSocket, 5);

    int clientSocket = accept(serverSocket, nullptr, nullptr);

    std::cout << clientSocket << std::endl;

    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "msg do cliente: " << buffer << std::endl;

    close(serverSocket);
}