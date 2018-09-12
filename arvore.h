#include "base.h"

typedef struct arv{
    No *raiz;
}Arvore;

//Inicia a arvore.
int iniciaArvore(Arvore *a);

//Insere um dado na arvore usando laco de repetissao.
int insereArvore(Arvore *a, Dados *d);

//Remove um no da arvore usando laco de repeticao.
Dados* removeNo(Arvore *a, int ch);

//Retorna a altura da arvore.
int getHeightTree(Arvore *a);

//Conta a quantidade de nos na arvore.
int countTree(Arvore *a);

//Cada nivel da arvore em uma linha.
void imprimeLargura(Arvore *a);

//Insere um novo no na arvore de forma de forma recursiva.
int insertBtree(Arvore *a, Dados *d);