#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Biblioteca nescessaria para utilização do setlocale.
#include <locale.h> 
//Constantes para indicar o tipo de nó e o lado q pertence.
#define E 0
#define D 1
#define R -1

//Determina o tipo de Nó.
typedef struct NO {
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;

//Tipo árvore
typedef struct Arvore{
	NO *raiz;
}Arvore;

//Declarando a arvore como uma variável.
Arvore a;

//Prototipação das funções.
void inicializaArvore(Arvore arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);


//Função que sempre deve ser chamada ao se criar uma nova árvore
void inicializaArvore(Arvore arv)
{
	arv.raiz = NULL;
}

//Função utilizada para inicializar um novo nó na árvore
void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Alocação não realizada.\n\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}

//Função para inserção de novo nó.
void insereNoArvoreOrdenada(int valor)
{
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));//"reserva" local na memoria.
	inicializaNo(novoNo, valor);
	printf(" - Inserindo nó %d.\n", novoNo->dado);
	
	if(corrente == NULL)
	{
		a.raiz = novoNo;
		printf(" Nó inserido na raiz.\n\n");
		return;
	}
	//Cógigo que define o lado que o novo Nó será inserido 
	//Se o novo Nó for menorque o Pai ele vai para a esquerda e se for menor ou igual vai para a direita.
	while(corrente){
		pai = corrente;
		if(novoNo->dado < corrente->dado){
			corrente = corrente->esq;
			if(!corrente){
				printf(" Nó inserido à esquerda do nó %d.\n\n", pai->dado);
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				printf(" Nó inserido à direita do nó %d.\n\n", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}

//Função para mostrar a ordenação Pré_ordem.
//visita Nó raiz,visita sub-árvore a esquerda, visita sub-árvore a direita. 
void preOrdem(NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}
//Código principal.
int main(int argc, char *argv[]){
	
	setlocale(LC_ALL, "Portuguese");
	
	inicializaArvore(a);
	//inserção dos valores referente ao RA:21072066.
	insereNoArvoreOrdenada(20);
	insereNoArvoreOrdenada(3);
	insereNoArvoreOrdenada(21);
	insereNoArvoreOrdenada(1);
	insereNoArvoreOrdenada(8);
	insereNoArvoreOrdenada(31);
	insereNoArvoreOrdenada(0);
	insereNoArvoreOrdenada(7);
	insereNoArvoreOrdenada(30);
	insereNoArvoreOrdenada(40);
	//Ipressão dos valores em Pré-ordem.
	printf("\nBusca por pré-ordem: \n");
	preOrdem(a.raiz);	
}
