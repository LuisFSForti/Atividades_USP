#include <iostream>
#include <fstream>

#include "Dinossauro.h"
#include "ListaDeAdjacencias.h"

int main()
{
    //std::fstream arq("binario1.bin", std::ios::in|std::ios::out|std::ios::binary);

    int cod;
    std::string endereco;

    std::cin >> cod >> endereco;

    std::fstream arq(endereco, std::ios::in|std::ios::binary);

    if(!arq.is_open())
    {
        std::cout << "Falha no processamento do arquivo.";
        return 0;
    }

    switch(cod)
    {
    case 10:
        {
            ListaDeAdjacencias lista(arq);
            arq.close();

            std::cout << lista;

            break;
        }

    case 11:
        {
            ListaDeAdjacencias lista(arq);
            arq.close();

            std::cin >> cod;
            getline(std::cin, endereco);
            //Copia tudo depois da primeira aspas
            endereco = endereco.substr(endereco.find("\"") + 1, endereco.length() - endereco.find("\"") - 1);

            for(int i = 0; i < cod; i++)
            {
                //Pega o nome
                std::string nome = endereco.substr(0, endereco.find("\""));
                //Remove as aspas finais do nome
                endereco.erase(0, endereco.find("\"") + 1);
                //Remove as aspas iniciais do próximo nome
                endereco.erase(0, endereco.find("\"") + 1);

                std::vector<std::string> predadores = lista.FindPredadores(nome);

                if(predadores.size() == 0)
                {
                    std::cout << "Registro Inexistente.";
                    std::cout << std::endl << std::endl;
                    continue;
                }

                std::cout << nome + ": ";
                for(auto& predador : predadores)
                {
                    std::cout << predador;

                    if(predador != predadores.back())
                        std::cout << ", ";
                }

                std::cout << std::endl << std::endl;
            }

            break;
        }
    case 12:
        {
            ListaDeAdjacencias lista(arq);
            arq.close();

            std::cout << "Quantidade de ciclos: " << lista.ContarQuantidadeCiclos();

            break;
        }
    }

    return 0;
}
