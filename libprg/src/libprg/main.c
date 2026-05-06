#include <stdio.h>
#include <stdbool.h>
#include <libprg/libprg.h>

int main() {

    /* =========================
              PILHA
       ========================= */
    printf("===== TESTE PILHA =====\n");

    pilha_t *p = pilha_criar();
    printf("Pilha vazia? %s\n", pilha_vazia(p) ? "sim" : "nao");

    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);

    printf("Topo: %d\n", pilha_topo(p));
    printf("Tamanho: %d\n", pilha_tamanho(p));

    printf("Desempilhando: ");
    while (!pilha_vazia(p)) {
        printf("%d ", pilha_desempilhar(p));
    }
    printf("\n");

    pilha_destruir(p);


    /* =========================
              FILA
       ========================= */
    printf("\n===== TESTE FILA =====\n");

    fila_t *f = fila_criar();
    printf("Fila vazia? %s\n", fila_vazia(f) ? "sim" : "nao");

    fila_enfileirar(f, 5);
    fila_enfileirar(f, 15);
    fila_enfileirar(f, 25);
    fila_enfileirar(f, 35);

    printf("Inicio: %d\n", fila_inicio(f));
    printf("Tamanho: %d\n", fila_tamanho(f));

    printf("Desenfileirando: ");
    while (!fila_vazia(f)) {
        printf("%d ", fila_desenfileirar(f));
    }
    printf("\n");

    fila_destruir(f);


    /* =========================
           LISTA LINEAR
       ========================= */
    printf("\n===== TESTE LISTA LINEAR =====\n");

    lista_t *l = lista_linear_criar();
    printf("Lista vazia? %s\n", lista_linear_vazia(l) ? "sim" : "nao");

    lista_linear_inserir(l, 100);
    lista_linear_inserir(l, 200);
    lista_linear_inserir(l, 300);

    printf("Tamanho: %d\n", lista_linear_tamanho(l));

    printf("Buscar 200: indice = %d\n", lista_linear_buscar(l, 200));
    printf("Buscar 999: indice = %d\n", lista_linear_buscar(l, 999));

    printf("Removendo: ");
    while (!lista_linear_vazia(l)) {
        printf("%d ", lista_linear_remover(l));
    }
    printf("\n");

    lista_linear_destruir(l);


    /* =========================
     LISTA ENCADEADA NÃO ORDENADA
       ========================= */
    printf("\n===== TESTE LISTA ENCADEADA (NAO ORDENADA) =====\n");

    no_t *le = lista_encadeada_criar();

    lista_encadeada_inserir(&le, 10);
    lista_encadeada_inserir(&le, 20);
    lista_encadeada_inserir(&le, 30);

    printf("Buscar 20: %s\n", lista_encadeada_buscar(le, 20) ? "encontrou" : "nao encontrou");
    printf("Buscar 99: %s\n", lista_encadeada_buscar(le, 99) ? "encontrou" : "nao encontrou");

    printf("Remover 20: %s\n", lista_encadeada_remover(&le, 20) ? "removeu" : "nao removeu");
    printf("Remover 99: %s\n", lista_encadeada_remover(&le, 99) ? "removeu" : "nao removeu");

    printf("Buscar 20 depois de remover: %s\n", lista_encadeada_buscar(le, 20) ? "encontrou" : "nao encontrou");

    lista_encadeada_destruir(&le);
    printf("Lista destruida: %s\n", le == NULL ? "sim" : "nao");


    /* =========================
       LISTA ENCADEADA ORDENADA
       ========================= */
    printf("\n===== TESTE LISTA ENCADEADA (ORDENADA) =====\n");

    no_t *leo = lista_encadeada_ordenada_criar();

    lista_encadeada_ordenada_inserir(&leo, 30);
    lista_encadeada_ordenada_inserir(&leo, 10);
    lista_encadeada_ordenada_inserir(&leo, 20);

    printf("Buscar 20: %s\n", lista_encadeada_ordenada_buscar(leo, 20) ? "encontrou" : "nao encontrou");
    printf("Buscar 99: %s\n", lista_encadeada_ordenada_buscar(leo, 99) ? "encontrou" : "nao encontrou");

    printf("Remover 10: %s\n", lista_encadeada_ordenada_remover(&leo, 10) ? "removeu" : "nao removeu");
    printf("Remover 99: %s\n", lista_encadeada_ordenada_remover(&leo, 99) ? "removeu" : "nao removeu");

    printf("Buscar 10 depois de remover: %s\n", lista_encadeada_ordenada_buscar(leo, 10) ? "encontrou" : "nao encontrou");

    lista_encadeada_ordenada_destruir(&leo);
    printf("Lista destruida: %s\n", leo == NULL ? "sim" : "nao");


    /* =========================
   LISTA ENCADEADA DUPLA NÃO ORDENADA
       ========================= */
    printf("\n===== TESTE LISTA DUPLA (NAO ORDENADA) =====\n");

    nod_t *ld = lista_encadeada_dupla_criar();

    lista_encadeada_dupla_inserir(&ld, 10);
    lista_encadeada_dupla_inserir(&ld, 20);
    lista_encadeada_dupla_inserir(&ld, 30);

    printf("Buscar 20: %s\n", lista_encadeada_dupla_buscar(ld, 20) ? "encontrou" : "nao encontrou");
    printf("Buscar 99: %s\n", lista_encadeada_dupla_buscar(ld, 99) ? "encontrou" : "nao encontrou");

    printf("Remover 20: %s\n", lista_encadeada_dupla_remover(&ld, 20) ? "removeu" : "nao removeu");
    printf("Remover 99: %s\n", lista_encadeada_dupla_remover(&ld, 99) ? "removeu" : "nao removeu");

    printf("Buscar 20 depois de remover: %s\n", lista_encadeada_dupla_buscar(ld, 20) ? "encontrou" : "nao encontrou");

    lista_encadeada_dupla_destruir(&ld);
    printf("Lista destruida: %s\n", ld == NULL ? "sim" : "nao");


    /* =========================
     LISTA ENCADEADA DUPLA ORDENADA
       ========================= */
    printf("\n===== TESTE LISTA DUPLA (ORDENADA) =====\n");

    nod_t *ldo = lista_encadeada_dupla_ordenada_criar();

    lista_encadeada_dupla_ordenada_inserir(&ldo, 50);
    lista_encadeada_dupla_ordenada_inserir(&ldo, 10);
    lista_encadeada_dupla_ordenada_inserir(&ldo, 30);
    lista_encadeada_dupla_ordenada_inserir(&ldo, 20);

    printf("Buscar 30: %s\n", lista_encadeada_dupla_ordenada_buscar(ldo, 30) ? "encontrou" : "nao encontrou");
    printf("Buscar 99: %s\n", lista_encadeada_dupla_ordenada_buscar(ldo, 99) ? "encontrou" : "nao encontrou");

    printf("Remover 10: %s\n", lista_encadeada_dupla_ordenada_remover(&ldo, 10) ? "removeu" : "nao removeu");
    printf("Remover 99: %s\n", lista_encadeada_dupla_ordenada_remover(&ldo, 99) ? "removeu" : "nao removeu");

    printf("Buscar 10 depois de remover: %s\n", lista_encadeada_dupla_ordenada_buscar(ldo, 10) ? "encontrou" : "nao encontrou");

    lista_encadeada_dupla_ordenada_destruir(&ldo);
    printf("Lista destruida: %s\n", ldo == NULL ? "sim" : "nao");


    printf("\n===== TODOS OS TESTES FINALIZADOS =====\n");
    return 0;
}