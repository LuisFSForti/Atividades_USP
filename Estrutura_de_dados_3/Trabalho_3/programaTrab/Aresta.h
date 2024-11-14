#ifndef ARESTA_H
#define ARESTA_H

#include <stdio.h>
#include <iostream>

class Aresta
{
private:
    std::string _valor;
    int _peso;
public:
    Aresta(std::string valor, int peso);

    std::string Valor() const;
    int Peso() const;

    friend std::ostream& operator<<(std::ostream& out, const Aresta& arest);
};

#endif // ARESTA_H
