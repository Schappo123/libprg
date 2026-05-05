#include <stdlib.h>
#include "libprg/libprg.h"

/* =========================
    LISTA ENCADEADA DUPLA
   ========================= */

nod_t *lista_encadeada_dupla_criar () {
    return NULL;
}

void lista_encadeada_dupla_inserir (nod_t **inicio, int valor) {
    nod_t *novo = malloc(sizeof(nod_t));

    novo->dados = valor;
    novo->anterior = NULL;
    novo->proximo = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = novo;
    }
    *inicio = novo;
}

bool lista_encadeada_dupla_remover (nod_t** inicio) {
    nod_t *temp = *inicio;
    int valor = temp->dados;

    *inicio = temp->proximo;

    if (*inicio != NULL) {
        (*inicio)->anterior = NULL;
    }

    free(temp);
    return true;
}

nod_t* lista_encadeada_dupla_buscar (nod_t *inicio, int elemento) {
    nod_t *atual = inicio;

    while (atual != NULL) {
        if (atual->dados == elemento) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void lista_encadeada_dupla_destruir (nod_t **inicio) {
    while (*inicio != NULL) {
        lista_encadeada_dupla_destruir(inicio);
    }
}