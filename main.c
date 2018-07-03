#include <stdio.h>
#include <stdlib.h>
#include "INT.h"

/*run this program using the console pauser or add your own getch, system("pause") or input loop */

void mostra_int(void *p){
  printf("%d",*(char*)p); // (int*) -> convertendo a direita da express�o para int, nesse caso, a vari�vel p
}

void main(int argc, char *argv[]) {
	INT x, novo, resultado;
	char s[100], novo_S[100];

	printf("Digite o valor a ser inicializado: ");
	scanf("%s", s);

	inicializa_INT(&x, &(*s));
	mostra_INT(&x, mostra_int);

	printf("\nDigite o valor a ser atribuido: ");
	scanf("%s", novo_S);

	inicializa_INT(&novo, &(*novo_S));
	atribui_INT(&x, novo);
	mostra_INT(&x, mostra_int);
//	resultado = soma_INT(&x, &novo);
//	mostra_INT(&resultado, mostra_int);

	desaloca_INT(&x);
}
