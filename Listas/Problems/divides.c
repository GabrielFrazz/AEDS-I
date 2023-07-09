#include <stdio.h>

typedef struct {
    int codigo;
    float preco;
    char nome[50];
    char descricao[100];
    int quantidade;
} TProduto;

typedef struct celula{
    TProduto item;
    struct celula* prox;
    struct celula* ant;
} TCelula;

typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

void Inserir(TProduto x, TLista *Lista){
    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;
}

void divides(TLista Lista1, TLista Lista2, TLista Lista3){

    int half = (Lista1.tamanho)/2;

    TCelula *Aux = Lista1.primeiro->prox;
    int test=0;

    while(Aux != NULL){

        if(test < half){
            Inserir(Aux->item,&Lista2);
        }else{
            Inserir(Aux->item,&Lista3);
        }

        test++;
        Aux = Aux->prox;

    } 
    
}


