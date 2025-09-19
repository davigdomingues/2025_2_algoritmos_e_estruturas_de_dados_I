#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

typedef struct no_{
	ITEM *item;
	No *proximo;
}

typedef struct lista_{
	No *inicio;
	No *fim;
	int tamanho;
	bool ordenada;
}

LISTA *lista_criar(bool ordenada) {
	LISTA *l;
	
	l = (LISTA*)malloc(sizeof(LISTA));
	if (l) {
		l->inicio = NULL;
		l->fim = NULL;
		l->tamanho = 0;
		l->ordenada = ordenada;
	}
	
	return l;
}

bool *lista_inserir(LISTA *lista, ITEM *item) {
	if (lista != NULL && !lista_cheia(lista) {
		if (lista->ordenada)
			
		else
			return lista_inserir_fim(lista, item);
	}
}

bool lista_inserir_fim(LISTA *lista, ITEM *item) { // Sem verificações, já que apenas é usada quando é consistente a inserção.
	No *p;
	p = (No*)malloc(sizeof(No));
	
	if (p) {
		p->item = item;
		p->proximo = NULL;
	
		if (lista->tamanho == 0)
			lista->inicio = p;
	
		else
			lista->fim->proximo = p;
	
		lista->fim = p;
		lista->tamanho++;
		return true;
	}
	
	return false;	
}
ITEM *lista_busca_n_ordenada(LISTA *lista, int chave) {
	No *p;
	
	if (lista != NULL ) {
		p = lista->inicio;
		
		while (p != NULL) {
			if (item_get_chave(p->item) == chave)
				return p->item;
			p = p->proximo;
		}
	}
}
	
  return NULL;
}

ITEM *lista_busca_ordenada(ITEM *lista, int chave) {
	No *p;
	
	if (lista != NULL) {
		p = lista->inicio;
		
		while (p != NULL && item_get_chave(p->item) < chave)
			p = p->proximo;
	}
	
	if (p == NULL || item_get_chave(p->item) > chave)
		return NULL;
	
	else
		return p->item;
	
	return NULL;
}

ITEM *lista_busca_rec(No *n, int chave) {
	if (n == NULL)
		return NULL;
	
	if (item_get_chave(n->item) == chave)
		return n->item;
	
	return lista_busca_rec(n->proximo, chave);
}

ITEM *lista_busca(LISTA *lista, int chave) {
	if (lista != NULL) {
		if (!lista->ordenada)
			it = lista_n_busca_ordenada(lista, chave);
		else
			it = lista_busca_ordenada(lista, chave);
		
		return it;
	}
}

bool lista_cheia(LISTA *lista) {
	return false;
}

ITEM *lista_remover(LISTA *lista, int chave) {
	NO *p, *a = NULL;
	
	if (lista != NULL) {
		p = lista->inicio;
		
		while (p != NULL && item_get_chave(p->item) != chave) {
			a = p;
			p = p->proximo;
		}
		
		if (p != NULL) {
			if (lista->inicio == p) // primeiro
				lista->inicio = lista->proximo;
			
			else
				a->proximo = p->proximo;
			
			if (lista->fim == p) // último no
				lista->fim = a;
			
			p->proximo = NULL;
			ITEM *it = p->item;
			free(p);
			lista->tamanho--;
			
			return it;
		}
	}
	
	return NULL;
}

void lista_imprimir(LISTA *lista) {
	NO *P;
	
	if (lista != NULL) {
		
	}
}