#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define TAM_MAX 10

struct pilha {
	int itens[TAM_MAX];
	int tp;
};

Pilha * criar() {
	Pilha * p = malloc(sizeof(Pilha));
	p->tp = 0;
	return p;
}

void destruir(Pilha * p) {
	if (p != NULL) {
		free(p);
	}	
}

int desempilhar(Pilha * p) {
	if (p->tp == 0) {
		return -1;
	}
	return p->itens[--p->tp];	
}

void empilhar(Pilha * p, int v) {
	if (p->tp == TAM_MAX) {
		printf("Pilha cheia!\n");
		return;
	}	
	p->itens[p->tp++] = v;	
}

int tamanho(Pilha * p) {
	return p->tp;
}

int topo(Pilha * p) {
	if (p->tp == 0) {
		return -1;
	}	
	return p->itens[p->tp-1];
}

void imprimir(Pilha * p) {
	int i;
	printf("[");
	for (i=0; i<p->tp; i++) {
		printf(" %d", p->itens[i]);
	}
	printf(" ]\n");
}

int eh_igual(Pilha * p1, Pilha * p2) {
	int i;
	if (p1->tp == p2->tp) {
		for(i=0; i<p1->tp; i++) {
			if (p1->itens[i] != p2->itens[i]) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}


