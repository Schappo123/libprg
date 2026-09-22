#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

no_t *lista_encadeada_criar_no (int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->dados = valor;
    no->proximo = NULL;
    return no;
}

void lista_encadeada_inserir (lista_encadeada_t *lista, int valor) {
    if (lista->inicio == NULL) return;
    no_t *novo_no = lista_encadeada_criar_no(valor);
    novo_no->proximo = lista->inicio;
    lista->inicio = novo_no;
    lista->tamanho++;
}

void lista_encadeada_remover (lista_encadeada_t *lista, int valor) {
    if (lista->inicio == NULL) return;
    no_t *atual = lista->inicio;
    no_t *anterior = NULL;

    while (atual) {
        if (atual->dados == valor) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            }
            else {
                lista->inicio = atual->proximo;
            }
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

int lista_encadeada_tamanho (lista_encadeada_t *lista) {
    return lista->tamanho;
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