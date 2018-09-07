#include "arvore.h"
#include "fila.h"

int iniciaArvore(Arvore *a){
    a->raiz = NULL;
}

void inOrdem(No *n){
    if(n != NULL){
        inOrdem(n->left);
        mostraNo(n);
        inOrdem(n->right);
    }
}

void preOrdem(No *n){
    if(n != NULL){
        mostraNo(n);
        preOrdem(n->left);
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

    No *pai = a->raiz;
    No *lixo = NULL;
    char flag = 1;
    while(flag){
        if(pai->left){
            if(pai->left->dado->id == ch){
                lixo = pai->left;
                flag = 0;
                break;
            }
        }
        if(pai->right){
            if(pai->right->dado->id == ch){
                lixo = pai->right;
                flag=0;
                break;
            }
        }
        if(pai->dado->id > ch)
            pai = pai->left;
        else
            pai = pai->right;
    }
    if(lixo){
        No *sub = NULL;
        /*Busca o no substituto*/
        if(lixo->left){
            sub = lixo->left;
            while(sub->right){
                sub = sub->right;
            }
        }else if(lixo->right){
            sub = lixo->right;
            while(sub->left)
                sub = sub->left;
        }
        if(sub){
            /*Significa que tem no substituo.*/
            if(pai->dado->id > ch)
                pai->left = sub;
            else
                pai->right = sub;
            sub->right = lixo->right;
        }
        Dados *d = lixo->dado;
        free(lixo);
        lixo = NULL;
        return d;
    }else{
        printf("Chave nao foi encontrada.");
        return NULL;
    }
}


