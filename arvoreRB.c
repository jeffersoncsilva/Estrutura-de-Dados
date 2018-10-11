#include "arvoreRB.h"

int inOrderRB(RBNode *r){
    if(r != NULL){
        
        inOrderRB(r->left);
        printf("[(%d)%d] ",r->cor, r->ch);
        inOrderRB(r->right);
    }
}

void preOrderRB(RBNode *r){
    if(r != NULL){
        printf("[(%d)%d] ",r->cor, r->ch);
        preOrderRB(r->left);
        preOrderRB(r->right);
    }
}

void posOrderRB(RBNode *r){
    if(r!=NULL){
        posOrderRB(r->left);
        posOrderRB(r->left);
        printf("[(%d)%d] ",r->cor, r->ch);
    }
}

RBNode* criaNovoNoRB(int ch){
    RBNode *nv = malloc(sizeof(RBNode));
    nv->left = NULL;
    nv->right = NULL;
    nv->pai = pai;
    nv->ch = ch;
    nv->cor = 1;
    return nv;
}

RBNode* rotacaoDireita(RBNode *r){
    RBNode *fesq = r->left;
    fesq->pai = r->pai;
    r->left = fesq->right;
    r->pai = fesq;
    if(r->left!=NULL)
        r->left->pai = r;
    return fesq;
}
RBNode* rotacaoEsquerda(RBNode *r){
    RBNode *fdir = r->right;
    fdir->pai = r->pai;
    r->pai = fdir;
    r->right = fdir->left;
    fdir->left = r;
    if(r->right != NULL)
        r->right->pai = r;
    return fdir;
}
RBNode* rotacaoEsquerdaDireita(RBNode *r){
    r->right = rotacaoEsquerda(r->right);
    return rotacaoDireita(r);
}
RBNode* rotacaoDireitaEsquerda(RBNode *r){
    r->left = rotacaoDireita(r->left);
    return rotacaoEsquerda(r);
}

void consertaArvoreRB(RBNode *r){
    //caso pai seja nulo, r e raiz.
    if(r->pai != NULL){
        //caso 1.
        RBNode *irmaoR = pegaIrmao(r);
        if(irmaoR->cor == 1){
            r->pai->cor = 1;
            r->cor = 0;
            irmaoR->cor = 0;
        }else if(r->ch < r->pai->ch){
            //o no r e um filho a esquerda.
            if(r->left != NULL){
                if(r->left->cor == 1){
                    r->pai->cor = 1;
                    r->cor = 0;
                    RBNode* avoR = r->pai->pai;
                    if(avoR!=NULL){
                        if(r->pai->ch > avoR->ch)
                            
                    }
                }
            }

        }
    }else
        r->cor = 0;
}

RBNode* insereRB(RBNode *r, int ch){
    if(r==NULL)
        return criaNovoNoRB(ch);
    if(r->ch > ch){
        r->left = insereRB(r->left, ch);
        r->left->pai = r;
        if(r->cor == 1 && r->left->cor == 1)
            consertaArvoreRB(r);
    }
    else {
        r->right = insereRB(r->right, ch);
        r->right->pai = r;
        if(r->cor == 1 && r->right->cor == 1)
            consertaArvoreRB(r);
    }
    return r;
}
