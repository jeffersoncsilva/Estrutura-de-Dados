#include "base.h"


void mostraDados(Dados *d){
	if(d!=NULL){
		printf("ID: %d ", d->id);
		/*printf("Nome: %s\n", d->nome);
		printf("Tel: %s\n", d->telefone);
		printf("E-mail: %s\n", d->email);
		printf("Endereco: %s\n", d->endereco);*/
	}else{
		printf("ERRO: DADOS INVALIDOS.\n");
	}
}

void mostraNo(No *n){
	if(n==NULL){
		printf("ERRO: No vazio passado.");
	}else{
		mostraDados(n->dado);
	}
}

FILE *carregaArquivo(){
	FILE *arq = fopen(URL, "r");
	if(arq==NULL){
		printf("ERRO: Impossivel ler arquivo.");
		return NULL;
	}else
		return arq;
}

/*Recebe uma linha do arquivo de teste lido.*/
Dados* converteDados(char *linha){
	Dados *d = malloc(sizeof(Dados));
	char *token;
	//pega o id.
	token = strtok(linha, "|");
	d->id = atoi(token);

	//pega o nome da linha.
	token = strtok(NULL,"|");
	strcpy(d->nome, token);

	//pega o email.
	token = strtok(NULL, "|");
	strcpy(d->email, token);

	//pega o telefone.
	token = strtok(NULL, "|");
	strcpy(d->telefone, token);

	//pega o endereco.
	token = strtok(NULL, "|");
	strcpy(d->endereco, token);

	return d;
}

void mostraTela(char msg[]){
	printf("%s/n", msg);
}

//Cria um novo no com os dados passados e com todos os ponteiros para NULL.
No *criaNo(Dados *d){
	No *n = malloc(sizeof(No));
	n->height = 0;
	n->dado = d;
	n->ant = NULL;
	n->prox = NULL;
	n->left = NULL;
	n->right = NULL;
	return n;
}

//Copia d1 para d2.
void copyData(Dados *d1, Dados *d2){
	strcpy(d2->nome, d1->nome);
	strcpy(d2->email, d1->email);
	strcpy(d2->telefone, d1->telefone);
	strcpy(d2->endereco, d1->telefone);
	d2->id = d1->id;

}

//retorna o maior inteiro.
int max(int a, int b){
	return (a > b ? a : b);
}

//Mostra a arvore em ordem na forma ERD.
void inOrdem(No *n){
    if(n != NULL){
        inOrdem(n->left);
        mostraNo(n);
        inOrdem(n->right);
    }
}

//Mostra a arvore em pre-ordem na forma RED.
void preOrdem(No *n){
    if(n != NULL){
        mostraNo(n);
        preOrdem(n->left);
        preOrdem(n->right);
    }
}

//Mostra a arvore no percursso pos-ordem na forma EDR
void posOrdem(No *n){
    if(n != NULL){
        posOrdem(n->left);
        posOrdem(n->right);
        mostraNo(n);
    }
}