//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 3 de ED3

#ifndef LISTADEADJACENCIAS_H
#define LISTADEADJACENCIAS_H

#include <limits.h>

#include "Vertice.h"

//Para manipular o grafo
class ListaDeAdjacencias
{
private:
    //Lista de adjacencias
    std::vector<Vertice> _listaAdj;

    //Funcoes internas

    ListaDeAdjacencias();

    //Encontra onde o ser vivo esta, avisando se ele nao estiver
    int EncontrarSerVivo(std::string nome) const;
    //Encontra onde o ser vivo deve ser inserido
    int EncontrarPosInsercao(std::string nome) const;
    //Para fazer a contagem de ciclos no grafo
    int ContarCirculos(std::vector<std::string>* brancos, std::vector<std::string>* cinzas, int verticeAtual) const;
    //Retorna o grafo transposto, para o calculo de componentes conexos
    ListaDeAdjacencias GrafoTransposto() const;
    //Para calcular a quantidade de componentes conexos
    void ContarComponentes(std::vector<std::string>* naoVerificados, std::vector<std::string>* pilha, int verticeAtual);

public:
    //Construtor com arquivo de entrada
    ListaDeAdjacencias(std::fstream &arqEntrada);
    //Destrutor
    ~ListaDeAdjacencias();

    //Para encontrar os predadores da presa
    std::vector<std::string> FindPredadores(std::string nome) const;
    //Para iniciar a contagem de ciclos
    int ContarQuantidadeCiclos() const;
    //Para calcular a quantidade de componentes conexos
    int CalcularComponentesConexos();
    int CalcularRisco(std::string predador, std::string presa);

    //Para imprimir os dados
    friend std::ostream& operator<<(std::ostream& out, const ListaDeAdjacencias& lista);
};

#endif // LISTADEADJACENCIAS_H
