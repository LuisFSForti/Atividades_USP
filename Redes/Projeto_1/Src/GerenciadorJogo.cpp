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

void GerenciadorJogo::VerificarNovosJogadores()
{
    for(int newSocket : _servidor->GetNewSockets())
    {
        std::string nomeJogador;
        nlohmann::json msg;
        msg[codigo] = codPedirNome;

        _servidor->SendClientMessage(newSocket, msg);

        msg.clear();
        do
        {
            msg = _servidor->GetClientMessage(newSocket);
        } while (msg.is_null());

        if(msg[codigo] == codFornecerNome)
        {
            nomeJogador = msg[codAtributoNomeJogador];

            _jogadores.push_back({ newSocket, 
                                Jogador(Carta(), Carta(), _fichasEntrada, nomeJogador) });

            std::cout << "\nJogador " << nomeJogador << " entrou!" << std::endl << std::endl;
        }
        else
        {
            std::cerr << "Mensagem inválida de adição de jogador do socket " << 
                            newSocket << std::endl;


            _servidor->FecharServidor();
            exit(EXIT_FAILURE);
        }
    }
}

void GerenciadorJogo::VerificarJogadoresFechados()
{
    std::vector<int> jogadoresQueFecharam = _servidor->GetClosedSockets();
    for(int closedSocket : jogadoresQueFecharam)
    {
        std::cout << closedSocket << std::endl;
        for(int i = 0; i < (int)_jogadores.size(); i++)
        {
            if(_jogadores[i].socket == closedSocket)
            {
                std::cout << _jogadores[i].jogador.GetNome()
                        << " desconectou!" << std::endl;

                _jogadores.erase(_jogadores.begin() + i);
                i--;

                //Se saiu um jogador com indíce anterior ao primeiro jogador da rodada
                if(i < _primeiroJogadorRodada)
                {
                    _primeiroJogadorRodada--;
                }
                //Se saiu o primeiro jogador da rodada
                else if(i == _primeiroJogadorRodada)
                {
                    //O valor não altera, pois agora é do próximo jogador
                    //Recalcula para ver se não será o 0, caso quem saiu foi o último
                    _primeiroJogadorRodada %= _jogadores.size();
                }
            }
        }
    }
}

//Distribuir cartas e definir mesa
void GerenciadorJogo::IniciarJogo()
{
    int jogadorAtual = _primeiroJogadorRodada;
    _pote = 0;
    _jogadoresRestantes = _jogadores.size();
    _numeroRodada = 0;
    _apostasJogadores.clear();
    Baralho baralhoAtual = Baralho();

    for(DadosJogador& jog : _jogadores)
    {
        jog.jogador.TrocarMao(baralhoAtual.PegarCarta(), baralhoAtual.PegarCarta());
        _servidor->SendClientMessage(jog.socket, jog.jogador.ToJson());

        _apostasJogadores[jog.socket] = 0;
    }

    for(int i = 0; i < 5; i++)
    {
        _mesa[i] = baralhoAtual.PegarCarta();
    }

    //O primeiro jogador da rodada aposta o small blind
    _apostasJogadores[_jogadores[jogadorAtual].socket] = _smallBlind;
    _jogadores[jogadorAtual].jogador.Apostar(_smallBlind);

    //Salva quem fez o small blind
    nlohmann::json msgComunicacao;
    msgComunicacao[codigo] = codComunicacao;

    nlohmann::json msg;
    msg[codigo] = codSmall;
    msg[codAtributoValor] = _smallBlind;
    msgComunicacao[codAtributoMensagem] = "Small blind " + std::to_string(_smallBlind) + " feito por " 
                    + _jogadores[jogadorAtual].jogador.GetNome() + "\n";

    //Avisa o jogador que ele apostou o small blind
    _servidor->SendClientMessage(_jogadores[jogadorAtual].socket, msg);

    //Avança para o próximo jogador, indo de volta para o primeiro se necessário
    jogadorAtual = (jogadorAtual + 1) % _jogadores.size();

    //O segundo jogador da rodada aposta o big blind
    _apostasJogadores[_jogadores[jogadorAtual].socket] = _bigBlind;
    _jogadores[jogadorAtual].jogador.Apostar(_bigBlind);

    //Salva quem fez o big blind
    msg.clear();
    msg[codigo] = codBig;
    msg[codAtributoValor] = _bigBlind;
    std::string msgAux = "Big blind " + std::to_string(_bigBlind) + " feito por " 
                    + _jogadores[jogadorAtual].jogador.GetNome() + "\n";
    msgComunicacao[codAtributoMensagem] = msgComunicacao.value(codAtributoMensagem, "") 
                    + msgAux;

    //Avisa o jogador que ele apostou o small blind
    _servidor->SendClientMessage(_jogadores[jogadorAtual].socket, msg);

    //Avisa todos os jogadores sobre os blinds e os estados das apostas atuais
    for(DadosJogador jogador : _jogadores)
        msgComunicacao[codTabelaFichasRestantes][jogador.jogador.GetNome()] = jogador.jogador.GetFichas();

    msgComunicacao[codMaiorAposta][codAtributoNomeJogador] = _jogadores[jogadorAtual].jogador.GetNome();
    msgComunicacao[codMaiorAposta][codAtributoValor] = _apostasJogadores[_jogadores[jogadorAtual].socket];
    msgComunicacao[codValorPote] = _pote;

    _servidor->BroadcastMessage(msgComunicacao);

    //Avança para o próximo jogador
    jogadorAtual = (jogadorAtual + 1) % _jogadores.size();

    //Inicia a rodada de apostas
    RodadaDeApostas(jogadorAtual);
}

