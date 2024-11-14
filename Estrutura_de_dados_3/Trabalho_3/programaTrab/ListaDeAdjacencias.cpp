#include "ListaDeAdjacencias.h"

ListaDeAdjacencias::ListaDeAdjacencias(std::fstream &arqEntrada)
{
    char status;
    arqEntrada.read(&status, sizeof(char));

    if(status == '0')
    {
        std::cout << "Falha no processamento do arquivo.";
        arqEntrada.close();
        return;
    }

    int qtd;
    arqEntrada.seekg(sizeof(char) + sizeof(int));
    arqEntrada.read((char*)&qtd, sizeof(int));
    arqEntrada.seekg(1600);

    for(int i = 0; i < qtd * 160; i += 160)
    {
        Dinossauro dino(arqEntrada);

        int posDino = this->EncontrarPosInsercao(dino.Nome());
        auto posInsercao = this->_listaAdj.begin();
        std::advance(posInsercao, posDino-1);

        if(this->EncontrarDino(dino.Nome()) == -1)
        {
            this->_listaAdj.insert(posInsercao, Vertice(dino));
            continue;
        }

        std::advance(posInsercao, 1);
        posInsercao->IncluirAlimento(dino);
    }

    for(auto& atual : this->_listaAdj)
    {
        this->CalcularQuantidadeEntradas(atual.Origem().Nome());
    }
}

ListaDeAdjacencias::~ListaDeAdjacencias()
{
    this->_listaAdj.clear();
}

int ListaDeAdjacencias::EncontrarDino(std::string nome)
{
    auto atual = this->_listaAdj.begin();
    for(int i = 0; atual != this->_listaAdj.end(); i++, std::advance(atual, 1))
    {
        int relacao = nome.compare(atual->Origem().Nome());
        if(relacao == 0)
        {
            return i;
        }
        if(relacao < 0)
        {
            return -1;
        }
    }

    return -1;
}


int ListaDeAdjacencias::EncontrarPosInsercao(std::string nome)
{
    auto atual = this->_listaAdj.begin();
    for(int i = 0; atual != this->_listaAdj.end(); i++, std::advance(atual, 1))
    {
        if(nome.compare(atual->Origem().Nome()) <= 0)
        {
            return i;
        }
    }

    return this->_listaAdj.size() + 1;
}

void ListaDeAdjacencias::CalcularQuantidadeEntradas(std::string nome)
{
    int qtd = 0, pos = 0;
    auto posV = this->_listaAdj.begin();

    for(auto& atual : this->_listaAdj)
    {
        if(nome.compare(atual.Origem().Nome()) == 0)
        {
            std::advance(posV, pos);
            continue;
        }
        pos++;

        if(atual.AlimentaDe(nome))
            qtd++;
    }
    posV->SetGrauDeEntrada(qtd);
}

std::ostream& operator<<(std::ostream& out, const ListaDeAdjacencias& lista)
{
    for(auto const& atual : lista._listaAdj)
    {
        out << atual;
    }

    return out;
}
