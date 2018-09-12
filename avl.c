#include "avl.h"

//Realiza uma rotacao a esquerda.
No* leftRotate(No *n){
    if(n!=NULL){
        No *aux = n->right;
        n->right = aux->left;
        aux->left = n;
        return aux;
    }else{
        printf("ERRO: No null passado.");
        return n;
    }
}

//Realiza uma rotacao a direita.
No* rightRotate(No *n){
    if(n != NULL){
        No *aux = n->left;
        n->left = aux->right;
        aux->right = n;
        return aux;
    }else{
        printf("ERRO: No null passado.");
        return n;
    }
}
//Realiza uma rotacao a esquerda no filho a direita, e em seguida uma rotacao a esquerda no no passado.
No* rightLeftRotate(No *n){
    if(n != NULL){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }else{
        printf("ERRO na rotacao esquerda direita.");
        return NULL;
    }
}
//Realiza uma rotacao a esquerda no filho a esquerda em seguida uma rotacao a direita no no passado.
No* leftRightRotate(No *n){
    if(n != NULL){  
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }else{
        printf("ERRO na rotacao direita esquerda.");
        return NULL;
    }
}

//Insere um valor na AVL.
No* insertAvl(No *r, No *nv){
    if(r == NULL){
       return nv; 
    }
    if(nv->dado->id < r->dado->id){

        r->left = insertAvl(r->left, nv);
        if((height(r->left) - height(r->right)) == 2){
            if(nv->dado->id < r->dado->id){
                r = rightRotate(r);
            }else{
                r = leftRightRotate(r);
            }
        }
    }else{
        r->right = insertAvl(r->right, nv);
        if((height(r->right) - height(r->left)) == 2){
            if(nv->dado->id > r->dado->id){
                r = leftRotate(r);
            }else{
                r = rightLeftRotate(r);
            }
        }
    }
    r->height = max(height(r->left), height(r->right)) + 1;
    return r;
}

/***************************Metodos publicos - sao vistos pelo programa principal**************************/
//Inicia a arovre.
void iniciaArvoreAvl(AvlTree *a){
    a->root = NULL;
}

//Retorna a altura armazenada no.
int height(No *n){
    return (n != NULL ? n->height : 0);
}

int insertAvlAux(AvlTree *a, Dados *d){
    if(a != NULL){
        No *nv = criaNo(d);
        a->root = insertAvl(a->root, nv);
    }else{
        printf("ERRO: insertAvlAux(AvlTree *a, Dados *d);");
        return -1;
    }
}

