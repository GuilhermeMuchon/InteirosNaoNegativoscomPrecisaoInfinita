#include "INT.h"
#include <stdio.h>
#include <stdlib.h>

/*run this program using the console pauser or add your own getch, system("pause") or input loop */

void mostra_int(void *p){
  printf("%d",*(char*)p); // (int*) -> convertendo a direita da express�o para int, nesse caso, a vari�vel p
}

int comparacao_maior(INT *p, INT *q){
	return compara_INT(p, q);
}

int comparacao_menor(INT *p, INT *q){
	return -(compara_INT(p, q));
}

int main(int argc, char *argv[]) {
	char s[100];
	int i=0;
	LDE listaINT;

	inicializa_lista(&listaINT, sizeof(INT));
	
	while(s != "-1"){
		printf("\nDigite o valor do %d inteiro longo (-1 para continuar): ", i+1);
		scanf("%s", s);
		INT novoInt;
		if(inicializa_INT(&novoInt, s) == 1){
			insereNoFim(&listaINT, &novoInt);	
		}else{
			break;
		}
		
		i++;
	}
	
//	int indiceMenor = maior(listaINT, comparacao_menor);
//	int indiceMaior = maior(listaINT, comparacao_maior);
//	
//	INT maior;
//	leNaPos(&listaINT, &maior, indiceMaior);
//	
//	printf("\n\nMaior numero:");
//	mostra_INT(&maior, mostra_int);
	
//	INT menor;
//	leNaPos(&listaINT, &menor, indiceMenor);
//	printf("\n\nMenor numero:");
//	mostra_INT(&menor, mostra_int);
	
	i = 0;
	ElementoDuplo *aux = listaINT.cabeca;
	INT resultado;
	
	while(aux->suc != NULL){
		
		printf("\n\nSoma do %d com o %d: ", i+1, i+2);
		soma_INT((INT*)aux->info, (INT*)aux->suc->info, &resultado);
		mostra_INT(&resultado, mostra_int);

		printf("\n\nSubtracao do %d com o %d: ", i+1, i+2);
		diminui_INT(aux->info, aux->suc->info, &resultado);
		mostra_INT(&resultado, mostra_int);

		printf("\n\nMultiplicacao do %d com o %d: ", i+1, i+2);
		multiplica_INT(aux->info, aux->suc->info, &resultado);
		mostra_INT(&resultado, mostra_int);

//		 printf("\n\nDivisao do %d com o %d: ", i+1, i+2);
		 printf("\n\nDivisao do %d com o %d e: %d", i+1, i+2, divisao_INT(aux->info, aux->suc->info, &resultado));
		 printf("\nResto: ");
		 mostra_INT(&resultado, mostra_int);

		printf("\n\nComparacao do %d com o %d: ", i+1, i+2);
		int comparacao = compara_INT(aux->info, aux->suc->info);
		printf("%d", comparacao);

		printf("\n");
		i++;
		aux = aux->suc;
}

	//desaloca_INT(&x);
	return 0;
}
