#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p);
int estaVazia(Pilha *p);
int estaCheia(Pilha *p);
int empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p, int *valor);
int topo(Pilha *p, int *valor);

#endif