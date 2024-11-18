#include "ListaDeAdjacencias.h"

//Construtor com arquivo de entrada
ListaDeAdjacencias::ListaDeAdjacencias(std::fstream &arqEntrada)
{
    //Volta para o comeco do arquivo
    //Possivelmente redundante, mas garante o funcionamento do codigo
    arqEntrada.seekg(0);

    //Verifica se o arquivo esta consistente
    char status;
    arqEntrada.read(&status, sizeof(char));

    //Se nao estiver consistente
    if(status == '0')
    {
        //Alerta
        std::cout << "Falha no processamento do arquivo.";
        //Fecha o arquivo
        arqEntrada.close();
        //Retorna
        return;
    }

    //Pula para o comeco dos registros
    arqEntrada.seekg(1600);

    //Le o primeiro registro
    SerVivo serVivo(arqEntrada);

    //Enquanto nao chegou no final do arquivo
    while(serVivo.UnidadeMedida() != 'E')
    {
        //Para definir onde inserir
        int posSer;

        //Se o alimento deste serVivo nao existe no grafo
        if(this->EncontrarSerVivo(serVivo.Alimento()) == -1)
        {
            //Encontra onde deveria ser inserido
            posSer = this->EncontrarPosInsercao(serVivo.Alimento());
            //Insere o alimento sem dados, apenas o nome
            this->_listaAdj.insert(this->_listaAdj.begin() + posSer, Vertice(SerVivo(serVivo.Alimento())));
        }

        //Calcula onde inserir o serVivo
        posSer = this->EncontrarPosInsercao(serVivo.Nome());

        //Se ele nao existe no grafo
        if(this->EncontrarSerVivo(serVivo.Nome()) == -1)
        {
            //Insere ele na posicao adequada
            this->_listaAdj.insert(this->_listaAdj.begin() + posSer, Vertice(serVivo));

            //Le um novo serVivo
            serVivo = SerVivo(arqEntrada);
            //Continua o loop
            continue;
        }

        //Se o serVivo existe

        //Se ele ja tiver uma aresta, significa que ele ja esta consistente
        if(this->_listaAdj.at(posSer).GrauDeSaida() > 0)
        {
            //Adiciona a nova presa
            this->_listaAdj.at(posSer).IncluirAlimento(serVivo);
        }
        //Se ele nao tiver uma aresta, entao ele esta inconsistente
        else
        {
            //Recria o vertice, agora com o restante dos dados
            this->_listaAdj.at(posSer) = Vertice(serVivo);
        }

        //Le um novo serVivo
        serVivo = SerVivo(arqEntrada);
    }

    //Para todos os vertices
    for(auto& atual : this->_listaAdj)
    {
        //Calcula qual eh o seu grau de entrada
        atual.SetGrauDeEntrada(this->FindPredadores(atual.Origem().Nome()).size());
    }
}

ListaDeAdjacencias::ListaDeAdjacencias()
{
    return;
}

//Destrutor da classe
ListaDeAdjacencias::~ListaDeAdjacencias()
{
    //Libera os vertices criados
    this->_listaAdj.clear();
}

//Encontra onde o ser vivo esta, avisando se ele nao estiver
int ListaDeAdjacencias::EncontrarSerVivo(std::string nome) const
{
    //Para cada vertice
    for(int i = 0; i < (int)this->_listaAdj.size(); i++)
    {
        //Calcula a relacao do vertice com o ser vivo procurado
        int relacao = nome.compare(this->_listaAdj.at(i).Origem().Nome());

        //Se for quem esta procurando
        if(relacao == 0)
            //Retorna a posicao
            return i;

        //Se o ser vivo tiver precedencia sobre o atual, ele nao pode estar para frente
        if(relacao < 0)
            //Encerra a pesquisa
            break;
    }

    //Retorna que nao encontrou
    return -1;
}

