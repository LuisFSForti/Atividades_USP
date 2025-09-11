#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <atomic>
#include <thread>
#include <vector>
#include <mutex>

#include "Carta.h"

#define timeoutMensagens 1000

#ifndef SERVIDOR_H
#define SERVIDOR_H

class Servidor
{
private:
    int _serverSocket;
    std::atomic<bool> _stopAccepting, _servidorFechou;
    std::thread _threadAccept;
    std::vector<std::thread> _threadsConexoes;
    std::vector<int> _threadsMortas;
    std::mutex _controle;

public:
    Servidor(std::string ipv4);
    ~Servidor();
    void AcceptClients();
    void CheckOnClient(int clientSocket);
    void FecharServidor();
};

#endif // SERVIDOR_H