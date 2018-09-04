#include "fila.h"
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
}*/

Fila* criaFila(FILE *arq){
	Fila *f = malloc(sizeof(Fila));
	iniciaFila(f);
	char l[200];
	fgets(l, 200, arq);
	while(fgets(l, 200, arq))
		insereFila(f, converteDados(l));

	return f;
}

/*
Lista* criaLista(FILE *arq){
	Lista *lst = malloc(sizeof(Lista));
	iniciaLista(l);
	char l[200];
	fgets(l, 200, arq);
	while(fgets(l, 200, arq))
		insereLista(lst, converteDados(l));

	return l;
}*/


int main(){

	FILE *file = carregaArquivo();
	/*Pilha *p = criaPilha(file);
	mostraPilha(p);*/

	Fila *f = criaFila(file);
	mostraFila(f);
	
	return 0;
}
