#include "INT.h"
#include <stdio.h>
#include <stdlib.h>

/*run this program using the console pauser or add your own getch, system("pause") or input loop */

void mostra_int(void *p){
  printf("%d",*(char*)p); // (int*) -> convertendo a direita da expressão para int, nesse caso, a variável p
}

compara(void *a, void *b){
    char *x=(char*)a, *y=(char*)b;
    if(*x > *y){
        return 1; // A>B
    }
    if(*x < *y){
        return -1; // A<B
    }
    return 0; // A==B
}

void main(int argc, char *argv[]) {
	char s[100];
	int resp, i;
	
	printf("\nDigite quantos Inteiros longos voce deseja inicializar: ");
	scanf("%d", &resp);
	
	INT x[resp], resultado;
	
	for(i = 0; i < resp; i++){
		printf("\nDigite o valor do %d inteiro longo: ", i+1);
		scanf("%s", s);
		inicializa_INT(&x[i], s);
	}
	
	for(i = 0; i < resp-1; i++){
		printf("\n\nSoma do %d com o %d: ", i+1, i+2);
		soma_INT(&x[i], &x[i+1], &resultado);
		mostra_INT(&resultado, mostra_int);
		
		printf("\n\nSubtracao do %d com o %d: ", i+1, i+2);
		diminui_INT(&x[i], &x[i+1], &resultado);
		mostra_INT(&resultado, mostra_int);
		
		printf("\n\nMultiplicacao do %d com o %d: ", i+1, i+2);
		multiplica_INT(&x[i], &x[i+1], &resultado);
		mostra_INT(&resultado, mostra_int);
	}
	
	desaloca_INT(&x);
}
