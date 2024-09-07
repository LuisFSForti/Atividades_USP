/*#######

Luis Filipe Silva Forti - 14592348
Lucien Rodrigues Franzen - 14554835

Trabalho Introdutório de ED3



main.c - módulo principal que contra comandos e operações de criação de espécies
e de recuperação e gravação de dados em binário

controlador.c - módulo das funções criadas para lidar com os dados binários e entrada

funcoesFornecidas - módulo com funções pré-fornecidas para o trabalho

########*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para lidar com strings

typedef struct specie //struct da espécie com seus campos de dados.
{
    int SPECIES_ID; //4 bytes
    char* NAME; //41 bytes
    char* SCIENTIFIC_NAME; //61 bytes
    int POPULATION; //4 bytes
    char* STATUS; //9 bytes
    float LOCATION[2]; //2 floats de 4 bytes
    int HUMAN_IMPACT; //4 bytes
} SPECIE;

SPECIE CriaEspecie(); //Função que cria uma struct espécie nova com valores
//padrões indicando estar sem informações
SPECIE CriarDoConsole(); //Função que cria uma struct espécie com valores
//indicados a partir do console
SPECIE CriarDoArquivo(FILE* arq); //Função que cria uma struct espécie com valores
//indicados a partir do arquívo de registros, começando em onde o ponteiro do arquivo está.
//Ela resgata os dados de um registro do arquivo e os transforma para essa struct.
void LiberarEspecie(SPECIE especie); //Libera a memória de uma struct espécie, a apagando
void ImprimirDados(SPECIE especie); //Mostra os dados de uma struct espécie na formatação
//certa do problema
void GravarDados(SPECIE especie, FILE* arq); //Grava os dados de uma struct espécie no
//arquivo de registros, os transformando para a forma binária requesitada.
