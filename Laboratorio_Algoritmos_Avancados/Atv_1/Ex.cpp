#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    int nroCasos = 0, nroAssuntos = 0, prazoAtividade = 0;
    std::unordered_map<std::string, int> atividades;
    std::string assunto;

    std::cin >> nroCasos;
    //Para cada caso
    for (int i = 0; i < nroCasos; ++i)
    {
        //Salva o tempo necessário para cada assunto no mapa
        //Assunto -> tempo necessário
        std::cin >> nroAssuntos;
        for (int j = 0; j < nroAssuntos; ++j)
        {
            std::cin >> assunto;
            std::cin >> atividades[assunto];
        }

        //Pega os detalhes da atividade
        std::cin >> prazoAtividade;
        std::cin >> assunto;

        //Imprime qual o caso atual
        std::cout << "Case " << i + 1 << ": ";

        //Verifica se o assunto da atividade foi descrito pelo usuário
        auto iterador = atividades.find(assunto);
        //Se sim
        if (iterador != atividades.end())
        {
            //Verifica o prazo
            if (iterador->second <= prazoAtividade)
                std::cout << "Yessss" << std::endl;
            else if (iterador->second <= prazoAtividade + 5)
                std::cout << "Late" << std::endl;
            else
                std::cout << "Do your own homework!" << std::endl;
        }
        //Se o assunto não foi descrito
        else
            std::cout << "Do your own homework!" << std::endl;
    }

    return 0;
}