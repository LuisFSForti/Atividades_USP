#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h" //inclui os Protótipos

ArvBin* cria_ArvBin(){
    ArvBin* raiz;

    raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO_ABO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO_ABO(no->esq);
    libera_NO_ABO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO_ABO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

void ins_nodo_arvbin_rec(struct NO* atual, struct NO* ant, struct NO* novo, Tipo_Dado valor)
{
    if (atual != NULL)
    {
            ant = atual;

            if(strcmp(valor.TAG, atual->info.TAG) == 0)
            {
                free(novo);
                return;//elemento já existe
            }

            if (strcmp(valor.TAG, atual->info.TAG) > 0)
                ins_nodo_arvbin_rec(atual->dir, ant, novo, valor);
            else
                ins_nodo_arvbin_rec(atual->esq, ant, novo, valor);
    }
    else
    {
        if(strcmp(valor.TAG, ant->info.TAG) > 0)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
}

int insere_ArvBin_recursiva(ArvBin* raiz, Tipo_Dado valor)
{
    struct NO* novo;

    if(raiz == NULL)
        return 0;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
    {
        *raiz = novo;
        return 1;
    }

    struct NO* atual = *raiz;
    struct NO* ant = NULL;

    ins_nodo_arvbin_rec(atual,ant,novo,valor);

    return 1;

}

int insere_ArvBin(ArvBin* raiz, Tipo_Dado valor)
{
    struct NO* novo;

    if(raiz == NULL)
        return 0;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(strcmp(valor.TAG, atual->info.TAG) == 0){
                free(novo);
                return 0;//elemento já existe
            }

            if(strcmp(valor.TAG, atual->info.TAG) > 0)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(strcmp(valor.TAG, ant->info.TAG) > 0)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, Tipo_Dado valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(strcmp(valor.TAG, atual->info.TAG) == 0){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(strcmp(valor.TAG, atual->info.TAG) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, Tipo_Dado valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    int buscas = 0;
    while(atual != NULL){
        buscas++;
        if(strcmp(valor.TAG, atual->info.TAG) == 0){
            return buscas;
        }
        if(strcmp(valor.TAG, atual->info.TAG) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return buscas;
}

void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%s %d\n",(*raiz)->info.TAG, (*raiz)->info.status);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%s %d\n",(*raiz)->info.TAG, (*raiz)->info.status);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%s %d\n",(*raiz)->info.TAG, (*raiz)->info.status);
    }
}

// Funcoes Adicionais de Arvore

void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_Dado valor, int *achou)
{
    if(raiz == NULL)
        return;
    if (*achou)
        return;
    if((*raiz) != NULL)
    {
        if (strcmp(valor.TAG, (*raiz)->info.TAG) == 0)
        {
            (*achou) = 1;
        }
        Procura_preOrdem_ArvBin(&((*raiz)->esq),valor,achou);
        Procura_preOrdem_ArvBin(&((*raiz)->dir),valor,achou);
    }
}

void Exibe_emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        printf("Atual: %s - %d - Vai para Esquerda \n",(*raiz)->info.TAG, (*raiz)->info.status);   // Info é Int
        Exibe_emOrdem_ArvBin(&((*raiz)->esq));
        printf("Dado : %s - %d \n",(*raiz)->info.TAG,(*raiz)->info.status);
        printf("Atual: %s - %d - Vai para Direita \n",(*raiz)->info.TAG, (*raiz)->info.status);    // Info é Int
        Exibe_emOrdem_ArvBin(&((*raiz)->dir));
        printf("Feito(%s - %d) \n", (*raiz)->info.TAG, (*raiz)->info.status);                       // Info é Int
    }
    else
        printf("NULL\n");

}

int EstaNaArvore(ArvBin *raiz, Tipo_Dado valor)
{
    if(raiz == NULL)
        return -1;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(strcmp(valor.TAG, atual->info.TAG) == 0){
            return 0;
        }
        if(strcmp(valor.TAG, atual->info.TAG) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return -1;
}
