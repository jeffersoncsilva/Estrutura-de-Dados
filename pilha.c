#include "pilha.h"

int iniciaPilha(Pilha *p){
	if(p->naoIniciada){
		p->topo = NULL;
		p->tam = 0;
		p->naoIniciada = false;
		return true;
	}else{
		printf("ERRO: Pilha ja foi inicada.");
		return false;
	}
}

int inserePilha(Pilha *p, Dados *d){
	if(p->naoIniciada){
		printf("ERRO: Pilha nao foi inicada.");
		return false;
	}
	No *novo = malloc(sizeof(No));
	novo->dado = d;
	if(p->topo != NULL){
		novo->ant = p->topo;
	}
	p->topo = novo;
	p->tam += 1;
	return true;
}

Dados* removePilha(Pilha *p){
	if(p->naoIniciada){
		printf("ERRO: Pilha ja foi iniciada.");
		return NULL;
	}
	if(pilhaVazia(p)){
		printf("ERRO: Pilha vazia.");
		return NULL;   
	}
	No *l = p->topo;
	p->topo = l->ant;
	p->tam-=1;
	Dados *d = l->dado;
	free(l);
	l=NULL;
	return d;
}

void mostraPilha(Pilha *p){
	if(p->naoIniciada){
		printf("ERRO: Pilha nao foi iniciada.");
	}else{
		No *n = p->topo;
		while(n){
			mostraNo(n);
			n = n->ant;
		}
	}
}

int pilhaVazia(Pilha *p){
	if(p->naoIniciada){
		printf("ERRO: Pilha nao foi iniciada.");
		return true;
	}

	return (p->topo == NULL ? true : false);
}

