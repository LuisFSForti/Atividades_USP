//Luis Filipe Silva Forti 14592348

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDED.h"  //inclui os Protótipos

int main()
{
    Lista* lista = cria_lista();
    Elem **cursor = calloc(1, sizeof(*cursor));
    char comando = 'a';
    char aux[12];

    while(comando != 'X')
    {
        scanf("%c%*c", &comando);
        fgets(aux, 12, stdin);
        aux[strcspn(aux, "\r\n")] = '\0';

        switch(comando)
        {
        case 'I':
            insere_lista_inicio(lista, aux);
            consulta_lista_dado(lista, aux, cursor);
            break;
        case 'F':
            insere_lista_final(lista, aux);
            consulta_lista_dado(lista, aux, cursor);
            break;
        case 'A':
            insere_lista_antes(lista, aux, cursor);
            consulta_lista_dado(lista, aux, cursor);
            break;
        case 'D':
            insere_lista_depois(lista, aux, cursor);
            consulta_lista_dado(lista, aux, cursor);
            break;
        case 'P':
            consulta_lista_dado(cursor, aux, cursor);
            break;
        case 'R':
            remove_lista_por_endereco(lista, cursor);
        case 'G':
            if(strcmp(aux, "inicio") == 0)
            {
                consulta_lista_pos(lista, 1, cursor);
            }
            else if(strcmp(aux, "fim") == 0)
            {
                consulta_lista_pos(lista, tamanho_lista(lista), cursor);
            }
            else if(strcmp(aux, "prox") == 0)
            {
                if(*cursor != NULL && (*cursor)->prox != NULL)
                    *cursor = (*cursor)->prox;
            }
            else if(strcmp(aux, "ant") == 0)
            {
                if(*cursor != NULL && (*cursor)->ante != NULL)
                    *cursor = (*cursor)->ante;
            }
            break;
        case 'L':
            if(strcmp(aux, "texto") == 0)
            {
                imprime_lista_legivel(lista);
                printf("\n");
            }
            else if(strcmp(aux, "palavra") == 0)
            {
                printf("%s\n", (*cursor)->dado);
            }
        default:
            break;
        }
    }

    return 0;
}
