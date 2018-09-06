#include "base.h"


void mostraDados(Dados *d){
	if(d!=NULL){
		printf("ID: %d ", d->id);
		printf("Nome: %s\n", d->nome);
		printf("Tel: %s\n", d->telefone);
		printf("E-mail: %s\n", d->email);
		printf("Endereco: %s\n", d->endereco);
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

