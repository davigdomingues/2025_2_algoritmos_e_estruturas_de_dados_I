#include <stdlib.h>
#include "fila.h"

struct no_ {
    ITEM *item;
    NO *proximo;
};

struct fila_ {
    NO *inicio;
    NO *fim;
    int tamanho;
};

FILA *fila_criar(void) {
    FILA *f = malloc(sizeof *f);
    if (!f) return NULL;
    f->inicio = f->fim = NULL;
    f->tamanho = 0;
    return f;
}

bool fila_inserir(FILA *f, ITEM *item) {
    if (!f || !item) return false;
    NO *novo = malloc(sizeof *novo);
    if (!novo) return false;
    novo->item = item;
    novo->proximo = NULL;
    if (f->fim) f->fim->proximo = novo;
    else       f->inicio = novo;
    f->fim = novo;
    f->tamanho++;
    return true;
}

ITEM *fila_remover(FILA *f) {
    if (!f || f->tamanho == 0) return NULL;
    NO *rem = f->inicio;
    ITEM *it = rem->item;
    f->inicio = rem->proximo;
    if (!f->inicio) f->fim = NULL;
    free(rem);
    f->tamanho--;
    return it;
}

ITEM *fila_frente(FILA *f) {
    if (!f || f->tamanho == 0) return NULL;
    return f->inicio->item;
}

int fila_tamanho(FILA *f) {
    return f ? f->tamanho : 0;
}

bool fila_vazia(FILA *f) {
    return !f || f->tamanho == 0;
}

bool fila_cheia(FILA *f) {
    (void)f;
    return false;
}

void fila_imprimir(FILA *f) {
    if (!f) { printf("NULL\n"); return; }
    for (NO *p = f->inicio; p; p = p->proximo) {
        item_imprimir(p->item);
        if (p->proximo) printf(" ");
    }
    printf("\n");
}

static void apagar_rec(NO *n) {
    if (!n) return;
    apagar_rec(n->proximo);
    item_apagar(&n->item);
    free(n);
}

void fila_apagar(FILA **f) {
    if (!f || !*f) return;
    apagar_rec((*f)->inicio);
    free(*f);
    *f = NULL;
}