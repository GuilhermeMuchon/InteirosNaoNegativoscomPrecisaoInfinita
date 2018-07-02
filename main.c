#include "INT.h"
#include <stdio.h>
#include <stdlib.h>

/*run this program using the console pauser or add your own getch, system("pause") or input loop */

void mostra_int(void *p){
  printf("%d",*(char*)p); // (int*) -> convertendo a direita da expressão para int, nesse caso, a variável p
}

void main(int argc, char *argv[]) {
	INT x, novo, resultadoSoma, resultadoMulti;
	char s[100], novo_S[100];
	
	printf("Digite o valor a ser inicializado: ");
	scanf("%s", s);
	
	inicializa_INT(&x, &s);
	mostra_INT(&x, mostra_int);
	
	printf("\nDigite o valor a ser atribuido: ");
	scanf("%s", novo_S);
	inicializa_INT(&novo, &novo_S);
	
	printf("\nSoma:\n");
	resultadoSoma = soma_INT(&x, &novo);
	mostra_INT(&resultadoSoma, mostra_int);
	
	printf("\nMulti:\n");
	resultadoMulti = multiplica_INT(&x, 6);
	mostra_INT(&resultadoMulti, mostra_int);
	
	desaloca_INT(&x);
}
