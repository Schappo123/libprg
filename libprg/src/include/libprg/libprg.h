#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <stdlib.h>


/* =========================
   PILHA
   ========================= */

typedef struct NoPilha {
    void *dado;
    struct NoPilha *prox;
} NoPilha;

typedef struct Pilha {
    NoPilha *topo;
    int tamanho;
} Pilha;

Pilha* pilha_criar();
void pilha_empilhar(Pilha *p, void *dado);
void* pilha_desempilhar(Pilha *p);
void* pilha_topo(Pilha *p);
int pilha_vazia(Pilha *p);
int pilha_tamanho(Pilha *p);
void pilha_destruir(Pilha *p);


/* =========================
   FILA
   ========================= */

typedef struct NoFila {
    void *dado;
    struct NoFila *prox;
} NoFila;

typedef struct Fila {
    NoFila *inicio;
    NoFila *fim;
    int tamanho;
} Fila;

Fila* fila_criar();
void fila_enfileirar(Fila *f, void *dado);
void* fila_desenfileirar(Fila *f);
void* fila_inicio(Fila *f);
int fila_vazia(Fila *f);
int fila_tamanho(Fila *f);
void fila_destruir(Fila *f);


/* =========================
   LISTA ENCADEADA
   ========================= */

typedef struct NoLista {
    void *dado;
    struct NoLista *prox;
} NoLista;

typedef struct Lista {
    NoLista *cabeca;
    int tamanho;
} Lista;

Lista* lista_criar();
void lista_inserir_inicio(Lista *l, void *dado);
void lista_inserir_fim(Lista *l, void *dado);
void* lista_remover_inicio(Lista *l);
void* lista_remover_fim(Lista *l);
void* lista_obter(Lista *l, int indice);
int lista_tamanho(Lista *l);
int lista_vazia(Lista *l);
void lista_destruir(Lista *l);

#endif
