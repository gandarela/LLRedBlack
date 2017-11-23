#include <stdio.h>
#include <stdlib.h>


typedef struct _Arv{
  int chave;
  struct _Arv *dir;
  struct _Arv *esq;
  int cor;
} Arv;

int cor(Arv *pt){
  if(pt == NULL || pt->cor == 0){
    return 0;
  }
  else{
    return 1;
  }
}

void recolore(Arv *pt){
  pt->cor = !pt->cor;
  pt->esq->cor = !pt->esq->cor;
  pt->dir->cor = !pt->dir->cor;
}

Arv *rotaesq(Arv *pt){
  Arv *novo = pt->dir;
  pt->dir = novo->esq;
  novo->esq = pt;
  novo->cor = pt->cor;
  pt->cor = 1;
  return novo;
}

Arv *rotadir(Arv *pt){
  Arv *novo = pt->esq;
  pt->esq = novo->dir;
  novo->dir = pt;
  novo->cor = pt->cor;
  pt->cor = 1;
  return novo;
}



Arv *insere(Arv *pt, int x){
  if(pt == NULL){
    pt = (Arv *)malloc(sizeof(Arv));
    pt->dir = NULL;
    pt->esq = NULL;
    pt->chave = x;
    pt->cor = 1;
    return pt;
  }
  if(cor(pt->esq) == 1 && cor(pt->dir) == 1){
    recolore(pt);
  }
  if(x < pt->chave){
    pt->esq = insere(pt->esq,x);
  }
  else if(x > pt->chave){
    pt->dir = insere(pt->dir,x);
  } else{
    puts("ja consta");
  }
  if(cor(pt->esq) == 0 && cor(pt->dir) == 1){
    pt = rotaesq(pt);
  }
  if(cor(pt->esq) == 1 && cor(pt->esq->esq) == 1){
    pt = rotadir(pt);
  }
  return pt;
}

Arv *insere1(Arv *pt, int x){
  pt = insere(pt,x);
  pt->cor = 0;
  return pt;
}

void imprime(Arv *pt){
  if(pt != NULL){
    if(pt->cor == 1)
      printf("%dR ", pt->chave);
    else
      printf("%dN ", pt->chave);


    imprime(pt->esq);

    imprime(pt->dir);

  }
}

int main(void){
  Arv *pt = NULL;
  pt = insere1(pt,1);
  pt = insere1(pt,2);
  pt = insere1(pt,3);
  pt = insere1(pt,4);
  pt = insere1(pt,5);
  pt = insere1(pt,6);
  imprime(pt);
  puts("");
  return 0;
}
