//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 1 de ED3

#include "funcoes_fornecidas.h"
#include "controlador.h"
#include "dinossauro.h"

//Cria um dinossauro com valores nulos
Dinossauro CriaDinossauro()
{
    Dinossauro dino;
    dino.removido = '0';
    dino.encadeamento = -1;
    dino.populacao = -1;
    dino.tamanho = -1;
    dino.unidadeMedida = '$';
    dino.velocidade = -1;
    dino.nome = calloc(160, sizeof(char)); //160 bytes pois é o tamanho do registro, nunca será maior
    dino.especie = calloc(160, sizeof(char)); //160 bytes pois é o tamanho do registro, nunca será maior
    dino.habitat = calloc(160, sizeof(char)); //160 bytes pois é o tamanho do registro, nunca será maior
    dino.tipo = calloc(160, sizeof(char)); //160 bytes pois é o tamanho do registro, nunca será maior
    dino.dieta = calloc(160, sizeof(char)); //160 bytes pois é o tamanho do registro, nunca será maior
    dino.alimento = calloc(160, sizeof(char)); //160 bytes pois é o tamanho do registro, nunca será maior

    return dino;
}

//Libera o espaço alocado para dino
void LiberaDinossauro(Dinossauro dino)
{
    if(dino.nome) //if != NULL
        free(dino.nome);

    if(dino.especie) //if != NULL
        free(dino.especie);

    if(dino.habitat) //if != NULL
        free(dino.habitat);

    if(dino.tipo) //if != NULL
        free(dino.tipo);

    if(dino.dieta) //if != NULL
        free(dino.dieta);

    if(dino.alimento) //if != NULL
        free(dino.alimento);
}

//Imprime dino na tela
void ImprimeDinossauro(Dinossauro dino)
{
    printf("Nome: %s\n", dino.nome);
    printf("Especie: %s\n", dino.especie);

    if(strcmp(dino.tipo, "") != 0) //if não é nulo
        printf("Tipo: %s\n", dino.tipo);

    printf("Dieta: %s\n", dino.dieta);

    if(strcmp(dino.habitat, "") != 0) //if não é nulo
        printf("Lugar que habitava: %s\n", dino.habitat);

    if(dino.tamanho != -1) //if não é nulo
        printf("Tamanho: %.1f m\n", dino.tamanho);

    if(dino.velocidade != -1 && dino.unidadeMedida != '$') //if não é nulo algum dos valores
        printf("Velocidade: %d %cm/h\n", dino.velocidade, dino.unidadeMedida);

    printf("\n");
}
