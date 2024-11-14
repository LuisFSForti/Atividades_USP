#include "Aresta.h"

Aresta::Aresta(std::string valor, int peso)
{
    this->_valor = valor;
    this->_peso = peso;
}

std::string Aresta::Valor() const
{
    return this->_valor;
}

int Aresta::Peso() const
{
    return this->_peso;
}

std::ostream& operator<<(std::ostream& out, const Aresta& arest)
{
    out << arest._valor << " " << arest._peso;

    return out;
}
