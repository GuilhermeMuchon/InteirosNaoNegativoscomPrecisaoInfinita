#include "LDE.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> //memcopy

void inicializa_lista(LDE *p, int t){
  p->cabeca  = NULL; //NULL -> ponteiro sem valor definido - n inicializado
  p->tamInfo = t;
}

void inverteLista(LDE l){
    if(lista_vazia(l)){
      printf("LDE vazia!\n");
    }else{
      ElementoDuplo *p1 = l.cabeca;
      ElementoDuplo *p2 = l.cabeca;
      while (p2->suc != NULL) {
          p2 = p2->suc;
      }
      while(p1 != p2->suc && p1 != p2){
          void *aux = p2->info;
          p2->info = p1->info;
          p1->info = aux;
          p2 = p2->ant;
          p1 = p1->suc;
      }
    }
}

int maior(LDE l, int (*compara)(void*, void*)){
    if(lista_vazia(l)){
        return ERRO_LISTA_VAZIA;
    }
    int cont = 0, i_maior = 0;
    ElementoDuplo *p = l.cabeca;
    void *maior = p->info;
    while (p != NULL) {
        if(compara(p->info, maior)>0){
            maior = p->info;
            i_maior = cont;
        }
        p=p->suc;
        cont += 1;
    }
    return i_maior;
}

void mostrarInversamente(LDE l, void (*mostra)(void*)){
    // int cont = 0;
    if(lista_vazia(l)){
      printf("LDE vazia!\n");
    }else{
      printf("Dados da lista:\n");
      ElementoDuplo *p = l.cabeca;
      while(p->suc != NULL){
        p = p->suc;
      }
      while(p != NULL) {
        // cont+=1;
        mostra(p->info);
        p = p->ant;
      }
    //   printf("O total de elementos e: %d\n", cont);
    }
}

// void mostra_invertido(LDE l, void(*mostra)(void*)){
//     if(lista_vazia(l)){
//         printf("Lista vazia\n");
//     }else{
//         mostra_ele(l.cabeca, mostra);
//     }
// }
// void mostra_ele(Elemento *p, void (*mostra)(void*)){
//     if(p!=NULL){
//         mostra_ele(p->proximo, mostra);
//         mostra(p->info);
//     }
// }
void conta_elementos(LDE l){
    int cont = 0;
    if(lista_vazia(l)){
      printf("LDE vazia!\n");
    }else{
      printf("Dados da lista:\n");
      ElementoDuplo *p = l.cabeca;
      while(p->suc != NULL){
        p = p->suc;
      }
      while(p != NULL) {
        cont+=1;
        p = p->ant;
      }
      printf("O total de elementos e: %d\n", cont);
    }
}

void mostra_lista(LDE l, void (*mostra)(void*)){
  if(lista_vazia(l)){
    printf("LDE vazia!\n");
  }else{
    printf("Dados da lista:\n");
    ElementoDuplo *p = l.cabeca;
    while(p != NULL){
      mostra(p->info);
      p = p->suc;
    }
  }
}

int lista_vazia(LDE l){ //funcao privada, n precisa estar no '.'h
  return l.cabeca == NULL;
}

void desaloca_lista(LDE *l){
    ElementoDuplo *p = l->cabeca;
    while(p != NULL){
        ElementoDuplo *suc = p->suc;
        free(p->info);
        free(p);
        p=suc;
    }
    l->cabeca=NULL;
}

int insereNoInicio(LDE *l, void *info){
  ElementoDuplo *novo = aloca_ele(info, l->tamInfo);
  if(novo == NULL){
    return 0; //Erro na alocação !
  }
  novo->suc = l->cabeca;
  l->cabeca = novo;
  novo->ant = NULL;
  if(novo->suc != NULL){
      novo->suc->ant=novo;
  }
  return 1; // sucesso total
}

ElementoDuplo *aloca_ele(void *x, int t){
  ElementoDuplo *p=(ElementoDuplo*)malloc(sizeof(ElementoDuplo));
  if(p==NULL){
    return NULL;
  }
  p->info=malloc(t);
  if(p->info==NULL){
    free(p);
    return NULL;
  }
  memcpy(p->info, x, t);
  return p;
}

int removeDoInicio(LDE *l, void *info){
  if(lista_vazia(*l)){
    return ERRO_LISTA_VAZIA;
  }
  ElementoDuplo *p=l->cabeca;
  l->cabeca=p->suc;
  memcpy(info,p->info,l->tamInfo);
  free(p->info);
  l->cabeca->ant=NULL;
  free(p);
  if(l->cabeca!=NULL){
  }
  return 1;
}

int insereNoFim(LDE *l, void *info){
    if(lista_vazia(*l)){
        return insereNoInicio(l,info);
    }
    ElementoDuplo *p = l->cabeca;
    while (p->suc!=NULL) {
        p=p->suc;
    }
    ElementoDuplo *novo = aloca_ele(info, l->tamInfo);
    if(novo == NULL){
        return 0; //erro na alocação
    }
    novo->suc = NULL;
    p->suc = novo;
    novo->ant = p;
    return 1; //sucesso
}

