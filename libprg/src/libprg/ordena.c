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