//Luís Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 3 de ED3

#include <iostream>
#include <fstream>

#include "SerVivo.h"
#include "ListaDeAdjacencias.h"

int main()
{
    //Código da função
    int cod;
    //Endereço do arquivo
    std::string endereco;

    //Pega os dados
    std::cin >> cod >> endereco;

    //Abre o arquivo no modo de leitura binária
    std::fstream arq(endereco, std::ios::in|std::ios::binary);

    //Se falhou em abrir
    if(!arq.is_open())
    {
        std::cout << "Falha no processamento do arquivo.";
        return 0;
    }

    //Cria o grafo
    ListaDeAdjacencias lista(arq);
    //Fecha o arquivo
    arq.close();

    //Para cada função
    switch(cod)
    {
    case 10:
        {
            //Imprime o grafo
            std::cout << lista;

            break;
        }

    case 11:
        {
            //Lê a quantidade de pesquisas
            std::cin >> cod;

            //Pega todos os nomes à serem pesquisados
            getline(std::cin, endereco);

            //Remove as aspas iniciais
            endereco.erase(0, endereco.find("\"") + 1);

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

                //Se não tiver predadores
                if(predadores.size() == 0)
                {
                    //Alerta
                    std::cout << "Registro Inexistente.";
                }
                //Se tiver predadores
                else
                {
                    //Escreve o nome da presa
                    std::cout << nome + ": ";

                    //Para cada predador
                    for(auto& predador : predadores)
                    {
                        //Escreve o nome do predador
                        std::cout << predador;

                        //Se ele não for o ultimo
                        if(predador != predadores.back())
                            //Adiciona uma vírgula
                            std::cout << ", ";
                    }
                }

                std::cout << std::endl << std::endl;
            }

            break;
        }
    case 12:
        {
            //Calcula a quantidade de ciclos e imprime
            std::cout << "Quantidade de ciclos: " << lista.ContarQuantidadeCiclos();

            break;
        }
    case 13:
        {
            //Calcula a quantidade de componentes complexos
            int qtdComponentesConexos = lista.CalcularComponentesConexos();

            //Se tiver um único componente complexo
            if(qtdComponentesConexos == 0)
            {
                //Então é fortemente conexo
                std::cout << "Sim, o grafo é fortemente conexo e possui " << qtdComponentesConexos << " componente.";
            }
            //Se tiver mais que 1
            else
            {
                //Então não é fortemente conexo
                std::cout << "Não, o grafo não é fortemente conexo e possui " << qtdComponentesConexos << " componentes.";
            }

            break;
        }
    case 14:
        {
            //Le a quantidade de pesquisas
            std::cin >> cod;

            //Pega todos os nomes de pesquisas
            getline(std::cin, endereco);

            //Apaga tudo até as primeiras aspas
            endereco.erase(0, endereco.find("\"") + 1);

            //Para cada pesquisa
            for(int i = 0; i < cod; i++)
            {
                //nomes[0] -> predados
                //nomes[1] -> presa
                std::string nomes[2];

                //Para pegar o par de nomes
                for(int i = 0; i < 2; i++)
                {
                    //Pega o nome do predador/presa
                    nomes[i] = endereco.substr(0, endereco.find("\""));
                    //Remove as aspas finais do nome
                    endereco.erase(0, endereco.find("\"") + 1);
                    //Remove as aspas iniciais do proximo nome
                    endereco.erase(0, endereco.find("\"") + 1);
                }

                //Calcula o risco da presa em relação ao predador
                int resultado = lista.CalcularRisco(nomes[0], nomes[1]);

                //Imprime os nomes do predador e da presa
                std::cout << nomes[0] + " " + nomes[1] + ": ";

                //Se um dos nomes não estiver no grafo
                //ou a presa não foi iterada, ou seja, não tem conexão entre predador e presa
                if(resultado == -1 || resultado == INT_MAX)
                {
                    //Imprime caminho inexistente
                    std::cout  << "CAMINHO INEXISTENTE" << std::endl;
                }
                //Se ambos existem no grafo e há um caminho entre eles
                else
                {
                    //Imprime o resultado
                    std::cout << resultado << std::endl;
                }


            }

            break;
        }
    }

    return 0;
}
