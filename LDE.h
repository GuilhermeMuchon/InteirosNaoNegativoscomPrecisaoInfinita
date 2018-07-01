#define ERRO_LISTA_VAZIA -1
#define ERRO_POSICAO_INVALIDA -2

typedef struct ele{
  void *info;
  struct ele *suc, *ant;
}ElementoDuplo;

typedef struct{
  int tamInfo;
  ElementoDuplo *cabeca;
}LDE;

int maior(LDE l, int (*compara)(void*, void*));
void inverteLista(LDE l);
ElementoDuplo *aloca_ele(void *x, int t);
int busca(LDE l, void *chave, int(*compara)(void *, void *));
int quantidade(LDE l);
void inicializa_lista(LDE *p, int t);
int insereNoInicio(LDE *p, void *info);
void mostra_lista(LDE l, void (*mostra)(void*));
int lista_vazia(LDE l);
int removeDoInicio(LDE *l, void *info);
int removeDoFim(LDE *l, void *info);
int removeDaPos(LDE *l, void *info, int pos);
int modificaNaPos(LDE *l, void *info, int pos);
int leNaPos(LDE *l, void *info, int pos);
int insereNoFim(LDE *l, void *info);
void desaloca_lista(LDE *l);
int insereNaPos(LDE *l, void *info, int pos);
int insereEmOrdem(LDE *l, void *info, int (*compara)(void*, void*));
void mostrarInversamente(LDE l, void (*mostra)(void*));
void conta_elementos(LDE l);
