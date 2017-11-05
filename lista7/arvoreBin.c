#include <stdio.h>
#include <stdlib.h>
#include "arvoreBin.h"


struct NO{
  int info;
  struct NO *esq;
  struct NO *dir;
};
//criação
arvBin* cria_arv(){
  arvBin* raiz = (arvBin*) malloc(sizeof(arvBin)); //ponteiro para arvBin
  if(raiz != NULL) //se alocação ok
    *raiz = NULL; //retorna NULL
  return raiz;//retorna NULL
  /*
      arvBin* raiz
           |
       ________
        [raiz]
           |
          \|/
          NULL
  */
}
//libera nó a nó
void libera_NO(struct NO* no){
  if(no == NULL)
    return;//não há o que fazer
  libera_NO(no->esq);//percorre recursivamente
  libera_NO(no->dir);//percorre recursivamente
  free(no);//libera o NÓ
  no = NULL;//para evitar algum erro posterior

}
//libera árvore
void libera_arv(arvBin* raiz){
  if(raiz == NULL)
    return;//não há o que fazer
  libera_NO(*raiz);//libera cada nó
  free(raiz);//libera a raiz
}
//está vazia?
int estaVazia_arv(arvBin* raiz){
  if(raiz == NULL)//se a raiz == null
    return 1;
  if(*raiz == NULL)//se o conteúdo da raiz == null
    return 1;
  return 0;
}
//saber a altura da arvore
int altura_arv(arvBin *raiz){
  if(raiz==NULL) return 0;
  if(*raiz==NULL) return 0;
    int alt_esq = altura_arv(&((*raiz)->esq));//chamada recurvisa p/ sub arvora da esq
    int alt_dir = altura_arv(&((*raiz)->dir));//chamada recurvisa p/ sub arvora da dir
    if(alt_esq > alt_dir)
      return (alt_esq + 1);
    else
      return (alt_dir + 1);

}
//saber total de nós da arvore
int totalNO_arv(arvBin *raiz){
  if(raiz==NULL) return 0;
  if(*raiz==NULL) return 0;
    int alt_esq = totalNO_arv(&((*raiz)->esq));//percorre o nó da esquerda
    int alt_dir = totalNO_arv(&((*raiz)->dir));//percorre o nó da direita
    return(alt_esq + alt_dir + 1);//soma o total de nós daquel percurso

}
void preOrdem_arv(arvBin *raiz){
  if(raiz==NULL) return;
  if(*raiz!=NULL){
    printf("%d\n",(*raiz)->info);
    preOrdem_arv(&((*raiz)->esq));
    preOrdem_arv(&((*raiz)->dir));
  }

}
void emOrdem_arv(arvBin *raiz){
  if(raiz==NULL) return;
  if(*raiz!=NULL){
    emOrdem_arv(&((*raiz)->esq));
    printf("%d\n",(*raiz)->info);
    emOrdem_arv(&((*raiz)->dir));
  }

}
void posOrdem_arv(arvBin *raiz){
  if(raiz==NULL) 
    return;
  if(*raiz!=NULL){
    posOrdem_arv(&((*raiz)->esq));
    posOrdem_arv(&((*raiz)->dir));
    printf("%d\n",(*raiz)->info);
  }
}
int insere_arv(arvBin *raiz, int valor){
    if(raiz==NULL) 
      return 0;
    struct NO* novo;//alocando novo nó
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL) 
      return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
      //procurar onde inserir o valor
    if(*raiz == NULL)
      *raiz = novo;
    else{
      struct NO* atual = *raiz;
      struct NO* ant = NULL;
      while(atual != NULL){//vai desccendo na arvore
        ant = atual;
        if(valor == atual->info){//para evitar valores repetidos
          free(novo);//libera nó alocado
          return 0;//elemento já existe!
        }
        if(valor > atual->info){
          atual = atual->dir;
        }
        if(valor < atual->info){
          atual = atual->esq;
        }
      }
      //insere como filho desse nó folha
      if(valor > ant->info)
        ant->dir = novo;
      else
        ant->esq = novo;

      return 1;
    }

}/* condition */
/*
Remoção
Para remoção existem 3 casos:
1 - nó folha, ou seja, sem filhos.
2 - nó com apenas 1 filho.
3 - nó com 2 filhos.
*/
struct NO* remove_atual(struct NO* atual){
  struct NO *no1, *no2;
  /*
  sem filho da esquerda
  apontar para o filho da direita, ou seja,
  trata nó folha e nó com 1 filho.
  */
  if(atual->esq == NULL){
    no2 = atual->dir;
    free(atual);
    return no2;
  }
  /*
  procura filho mais a direita na sub-arvore da
  esquerda. vai descendo na arvore mais a direita
  ()
     \
      ()
        \
         ()
  */
  no1 = atual;
  no2 = atual->esq;
  while (no2->dir != NULL) {
    no1 = no2;
    no2 = no2->dir;
  }
  /*
  copia o filho mais a direita da sub-arvore
  esquerda para o lugar do nó removido.
  */
  if(no1 != atual){
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }
  no2->dir = atual->dir;
  free(atual);
  return no2;
}
int remove_arv(arvBin *raiz, int valor){
  //validando a arvore
  if(raiz == NULL) return 0;
  struct NO* ant = NULL;
  struct NO* atual = *raiz;
  //enquanto for diferente de null fico fazendo a busca
  while(atual != NULL){
    //achou o nó a ser removido. Tratar o lado da remoção
    //tratando quem eu vou remover
    if(valor == atual->info){
      if(atual == *raiz)
        *raiz = remove_atual(atual);
      else{
        if(ant->dir == atual)
          ant->dir = remove_atual(atual);
        else
          ant->esq = remove_atual(atual);
      }
      return 1;
    }
    //continua andando na arvore a procura do nó a ser removido
    ant = atual;
    if(valor > atual->info)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
}

/*
  Consultar um valor x na arvore:
  -comparar com a raiz
  -x é menor que a raiz?
  vá para a sub-arvore da esquerda

  -x é maior que a raiz?
  vá para a sub-arvore da direita
*/
int consulta_item_arv(arvBin *raiz, int valor){
  if(raiz == NULL) return 0;
  struct NO* atual = *raiz;
  while (atual != NULL) {
    if(valor == atual->info)
      return 1;
    //navegando dentro da arvore
    if(valor > atual->info)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return 0;
}
int main(){
  arvBin* raiz = cria_arv();
  if(estaVazia_arv(raiz)){
    printf("arvore vazia\n");
  }

  insere_arv(raiz,15);
  insere_arv(raiz,10);
  insere_arv(raiz,20);
  insere_arv(raiz,50);
  insere_arv(raiz,8);
  
  if(consulta_item_arv(raiz,25)){
    printf("achou\n");
  }else{
    printf("nao achou\n");
  }
  if(estaVazia_arv(raiz)){
    printf("arvore vazia\n");
  }
  posOrdem_arv(raiz);
}
