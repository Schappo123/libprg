#include <stdio.h>
#include <stdbool.h>
#include <libprg/libprg.h>

int main() {
    int vetor[10] = {8,6,100,8,3,8,44,22,1,13};

    bubble_sort(vetor, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", vetor[i]);
    }

}