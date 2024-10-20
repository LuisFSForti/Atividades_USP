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

//Lê o cabeçalho (apenas chamado pelo AbrirArquivo)
void LerCabecalhoArvore(FILE *arq);
//Escreve o cabeçalho salvo em cabA
void EscreverCabecalhoArvore(FILE *arq, char naoEstaNoComeco);

//Cria um arquivo com cabeçalho no endereço passado
FILE* CriarArquivoArvore(char* endereco);
//Cria um arquivo no endereço passado e lê o cabeçalho
FILE* AbrirArquivoArvore(char* endereco);
//Fecha o arquivo no endereço passado e atualiza o cabeçalho
void FecharArquivoArvore(FILE* arq);

//Para inserir um dado na árvore
Dado InserirDado(FILE* arq, Dado input, int RRNatual);
//Para encontrar um dado na árvore
long EncontrarDado(FILE* arq, long chave);

//Cria a árvore com um arquivo de dados
void CreateArvore(char* enderecoDados, char* enderecoArvore);
//Procura um dinossauro no arquivo de dados usando o arquivo de árvore
void SelectArvore(char* enderecoDados, char* enderecoArvore, char* nomeDino);
//Insere dados nos arquivos
void InserirDados(int qtd, char* enderecoDados, char* enderecoArvore);

#endif // ARVOREB_H_INCLUDED
