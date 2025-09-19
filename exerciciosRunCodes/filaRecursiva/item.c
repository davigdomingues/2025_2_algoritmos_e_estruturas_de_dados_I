#include <stdlib.h>
#include "item.h"

struct item_ {
    int valor;
};

ITEM *item_criar(int chave, void *comp) {
    (void) comp;
    ITEM *i = malloc(sizeof *i);
    if (!i) return NULL;
    i->valor = chave;
    return i;
}

ITEM *item_criar_simple(int chave) {
    return item_criar(chave, NULL);
}

bool item_apagar(ITEM **item) {
    if (!item || !*item) return false;
    free(*item);
    *item = NULL;
    return true;
}

void item_imprimir(ITEM *item) {
    if (!item) { printf("NULL"); return; }
    printf("%d", item->valor);
}

int item_get_chave(ITEM *item) {
    return item ? item->valor : ERRO;
}

bool item_set_chave(ITEM *item, int chave) {
    if (!item) return false;
    item->valor = chave;
    return true;
}