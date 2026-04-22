#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdlib.h>

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
int pilha_vazia(pilha_t *p);
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
int fila_vazia(fila_t *f);
int fila_tamanho(fila_t *f);
void fila_destruir(fila_t *f);


/* =========================
            LISTA
   ========================= */
typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} lista_t;

lista_t* lista_criar();
void lista_inserir_fim(lista_t *l, int valor);
void lista_inserir_inicio(lista_t *l, int valor);
void lista_inserir_indice(lista_t *l, int indice, int valor);

int lista_remover_fim(lista_t *l);
int lista_remover_inicio(lista_t *l);
int lista_remover_indice(lista_t *l, int indice);

int lista_obter(lista_t *l, int indice);
void lista_definir(lista_t *l, int indice, int valor);

int lista_vazia(lista_t *l);
int lista_tamanho(lista_t *l);

void lista_destruir(lista_t *l);

#endif