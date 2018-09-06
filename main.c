#include<stdio.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"

void criaLista(FILE *a, Lista *lst){
	iniciaLista(lst);
	char l[100];
	fgets(l, 100, a);
	while(fgets(l, 100, a)){
		insereFim(lst, converteDados(l));
	}
}

void criaPilha(FILE *arq, Pilha *p){
	iniciaPilha(p);
	char linha[200];
	fgets(linha, 200, arq);
	while(fgets(linha, 200, arq)){
		inserePilha(p, converteDados(linha));
	}
}

Fila* criaFila(FILE *arq, Fila *fila){
	iniciaFila(fila);
	char linha[200];
	fgets(linha, 200, arq);
	while(fgets(linha, 200, arq)){
		insereFila(fila, converteDados(linha));
	}
}

int main(){

	FILE *arquivo = carregaArquivo();
	if(arquivo==NULL){
		printf("Arquivo nao carregado.");
		return 0;
	}
	/*
	Lista lst;
	printf("LISTA: ");
	criaLista(arquivo, &lst);
	mostraLista(&lst);
	printf("\n\n\n");

	arquivo = carregaArquivo();
	printf("FILA: ");
	Fila fila;
	criaFila(arquivo, &fila);
	mostraFila(&fila);
	printf("\n\n\n");
	
	arquivo = NULL;
	arquivo = carregaArquivo();
	*/
	printf("PILHA: ");
	Pilha p;
	criaPilha(arquivo, &p);
	mostraPilha(&p);

	return 0;
}
