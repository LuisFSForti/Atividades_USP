#include <iostream>
#include <fstream>

#include "SerVivo.h"
#include "ListaDeAdjacencias.h"

int main()
{
    //Codigo da funcao
    int cod;
    //Endereco do arquivo
    std::string endereco;

    //Pega os dados
    std::cin >> cod >> endereco;

    //Abre o arquivo no modo de leitura binaria
    std::fstream arq(endereco, std::ios::in|std::ios::binary);

    //Se falhou em abrir
    if(!arq.is_open())
    {
        std::cout << "Falha no processamento do arquivo.";
        return 0;
    }

    //Para cada funcao
    switch(cod)
    {
    case 10:
        {
            //Cria o grafo
            ListaDeAdjacencias lista(arq);
            arq.close();

            //Imprime o grafo
            std::cout << lista;

            break;
        }

    case 11:
        {
            //Cria o grafo
            ListaDeAdjacencias lista(arq);
            arq.close();

            //Le a quantidade de pesquisas
            std::cin >> cod;

            //Pega todos os nomes de pesquisas
            getline(std::cin, endereco);

            //Copia tudo depois da primeira aspas
            endereco = endereco.substr(endereco.find("\"") + 1, endereco.length() - endereco.find("\"") - 1);

            //Para cada pesquisa
            for(int i = 0; i < cod; i++)
            {
                //Pega o nome
                std::string nome = endereco.substr(0, endereco.find("\""));
                //Remove as aspas finais do nome
                endereco.erase(0, endereco.find("\"") + 1);
                //Remove as aspas iniciais do proximo nome
                endereco.erase(0, endereco.find("\"") + 1);

                //Pega os predadores
                std::vector<std::string> predadores = lista.FindPredadores(nome);

                //Se nao tiver predadores
                if(predadores.size() == 0)
                {
                    //Alerta
                    std::cout << "Registro Inexistente.";
                    std::cout << std::endl << std::endl;

                    //Pula pra proxima pesquisa
                    continue;
                }

                //Se tiver predadores
                //Escreve o nome da presa
                std::cout << nome + ": ";

                //Para cada predador
                for(auto& predador : predadores)
                {
                    //Escreve o nome do predador
                    std::cout << predador;

                    //Se ele nao for o ultimo
                    if(predador != predadores.back())
                        //Adiciona uma virgula
                        std::cout << ", ";
                }

                std::cout << std::endl << std::endl;
            }

            break;
        }
    case 12:
        {
            //Cria o grafo
            ListaDeAdjacencias lista(arq);
            arq.close();

            //Calcula a quantidade de ciclos
            std::cout << "Quantidade de ciclos: " << lista.ContarQuantidadeCiclos();

            break;
        }
    case 13:
        {
            //Cria o grafo
            ListaDeAdjacencias lista(arq);
            arq.close();

            int qtdComponentesConexos = lista.CalcularComponentesConexos();

            if(qtdComponentesConexos == 0)
            {
                std::cout << "Sim, o grafo é fortemente conexo e possui " << qtdComponentesConexos << " componente.";
            }
            else
            {
                std::cout << "Não, o grafo não é fortemente conexo e possui " << qtdComponentesConexos << " componentes.";
            }

            break;
        }
    }

    return 0;
}
