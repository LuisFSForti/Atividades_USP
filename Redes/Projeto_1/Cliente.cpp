
#include "Cliente.h"

Cliente::Cliente(std::string ipv4)
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(8080);
    serverAdress.sin_addr.s_addr = inet_addr(ipv4.c_str());

    connect(clientSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress));

    const char* message = "Ola";
    send(clientSocket, message, strlen(message), 0);

    close(clientSocket);
}