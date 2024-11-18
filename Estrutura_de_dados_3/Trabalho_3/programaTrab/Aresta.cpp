#include "Aresta.h"

//Construtor com nome e quantidade
Aresta::Aresta(std::string valor, int peso)
{
    this->_valor = valor;
    this->_peso = peso;
}

Aresta::Aresta(SerVivo serVivo)
{
    this->_valor = serVivo.Alimento();
    this->_peso = serVivo.Populacao();
}

//Para imprimir os dados da aresta
std::ostream& operator<<(std::ostream& out, const Aresta& arest)
{
    out << arest._valor << " " << arest._peso;

    return out;
}

//Para pegar as informacoes nas outras classes
std::string Aresta::Valor() const
{
    return this->_valor;
}

int Aresta::Peso() const
{
    return this->_peso;
}
