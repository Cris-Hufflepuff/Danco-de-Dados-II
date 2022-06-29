/* Curso SUPERIOR DE TECNOLOGIA EM ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
   Disciplina Estrutura de Banco de Dados
   Professor Pietro Martins
   Academico Cristine Siqueira Dias
   RA: 21072066-5  */

#include <stdio.h>
#include <stdlib.h>
//necessário para usar setlocale
#include <locale.h> 
//constante que define o tamaho max estrutura
#define tamanho 5

// Declaração de pilha.
typedef struct tipo_pilha{
	int dados[tamanho];
	int ini;
	int topo;
}tipo_pilha;
//criando uma variavel tipo_pilha para receber o primeiro empilhamento.
tipo_pilha pilha;
//Declaração da nova pilha.
typedef struct tipo_repilha{
	int dados[tamanho];
	int ini;
	int topo;
}tipo_repilha;
//criando uma variavel tipo_repilha para receber o segundo empilhamento.
tipo_repilha repilha;

//Procedimento que empilha um novo elemento no topo.
void empilha (int elemento){
	// verifica se existe aiguma posição para uma inserção.
	if(pilha.topo==tamanho){
		//se pilha estiver cheia, não é possivel empilhar.
		printf("Pilha cheia!\n");
		system("pause");
	}
	else{
		/*se a pilha não estiver cheia:
		-add novo elemento no topo
		-incrementa o topo*/
		pilha.dados[pilha.topo]=elemento;
		pilha.topo++;
	}
}
//Função desempilha e rotorna elemento topo retirado.
int desempilha(){
	//variavel que guarda um backup elemento desempilhado.
	int elemento;
	//verifica se existe algum elemento disponivel para remoção
	if(pilha.topo==pilha.ini){
		printf("Pilha vazia!\n");
		system("pause");
	}
	else{
		/*se a pilha não estiver vazia:
		-decrementa o topo
		-retorna o elemento que esta no topo*/
		pilha.topo--;
		elemento=pilha.dados[pilha.topo];
		return elemento;
	}
}

//Procedimento para fazer a nova pilha.
void novaPilha (int elemento){
	// verifica se existe aiguma posição para uma inserção.
	if(repilha.topo==tamanho){
		//se pilha estiver cheia, não é possivel empilhar.
		printf("Pilha cheia!\n");
		system("pause");
	}
	else{
		/*se a pilha não estiver cheia:
		-add novo elemento no topo
		-incrementa o topo*/
		repilha.dados[repilha.topo]=elemento;
		repilha.topo++;
	}
}
//Procedimento que mostra a cor do prado de acordo com o número.
void corPratos(int valor){
	if(valor == 1){
		printf("\t\tVermelho(1)\n");
	}else
	if(valor == 2){
		printf("\t\tVerde(2)\n");
	}
	else
	if(valor == 3){
		printf("\t\tAzul(3)\n");
	}else
	if(valor == 4){
		printf("\t\tBranco(4)\n");
	}else
	if(valor == 5){
		printf("\t\tLaranja(5)\n");
	}else{
		printf("\t\tErro!\n");
	}
}
//Procedimento para incluir um cabeçalho.
void cabecalho(){
	printf("\n--------------------------------------------\n");
	printf("\tOrdenação de pilha em entrada saida e \n\tinsersão em uma nova pilha.\n");
	printf("---------------------------------------------\n");
}
// implementação do código.	
int main(int argc, char *argv[]) {
	//configurar o idioma português.
	setlocale(LC_ALL, "Portuguese");	
	// Variaveis.
	pilha.ini=0;
	pilha.topo=0;
	//Variável para o laço "For".
	int i;
	
	cabecalho();
	
	printf("\n\t\t#Empilhamento!\n\n");
	//implementação do empilhamento.	
	for(i=1;i<=tamanho;i++){
		empilha(i);
		corPratos(i);
	}
	
	printf("\n\t\t#Desempilhamento!\n\n");
	
	// implementação do desempilhamento.
	for(i=tamanho;i>=1;i--){
		desempilha(i);
		corPratos(i);
	}
	
	printf("\n\t\t#Reempilhamento!\n\n");
	// implementação do desempilhamento.
	for(i=tamanho; i>=1; i--){
		novaPilha(i);
		corPratos(i);
	}
	
	system("pause");
	return 0;
}
