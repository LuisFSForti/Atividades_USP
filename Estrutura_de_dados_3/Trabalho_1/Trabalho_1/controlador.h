#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

FILE* CriarArquivo(char* endereco);
void FecharArquivo(FILE* arq, char* endereco);
void EscreverCabecalho(FILE *arq, char naoEstaNoComeco);
void SalvarRegistro(Dinossauro dino, FILE* arq);
int SalvarStringRegistro(char* str, FILE* arq);

//Cria a tabela usando o endereço de entrada e saída
void CreateTable(char* enderecoE, char* enderecoS);

#endif // CONTROLADOR_H_INCLUDED
