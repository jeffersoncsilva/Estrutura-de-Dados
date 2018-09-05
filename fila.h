#include "base.h"
/*
char fl_nao_inicida[] = "Fila nao foi iniciada.";
char fl_vazia[] = "Fila esta vazia.";
char fl_ja_iniciada[] = "Fila ja foi iniciada.";
*/
typedef struct fila{
    No *ini;
    No *fim;
    int tam;
    int naoIniciado;
}Fila;

int iniciaFila(Fila *f);
/*E usado o ponteiro ant para o proximo no da fila.*/
int insereFila(Fila *f, Dados *d);

int esvaziaFila(Fila *f);

int filaVazia(Fila *f);

void mostraFila(Fila *f);
