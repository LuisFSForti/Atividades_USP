#include <string>
#include <iostream>
#include <algorithm>
#include <array>
#include <cstdlib>

#include "json.hpp"

#define ouros 'O'
#define espadas 'E'
#define copas 'C'
#define paus 'P'

#ifndef REFERENCIAVALORES
#define REFERENCIAVALORES

static const std::array<std::string, 13> referenciaValores = 
    {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

#endif //REFERENCIAVALORES

#ifndef REFERENCIANAIPES
#define REFERENCIANAIPES

static const std::array<char, 4> referenciaNaipes = 
    {ouros, copas, espadas, paus};

#endif //REFERENCIANAIPES

#ifndef CARTA_H
#define CARTA_H

class Carta
{
private:
    std::string _valor;
    char _naipe;

public:
    Carta(std::string valor, char naipe);
    Carta(nlohmann::json json);
    nlohmann::json ToJson();

    friend bool operator>(const Carta& a, const Carta& b);
    friend bool operator==(const Carta& a, const Carta &b);
    friend std::ostream& operator<<(std::ostream &out, const Carta &a);
};

#endif // CARTA_H