#include "controlador.h"

Cabecalho cab;

FILE* CriarArquivo(char* endereco)
{
    FILE* arq = fopen(endereco, "wb");

    cab.status = '0';
    cab.topo = -1;
    cab.proxRRN = 0;
    cab.nroRegRem = 0;
    cab.nroPagDisco = 1;
    cab.qttCompacta = 0;

    EscreverCabecalho(arq, 0);
    for(int i = 0; i < 1579; i++)
        fwrite("$", sizeof(char), 1, arq);

    return arq;
}

/*void AbrirArquivo(FILE* arq, char* endereco)
{

}*/

void FecharArquivo(FILE* arq, char* endereco)
{
    cab.status = '1';
    fclose(arq);

    arq = fopen(endereco, "rb+");
    EscreverCabecalho(arq, 1);
    fclose(arq);
}

void EscreverCabecalho(FILE *arq, char naoEstaNoComeco)
{
    if(naoEstaNoComeco)
        fseek(arq, 0, SEEK_SET);

    fwrite(&cab.status, sizeof(char), 1, arq);
    fwrite(&cab.topo, sizeof(int), 1, arq);
    fwrite(&cab.proxRRN, sizeof(int), 1, arq);
    fwrite(&cab.nroRegRem, sizeof(int), 1, arq);
    fwrite(&cab.nroPagDisco, sizeof(int), 1, arq);
    fwrite(&cab.qttCompacta, sizeof(int), 1, arq);
}

void SalvarRegistro(Dinossauro dino, FILE* arq)
{
    fwrite("0", sizeof(char), 1, arq);

    int temporario = -1;
    fwrite(&temporario, sizeof(int), 1, arq);

    fwrite(&dino.populacao, sizeof(int), 1, arq);
    fwrite(&dino.tamanho, sizeof(int), 1, arq);
    fwrite(&dino.unidadeMedida, sizeof(char), 1, arq);
    fwrite(&dino.velocidade, sizeof(int), 1, arq);

    int bytesOcupados = sizeof(char) * 2 + sizeof(int) * 4;

    bytesOcupados += SalvarStringRegistro(dino.nome, arq);
    bytesOcupados += SalvarStringRegistro(dino.especie, arq);
    bytesOcupados += SalvarStringRegistro(dino.habitat, arq);
    bytesOcupados += SalvarStringRegistro(dino.tipo, arq);
    bytesOcupados += SalvarStringRegistro(dino.dieta, arq);
    bytesOcupados += SalvarStringRegistro(dino.alimento, arq);

    for(int i = bytesOcupados; i < 160; i++)
        fwrite("$", sizeof(char), 1, arq);
}

int SalvarStringRegistro(char* str, FILE* arq)
{
    char* aux = calloc(160, sizeof(char));
    strcpy(aux, str);

    aux[strcspn(aux, "\r")] = 0;
    aux[strcspn(aux, "\n")] = 0;
    int tam = strlen(aux);

    aux[tam] = '#';
    fwrite(aux, sizeof(char), tam+1, arq);

    free(aux);

    return tam+1;
}

//Cria a tabela usando o endereço de entrada e saída
void CreateTable(char* enderecoE, char* enderecoS)
{
    FILE* entrada = fopen(enderecoE, "rb");
    FILE* saida = CriarArquivo(enderecoS);

    if(entrada == NULL || saida == NULL)
    {
        fclose(entrada);
        printf("Falha no processamento do arquivo.");
        return;
    }

    char* linha = calloc(160, sizeof(char));
    Dinossauro dino = CriaDinossauro();
    int qtdRegistros = 0;

    fgets(linha, 160, entrada);

    while(fgets(linha, 160, entrada))
    {
        strcpy(dino.nome, strsep(linha, ","));
        strcpy(dino.dieta, strtok(NULL, ","));
        strcpy(dino.habitat, strtok(NULL, ","));

        dino.populacao = atoi(strtok(NULL, ","));

        strcpy(dino.tipo, strtok(NULL, ","));

        dino.velocidade = atoi(strtok(NULL, ","));
        dino.unidadeMedida = strtok(NULL, ",")[0];
        dino.tamanho = atof(strtok(NULL, ","));

        char* aux = strtok(NULL, ",");
        if(aux)
            printf("a");
        //strcpy(dino.especie, strtok(NULL, ","));
        strcpy(dino.alimento, strtok(NULL, "\r"));

        //ImprimeDinossauro(dino);
        SalvarRegistro(dino, saida);
        qtdRegistros++;

        LiberaDinossauro(dino);
        free(linha);

        dino = CriaDinossauro();
        linha = calloc(160, sizeof(char));
    }
    cab.proxRRN = qtdRegistros;
    cab.nroPagDisco += ceil((float)qtdRegistros / 10.0);

    fclose(entrada);
    FecharArquivo(saida, enderecoS);

    binarioNaTela(enderecoS);
}
