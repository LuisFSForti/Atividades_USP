#include <iostream>
#include <string>
#include <map>

#include "json.hpp"
#include "Servidor.h"
#include "Carta.h"
#include "Baralho.h"
#include "Jogador.h"

#ifndef GERENCIADORJOGO_H
#define GERENCIADORJOGO_H

#define codSmall "SmallBlind"
#define codBig "BigBlind"
#define codAposta "Aposta"
#define codCheck "Check"
#define codFold "Fold"

#define codPedirNome "RequisitarNome"
#define codFornecerNome "FornecerNome"

#define codPedirAposta "DecidirAposta"
#define codComunicarAcao "ComunicacaoAcao"

struct DadosJogador
{
    int socket;
    //Ordenadas de forma decrescente
    Jogador jogador;
};

struct RankingMao
{
    int rank;
    //Ordenadas de forma decrescente
    Carta mao[5];
};

class GerenciadorJogo
{
private:
    Servidor* _servidor;

    std::vector<DadosJogador> _jogadores;
    Carta _mesa[5];

    int _primeiroJogadorRodada, _fichasEntrada = 1000, _smallBlind = 5, _bigBlind = 10;
    std::map<int, int> _apostasJogadores;
    int _pote, _jogadoresRestantes, _numeroRodada;

    RankingMao VerificarMao(Jogador jogador);

public:
    GerenciadorJogo(Servidor* server);

    void VerificarNovosJogadores();
    void VerificarJogadoresFechados();
    //Distribuir cartas e definir mesa
    void IniciarJogo();
    void RodadaDeApostas();
    //Vira a próxima carta
    void AvancarRodada();
    //Checa as mãos e define o vencedor
    void FinalizarJogo();
    //Gerenciador do jogo
    int JogarPartida();
};

#endif // GERENCIADORJOGO_H