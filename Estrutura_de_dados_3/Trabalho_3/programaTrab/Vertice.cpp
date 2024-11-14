#include "Vertice.h"

Vertice::Vertice(Dinossauro dino)
{
    this->_origem = Dinossauro(dino);

    Aresta aresta(dino.Alimento(), dino.Populacao());
    this->_listaAlimentos.insert(this->_listaAlimentos.begin(), aresta);

    this->_grauDeSaida = 1;
    this->_grau = 1;
    this->_grauDeEntrada = 0;
}

Vertice::~Vertice()
{
    this->_listaAlimentos.clear();
}

void Vertice::IncluirAlimento(Dinossauro dino)
{
    Aresta aresta(dino.Alimento(), dino.Populacao());

    for(int i = 0; i < this->_listaAlimentos.size(); i++)
    {
        int relacao = dino.Alimento().compare(this->_listaAlimentos.at(i).Valor());

        if(relacao == 0)
            return;

        if(relacao < 0)
        {
            this->_listaAlimentos.insert(this->_listaAlimentos.begin() + i, aresta);
            this->_grauDeSaida++;
            this->_grau++;
            return;
        }
    }

    this->_listaAlimentos.push_back(aresta);
    this->_grauDeSaida++;
    this->_grau++;
}

bool Vertice::AlimentaDe(std::string nome)
{
    for(auto const& aresta : this->_listaAlimentos)
    {
        if(nome.compare(aresta.Valor()) == 0)
            return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Vertice& vert)
{
    for(const auto& aresta : vert._listaAlimentos)
    {
        out <<  vert._origem.Nome() + " " + vert._origem.Especie() + " " + vert._origem.Habitat() + " " + vert._origem.Dieta() + " " + vert._origem.Tipo() + " " +
            std::to_string(vert._grauDeEntrada) + " " + std::to_string(vert._grauDeSaida) + " " + std::to_string(vert._grau);

        out << " " << aresta << std::endl;
    }

    return out;
}

Dinossauro Vertice::Origem() const
{
    return this->_origem;
}

std::vector<Aresta> Vertice::ListaAlimentos() const
{
    return this->_listaAlimentos;
}

void Vertice::SetGrauDeEntrada(int valor)
{
    this->_grau = this->_grauDeSaida + valor;
    this->_grauDeEntrada = valor;
}

int Vertice::GrauDeEntrada() const
{
    return this->_grauDeEntrada;
}

int Vertice::GrauDeSaida() const
{
    return this->_grauDeSaida;
}

int Vertice::Grau() const
{
    return this->_grau;
}

