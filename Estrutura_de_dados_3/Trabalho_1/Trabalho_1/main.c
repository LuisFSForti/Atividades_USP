//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 1 de ED3

#include <stdio.h>
#include <stdlib.h>

#include "funcoes_fornecidas.h"
#include "controlador.h"
#include "dinossauro.h"

int main()
{
    //Variáveis necessárias
    int comando;
    char* aux1 = calloc(100, sizeof(char));
    char* aux2 = calloc(100, sizeof(char));

    //Define o comando
    scanf("%d ", &comando);

    switch(comando)
    {
    //Se for CreateTable
    case 1:
        //Pega os endereços dos arquivos de entrada e saída
        scanf("%s %s", aux1, aux2);
        //Cria a tabela
        CreateTable(aux1, aux2);
        break;
    //Se for SelectTable
    case 2:
        //Pega o endereço do arquivo de entrada
        scanf("%s", aux1);
        //Imprime os dados da tabela
        SelectTable(aux1);
        break;
    //Se for a função de Remover
    case 4:
        //Pega o endereço do arquivo à ser modificado
        scanf("%s", aux1);
        //Pega a quantidade de pedidos
        int qtd = 0;
        scanf(" %d ", &qtd);
        //Remove os registros que serão pedidos
        RemoverRegistros(aux1, qtd);
        break;
    //Se for InsertTo
    case 5:
        //Pega o endereço do arquivo à ser modificado
        scanf("%s", aux1);
        //Pega a quantidade de pedidos
        qtd = 0;
        scanf(" %d ", &qtd);
        //Insere os registros que serão pedidos
        InsertInto(aux1, qtd);
        break;
    default:
        break;
    }

    //Libera os ponteiro usados
    free(aux1);
    free(aux2);
    return 0;
}
