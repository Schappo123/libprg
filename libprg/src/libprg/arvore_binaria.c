
#include <stdlib.h>
#include "libprg/libprg.h"

void abp_inicializar(abp_t *raiz) {
    *raiz = NULL;
}

int abp_inserir(abp_t *raiz, int valor) {
    if (*raiz == NULL) {
        no_abp_t *novo = malloc(sizeof(no_abp_t));

        if (novo == NULL)
            return 0;

        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        *raiz = novo;
        return 1;
    }

    if (valor < (*raiz)->valor)
        return abp_inserir(&(*raiz)->esquerda, valor);

    if (valor > (*raiz)->valor)
        return abp_inserir(&(*raiz)->direita, valor);

    return 0;
}

int abp_buscar(abp_t raiz, int valor) {
    if (raiz == NULL)
        return 0;

    if (valor == raiz->valor)
        return 1;

    if (valor < raiz->valor)
        return abp_buscar(raiz->esquerda, valor);

    return abp_buscar(raiz->direita, valor);
}

static no_abp_t *menor_no(no_abp_t *raiz) {
    while (raiz != NULL && raiz->esquerda != NULL)
        raiz = raiz->esquerda;

    return raiz;
}

int abp_remover(abp_t *raiz, int valor) {
    if (*raiz == NULL)
        return 0;

    if (valor < (*raiz)->valor)
        return abp_remover(&(*raiz)->esquerda, valor);

    if (valor > (*raiz)->valor)
        return abp_remover(&(*raiz)->direita, valor);

    no_abp_t *aux = *raiz;

    // Caso 1: nó sem filhos
    if (aux->esquerda == NULL && aux->direita == NULL) {
        free(aux);
        *raiz = NULL;
    }
    // Caso 2: nó com apenas filho direito
    else if (aux->esquerda == NULL) {
        *raiz = aux->direita;
        free(aux);
    }
    // Caso 2: nó com apenas filho esquerdo
    else if (aux->direita == NULL) {
        *raiz = aux->esquerda;
        free(aux);
    }
    // Caso 3: nó com dois filhos
    else {
        no_abp_t *sucessor = menor_no(aux->direita);

        aux->valor = sucessor->valor;

        abp_remover(&aux->direita, sucessor->valor);
    }

    return 1;
}

void abp_libera(abp_t *raiz) {
    if (*raiz == NULL)
        return;

    abp_libera(&(*raiz)->esquerda);
    abp_libera(&(*raiz)->direita);

    free(*raiz);
    *raiz = NULL;
}
