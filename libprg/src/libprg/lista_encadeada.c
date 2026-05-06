#include <stdlib.h>
#include "libprg/libprg.h"

/* =========================
  LISTA ENCADEADA NÃO ORDENADA
   ========================= */

no_t *criar_no(int valor) {
    no_t *novo = malloc(sizeof(no_t));

    novo->dados = valor;
    novo->proximo = NULL;
    return novo;
}

no_t *lista_encadeada_criar() {
    return NULL;
}

void lista_encadeada_inserir(no_t **inicio, int valor) {
    no_t *novo = criar_no(valor);

    novo->proximo = *inicio;
    *inicio = novo;
}

bool lista_encadeada_remover(no_t **inicio, int valor) {
    no_t *atual = *inicio;
    no_t *anterior = NULL;

    while (atual != NULL && atual->dados != valor) {
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

no_t *lista_encadeada_buscar(no_t *inicio, int valor) {
    no_t *atual = inicio;

    while (atual != NULL) {
        if (atual->dados == valor) return atual;
        atual = atual->proximo;
    }

    return NULL;
}

void lista_encadeada_destruir(no_t **inicio) {
    no_t *atual = *inicio;

    while (atual != NULL) {
        no_t *prox = atual->proximo;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}

/* =========================
    LISTA ENCADEADA ORDENADA
   ========================= */

no_t *lista_encadeada_ordenada_criar() {
    return NULL;
}

void lista_encadeada_ordenada_inserir(no_t **inicio, int valor) {
    no_t *novo = criar_no(valor);

    if (*inicio == NULL || valor <= (*inicio)->dados) {
        novo->proximo = *inicio;
        *inicio = novo;
        return;
    }

    no_t *atual = *inicio;

    while (atual->proximo != NULL && atual->proximo->dados < valor) {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

bool lista_encadeada_ordenada_remover(no_t **inicio, int valor) {
    return lista_encadeada_remover(inicio, valor);
}

no_t *lista_encadeada_ordenada_buscar(no_t *inicio, int valor) {
    no_t *atual = inicio;

    while (atual != NULL) {
        if (atual->dados == valor) return atual;
        if (atual->dados > valor) return NULL;
        atual = atual->proximo;
    }

    return NULL;
}

void lista_encadeada_ordenada_destruir(no_t **inicio) {
    lista_encadeada_destruir(inicio);
}