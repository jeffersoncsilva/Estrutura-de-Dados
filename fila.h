#ifndef _FILA_
#define _FILA_
#include "base.h"

typedef struct fila{
    No *ini;
    No *fim;
    int tam;
    int naoIniciado;
}Fila;

//Inicia a fila.
int initialize(Fila *f);

//Conta todos os elementos da fila.
int count(Fila *f);

//Limpa toda a fila.
int clearFila(Fila *f);

//Cria uma nova fila e retorna o endereco dela.
Fila* clone (Fila *f);

//Troca a fila um e a fila 2.
int swap(Fila *f1, Fila *f2);

//Verifica se o objeto esta ou nao na fila.
int contains(Fila *f, No *n);

//Desempilha e retorna o primeiro objeto da fila.
Dados* dequeue(Fila *f);
//Coloca um objeto na fila.
int enqueue(Fila *f, Dados *d);

//Empilha um no.
int enqueueNode(Fila *f, No *n);
//Desenpilha um no.
No *dequeueNode(Fila *f);

//retorna true caso a fila esteja vazia.
int empty(Fila *f);

//retorna se dois nos sao iguais comparando o id de ambos.
int equals(No *n1, No *n2);

//Retorna o topo da fila.
Dados* peek(Fila *f);

//Mostra a fila.
void show(Fila *f);


#endif