void GerenciadorJogo::RodadaDeApostas(int jogadorAtual)
{
    //Para todos interagirem pelo menos uma vez, o último jogador que aumentou é, inicialmente, o primeiro a jogar
    _maiorAposta = jogadorAtual;
    do
    {
        //Se ele deu fold anteriormente
        if(_apostasJogadores[_jogadores[jogadorAtual].socket] == -1)
            continue;

        //Se ele deu all-in
        if(_jogadores[jogadorAtual].jogador.GetFichas() == 0)
            continue;

        nlohmann::json msg;
        msg[codigo] = codPedirAposta;
        //Manda quanto ele deve aumentar, no mínimo
        msg[codAtributoValor] = _apostasJogadores[_jogadores[_maiorAposta].socket] 
                                - _apostasJogadores[_jogadores[jogadorAtual].socket];

        _servidor->SendClientMessage(_jogadores[jogadorAtual].socket, msg);

        do
        {
            nlohmann::json msgCommDesc;
            msgCommDesc[codigo] = codComunicacaoDesconectou;

            bool removeuAtual = false;
            std::vector<int> jogadoresQueFecharam = _servidor->GetClosedSockets();
            for(int closedSocket : jogadoresQueFecharam)
            {
                for(int i = 0; i < (int)_jogadores.size(); i++)
                {
                    if(_jogadores[i].socket == closedSocket)
                    {
                        _pote += _apostasJogadores[_jogadores[i].socket];
                        _pote += _jogadores[i].jogador.GetFichas();

                        std::cout << _jogadores[i].jogador.GetNome()
                                << " desconectou!" << std::endl;

                        //Adiciona o nome do jogador que desconectou
                        std::string msgAux = _jogadores[i].jogador.GetNome()
                                            + " desconectou, aumentando o pote para "
                                            + std::to_string(_jogadores[i].jogador.GetFichas())
                                            + "!\n";
                        msgCommDesc[codAtributoMensagem] = msgCommDesc.value(codAtributoMensagem, "")
                                                        + msgAux;

                        _apostasJogadores.erase(_jogadores[i].socket);
                        _jogadores.erase(_jogadores.begin() + i);
                        i--;
                        _jogadoresRestantes--;

                        //Se saiu um jogador com indíce anterior ao primeiro jogador da rodada
                        if(i < _primeiroJogadorRodada)
                            _primeiroJogadorRodada--;
                        //Se saiu o primeiro jogador da rodada
                        else if(i == _primeiroJogadorRodada)
                            //O valor não altera, pois agora é do próximo jogador
                            //Recalcula para ver se não será o 0, caso quem saiu foi o último
                            _primeiroJogadorRodada %= _jogadores.size();

                        //Mesma análise pro último jogador que aumentou
                        if(i < _maiorAposta)
                            _maiorAposta--;
                        else if(i == _maiorAposta)
                            _maiorAposta %= _jogadores.size();

                        //Mesma análise pro jogador atual
                        if(i < jogadorAtual)
                            jogadorAtual--;
                        else if(i == jogadorAtual)
                        {
                            jogadorAtual %= _jogadores.size();
                            removeuAtual = true;
                        }
                    }
                }
            }
            //Avisa os jogadores quem desconectou
            if(jogadoresQueFecharam.size() > 0)
            {
                _servidor->BroadcastMessage(msgCommDesc);


                //Se há 1 ou menos jogadores restantes
                if(_jogadoresRestantes <= 1)
                    return;

                std::cout << "Lugar errado" << std::endl;

                //Se o jogador atual foi removido
                if (removeuAtual)
                    //Avança pro próximo
                    continue;
            }

            msg = _servidor->GetClientMessage(_jogadores[jogadorAtual].socket);
        } while (msg.is_null());
        
        nlohmann::json msgComunicacao;
        msgComunicacao[codigo] = codComunicacao;

        if(msg[codigo] == codAposta)
        {
            int valorAposta = msg[codAtributoValor];

            if(valorAposta == 0)
            {
                std::cout << "Check de " << _jogadores[jogadorAtual].jogador.GetNome() 
                << std::endl;

                msgComunicacao[codAtributoMensagem] = _jogadores[jogadorAtual].jogador.GetNome() 
                            + " deu check";
            }
            else
            {
                //Se apostou mais do que tem
                //Ou apostou menos do que o necessário
                //Aqui causa um erro, mas tem validação no lado do cliente para cuidar disso
                if(_jogadores[jogadorAtual].jogador.GetFichas() < valorAposta ||
                    valorAposta < _apostasJogadores[_jogadores[_maiorAposta].socket] 
                                    - _apostasJogadores[_jogadores[jogadorAtual].socket])
                {
                    std::cerr << "Aposta inválida do jogador " << 
                                _jogadores[jogadorAtual].jogador.GetNome() << std::endl;
                        
                    _servidor->FecharServidor();
                    exit(EXIT_FAILURE);
                }

                _apostasJogadores[_jogadores[jogadorAtual].socket] += valorAposta;
                _jogadores[jogadorAtual].jogador.Apostar(valorAposta);

                //Se aumentou a aposta
                if(_apostasJogadores[_jogadores[jogadorAtual].socket] > 
                        _apostasJogadores[_jogadores[_maiorAposta].socket])
                    _maiorAposta = jogadorAtual;

                //Se ele deu all-in
                if(_jogadores[jogadorAtual].jogador.GetFichas() == 0)
                {
                    std::cout << "All-in de " << _jogadores[jogadorAtual].jogador.GetNome() 
                    << " = " 
                    << std::to_string(_apostasJogadores[_jogadores[jogadorAtual].socket]) 
                    << std::endl;

                    msgComunicacao[codAtributoMensagem] = _jogadores[jogadorAtual].jogador.GetNome()
                            + " deu all-in, aumentando a aposta para "
                            + std::to_string(_apostasJogadores[_jogadores[jogadorAtual].socket]);
                }
                else
                {
                    std::cout << "Aposta de " << _jogadores[jogadorAtual].jogador.GetNome() 
                    << " = " 
                    << std::to_string(_apostasJogadores[_jogadores[jogadorAtual].socket]) 
                    << std::endl;

                    msgComunicacao[codAtributoMensagem] = _jogadores[jogadorAtual].jogador.GetNome()
                            + " aumentou a aposta para "
                            + std::to_string(_apostasJogadores[_jogadores[jogadorAtual].socket]);
                } 
            }                       
        }
        else if(msg[codigo] == codFold)
        {
            _pote += _apostasJogadores[_jogadores[jogadorAtual].socket];
            _apostasJogadores[_jogadores[jogadorAtual].socket] = -1;
            _jogadoresRestantes--;

            //Se há apenas um jogador restante
            if(_jogadoresRestantes <= 1)
                break;

            std::cout << "Fold de " << _jogadores[jogadorAtual].jogador.GetNome() 
                << std::endl;

            msgComunicacao[codAtributoMensagem] = _jogadores[jogadorAtual].jogador.GetNome() 
                        + " deu fold, aumentando o pote para "
                        + std::to_string(_pote);
        }
        else
        {
            std::cerr << "Código de retorno da aposta inválido!" << std::endl;
            _servidor->FecharServidor();
            exit(EXIT_FAILURE);
        }

        //Salva os estados das apostas atuais
        for(DadosJogador jogador : _jogadores)
            msgComunicacao[codTabelaFichasRestantes][jogador.jogador.GetNome()] = jogador.jogador.GetFichas();

        msgComunicacao[codMaiorAposta][codAtributoNomeJogador] = 
                    _jogadores[_maiorAposta].jogador.GetNome();
        msgComunicacao[codMaiorAposta][codAtributoValor] = 
                    _apostasJogadores[_jogadores[_maiorAposta].socket];
        msgComunicacao[codValorPote] = _pote;

        //Informa a todos os jogadores o novo estado do jogo, incluindo o novo número de fichas dos jogadores
        _servidor->BroadcastMessage(msgComunicacao);

        jogadorAtual = (jogadorAtual + 1) % _jogadores.size();
    } while(jogadorAtual != _maiorAposta);
}

