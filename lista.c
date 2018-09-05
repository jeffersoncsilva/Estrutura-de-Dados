#include "lista.h"

int iniciaLista(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insereInicio(Lista *l, Dados *d){
    No *n = malloc(sizeof(No));
    n->dado = d;
    n->prox = l->inicio;
    n->ant = NULL;
    if(l->inicio != NULL){
        l->inicio->ant = n;
    }else{
        l->fim = n;
    }
    l->inicio = n;
    l->tam++;
    return true;
}

int insereFim(Lista *l, Dados *d){
    No *n = malloc(sizeof(No));
    n->dado = d;
    n->prox = NULL;
    n->ant = l->fim;
    if(l->fim != NULL)
        l->fim->prox = n;
    else
        l->inicio = n;
    l->fim = n;
    l->tam++;
    return true;
}

int inserePosicao(Lista *l, Dados *d, int pos){
    if(pos < 0 || pos > l->tam){
        printf("Posicao invalida de insercao.");
        return false;
    }
    if(pos == 0)
        insereInicio(l, d);
    if(pos == l->tam)
        insereFim(l, d);

    /*Busca o no anterior ao no buscado, para isso conta o no do inicio ao final.*/
    No *anterior = l->inicio;
    int i = 0;
    while(i<pos){
        anterior = anterior->prox;
        i++;
    }
    No *novo = malloc(sizeof(No));
    novo->dado = d;
    novo->ant = anterior->ant;
    anterior->ant->prox = novo;
    novo->prox = anterior;
    anterior->ant = novo;
    return true;
}

Dados* removeFim(Lista *l){
    if(listaVazia(l)){
        printf("Lista vazia.");
        return NULL;
    }
    No *lixo = l->fim;
    Dados *d = lixo->dado;
    if(l->fim->ant == NULL){/*Lista somente com um elemento.*/
        l->inicio = NULL;
     }
    l->fim = lixo->ant;
    free(lixo);
    lixo = NULL;
    l->tam--;
    return d;
}

Dados* removeInicio(Lista *l){
    if(listaVazia(l)){
        printf("Lista esta vazia.");
        return NULL;
    }
    No *lixo = l->inicio;
    Dados *d = lixo->dado;
    if(l->inicio->prox != NULL)
        l->inicio->ant = NULL;
    else
        l->fim = NULL;
    l->inicio = lixo->prox;
    free(lixo);
    lixo = NULL;
    l->tam--;
    return d;
}

Dados* removePosicao(Lista *l, int pos){
    if(pos < 0 || pos > l->tam){
        printf("Posicao invalida.");
        return NULL;
    }
    if(pos==0)
        return removeInicio(l);
    if(l->tam == pos)
        return removeFim(l);
    No*lixo = l->inicio;
    int i = 0;
    while(i<=0){
        lixo = lixo->prox;
        i++;
    }
    Dados *d = lixo->dado;
    lixo->ant->prox = lixo->prox;
    lixo->prox->ant = lixo->ant;
    free(lixo);
    lixo = NULL;
    l->tam--;
    return d;
}

int listaVazia(Lista *l){
    return (l->tam == 0 ? true : false);
}

int tamanhoLista(Lista *l){
    return l->tam;
}

void mostraLista(Lista *l){
    if(listaVazia(l)){
        printf("Lista vazia.\n");
    }else{
        No *m = l->inicio;
        while(m){
            mostraNo(m);
            m = m->prox;
        }

    }
}
