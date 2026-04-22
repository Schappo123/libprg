#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdlib.h>

/* =========================
   PILHA DINÂMICA
   ========================= */
typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

Pilha* pilha_criar();
void pilha_empilhar(Pilha *p, int valor);
int pilha_desempilhar(Pilha *p);
int pilha_topo(Pilha *p);
int pilha_vazia(Pilha *p);
int pilha_tamanho(Pilha *p);
void pilha_destruir(Pilha *p);


/* =========================
   FILA DINÂMICA
   ========================= */
typedef struct {
    int *dados;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
} Fila;

Fila* fila_criar();
void fila_enfileirar(Fila *f, int valor);
int fila_desenfileirar(Fila *f);
int fila_inicio(Fila *f);
int fila_vazia(Fila *f);
int fila_tamanho(Fila *f);
void fila_destruir(Fila *f);


/* =========================
   LISTA DINÂMICA
   ========================= */
typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Lista;

Lista* lista_criar();
void lista_inserir_fim(Lista *l, int valor);
void lista_inserir_inicio(Lista *l, int valor);
void lista_inserir_indice(Lista *l, int indice, int valor);

int lista_remover_fim(Lista *l);
int lista_remover_inicio(Lista *l);
int lista_remover_indice(Lista *l, int indice);

int lista_obter(Lista *l, int indice);
void lista_definir(Lista *l, int indice, int valor);

int lista_vazia(Lista *l);
int lista_tamanho(Lista *l);

void lista_destruir(Lista *l);

#endif