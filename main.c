#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void mostra_float(void *p){
  printf("%.1f\n",*(float*)p); // (float*) -> convertendo a direita da expressão para float, nesse caso, a variável p
}


void main(int argc, char *argv[]) {
	int x;
	char s[10];
	scanf("%s",s);
	inicializa_INT(&x,&s);
//	mostra_INT(x, mostra_float);
	desaloca_INT(&x);
//	mostra_INT(x);
//	desaloca_INT(&x);
}
