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

//FREE LINKED LIST
void freeList(TLista *Lista){

    TCelula *Aux1, *Aux2;
    Aux1 = Lista -> primeiro;
    Aux2 = Lista -> primeiro -> prox;

    while(Aux1 != NULL){
        free(Aux1);
        Aux1 = Aux2;
        if(Aux2 != NULL)
            Aux2 = Aux2 -> prox;
    }

}

//FREE DOUBLY LINKED LIST
void freeListDL(TLista *Lista){

    TCelula *Aux;
    Aux = Lista->ultimo;

    while(Aux != Lista -> primeiro){
        Aux = Aux->ant;
        free(Aux->prox);
    }

    free(Aux);

}

