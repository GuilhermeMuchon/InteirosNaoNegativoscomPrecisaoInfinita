#include "INT.h"

int inicializa_INT (INT *pm char *s){
	if(valida(s)){
		omicializa_lista(&l,sizeof(int));
		int i;
		for(i=0;s[i]!='\0';i++){
			int n = converte(s[i]);
			inserenofim(&p->l,&n);
		}
		return 1;//sucesso
	}else{
		return INT_INVALIDO;
	}
}