int insereNaPos(LDE *l, void *info, int pos){
  if(pos<0){
    return ERRO_POSICAO_INVALIDA; //-2 -> erro
  }
  if(pos==0){
    return insereNoInicio(l, info);
  }
  if(lista_vazia(*l)){ //pos > 0;
    return ERRO_POSICAO_INVALIDA;
  }
  ElementoDuplo *p = l->cabeca;
  int cont = 0;
  while(cont < pos -1 && p->suc !=NULL){
    p = p->suc;
    cont ++;
  }
  if(cont != pos -1){
    return ERRO_POSICAO_INVALIDA;
  }
  ElementoDuplo *novo = aloca_ele(info, l->tamInfo);
  if(novo == NULL){
    return 0; // Erro na alocação
  }
  novo->suc = p->suc;
  p->suc=novo;
  novo->ant=p;
  if(novo->suc!=NULL){
      novo->suc->ant = novo;
  }
  return 1; //sucesso
}

int removeDaPos(LDE *l, void *info, int pos){
  if(lista_vazia(*l)){
    return ERRO_LISTA_VAZIA;
  }
  if(pos<0){
    return ERRO_POSICAO_INVALIDA; //-2 -> erro
  }
  if(pos==0){
    return removeDoInicio(l, info);
  }
  ElementoDuplo *p = l->cabeca;
  int cont = 0;
  while(cont < pos-1 && p->suc != NULL){
    p = p->suc;
    cont++;
  }
  if(p->suc == NULL){
    return ERRO_POSICAO_INVALIDA;
  }
  ElementoDuplo *x = p->suc;
  p->suc = x->suc;
  memcpy(info, x->info, l->tamInfo);
  free(x->info);
  free(x);
  if(p->suc!=NULL){
      p->suc->ant = p;
  }
  return 1;
}

int leNaPos(LDE *l, void *info, int pos){
  if(lista_vazia(*l)){
    return ERRO_LISTA_VAZIA;
  }
  if(pos<0){
    return ERRO_POSICAO_INVALIDA; //-2 -> erro
  }
  ElementoDuplo *p = l->cabeca;
  int cont = 0;
  while(cont < pos-1 && p->suc != NULL){
    p = p->suc;
    cont++;
  }
  if(cont != pos){
    return ERRO_POSICAO_INVALIDA;
  }
  memcpy(info, p->info, l->tamInfo);
  return 1;
}


// ElementoDuplo *aloca_ele(void *x, int t){
//   ElementoDuplo *p=(ElementoDuplo*)malloc(sizeof(ElementoDuplo));
//   if(p==NULL){
//     return NULL;
//   }
//   p->info=malloc(t);
//   if(p->info==NULL){
//     free(p);
//     return NULL;
//   }
//   memcpy(p->info, x, t);
//   return p;
// }


int removeDoFim(LDE *l, void *info){
    if(lista_vazia(*l)){
        return ERRO_LISTA_VAZIA;
    }
    if(l->cabeca->suc == NULL){ //somente 1 ElementoDuplo
        return removeDoInicio(l, info);
    }
    ElementoDuplo *p = l->cabeca;
    while (p->suc->suc!=NULL) {
        p=p->suc;
    }
    ElementoDuplo*x = p->suc;
    memcpy(info, x->info, l->tamInfo);
    free(x->info);
    free(x);
    p->suc = NULL;
    return 1; //sucesso
}

void desaloca_lista_v2(LDE *l){
    void *aux = malloc(l->tamInfo);
    while(!lista_vazia(*l)){
        removeDoInicio(l,aux);
    }
    free(aux);
}

int quantidade(LDE l){
    if(lista_vazia(l)){
        return 0;
    }
    ElementoDuplo *p = l.cabeca;
    int cont = 0;
    while(p != NULL){
        cont ++;
        p = p->suc;
    }
    return cont;
}

int busca(LDE l, void *chave, int(*compara)(void *, void *)){
    if(lista_vazia(l)){
        return -1;
    }
    ElementoDuplo *p = l.cabeca;
    int cont=0;
    while (p!=NULL) {
        if(compara(chave, p->info)==0){
            return cont;
        }
        cont ++;
        p=p->suc;
    }
    return -1;
}

int insereEmOrdem(LDE *l, void *info, int (*compara)(void*, void*)){
    ElementoDuplo *p = l->cabeca;
    int cont = 0;
    while (p!= NULL && compara(p->info, info) < 0) {
        cont ++;
        p = p->suc;
    }
    return insereNaPos(l, info, cont);
}

/*
void *info = malloc(l.tamInfo);
int i;
for (i = 0; i < leNaPos(&l, info, i) != ERRO_POSICAO_INVALIDA; i++) {
    if(compara(info, chave)==0){
        free(info);
        return i;
    }
}
free(info);
return -1;
*/

