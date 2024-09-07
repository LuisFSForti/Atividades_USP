/*#######

Luis Filipe Silva Forti - 14592348
Lucien Rodrigues Franzen - 14554835

Trabalho Introdut�rio de ED3



main.c - m�dulo principal que contra comandos e opera��es de cria��o de esp�cies
e de recupera��o e grava��o de dados em bin�rio

controlador.c - m�dulo das fun��es criadas para lidar com os dados bin�rios e entrada

funcoesFornecidas - m�dulo com fun��es pr�-fornecidas para o trabalho

########*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para lidar com strings

typedef struct specie //struct da esp�cie com seus campos de dados.
{
    int SPECIES_ID; //4 bytes
    char* NAME; //41 bytes
    char* SCIENTIFIC_NAME; //61 bytes
    int POPULATION; //4 bytes
    char* STATUS; //9 bytes
    float LOCATION[2]; //2 floats de 4 bytes
    int HUMAN_IMPACT; //4 bytes
} SPECIE;

SPECIE CriaEspecie(); //Fun��o que cria uma struct esp�cie nova com valores
//padr�es indicando estar sem informa��es
SPECIE CriarDoConsole(); //Fun��o que cria uma struct esp�cie com valores
//indicados a partir do console
SPECIE CriarDoArquivo(FILE* arq); //Fun��o que cria uma struct esp�cie com valores
//indicados a partir do arqu�vo de registros, come�ando em onde o ponteiro do arquivo est�.
//Ela resgata os dados de um registro do arquivo e os transforma para essa struct.
void LiberarEspecie(SPECIE especie); //Libera a mem�ria de uma struct esp�cie, a apagando
void ImprimirDados(SPECIE especie); //Mostra os dados de uma struct esp�cie na formata��o
//certa do problema
void GravarDados(SPECIE especie, FILE* arq); //Grava os dados de uma struct esp�cie no
//arquivo de registros, os transformando para a forma bin�ria requesitada.
