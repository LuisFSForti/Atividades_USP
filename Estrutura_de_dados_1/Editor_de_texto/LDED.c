#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDED.h"

Lista* cria_lista()
{
    Lista* li;

    li = (Lista*) malloc(sizeof(*li));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li)
{
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, Tipo_Dado dt)
{
    Elem *no;

    if (li == NULL)
        return ERRO;

    no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return ERRO;

    strcpy(no->dado, dt);
    no->prox = NULL;
    no->ante = NULL;
    if ((*li) == NULL) { //lista vazia: insere início
        *li = no;
    } else {
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
        no->ante = aux;
    }
    return OK;
}

int insere_lista_inicio(Lista* li, Tipo_Dado dt)
{
    Elem* no;

    if (li == NULL)
        return ERRO;

    no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return ERRO;

    strcpy(no->dado, dt);
    no->prox = (*li);
    no->ante = NULL;

    if(*li != NULL)
        (*li)->ante = no;

    *li = no;

    return OK;
}

int insere_lista_ordenada(Lista* li, Tipo_Dado dt)
{
    if (li == NULL)
        return ERRO;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return ERRO;

    strcpy(no->dado, dt);
    if ((*li) == NULL) { //lista vazia: insere início
        no->prox = NULL;
        no->ante = NULL;
        *li = no;
        return OK;
    }
    else {
        Elem *atual = *li;
        while (atual != NULL && strcmp(atual->dado, dt) <= 0) {
            atual = atual->prox;
        }
        if (atual == *li) { //insere início
            no->prox = (*li);
            no->ante = (*li)->ante;
            (*li)->ante = no;
            *li = no;
        }
        else
        {
            no->prox = atual;
            no->ante = atual->ante;
            atual->ante = no;
            no->ante->prox = no;
        }
        return OK;
    }
}


int remove_lista(Lista* li, Tipo_Dado dt)
{
    if(li == NULL)
        return ERRO;
    if((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;
    while(no != NULL && strcmp(no->dado, dt) != 0){
        no = no->prox;
    }
    if(no == NULL) //não encontrado
        return ERRO;

    if(no == *li) //remover o primeiro?
    {
        *li = no->prox;
        if(*li != NULL)
            (*li)->ante = NULL;
    }
    else
    {
        if(no->ante != NULL)
            no->ante->prox = no->prox;
        if(no->prox != NULL) //Ultimo
            no->prox->ante = no->ante;
    }
    free(no);
    return OK;
}

int remove_lista_por_endereco(Lista* li, Elem **noASerRemovido)
{
    if(li == NULL)
        return ERRO;
    if((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;
    while(no != NULL && no != *noASerRemovido){
        no = no->prox;
    }
    if(no == NULL) //não encontrado
        return ERRO;

    if(no == *li) //remover o primeiro?
    {
        *li = no->prox;
        if(*li != NULL)
            (*li)->ante = NULL;
        *noASerRemovido = *li;
    }
    else
    {
        if(no->ante != NULL)
        {
            *noASerRemovido = no->ante;
            no->ante->prox = no->prox;
        }
        if(no->prox != NULL) //Ultimo
            no->prox->ante = no->ante;
    }
    free(no);
    return OK;
}

int remove_lista_inicio(Lista* li)
{
    if(li == NULL)
        return ERRO;
    if((*li) == NULL) //lista vazia
        return ERRO;

    Elem *no = *li;
    *li = no->prox;
    (*li)->ante = no->ante;
    free(no);
    return OK;
}

int remove_lista_final(Lista* li)
{
    if(li == NULL)
        return ERRO;
    if((*li) == NULL) //lista vazia
        return ERRO;

    Elem *no = *li;
    while(no->prox != NULL){
        no = no->prox;
    }

    if(no == (*li)) //remover o primeiro?
        *li = no->prox;
    else
        no->ante->prox = no->prox;
    free(no);
    return OK;
}

int tamanho_lista(Lista* li)
{
    if(li == NULL)
        return 0;

    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li)
{
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int lista_cheia(Lista* li)
{
    return 0;
}

void imprime_lista(Lista* li)
{
    if(li == NULL)
        return;

    Elem* no = *li;
    while(no != NULL){
        printf("Dado: %p - %s # %p - %p\n",no->ante,no->dado,no,no->prox);
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}

void imprime_lista_legivel(Lista* li)
{
    if(li == NULL)
        return;

    Elem* no = *li;
    while(no != NULL){
        printf("%s ", no->dado);
        no = no->prox;
    }
}


int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el)
{
    if(li == NULL)
        return ERRO;

    Elem *no = *li;

    while(no != NULL && strcmp(no->dado, dt)){
        no = no->prox;
    }
    if(no == NULL)
        return ERRO;
    else{
        *el = no;
        return OK;
    }
}

int consulta_lista_pos(Lista* li, int pos, Elem **el) //Nao procura como array (pos 1 = [0])
{
    if(li == NULL || pos <= 0)
        return ERRO;

    Elem *no = *li;

    for(int i = 1; no != NULL && i < pos; i++){
        no = no->prox;
    }
    if(no == NULL)
        return ERRO;
    else{
        *el = no;
        return OK;
    }
}

int insere_lista_antes(Lista* li, Tipo_Dado dt, Elem **el)
{
    if (li == NULL)
        return ERRO;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return ERRO;

    strcpy(no->dado, dt);
    if ((*el == NULL) && (*li == NULL))  { //lista vazia: insere início
        no->prox = NULL;
        no->ante = NULL;
        *li = no;
        *el = no;
        return OK;
    }
    else
    {
        Elem *atual = *li;
        while (atual != NULL && atual != *el) {  // Acha o nodo e seu anterior
            atual = atual->prox;
        }

        if (atual != *el) // Ops: nao achou o nodo de referencia para insercao!
            return ERRO;

        if (atual == *li) { //insere antes (no inicio da lista)
            no->prox = (*li);
            no->ante = (*li)->ante;
            (*li)->ante = no;
            *li = no;
            *el = no;
        }
        else
        {
            no->prox = atual;
            no->ante = atual->ante;
            atual->ante = no;
            no->ante->prox = no;
            *el = no;
        }
        return OK;
    }
}

int insere_lista_depois(Lista* li, Tipo_Dado dt, Elem **el)
{
    if (li == NULL)
        return ERRO;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return ERRO;

    strcpy(no->dado, dt);
    if ((*el == NULL) && (*li == NULL))  // Lista vazia
    {
        no->prox = NULL;
        no->ante = NULL;
    }
    else
       if ((*el == NULL) || (*li==NULL))  // Inconsistencia nos parametros (ponteiros) da rotina
           return ERRO;

    if ((*li) == NULL) { // Lista vazia: insere início
        *li = no;
        *el = no;
    }
    else
    {
        no->prox  = (*el)->prox;
        no->ante = *el;

        if(no->prox != NULL)
            no->prox->ante = no;

        (*el)->prox = no;
        *el = no;
    }
    return OK;
}
