#include <stdlib.h>
#include "libprg/libprg.h"

/* =========================
FUNÇÃO AUXILIAR
   ========================= */
static void aumentar_capacidade(int **dados, int *capacidade) {
    int nova_capacidade = (*capacidade == 0) ? 4 : (*capacidade * 2);

    int *novo = realloc(*dados, nova_capacidade * sizeof(int));
    if (!novo) return;

    *dados = novo;
    *capacidade = nova_capacidade;
}

/* =========================
            PILHA
   ========================= */

pilha_t* pilha_criar() {
    pilha_t *p = malloc(sizeof(pilha_t));
    if (!p) return NULL;

    p->dados = NULL;
    p->topo = -1;
    p->capacidade = 0;

    return p;
}

void pilha_empilhar(pilha_t *p, int valor) {
    if (!p) return;

    if (p->topo + 1 >= p->capacidade) {
        aumentar_capacidade(&p->dados, &p->capacidade);
    }

    p->dados[++p->topo] = valor;
}

int pilha_desempilhar(pilha_t *p) {
    if (!p || p->topo < 0) return -1;
    return p->dados[p->topo--];
}

int pilha_topo(pilha_t *p) {
    if (!p || p->topo < 0) return -1;
    return p->dados[p->topo];
}

bool pilha_vazia(pilha_t *p) {
    return (!p || p->topo < 0);
}

int pilha_tamanho(pilha_t *p) {
    if (!p) return 0;
    return p->topo + 1;
}

void pilha_destruir(pilha_t *p) {
    if (!p) return;

    free(p->dados);
    free(p);
}