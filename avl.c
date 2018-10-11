#include "avl.h"

/**********************************************Metodos privados da AVL************************/

//Realiza uma rotacao a esquerda.
No* leftRotate(No *n){
    No *nright = n->right;
    n->right = nright->left;
    nright->left = n;
    n->height = max(height(n->left), height(n->right))+1;
    nright->height = max(height(nright->left), height(nright->right))+1;
    return nright;
}
//Realiza uma rotacao a direita.
No* rightRotate(No *n){
    No *nleft = n->left;
    n->left = nleft->right;
    nleft->right = n;
    n->height = max(height(n->left), height(n->right))+1;
    nleft->height = max(height(nleft->left), height(nleft->right))+1;
    return nleft;
}
//Realiza uma rotacao a esquerda no filho a direita, e em seguida uma rotacao a esquerda no no passado.
No* rightLeftRotate(No *n){
    n->right = rightRotate(n->right);
    leftRotate(n);
}
//Realiza uma rotacao a esquerda no filho a esquerda em seguida uma rotacao a direita no no passado.
No* leftRightRotate(No *n){
    n->left = leftRotate(n->left);
    rightRotate(n);
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

No* sucessorNo(No *n){
    while(n->left != NULL)
        n = n->left;
    return n;
}   

int getBal(No *r){
    if(r == NULL)
        return 0;
    else
        return (height(r->left) - height(r->right));
}

No *removerAVL(No *root, int ch, Dados *d){
    if(root == NULL)
        return root;
    if(ch < root->dado->id)
        root->left = removerAVL(root->left, ch, d);
    else if(ch > root->dado->id)
        root->right = removerAVL(root->right, ch, d);
    else{
        d = root->dado;
        if((root->left == NULL) || (root->right == NULL)){
            //pega o filho do no, remove o no na memoria e faz o filho virar
            //a nova raiz.
            No *filho = ((root->left!=NULL) ? root->left : root->right);
            free(root);
            root  = filho;
        }else{
            No *suc = sucessorNo(root->right);
            root->dado = suc->dado;
            Dados aux;
            root->right = removerAVL(root->right, suc->dado->id, &aux);
        }
    }
    if(root == NULL)
        return root;
    root->height = max(height(root->left), height(root->right))+1;
    int bal = getBal(root);
    if(bal > 1 && getBal(root->left) >= 0)
        return rightRotate(root);
    if(bal > 1 && getBal(root->left) < 0)
        return leftRightRotate(root);
    if(bal < -1 && getBal(root->right) <= 0)
        return rightRotate(root);
    if(bal < -1 && getBal(root->right) > 0)
        return rightLeftRotate(root);
    return root;
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

Dados* removeAvl(AvlTree *avl, int ch){
    Dados *d;
    avl->root = removerAVL(avl->root, ch, d);
    if(d==NULL){
        printf("a chave nao esta na arvore.");
        return NULL;
    }else
        return d;
}


