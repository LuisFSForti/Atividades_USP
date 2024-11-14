#ifndef LISTADEADJACENCIAS_H
#define LISTADEADJACENCIAS_H

#include "Vertice.h"

class ListaDeAdjacencias
{
private:
    std::list<Vertice> _listaAdj;

    int EncontrarDino(std::string nome);
    int EncontrarPosInsercao(std::string nome);
    void CalcularQuantidadeEntradas(std::string nome);

public:
    ListaDeAdjacencias(std::fstream &arqEntrada);
    ~ListaDeAdjacencias();

    friend std::ostream& operator<<(std::ostream& out, const ListaDeAdjacencias& lista);
};

#endif // LISTADEADJACENCIAS_H
