#include "INT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> //memcopy

char retornaValor(ElementoDuplo *e){
	return *((char*)e->info);
}

void setValor(ElementoDuplo *e, char valor){
	memcpy(e->info, &valor, sizeof(char));
}

void removeZeros(INT *p){
	ElementoDuplo *aux = p->l.cabeca;
	char info = 0;
	while(retornaValor(aux) == 0 && aux->suc != NULL){
		removeDoInicio(&(p->l), &info);
		aux = p->l.cabeca;
	}
}

int valida(char *x) {
	int i;
    for (i = 0; x[i] != '\0'; i++) {
        if (converte(x[i]) > 9 || converte(x[i]) < 0) {
            return 0;
        }
    }
    return 1;
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
//        printf("\nDados da lista:\n");
        ElementoDuplo *aux = inteiroLongo -> l.cabeca;
        while (aux != NULL) {
            mostra(aux -> info);
            aux = aux -> suc;
        }
    }
}

void atribui_INT(INT *inteiroLongo, INT aux) {
	desaloca_lista(&(inteiroLongo->l));
	inicializa_lista(&(inteiroLongo->l), sizeof(char));

	while(aux.l.cabeca != NULL){
		insereNoFim(&(inteiroLongo -> l), (aux.l.cabeca->info));
		aux.l.cabeca = aux.l.cabeca->suc;
	}
}

/*void atribui_INT(INT *inteiroLongo, INT aux) {
	int variavel_qualquer;
	while(!lista_vazia(inteiroLongo -> l)){
		removeDoFim(&(inteiroLongo -> l), &variavel_qualquer);
	}
	while(aux.l.cabeca != NULL){
		insereNoFim(&(inteiroLongo -> l), aux.l.cabeca->info);
		aux.l.cabeca = aux.l.cabeca->suc;
	}
}*/

int soma_INT(INT *p, INT *q, INT *resultado){
	inicializa_lista(&(resultado->l), sizeof(char));

	ElementoDuplo *aux1 = p->l.cabeca;
	ElementoDuplo *aux2 = q->l.cabeca;

	if(aux1 == NULL && aux2 != NULL){
		atribui_INT(resultado, *q);
		return 1;
	}
	if(aux2 == NULL && aux1 != NULL){
		atribui_INT(resultado, *p);
		return 1;
	}

	while(aux1->suc != NULL){
		aux1 = aux1->suc;
	}

	while(aux2->suc != NULL){
		aux2 = aux2->suc;
	}

	char soma1, soma2, restaUm = 0;

	while(aux1 != NULL || aux2 != NULL){

		soma1=0;
		soma2=0;

		if(aux1 != NULL){
			soma1 = retornaValor(aux1);
			aux1 = aux1->ant;
		}
		if(aux2 != NULL){
			soma2 = retornaValor(aux2);
			aux2 = aux2->ant;
		}

		soma1+=soma2+restaUm;
		restaUm = soma1/10;
		soma1 = soma1% 10;
		insereNoInicio(&(resultado->l),&soma1);
	}

	if(restaUm>0){
		insereNoInicio(&(resultado->l),&restaUm);
	}

	return 1;
}

char emprestaUm(ElementoDuplo *e){
	if(e != NULL){
		char valor= retornaValor(e);
		if(valor == 0){
			valor += emprestaUm(e->ant);
		}
		valor--;
		setValor(e, valor);
		return 10;
	}
    return 1;
}

int diminui_INT(INT *p, INT *q, INT *resultado){
	
	int comparacao = compara_INT(p, q);
	
	if(comparacao == -1){
		return INT_INVALIDO;
	}

	inicializa_lista(&(resultado->l),sizeof(char));

	ElementoDuplo *aux1 = p->l.cabeca;
	ElementoDuplo *aux2 = q->l.cabeca;

	int count1 =0, count2 = 0;
	char valor1 = retornaValor(aux1);
	char valor2 = retornaValor(aux2);

	while(aux1->suc != NULL){
		aux1 = aux1->suc;
	}

	while(aux2->suc != NULL){
		aux2 = aux2->suc;
	}

	while(aux1 != NULL && aux2 != NULL){
		valor1 = retornaValor(aux1);
		aux1 = aux1->ant;

		valor2 = retornaValor(aux2);
		aux2 = aux2->ant;

		if(valor2>valor1){
			valor1 += emprestaUm(aux1);
		}

		valor1 -= valor2;

		insereNoInicio(&(resultado->l),&valor1);
	}

	while(aux1 != NULL){

		valor1 = retornaValor(aux1);
		aux1 = aux1->ant;

		insereNoInicio(&(resultado->l),&valor1);
	}

	removeZeros(resultado);

	return 1;
}

int divisao_INT(INT *p, INT *q, INT *resultado){
    int cont = 0; 
    while(diminui_INT(p, q, resultado) == 1){ 
        atribui_INT(p,*resultado); 
        cont +=1; 
    }
    return cont; 
}

int multiplica_INT(INT *p, INT *q, INT *resultado){
	inicializa_lista(&(resultado->l), sizeof(char));

	ElementoDuplo *aux1 = p->l.cabeca;
	ElementoDuplo *aux2 = q->l.cabeca;

	while(aux1->suc != NULL){
		aux1 = aux1->suc;
	}

	while(aux2->suc != NULL){
		aux2 = aux2->suc;
	}

	char valor1, valor2, restaUm = 0, multiplicador = 0;
	char x = 0;

	while(aux2 != NULL){
		ElementoDuplo *aux3 = aux1;
		INT multiplicacaoAtual;
		inicializa_lista(&(multiplicacaoAtual.l), sizeof(char));
		restaUm = 0;

		int i;
		for(i = 0;i<multiplicador;i++){
			insereNoInicio(&(multiplicacaoAtual.l), &x);
		}

		while(aux3 != NULL){
			valor1 = retornaValor(aux3);
			valor2 = retornaValor(aux2);

			valor1*=valor2;
			valor1+=restaUm;

			restaUm = valor1/10;
			valor1 = valor1%10;

			insereNoInicio(&(multiplicacaoAtual.l), &valor1);

			aux3 = aux3->ant;
		}

		multiplicador++;

		if(restaUm>0){
			insereNoInicio(&(multiplicacaoAtual.l), &restaUm);
		}

		INT soma;
		soma_INT(resultado, &multiplicacaoAtual ,&soma);

		atribui_INT(resultado, soma);

		aux2 = aux2->ant;
	}

	return 1;
}

int compara_INT(INT *p, INT *q){
	
	ElementoDuplo *aux1 = p->l.cabeca;
	ElementoDuplo *aux2 = q->l.cabeca;

	int count1 = 0, count2 = 0;
	
	while(aux1 != NULL){
		aux1 = aux1->suc;
		count1++;
	}

	while(aux2 != NULL){
		aux2 = aux2->suc;
		count2++;
	}

	if(count1 > count2){
		return 1;
	}else if (count1 < count2){
		return -1;
	}else{
		aux1 = p->l.cabeca;
		aux2 = q->l.cabeca;
		
		char valor1 = retornaValor(aux1);
		char valor2 = retornaValor(aux2);
		
		while(valor1==valor2 && aux1 != NULL){
			valor1 = retornaValor(aux1);
			valor2 = retornaValor(aux2);
			
			aux1 = aux1->suc;
			aux2 = aux2->suc;
		}
		
		if(valor1>valor2){
			return 1;
		}else if(valor1<valor2){
			return -1;
		}
	}
	
	return 0;
}
