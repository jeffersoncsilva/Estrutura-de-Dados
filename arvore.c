#include "arvore.h"
#include "fila.h"

//Inicia a arvore.
int iniciaArvore(Arvore *a){
    a->raiz = NULL;
}

//Insere um dado na arvore usando laco de repetissao.
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

//Remove um no da arvore usando laco de repeticao.
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

//Cada nivel da arvore em uma linha.
void imprimeLargura(Arvore *a){
    Fila nv_atual, nv_seguinte;
    initialize(&nv_atual);
    initialize(&nv_seguinte);

    enqueueNode(&nv_atual, a->raiz);

    while(!empty(&nv_atual)){
        No *no_atual = dequeueNode(&nv_atual);
        if(no_atual){
            mostraNo(no_atual);
            if(no_atual->left != NULL)
                enqueueNode(&nv_seguinte, no_atual->left);
            if(no_atual->right != NULL)
                enqueueNode(&nv_seguinte, no_atual->right);
        }
        if(empty(&nv_atual)){
            printf("\n");
            swap(&nv_atual, &nv_seguinte);
        }
    }
}

//Retorna a altura de um no.
int heightNode(No *n){
    if(n== NULL)
        return -1;

    return (max(heightNode(n->left), heightNode(n->right)) + 1);    
}

//Retorna a altura da arvore.
int getHeightTree(Arvore *a){
    if(a == NULL){
        mostraTela("Arvore vazia.");
        return -1;
    }
    return heightNode(a->raiz);
}

int countNodes(No *n){
    if(n == NULL)
        return 0;
    return (countNodes(n->left) + 1 + countNodes(n->right));
}

//Conta a quantidade de nos na arvore.
int countTree(Arvore *a){
    if(a == NULL){
        mostraTela("Arvore invalida.");
        return -1;
    }
    return countNodes(a->raiz);
}

//Busca o  novo lugar do no e adiciona ele como filho de outro.s
No *insertNode(No *r, No *nv){
    if(r == NULL)
        return nv;
    if(r->dado->id > nv->dado->id)
        r->left = insertNode(r->left, nv);
    else
        r->right = insertNode(r->right, nv);
}

//Insere um novo no na arvore de forma de forma recursiva.
int insertBtree(Arvore *a, Dados *d){
    if(a == NULL){
        mostraTela("Arvore invalida.");
        return false;
    }
    No *novo = criaNo(d);
    a->raiz = insertNode(a->raiz, novo);
    return true;
}

