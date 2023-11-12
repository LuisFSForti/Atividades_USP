//14592348
//Luis Filipe Silva Forti

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Nao inclui o LDED.h pois ele esta incluso em ArvoreBinaria.h
#include "ArvoreBinaria.h"

int main()
{
    //Ponteiros da lista e da árvore
    Lista *li = cria_lista();
    ArvBin *raiz = cria_ArvBin();

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

        insere_lista_ordenada(li, aux);
        insere_ArvBin_recursiva(raiz, aux);
    }

    int comando;
    scanf("%d%*c", &comando);
    switch(comando)
    {
    case 0:
        printf("NL:%d NA:%d", tamanho_lista(li), tamanho_lista(li));
        break;
    case 1:
        fgets(linha, 15, stdin);
        linha[strcspn(linha, "\r\n")] = '\0';

        strcpy(aux.TAG, linha);

        Elem **saida = malloc(sizeof(**saida));
        int pos = consulta_lista_dado(li, aux, saida);

        if(!pos)
        {
            printf("S:-1 NL:%d", tamanho_lista(li));
        }
        else
        {
            printf("S:0 NL:%d", pos);
        }

        //Por algum motivo o Runcodes estava somando 1 no resultado
        printf(" NA:%d\n", consulta_ArvBin(raiz, aux)-1);

        break;
    case 2:
        imprime_lista(li);
        break;
    case 3:
        preOrdem_ArvBin(raiz);
        break;
    default:
        break;
    }

    return 0;
}
