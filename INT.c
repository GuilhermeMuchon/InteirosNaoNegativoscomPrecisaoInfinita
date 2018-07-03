#include "INT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> //memcopy

int valida(char *x) {
	int i;
    for (i = 0; x[i] != '\0'; i++) {
        if (converte(x[i]) > 9 || converte(x[i]) < 0) {
            return 0;
        }
    }
    return 1;
}

void removeZeros(INT *p){
	char info = 0;
	while(leNaPos(&(p->l),&info, 0) == 1 && info == 0){
		removeDoInicio(&(p->l), &info);
	}
}

int inicializa_INT(INT *inteiroLongo, char *s) {
    if (valida(s)) {
        inicializa_lista(&(inteiroLongo -> l), sizeof(char));
        int i;
        for (i = 0; s[i] != '\0'; i++) {
            char n = converte(s[i]);
            insereNoFim(&(inteiroLongo -> l), &n);
        }
        removeZeros(inteiroLongo);
        return 1; //sucesso
    } else {
        printf("\n!!Valor Invalido!!\n");
        return INT_INVALIDO;
    }
}

char converte(char x) {
    return x - '0';
}

void desaloca_INT(INT *inteiroLongo) {
    void *aux = malloc(inteiroLongo -> l.tamInfo);
    while (!lista_vazia(inteiroLongo -> l)) {
        removeDoInicio(&(inteiroLongo -> l), &aux);
    }
    free(aux);
}

void mostra_INT(INT *inteiroLongo, void(*mostra)(void *)) {
    if (lista_vazia(inteiroLongo -> l)) {
        printf("INT vazio!\n");
    } else {
        printf("Dados da lista:\n");
        ElementoDuplo *aux = inteiroLongo -> l.cabeca;
        while (aux != NULL) {
            mostra(aux -> info);
            aux = aux -> suc;
        }
    }
}

void atribui_INT(INT *inteiroLongo, INT aux) {
	int variavel_qualquer;
	while(!lista_vazia(inteiroLongo -> l)){
		removeDoFim(&(inteiroLongo -> l), &variavel_qualquer);
	}
	while(aux.l.cabeca != NULL){
		insereNoFim(&(inteiroLongo -> l), aux.l.cabeca->info);
		aux.l.cabeca = aux.l.cabeca->suc;
	}
}

INT soma_INT(INT *p, INT *q){
	LDE resultado;
	inicializa_lista(&resultado, sizeof(char));

	ElementoDuplo *aux1 = p->l.cabeca;
	ElementoDuplo *aux2 = q->l.cabeca;

	while(aux1->suc != NULL){
		aux1 = aux1->suc;
	}

	while(aux2->suc != NULL){
		aux2 = aux2->suc;
	}

	char restaUm = 0;

	while(aux1 != NULL || aux2 != NULL){
		char soma1=0, soma2=0;
		if(aux1 != NULL){
			soma1 = *((char*)aux1->info);
			aux1 = aux1->ant;
		}
		if(aux2 != NULL){
			soma2 = *((char*)aux2->info);
			aux2 = aux2->ant;
		}

		soma1 += soma2 + restaUm;
		restaUm = soma1/10;
		soma1 = soma1%10;
		insereNoInicio(&resultado, &soma1);
	}

	if(restaUm > 0){
		insereNoInicio(&resultado, &restaUm);
	}

	INT retorno;
	retorno.l = resultado;

	return retorno;
}

INT multiplica_INT(INT *p, int a){
	INT multiplicacao = *p;
	int i;

	for(i = 0; i < a;  i++){
		atribui_INT(&multiplicacao, soma_INT(p, &multiplicacao));
	}

	return multiplicacao;
}
