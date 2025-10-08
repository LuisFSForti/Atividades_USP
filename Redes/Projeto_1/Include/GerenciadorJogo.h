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

#define codigo "Cod"

#define codSmall "SmallBlind"
#define codBig "BigBlind"
#define codAposta "Aposta"
#define codFold "Fold"
#define codGanho "Ganho"

#define codComunicacaoDesconectou "JogadorDesconectou"
#define codComunicacao "Comunicacao"
#define codComunicacaoFinalizacao "Finalizacao"

#define codPedirNome "RequisitarNome"
#define codFornecerNome "FornecerNome"

#define codPedirAposta "RequisitarAposta"

#define codTabelaFichasRestantes "TabelaFichas"
#define codValorPote "ValorPote"
#define codMaiorAposta "MaiorAposta"
#define codAtributoNomeJogador "NomeJogador"
#define codAtributoValor "Valor"
#define codAtributoMensagem "Msg"

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

    //vector e não map para manter a ordem dos jogadores
    std::vector<DadosJogador> _jogadores;
    Carta _mesa[5];

    int _primeiroJogadorRodada, _maiorAposta, _fichasEntrada = 1000, _smallBlind = 5, _bigBlind = 10;
    std::map<int, int> _apostasJogadores;
    int _pote, _jogadoresRestantes, _numeroRodada;

    RankingMao VerificarMao(Jogador jogador);
    
    //Distribuir cartas e definir mesa
    void IniciarJogo();
    void RodadaDeApostas(int jogadorAtual);
    //Vira a próxima carta
    void AvancarRodada();
    //Checa as mãos e define o vencedor
    void FinalizarJogo();

public:
    GerenciadorJogo(Servidor* server);

    void VerificarNovosJogadores();
    void VerificarJogadoresFechados();

    //Gerenciador do jogo
    void JogarPartida();
};

#endif // GERENCIADORJOGO_H