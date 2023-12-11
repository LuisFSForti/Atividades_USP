//14592348
//Luis Filipe Silva Forti

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Nao inclui o LDED.h pois ele esta incluso em ArvoreBinaria.h
#include "ArvoreAVL.h"

int main()
{
    //Ponteiros das árvores
    ArvBin *raizABO = cria_ArvBin();
    ArvAVL *raizAVL = cria_ArvAVL();

    //Ponteiro do arquivo
    FILE *arq = fopen("arq.txt", "r");

    //Leitores dos dados
    char *linha = malloc(15 * sizeof(*linha));
    int status;

    //Armazenador temporário dos dados
    Dados aux;

    while(1)
    {
        fgets(linha, 15, arq);
        linha[strcspn(linha, "\r\n")] = '\0';

        if(linha[0] == 'x' || feof(arq))
            break;

        strcpy(aux.TAG, linha);

        fgets(linha, 15, arq);
        linha[strcspn(linha, "\r\n")] = '\0';
        status = atoi(linha);

        aux.status = status;

        insere_ArvBin_recursiva(raizABO, aux);
        insere_ArvAVL(raizAVL, aux);
    }

    int comando;
    scanf("%d%*c", &comando);
    switch(comando)
    {
    case 0:
        printf("NA:%d NB:%d", totalNO_ArvBin(raizABO), totalNO_ArvAVL(raizAVL));
        break;
    case 1:
        fgets(linha, 15, stdin);
        linha[strcspn(linha, "\r\n")] = '\0';

        strcpy(aux.TAG, linha);

        printf("S:%d ", EstaNaArvore(raizABO, aux));
        printf("NA:%d ", consulta_ArvBin(raizABO, aux));
        printf("NB:%d\n", consulta_ArvAVL(raizAVL, aux));

        break;
    case 2:
        preOrdem_ArvBin(raizABO);
        break;
    case 3:
        preOrdem_ArvAVL(raizAVL);
        break;
    default:
        break;
    }

    return 0;
}
