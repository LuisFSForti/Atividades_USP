#include <iostream>
#include <vector>
#include <set>

//Struct para facilitar a ordenação
struct Horarios
{
    int inicio, fim;
};

//Struct para facilitar a leitura
struct Entregador
{
    int ultimaEntrega;
};

//Algoritmo de ordenação de finalização crescente
bool operator<(const Horarios& lhs, const Horarios& rhs)
{
    if (lhs.fim != rhs.fim)
        return lhs.fim < rhs.fim;
    else
        return lhs.inicio < rhs.inicio;
}

//Algoritmo de ordenação de finalização decrescente
bool operator<(const Entregador& lhs, const Entregador& rhs)
{
    return lhs.ultimaEntrega < rhs.ultimaEntrega;
}

int main()
{
    int casos, qtdMotoboys, qtdEntregas;

    //Pega o número de casos teste
    std::cin >> casos;

    //Para cada caso teste
    for (int i = 0; i < casos; ++i)
    {
        //Pega o número de entregas e de motoboys
        std::cin >> qtdEntregas;
        std::cin >> qtdMotoboys;

        //Instancia os vetores dos horários dos entregadores e os horários das entregas
        std::multiset<Entregador> entregadores;
        std::multiset<Horarios> horariosEntregas;

        //Salva os dados de cada entrega
        Horarios aux;
        for (int j = 0; j < qtdEntregas; ++j)
        {
            std::cin >> aux.inicio;
            std::cin >> aux.fim;
            horariosEntregas.insert(aux);
        }

        //Cria todos os entregadores com última entrega em 0
        for (int j = 0; j < qtdMotoboys; ++j)
            entregadores.insert({0});

        int entregasPossiveis = 0;
        //Para cada horário de entrega
        for (const Horarios& entrega : horariosEntregas)
        {
            //Encontra o primeiro entregador que não consegue fazer a entrega
            auto it = entregadores.upper_bound({entrega.inicio});

            //Se estiver no começo, nenhum consegue entregar
            if (it == entregadores.begin())
                continue; //Avança pra próxima entrega

            --it; //Se o atual não consegue, o anterior consegue

            //Remove o entregador da lista, para o multiset reordenar
            Entregador entregador = *it;
            entregadores.erase(it);

            //Atualiza o horário da última entrega
            entregador.ultimaEntrega = entrega.fim;
            //O insere de volta, reordenando o vetor
            entregadores.insert(entregador);

            //Aumenta o número de entregas disponíveis
            entregasPossiveis++;
        }
        //Imprime o número de entregas possíveis do caso
        std::cout << entregasPossiveis << std::endl;
    }

    return 0;
}