//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 2 de ED3

#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoes_fornecidas.h"
#include "funcoes_auxiliares.h"
#include "dinossauro.h"
#include "controlador.h"

#define tamPagA 93
#define qtdValReg 4

typedef struct cabecalhoArvore
{
    char status;
    int noRaiz;
    int RRNproxNo;
} CabecalhoArvore;

typedef struct dado
{
    long chave;
    long pos;
    int pontD;
} Dado;

//L� o cabe�alho (apenas chamado pelo AbrirArquivo)
void LerCabecalhoArvore(FILE *arq);
//Escreve o cabe�alho salvo em cabA
void EscreverCabecalhoArvore(FILE *arq, char naoEstaNoComeco);

//Cria um arquivo com cabe�alho no endere�o passado
FILE* CriarArquivoArvore(char* endereco);
//Cria um arquivo no endere�o passado e l� o cabe�alho
FILE* AbrirArquivoArvore(char* endereco);
//Fecha o arquivo no endere�o passado e atualiza o cabe�alho
void FecharArquivoArvore(FILE* arq);

//Para inserir um dado na �rvore
Dado InserirDado(FILE* arq, Dado input, int RRNatual);
//Para encontrar um dado na �rvore
long EncontrarDado(FILE* arq, long chave);

//Cria a �rvore com um arquivo de dados
void CreateArvore(char* enderecoDados, char* enderecoArvore);
//Procura um dinossauro no arquivo de dados usando o arquivo de �rvore
void SelectArvore(char* enderecoDados, char* enderecoArvore, char* nomeDino);
//Insere dados nos arquivos
void InserirDados(int qtd, char* enderecoDados, char* enderecoArvore);

#endif // ARVOREB_H_INCLUDED
