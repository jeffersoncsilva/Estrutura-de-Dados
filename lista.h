#include "base.h"

typedef struct lista{
    No *inicio;
    No *fim;
    int tam;
}Lista;

int iniciaLista(Lista *l);

int insereInicio(Lista *l, Dados *d);

int insereFim(Lista *l, Dados *d);

int inserePosicao(Lista *l, Dados *d, int pos);

Dados* removeFim(Lista *l);

Dados* removeInicio(Lista *l);

Dados* removePosicao(Lista *l, int pos);

int listaVazia(Lista *l);

int tamanhoLista(Lista *l);

void mostraLista(Lista *l);



