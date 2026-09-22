#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

no_t *lista_encadeada_criar (int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->dados = valor;
    no->proximo = NULL;
    return no;
}

void lista_encadeada_inserir (no_t **inicio, int valor) {
    if (inicio == NULL) return;
    no_t *novo_no = lista_encadeada_criar(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}

void lista_encadeada_remover (no_t **inicio, int valor) {
    if (inicio == NULL) return;
    no_t *atual = *inicio;
    no_t *anterior = NULL;

    while (atual) {
        if (atual->dados == valor) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            }
            else {
                *inicio = atual->proximo;
            }
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void lista_encadeada_imprimir (no_t *inicio) {
    if (inicio == NULL) return;
    no_t *atual = inicio;

    while (atual) {
        printf("%d ", atual->dados);
        atual = atual->proximo;
    }
}

void lista_encadeada_destruir (no_t **inicio) {
    if (inicio == NULL) return;

    no_t *atual = *inicio;
    while (atual) {
        no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}