#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
  int valor;
  struct NO *esq;
  struct NO *dir;
}NO;
NO* criaArvore(NO *raiz){
    raiz = NULL;
    return raiz;
}
int estaVazia(NO *raiz){
  if(raiz == NULL)
    return 1;//esta vazio
  else
    return 0;//nao esta vazio
}
NO *inserir(NO *raiz,int valor){
  NO *novo;
  if(estaVazia(raiz)){
    // printf("inicializando\n");
    novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    raiz = novo;
    printf("valor inserido foi %d\n",raiz->valor);
  }else{
    if(valor < novo->esq->valor){
      raiz = inserir(novo->esq,valor);
    }else{
      raiz = inserir(novo->esq,valor);
    }
  }
  return raiz;
}
void pesquisaEmOrdem(NO *raiz, int valor){
  if(raiz != NULL){
    pesquisaEmOrdem(raiz->esq,valor);
    // if(valor == raiz->valor){
      printf("%d 1",raiz->valor);
    // }
    pesquisaEmOrdem(raiz->dir,valor);
  }
}

void main(){
  NO *raiz;
  criaArvore(raiz);
  inserir(raiz, 2);
  inserir(raiz, 1);
  inserir(raiz, 3);
  if(estaVazia(raiz)){
    printf("vazio\n");
  }
  pesquisaEmOrdem(raiz,1);
}
