#include "stdlib.h"
#include "stdio.h"
#include<time.h>

typedef struct No{

    int valor;
    struct No *prox;
}No;

typedef struct{

    No *ini,*fin;
    int tamanho;

}Fila;

void iniciaFila(Fila *f){
    f->ini=NULL;
    f->fin=NULL;
    f->tamanho=0;
}

void insereFila(Fila *f,int v){

    No *novo = (No*)malloc(sizeof(No));
    novo->valor = v;
    novo->prox = NULL;
    /* Se a fila estiver vazia, insere no inicio e fim da fila
    */
    if(f->fin==NULL){
        f->ini = novo;
        f->fin = novo;
    }else{
        f->fin->prox = novo;
        f->fin = novo; 
    }
    f->tamanho++;
}

void removeFila(Fila *f){
    No *aux = f->ini;
    /* Se tiver um único elemento o último recebe null
    */
    if(f->ini->prox==NULL){
        f->fin = NULL;
    }
    f->ini = aux->prox;
    free(aux);
    f->tamanho--;
}

void imprimeFila(Fila *f){
    No *aux = f->ini;

    while(aux!=NULL){
        printf("%d ",aux->valor);
        aux = aux->prox;
    }


}

void deletaFila(Fila *f){
    No *aux = f->ini;
    
    while(aux!=NULL){
        removeFila(f);
    }
}

int main(){

    Fila *teste = (Fila*)malloc(sizeof(Fila));
    int i,r;

    iniciaFila(teste);
    srand(time(NULL));

    for (i=0;i<100000;i++){
        r= rand() % 100;
        insereFila(teste,r);
    }
    imprimeFila(teste);
    deletaFila(teste);
    imprimeFila(teste);

    return 0;
}