#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int ch;
    char cor;
    struct node* left;
    struct node* right;
    struct node* pai;
}RBNode;

typedef struct avRb{
    RBNode *raiz;
}RBTree;

int insertRBTree(RBTree *rbt, int ch);

void inOrderRB(RBNode *r);

void preOrderRB(RBNode *r);

void posOrderRB(RBNode *r);