//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 3 de ED3

#include "Aresta.h"

//Construtor com nome e quantidade
Aresta::Aresta(std::string valor, int peso)
{
    this->_valor = valor;
    this->_peso = peso;
}

//Construtor com dados do predador
Aresta::Aresta(SerVivo serVivo)
{
    //Salva a presa e a população do predador
    this->_valor = serVivo.Alimento();
    this->_peso = serVivo.Populacao();
}

//Para imprimir os dados da aresta
std::ostream& operator<<(std::ostream& out, const Aresta& arest)
{
    out << arest._valor << " " << arest._peso;

    return out;
}

//Para pegar as informações nas outras classes
std::string Aresta::Valor() const
{
    return this->_valor;
}

int Aresta::Peso() const
{
    return this->_peso;
}
