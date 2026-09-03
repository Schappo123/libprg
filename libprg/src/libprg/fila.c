#include <stdbool.h>
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

// FILA GABRIEL //

void fila_criar (int capacidade) {
    if (capacidade <= 0) return;
    fila_t *fila = malloc(sizeof(fila_t));
    f->capacidade = capacidade;
    f->tamanho = 0;
    f->inicio = 0;
    f->fim = 0;
    f->dados = malloc(sizeof(int) * capacidade);
}

int fila_tamanho (fila_t *f) {
    return f->tamanho;
}

void fila_enfileirar (fila_t *f, int elemento) {
    if (f->tamanho == f->capacidade) return;

    f->dados[f->fim] = elemento;
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;
}

int fila_desinfileirar (fila_t *f) {
    if (f->tamanho == 0) return -1;

    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
    return valor;
}

bool fila_vazia (fila_t *f) {
    if (f->tamanho == 0) return true;
    return false;
}

void fila_imprimir (fila_t *f) {
    if (f->tamanho == 0) return;
    int posicao = f->inicio;
    for (int i = 0; i < f->tamanho; i++) {
        printf("%d ", f->dados[posicao]);
        posicao = (posicao + 1) % f->capacidade;
    }
}

void fila_destruir (fila_t *f) {
    free(f->dados);
    f->dados = NULL;
}