#include "stdlib.h"
#include "stdio.h"
#include<time.h>


typedef struct No{

    int valor;
    struct No *esq;
    struct No *dir;
}No;

typedef struct{

    No *raiz;
    int tamanho;

}Arvore;

void inicializaArvore(Arvore *a){
    a = (Arvore*)mallloc(sizeof(Arvore));
    a->raiz->esq = NULL;
    a->raiz->dir = NULL;
    a->tamanho = 0;
}

void insereArvore(Arvore *a, int v){
    No *ant = NULL;
    No *aux = a->raiz;
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = v;
    novo->dir = NULL;
    novo->esq = NULL;

    if(a->raiz==NULL){
        a->raiz = novo;
        return;
    }

    while(aux!=NULL && v!=aux->valor){
        ant = aux;

        if(v < aux->valor){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }

    }
    if(aux==NULL){
        if(v< ant->valor){
            ant->esq = novo;
        }else{
            ant->dir = novo;
        }
    /*Se o valor já existir na árvore a função retorna sem adicionar nada
    */
    }else{
        return;
    }

    a->tamanho++;   
}

void removeArvore(No *n,int v){
    No *ant = NULL;
    No *remove = NULL;

    if(n==NULL){
        return;
    }else{
        if(v==n->valor){
            if(n->esq==NULL && n->dir==NULL){
                free(n);
                return;
            }else{
                if(n->dir!=NULL && n->esq!= NULL){
                    No *aux = n->dir;
                    while(aux->esq!=NULL)
                        aux = aux->esq;
                    
                    n->valor = aux->valor;
                    aux->valor = v;
                    removeArvore(n,v);

                }else{
                    No *aux2;
                    if(n->esq!=NULL){
                        aux2 = n->esq;
                    }else{
                        aux2 = n->dir;
                    }
                    free(n);

                }
            }
        }else{
            if(v<n->valor){
                removeArvore(n->esq,v);
            }else{
                removeArvore(n->dir,v);
            }
        }
    }
}

void deletaArvore(Arvore *a){
    No *aux = a->raiz;
    while(a->raiz!=NULL){

    if(aux->esq!=NULL){
        deletaArvore(aux->esq);
    }else{
        if(aux->dir!=NULL){
            deletaArvore(aux->dir);
        }
    }
}
}

void imprimePreOrdem(Arvore *a){
    No *aux = a->raiz;
    if(aux != NULL){
        printf(" %d ", aux->valor);
        imprimePreOrdem(aux->esq);
        imprimePreOrdem(aux->dir);
    }
 }


int main(){
    Arvore *teste;
    int i,r;

    inicializaArvore(teste);
    srand(time(NULL));

    for (i=0;i<10;i++){
        r= rand() % 10;
        insereArvore(teste,r);
    }
    imprimePreOrdem(teste);



}