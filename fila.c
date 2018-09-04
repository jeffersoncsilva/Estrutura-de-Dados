#include "fila.h"

int iniciaFila(Fila *f){
    if(f->naoIniciado){
        f->ini = NULL;
        f->fim = NULL;
        f->tam = 0;
        f->naoIniciado = false;
        return true;
    }else{
        
        mostraTela(fl_ja_iniciada);
        return false;
    }
}

int insereFila(Fila *f, Dados *d){
    if(f->naoIniciado){
        mostraTela(fl_nao_inicida);
        return false;
    }

    No *n = malloc(sizeof(No));
    n->dado = d;
    n->ant = f->fim;
    f->fim = n;
    if(filaVazia(f)){
        f->ini = n;
    }

    f->tam+=1;
    return true;
}

Dados* removeFila(Fila *f){
    if(f->naoIniciado){
        mostraTela(fl_nao_inicida);
        return false;
    }
    if(filaVazia(f)){
        mostraTela(fl_vazia);
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
        mostraTela (fl_nao_inicida);
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
        mostraTela(fl_nao_inicida);
        return false;
    }
    return ((f->ini == NULL) ? true : false);
}

void mostraFila(Fila *f){
    if(f->naoIniciado){
        mostraTela(fl_nao_inicida);
    }
    if(filaVazia(f)){
        mostraTela(fl_vazia);
    }
    No *n = f->ini;
    while(n){
        mostraNo(n);
        n = n->ant;
    }
}



