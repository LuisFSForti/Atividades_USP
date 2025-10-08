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

#include "json.hpp"
#include "Carta.h"

#ifndef SERVIDOR_H
#define SERVIDOR_H

#define timeoutMensagens 1000

//Para relacionar o número do socket com sua respectiva thread
struct DadosSocket
{
    int socket;
    std::thread thread;
};

class Servidor
{
private:
    int _serverSocket;
    std::atomic<bool> _stopAccepting, _servidorFechou;

    std::thread _threadAccept;

    std::vector<DadosSocket> _threadsConexoes;
    std::vector<int> _clientsAccepted, _clientsClosed;

    std::mutex _controle;

    std::map<int, std::vector<nlohmann::json>> _mensagensClientes;

    void AcceptClients();
    void CheckOnClient(int clientSocket);

public:
    Servidor(std::string ipv4);
    ~Servidor();

    void SendClientMessage(int clientSocket, nlohmann::json msg);
    void BroadcastMessage(nlohmann::json msg);
    nlohmann::json GetClientMessage(int clientSocket);

    void AdicionarClienteParaRemocao(int clientSocket);
    void CloseDeadThreads();
    void StopAccpetingClients();
    void FecharServidor();

    std::vector<int> GetNewSockets();
    std::vector<int> GetClosedSockets();
    bool ServerOpen();
};

#endif // SERVIDOR_H