//Encontra onde o ser vivo deve ser inserido
int ListaDeAdjacencias::EncontrarPosInsercao(std::string nome) const
{
    //Para cada vertice
    for(int i = 0; i < (int)this->_listaAdj.size(); i++)
    {
        //Se o ser vivo tiver precedencia sobre o atual ou for o atual
        if(nome.compare(this->_listaAdj.at(i).Origem().Nome()) <= 0)
        {
            //Retorna a posicao atual
            return i;
        }
    }

    //Se nao tem precedencia sobre nenhum outro ou nao foi achado
    //Retorna que deve ser inserido no fim da lista
    return this->_listaAdj.size();
}

//Para fazer a contagem de ciclos no grafo
int ListaDeAdjacencias::ContarCirculos(std::vector<std::string>* brancos, std::vector<std::string>* cinzas, int verticeAtual) const
{
    //Procura a posicao dele nos brancos
    for(int i = 0; i < (int)brancos->size(); i++)
    {
        //Se encontrou
        if(brancos->at(i).compare(this->_listaAdj.at(verticeAtual).Origem().Nome()) == 0)
        {
            //Deleta ele
            brancos->erase(brancos->begin() + i);
            break;
        }
    }

    int qtd = 0;

    //Verifica se tem presas
    if(this->_listaAdj.at(verticeAtual).GrauDeSaida() != 0)
    {
        //Se tiver, salva onde ele foi inserido nos cinzas (no fim da lista)
        int pos = cinzas->size();
        //Define ele como sendo um cinza
        cinzas->push_back(this->_listaAdj.at(verticeAtual).Origem().Nome());

        //Para cada aresta
        for(auto& aresta : this->_listaAdj.at(verticeAtual).ListaAlimentos())
        {
            //Para verificar se a aresta atual era originalmente branca
            bool procurou = false;

            //Procura a posicao dele nos brancos
            for(int i = 0; i < (int)brancos->size(); i++)
            {
                //Se encontrou
                if(brancos->at(i).compare(aresta.Valor()) == 0)
                {
                    //Chama a funcao novamente, somando o retorno dela
                    qtd += this->ContarCirculos(brancos, cinzas, this->EncontrarSerVivo(aresta.Valor()));
                    //Define que era uma branca
                    procurou = true;
                    //Encerra o loop de pesquisa
                    break;
                }
            }

            //Se era uma branca
            if(procurou)
                //Avanca para a proxima aresta
                continue;

            //Se nao era branca
            //Procura a posicao dele nos cinzas
            for(int i = 0; i < (int)cinzas->size(); i++)
            {
                //Se encontrou
                if(cinzas->at(i).compare(aresta.Valor()) == 0)
                {
                    //Define que encontrou um novo ciclo
                    qtd++;
                    //Encerra o loop de pesquisa
                    break;
                }
            }
        }

        //Ao terminar de operar com suas arestas
        //Remove o vertice das cinzas, removendo ele por inteiro do algoritmo
        cinzas->erase(cinzas->begin() + pos);
    }

    //Retorna quantos ciclos ele encontrou
    return qtd;
}

//Retorna o grafo transposto, para o calculo de componentes conexos
ListaDeAdjacencias ListaDeAdjacencias::GrafoTransposto() const
{
    //Cria a lista nova
    ListaDeAdjacencias listaRet;

    //Copia os vertices, sem as arestas
    for(const auto& vertice : this->_listaAdj)
    {
        //Insere o vertice no fim da lista, pois ja estao sendo inseridos em ordem alfabetica
        listaRet._listaAdj.push_back(Vertice(vertice.Origem()));
        //Remove as arestas, atualizando tambem o grau de saida e o grau geral
        listaRet._listaAdj.back().LimparArestas();
        //Define que a quantidade de saidas eh a antiga quantidade de entradas
        listaRet._listaAdj.back().SetGrauDeEntrada(vertice.GrauDeSaida());
    }

    //Para cada vertice da lista antiga
    for(const auto& vertice : this->_listaAdj)
    {
        //Para cada aresta original
        for(const auto& aresta : vertice.ListaAlimentos())
        {
            //Encontra onde a presa esta na lista
            int pos = this->EncontrarSerVivo(aresta.Valor());

            //Inclui a nova aresta para a presa
            //Mantem o mesmo peso, pois apenas muda a direcao da aresta
            listaRet._listaAdj.at(pos).IncluirAlimento(Aresta(vertice.Origem().Nome(), aresta.Peso()));
        }
    }

    return listaRet;
}

