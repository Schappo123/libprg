#include <stdlib.h>
#include "libprg/libprg.h"

/* =========================
FUNÇÃO AUXILIAR
   ========================= */

static void aumentar_capacidade(int **dados, int *capacidade) {
    int nova_capacidade = (*capacidade == 0) ? 4 : (*capacidade * 2);

    int *novo = realloc(*dados, nova_capacidade * sizeof(int));
    if (!novo) return;

    *dados = novo;
    *capacidade = nova_capacidade;
}

/* =========================
        LISTA LINEAR
   ========================= */

lista_t* lista_linear_criar() {
    lista_t *l = malloc(sizeof(lista_t));
    if (!l) return NULL;

    l->dados = NULL;
    l->tamanho = 0;
    l->capacidade = 0;

    return l;
}

void lista_linear_inserir(lista_t *l, int valor) {
    if (!l) return;

    if (l->tamanho >= l->capacidade) {
        aumentar_capacidade(&l->dados, &l->capacidade);
    }

    l->dados[l->tamanho++] = valor;
}

int lista_linear_remover(lista_t *l) {
    if (!l || l->tamanho == 0) return -1;
    return l->dados[--l->tamanho];
}

int buscar (lista_t *lista, int elemento) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == elemento) return i;
    }
    return -1;
}

bool lista_linear_vazia(lista_t *l) {
    return !l || l->tamanho == 0;
}

int lista_linear_tamanho(lista_t *l) {
    if (!l) return 0;
    return l->tamanho;
}

void lista_linear_destruir(lista_t *l) {
    if (!l) return;

    free(l->dados);
    free(l);
}