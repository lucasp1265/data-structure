#include "stdlib.h"
#include "stdio.h"
#include<time.h>

typedef struct No{

    int valor;
    struct No *prox;
}No;

typedef struct{

    No *topo;
    int tamanho;

}Pilha;

void iniciaPilha(Pilha *p){

    p->topo = NULL;
    p->tamanho = 0;

    return;
}

void inserePilha(Pilha *p, int v){

    No *novo = (No*)malloc(sizeof(No));
    
    novo->prox = NULL;
    novo->valor = v;

/* Verificação para verificar se a pilha está vazia 
*/
    if(p->topo==NULL){   
        p->topo = novo;
    }else{
    /* Insere o novo elemento na pilha como topo e aponta o anterior para o novo elemento
    */
        novo->prox = p->topo;
        p->topo = novo;
            
    }

    p->tamanho++;
    return;
}

void removePilha(Pilha *p){

    No *remove = NULL;

    if(p->topo!=NULL){
        remove=p->topo; 
        p->topo = remove->prox;
        free(remove);
        p->tamanho--;
    }

}

void deletaPilha(Pilha *p){
    No *aux = p->topo;

    while(aux!=NULL){
        removePilha(aux);
        aux = aux->prox;
    }
   free(p); 
}

void imprimePilha(Pilha *p){
    
    No *aux = p->topo;

   while(aux!=NULL){
        printf("%d\n",aux->valor);
        aux = aux->prox;
        }
   }

int main(){

    Pilha *teste = (Pilha*)malloc(sizeof(Pilha));
    int i;
    int r;

    iniciaPilha(teste);
    srand(time(NULL));

    for (i=0;i<100000;i++){
        r= rand() % 10;
        printf(" %d ",r);
        inserePilha(teste,r);
    }
    printf("\n");
    imprimePilha(teste);
    printf("\n");
    removePilha(teste);
    imprimePilha(teste);
    deletaPilha(teste);
    imprimePilha(teste);

return 0;
    
    
}