//Vira a próxima carta
void GerenciadorJogo::AvancarRodada()
{
    if(_numeroRodada == 0)
    {
        std::cout << "Virando as primeiras 3 cartas" << std::endl;

        for(int i = 0; i < 3; i++)
            _servidor->BroadcastMessage(_mesa[i].ToJson());

        _numeroRodada++;
    }
    else if(_numeroRodada == 1)
    {
        std::cout << "Virando a terceira carta" << std::endl;

        _servidor->BroadcastMessage(_mesa[3].ToJson());

        _numeroRodada++;
    }
    else
    {
        std::cout << "Virando a última carta" << std::endl;

        _servidor->BroadcastMessage(_mesa[4].ToJson());

        _numeroRodada++;
    }

    //Avisa todos os jogadores sobre os estados das apostas atuais
    nlohmann::json msgComunicacao;
    msgComunicacao[codigo] = codComunicacao;
    for(DadosJogador jogador : _jogadores)
        msgComunicacao[codTabelaFichasRestantes][jogador.jogador.GetNome()] = jogador.jogador.GetFichas();

    msgComunicacao[codMaiorAposta][codAtributoNomeJogador] = _jogadores[_maiorAposta].jogador.GetNome();
    msgComunicacao[codMaiorAposta][codAtributoValor] = _apostasJogadores[_jogadores[_maiorAposta].socket];
    msgComunicacao[codValorPote] = _pote;

    _servidor->BroadcastMessage(msgComunicacao);
}

