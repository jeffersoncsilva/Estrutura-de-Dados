#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "arvore.h"


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

void criaFila(FILE *arq, Fila *fila){
	iniciaFila(fila);
	char linha[200];
	fgets(linha, 200, arq);
	while(fgets(linha, 200, arq)){
		insereFila(fila, converteDados(linha));
	}
}

void criaArvore(FILE *arq, Arvore *arv){
	iniciaArvore(arv);
	char linha[200];
	fgets(linha, 200, arq);
	while(fgets(linha, 200, arq)){
		insereArvore(arv, converteDados(linha));
	}
}

int main(){

	FILE *arquivo = carregaArquivo();
	if(arquivo==NULL){
		printf("Arquivo nao carregado.");
		return 0;
	}

	Arvore arv;
	criaArvore(arquivo, &arv);
	printf("\nIn-Ordem: \n");
	inOrdem(arv.raiz);
	printf("\n\nPre-Ordem: \n");
	preOrdem(arv.raiz);
	printf("\n\nPos-Ordem: \n");
	posOrdem(arv.raiz);
	printf("\n");
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
	printf("PILHA: ");
	Pilha p;
	criaPilha(arquivo, &p);
	mostraPilha(&p);
	*/

	return 0;
}
