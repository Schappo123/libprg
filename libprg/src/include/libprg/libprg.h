#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H


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
        LISTA LINEAR
   ========================= */
typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} lista_t;

lista_t* lista_linear_criar();
void lista_linear_inserir_fim(lista_t *l, int valor);
void lista_linear_inserir_inicio(lista_t *l, int valor);
void lista_linear_inserir_indice(lista_t *l, int indice, int valor);

int lista_linear_remover_fim(lista_t *l);
int lista_linear_remover_inicio(lista_t *l);
int lista_linear_remover_indice(lista_t *l, int indice);

int lista_linear_obter(lista_t *l, int indice);
void lista_linear_definir(lista_t *l, int indice, int valor);

int lista_linear_vazia(lista_t *l);
int lista_linear_tamanho(lista_t *l);

void lista_linear_destruir(lista_t *l);

/* =========================
        LISTA ENCADEADA
   ========================= */

typedef struct no{
    int dados;
    struct no *proximo;
} no_t;

no_t* lista_encadeada_criar (int dado);
void lista_encadeada_inserir (no_t **inicio, int valor);

#endif