//Checa as mãos e define o vencedor
void GerenciadorJogo::FinalizarJogo()
{
    //Para diferentes quantidades de apostas, tem diferentes prêmios
    std::vector<int> apostasOrdenadas;

    for(auto& aposta : _apostasJogadores)
    {
        //Se não foi um fold
        if(aposta.second != -1)
            apostasOrdenadas.push_back(aposta.second);
    }

    //Ordena de forma crescente e sem duplicatas
    std::sort(apostasOrdenadas.begin(), apostasOrdenadas.end());
    apostasOrdenadas.erase(std::unique(apostasOrdenadas.begin(), apostasOrdenadas.end()), apostasOrdenadas.end());

    //Quanto cada jogador ganhou a cada pote
    std::map<int, int> ganhosPorJogador;
    for(DadosJogador jogador : _jogadores)
        ganhosPorJogador[jogador.socket] = 0;

    nlohmann::json mensagemGanhoGeral;
    mensagemGanhoGeral[codigo] = codComunicacaoFinalizacao;

    for(int i = 0; i < (int)apostasOrdenadas.size(); i++)
    {
        //Mapa com todos os maiores rankings
        //Só terá mais de 1 em caso de empate
        std::map<int, RankingMao> ranksVencedores;

        //Determina que não tem um maior rank ainda
        int maiorRank = -1;

        //Define os vencedores
        for(DadosJogador jogador : _jogadores)
        {
            //Avalia apenas para os jogadores deste pote
            if(_apostasJogadores[jogador.socket] < apostasOrdenadas[i])
                continue;

            //Se ele não deu fold
            if(_apostasJogadores[jogador.socket] != -1)
            {
                RankingMao rankJogador = VerificarMao(jogador.jogador);

                //Se ainda não tem um maior rank definido
                if(maiorRank == -1)
                {
                    //Salva o novo ranking
                    maiorRank = jogador.socket;
                    ranksVencedores[maiorRank] = rankJogador;
                    continue;
                }

                //Se o novo ranking é maior que o anterior
                if(rankJogador.rank > ranksVencedores[maiorRank].rank)
                {
                    //Limpa a lista
                    ranksVencedores.clear();

                    //Salva o novo ranking
                    maiorRank = jogador.socket;
                    ranksVencedores[maiorRank] = rankJogador;
                }
                //Se forem iguais
                else if(rankJogador.rank == ranksVencedores[maiorRank].rank)
                {
                    //Compara as cartas da jogada de cada um para desempate
                    bool desempatou = false;
                    for(int j = 0; j < 5; j++)
                    {
                        //Se a carta do jogador atual for maior que a carta do maior ranking
                        if(rankJogador.mao[j] > ranksVencedores[maiorRank].mao[j])
                        {
                            desempatou = true;

                            //Limpa a lista
                            ranksVencedores.clear();

                            //Salva o novo ranking
                            maiorRank = jogador.socket;
                            ranksVencedores[maiorRank] = rankJogador;
                            break;
                        }
                        //Se a carta do maior ranking for maior que a carta do jogador atual
                        else if(ranksVencedores[maiorRank].mao[j] > rankJogador.mao[j])
                        {
                            desempatou = true;
                            break;
                        }
                    }
                    //Se não desempatou
                    if(!desempatou)
                    {
                        //Adiciona o jogador atual à lista dos maiores rankings
                        ranksVencedores[jogador.socket] = rankJogador;
                    }
                }
            }
        }

        //O valor da aposta do pote
        int aposta = apostasOrdenadas[i];
        //Se não for o primeiro, então precisa diminuir ele, pois é só o que restou do anterior
        if(i > 0)
        {
            //Diminui pelo valor do pote anterior
            aposta -= apostasOrdenadas[i-1];
        }
        //Se i == 0, então adiciona o valor do pote
        else
        {
            aposta += _pote;
        }

        //std::map<int, RankingMao> ranksVencedores
        //rankJogador.first == socket
        //rankJogador.second == rank
        for(auto& rankJogador : ranksVencedores)
        {
            //Valor extra da conversão -> taxa do cassino
            //Divide o valor total pelo número de vencedores do pote
            ganhosPorJogador[rankJogador.first] += (int)aposta/ranksVencedores.size();
        }
    }

    //Informa para cada jogador quanto ele ganhou nesta rodada
    nlohmann::json mensagemGanho;
    for(DadosJogador& jogador : _jogadores)
    {
        mensagemGanho.clear();

        mensagemGanho[codigo] = codGanho;
        mensagemGanho[codAtributoValor] = ganhosPorJogador[jogador.socket];

        jogador.jogador.Coletar(ganhosPorJogador[jogador.socket]);

        std::string msgAux = jogador.jogador.GetNome() + " ganhou " 
                                + std::to_string(ganhosPorJogador[jogador.socket]) 
                                + ", tendo agora " 
                                + std::to_string(jogador.jogador.GetFichas())
                                + " fichas!\n";
        mensagemGanhoGeral[codAtributoMensagem] = mensagemGanhoGeral.value(codAtributoMensagem, "")
                                                    + msgAux;

        _servidor->SendClientMessage(jogador.socket, mensagemGanho);
    }

    _servidor->BroadcastMessage(mensagemGanhoGeral);
}

void GerenciadorJogo::JogarPartida()
{
    if(_jogadores.size() < 2)
    {
        std::cout << "Quantidade insuficiente de jogadores!" << std::endl;
        return;
    }

    IniciarJogo();
    for(int i = 0; i < 3; i++)
    {
        if(_jogadoresRestantes <= 1)
            break;

        AvancarRodada();
        RodadaDeApostas(_primeiroJogadorRodada);
    }
    FinalizarJogo();
    _primeiroJogadorRodada++;
}