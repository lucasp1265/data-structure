#include "stdlib.h"
#include "stdio.h"
#include<time.h>


typedef struct No{

    int valor;
    struct No *esq;
    struct No *dir;
    struct No *pai;
}No;

typedef struct{

    No *raiz;
    int tamanho;

}Arvore;

void inicializaArvore(Arvore *a){
    a->raiz = NULL;
    a->tamanho = 0;
}

void insereArvore(Arvore *a, int v){
    No *ant = NULL;
    No *aux = a->raiz;
    No *novo = (No*)malloc(sizeof(No));

    novo->valor = v;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;

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
        novo->pai = ant;
    /*Se o valor já existir na árvore a função retorna sem adicionar nada
    */
    }else{
        return;
    }

    a->tamanho++;   
}

void removeArvore(No *n,int v){
    No *ant = n;

    if(ant==NULL){
        return;
    }else{
        if(v==ant->valor){
            /* Caso o nó seja um nó folha
            */
            if(ant->esq==NULL && ant->dir==NULL){
                free(ant);
                return;
            }else{
                /* Caso o nó tenha dois filhos, o while procura o elemento mais a esquerda do nó da direita,
                    troca de lugar os valores dos dois e remove a folha com valor trocado
                */
                if(ant->dir!=NULL && ant->esq!= NULL){
                    No *aux = ant->dir;
                    while(aux->esq!=NULL)
                        aux = aux->esq;
                    
                    ant->valor = aux->valor;
                    aux->valor = v;
                    removeArvore(aux,v);

                }else{
                    /* Caso o Nó tenha um único filho
                    */
                    No *aux2 = ant;
                     /* O ponteiro ant recebe o filho, o ponteiro pai do nó que vai ser excluido aponta para o próximo da arvore
                        e é liberado a memória do nó a ser excluído
                    */
                    if(ant->esq!=NULL){
                        ant = ant->esq;
                    }else{
                        ant = ant->dir;
                    }
                    ant->pai = aux2->pai;
                    if(ant->pai->dir == aux2){
                        ant->pai->dir = ant;
                    }else{
                        ant->pai->esq = ant;
                    }
                     
                    free(aux2);

                }
            }
        }else{
            if(v<ant->valor){
                removeArvore(ant->esq,v);
            }else{
                removeArvore(ant->dir,v);
            }
        }
    }
}

void deletaArvore(No *n){

    if(n!=NULL){
        deletaArvore(n->esq);
        deletaArvore(n->dir);
        free(n);
    }
}

void imprimePreOrdem(No *n){
    No *aux = n;
    if(aux != NULL){
        printf(" %d ", aux->valor);
        printf("\n");
        imprimePreOrdem(aux->esq);
        imprimePreOrdem(aux->dir);
    }
 }

void imprimeEmOrdem(No *n){
  if(n != NULL){
   imprimeEmOrdem(n->esq);
   printf(" %d ", n->valor);
   printf("\n");
   imprimeEmOrdem(n->dir);

}
}

void imprimePosOrdem(No *n){
  if(n != NULL){
   imprimePosOrdem(n->esq);
   imprimePosOrdem(n->dir);
   printf(" %d ", n->valor);
   printf("\n");
}
}

int main(){
    Arvore *teste = (Arvore*)malloc(sizeof(Arvore));
    int i,r,op,n;

    inicializaArvore(teste);
    srand(time(NULL));

    for (i=0;i<10;i++){
        r= rand() % 1000;
        insereArvore(teste,r);
    }

    printf("Escolha : 1-Pre Ordem 2-Em Ordem 3-Pos Ordem \n");
    scanf("%d",&op);
    switch(op){
        case 1:
        imprimePreOrdem(teste->raiz);
        break; 

        case 2:
        imprimeEmOrdem(teste->raiz);

        case 3:
        imprimePosOrdem(teste->raiz);

    }

    printf("Escolha um elemento para remover\n");
    scanf("%d",&n);
    
    removeArvore(teste->raiz,n);
    imprimeEmOrdem(teste->raiz);

    deletaArvore(teste->raiz);
    imprimeEmOrdem(teste->raiz);

}
