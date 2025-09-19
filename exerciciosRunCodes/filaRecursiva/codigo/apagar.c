#include <stdio.h>
#include "fila.h"

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    FILA *f = fila_criar();
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        ITEM *it = item_criar_simple(x);
        fila_inserir(f, it);
    }

    fila_apagar(&f);
    printf("Fila Vazia!\n");
    return 0;
}