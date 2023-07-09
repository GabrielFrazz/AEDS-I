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
} TCelula;

typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

void FLVazia(TLista *Lista){
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista -> tamanho = 0;
}

void Inserir(TProduto x, TLista *Lista){
    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;
}

//Creates a new list
TLista concatenates(TLista Lista1, TLista Lista2){

    TLista result;
    FLVazia(&result);
    
    for(int i = 1; i<=2; i++){
        TCelula *Aux;
        if(i==1){
            Aux = Lista1.primeiro->prox;
        }else if(i == 2){
            Aux = Lista2.primeiro->prox;
        }
        while (Aux != NULL){
            Inserir(Aux->item, &result);
            Aux = Aux->prox;
        }
        
    }

    return result;
}

//modify Lista1
void concatenates(TLista *Lista1, TLista Lista2){
    Lista1 -> ultimo -> prox = Lista2.primeiro -> prox;
    Lista1 -> ultimo = Lista2.ultimo;
}