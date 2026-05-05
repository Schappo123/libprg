#include <stdlib.h>
#include "libprg/libprg.h"

/* =========================
        LISTA ENCADEADA
   ========================= */

no_t *criar_no() {
    return NULL;
}

lista_encadeada_t* lista_encadeada_criar(bool ordenada) {
    lista_encadeada_t* lista = malloc(sizeof(lista_encadeada_t));
    lista->inicio = NULL;
    lista->ordenada = ordenada;

    return lista;
}

void lista_encadeada_inserir(lista_encadeada_t *lista, int valor) {
    no_t *novo = criar_no(valor);

    novo->proximo = lista->inicio;
    lista->inicio = novo;

}

bool lista_encadeada_remover(no_t **inicio, int elemento) {
    no_t *atual = *inicio;
    no_t *anterior = NULL;

    while (atual != NULL && atual->dados != elemento) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
    return true;
}

no_t *lista_encadeada_buscar(no_t *inicio, int elemento) {
    no_t *atual = inicio;

    while (atual != NULL) {
        if (atual->dados == elemento) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void lista_encadeada_destruir(no_t **inicio) {

    no_t *atual = *inicio;
    no_t *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}
