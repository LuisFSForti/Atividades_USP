#include "Jogador.h"

Jogador::Jogador(Carta carta1, Carta carta2, int fichasIniciais, std::string nome)
{
    this->_mao[0] = carta1;
    this->_mao[1] = carta2;

    this->_valorFichas = fichasIniciais;
    this->_nome = nome;
}

Jogador::Jogador(nlohmann::json json)
{
    this->_mao[0] = Carta(json["Carta1"]);
    this->_mao[1] = Carta(json["Carta2"]);
    this->_valorFichas = json["Fichas"].get<int>();
    this->_nome = json["Nome"];
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

std::string Jogador::GetNome()
{
    return this->_nome;
}

nlohmann::json Jogador::ToJson()
{
    nlohmann::json aux;

    aux["Cod"] = codJogador;
    aux["Carta1"] = _mao[0].ToJson();
    aux["Carta2"] = _mao[1].ToJson();
    aux["Fichas"] = _valorFichas;
    aux["Nome"] = _nome;

    return aux;
}

Carta* Jogador::GetMao()
{
    return _mao;
}

std::ostream& operator<<(std::ostream &out, const Jogador &a)
{
    out << a._nome << ": " << std::endl;
    out << a._valorFichas << " fichas" << std::endl;

    for(Carta cart : a._mao)
        out << cart << std::endl;

    return out;
}