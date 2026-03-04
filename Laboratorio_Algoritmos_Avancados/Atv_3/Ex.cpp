//Luís Filipe Silva Forti - 14592348

#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    int nroServers = 0, nroCasos = 0;
    std::unordered_map<std::string, std::string> servers;
    std::string nome, ip, comando;

    std::cin >> nroServers;
    std::cin >> nroCasos;
    
    //Salva os detalhes de cada servidor no mapa
    //Ip -> nome
    for (int i = 0; i < nroServers; ++i)
    {
        std::cin >> nome;
        std::cin >> ip;
        servers[ip] = nome;
    }

    //Para cada comando
    for (int i = 0; i < nroCasos; ++i)
    {
        //Pega os detalhes do comando
        std::cin >> comando;
        std::cin >> ip;

        //Remove o caractere ';', para poder acessar o mapa
        ip.pop_back();

        //Imprime o comando com o nome do servidor
        //Como todo comando é obrigatoriamente em um servidor existente, não é necessário verificar
        std::cout << comando << " " << ip << "; #" << servers[ip] << std::endl;
    }

    return 0;
}