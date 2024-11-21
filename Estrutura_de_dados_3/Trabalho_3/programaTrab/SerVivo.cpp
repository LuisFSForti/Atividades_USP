//Luís Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 3 de ED3

#include "SerVivo.h"

//Construtor vazio, gera valores nulos
SerVivo::SerVivo()
{
    this->_populacao = -1;
    this->_tamanho = -1;
    this->_unidadeMedida = '$';
    this->_velocidade = -1;
}

//Construtor com nome, serve para os seres vivos que ainda não tem dados, apenas o nome
SerVivo::SerVivo(std::string nome)
{
    this->_populacao = -1;
    this->_tamanho = -1;
    this->_unidadeMedida = '$';
    this->_velocidade = -1;

    this->_nome = nome;
}

//Construtor de cópia
SerVivo::SerVivo(const SerVivo& serVivo)
{
    //Copia os dados de serVivo

    this->_populacao = serVivo._populacao;
    this->_tamanho = serVivo._tamanho;
    this->_unidadeMedida = serVivo._unidadeMedida;
    this->_velocidade = serVivo._velocidade;
    this->_nome = serVivo._nome;
    this->_especie = serVivo._especie;
    this->_habitat = serVivo._habitat;
    this->_tipo = serVivo._tipo;
    this->_dieta = serVivo._dieta;
    this->_alimento = serVivo._alimento;
}

//Construtor usando um arquivo binário
//Deve estar no começo do registro para funcionar
SerVivo::SerVivo(std::fstream &arq)
{
    //Lê se foi removido logicamente
    if(!arq.read(&this->_unidadeMedida, sizeof(char)))
    {
        //Se está no fim do arquivo

        //Avisa que está no fim
        this->_unidadeMedida = 'E';
        return;
    }
    //Se foi removido, retorna avisando que foi removido
    if(this->_unidadeMedida == '1')
    {
        return;
    }

    //Lê os dados de tamanho fixo
    arq.read((char*)&this->_populacao, sizeof(int));
    arq.read((char*)&this->_populacao, sizeof(int));
    arq.read((char*)&this->_tamanho, sizeof(float));
    arq.read(&this->_unidadeMedida, sizeof(char));
    arq.read((char*)&this->_velocidade, sizeof(int));

    //Para fazer a leitura dos dados de tamanho variável
    char* auxC = (char*)calloc(160, sizeof(char));
    arq.read(auxC, 160 - 2*sizeof(char) - 3*sizeof(int) - sizeof(float));

    //Para manipular os dados de tamanho variável
    std::string aux;
    aux = auxC;

    //Libera o espaço alocado
    delete auxC;

    //Pega tudo do começo da string ate o primeiro #
    this->_nome = aux.substr(0, aux.find("#"));
    //Deleta o que foi salvo
    aux.erase(0, aux.find("#") + 1);

    //Repete para os demais dados de tamanho fixo
    this->_especie = aux.substr(0, aux.find("#"));
    aux.erase(0, aux.find("#") + 1);
    this->_habitat = aux.substr(0, aux.find("#"));
    aux.erase(0, aux.find("#") + 1);
    this->_tipo = aux.substr(0, aux.find("#"));
    aux.erase(0, aux.find("#") + 1);
    this->_dieta = aux.substr(0, aux.find("#"));
    aux.erase(0, aux.find("#") + 1);
    this->_alimento = aux.substr(0, aux.find("#"));
}

//Para imprimir os dados
std::ostream& operator<<(std::ostream& out, const SerVivo& serVivo)
{
    out << "Nome: " + serVivo._nome << std::endl;

    if(serVivo._especie.compare("") > 0)
        out << "Espécie: " + serVivo._especie << std::endl;

    if(serVivo._tipo.compare("") > 0)
        out << "Tipo: " + serVivo._tipo << std::endl;

    if(serVivo._dieta.compare("") > 0)
        out << "Dieta: " + serVivo._dieta << std::endl;

    if(serVivo._habitat.compare("") > 0)
        out << "Lugar que habitava: " + serVivo._habitat << std::endl;

    if(serVivo._tamanho >= 0)
        out << "Tamanho: " << std::to_string(serVivo._tamanho) << " m" << std::endl;

    if(serVivo._velocidade >= 0 && serVivo._unidadeMedida != '&')
        out << "Velocidade: " << std::to_string(serVivo._velocidade) << " " << serVivo._unidadeMedida << "m/h" << std::endl;

    return out;
}

//Para pegar as informações nas outras classes
int SerVivo::Populacao() const
{
    return this->_populacao;
}

int SerVivo::Velocidade() const
{
    return this->_velocidade;
}

float SerVivo::Tamanho() const
{
    return this->_tamanho;
}

char SerVivo::UnidadeMedida() const
{
    return this->_unidadeMedida;
}

std::string SerVivo::Nome() const
{
    return this->_nome;
}

std::string SerVivo::Especie() const
{
    return this->_especie;
}

std::string SerVivo::Habitat() const
{
    return this->_habitat;
}

std::string SerVivo::Tipo() const
{
    return this->_tipo;
}

std::string SerVivo::Dieta() const
{

    return this->_dieta;
}

std::string SerVivo::Alimento() const
{
    return this->_alimento;
}
