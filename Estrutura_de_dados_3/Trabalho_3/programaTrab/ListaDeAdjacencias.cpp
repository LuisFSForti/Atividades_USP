//Luís Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 3 de ED3

#include "ListaDeAdjacencias.h"

//Construtor com arquivo de entrada
ListaDeAdjacencias::ListaDeAdjacencias(std::fstream &arqEntrada)
{
    //Volta para o começo do arquivo
    //Possivelmente redundante, mas garante o funcionamento do código
    arqEntrada.seekg(0);

    //Verifica se o arquivo está consistente
    char status;
    arqEntrada.read(&status, sizeof(char));

    //Se não estiver consistente
    if(status == '0')
    {
        //Alerta
        std::cout << "Falha no processamento do arquivo.";
        //Fecha o arquivo
        arqEntrada.close();
        //Retorna
        return;
    }

    //Pula para o começo dos registros
    arqEntrada.seekg(1600);

    //Lê o primeiro registro
    SerVivo serVivo(arqEntrada);

    //Enquanto não chegou no final do arquivo
    while(serVivo.UnidadeMedida() != 'E')
    {
        //Para definir onde inserir
        int posSer;

        //Se o alimento deste serVivo não existe no grafo
        if(this->EncontrarSerVivo(serVivo.Alimento()) == -1)
        {
            //Encontra onde deveria ser inserido
            posSer = this->EncontrarPosInsercao(serVivo.Alimento());
            //Insere o alimento sem dados, apenas o nome
            this->_listaAdj.insert(this->_listaAdj.begin() + posSer, Vertice(SerVivo(serVivo.Alimento())));
        }

        //Calcula onde inserir o serVivo
        posSer = this->EncontrarPosInsercao(serVivo.Nome());

        //Se ele não existe no grafo
        if(this->EncontrarSerVivo(serVivo.Nome()) == -1)
        {
            //Insere ele na posição adequada
            this->_listaAdj.insert(this->_listaAdj.begin() + posSer, Vertice(serVivo));
            this->_listaAdj.at(posSer).IncluirAlimento(serVivo);

            //Lê um novo serVivo
            serVivo = SerVivo(arqEntrada);
            //Continua o loop
            continue;
        }

        //Se o serVivo existe

        //Se ele tiver uma aresta, significa que ele está consistente
        if(this->_listaAdj.at(posSer).GrauDeSaida() > 0)
        {
            //Adiciona a nova presa
            this->_listaAdj.at(posSer).IncluirAlimento(serVivo);
        }
        //Se ele não tiver uma aresta, entao ele está inconsistente
        else
        {
            //Recria o vértice, agora com o restante dos dados
            this->_listaAdj.at(posSer) = Vertice(serVivo);
            this->_listaAdj.at(posSer).IncluirAlimento(serVivo);
        }

        //Lê um novo serVivo
        serVivo = SerVivo(arqEntrada);
    }

    //Para todos os vértices
    for(auto& atual : this->_listaAdj)
    {
        //Calcula qual é o seu grau de entrada
        atual.SetGrauDeEntrada(this->FindPredadores(atual.Origem().Nome()).size());
    }
}

//Construtor vazio, necessário pra fazer o grafo transposto
ListaDeAdjacencias::ListaDeAdjacencias()
{
    return;
}

//Destrutor da classe
ListaDeAdjacencias::~ListaDeAdjacencias()
{
    //Libera os vértices criados
    this->_listaAdj.clear();
}

//Encontra onde o ser vivo está, avisando se ele não existir
int ListaDeAdjacencias::EncontrarSerVivo(std::string nome) const
{
    //Para cada vértice
    for(int i = 0; i < (int)this->_listaAdj.size(); i++)
    {
        //Calcula a relação do vértice com o ser vivo procurado
        int relacao = nome.compare(this->_listaAdj.at(i).Origem().Nome());

        //Se for quem está procurando
        if(relacao == 0)
            //Retorna a posicao
            return i;

        //Se o ser vivo tiver precêdencia sobre o atual, ele não pode estar para frente
        if(relacao < 0)
            //Encerra a pesquisa
            break;
    }

    //Retorna que não encontrou
    return -1;
}

