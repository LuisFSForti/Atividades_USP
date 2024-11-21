//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 3 de ED3

#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

#include "Aresta.h"

//Para armazenar as informa��es dos vertices
class Vertice
{
private:
    //Os dados do vertice
    SerVivo _origem;
    //A lista de arestas
    std::vector<Aresta> _listaAlimentos;
    //Informa��es dos graus
    int _grauDeEntrada, _grauDeSaida, _grau;

public:
    //Cria um v�rtice com um SerVivo
    Vertice(SerVivo serVivo);
    //Destrutor da classe
    virtual ~Vertice();

    //Para adicioanr presas
    void IncluirAlimento(Aresta aresta);
    //Para verificar se preda o ser vivo
    bool AlimentaDe(std::string nome) const;

    //Para imprimir os dados
    friend std::ostream& operator<<(std::ostream& out, const Vertice& vert);

    //Para ter um v�rtice sem arestas, importante para calcular o grafo transposto
    //Esta fun��o tambem aceita um SerVivo como parametro, pois Aresta tem um construtor com SerVivo
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
