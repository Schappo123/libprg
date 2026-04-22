#include "libprg/libprg.h"

/* =========================
   PILHA
   ========================= */

Pilha* pilha_criar() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) return NULL;

    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void pilha_empilhar(Pilha *p, void *dado) {
    if (!p) return;

    NoPilha *no = (NoPilha*) malloc(sizeof(NoPilha));
    if (!no) return;

    no->dado = dado;
    no->prox = p->topo;
    p->topo = no;
    p->tamanho++;
}

void* pilha_desempilhar(Pilha *p) {
    if (!p || p->topo == NULL) return NULL;

    NoPilha *temp = p->topo;
    void *dado = temp->dado;

    p->topo = temp->prox;
    free(temp);

    p->tamanho--;
    return dado;
}

void* pilha_topo(Pilha *p) {
    if (!p || p->topo == NULL) return NULL;
    return p->topo->dado;
}

int pilha_vazia(Pilha *p) {
    return (!p || p->tamanho == 0);
}

int pilha_tamanho(Pilha *p) {
    if (!p) return 0;
    return p->tamanho;
}

void pilha_destruir(Pilha *p) {
    if (!p) return;

    while (p->topo != NULL) {
        pilha_desempilhar(p);
    }

    free(p);
}


/* =========================
   FILA
   ========================= */

Fila* fila_criar() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (!f) return NULL;

    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

void fila_enfileirar(Fila *f, void *dado) {
    if (!f) return;

    NoFila *no = (NoFila*) malloc(sizeof(NoFila));
    if (!no) return;

    no->dado = dado;
    no->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = no;
        f->fim = no;
    } else {
        f->fim->prox = no;
        f->fim = no;
    }

    f->tamanho++;
}

void* fila_desenfileirar(Fila *f) {
    if (!f || f->inicio == NULL) return NULL;

    NoFila *temp = f->inicio;
    void *dado = temp->dado;

    f->inicio = temp->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
    f->tamanho--;

    return dado;
}

void* fila_inicio(Fila *f) {
    if (!f || f->inicio == NULL) return NULL;
    return f->inicio->dado;
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

    while (f->inicio != NULL) {
        fila_desenfileirar(f);
    }

    free(f);
}


/* =========================
   LISTA ENCADEADA
   ========================= */

Lista* lista_criar() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (!l) return NULL;

    l->cabeca = NULL;
    l->tamanho = 0;
    return l;
}

void lista_inserir_inicio(Lista *l, void *dado) {
    if (!l) return;

    NoLista *no = (NoLista*) malloc(sizeof(NoLista));
    if (!no) return;

    no->dado = dado;
    no->prox = l->cabeca;

    l->cabeca = no;
    l->tamanho++;
}

void lista_inserir_fim(Lista *l, void *dado) {
    if (!l) return;

    NoLista *no = (NoLista*) malloc(sizeof(NoLista));
    if (!no) return;

    no->dado = dado;
    no->prox = NULL;

    if (l->cabeca == NULL) {
        l->cabeca = no;
    } else {
        NoLista *atual = l->cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = no;
    }

    l->tamanho++;
}

void* lista_remover_inicio(Lista *l) {
    if (!l || l->cabeca == NULL) return NULL;

    NoLista *temp = l->cabeca;
    void *dado = temp->dado;

    l->cabeca = temp->prox;
    free(temp);

    l->tamanho--;
    return dado;
}

void* lista_remover_fim(Lista *l) {
    if (!l || l->cabeca == NULL) return NULL;

    NoLista *atual = l->cabeca;
    NoLista *anterior = NULL;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    void *dado = atual->dado;

    if (anterior == NULL) {
        l->cabeca = NULL;
    } else {
        anterior->prox = NULL;
    }

    free(atual);
    l->tamanho--;

    return dado;
}

void* lista_obter(Lista *l, int indice) {
    if (!l || indice < 0 || indice >= l->tamanho) return NULL;

    NoLista *atual = l->cabeca;
    int i = 0;

    while (atual != NULL) {
        if (i == indice) return atual->dado;
        atual = atual->prox;
        i++;
    }

    return NULL;
}

int lista_tamanho(Lista *l) {
    if (!l) return 0;
    return l->tamanho;
}

int lista_vazia(Lista *l) {
    return (!l || l->tamanho == 0);
}

void lista_destruir(Lista *l) {
    if (!l) return;

    while (l->cabeca != NULL) {
        lista_remover_inicio(l);
    }

    free(l);
}