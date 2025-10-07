#include "GerenciadorJogo.h"

GerenciadorJogo::GerenciadorJogo(Servidor* server)
{
    _servidor = server;

    _primeiroJogadorRodada = 0;
}

RankingMao GerenciadorJogo::VerificarMao(Jogador jogador)
{
    //Esse algoritmo não é, nem de perto, eficiente. 
    //Infelizmente não houve tempo para aprender opções mais otimizadas

    //Verifica as combinações possíveis de cartas da mão do jogador + mesa

    //Vetor das 7 cartas ordenadas de forma decrescente
    Carta cartas[7];
    
    //Mão do jogador
    Carta* maoJogador = jogador.GetMao();
    int cartasPosicionadas = 0;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < cartasPosicionadas+1; j++)
        {
            if(maoJogador[i] > cartas[j])
            {
                for(int k = cartasPosicionadas; k > j; k--)
                    cartas[k] = cartas[k-1];

                //Salva a carta
                cartas[j] = maoJogador[i];
                //Define que uma nova foi adicionada
                cartasPosicionadas++;
                //Avança pra próxima carta
                break;
            }
        }
    }
    //Mesa
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < cartasPosicionadas+1; j++)
        {
            if(_mesa[i] > cartas[j])
            {
                for(int k = cartasPosicionadas; k > j; k--)
                    cartas[k] = cartas[k-1];

                cartas[j] = _mesa[i];
                //Define que uma nova foi adicionada
                cartasPosicionadas++;
                //Avança pra próxima carta
                break;
            }
        }
    }

    //Separa as cartas por naipe, facilita pras análises de mesmo naipe
    //Também em ordem decrescente
    std::map<char, std::vector<Carta>> cartasPorNaipe;
    for(char naipe : referenciaNaipes)
        cartasPorNaipe[naipe] = std::vector<Carta>();
        
    for(Carta carta : cartas)
        cartasPorNaipe[carta.GetNaipe()].push_back(carta);

    //1 == Royal flush
    {
        //Analisa pra cada naipe
        for(char naipe : referenciaNaipes)
        {
            //Se tiver menos que 5 cartas, não pode ter uma sequência
            if(cartasPorNaipe[naipe].size() < 5)
                continue;

            //Se a carta de maior valor não for um Ás, então não pode ser royal flush
            if(cartasPorNaipe[naipe][0].GetValue() != "A")
                continue;

            //Como a análise é de 2 em 2, inicia na primeira e termina na penúltima
            //Como não podem ter cartas repetidas do mesmo naipe e já estão em ordem decrescente,
            //então a sequência deve ser pefeita
            for(int i = 0; i < 4; i++)
            {
                //Se a carta atual não for sequência da próxima
                if(!cartasPorNaipe[naipe][i].EhSequencia(cartasPorNaipe[naipe][i+1]))
                {
                    //Perdeu a sequência, avança pro próximo naipe
                    break;
                }

                //Se chegou aqui com i == 3, então é uma sequência perfeita
                //Como as análises são em pares, precisa de uma iteração a menos
                if(i == 3)
                {
                    //Obrigatóriamente serão as 5 cartas mais altas
                    return {1, 
                            { cartasPorNaipe[naipe][0], cartasPorNaipe[naipe][1], cartasPorNaipe[naipe][2],
                            cartasPorNaipe[naipe][3], cartasPorNaipe[naipe][4] }};
                }
            }
        }
    }

    //2 == StraightFlush
    {
        //Analisa pra cada naipe
        for(char naipe : referenciaNaipes)
        {
            //Se tiver menos que 5 cartas, não pode ter uma sequência
            if(cartasPorNaipe[naipe].size() < 5)
                continue;

            //Contagem começa em 1 porque as análises são em pares, então precisa de uma iteração a menos
            int contagemSequencia = 1;

            //Se a carta mais alta for um As e a mais fraca for um 2, pode-se ter um straight começando em A
            if(cartasPorNaipe[naipe][0].GetValue() == "A" 
                && cartasPorNaipe[naipe][cartasPorNaipe[naipe].size()-1].GetValue() == "2")
            {
                //Como sabemos que tem um A e um 2, então já temos um par de sequẽncia
                contagemSequencia++;

                //Como não tem valores repetidos pro mesmo naipe,
                //podemos só analisar se as mais fracas são sequência sem procurar repetidos
                //O limite i > 0 é indiferente, ele encerrará antes por falta de sequência ou por retorno
                for(int i = cartasPorNaipe[naipe].size() - 2; i > 0; i--)
                {
                    if(!cartasPorNaipe[naipe][i].EhSequencia(cartasPorNaipe[naipe][i+1]))
                    {
                        //Como é um caso excepcional, podemos só terminar a pesquisa se não encontrou
                        break;
                    }
                    //Se for uma sequência da anterior
                    else
                    {
                        contagemSequencia++;

                        //Se chegou aqui com contagemSequencia == 5, então é uma sequência
                        if(contagemSequencia == 5)
                        {
                            //Obrigatoriamente serão a primeira e últimas 4 cartas
                            //Como estará aqui no i = tamanho - 2, então podemos operar com o valor de i
                            return {2, 
                                    {cartasPorNaipe[naipe][0], cartasPorNaipe[naipe][i],
                                    cartasPorNaipe[naipe][i + 1], cartasPorNaipe[naipe][i + 2],
                                    cartasPorNaipe[naipe][i + 3]}};
                        }
                    }
                }
            }

            //Contagem começa em 1 porque as análises são em pares, então precisa de uma iteração a menos
            contagemSequencia = 1;

            //Como a análise é de 2 em 2, inicia na primeira e termina na penúltima
            //Como não tem valores repetidos pro mesmo naipe,
            //podemos só analisar se as mais fracas são sequência sem procurar repetidos
            for(int i = 0; i < (int)cartasPorNaipe[naipe].size()-1; i++)
            {
                //Se a carta atual não for sequência da próxima
                if(!cartasPorNaipe[naipe][i].EhSequencia(cartasPorNaipe[naipe][i+1]))
                {
                    //Reinicia a contagem
                    contagemSequencia = 1;

                    //Se não há cartas restantes suficientes para analisar se formam uma sequência
                    //4 == 5 - 1, porque a análise é de pares
                    //Então precisa de pelo menos 4 iterações pra achar uma sequência
                    if(cartasPorNaipe[naipe].size()-1 - i < 4)
                        //Avança pro próximo naipe
                        break;
                }
                //Se for uma sequência da anterior
                else
                {
                    contagemSequencia++;

                    //Se chegou aqui com contagemSequencia == 5, então é uma sequência
                    if(contagemSequencia == 5)
                    {
                        //Obrigatoriamente serão as últimas 4 cartas analisadas e a próxima
                        return {2, 
                                {cartasPorNaipe[naipe][i - 3], cartasPorNaipe[naipe][i - 2],
                                cartasPorNaipe[naipe][i - 1], cartasPorNaipe[naipe][i],
                                cartasPorNaipe[naipe][i + 1]}};
                    }
                }
            }
        }
    }

    //3 == four of a kind
    {
        //Como as análises são em pares, precisa de uma iteração a menos
        int contagemRepetidas = 1;

        //Como a análise é de 2 em 2, inicia na primeira e termina na penúltima
        for(int i = 0; i < 6; i++)
        {
            //Se as cartas não tiverem o mesmo valor
            if(cartas[i].GetValue() != cartas[i+1].GetValue())
            {
                //Reinicia a contagem
                contagemRepetidas = 1;

                //Se não há cartas restantes o suficiente pra achar um quarteto
                //3 == 6-3, porque a análise é de pares, então bastam 3 iterações
                if(i >= 3)
                    break;
            }
            else
            {
                contagemRepetidas++;

                if(contagemRepetidas == 4)
                {
                    //Se i == 2, então o quarteto é das 4 cartas mais altas
                    if(i == 2)
                    {
                        //Obrigatóriamente serão as 5 cartas mais altas
                        return {3, 
                                { cartas[0], cartas[1], cartas[2],
                                cartas[3], cartas[4] }};
                    }
                    //Se i != 2, então precisa salvar a carta mais alta
                    else
                    {
                        return {3, 
                                { cartas[0], cartas[i-2], cartas[i-1],
                                cartas[i], cartas[i+1] }};
                    }
                }
            }
        }
    }

    //4 == full house
    {
        //Para salvar as duas duplas/trios
        std::vector<int> grupos[2];
        //Como as análises são em pares, precisam de uma iteração a menos
        int contagens[2] = {1, 1};
        int grupoAtual = 0;

        //Como a análise é de 2 em 2, inicia na primeira e termina na penúltima
        for(int i = 0; i < 6; i++)
        {
            //Se as cartas não tiverem o mesmo valor
            if(cartas[i].GetValue() != cartas[i+1].GetValue())
            {
                //Se tiver achado a primeira dupla/trio
                if(grupoAtual == 0 && contagens[0] >= 2)
                {
                    //Avança pro próximo grupo
                    grupoAtual++;
                    //Salva a posição atual, pois ela era equivalente à carta anterior, então pertence ao grupo
                    grupos[grupoAtual].push_back(i);
                }
                contagens[grupoAtual] = 1;

                //Se não achou nenhuma dupla ou trio
                if(grupoAtual == 0)
                {
                    //Para achar uma dupla E um trio, precisa de pelo menos 4 iterações (i < 2)
                    if(i >= 2)
                        break;
                }
                //Se já achou um grupo
                else
                {
                    //Precisa de 4 - 2/3 (par/trio) iterações.
                    //Na troca entre grupos sempre ocorrerá um erro, então soma mais 1
                    if(i >= 2 + contagens[0] + 1)
                        break;
                }
            }
            else
            {
                //Aumenta a contagem e salva a carta atual
                contagens[grupoAtual]++;
                grupos[grupoAtual].push_back(i);

                //Se achou o full house
                if(contagens[0] + contagens[1] == 5)
                {
                    //Salva a próxima carta, pois ela é igual à atual
                    grupos[grupoAtual].push_back(i+1);

                    RankingMao rank;
                    rank.rank = 4;

                    for(int j = 0; j < (int)grupos[0].size(); j++)
                        rank.mao[j] = cartas[grupos[0][j]];

                    int offset = grupos[0].size();
                    for(int j = 0; j < (int)grupos[1].size(); j++)
                        rank.mao[j+offset] = cartas[grupos[1][j]];

                    return rank;
                }
            }
        }
    }

    //5 == flush
    {
        for(char naipe : referenciaNaipes)
        {
            //Num conjunto de 7 cartas, pode ter apenas 1 naipe com mais de 5 cartas nele
            //Assim só precisa encontrar o naipe com mais de 5 cartas
            if(cartasPorNaipe[naipe].size() >= 5)
            {
                return {5, 
                        cartasPorNaipe[naipe][0], cartasPorNaipe[naipe][1], cartasPorNaipe[naipe][2],
                        cartasPorNaipe[naipe][3], cartasPorNaipe[naipe][4]};
            }
        }
    }

    //6 == straight
    {
        std::vector<int> cartasSequencia;
        //Inicia com a carta mais alta
        cartasSequencia.push_back(0);

        //Se a carta mais alta for um As e a mais fraca for um 2, pode-se ter um straight começando em A
        if(cartas[0].GetValue() == "A" && cartas[6].GetValue() == "2")
        {
            //Como sabemos que tem um A e um 2, então já temos um par de sequẽncia
            //Como o A já foi salvo, então salva o 6
            cartasSequencia.push_back(6);

            //Podemos analisar se as mais fracas são sequência
            for(int i = 5; i > 0; i--)
            {
                //Se forem iguais, então pula pra próxima comparação
                if(cartas[i].GetValue() == cartas[i+1].GetValue())
                    continue;

                if(!cartas[i].EhSequencia(cartas[i+1]))
                {
                    //Como é um caso excepcional, podemos só terminar a pesquisa se não encontrou
                    break;
                }
                //Se for uma sequência da anterior
                else
                {
                    //Como a análise tem valores crescentes das cartas,
                    //então elas entram depois do A, que é a primeira
                    cartasSequencia.insert(cartasSequencia.begin()+1, i);

                    //Se tiver 5 valores salvos, então achou a sequência
                    if(cartasSequencia.size() == 5)
                    {
                        //Obrigatoriamente serão a primeira e últimas 4 cartas
                        //Como estará aqui no i = tamanho - 2, então podemos operar com o valor de i
                        return {6, 
                                {cartas[cartasSequencia[0]], cartas[cartasSequencia[1]],
                                cartas[cartasSequencia[2]], cartas[cartasSequencia[3]],
                                cartas[cartasSequencia[4]]}};
                    }
                }
            }
        }

        cartasSequencia.clear();
        cartasSequencia.push_back(0);

        //Como a análise é de 2 em 2, inicia na primeira e termina na penúltima
        for(int i = 0; i < 6; i++)
        {
            //Se forem iguais, então pula pra próxima comparação
            if(cartas[i].GetValue() == cartas[i+1].GetValue())
                continue;

            //Se a atual não for sequência da próxima
            if(!cartas[i].EhSequencia(cartas[i+1]))
            {
                //Reinicia a contagem
                cartasSequencia.clear();

                //Se i > 2, então não restam cartas o suficiente pra uma sequência
                //1 == 5 - 4, pois precisa de pelo menos 4 iterações
                if(i >= 2)
                    break;
                else
                    //Começa pela próxima, que vai ser o início da nova sequência
                    cartasSequencia.push_back(i+1);
            }
            else
            {
                cartasSequencia.push_back(i+1);

                //Se achou a sequência
                if(cartasSequencia.size() == 5)
                {
                    return {6, 
                            {cartas[cartasSequencia[0]], cartas[cartasSequencia[1]],
                            cartas[cartasSequencia[2]], cartas[cartasSequencia[3]],
                            cartas[cartasSequencia[4]]}};
                }
            }
        }
    }

    //7 == three of a kind
    {
        //Como as análises são em pares, precisa de uma iteração a menos
        int contagemRepetidas = 1;

        //Como a análise é de 2 em 2, inicia na primeira e termina na penúltima
        for(int i = 0; i < 6; i++)
        {
            //Se as cartas não tiverem o mesmo valor
            if(cartas[i].GetValue() != cartas[i+1].GetValue())
            {
                //Reinicia a contagem
                contagemRepetidas = 1;

                //Se não há cartas restantes o suficiente pra achar um trio
                //4 == 6-2, porque a análise é de pares, então bastam 2 iterações
                if(i >= 4)
                    break;
            }
            else
            {
                contagemRepetidas++;

                if(contagemRepetidas == 3)
                {
                    //Se i <= 1, então serão as 5 maiores cartas
                    if(i <= 3)
                    {
                        return {7,
                                cartas[0], cartas[1], cartas[2], cartas[3], cartas[4]};
                    }
                    //Se i > 1, então serão as duas maiores e o trio
                    else
                    {
                        return {7,
                                cartas[0], cartas[1], cartas[i-1], cartas[i], cartas[i+1]};
                    }
                }
            }
        }
    }

    //8 == two pair
    {
        //Para salvar as duas duplas
        int primeiraDaDupla[2];
        //Como as análises são em pares, precisam de uma iteração a menos
        int grupoAtual = 0;

        //Como a análise é de 2 em 2, inicia na primeira e termina na penúltima
        for(int i = 0; i < 6; i++)
        {
            //Se as cartas não tiverem o mesmo valor
            if(cartas[i].GetValue() != cartas[i+1].GetValue())
            {
                
                if(grupoAtual == 0)
                {
                    //Para achar duas duplas, precisa de pelo menos 3 iterações (i < 3)
                    //1 iteração pra cada dupla e 1 de erro entre elas
                    if(i >= 3)
                        break;
                }
                //Se já tiver achado a primeira dupla
                //Então precisa de iterações o suficiente só pra segunda, ou seja, 1 iteração
                //Então só não pode estar na última, que já encerraria o loop de qualquer jeito
            }
            //Se tiverem o mesmo valor, achou uma dupla
            else
            {
                //Salva a carta atual e avança pra próxima dupla
                primeiraDaDupla[grupoAtual] = i;
                grupoAtual++;

                //Se achou as duas duplas
                if(grupoAtual == 2)
                {
                    //Se a primeira dupla não for da carta mais alta
                    if(primeiraDaDupla[0] > 0)
                    {
                        return {8,
                                {cartas[0], cartas[primeiraDaDupla[0]], cartas[primeiraDaDupla[0]+1], 
                                cartas[primeiraDaDupla[1]], cartas[primeiraDaDupla[1]+1]}};
                    }
                    else
                    {
                        //Se a segunda dupla não for da segunda carta mais alta
                        if(primeiraDaDupla[1] > 2)
                            return {8,
                                    {cartas[primeiraDaDupla[0]], cartas[primeiraDaDupla[0]+1], cartas[2],
                                    cartas[primeiraDaDupla[1]], cartas[primeiraDaDupla[1]+1]}};
                        //As duas duplas são das cartas mais altas
                        else
                            return {8,
                                    {cartas[0], cartas[1], cartas[2],
                                    cartas[3], cartas[4]}};
                    }
                }

                //Pula a próxima carta, pois ela só pode fazer dupla com a atual
                i++;
            }
        }
    }

    //9 == pair
    {
        //Como a análise é de 2 em 2, inicia na primeira e termina na penúltima
        for(int i = 0; i < 6; i++)
        {
            //Se as cartas não tiverem o mesmo valor
            if(cartas[i].GetValue() != cartas[i+1].GetValue())
            {
                //Se não há cartas restantes o suficiente pra achar uma dupla
                //5 == 6-1, porque a análise é de pares, então basta 1 iteração
                if(i >= 5)
                    break;
            }
            //Se achou o par
            else
            {
                //Se i <= 3, então serão as 5 maiores cartas
                //Em i == 3 a análise é de cartas[3] e cartas[4]
                if(i <= 3)
                {
                    return {9,
                            cartas[0], cartas[1], cartas[2], cartas[3], cartas[4]};
                }
                //Se i > 3, então serão as três primeiras e a dupla
                else
                {
                    return {9,
                            cartas[0], cartas[1], cartas[2], cartas[i], cartas[i+1]};
                }
            }
        }
    }

    //10 == High card
    {
        //Apenas retorna as 5 maiores cartas
        return {10,
                cartas[0], cartas[1], cartas[2], cartas[3], cartas[4]};
    }
}

//Distribuir cartas e definir mesa
void GerenciadorJogo::IniciarRodada()
{

}

void GerenciadorJogo::RodadaDeApostas()
{

}

//Vira a próxima carta
void GerenciadorJogo::AvancarRodada()
{

}

//Checa as mãos e define o vencedor
void GerenciadorJogo::FinalizarRodada()
{

}