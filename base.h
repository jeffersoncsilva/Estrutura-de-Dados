/*Biblioteca base com funcoes bases.*/
#ifndef _BASE_H
#define _BASE_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define true 1
#define false 0

#define URL "dados.txt"

typedef struct dados{
	char nome[100];
	char email[50];
	char telefone[12];
	char endereco[100];
	int id;
}Dados;

typedef struct no{
	Dados *dado;
	struct no *prox;
	struct no *ant;
	struct no *left;
	struct no *right;
}No;

void mostraDados(Dados *d);

void mostraNo(No *n);

FILE * carregaArquivo();

Dados* converteDados(char *linha);
/*
Pilha* criaPilha(FILE *arq);

Fila* criaFila(FILE *arq);

Lista* criaLista(FILE *arq);
*/
void mostraTela(char msg[]);

#endif