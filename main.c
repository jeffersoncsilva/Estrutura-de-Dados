#include<stdio.h>
#include "lista.h"

Lista* criaLista(FILE *a, Lista *lst){
	if(lst== NULL){
		/*Em breve uma implementacao aqui.*/
		return NULL;
	}else{
		char l[100];
		fgets(l, 100, a);
		while(fgets(l, 100, a)){
			insereFim(lst, converteDados(l));
		}
		return lst;
	}
}

int main(){
	FILE *arquivo;
	Lista lst;
	iniciaLista(&lst);
	arquivo = fopen("dados.txt", "rt");
	if(arquivo==NULL){
		printf("ERRO: Arquivo nao carregado.");
		return 0;
	}
	criaLista(arquivo, &lst);
	printf("TAM: %d\n", tamanhoLista(&lst));
	removeInicio(&lst);
	printf("TAM: %d\n", tamanhoLista(&lst));
	removeFim(&lst);
	printf("TAM: %d\n", tamanhoLista(&lst));
	removePosicao(&lst, 4);
	printf("TAM: %d\n", tamanhoLista(&lst));
	return 0;

}


/*
#include "fila.h"
Fila* criaFila(FILE *arq, Fila *fila){
	if(fila == NULL){
		Fila *f = malloc(sizeof(Fila));
		iniciaFila(f);
		char linha[200];
		fgets(linha, 200, arq);
		while(fgets(linha, 200, arq)){
			insereFila(f, converteDados(linha));
		}
		return f;
	}else{
		char linha[200];
		fgets(linha, 200, arq);
		while(fgets(linha, 200, arq)){
			insereFila(fila, converteDados(linha));
		}
		return fila;
	}
}

int main(){
	FILE *arquivo;
	Fila fila;
	iniciaFila(&fila);
	arquivo = fopen("dados.txt", "rt");
	if(arquivo==NULL){
		printf("ERRO: Arquivo nao carregado.");
	}else{
		criaFila(arquivo, &fila);
		mostraFila(&fila);
	}
	return 0;

}*/

/*
#include "pilha.h"
Pilha* criaPilha(FILE *arq){
	Pilha *p = malloc(sizeof(Pilha));
	iniciaPilha(p);
	char linha[200];
	fgets(linha, 200, arq);
	while(fgets(linha, 200, arq)){
		inserePilha(p, converteDados(linha));
	}
	return p;
}
int main(){
	FILE *fl;
	Pilha *p;
	fl = fopen("dados.txt", "rt");
	if(fl==NULL){
		printf("ERRO: Arquivo nao carregado.");
	}else{
		p = criaPilha(fl);
		mostraPilha(p);
	}
	return 0;
}
*/

