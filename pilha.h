#ifndef _PILHA_
#define _PILA_

#include "base.h"

typedef struct pilha{
	No *topo;
	int tam;
	int naoIniciada;
}Pilha;

int iniciaPilha(Pilha *p);

int inserePilha(Pilha *p, Dados *d);

Dados* removePilha(Pilha *p);

void mostraPilha(Pilha *p);

int pilhaVazia(Pilha *p);


#endif