#include "INT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> //memcopy

int inicializa_INT (INT *p, char *s){
	if(valida(s)){
		inicializa_lista(&(p->l),sizeof(char));
		printf("Passou\n");
		int i;
		for(i = 0; s[i] != '\0'; i++){
			printf("Passou 2\n");
			char n = converte(s[i]);
			insereNoFim(&(p->l),&n);
		}
		return 1; //sucesso
	}else{
		printf("\n!!Valor Invalido!!\n");
		return INT_INVALIDO;
	}
}

char converte(char x){
	return x - 48;
}

int valida(char *x){
	int i;
	for(i = 0; x[i] != '\0'; i++){
		if(converte(x[i]) > 9 || converte(x[i]) < 0){
			return 0;
		}
	}
	return 1;
}

void desaloca_INT(INT *p){
	//printf("Entrou!");
    void *aux = malloc(p->l.tamInfo);
    while(!lista_vazia(p->l)){
    	printf("Entrou 1 !");
        removeDoInicio(&(p->l),&aux);
    	printf("Entrou 2 !");
	}
    printf("Saiu!");
    free(aux);
}

void mostra_INT(INT *p, void (*mostra)(void*)){
  if(lista_vazia(p->l)){
    printf("INT vazio!\n");
  }else{
    printf("Dados da lista:\n");
    ElementoDuplo *aux = p->l.cabeca;
    while(aux != NULL){
      mostra(aux->info);
      aux = aux->suc;
    }
  }
}
