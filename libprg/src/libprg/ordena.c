#include "libprg/libprg.h"


int *bubble_sort (int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    return vetor;
}


//insertion_sort
//selection_sort

int *merge (int *vetor, int esquerda, int meio, int direita) {
    int aux [direita - esquerda + 1];
    int i = esquerda;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= direita) {
        if (vetor[i] <= vetor[j]) {
            aux[k] = vetor[i];
            i++;
        } else {
            aux[k] = vetor[j];
            j++;
        }
        k++;

        while (i <= meio) {
            aux[k] = vetor[i];
            i++;
            k++;
        }
        while (j <= direita) {
            aux[k] = vetor[j];
            j++;
            k++;
        }
        for (i = esquerda; i <= direita; i++) {
            vetor[i] = aux[i - esquerda];
        }
    }
}
int *merge_sort (int *vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda)/2;
        merge_sort(vetor, esquerda, direita);
        merge_sort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
    return vetor;
}



//quicksort