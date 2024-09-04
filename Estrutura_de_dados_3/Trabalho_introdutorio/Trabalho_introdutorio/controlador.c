#include "./controlador.h"
#include "./funcoesFornecidas.h"

SPECIE CriaEspecie()
{
    SPECIE especie;

    especie.SPECIES_ID = 0; //Neutro

    especie.NAME = malloc(41 * sizeof(char*));
    for(int i = 0; i < 41; i++)
        especie.NAME[i] = '$'; //Caractere de espaco em branco

    especie.SCIENTIFIC_NAME = malloc(61 * sizeof(*especie.SCIENTIFIC_NAME));
    for(int i = 0; i < 61; i++)
        especie.SCIENTIFIC_NAME[i] = '$'; //Caractere de espaco em branco

    especie.POPULATION = 0; //Nulo

    especie.STATUS = malloc(9 * sizeof(*especie.STATUS));
    for(int i = 0; i < 9; i++)
        especie.STATUS[i] = '$'; //Caractere de espaco em branco

    memccpy(especie.LOCATION, (int[]){0, 0}, sizeof(float), 2); //Neutro

    especie.HUMAN_IMPACT = 0; //Nulo

    return especie;
}

SPECIE CriarDoConsole()
{
    SPECIE especie = CriaEspecie();

    scanf("%d", &especie.SPECIES_ID);
    readline(especie.NAME);
    readline(especie.SCIENTIFIC_NAME);
    scanf("%d", &especie.POPULATION);
    readline(especie.STATUS);
    scanf("%f", &especie.LOCATION[0]);
    scanf("%f", &especie.LOCATION[1]);
    scanf("%d", &especie.HUMAN_IMPACT);

    return especie;
}

void LiberarEspecie(SPECIE especie)
{
    free(especie.NAME);
    free(especie.SCIENTIFIC_NAME);
    free(especie.STATUS);
}

SPECIE CriarDoArquivo(FILE* arq)
{
    SPECIE especie = CriaEspecie();

    if(!fread(&especie.SPECIES_ID, sizeof(int), 1, arq))
    {
        especie.SPECIES_ID = -1;
        return especie;
    }

    fread(especie.NAME, sizeof(char), 41, arq);
    fread(especie.SCIENTIFIC_NAME, sizeof(char), 61, arq);
    fread(&especie.POPULATION, sizeof(int), 1, arq);
    fread(especie.STATUS, sizeof(char), 9, arq);
    fread(&especie.LOCATION[0], sizeof(float), 1, arq);
    fread(&especie.LOCATION[1], sizeof(float), 1, arq);
    fread(&especie.HUMAN_IMPACT, sizeof(int), 1, arq);

    return especie;
}

void ImprimirDados(SPECIE especie)
{
    printf("ID: %d\n", especie.SPECIES_ID);
    printf("Nome: %s\n", especie.NAME);
    printf("Nome Científico: %s\n", especie.SCIENTIFIC_NAME);

    if(especie.POPULATION == 0)
        printf("População: NULO\n");
    else
        printf("População: %d\n", especie.POPULATION);

    printf("Status: %s\n", especie.STATUS);
    printf("Localização: (%.2f, %.2f)\n", especie.LOCATION[0], especie.LOCATION[1]);

    if(especie.HUMAN_IMPACT == 0)
        printf("Impacto Humano: NULO\n\n");
    else
        printf("Impacto Humano: %d\n\n", especie.HUMAN_IMPACT);
}

void GravarDados(SPECIE especie, FILE* arq)
{
    fwrite(&especie.SPECIES_ID, sizeof(int), 1, arq);
    fwrite(especie.NAME, sizeof(char), 41, arq);
    fwrite(especie.SCIENTIFIC_NAME, sizeof(char), 61, arq);
    fwrite(&especie.POPULATION, sizeof(int), 1, arq);
    fwrite(especie.STATUS, sizeof(char), 9, arq);
    fwrite(&especie.LOCATION[0], sizeof(float), 1, arq);
    fwrite(&especie.LOCATION[1], sizeof(float), 1, arq);
    fwrite(&especie.HUMAN_IMPACT, sizeof(int), 1, arq);
}
