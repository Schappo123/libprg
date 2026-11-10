
#include <stdlib.h>
#include "libprg/libprg.h"

static int altura(avl_t raiz) {
    if (raiz == NULL)
        return 0;

    return raiz->altura;
}

static int maior(int a, int b) {
    return (a > b) ? a : b;
}

static int fator_balanceamento(avl_t raiz) {
    if (raiz == NULL)
        return 0;

    return altura(raiz->esquerda) - altura(raiz->direita);
}

static void atualizar_altura(avl_t raiz) {
    raiz->altura = 1 + maior(
        altura(raiz->esquerda),
        altura(raiz->direita)
    );
}

// Rotação simples à direita
static avl_t rotacao_direita(avl_t y) {
    avl_t x = y->esquerda;
    avl_t aux = x->direita;

    x->direita = y;
    y->esquerda = aux;

    atualizar_altura(y);
    atualizar_altura(x);

    return x;
}

// Rotação simples à esquerda
static avl_t rotacao_esquerda(avl_t x) {
    avl_t y = x->direita;
    avl_t aux = y->esquerda;

    y->esquerda = x;
    x->direita = aux;

    atualizar_altura(x);
    atualizar_altura(y);

    return y;
}

void avl_inicializar(avl_t *raiz) {
    *raiz = NULL;
}

static avl_t inserir_recursivo(avl_t raiz, int valor, int *sucesso) {
    if (raiz == NULL) {
        avl_t novo = malloc(sizeof(no_avl_t));

        if (novo == NULL) {
            *sucesso = 0;
            return NULL;
        }

        novo->valor = valor;
        novo->altura = 1;
        novo->esquerda = NULL;
        novo->direita = NULL;

        *sucesso = 1;
        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_recursivo(
            raiz->esquerda, valor, sucesso
        );
    }
    else if (valor > raiz->valor) {
        raiz->direita = inserir_recursivo(
            raiz->direita, valor, sucesso
        );
    }
    else {
        *sucesso = 0;
        return raiz;
    }

    if (!*sucesso)
        return raiz;

    atualizar_altura(raiz);

    int fb = fator_balanceamento(raiz);

    // Caso LL
    if (fb > 1 && valor < raiz->esquerda->valor)
        return rotacao_direita(raiz);

    // Caso RR
    if (fb < -1 && valor > raiz->direita->valor)
        return rotacao_esquerda(raiz);

    // Caso LR
    if (fb > 1 && valor > raiz->esquerda->valor) {
        raiz->esquerda = rotacao_esquerda(raiz->esquerda);
        return rotacao_direita(raiz);
    }

    // Caso RL
    if (fb < -1 && valor < raiz->direita->valor) {
        raiz->direita = rotacao_direita(raiz->direita);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

int avl_inserir(avl_t *raiz, int valor) {
    int sucesso = 0;

    *raiz = inserir_recursivo(*raiz, valor, &sucesso);

    return sucesso;
}

int avl_buscar(avl_t raiz, int valor) {
    if (raiz == NULL)
        return 0;

    if (valor == raiz->valor)
        return 1;

    if (valor < raiz->valor)
        return avl_buscar(raiz->esquerda, valor);

    return avl_buscar(raiz->direita, valor);
}

static avl_t menor_no(avl_t raiz) {
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;

    return raiz;
}

static avl_t remover_recursivo(avl_t raiz, int valor, int *sucesso) {
    if (raiz == NULL)
        return NULL;

    if (valor < raiz->valor) {
        raiz->esquerda = remover_recursivo(
            raiz->esquerda, valor, sucesso
        );
    }
    else if (valor > raiz->valor) {
        raiz->direita = remover_recursivo(
            raiz->direita, valor, sucesso
        );
    }
    else {
        *sucesso = 1;

        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            avl_t filho = raiz->esquerda ?
                raiz->esquerda : raiz->direita;

            free(raiz);
            return filho;
        }
        else {
            avl_t sucessor = menor_no(raiz->direita);

            raiz->valor = sucessor->valor;

            int removido = 0;
            raiz->direita = remover_recursivo(
                raiz->direita, sucessor->valor, &removido
            );
        }
    }

    if (raiz == NULL)
        return NULL;

    atualizar_altura(raiz);

    int fb = fator_balanceamento(raiz);

    // Caso LL
    if (fb > 1 && fator_balanceamento(raiz->esquerda) >= 0)
        return rotacao_direita(raiz);

    // Caso LR
    if (fb > 1 && fator_balanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacao_esquerda(raiz->esquerda);
        return rotacao_direita(raiz);
    }

    // Caso RR
    if (fb < -1 && fator_balanceamento(raiz->direita) <= 0)
        return rotacao_esquerda(raiz);

    // Caso RL
    if (fb < -1 && fator_balanceamento(raiz->direita) > 0) {
        raiz->direita = rotacao_direita(raiz->direita);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

int avl_remover(avl_t *raiz, int valor) {
    int sucesso = 0;

    *raiz = remover_recursivo(*raiz, valor, &sucesso);

    return sucesso;
}

void avl_libera(avl_t *raiz) {
    if (*raiz == NULL)
        return;

    avl_libera(&(*raiz)->esquerda);
    avl_libera(&(*raiz)->direita);

    free(*raiz);
    *raiz = NULL;
}

