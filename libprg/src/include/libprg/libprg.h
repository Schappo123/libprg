#ifndef LABORATORIO_LIBPRG_H
#define LABORATORIO_LIBPRG_H
#include <stdbool.h>

// PILHA GABRIEL //

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} pilha_t;

pilha_t *pilha_criar (int capacidade);
int pilha_tamanho (pilha_t *p);
void pilha_empilhar (pilha_t *p, int valor);
int pilha_desempilhar (pilha_t *p);
void pilha_imprimir (pilha_t *p);
void pilha_destruir (pilha_t *p);

// FILA GABRIEL //

typedef struct {
    int *dados;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
}fila_t;

fila_t *fila_criar (int capacidade);
int fila_tamanho (fila_t *f);
void fila_enfileirar (fila_t *f, int elemento);
int fila_desinfileirar (fila_t *f);
bool fila_vazia (fila_t *f);
void fila_imprimir (fila_t *f);
void fila_destruir (fila_t *f);

// LISTA LINEAR GABRIEL //

typedef struct {
    int *dados;
    int capacidade;
    int tamanho;
} lista_linear_t;

lista_linear_t *lista_linear_criar (int capacidade);
int lista_linear_tamanho(lista_linear_t* lista);
void lista_linear_inserir(lista_linear_t* lista, int valor);
int lista_linear_remover (lista_linear_t* lista, int valor);
bool lista_linear_vazia (lista_linear_t* lista);
void lista_linear_imprimir (lista_linear_t* lista);
void lista_linear_destruir (lista_linear_t* lista);

#endif //LABORATORIO_LIBPRG_H
