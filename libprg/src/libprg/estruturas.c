#include "libprg/estruturas.h"
#include <stdlib.h>
#include <stdbool.h>

/* =========================
        FUNÇÃO AUXILIAR
   ========================= */
static void aumentar_capacidade(int **dados, int *capacidade) {
    int nova_capacidade = (*capacidade == 0) ? 4 : (*capacidade * 2);

    int *novo = realloc(*dados, nova_capacidade * sizeof(int));
    if (!novo) return;

    *dados = novo;
    *capacidade = nova_capacidade;
}

/* =========================
            PILHA
   ========================= */

pilha_t* pilha_criar() {
    pilha_t *p = malloc(sizeof(pilha_t));
    if (!p) return NULL;

    p->dados = NULL;
    p->topo = -1;
    p->capacidade = 0;

    return p;
}

void pilha_empilhar(pilha_t *p, int valor) {
    if (!p) return;

    if (p->topo + 1 >= p->capacidade) {
        aumentar_capacidade(&p->dados, &p->capacidade);
    }

    p->dados[++p->topo] = valor;
}

int pilha_desempilhar(pilha_t *p) {
    if (!p || p->topo < 0) return -1;
    return p->dados[p->topo--];
}

int pilha_topo(pilha_t *p) {
    if (!p || p->topo < 0) return -1;
    return p->dados[p->topo];
}

bool pilha_vazia(pilha_t *p) {
    return (!p || p->topo < 0);
}

int pilha_tamanho(pilha_t *p) {
    if (!p) return 0;
    return p->topo + 1;
}

void pilha_destruir(pilha_t *p) {
    if (!p) return;

    free(p->dados);
    free(p);
}

/* =========================
            FILA
   ========================= */

fila_t* fila_criar() {
    fila_t *f = malloc(sizeof(fila_t));
    if (!f) return NULL;

    f->dados = NULL;
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = 0;

    return f;
}

static void fila_aumentar(fila_t *f) {
    int nova_capacidade = (f->capacidade == 0) ? 4 : (f->capacidade * 2);

    int *novo = malloc(nova_capacidade * sizeof(int));
    if (!novo) return;

    if (f->capacidade > 0) {
        for (int i = 0; i < f->tamanho; i++) {
            novo[i] = f->dados[(f->inicio + i) % f->capacidade];
        }
    }

    free(f->dados);
    f->dados = novo;
    f->capacidade = nova_capacidade;
    f->inicio = 0;
    f->fim = f->tamanho;
}

void fila_enfileirar(fila_t *f, int valor) {
    if (!f) return;

    if (f->tamanho >= f->capacidade) {
        fila_aumentar(f);
    }

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;
}

int fila_desenfileirar(fila_t *f) {
    if (!f || f->tamanho == 0) return -1;

    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;

    return valor;
}

int fila_inicio(fila_t *f) {
    if (!f || f->tamanho == 0) return -1;
    return f->dados[f->inicio];
}

bool fila_vazia(fila_t *f) {
    return (!f || f->tamanho == 0);
}

int fila_tamanho(fila_t *f) {
    if (!f) return 0;
    return f->tamanho;
}

void fila_destruir(fila_t *f) {
    if (!f) return;

    free(f->dados);
    free(f);
}

/* =========================
        LISTA LINEAR
   ========================= */

lista_t* lista_linear_criar() {
    lista_t *l = malloc(sizeof(lista_t));
    if (!l) return NULL;

    l->dados = NULL;
    l->tamanho = 0;
    l->capacidade = 0;

    return l;
}

void lista_linear_inserir(lista_t *l, int valor) {
    if (!l) return;

    if (l->tamanho >= l->capacidade) {
        aumentar_capacidade(&l->dados, &l->capacidade);
    }

    l->dados[l->tamanho++] = valor;
}

int lista_linear_remover(lista_t *l) {
    if (!l || l->tamanho == 0) return -1;
    return l->dados[--l->tamanho];
}

bool lista_linear_vazia(lista_t *l) {
    return !l || l->tamanho == 0;
}

int lista_linear_tamanho(lista_t *l) {
    if (!l) return 0;
    return l->tamanho;
}

void lista_linear_destruir(lista_t *l) {
    if (!l) return;

    free(l->dados);
    free(l);
}

/* =========================
        LISTA ENCADEADA
   ========================= */

no_t* lista_encadeada_criar() {
    return NULL;
}

void lista_encadeada_inserir(no_t **inicio, int valor) {
    if (!inicio) return;

    no_t *novo = malloc(sizeof(no_t));
    if (!novo) return;

    novo->dados = valor;
    novo->proximo = *inicio;

    *inicio = novo;
}

int lista_encadeada_remover(no_t **inicio) {
    if (!inicio || *inicio == NULL) return -1;

    no_t *temp = *inicio;
    int valor = temp->dados;

    *inicio = temp->proximo;
    free(temp);

    return valor;
}

bool lista_encadeada_vazia(no_t *inicio) {
    return inicio == NULL;
}

void lista_encadeada_destruir(no_t **inicio) {
    if (!inicio) return;

    while (*inicio != NULL) {
        lista_encadeada_remover(inicio);
    }
}