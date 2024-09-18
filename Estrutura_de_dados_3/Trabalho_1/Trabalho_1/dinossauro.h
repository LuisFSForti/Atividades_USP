//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 1 de ED3

#ifndef DINOSSAURO_H_INCLUDED
#define DINOSSAURO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct para armazenamento dos registros
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
//Libera o espaço alocado para dino
void LiberaDinossauro(Dinossauro dino);
//Imprime dino na tela
void ImprimeDinossauro(Dinossauro dino);

#endif // DINOSSAURO_H_INCLUDED
