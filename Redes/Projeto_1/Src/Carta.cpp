#include "Carta.h"

Carta::Carta(std::string valor, char naipe)
{
    //valor == "N" -> carta neutra, inválida
    if(valor != "N")
    {
        auto pos1 = std::find(referenciaValores.begin(), referenciaValores.end(), valor);

        if(pos1 == referenciaValores.end())
        {
            std::cerr << "Valor da carta inválido!" << std::endl;
            exit(EXIT_FAILURE);
        }

        auto pos2 = std::find(referenciaNaipes.begin(), referenciaNaipes.end(), naipe);

        if(pos2 == referenciaNaipes.end())
        {
            std::cerr << "Naipe da carta inválido!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    this->_valor = valor;
    this->_naipe = naipe;
}

Carta::Carta(nlohmann::json json)
{
    *this = Carta(json["Valor"].get<std::string>(), json["Naipe"].get<char>());
}

nlohmann::json Carta::ToJson()
{
    //Se for uma carta inválida
    if(_valor == "N")
    {
        std::cerr << "Valor da carta inválido!" << std::endl;
        exit(EXIT_FAILURE);
    }

    nlohmann::json aux;

    aux["Cod"] = "Carta";
    aux["Valor"] = _valor;
    aux["Naipe"] = _naipe;

    return aux;
}

std::string Carta::GetValue()
{
    //Se for uma carta inválida
    if(_valor == "N")
    {
        std::cerr << "Valor da carta inválido!" << std::endl;
        exit(EXIT_FAILURE);
    }

    return _valor;
}

char Carta::GetNaipe()
{
    //Se for uma carta inválida
    if(_valor == "N")
    {
        std::cerr << "Valor da carta inválido!" << std::endl;
        exit(EXIT_FAILURE);
    }

    return _naipe;
}

bool Carta::EhSequencia(Carta outra)
{
    //Se for uma carta inválida
    if(_valor == "N")
    {
        return false;
    }

    int idx = std::distance(referenciaValores.begin(), 
        std::find(referenciaValores.begin(), referenciaValores.end(), _valor));

    if(idx == 0)
        return false;

    return outra._valor == referenciaValores[idx-1];
}

bool operator>(const Carta& a, const Carta& b)
{
    //Se for uma carta inválida
    if(a._valor == "N")
    {
        return false;
    }
    if(b._valor == "N")
    {
        return true;
    }

    auto pos1 = std::find(referenciaValores.begin(), referenciaValores.end(), a._valor);
    auto pos2 = std::find(referenciaValores.begin(), referenciaValores.end(), b._valor);

    int idx1 = pos1 - referenciaValores.begin();
    int idx2 = pos2 - referenciaValores.begin();

    return idx1 > idx2;
}

bool operator==(const Carta& a, const Carta &b)
{
    //Se for uma carta inválida
    if(a._valor == "N" || b._valor == "N")
    {
        return false;
    }

    return (a._valor == b._valor) && (a._naipe == b._naipe);
}

std::ostream& operator<<(std::ostream &out, const Carta &a)
{
    //Se for uma carta inválida
    if(a._valor == "N")
    {
        std::cerr << "Valor da carta inválido!" << std::endl;
        exit(EXIT_FAILURE);
    }

    out << a._valor << " de ";

    switch (a._naipe)
    {
    case ouros:
        out << "ouros";
        break;
    
    case copas:
        out << "copas";
        break;

    case paus:
        out << "paus";
        break;

    case espadas:
        out << "espadas";
        break;

    default:
        break;
    }

    return out;
}