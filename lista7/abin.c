#include <stdio.h>
#include <stdlib.h>

typedef struct no NO;
struct no{
    int valor;
    NO *esq, *dir;
};

NO* inserir(NO *raiz, int valor){
    if(raiz == NULL){
        raiz = malloc(sizeof(NO));
        raiz->valor = valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }else if(valor < raiz->valor){
        raiz->esq = inserir(raiz->esq,valor);
    }else{
        raiz->dir = inserir(raiz->dir,valor);
    }
    return raiz;
}
int estaVazia(NO *raiz){
    if(raiz == NULL){
        return 1;
    }
    return 0;
}
NO* buscar(NO *raiz,int valor){
    if(raiz == NULL)
        return NULL;
    if(raiz->valor == valor){
        return raiz;
    }
    if(valor > raiz->valor){
        return buscar(raiz->dir,valor);
    }
    return buscar(raiz->esq,valor);

}
int buscaEmOrdem(NO *raiz, int valor){
    if(raiz == NULL)
        return 0;
    buscaEmOrdem(raiz->esq,valor);
    if(raiz->valor == valor)
        printf("valor %d encontrado \n",raiz->valor);
    buscaEmOrdem(raiz->dir,valor);
    
}
int buscaPreOrdem(NO *raiz, int valor){
    if(raiz == NULL)
        return 0;
    if(raiz->valor == valor)
        printf("valor %d encontrado \n",raiz->valor);
    buscaPreOrdem(raiz->esq,valor);    
    buscaPreOrdem(raiz->dir,valor); 
}
int buscaPosOrdem(NO *raiz, int valor){
    if(raiz == NULL)
        return 0;
    buscaPosOrdem(raiz->esq,valor);    
    buscaPosOrdem(raiz->dir,valor);   
    if(raiz->valor == valor)
        printf("valor %d encontrado \n",raiz->valor); 
}
void emOrdem(NO *raiz){
    if(raiz == NULL)
        return;
    emOrdem(raiz->esq);
    printf("%d \n",raiz->valor);
    emOrdem(raiz->dir);
}
void preOrdem(NO *raiz){
    if(raiz == NULL)
        return;
    printf("%d \n",raiz->valor);
    preOrdem(raiz->esq);    
    preOrdem(raiz->dir);    
}
void posOrdem(NO *raiz){
    if(raiz == NULL)
        return;
    posOrdem(raiz->esq);    
    posOrdem(raiz->dir);   
    printf("%d \n",raiz->valor); 
}

int main(int argc, char** argv){
    NO *raiz = NULL;//cria arvore
    
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 7);
    
    // printf("Em ordem\n");
    // emOrdem(raiz);
    // if(buscar(raiz,1)==NULL){
    //     printf("Valor nao encontrado\n");
    // }else{
    //     printf("Valor encontrado\n");
    // }
    printf("Busca em ordem\n");
    buscaEmOrdem(raiz,25);
    buscaPreOrdem(raiz,10);
    buscaPosOrdem(raiz,7);
    // printf("\nBusca Pre ordem\n");
    // buscaPreOrdem(raiz,25);
}