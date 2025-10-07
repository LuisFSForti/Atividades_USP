#include <random>

#include "json.hpp"
#include "Carta.h"

#define codJogador "Jogador"

#ifndef JOGADOR_H
#define JOGADOR_H

class Jogador
{
private:
    Carta _mao[2];
    int _valorFichas;
    std::string _nome;

public:
    Jogador(Carta carta1 = Carta(), Carta carta2 = Carta(), int fichasIniciais = -1, std::string nome = "");
    Jogador(nlohmann::json json);

    void TrocarMao(Carta carta1, Carta carta2);
    void Apostar(int quantidade);
    void Coletar(int quantidade);

    int FichasRestantes();
    Carta* GetMao();
    std::string GetNome();

    nlohmann::json ToJson();


    friend std::ostream& operator<<(std::ostream &out, const Jogador &a);
};

#endif // JOGADOR_H