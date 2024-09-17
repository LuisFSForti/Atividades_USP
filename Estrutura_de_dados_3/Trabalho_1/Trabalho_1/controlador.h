#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dinossauro
{
    char removido;
    int encadeamento;
    int populacao;
    float tamanho;
    char unidadeMedida;
    int velocidade;
    char* nome;
    char* especie;
    char* habitat;
    char* tipo;
    char* dieta;
    char* alimento;
} Dinossauro;

//Cria um dinossauro com valores nulos
Dinossauro CriaDinossauro();

//Cria a tabela usando o endereço de entrada e saída
void CreateTable(char* enderecoE, char* enderecoS);

#endif // CONTROLADOR_H_INCLUDED
