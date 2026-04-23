#include "libprg/libprg.h"

/* =========================
   FUNÇÃO AUXILIAR
   ========================= */
static void aumentar_capacidade(int **dados, int *capacidade) {
    int nova_capacidade = (*capacidade == 0) ? 4 : (*capacidade * 2);

    int *novo = (int*) realloc(*dados, nova_capacidade * sizeof(int));
    if (!novo) return; // falhou realloc, ignora

    *dados = novo;
    *capacidade = nova_capacidade;
}

/* =========================
            PILHA
   ========================= */

pilha_t* pilha_criar() {
    pilha_t *p = (pilha_t*) malloc(sizeof(pilha_t));
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

int pilha_vazia(pilha_t *p) {
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
    fila_t *f = (fila_t*) malloc(sizeof(fila_t));
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

    int *novo = (int*) malloc(nova_capacidade * sizeof(int));
    if (!novo) return;

    for (int i = 0; i < f->tamanho; i++) {
        novo[i] = f->dados[(f->inicio + i) % f->capacidade];
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

int fila_vazia(fila_t *f) {
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
            LISTA
   ========================= */

lista_t* lista_criar() {
    lista_t *l = (lista_t*) malloc(sizeof(lista_t));
    if (!l) return NULL;

    l->dados = NULL;
    l->tamanho = 0;
    l->capacidade = 0;

    return l;
}

static void lista_aumentar(lista_t *l) {
    aumentar_capacidade(&l->dados, &l->capacidade);
}

void lista_inserir_fim(lista_t *l, int valor) {
    if (!l) return;

    if (l->tamanho >= l->capacidade) {
        lista_aumentar(l);
    }

    l->dados[l->tamanho++] = valor;
}

void lista_inserir_inicio(lista_t *l, int valor) {
    if (!l) return;

    if (l->tamanho >= l->capacidade) {
        lista_aumentar(l);
    }

    for (int i = l->tamanho; i > 0; i--) {
        l->dados[i] = l->dados[i - 1];
    }

    l->dados[0] = valor;
    l->tamanho++;
}

void lista_inserir_indice(lista_t *l, int indice, int valor) {
    if (!l) return;
    if (indice < 0 || indice > l->tamanho) return;

    if (l->tamanho >= l->capacidade) {
        lista_aumentar(l);
    }

    for (int i = l->tamanho; i > indice; i--) {
        l->dados[i] = l->dados[i - 1];
    }

    l->dados[indice] = valor;
    l->tamanho++;
}

int lista_remover_fim(lista_t *l) {
    if (!l || l->tamanho == 0) return -1;
    return l->dados[--l->tamanho];
}

int lista_remover_inicio(lista_t *l) {
    if (!l || l->tamanho == 0) return -1;

    int valor = l->dados[0];

    for (int i = 0; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->tamanho--;
    return valor;
}

int lista_remover_indice(lista_t *l, int indice) {
    if (!l || l->tamanho == 0) return -1;
    if (indice < 0 || indice >= l->tamanho) return -1;

    int valor = l->dados[indice];

    for (int i = indice; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->tamanho--;
    return valor;
}

int lista_obter(lista_t *l, int indice) {
    if (!l) return -1;
    if (indice < 0 || indice >= l->tamanho) return -1;
    return l->dados[indice];
}

void lista_definir(lista_t *l, int indice, int valor) {
    if (!l) return;
    if (indice < 0 || indice >= l->tamanho) return;
    l->dados[indice] = valor;
}

int lista_vazia(lista_t *l) {
    return (!l || l->tamanho == 0);
}

int lista_tamanho(lista_t *l) {
    if (!l) return 0;
    return l->tamanho;
}

void lista_destruir(lista_t *l) {
    if (!l) return;

    free(l->dados);
    free(l);
}