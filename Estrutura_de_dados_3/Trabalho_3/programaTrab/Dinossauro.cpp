#include "Dinossauro.h"

Dinossauro::Dinossauro()
{
    //Cria um dinossauro com valores nulos

    this->_populacao = -1;
    this->_tamanho = -1;
    this->_unidadeMedida = '$';
    this->_velocidade = -1;
}

Dinossauro::Dinossauro(Dinossauro& dino)
{
    //Copia os dados de dino

    this->_populacao = dino._populacao;
    this->_tamanho = dino._tamanho;
    this->_unidadeMedida = dino._unidadeMedida;
    this->_velocidade = dino._velocidade;
    this->_nome = dino._nome;
    this->_especie = dino._especie;
    this->_habitat = dino._habitat;
    this->_tipo = dino._tipo;
    this->_alimento = dino._alimento;
    this->_alimento = dino._alimento;
}

Dinossauro::Dinossauro(std::fstream &arq)
{
    //Se esta no fim do arquivo
    if(arq.eof())
    {
        new (this) Dinossauro();
        return;
    }
    //Le se foi removido logicamente
    arq.read(&this->_unidadeMedida, sizeof(char));
    //Se foir removido, retorna
    if(this->_unidadeMedida == '1')
    {
        return;
    }

    //Le os dados de tamanho fixo
    arq.read((char*)&this->_populacao, sizeof(int));
    arq.read((char*)&this->_populacao, sizeof(int));
    arq.read((char*)&this->_tamanho, sizeof(float));
    arq.read((char*)&this->_unidadeMedida, sizeof(char));
    arq.read((char*)&this->_velocidade, sizeof(int));

    //Para fazer a leitura dos dados de tamanho variavel
    char* auxC = (char*)calloc(160, sizeof(char));
    arq.read(auxC, 160 - 2*sizeof(char) - 3*sizeof(int) - sizeof(float));

    //Para manipular os dados de tamanho variavel
    std::string aux;
    aux = auxC;

    //Libera o espaco alocado
    delete auxC;

    //Pega tudo do comeco da string ate o primeiro #
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

void Dinossauro::SalvarDinossauro(std::fstream &arq)
{
    int aux = -1;
    arq.write("0", sizeof(char));
    arq.write((char*)&aux, sizeof(int));
    arq.write((char*)&this->_populacao, sizeof(int));
    arq.write((char*)&this->_tamanho, sizeof(float));
    arq.write((char*)&this->_unidadeMedida, sizeof(char));
    arq.write((char*)&this->_velocidade, sizeof(int));

    std::string auxS =  this->_nome + "#" + this->_especie + "#" + this->_habitat + "#" +
                        this->_tipo + "#" + this->_dieta + "#" + this->_alimento + "#";

    auxS.append(160 - auxS.length(), '$');
    arq.write(auxS.c_str(), 160);
}

//Imprime as informacoes do dino
std::ostream& operator<<(std::ostream& out, Dinossauro& dino)
{
    out << "Nome: " + dino._nome << std::endl;

    if(dino._especie.compare("") > 0)
        out << "Especie: " + dino._especie << std::endl;

    if(dino._tipo.compare("") > 0)
        out << "Tipo: " + dino._tipo << std::endl;

    if(dino._dieta.compare("") > 0)
        out << "Deita: " + dino._dieta << std::endl;

    if(dino._habitat.compare("") > 0)
        out << "Lugar que habitava: " + dino._habitat << std::endl;

    if(dino._tamanho >= 0)
        out << "Tamanho: " << std::to_string(dino._tamanho) << " m" << std::endl;

    if(dino._velocidade >= 0 && dino._unidadeMedida != '&')
        out << "Velocidade: " << std::to_string(dino._velocidade) << " " << dino._unidadeMedida << "m/h" << std::endl;


    return out;
}

int Dinossauro::Populacao()
{
    return this->_populacao;
}

int Dinossauro::Velocidade()
{
    return this->_velocidade;
}

float Dinossauro::Tamanho()
{
    return this->_tamanho;
}

char Dinossauro::UnidadeMedida()
{
    return this->_unidadeMedida;
}

std::string Dinossauro::Nome()
{
    return this->_nome;
}

std::string Dinossauro::Especie()
{
    return this->_especie;
}

std::string Dinossauro::Habitat()
{
    return this->_habitat;
}

std::string Dinossauro::Tipo()
{
    return this->_tipo;
}

std::string Dinossauro::Dieta()
{

    return this->_dieta;
}

std::string Dinossauro::Alimento()
{
    return this->_alimento;
}
