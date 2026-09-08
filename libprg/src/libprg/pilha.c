#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

pilha_t *pilha_criar (int capacidade) {
    if (capacidade <= 0) return NULL;
    pilha_t *pilha = malloc(sizeof(pilha_t));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->dados = malloc(sizeof(int) * capacidade);
    return pilha;
}

int pilha_tamanho (pilha_t *p) {
    if (p->topo == -1) return 0;
    return p->dados[p->topo];
}

void pilha_empilhar (pilha_t *p, int valor) {
    if (pilha_tamanho(p) == 0) return;
    if (pilha_tamanho(p) < p->capacidade) {
        p->topo++;
        p->dados[p->topo] = valor;
    }
}

int pilha_desempilhar (pilha_t *p) {
    if (p->topo >= 0) {
        int valor = p->dados[p->topo];
        p->topo--;
        return valor;
    }
    return -1;
}

void pilha_imprimir (pilha_t *p) {
    for (int i = 0; i < pilha_tamanho(p); i++) {
        printf("%d ", p->dados[i]);
    }
}

void pilha_destruir (pilha_t *p) {
    free(p->dados);
    free(p);
}