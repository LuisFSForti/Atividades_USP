#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

#include "Aresta.h"

//Para armazenar as informacoes dos vertices
class Vertice
{
private:
    //Os dados do vertice
    SerVivo _origem;
    //A lista de arestas
    std::vector<Aresta> _listaAlimentos;
    //Informacoes dos graus
    int _grauDeEntrada, _grauDeSaida, _grau;

public:
    //Cria um vertice com um SerVivo
    Vertice(SerVivo serVivo);
    //Destrutor da classe
    virtual ~Vertice();

    //Para adicioanr presas
    void IncluirAlimento(Aresta aresta);
    //Para verificar se preda o ser vivo
    bool AlimentaDe(std::string nome) const;

    //Para imprimir os dados
    friend std::ostream& operator<<(std::ostream& out, const Vertice& vert);

    //Para ter um vertice sem arestas, importante para calcular o grafo transposto
    //Esta funcao tambem aceita um SerVivo como parametro, pois Aresta tem um construtor com SerVivo
    void LimparArestas();
    //Para definir os graus
    void SetGrauDeEntrada(int valor);
    void SetGrauDeSaida(int valor);

    //Para pegar as informacoes nas outras classes
    SerVivo Origem() const;
    std::vector<Aresta> ListaAlimentos() const;
    int GrauDeEntrada() const;
    int GrauDeSaida() const;
    int Grau() const;
};

#endif // VERTICE_H
