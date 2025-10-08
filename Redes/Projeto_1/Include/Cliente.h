#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <thread>
#include <atomic>
#include <mutex>

#include "json.hpp"
#include "Carta.h"

#define timeoutMensagens 1000

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente
{
private:
    int _serverSocket;
    std::atomic<bool> _clienteFechou;
    std::thread _threadConexao;

    std::mutex _controle;

    std::vector<nlohmann::json> _mensagensServidor;

    void CheckOnServer();

public:
    Cliente(std::string ipv4);
    ~Cliente();

    void SendServerMessage(nlohmann::json msg);
    nlohmann::json GetServerMessage();

    void FecharCliente();

    bool ConnectionOpen();
};

#endif // CLIENTE_H