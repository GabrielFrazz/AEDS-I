#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"


void FFVazia(TFila *Fila){
    Fila -> frente = (TCelula *) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> frente;
    Fila -> frente -> prox = NULL;
    Fila -> tamanho = 0;
}

int VaziaFila(TFila Fila){
    return(Fila.frente == Fila.tras);
}

void Enfileirar(TItem x, TFila *Fila){
    Fila -> tras -> prox = (TCelula *) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> tras -> prox;
    Fila -> tras -> item = x;
    Fila -> tras -> prox = NULL;
    Fila -> tamanho++;
}

void recursivePrintQueue(TCelula *Celula){
    
    if(Celula != NULL){
        ImprimirItem(Celula -> item);
        recursivePrintQueue(Celula -> prox);
    }    

}

int PesquisarFila(TFila *Fila, TItem *Item){

    TFila Aux;
    FFVazia(&Aux);

    int tst;
    int codigo = Item->chave;

    while(!VaziaFila(*Fila)){
        Desenfileirar(Fila, Item);
        Enfileirar(*Item, &Aux);
        if(Item->chave == codigo){
            tst = 1;
            break;
        }    
    }

    TItem x;
    while (!VaziaFila(*Fila)){
        Desenfileirar(Fila, &x);
        Enfileirar(x, &Aux);
    }

    while (!VaziaFila(Aux)){
        Desenfileirar(&Aux, &x);
        Enfileirar(x, Fila);
    }
    
    if(tst == 1)
        return 1;

    return 0;

    LiberarFila(&Aux);

}

void Desenfileirar(TFila *Fila, TItem *Item){

    TCelula *Aux;
    if(!VaziaFila(*Fila)){
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *Item = Aux->item;
        free(Aux);
        if(Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila -> tamanho--;
    }

}

void queueCpy(TFila *fila1, TFila *fila2){
    
    TItem x;
    int aux = 0;
    while(aux<fila1->tamanho){
        Desenfileirar(fila1, &x);
        Enfileirar(x,fila2);
        Enfileirar(x,fila1);
        aux++;
    }

}


void LiberarFila(TFila *Fila){

    if(VaziaFila(*Fila)){
        free(Fila->frente);
        return;
    }

    TItem temp;
    Desenfileirar(Fila,&temp);
    LiberarFila(Fila);

}

void invertsQueue(TFila *Fila){

    if(VaziaFila(*Fila)){
        return;
    }

    TItem x;

    Desenfileirar(Fila, &x);
    invertsQueue(Fila);
    Enfileirar(x, Fila);

}
