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

Pilha* pilha_criar() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return NULL;

    p->dados = NULL;
    p->topo = -1;
    p->capacidade = 0;

    return p;
}

void pilha_empilhar(Pilha *p, int valor) {
    if (!p) return;

    if (p->topo + 1 >= p->capacidade) {
        aumentar_capacidade(&p->dados, &p->capacidade);
    }

    p->dados[++p->topo] = valor;
}

int pilha_desempilhar(Pilha *p) {
    if (!p || p->topo < 0) return -1;
    return p->dados[p->topo--];
}

int pilha_topo(Pilha *p) {
    if (!p || p->topo < 0) return -1;
    return p->dados[p->topo];
}

int pilha_vazia(Pilha *p) {
    return (!p || p->topo < 0);
}

int pilha_tamanho(Pilha *p) {
    if (!p) return 0;
    return p->topo + 1;
}

void pilha_destruir(Pilha *p) {
    if (!p) return;

    free(p->dados);
    free(p);
}

/* =========================
   FILA (circular)
   ========================= */

Fila* fila_criar() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (!f) return NULL;

    f->dados = NULL;
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = 0;

    return f;
}

static void fila_aumentar(Fila *f) {
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

void fila_enfileirar(Fila *f, int valor) {
    if (!f) return;

    if (f->tamanho >= f->capacidade) {
        fila_aumentar(f);
    }

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;
}

int fila_desenfileirar(Fila *f) {
    if (!f || f->tamanho == 0) return -1;

    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;

    return valor;
}

int fila_inicio(Fila *f) {
    if (!f || f->tamanho == 0) return -1;
    return f->dados[f->inicio];
}

int fila_vazia(Fila *f) {
    return (!f || f->tamanho == 0);
}

int fila_tamanho(Fila *f) {
    if (!f) return 0;
    return f->tamanho;
}

void fila_destruir(Fila *f) {
    if (!f) return;

    free(f->dados);
    free(f);
}

/* =========================
   LISTA
   ========================= */

Lista* lista_criar() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (!l) return NULL;

    l->dados = NULL;
    l->tamanho = 0;
    l->capacidade = 0;

    return l;
}

static void lista_aumentar(Lista *l) {
    aumentar_capacidade(&l->dados, &l->capacidade);
}

void lista_inserir_fim(Lista *l, int valor) {
    if (!l) return;

    if (l->tamanho >= l->capacidade) {
        lista_aumentar(l);
    }

    l->dados[l->tamanho++] = valor;
}

void lista_inserir_inicio(Lista *l, int valor) {
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

void lista_inserir_indice(Lista *l, int indice, int valor) {
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

int lista_remover_fim(Lista *l) {
    if (!l || l->tamanho == 0) return -1;
    return l->dados[--l->tamanho];
}

int lista_remover_inicio(Lista *l) {
    if (!l || l->tamanho == 0) return -1;

    int valor = l->dados[0];

    for (int i = 0; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->tamanho--;
    return valor;
}

int lista_remover_indice(Lista *l, int indice) {
    if (!l || l->tamanho == 0) return -1;
    if (indice < 0 || indice >= l->tamanho) return -1;

    int valor = l->dados[indice];

    for (int i = indice; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->tamanho--;
    return valor;
}

int lista_obter(Lista *l, int indice) {
    if (!l) return -1;
    if (indice < 0 || indice >= l->tamanho) return -1;
    return l->dados[indice];
}

void lista_definir(Lista *l, int indice, int valor) {
    if (!l) return;
    if (indice < 0 || indice >= l->tamanho) return;
    l->dados[indice] = valor;
}

int lista_vazia(Lista *l) {
    return (!l || l->tamanho == 0);
}

int lista_tamanho(Lista *l) {
    if (!l) return 0;
    return l->tamanho;
}

void lista_destruir(Lista *l) {
    if (!l) return;

    free(l->dados);
    free(l);
}