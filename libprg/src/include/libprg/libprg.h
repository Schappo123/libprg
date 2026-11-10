#ifndef LABORATORIO_LIBPRG_H
#define LABORATORIO_LIBPRG_H
#include <stdbool.h>

// PILHA//

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

// FILA//

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

// LISTA LINEAR//

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

//LISTA ENCADEADA//

typedef struct no_t{
    int dados;
    struct no_t *proximo;
} no_t;

typedef struct {
    no_t *inicio;
    int tamanho;
} lista_encadeada_t;

no_t *lista_encadeada_criar_no (int valor);
void lista_encadeada_inserir (lista_encadeada_t *lista, int valor);
void lista_encadeada_remover (lista_encadeada_t *lista, int valor);
int lista_encadeada_tamanho (lista_encadeada_t *lista);
void lista_encadeada_imprimir (lista_encadeada_t *lista);
void lista_encadeada_destruir (lista_encadeada_t *lista);

//ALGORITMO DE ORDENAÇÃO//

typedef struct {
    int dados[100];
    int tamanho;
} ordenacao_t;

void trocar(int *a, int *b);
void bubbleSort(ordenacao_t *v);
void insertionSort(ordenacao_t *v);
void selectionSort(ordenacao_t *v);
void intercalar(ordenacao_t *v, int inicio, int meio, int fim);
void mergeSort (ordenacao_t *v, int inicio, int fim);
int particionar (ordenacao_t *v, int inicio, int fim);
void quickSort (ordenacao_t *v, int inicio, int fim);

// LISTA ENCADEADA DUPLA //

typedef struct no_lista {
    int valor;
    struct no_lista *anterior;
    struct no_lista *proximo;
} no_lista_t;

typedef struct {
    no_lista_t *inicio;
    no_lista_t *fim;
    int tamanho;
} lista_dupla_t;

void lista_inicializar(lista_dupla_t *lista);
int lista_inserir_inicio(lista_dupla_t *lista, int valor);
int lista_inserir_fim(lista_dupla_t *lista, int valor);
int lista_buscar(lista_dupla_t *lista, int valor);
int lista_remover(lista_dupla_t *lista, int valor);
void lista_percorrer(lista_dupla_t *lista);
void lista_libera(lista_dupla_t *lista);

// ARBORE BINARIA DE PESQUISA //

typedef struct no_abp {
    int valor;
    struct no_abp *esquerda;
    struct no_abp *direita;
} no_abp_t;

typedef no_abp_t* abp_t;

void abp_inicializar(abp_t *raiz);
int abp_inserir(abp_t *raiz, int valor);
int abp_buscar(abp_t raiz, int valor);
int abp_remover(abp_t *raiz, int valor);
void abp_libera(abp_t *raiz);

// ARVORE AVL //

typedef struct no_avl {
    int valor;
    int altura;
    struct no_avl *esquerda;
    struct no_avl *direita;
} no_avl_t;

typedef no_avl_t* avl_t;

void avl_inicializar(avl_t *raiz);
int avl_inserir(avl_t *raiz, int valor);
int avl_buscar(avl_t raiz, int valor);
int avl_remover(avl_t *raiz, int valor);
void avl_libera(avl_t *raiz);

#endif //LABORATORIO_LIBPRG_H
