#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoes_fornecidas.h"
#include "dinossauro.h"

typedef struct cabecalho
{
    char status;
    int topo;
    int proxRRN;
    int nroRegRem;
    int nroPagDisco;
    int qttCompacta;
} Cabecalho;

void LerCabecalho(FILE *arq);
void EscreverCabecalho(FILE *arq, char naoEstaNoComeco);
FILE* CriarArquivo(char* endereco);
FILE* AbrirArquivo(char* endereco);
void FecharArquivo(FILE* arq, char* endereco);
void SalvarRegistro(Dinossauro dino, FILE* arq);
int SalvarStringRegistro(char* str, FILE* arq);
void SelectTable(char* enderecoE);
int TipoRemocao(char* comando);
int EncontrarRRN(FILE* arq, int RRNinicial, int idBusca, char* valS);
void RemoverRegistros(char* enderecoE, int qtd);

//Cria a tabela usando o endereço de entrada e saída
void CreateTable(char* enderecoE, char* enderecoS);

#endif // CONTROLADOR_H_INCLUDED
