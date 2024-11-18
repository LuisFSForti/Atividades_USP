#include "Vertice.h"

//Cria um vertice com um SerVivo
Vertice::Vertice(SerVivo serVivo)
{
    this->_origem = SerVivo(serVivo);

    if(serVivo.Alimento().compare("") != 0)
    {
        Aresta aresta(serVivo.Alimento(), serVivo.Populacao());
        this->_listaAlimentos.insert(this->_listaAlimentos.begin(), aresta);

        this->_grauDeSaida = 1;
        this->_grau = 1;
    }
    else
    {
        this->_grauDeSaida = 0;
        this->_grau = 0;
    }
    this->_grauDeEntrada = 0;
}

//Destrutor da classe
Vertice::~Vertice()
{
    //Libera o espaco armazenado para as arestas
    this->_listaAlimentos.clear();
}

//Para adicioanr presas
//Esta funcao tambem aceita um SerVivo como parametro, pois Aresta tem um construtor com SerVivo
void Vertice::IncluirAlimento(Aresta aresta)
{
    //Para encontrar onde deve inserir
    for(int i = 0; i < (int)this->_listaAlimentos.size(); i++)
    {
        //Compara o nome da presa atual com a nova
        int relacao = aresta.Valor().compare(this->_listaAlimentos.at(i).Valor());

        //Se achou a presa que deseja inserir
        //Retorna sem inserir
        if(relacao == 0)
            return;

        //Se a presa tiver precedencia sobre o atual
        if(relacao < 0)
        {
            //Insere no local
            this->_listaAlimentos.insert(this->_listaAlimentos.begin() + i, aresta);

            //Atualiza os graus
            this->_grauDeSaida++;
            this->_grau++;

            //Retorna
            return;
        }
    }

    //Se nao achou onde inserir
    //Insere no final
    this->_listaAlimentos.push_back(aresta);

    //Atualiza os graus
    this->_grauDeSaida++;
    this->_grau++;
}

//Para verificar se preda o ser vivo
bool Vertice::AlimentaDe(std::string nome) const
{
    //Para cada aresta
    for(auto const& aresta : this->_listaAlimentos)
    {
        //Verifica a relacao com a presa atual
        int relacao = nome.compare(aresta.Valor());

        //Se encontrou a presa passada
        if(relacao == 0)
            //Retorna que achou
            return true;

        //Se tem precedencia
        //Entao nao pode estar em nenhuma posicao para frente
        if(relacao < 0)
            break;
    }
    //Se nao encontrou retorna falso
    return false;
}

//Para imprimir os dados
std::ostream& operator<<(std::ostream& out, const Vertice& vert)
{
    //Para cada aresta
    for(const auto& aresta : vert._listaAlimentos)
    {
        //Imprime os dados do vertice
        out <<  vert._origem.Nome() + " " + vert._origem.Especie() + " " + vert._origem.Habitat() + " " + vert._origem.Dieta() + " " + vert._origem.Tipo() + " " +
            std::to_string(vert._grauDeEntrada) + " " + std::to_string(vert._grauDeSaida) + " " + std::to_string(vert._grau);

        //Imprime os dados da aresta atual
        out << " " << aresta << std::endl;
    }

    return out;
}

//Para ter um vertice sem arestas, importante para calcular o grafo transposto
void Vertice::LimparArestas()
{
    this->_listaAlimentos.clear();
    this->SetGrauDeSaida(0);
}

//Para definir os graus
void Vertice::SetGrauDeEntrada(int valor)
{
    //Atualiza tambem o grau geral
    this->_grau = this->_grauDeSaida + valor;
    this->_grauDeEntrada = valor;
}

void Vertice::SetGrauDeSaida (int valor)
{
    //Atualiza tambem o grau geral
    this->_grau = this->_grauDeEntrada + valor;
    this->_grauDeSaida = valor;
}

//Para pegar as informacoes nas outras classes
SerVivo Vertice::Origem() const
{
    return this->_origem;
}

std::vector<Aresta> Vertice::ListaAlimentos() const
{
    return this->_listaAlimentos;
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

