#include "fila.h"

//Inicia a fila.
int initialize(Fila *f){
    f->fim = NULL;
    f->ini = NULL;
    f->tam = 0;
    f->naoIniciado = false;
}

//Conta todos os elementos da fila.
int count(Fila *f){
    int i = 0;
    No *p = f->ini;
    while(p){
        i++;
        p = p->prox;
    }
    return i;
}

//Limpa toda a fila.
int clearFila(Fila *f){
    while(f->ini != NULL){
        free(dequeue(f));
    }
    f->ini = NULL;
    f->fim = NULL;
    f->tam = 0;
    return true;
}

//Cria uma nova fila e retorna o endereco dela.
Fila* clone (Fila *f){
    Fila *nvf = malloc(sizeof(Fila));
    initialize(nvf);
    No *nav = f->ini;
    while(nav){
        Dados *nd = malloc(sizeof(Dados));
        copyData(nav->dado, nd);
        enqueue(nvf, nd);
        nav = nav->prox;
    }
    return f;
}

//Troca a fila um e a fila 2.
int swap(Fila *f1, Fila *f2){
    if(f1 == NULL || f2 == NULL){
        printf("ERRO: Impossivel trocar as filas.");
        return false;
    }
    int tamf1 = f1->tam;
    No *ini = f1->ini;
    No *fim = f1->fim;
    f1->ini = f2->ini;
    f1->fim = f2->fim;
    f1->tam = f2->tam;
    f2->ini = ini;
    f2->fim = fim;
    f2->tam = tamf1;
    return true;
}

//Verifica se o objeto esta ou nao na fila.
int contains(Fila *f, No *n){
    if(f == NULL || empty(f)){
        printf("ERRO: fila esta vazia.");
        return false;
    }
    if(n==NULL){
        mostraTela("Objeto NULLL passado.");
        return false;
    }
    No *nv = f->ini;
    while(nv){
        if(nv->dado->id == n->dado->id)
            return true;
        nv = nv->prox;
    }
    return false;
}

//Desempilha e retorna o primeiro objeto da fila.
Dados* dequeue(Fila *f){
    if(empty(f)){
        mostraTela("Fila vazia.");
        return NULL;
    }
    No *lx = f->ini;
    Dados *d = lx->dado;
    if(equals(f->ini, f->fim)){
        f->fim = NULL;
    }
    f->ini = lx->prox;
    f->tam--;
    free(lx);
    lx = NULL;
    return d;
}

//Coloca um objeto na fila.
int enqueue(Fila *f, Dados *d){
    No *nv = criaNo(d);
    if(f->fim != NULL){
        f->fim->prox = nv;
    }else
        f->ini = nv;
    
    f->fim = nv;
    f->tam++;
    return true;
}

//Empilha um no.
int enqueueNode(Fila *f, No *n){
    No *nv = malloc(sizeof(No));
    nv->dado = n->dado;
    nv->left = n->left;
    nv->right = n->right;
    nv->ant = n->ant;
    nv->prox = n->prox;

    if(f->fim != NULL){
        f->fim->prox = nv;
    }else
        f->ini = nv;
    
    f->fim = nv;
    f->tam++;
    return true;

}

//Desenpilha um no.
No *dequeueNode(Fila *f){
    No *lx = f->ini;
    if(equals(f->ini, f->fim))
        f->fim = NULL;
    f->ini = lx->prox;
    f->tam--;
    return lx;
}

//Retorna o topo da fila.
Dados* peek(Fila *f){
    if(empty(f)){
        mostraTela("Fila vazia.");
        return NULL;
    }
    return f->ini->dado;
}

//Retorna se a fila esta vazia ou nao.
int empty(Fila *f){
    return ((f->tam == 0) ? true : false);
}


//retorna se dois nos sao iguais comparando o id de ambos.
int equals(No *n1, No *n2){
    return ((n1->dado->id == n2->dado->id) ? true : false);
}

//Mostra a fila.
void show(Fila *f){
    if(empty(f)){
        mostraTela("Fila vazia.");
    }else{
        No *n = f->ini;
        while(n){
            mostraNo(n);
            n = n->prox;
        }
    }
}
