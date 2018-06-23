#include "INT.h"
#include <stdlib.h>
#include <stdio.h>

int inicializa_INT (INT *p, char *s){
	if(valida(s)){
		inicializa_lista(&p->l,sizeof(char));
		int i;
		for(i = 0; s[i] != '\0'; i++){
			char n = converte(s[i]);
			insereNoFim(&(p->l),&n);
		}
		return 1;//sucesso
	}else{
		return INT_INVALIDO;
	}
}

char converte(char x){
	return x - '0';
}

int valida(char *x){
	int i;
	for(i = 0; x[i] != '\0'; i++){
		if(converte(x[i]) > 9){
			return 0;
		}
	}
	return 1;
}
