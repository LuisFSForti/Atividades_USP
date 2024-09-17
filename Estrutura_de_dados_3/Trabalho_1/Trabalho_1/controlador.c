#include "funcoes_fornecidas.h"
#include "controlador.h"

//Cria um dinossauro com valores nulos
Dinossauro CriaDinossauro()
{
    Dinossauro dino;
    dino.removido = 0;
    dino.encadeamento = -1;
    dino.populacao = -1;
    dino.tamanho = -1;
    dino.unidadeMedida = '$';
    dino.velocidade = -1;
    dino.nome = calloc(160, sizeof(char)); //Valor inválido, deve ser corrigido posteriormente
    dino.especie = calloc(160, sizeof(char)); //Valor inválido, deve ser corrigido posteriormente
    dino.habitat = calloc(160, sizeof(char));
    dino.tipo = calloc(160, sizeof(char));
    dino.dieta = calloc(160, sizeof(char)); //Valor inválido, deve ser corrigido posteriormente
    dino.alimento = calloc(160, sizeof(char));

    return dino;
}

void LiberaDinossauro(Dinossauro dino)
{
    if(dino.nome)
        free(dino.nome);

    if(dino.especie)
        free(dino.especie);

    if(dino.habitat)
        free(dino.habitat);

    if(dino.tipo)
        free(dino.tipo);

    if(dino.dieta)
        free(dino.dieta);

    if(dino.alimento)
        free(dino.alimento);
}

void ImprimeDinossauro(Dinossauro dino)
{
    printf("Nome: %s\n", dino.nome);
    printf("Especie: %s\n", dino.especie);

    if(dino.tipo)
        printf("Tipo: %s\n", dino.tipo);

    printf("Dieta: %s\n", dino.dieta);

    if(dino.habitat)
        printf("Lugar que habitava: %s\n", dino.habitat);

    if(dino.tamanho != -1)
        printf("Nome: %.1f m\n", dino.tamanho);

    if(dino.velocidade != -1 && dino.unidadeMedida != '$')
        printf("Nome: %d %cm/h\n", dino.velocidade, dino.unidadeMedida);

    printf("\n");
}

//Cria a tabela usando o endereço de entrada e saída
void CreateTable(char* enderecoE, char* enderecoS)
{
    FILE* entrada = fopen(enderecoE, "rb");

    if(entrada == NULL)
    {
        fclose(entrada);
        printf("Falha no processamento do arquivo.");
    }

    char* linha = calloc(160, sizeof(char));
    Dinossauro dino = CriaDinossauro();

    fgets(linha, 160, entrada);

    while(fgets(linha, 160, entrada))
    {
        strcpy(dino.nome, strtok(linha, ","));
        strcpy(dino.dieta, strtok(NULL, ","));
        strcpy(dino.habitat, strtok(NULL, ","));

        dino.populacao = atoi(strtok(NULL, ","));

        strcpy(dino.tipo, strtok(NULL, ","));

        dino.velocidade = atoi(strtok(NULL, ","));
        dino.unidadeMedida = strtok(NULL, ",")[0];
        dino.tamanho = atoi(strtok(NULL, ","));

        strcpy(dino.especie, strtok(NULL, ","));
        strcpy(dino.alimento, strtok(NULL, ","));

        ImprimeDinossauro(dino);

        LiberaDinossauro(dino);
        free(linha);

        dino = CriaDinossauro();
        linha = calloc(160, sizeof(char));
    }


    printf("%d", sizeof(dino.nome));
    fclose(entrada);
}

void EscreverCabecalho(FILE *arq)
{

}

void AbrirArquivo(FILE* arq, char* endereco)
{
    arq = fopen(endereco, "rb+");
    fseek(arq, 0, SEEK_SET);
    fwrite("0", sizeof(char), 1, arq);
}

void FecharArquivo(FILE* arq)
{
    fseek(arq, 0, SEEK_SET);
    fwrite("1", sizeof(char), 1, arq);
    fclose(arq);
}

void SalvarRegistro(Dinossauro dino, FILE* arq)
{
    fwrite("0", sizeof(char), 1, arq);
    fwrite(-1, sizeof(int), 1, arq);

    char* aux = calloc(160, sizeof(char));

}
