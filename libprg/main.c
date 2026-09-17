#include <stdio.h>
#include "libprg/libprg.h"

int main () {

    lista_encadeada_t lista;
    lista.inicio = NULL;
    lista.tamanho = 0;

    lista_encadeada_inserir(&lista, 5);

    return 0;
}