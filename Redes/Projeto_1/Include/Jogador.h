#include <random>

#include "json.hpp"
#include "Carta.h"

#ifndef JOGADOR_H
#define JOGADOR_H

class Jogador
{
private:
    std::vector<Carta> _mao;
    int _valorFichas;

public:
    Jogador();
    Jogador(Carta carta1, Carta carta2, int fichasIniciais);
    Jogador(nlohmann::json json);

    void ComprarCarta(Carta carta);
    void TrocarMao(Carta carta1, Carta carta2);
    void Apostar(int quantidade);
    void Coletar(int quantidade);

    int FichasRestantes();

    nlohmann::json ToJson();

    friend std::ostream& operator<<(std::ostream &out, const Jogador &a);
};

#endif // JOGADOR_H