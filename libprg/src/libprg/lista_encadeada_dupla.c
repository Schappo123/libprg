#include <stdlib.h>
#include "libprg/libprg.h"

/* =========================
LISTA ENCADEADA DUPLA NÃO ORDENADA
   ========================= */

nod_t *criar_nod(int valor) {
    nod_t *novo = malloc(sizeof(nod_t));

    novo->dados = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}

nod_t *lista_encadeada_dupla_criar() {
    return NULL;
}

void lista_encadeada_dupla_inserir(nod_t **inicio, int valor) {
    nod_t *novo = criar_nod(valor);

    novo->proximo = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = novo;
    }

    *inicio = novo;
}

bool lista_encadeada_dupla_remover(nod_t **inicio, int valor) {
    nod_t *atual = *inicio;

    while (atual != NULL && atual->dados != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) return false;

    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        *inicio = atual->proximo;
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
    return true;
}

nod_t *lista_encadeada_dupla_buscar(nod_t *inicio, int valor) {
    nod_t *atual = inicio;

    while (atual != NULL) {
        if (atual->dados == valor) return atual;
        atual = atual->proximo;
    }

    return NULL;
}

void lista_encadeada_dupla_destruir(nod_t **inicio) {
    nod_t *atual = *inicio;

    while (atual != NULL) {
        nod_t *prox = atual->proximo;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}

/* =========================
LISTA ENCADEADA DUPLA ORDENADA
   ========================= */

nod_t *lista_encadeada_dupla_ordenada_criar() {
    return NULL;
}

void lista_encadeada_dupla_ordenada_inserir(nod_t **inicio, int valor) {
    nod_t *novo = criar_nod(valor);

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    nod_t *atual = *inicio;

    if (valor <= atual->dados) {
        novo->proximo = atual;
        atual->anterior = novo;
        *inicio = novo;
        return;
    }

    while (atual->proximo != NULL && atual->proximo->dados < valor) {
        atual = atual->proximo;
    }

    if (atual->proximo == NULL) {
        atual->proximo = novo;
        novo->anterior = atual;
        return;
    }

    novo->proximo = atual->proximo;
    novo->anterior = atual;

    atual->proximo->anterior = novo;
    atual->proximo = novo;
}

bool lista_encadeada_dupla_ordenada_remover(nod_t **inicio, int valor) {
    return lista_encadeada_dupla_remover(inicio, valor);
}

nod_t *lista_encadeada_dupla_ordenada_buscar(nod_t *inicio, int valor) {
    nod_t *atual = inicio;

    while (atual != NULL) {
        if (atual->dados == valor) return atual;
        if (atual->dados > valor) return NULL;
        atual = atual->proximo;
    }

    return NULL;
}

void lista_encadeada_dupla_ordenada_destruir(nod_t **inicio) {
    lista_encadeada_dupla_destruir(inicio);
}