//Encontra onde o ser vivo deve ser inserido
int ListaDeAdjacencias::EncontrarPosInsercao(std::string nome) const
{
    //Para cada vértice
    for(int i = 0; i < (int)this->_listaAdj.size(); i++)
    {
        //Se o ser vivo tiver precêdencia sobre o atual ou for o atual
        if(nome.compare(this->_listaAdj.at(i).Origem().Nome()) <= 0)
        {
            //Retorna a posição atual
            return i;
        }
    }

    //Se não tem precedencia sobre nenhum outro ou não foi achado
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
            //Para verificar se a aresta atual era para um vértice originalmente branco
            bool procurou = false;

            //Procura a posição da presa nos brancos
            for(int i = 0; i < (int)brancos->size(); i++)
            {
                //Se encontrou
                if(brancos->at(i).compare(aresta.Valor()) == 0)
                {


                    //Chama a função novamente, somando o retorno dela
                    qtd += this->ContarCirculos(brancos, cinzas, this->EncontrarSerVivo(aresta.Valor()));
                    //Define que era um vértice branco
                    procurou = true;
                    //Encerra o loop de pesquisa
                    break;
                }
            }

            //Se era um branco
            if(procurou)
                //Avança para a próxima aresta
                continue;

            //Se não era branco
            //Procura a posição dele nos cinzas
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

//Retorna o grafo transposto, para o cálculo de componentes conexos
ListaDeAdjacencias ListaDeAdjacencias::GrafoTransposto() const
{
    //Cria a lista nova
    ListaDeAdjacencias listaRet;

    //Copia os vértices, sem as arestas
    for(const auto& vertice : this->_listaAdj)
    {
        //Insere o vértice no fim da lista, pois já estão sendo inseridos em ordem alfabética
        listaRet._listaAdj.push_back(Vertice(vertice.Origem()));
        //Define que a quantidade de saídas é a antiga quantidade de entradas
        listaRet._listaAdj.back().SetGrauDeEntrada(vertice.GrauDeSaida());
    }

    //Para cada vértice da lista antiga
    for(const auto& vertice : this->_listaAdj)
    {
        //Para cada aresta
        for(const auto& aresta : vertice.ListaAlimentos())
        {
            //Encontra onde a presa está na lista
            int pos = this->EncontrarSerVivo(aresta.Valor());

            //Inclui a nova aresta para a presa
            //Mantém o mesmo peso, pois apenas muda a direção da aresta
            listaRet._listaAdj.at(pos).IncluirAlimento(Aresta(vertice.Origem().Nome(), aresta.Peso()));
        }
    }

    return listaRet;
}

//Para calcular a quantidade de componentes conexos
void ListaDeAdjacencias::ContarComponentes(std::vector<std::string>* naoVerificados, std::vector<std::string>* pilha, int verticeAtual)
{
    //Procura a posição dele nos naoVerificados
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

    //Para cada aresta do vértice
    for(const auto& aresta : this->_listaAdj.at(verticeAtual).ListaAlimentos())
    {
        //Para cada presa ainda não verificada
        for(const auto& presa : *naoVerificados)
        {
            //Se achou a presa da aresta
            if(presa.compare(aresta.Valor()) == 0)
            {
                //Chama a função novamente, passando pro próximo vértice
                this->ContarComponentes(naoVerificados, pilha, this->EncontrarSerVivo(aresta.Valor()));
            }
        }
    }

    //std::cout << this->_listaAdj.at(verticeAtual).Origem().Nome() << " - " << verticeAtual << std::endl;
    pilha->insert(pilha->begin(), this->_listaAdj.at(verticeAtual).Origem().Nome());
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
            //Como o loop ja está em ordem, basta inserir no fim da lista
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

    //Enquanto algum vertice não tiver sido analisado
    while(brancos->size() > 0)
    {
        //Chama a funcao de contar ciclos, comecando pelo primeiro branco restante
        qtd += this->ContarCirculos(brancos, cinzas, this->EncontrarSerVivo(brancos->front()));
    }

    //Retorna a quantidade de ciclos total
    return qtd;
}

//Para calcular a quantidade de componentes conexos
int ListaDeAdjacencias::CalcularComponentesConexos()
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

    delete naoVerificados;
    naoVerificados = new std::vector<std::string>();

    ListaDeAdjacencias listaTransposta = this->GrafoTransposto();

    int qtd = 0;

    while(pilha->size() > 0)
    {
        listaTransposta.ContarComponentes(pilha, naoVerificados, EncontrarSerVivo(pilha->front()));
        qtd++;
    }

    return qtd;
}

//Para calcular o risco de uma presa em relação a um predador
int ListaDeAdjacencias::CalcularRisco(std::string predador, std::string presa)
{
    int posPredador = this->EncontrarSerVivo(predador);
    int posPresa = this->EncontrarSerVivo(presa);

    if(posPredador == -1 || posPresa == -1)
        return -1;

    int **dados = (int**) malloc(this->_listaAdj.size() * sizeof(int*));

    for(int i = 0; i < (int)this->_listaAdj.size(); i++)
    {
        dados[i] = (int*) malloc(2 * sizeof(int));
        //Não avaliado
        dados[i][0] = 0;
        //Distância infinita
        dados[i][1] = INT_MAX;
    }

    int atual = posPredador;
    int presaAtual;

    //Para iterar sobre todos os vértices
    dados[posPredador][0] = 1;
    dados[posPredador][1] = 0;
    for(int i = 0; i < (int)this->_listaAdj.size(); i++)
    {
        //Para atualizar os dados
        for(const auto& aresta : this->_listaAdj.at(atual).ListaAlimentos())
        {
            presaAtual = EncontrarSerVivo(aresta.Valor());

            if(dados[presaAtual][1] > aresta.Peso() + dados[atual][1])
            {
                dados[presaAtual][1] = aresta.Peso() + dados[atual][1];
            }
        }

        dados[atual][0] = 1;
        atual = -1;

        for(int j = 0; j < (int)this->_listaAdj.size(); j++)
        {
            //Se ainda não foi iterado
            if(dados[j][0] == 0 && dados[j][1] != INT_MAX)
            {
                if(atual == -1)
                {
                    atual = j;
                    continue;
                }
                if(dados[atual][1] > dados[j][1])
                    atual = j;
            }
        }

        if(atual == -1)
            break;
    }

    return dados[posPresa][1];
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
