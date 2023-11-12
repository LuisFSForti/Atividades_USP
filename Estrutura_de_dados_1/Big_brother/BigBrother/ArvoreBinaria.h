#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

//  Arquivo ArvBinaria.h
//  TAD: ProjArvoreBinaria-V2

#include "LDED.h"

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

//Definição do tipo Arvore
struct NO{
    Tipo_Dado info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, Tipo_Dado valor);
int remove_ArvBin(ArvBin *raiz, Tipo_Dado valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, Tipo_Dado valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

// Funcoes Adicionais
void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_Dado valor, int *achou);
void Exibe_emOrdem_ArvBin(ArvBin *raiz);
// Insercao Recursiva
void ins_nodo_arvbin_rec(struct NO* atual, struct NO* ant, struct NO* novo, Tipo_Dado valor);
int insere_ArvBin_recursiva(ArvBin* raiz, Tipo_Dado valor);

#endif // ARVOREBINARIA_H_INCLUDED
