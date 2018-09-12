#include "base.h"

typedef struct tree{
    No *root;
}AvlTree;

void iniciaArvoreAvl(AvlTree *a);

//Realiza uma rotacao a esquerda.
No* leftRotate(No *n);
//Realiza uma rotacao a direita.
No* rightRotate(No *n);

No* insertAvl(No *r, No *nv);

int insertAvlAux(AvlTree *a, Dados *d);
