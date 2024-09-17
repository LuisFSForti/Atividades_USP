#include <stdio.h>
#include <stdlib.h>

#include "funcoes_fornecidas.h"
#include "controlador.h"
#include "dinossauro.h"

int main()
{
    char* aux1 = calloc(100, sizeof(char));
    char* aux2 = calloc(100, sizeof(char));

    scanf("%s %s", aux1, aux2);
    CreateTable(aux1, aux2);

    return 0;
}
