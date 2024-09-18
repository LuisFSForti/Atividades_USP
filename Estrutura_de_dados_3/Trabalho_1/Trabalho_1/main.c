#include <stdio.h>
#include <stdlib.h>

#include "funcoes_fornecidas.h"
#include "controlador.h"
#include "dinossauro.h"

int main()
{
    int comando;
    char* aux1 = calloc(100, sizeof(char));
    char* aux2 = calloc(100, sizeof(char));

    scanf("%d ", &comando);

    switch(comando)
    {
    case 1:
        scanf("%s %s", aux1, aux2);
        CreateTable(aux1, aux2);
        break;
    case 2:
        scanf("%s", aux1);
        SelectTable(aux1);
        break;
    case 4:
        scanf("%s", aux1);
        int qtd = 0;
        scanf(" %d ", &qtd);
        RemoverRegistros(aux1, qtd);
        break;
    case 5:
        scanf("%s", aux1);
        qtd = 0;
        scanf(" %d ", &qtd);
        InsertInto(aux1, qtd);
        break;
    default:
        break;
    }

    free(aux1);
    free(aux2);
    return 0;
}
