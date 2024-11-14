#ifndef LISTADEADJACENCIAS_H
#define LISTADEADJACENCIAS_H

#include "Vertice.h"

class ListaDeAdjacencias
{
private:
    std::vector<Vertice> _listaAdj;

    int EncontrarDino(std::string nome);
    int EncontrarPosInsercao(std::string nome);
    int ContarCirculos(std::vector<std::string>* brancos, std::vector<std::string>* cinzas, int dinoAtual);

public:
    ListaDeAdjacencias(std::fstream &arqEntrada);
    ~ListaDeAdjacencias();

    std::vector<std::string> FindPredadores(std::string nome);
    int ContarQuantidadeCiclos();

    friend std::ostream& operator<<(std::ostream& out, const ListaDeAdjacencias& lista);
};

#endif // LISTADEADJACENCIAS_H
