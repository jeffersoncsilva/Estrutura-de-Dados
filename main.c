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
	initialize(fila);
	char linha[200];
	fgets(linha, 200, arq);
	while(fgets(linha, 200, arq)){
		Dados *d = converteDados(linha);
		enqueue(fila, d);
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

	Fila f;
	criaFila(arquivo, &f);
	show(&f);
	printf("\nClone: \n");
	Fila *f2 = clone(&f);
	show(f2);
	printf("\n");
	return 0;
}
