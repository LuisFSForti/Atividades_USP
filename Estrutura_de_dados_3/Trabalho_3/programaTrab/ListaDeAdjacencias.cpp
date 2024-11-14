#include "ListaDeAdjacencias.h"

ListaDeAdjacencias::ListaDeAdjacencias(std::fstream &arqEntrada)
{
    arqEntrada.seekg(0);

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

        //Se ele nao possui presa, nao deve ser adicionado
        if(dino.Alimento().compare("") == 0)
            continue;

        int posDino = this->EncontrarPosInsercao(dino.Nome());

        if(this->EncontrarDino(dino.Nome()) == -1)
        {
            this->_listaAdj.insert(this->_listaAdj.begin() + posDino, Vertice(dino));
            continue;
        }

        this->_listaAdj.at(posDino).IncluirAlimento(dino);
    }

    for(auto& atual : this->_listaAdj)
    {
        atual.SetGrauDeEntrada(this->FindPredadores(atual.Origem().Nome()).size());
    }
}

ListaDeAdjacencias::~ListaDeAdjacencias()
{
    this->_listaAdj.clear();
}

int ListaDeAdjacencias::EncontrarDino(std::string nome)
{
    for(int i = 0; i < (int)this->_listaAdj.size(); i++)
    {
        int relacao = nome.compare(this->_listaAdj.at(i).Origem().Nome());
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
    for(int i = 0; i < (int)this->_listaAdj.size(); i++)
    {
        if(nome.compare(this->_listaAdj.at(i).Origem().Nome()) <= 0)
        {
            return i;
        }
    }

    return this->_listaAdj.size();
}

int ListaDeAdjacencias::ContarCirculos(std::vector<std::string>* brancos, std::vector<std::string>* cinzas, int dinoAtual)
{
    //Procura a posicao dele nos brancos
    for(int i = 0; i < (int)brancos->size(); i++)
    {
        //Se encontrou
        if(brancos->at(i).compare(this->_listaAdj.at(dinoAtual).Origem().Nome()) == 0)
        {
            //Deleta ele
            brancos->erase(brancos->begin() + i);
        }
    }

    int qtd = 0;

    //Verifica se tem presas
    if(this->_listaAdj.at(dinoAtual).GrauDeSaida() != 0)
    {
        int pos = cinzas->size();
        cinzas->push_back(this->_listaAdj.at(dinoAtual).Origem().Nome());

        for(auto& aresta : this->_listaAdj.at(dinoAtual).ListaAlimentos())
        {
            bool procurou = false;

            //Procura a posicao dele nos brancos
            for(int i = 0; i < (int)brancos->size(); i++)
            {
                //Se encontrou
                if(brancos->at(i).compare(aresta.Valor()) == 0)
                {
                    qtd += this->ContarCirculos(brancos, cinzas, this->EncontrarDino(aresta.Valor()));
                    procurou = true;
                    break;
                }
            }

            if(procurou)
                continue;

            //Procura a posicao dele nos cinzas
            for(int i = 0; i < (int)cinzas->size(); i++)
            {
                //Se encontrou
                if(cinzas->at(i).compare(aresta.Valor()) == 0)
                {
                    qtd++;
                }
            }
        }

        cinzas->erase(cinzas->begin() + pos);
    }

    //Como ja foi removido dos brancos e dos cinzas, ele eh classificado como preto
    return qtd;
}

std::vector<std::string> ListaDeAdjacencias::FindPredadores(std::string nome)
{
    std::vector<std::string> predadores;

    for(auto& atual : this->_listaAdj)
    {
        if(atual.AlimentaDe(nome))
            predadores.push_back(atual.Origem().Nome());
    }

    return predadores;
}

int ListaDeAdjacencias::ContarQuantidadeCiclos()
{
    std::vector<std::string>* brancos = new std::vector<std::string>();
    std::vector<std::string>* cinzas = new std::vector<std::string>();

    for(auto& dino : this->_listaAdj)
    {
        brancos->push_back(dino.Origem().Nome());
    }

    int qtd = 0;

    while(brancos->size() > 0)
    {
        qtd += this->ContarCirculos(brancos, cinzas, this->EncontrarDino(brancos->at(0)));
    }

    return qtd;
}

std::ostream& operator<<(std::ostream& out, const ListaDeAdjacencias& lista)
{
    for(auto const& atual : lista._listaAdj)
    {
        out << atual;
    }

    return out;
}
