#include "stdlib.h"
#include "stdio.h"
#include<time.h>

typedef struct No{

    int valor;
    struct No *prox;
}No;

typedef struct{

    No *prim, *ult;
    int tamanho;

}Lista;

void inicializaLista(Lista *lista){
    lista->prim = NULL;
    lista->ult = NULL;
    lista->tamanho=0;
}

void insereLista(Lista *lista, int v){

    No *novo = (No*)malloc(sizeof(No));
   
    novo->valor = v;
    lista->tamanho++;
    /* Se a lista estiver vazia o novo elemento é colocado como primeiro e último
    */

    if(lista->prim==NULL){
        novo->prox = NULL;
        lista->prim = novo;
        lista->ult = novo;
    }else{
        /* Se o valor v for menor que o primeiro valor da lista, v aponta para o primeiro e v se torna o novo primeiro
        */
        if(v<=lista->prim->valor){
            novo->prox = lista->prim;
            lista->prim = novo;
            return;
        }
        /* Se o valor v for maior que o último elemento da lista, v aponta pra nulo, se torna o último e o último aponta pra ele
        */
        if(v >= lista->ult->valor ){
            novo->prox = NULL; 
            lista->ult->prox = novo;
            lista->ult = novo;
            return;
        }
        /*o último caso se ele estiver pelo meio, o while acha sua posição e insere ele 
        */
        No *aux;
        aux = lista->prim;

        while(v>=aux->prox->valor){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;

    }

}

void imprimeLista(Lista *lista){

    No *aux = lista->prim;
    while(aux!=NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

void removeLista(Lista *lista, int v){
    No *aux = lista->prim; 
    No *aux2 = NULL;

        /* Caminha pela lista com o atual e o antecessor
        */
        while(aux != NULL && aux->valor < v) {
            aux2= aux;
            aux = aux->prox;
        }
        /* Se o elemento não for encontrado a função retorna
        */
        if(aux==NULL){
            return;
        }else{
            if(aux==lista->prim){
                lista->prim = aux->prox; 
            }else{
                /* Se o elemento estiver no meio da lista o anterior aponta para o próximo
                */
                aux2->prox = aux->prox;
                /*Se o elemento for o último da lista, o anterior será o novo último
                */
                if(aux==lista->ult){
                    lista->ult = aux2;
                }
            }
            free(aux); 
            lista->tamanho--;
        }     
}

void deletaLista(Lista *lista){
    No *aux = lista->prim;

    /* Loop para deletar o primeiro valor da lista até a lista ficar vazia
    */
    while(aux!=NULL){
        removeLista(lista,aux->valor);
        aux = lista->prim;
    }
    
    free(aux);
}


int main(){

    Lista *teste=(Lista*)malloc(sizeof(Lista));
    int i;
    int r,op;

    inicializaLista(teste);
    srand(time(NULL));

    for (i=0;i<10;i++){
        r= rand() % 10;
        insereLista(teste,r);
    }

    printf("A quantidade de elementos dessa lista e: %d\n",teste->tamanho);
    printf("E eles sao: \n");
    imprimeLista(teste);

    printf("\nEscolha um valor para ser removido\n");
    scanf("%d", &op);
    removeLista(teste,op);
    imprimeLista(teste);
    printf("\n");
    deletaLista(teste);
    imprimeLista(teste);
    return 0;
    
}

