#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

#include "Dinossauro.h"
#include "Aresta.h"

class Vertice
{
private:
    Dinossauro _origem;
    std::vector<Aresta> _listaAlimentos;
    int _grauDeEntrada, _grauDeSaida, _grau;

public:
    Vertice(Dinossauro dino);
    virtual ~Vertice();

    void IncluirAlimento(Dinossauro dino);
    bool AlimentaDe(std::string nome);

    friend std::ostream& operator<<(std::ostream& out, const Vertice& vert);

    Dinossauro Origem() const;
    std::vector<Aresta> ListaAlimentos() const;
    void SetGrauDeEntrada(int valor);
    int GrauDeEntrada() const;
    int GrauDeSaida() const;
    int Grau() const;
};

#endif // VERTICE_H
