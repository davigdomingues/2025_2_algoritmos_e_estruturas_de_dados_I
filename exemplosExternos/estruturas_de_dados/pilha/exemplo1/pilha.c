#include "pilha.h"

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int empilhar(Pilha *p, int valor) {
    if (estaCheia(p)) return 0;
    p->dados[++p->topo] = valor;
    return 1;
}

int desempilhar(Pilha *p, int *valor) {
    if (estaVazia(p)) return 0;
    *valor = p->dados[p->topo--];
    return 1;
}

int topo(Pilha *p, int *valor) {
    if (estaVazia(p)) return 0;
    *valor = p->dados[p->topo];
    return 1;
}