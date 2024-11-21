//Luís Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 3 de ED3

#include "Vertice.h"

//Cria um vértice com um SerVivo
Vertice::Vertice(SerVivo serVivo)
{
    this->_origem = SerVivo(serVivo);

    this->_grauDeSaida = 0;
    this->_grau = 0;
    this->_grauDeEntrada = 0;
}

//Destrutor da classe
Vertice::~Vertice()
{
    //Libera o espaço armazenado para as arestas
    this->_listaAlimentos.clear();
}

//Para adicioanr presas
//Esta função tambem aceita um SerVivo como parametro, pois Aresta tem um construtor com SerVivo
void Vertice::IncluirAlimento(Aresta aresta)
{
    //Se for uma presa inválida
    if(aresta.Valor().compare("") == 0)
        //Cancela a inserção
        return;

    //Para encontrar onde deve inserir
    for(int i = 0; i < (int)this->_listaAlimentos.size(); i++)
    {
        //Compara o nome da presa atual com a nova
        int relacao = aresta.Valor().compare(this->_listaAlimentos.at(i).Valor());

        //Se achou a presa que deseja inserir
        //Retorna sem inserir
        if(relacao == 0)
            return;

        //Se a presa tiver precedência sobre a atual
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

    //Se não achou onde inserir
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
        //Verifica a relação com a presa atual
        int relacao = nome.compare(aresta.Valor());

        //Se encontrou a presa passada
        if(relacao == 0)
            //Retorna que achou
            return true;

        //Se tem precedência
        //Então não pode estar em nenhuma posição para frente
        if(relacao < 0)
            break;
    }
    //Se não encontrou retorna falso
    return false;
}

//Para imprimir os dados
std::ostream& operator<<(std::ostream& out, const Vertice& vert)
{
    //Para cada aresta
    for(const auto& aresta : vert._listaAlimentos)
    {
        //Imprime os dados do vértice
        out <<  vert._origem.Nome() + " " + vert._origem.Especie() + " " + vert._origem.Habitat() + " " + vert._origem.Dieta() + " " + vert._origem.Tipo() + " " +
            std::to_string(vert._grauDeEntrada) + " " + std::to_string(vert._grauDeSaida) + " " + std::to_string(vert._grau);

        //Imprime os dados da aresta atual
        out << " " << aresta << std::endl;
    }

    return out;
}

//Para definir os graus
void Vertice::SetGrauDeEntrada(int valor)
{
    //Atualiza também o grau geral
    this->_grau = this->_grauDeSaida + valor;
    this->_grauDeEntrada = valor;
}

//Para pegar as informações nas outras classes
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

