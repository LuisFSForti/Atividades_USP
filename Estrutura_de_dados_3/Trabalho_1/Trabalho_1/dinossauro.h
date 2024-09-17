#ifndef DINOSSAURO_H_INCLUDED
#define DINOSSAURO_H_INCLUDED

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
void LiberaDinossauro(Dinossauro dino);
void ImprimeDinossauro(Dinossauro dino);

#endif // DINOSSAURO_H_INCLUDED
