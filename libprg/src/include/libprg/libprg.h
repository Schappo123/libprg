#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdbool.h>

/* =========================
            PILHA
   ========================= */
typedef struct {
    int *dados;
    int topo;
    int capacidade;
} pilha_t;

pilha_t* pilha_criar();
void pilha_empilhar(pilha_t *p, int valor);
int pilha_desempilhar(pilha_t *p);
int pilha_topo(pilha_t *p);
bool pilha_vazia(pilha_t *p);
int pilha_tamanho(pilha_t *p);
void pilha_destruir(pilha_t *p);


/* =========================
            FILA
   ========================= */
typedef struct {
    int *dados;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
} fila_t;

fila_t* fila_criar();
void fila_enfileirar(fila_t *f, int valor);
int fila_desenfileirar(fila_t *f);
int fila_inicio(fila_t *f);
bool fila_vazia(fila_t *f);
int fila_tamanho(fila_t *f);
void fila_destruir(fila_t *f);


/* =========================
        LISTA LINEAR
   ========================= */
typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} lista_t;

lista_t* lista_linear_criar();
void lista_linear_inserir(lista_t *l, int valor);
int lista_linear_remover(lista_t *l);
int buscar (lista_t *lista, int elemento);
bool lista_linear_vazia(lista_t *l);
int lista_linear_tamanho(lista_t *l);
void lista_linear_destruir(lista_t *l);


/* =========================
        LISTA ENCADEADA
   ========================= */
typedef struct no {
    int dados;
    struct no *proximo;
} no_t;

no_t* lista_encadeada_criar();
void lista_encadeada_inserir(no_t **inicio, int valor);
int lista_encadeada_remover(no_t **inicio);
no_t* lista_encadeada_buscar (no_t *inicio, int elemento);
bool lista_encadeada_vazia(no_t *inicio);
void lista_encadeada_destruir(no_t **inicio);

#endif