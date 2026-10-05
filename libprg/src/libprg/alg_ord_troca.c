#include <stdlib.h>
#include "libprg/libprg.h"

void trocar(int *a, int *b) {
    int temporario = *a;
    *a = *b;
    *b = temporario;
}

void bubbleSort(ordenacao_t *v) {
    int i, j;
    for (i = 0; i < v->tamanho - 1; i++) {
        for (j = 0; j < v->tamanho - i - 1; j++) {
            if (v->dados[j] > v->dados[j + 1]) {
                trocar(&v->dados[j], &v->dados[j + 1]);
            }
        }
    }
}

void insertionSort(ordenacao_t *v) {
    int i, j, chave;
    for (i = 1; i < v->tamanho; i++) {
        chave = v->dados[i];
        j = i - 1;
        while (j >= 0 && v->dados[j] > chave) {
            v->dados[j + 1] = v->dados[j];
            j = j - 1;
        }
        v->dados[j + 1] = chave;
    }
}

void selectionSort(ordenacao_t *v) {
    int i, j, indiceMinimo;
    for (i = 0; i < v->tamanho - 1; i++) {
        indiceMinimo = i;
        for (j = i + 1; j < v->tamanho; j++) {
            if (v->dados[j] < v->dados[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        if (indiceMinimo != i) {
            trocar(&v->dados[i], &v->dados[indiceMinimo]);
        }
    }
}

