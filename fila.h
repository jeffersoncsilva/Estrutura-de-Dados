#ifndef _FILA_
#define _FILA_
#include "base.h"

typedef struct fila{
    No *ini;
    No *fim;
    int tam;
    int naoIniciado;
}Fila;

int iniciaFila(Fila *f);

/*E usado o ponteiro ant para o proximo no da fila.*/
int insereFila(Fila *f, Dados *d);

Dados* removeFila(Fila *f);

int esvaziaFila(Fila *f);

int filaVazia(Fila *f);

void mostraFila(Fila *f);

#endif