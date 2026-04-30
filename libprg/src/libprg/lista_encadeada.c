#include <stdlib.h>

#include "libprg/libprg.h"

/* =========================
        LISTA ENCADEADA
   ========================= */

no_t* lista_encadeada_criar() {
    return NULL;
}

void lista_encadeada_inserir(no_t **inicio, int valor) {
    if (!inicio) return;

    no_t *novo = malloc(sizeof(no_t));
    if (!novo) return;

    novo->dados = valor;
    novo->proximo = *inicio;

    *inicio = novo;
}

int lista_encadeada_remover(no_t **inicio) {
    if (!inicio || *inicio == NULL) return -1;

    no_t *temp = *inicio;
    int valor = temp->dados;

    *inicio = temp->proximo;
    free(temp);

    return valor;
}

bool lista_encadeada_vazia(no_t *inicio) {
    return inicio == NULL;
}

void lista_encadeada_destruir(no_t **inicio) {
    if (!inicio) return;

    while (*inicio != NULL) {
        lista_encadeada_remover(inicio);
    }
}