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

#define timeoutMensagens 1000

class Servidor
{
private:
    int _serverSocket;
    std::atomic<bool> _stopAccepting, _servidorFechou;
    std::thread _threadAccept;
    std::vector<std::thread> _threadsConexoes;
    std::mutex _controle;

public:
    Servidor(std::string ipv4);
    void AcceptClients();
    void CheckOnClient(int clientSocket);
    void FecharServidor();
};