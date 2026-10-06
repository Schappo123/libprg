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

void intercalar(ordenacao_t *v, int inicio, int meio, int fim) {
    int temp[100];
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (v->dados[i] < v->dados[j]) {
            temp[k++] = v->dados[i++];
        } else {
            temp[k++] = v->dados[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = v->dados[i++];
    }
    while (j <= fim) {
        temp[k++] = v->dados[j++];
    }
    for (int i = inicio; i <= fim; i++) {
        v->dados[i] = temp[i];
    }
}

void mergeSort (ordenacao_t *v, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        intercalar(v, inicio, meio, fim);
    }
}

int particionar (ordenacao_t *v, int inicio, int fim) {
    int pivo = v->dados[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim; j++) {
        if (v->dados[j] <= pivo) {
            i++;
            trocar(&v->dados[i], &v->dados[j]);
        }
    }
    trocar(&v->dados[i+1], &v->dados[fim]);
    return i + 1;
}

void quickSort (ordenacao_t *v, int inicio, int fim) {
    if (inicio < fim) {
        int p_indice = particionar(v, inicio, fim);
        quickSort(v, inicio, p_indice - 1);
        quickSort(v, p_indice + 1, fim);
    }
}
