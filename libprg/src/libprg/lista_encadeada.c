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

bool lista_encadeada_remover(no_t **inicio, int elemento) {
    if (inicio == NULL || *inicio == NULL) return false;

    no_t *atual = *inicio;
    no_t *anterior = NULL;

    while (atual != NULL && atual->dados != elemento) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return false;

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
    return true;
}

no_t* lista_encadeada_buscar(no_t *inicio, int elemento) {
    no_t *atual = inicio;

    while (atual != NULL) {
        if (atual->dados == elemento) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void lista_encadeada_destruir(no_t **inicio) {
    if (inicio == NULL) return;

    no_t *atual = *inicio;
    no_t *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}