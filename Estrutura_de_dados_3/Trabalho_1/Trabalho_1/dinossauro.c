#include "funcoes_fornecidas.h"
#include "controlador.h"
#include "dinossauro.h"

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
