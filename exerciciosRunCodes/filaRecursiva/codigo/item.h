#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>
#define ERRO -32000

typedef struct item_ ITEM;

ITEM *item_criar(int chave, void *comp);
ITEM *item_criar_simple(int chave);
bool item_apagar(ITEM **item);
void item_imprimir(ITEM *item);
int item_get_chave(ITEM *item);
bool item_set_chave(ITEM *item, int chave);

#endif