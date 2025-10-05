#include "Baralho.h"

Baralho::Baralho()
{
    this->_cartas = std::vector<Carta>();

    for(char naipe : referenciaNaipes)
    {
        for(std::string val : referenciaValores)
        {
            this->_cartas.emplace_back(Carta(val, naipe));
        }
    }
}

int Baralho::IndiceCartaAleatoria()
{
    if(this->_cartas.size() == 0)
        throw std::runtime_error("Tentou pegar carta do baralho vazio!");

    //Configura gerador de números aleatórios
    std::random_device dev;
    std::mt19937 rng(dev());
    //De 0 ao tamanho do baralho-1
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, this->_cartas.size()-1);
    
    return dist6(rng);
}

Carta Baralho::PegarCarta()
{
    int nroRand = IndiceCartaAleatoria();

    //Separa a carta e exclui ela do baralho
    Carta cartaEscolhida = this->_cartas[nroRand];
    this->_cartas.erase(this->_cartas.begin() + nroRand);

    return cartaEscolhida;
}

void Baralho::QueimarCarta()
{
    int nroRand = IndiceCartaAleatoria();

    //Exclui a carta do baralho
    this->_cartas.erase(this->_cartas.begin() + nroRand);
}

int Baralho::CartasRestantes()
{
    return this->_cartas.size();
}