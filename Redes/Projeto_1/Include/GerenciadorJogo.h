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

struct DadosJogador
{
    int socket;
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
    int _primeiroJogadorRodada, _fichasEntrada = 1000, _smallBlind = 5, _bigBlind = 10;

public:
    Carta _mesa[5];

    RankingMao VerificarMao(Jogador jogador);

    GerenciadorJogo(Servidor* server);

    //Distribuir cartas e definir mesa
    void IniciarRodada();
    void RodadaDeApostas();
    //Vira a próxima carta
    void AvancarRodada();
    //Checa as mãos e define o vencedor
    void FinalizarRodada();
};

#endif // GERENCIADORJOGO_H