#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"
#include "estrutura.h"

// Colocar regras para que um disco não fique em cima de um menor.

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	//Inicialização 
	iniciarJogo();
	system("pause");
	return 0;
}

