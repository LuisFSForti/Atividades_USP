//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct specie
{
    int SPECIES_ID; //4 bytes
    char* NAME; //41 bytes
    char* SCIENTIFIC_NAME; //61 bytes
    int POPULATION; //4 bytes
    char* STATUS; //9 bytes
    float LOCATION[2]; //2 floats de 4 bytes
    int HUMAN_IMPACT; //4 bytes
} SPECIE;

SPECIE CriaEspecie();
SPECIE CriarDoConsole();
SPECIE CriarDoArquivo(FILE* arq);
void LiberarEspecie(SPECIE especie);
void ImprimirDados(SPECIE especie);
void GravarDados(SPECIE especie, FILE* arq);
