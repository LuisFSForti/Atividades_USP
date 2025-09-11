#include "Baralho.h"

Baralho::Baralho()
{
    this->_cartas = std::vector<Carta>();

    for(char naipe : referenciaNaipes)
    {
        for(std::string val : referenciaValores)
        {
            this->_cartas.emplace_back(Carta(val, naipe));
            std::cout << this->_cartas[this->_cartas.size() - 1] << std::endl;
        }
    }
}

Carta Baralho::PegarCarta()
{
    
}

Carta BaralhoQueimarCarta()
{

}