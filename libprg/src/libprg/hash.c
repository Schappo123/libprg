#include <stdlib.h>
#include <string.h>
#include "libprg/libprg.h"

/* =========================
         TABELA HASH
   ========================= */

dicionario_t *criar_dicionario (int m) {
    if (m < 1) return NULL;

    dicionario_t *d = malloc(sizeof(dicionario_t));
    d->vetor = malloc(m * sizeof(noh_t*));
    d->tamanho = m;

    return d;
}

int hash (char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i+1) * chave[i];
    }
    return soma;
}

int inserir_hash (dicionario_t *d, char *chave, int valor) {
    int indice = hash (chave, d->tamanho);
    noh_t *no = malloc(sizeof(noh_t));
    if (no == NULL) return 1;

    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return 1;
    }

    no->valor = valor;
    no->proximo = NULL;

    d->vetor[indice] = no;
    return 0;
}
