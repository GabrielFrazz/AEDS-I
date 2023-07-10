#include <stdio.h>
#include <string.h>

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


int Vazia(TLista Lista){
    return(Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista){
    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;
}


void isertInOrder(TLista *Lista, TProduto x){

    if(Vazia(*Lista) ||strcmp(Lista->ultimo->item.nome,x.nome)<0){
        Inserir(x,Lista);
        return;
    }

    TCelula *new = (TCelula *)malloc(sizeof(TCelula));
    new->item = x;
    TCelula *Aux = Lista->primeiro;
    
    while(Aux != NULL){
        
        if(strcmp(Aux->prox->item.nome, x.nome)>0){
            new->prox = Aux->prox;
            Aux->prox = new;
            return;
        }
        
        Aux = Aux->prox;
    }

}
