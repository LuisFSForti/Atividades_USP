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

class Servidor
{
private:
    int _serverSocket;
    std::atomic<bool> _servidorFechou;
    std::vector<std::thread> _threadsConexoes;

public:
    Servidor(std::string ipv4);
    void FecharServidor();
};