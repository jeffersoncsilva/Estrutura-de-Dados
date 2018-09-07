#include "base.h"

typedef struct arv{
    No *raiz;
}Arvore;

int iniciaArvore(Arvore *a);

int insereArvore(Arvore *a, Dados *d);

Dados* removeNo(Arvore *a, int ch);

void inOrdem(No *n);
void preOrdem(No *n);
void posOrdem(No *n);

