#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "estrutura.h"
#include "pilha.h"


struct torre{
	int qtdDiscos;
	Pilha * p1;
	Pilha * p2;
	Pilha * p3;
	Pilha * pOrigem;
	Pilha * pDestino;
};

Torre * criarTorre(int discos){
	Torre * t = malloc(sizeof(Torre));
	t->p1 = criar();
	t->p2 = criar();
	t->p3 = criar();
	t->qtdDiscos = discos;
	
	return t;
}

void iniciarJogo(){
	int discos;
	char discosChar[6];
	Torre * t;
	
	fflush(stdin);
	printf("Digite a quantidade de discos: ");
	gets(discosChar);
	
	discos = atoi(discosChar);
	
	if(discos > 0){
		t = criarTorre(discos);
		
		inicializarPinos(t);
		
		escolherPinos(t);
	}else{
		system("cls");
		iniciarJogo();
	}
}

void inicializarPinos(Torre * t){
	int i;
	
	for(i = t->qtdDiscos; i >= 1; i--)
		empilhar(t->p1, i);
}

void escolherPinos(Torre * t){
	int origem = 0 , destino = 0;
	char pino[1];
	
	system("cls");
	printf("Pino 1: ");
	imprimir(t->p1);
	printf("Pino 2: ");
	imprimir(t->p2);
	printf("Pino 3: ");
	imprimir(t->p3);
	
	ajuda(t);
	
	fflush(stdin);
	printf("\n\n\nEscolha o pino que deseja mover: ");
	gets(pino);
	
	origem = atoi(pino);
	
	if(origem > 0){
		fflush(stdin);
		printf("Escolha o pino para qual deseja mover: ");
		gets(pino);
	
		destino = atoi(pino);
		if(destino > 0){
			
			if(origem == 1){
				t->pOrigem = t->p1;
			}else{
				if(origem == 2){	
					t->pOrigem = t->p2;
				}
				else{
					if(origem == 3){
						t->pOrigem = t->p3;
					}
					else{
						system("cls");
						printf("Pino inválido!\n\n");
						system("pause");
						escolherPinos(t);
					}
				}
			}
			
			if(destino == 1)
				t->pDestino = t->p1;
			else{
				if(destino == 2){
					t->pDestino = t->p2;
				}
				else{
					if(destino == 3){
						t->pDestino = t->p3;
					}
					else{
						system("cls");
						printf("Pino inválidos!\n\n");
						system("pause");
						escolherPinos(t);
					}
				}
			}
			movimentoPinos(t);
		}else{
			system("cls");
			printf("Pino inválido!\n\n");
			system("pause");
			escolherPinos(t);
		}
	}else{
		system("cls");
		printf("Pino inválido!\n\n");
		system("pause");
		escolherPinos(t);
	}
}

void movimentoPinos(Torre * t){
	
	if(topo(t->pOrigem) == -1){
		system("cls");
		printf("Movimento Invalido\n");
		system("pause");
		escolherPinos(t);
	}
	else{	
		if(topo(t->pDestino) == -1){
			empilhar(t->pDestino, desempilhar(t->pOrigem));
			verificarTermino(t);
			escolherPinos(t);	
		}else{
			if(topo(t->pOrigem) < topo(t->pDestino)){
				empilhar(t->pDestino, desempilhar(t->pOrigem));
				verificarTermino(t);
				escolherPinos(t);	
			}
			else{
				system("cls");
				printf("Movimento Invalido\n");
				system("pause");
				escolherPinos(t);
			}
		}
	}	
}

void verificarTermino(Torre * t){
	if(tamanho(t->p3) == t->qtdDiscos){
		system("cls");
		printf("Parabens, você terminou o Desafio!\n\n\n");
		system("pause");
		while(tamanho(t->p3)){
			empilhar(t->p2, desempilhar(t->p3));
		}
		while(tamanho(t->p2)){
			empilhar(t->p1,desempilhar(t->p2));
		}
		escolherPinos(t);
	}
	
}

void ajuda(Torre * t){
	printf("Possiveis Jogadas\n");
	//teste nao nulo origem
	if(topo (t->p1) != -1){
		if(topo(t->p1) < topo(t->p2)){
			printf("\nPino 1 para Pino 2");
		}
		if(topo (t->p1) < topo(t->p3)){
			printf("\nPino 1 para Pino 3");
		}
	}
	if(topo (t->p2) != -1){
		if(topo(t->p2) < topo(t->p1)){
			printf("\nPino 2 para Pino 1");
		}
		if(topo (t->p2) < topo(t->p3)){
			printf("\nPino 3 para Pino 1");
		}
	}
	if(topo (t->p3) != -1){
		if(topo(t->p3) < topo(t->p1)){
			printf("\nPino 3 para Pino 1");
		}
		if(topo (t->p3) < topo(t->p2)){
			printf("\nPino 3 para Pino 2");
		}
	}
	//teste nao nulo destino
	if(topo (t->p1) == -1){
		if(topo(t->p2) != -1)
			printf("\nPino 2 para Pino 1");
		if(topo(t->p3) != -1)
			printf("\nPino 3 para Pino 1");
	}
	if(topo (t->p2) == -1){
		if(topo(t->p1) != -1)
			printf("\nPino 1 para Pino 2");
		if(topo(t->p3) != -1)
			printf("\nPino 3 para Pino 2");
	}
	if(topo (t->p3) == -1){
		if(topo(t->p1) != -1)
			printf("\nPino 1 para Pino 3");
		if(topo(t->p2) != -1)
			printf("\nPino 2 para Pino 3");
	}
}


