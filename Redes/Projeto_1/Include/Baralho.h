#include "Carta.h"
#include <random>

#ifndef BARALHO_H
#define BARALHO_H

class Baralho
{
private:
    std::vector<Carta> _cartas;

    int IndiceCartaAleatoria();

public:
    Baralho();

    int CartasRestantes();

    Carta PegarCarta();
    void QueimarCarta();
};

#endif // BARALHO_H