#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pilha.h"


void FPVazia(TPilha *Pilha){

    Pilha->topo = (TCelula*) malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;

}


int VaziaPilha(TPilha Pilha){

    return(Pilha.fundo==Pilha.topo);

}

void Empilhar(TItem x, TPilha *Pilha){

    TCelula *Aux;
    Aux = (TCelula*)malloc(sizeof(TCelula));
    Pilha -> topo -> item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;

}

void Desempilhar(TPilha *Pilha, TItem *Item){

    TCelula *q;
    if(VaziaPilha(*Pilha)){
        printf("Erro: Pilha vazia\n");
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);
    Pilha->tamanho--;

}

void imprimirPilha(TPilha *Pilha){

    if(VaziaPilha(*Pilha)){
        return;
    }

    TItem x = Pilha->topo->item;
    Desempilhar(Pilha, &x);

    imprimirPilha(Pilha);

    ImprimirItem(x);
    Empilhar(x, Pilha);

}

void invertePilhaDuasPilhas(TPilha *Pilha){

    TItem x;
    TPilha Aux1, Aux2;
    FPVazia(&Aux1);
    FPVazia(&Aux2);

    while(!VaziaPilha(*Pilha)){
        Desempilhar(Pilha, &x);
        Empilhar(x, &Aux1);
    }

    while (!VaziaPilha(Aux1)){
        Desempilhar(&Aux1, &x);
        Empilhar(x, &Aux2);
    }

    while (!VaziaPilha(Aux2)){
        Desempilhar(&Aux2, &x);
        Empilhar(x, Pilha);
    }

    liberarPilha(&Aux1);
    liberarPilha(&Aux2);
    
}

void invertePilhaUmaPilha(TPilha *Pilha){

    TPilha Aux;
    FPVazia(&Aux);

    int loop = Pilha->tamanho;


    for(int i = 1; i < loop; i++){

    TItem x, y;
    Desempilhar(Pilha,&x);

    int j = i;

    while(j < loop){
        Desempilhar(Pilha,&y);
        Empilhar(y, &Aux);
        j++;
    }

    Empilhar(x, Pilha);

    j = i;
    while(j < loop){
        Desempilhar(&Aux, &x);
        Empilhar(x, Pilha);
        j++;
    }

    }

    liberarPilha(&Aux);

}

void invertePilhaFila(TPilha *Pilha){
    
    TFila Fila;
    FFVazia(&Fila);

    TItem x;

    while(!VaziaPilha(*Pilha)){
        Desempilhar(Pilha, &x);
        Enfileirar(x, &Fila);
    }

    while(!VaziaFila(Fila)){
        Desenfileirar(&Fila, &x);
        Empilhar(x, Pilha);
    }

    LiberarFila(&Fila);

}

int PesquisarPilha(TPilha *Pilha, TItem *Item){

    TPilha Aux;
    TItem x;
    FPVazia(&Aux);

    while(!VaziaPilha(*Pilha)){
        Desempilhar(Pilha, &x);
        Empilhar(x, &Aux);
        if(x.chave == Item->chave){
            Desempilhar(&Aux, Item);
            Empilhar(x, &Aux);
            while(!VaziaPilha(Aux)){
                Desempilhar(&Aux, &x); 
                Empilhar(x, Pilha);
            }
            return 1;
        }

    }

    while(!VaziaPilha(Aux)){
        Desempilhar(&Aux, &x); 
        Empilhar(x, Pilha);
    }

    liberarPilha(&Aux);

    return 0;

}

void liberarPilha(TPilha *Pilha){

    TItem x;
    while (!VaziaPilha(*Pilha))
    {
        Desempilhar(Pilha, &x);
    }

    free(Pilha->topo);
    //free(Pilha->fundo);
}