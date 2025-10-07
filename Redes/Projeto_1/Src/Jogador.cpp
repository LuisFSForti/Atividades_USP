#include "Jogador.h"

Jogador::Jogador()
{
    //Valor de jogador não-inicializado
    this->_valorFichas = -1;
}

Jogador::Jogador(Carta carta1, Carta carta2, int fichasIniciais)
{
    this->_mao[0] = carta1;
    this->_mao[1] = carta2;

    this->_valorFichas = fichasIniciais;
}

Jogador::Jogador(nlohmann::json json)
{
    this->_mao[0] = Carta(json["Carta1"]);
    this->_mao[1] = Carta(json["Carta2"]);
}

void Jogador::TrocarMao(Carta carta1, Carta carta2)
{
    this->_mao[0] = carta1;
    this->_mao[1] = carta2;
}

void Jogador::Apostar(int quantidade)
{
    if(quantidade > this->_valorFichas)
        throw std::runtime_error("Valor inválido de fichas!");

    this->_valorFichas -= quantidade;
}

void Jogador::Coletar(int quantidade)
{
    this->_valorFichas += quantidade;
}

int Jogador::FichasRestantes()
{
    return this->_valorFichas;
}

nlohmann::json Jogador::ToJson()
{
    nlohmann::json aux;

    aux["Cod"] = "Jogador";
    aux["Carta1"] = _mao[0].ToJson();
    aux["Carta2"] = _mao[1].ToJson();
    aux["Fichas"] = _valorFichas;

    return aux;
}

Carta* Jogador::GetMao()
{
    return _mao;
}

std::ostream& operator<<(std::ostream &out, const Jogador &a)
{
    out << a._valorFichas << " fichas" << std::endl;

    for(Carta cart : a._mao)
        out << cart << std::endl;

    return out;
}