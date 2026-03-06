#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int casos, qtdCriancas, pesoLimite;

    //Pega o número de casos teste
    std::cin >> casos;

    //Para cada caso
    for (int i = 0; i < casos; ++i)
    {
        //Pega o número de crianças e o limite de cada cabine
        std::cin >> qtdCriancas;
        std::cin >> pesoLimite;

        //Cria um vetor para armazenar os pesos das crianças
        std::vector<int> pesos(qtdCriancas);

        //Salva o peso das crianças
        for (int j = 0; j < qtdCriancas; ++j)
        {
            std::cin >> pesos[j];
        }

        //Ordena-as por peso em ordem decrescente
        std::sort(pesos.begin(), pesos.end(), std::greater<int>());

        int pesoCabine, nroCabines = 0, posSegundaCrianca;

        //Enquanto ainda tiver crianças para analisar
        while (!pesos.empty())
        {
            //Salva que precisa de mais uma cabine
            nroCabines++;
            //Define o peso da cabine atual
            //Como as crianças vão ser removidas do vetor, a mais pesada sempre será a primeira
            pesoCabine = pesos[0];

            //Se tiverem outras crianças e a atual não atingir o limite
            if (pesos.size() > 1 && pesoCabine < pesoLimite)
            {
                //A segunda criança será uma das próximas
                posSegundaCrianca = 1;

                //Enquanto não tiver analisado todas
                while (posSegundaCrianca < pesos.size())
                {
                    //Se as duas crianças ultrapassarem o peso limite
                    if (pesoCabine + pesos[posSegundaCrianca] > pesoLimite)
                        //Avança pra analisar a próxima
                        posSegundaCrianca++;
                    //Se as duas puderem ir juntas, sai do loop
                    else
                        break;
                }
                //Se achou uma criança para acompanhar a mais pesada
                if (posSegundaCrianca < pesos.size())
                    //Exclui ela do vetor
                    pesos.erase(pesos.begin() + posSegundaCrianca);
            }
            //Exclui a criança mais pesada do vetor
            pesos.erase(pesos.begin());
        }

        //Imprime o número de cabines necessárias
        std::cout << nroCabines << std::endl;
    }

    return 0;
}