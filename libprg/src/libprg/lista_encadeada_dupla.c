
#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

void lista_dupla_inicializar(lista_dupla_t *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int lista_dupla_inserir_inicio(lista_dupla_t *lista, int valor) {
    no_lista_t *novo = malloc(sizeof(no_lista_t));

    if (novo == NULL)
        return 0;

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = lista->inicio;

    if (lista->inicio != NULL)
        lista->inicio->anterior = novo;
    else
        lista->fim = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return 1;
}

int lista_dupla_inserir_fim(lista_dupla_t *lista, int valor) {
    no_lista_t *novo = malloc(sizeof(no_lista_t));

    if (novo == NULL)
        return 0;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->fim;

    if (lista->fim != NULL)
        lista->fim->proximo = novo;
    else
        lista->inicio = novo;

    lista->fim = novo;
    lista->tamanho++;

    return 1;
}

int lista_dupla_buscar(lista_dupla_t *lista, int valor) {
    no_lista_t *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->valor == valor)
            return 1;

        atual = atual->proximo;
    }

    return 0;
}

int lista_dupla_remover(lista_dupla_t *lista, int valor) {
    no_lista_t *atual = lista->inicio;

    while (atual != NULL && atual->valor != valor)
        atual = atual->proximo;

    if (atual == NULL)
        return 0;

    if (atual->anterior != NULL)
        atual->anterior->proximo = atual->proximo;
    else
        lista->inicio = atual->proximo;

    if (atual->proximo != NULL)
        atual->proximo->anterior = atual->anterior;
    else
        lista->fim = atual->anterior;

    free(atual);
    lista->tamanho--;

    return 1;
}

void lista_dupla_percorrer(lista_dupla_t *lista) {
    no_lista_t *atual = lista->inicio;

    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

void lista_dupla_libera(lista_dupla_t *lista) {
    no_lista_t *atual = lista->inicio;

    while (atual != NULL) {
        no_lista_t *aux = atual;
        atual = atual->proximo;
        free(aux);
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}
