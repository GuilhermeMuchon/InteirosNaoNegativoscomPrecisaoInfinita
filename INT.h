#include "LDE.h"
#define INT_INVALIDO -1

typedef struct{
	LDE l;
}INT;

int inicializa_INT(INT *p, char *s);
char converte(char x);
void desaloca_INT(INT *p);
