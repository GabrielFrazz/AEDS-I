#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int chave;
} TItem;

typedef struct celula{
    TItem item;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;
} TCelula;


typedef struct arvore{
    TCelula *raiz;
}TArvore;

//central recursiva
void Central(TCelula *x){
    if (x != NULL){
     Central(x->esq);
     printf("%d ",x->item.chave);
     Central(x->dir);
    }
}

//PreOrdem recursiva
void PreOrdem(TCelula *x){
    if (x != NULL){
     printf("%d ",x->item.chave);
     PreOrdem(x->esq);
     PreOrdem(x->dir);
    }
}

//PosOrdem recursiva
void PosOrdem(TCelula *x){
    if (x != NULL){
     PosOrdem(x->esq);
     PosOrdem(x->dir);
     printf("%d ",x->item.chave);
    }
}

//central iterativa
void CentralIterativa(TCelula *x){

    TCelula *y = x;
    TCelula *z = x;

   
    for(;y->esq != NULL; y = y->esq){
        z = y->pai;
        printf("%d", y->esq->item);
    }
    for(;y->dir != NULL; y = y->pai){
        for(;y->esq != NULL; y = y->esq){
            z = y->pai;
            printf("%d", x->esq->item);
        }
        printf("%d", y->dir->item);
    }
           
}