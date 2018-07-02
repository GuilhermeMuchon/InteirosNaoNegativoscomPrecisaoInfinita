#include "LDE.h"
#define INT_INVALIDO -1

typedef struct{
	LDE l;
}INT;

int inicializa_INT(INT *p, char *s);
char converte(char x);
void mostra_INT(INT *p, void (*mostra)(void*));
void desaloca_INT(INT *p);
void atribui_INT(INT *inteiroLongo, INT aux);
INT soma_INT(INT *p, INT *q);
INT multiplica_INT(INT *p, int a);
