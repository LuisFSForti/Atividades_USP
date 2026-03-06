#include <iostream>
#include <algorithm>
#include <vector>

//Struct para facilitar o armazenamento das tarefas
struct Tarefa
{
    int tempo, fim;
};

//Algoritmo de ordenação por tempo necessário crescente
bool CompararTarefas(const Tarefa a, const Tarefa b)
{
    return a.tempo < b.tempo;
}

int main()
{
    //Pega o número de tarefas
    int nroTarefas;
    std::cin >> nroTarefas;

    //Para salvar todas as tarefas
    std::vector<Tarefa> tarefas(nroTarefas);

    //Para cada tarefa, salva seus dados
    for (int i = 0; i < nroTarefas; ++i)
    {
        std::cin >> tarefas[i].tempo;
        std::cin >> tarefas[i].fim;
    }

    //Ordena as tarefas por tempo crescente
    std::sort(tarefas.begin(), tarefas.end(), CompararTarefas);

    //Para salvar a recompensa total e a data atual
    long long recompensa = 0, data = 0;
    //Para cada tarefa
    for (const Tarefa tarefa : tarefas)
    {
        //Salva a data e calcula a recompensa
        data += tarefa.tempo;
        recompensa += tarefa.fim - data;
    }
    std::cout << recompensa << std::endl;
}