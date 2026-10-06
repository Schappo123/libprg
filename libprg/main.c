#include <stdio.h>
#include "libprg/libprg.h"

int main () {

    ordenacao_t vetor = {{100,5,87,2,13,22},6};
    mergeSort(&vetor, 0, 5);

    for (int i = 0; i < 6; i++) {
        printf("%d", vetor.dados[i]);
    }
    return 0;
}