//Para calcular a quantidade de componentes conexos
void ListaDeAdjacencias::ContarComponentes(std::vector<std::string>* naoVerificados, std::vector<std::string>* pilha, int verticeAtual)
{
    //Procura a posicao dele nos naoVerificados
    for(int i = 0; i < (int)naoVerificados->size(); i++)
    {
        //Se encontrou
        if(naoVerificados->at(i).compare(this->_listaAdj.at(verticeAtual).Origem().Nome()) == 0)
        {
            //Deleta ele
            naoVerificados->erase(naoVerificados->begin() + i);
            break;
        }
    }

    for(const auto& aresta : this->_listaAdj.at(verticeAtual).ListaAlimentos())
    {
        int posPresa = this->EncontrarSerVivo(aresta.Valor());

        for(const auto& presa : *naoVerificados)
        {
            if(presa.compare(aresta.Valor()) == 0)
            {
                this->ContarComponentes(naoVerificados, pilha, posPresa);
            }
        }
    }

    pilha->push_back(this->_listaAdj.at(verticeAtual).Origem().Nome());
}

//Para encontrar os predadores da presa
std::vector<std::string> ListaDeAdjacencias::FindPredadores(std::string nome) const
{
    //Para guardar todos os predadores
    std::vector<std::string> predadores;

    //Para cada vertice
    for(auto& atual : this->_listaAdj)
    {
        //Se o atual se alimenta da presa procurada
        if(atual.AlimentaDe(nome))
            //Adiciona o predador na lista
            //Como o loop ja esta em ordem, basta inserir no fim da lista
            predadores.push_back(atual.Origem().Nome());
    }

    //Retorna a lista de predadores
    return predadores;
}

//Para iniciar a contagem de ciclos
int ListaDeAdjacencias::ContarQuantidadeCiclos() const
{
    //Cria os ponteiros para os vertices brancos e cinzas
    std::vector<std::string>* brancos = new std::vector<std::string>();
    std::vector<std::string>* cinzas = new std::vector<std::string>();

    //Salva nos brancos todos os vertices
    for(auto& serVivo : this->_listaAdj)
    {
        brancos->push_back(serVivo.Origem().Nome());
    }

    int qtd = 0;

    //Enquanto algum vertice nao tiver sido analisado
    while(brancos->size() > 0)
    {
        //Chama a funcao de contar ciclos, comecando pelo primeiro branco restante
        qtd += this->ContarCirculos(brancos, cinzas, this->EncontrarSerVivo(brancos->front()));
    }

    //Retorna a quantidade de ciclos total
    return qtd;
}

//Para calcular a quantidade de componentes conexos
void ListaDeAdjacencias::CalcularComponentesConexos()
{
    //Ponteiros para as operacoes
    std::vector<std::string>* naoVerificados = new std::vector<std::string>();
    std::vector<std::string>* pilha = new std::vector<std::string>();

    //Salva nos naoVerificados todos os vertices
    for(auto& serVivo : this->_listaAdj)
    {
        naoVerificados->push_back(serVivo.Origem().Nome());
    }

    while(naoVerificados->size() > 0)
    {
        this->ContarComponentes(naoVerificados, pilha, EncontrarSerVivo(naoVerificados->front()));
    }

    naoVerificados = new std::vector<std::string>();

    int qtd = 0;

    while(naoVerificados->size() > 0)
    {
        this->ContarComponentes(pilha, naoVerificados, EncontrarSerVivo(pilha->front()));
        qtd++;
    }

    std::cout << qtd;
}

//Para imprimir os dados
std::ostream& operator<<(std::ostream& out, const ListaDeAdjacencias& lista)
{
    //Para cada vertice
    for(auto const& atual : lista._listaAdj)
    {
        out << atual;
    }

    return out;
}
