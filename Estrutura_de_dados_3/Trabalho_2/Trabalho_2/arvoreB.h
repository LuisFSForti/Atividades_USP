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
//Escreve o cabeçalho salvo em cab
void EscreverCabecalhoArvore(FILE *arq, char naoEstaNoComeco);

//Cria um arquivo com cabeçalho no endereço passado
FILE* CriarArquivoArvore(char* endereco);
//Cria um arquivo no endereço passado e lê o cabeçalho
FILE* AbrirArquivoArvore(char* endereco);
//Fecha o arquivo no endereço passado e atualiza o cabeçalho
void FecharArquivoArvore(FILE* arq);

long EncontrarRegistro(FILE* arq, long chave);

void CreateArvore(char* enderecoDados, char* enderecoArvore);
void SelectArvore(char* enderecoDados, char* enderecoArvore, char* nomeDino);
void InserirDados(int qtd, char* enderecoDados, char* enderecoArvore);

#endif // ARVOREB_H_INCLUDED
