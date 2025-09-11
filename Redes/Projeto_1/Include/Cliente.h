#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <thread>
#include <atomic>

#include "Carta.h"

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente
{
private:
    int _serverSocket;
    std::atomic<bool> _servidorFechou, _clienteFechou;
    std::thread _threadConexao;

public:
    Cliente(std::string ipv4);
    ~Cliente();
    void CheckOnServer();
    void FecharCliente();
};

#endif // CLIENTE_H