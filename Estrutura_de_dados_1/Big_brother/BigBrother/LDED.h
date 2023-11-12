#ifndef LDED_H_INCLUDED
#define LDED_H_INCLUDED

//14592348
//Luis Filipe Silva Forti

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef struct dados{
    char TAG[9];
    int status;
} Dados;

typedef Dados Tipo_Dado;

//Definição do tipo lista
typedef struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
} Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt);
int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int insere_lista_inicio(Lista* li, Tipo_Dado dt);
int insere_lista_ordenada(Lista* li, Tipo_Dado dt);
int remove_lista(Lista* li, Tipo_Dado dt);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);


#endif // LDED_H_INCLUDED
