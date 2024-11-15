#ifndef LISTADEADJACENCIAS_H
#define LISTADEADJACENCIAS_H

#include "Vertice.h"

//Para manipular o grafo
class ListaDeAdjacencias
{
private:
    //Lista de adjacencias
    std::vector<Vertice> _listaAdj;

    //Funcoes internas

    //Encontra onde o ser vivo esta, avisando se ele nao estiver
    int EncontrarSerVivo(std::string nome) const;
    //Encontra onde o ser vivo deve ser inserido
    int EncontrarPosInsercao(std::string nome) const;
    //Para fazer a contagem de ciclos no grafo
    int ContarCirculos(std::vector<std::string>* brancos, std::vector<std::string>* cinzas, int serVivoAtual) const;

public:
    //Construtor com arquivo de entrada
    ListaDeAdjacencias(std::fstream &arqEntrada);
    //Destrutor
    ~ListaDeAdjacencias();

    //Para encontrar os predadores da presa
    std::vector<std::string> FindPredadores(std::string nome) const;
    //Para iniciar a contagem de ciclos
    int ContarQuantidadeCiclos() const;

    //Para imprimir os dados
    friend std::ostream& operator<<(std::ostream& out, const ListaDeAdjacencias& lista);
};

#endif // LISTADEADJACENCIAS_H
