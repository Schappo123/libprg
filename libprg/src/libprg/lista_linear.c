#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

lista_linear_t *lista_linear_criar (int capacidade) {
    if (capacidade <= 0) return NULL;
    lista_linear_t *lista = malloc(sizeof(lista_linear_t));
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->dados = malloc (sizeof (int) * capacidade);
    return lista;
}

int lista_linear_tamanho(lista_linear_t* lista) {
    return lista->tamanho;
}

void lista_linear_inserir(lista_linear_t* lista, int valor) {
    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
}

int lista_linear_remover (lista_linear_t* lista, int valor) {
    int index = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) {
            index = i;
        }
    }
    lista->dados[index] = lista->dados[lista->tamanho - 1];
    lista->tamanho--;
}

bool lista_linear_vazia (lista_linear_t* lista) {
    if (lista->tamanho == 0) return true;
    return false;
}

void lista_linear_imprimir (lista_linear_t* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
}

void lista_linear_destruir (lista_linear_t* lista) {
    free(lista->dados);
    free(lista);
}