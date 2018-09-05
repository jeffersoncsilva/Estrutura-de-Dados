#include "fila.h"

int iniciaFila(Fila *f){
    if(f->naoIniciado){
        f->ini = NULL;
        f->fim = NULL;
        f->tam = 0;
        f->naoIniciado = false;
        return true;
    }else{
        
        mostraTela("Fila ja foi iniciada.");
        return false;
    }
}

int insereFila(Fila *f, Dados *d){
    if(f->naoIniciado){
        mostraTela("Fila nao foi iniciada.");
        return false;
    }

    No *n = malloc(sizeof(No));
    n->dado = d;
    if(f->fim != NULL)
        f->fim->ant = n;
    else
        f->ini = n;
    
    f->fim = n;
    f->tam+=1;
    return true;
}

Dados* removeFila(Fila *f){
    if(f->naoIniciado){
        mostraTela("Fila nao foi iniciada.");
        return false;
    }
    if(filaVazia(f)){
        mostraTela("Fila esta vazia.");
        return false;
    }

    No *lx = f->ini;
    if(f->ini == f->fim){
        f->ini = NULL;
        f->fim = NULL;
    }else{
        f->ini = lx->ant;
    }

    Dados *d = lx->dado;
    free(lx);
    lx = NULL;
    f->tam-=1;
    return d;
}

int esvaziaFila(Fila *f){
    if(f->naoIniciado){
        mostraTela ("Fila nao foi iniciada.");
        return false;
    }
    if(!filaVazia(f)){
        No *lx = f->ini;
        while(lx){  
            free(lx->dado);
            f->ini = lx->ant;
            free(lx);
            lx = f->ini;
        }
    }
    free(f);
    return true;
}

int filaVazia(Fila *f){
    if(f->naoIniciado){
        mostraTela("Fila nao foi iniciada.");
        return false;
    }
    return ((f->ini == NULL) ? true : false);
}

void mostraFila(Fila *f){
    if(f->naoIniciado){
        mostraTela("Fila nao foi iniciada.");
    }
    if(filaVazia(f)){
        mostraTela("Fila esta vazia.");
    }
    No *n = f->ini;
    while(n){
        mostraNo(n);
        n = n->ant;
    }
}



