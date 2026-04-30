#include <stdlib.h>
#include "libprg/libprg.h"

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