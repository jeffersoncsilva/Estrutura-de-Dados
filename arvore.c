#include "arvore.h"

int iniciaArvore(Arvore *a){
    a->raiz = NULL;
}

void inOrdem(No *n){
    if(n != NULL){
        mostraNo(n);
        inOrdem(n->left);
        inOrdem(n->right);
    }
}

void preOrdem(No *n){
    if(n != NULL){
        preOrdem(n->left);
        mostraNo(n);
        preOrdem(n->right);
    }
}

void posOrdem(No *n){
    if(n != NULL){
        posOrdem(n->left);
        posOrdem(n->right);
        mostraNo(n);
    }
}

int insereArvore(Arvore *a, Dados *d){
    No *novo = malloc(sizeof(No));
    novo->dado = d;
    novo->left = NULL;
    novo->right = NULL;
    novo->prox = NULL;
    novo->ant = NULL;

    if(a->raiz == NULL){
        a->raiz = novo;
        return true;
    }
    No *pai = a->raiz;
    char flag = 1;
    while(flag){
        if(pai->dado->id == d->id){
            printf("Dado ja foi inserido.\n");
            return false;
        }
        if(pai->dado->id > d->id){
            if(pai->left == NULL){
                pai->left = novo;
                flag = 0;
            }else
                pai = pai->left;
        }else{
            if(pai->right == NULL){
                pai->right = novo;
                flag = 0;
            }else
                pai = pai->right;
        }
    }
    return true;
}

Dados* removeNo(Arvore *a, int ch){
    if(a->raiz == NULL){
        printf("Arvore vazia.");
        return NULL;
    }

    

}

