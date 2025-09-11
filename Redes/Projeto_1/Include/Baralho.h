#include "Carta.h"

#ifndef BARALHO_H
#define BARALHO_H

class Baralho
{
private:
    std::vector<Carta> _cartas;

public:
    Baralho();

    Carta PegarCarta();
    Carta QueimarCarta();
};

#endif // BARALHO_H