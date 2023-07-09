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

void Excluir(TLista *Lista, TProduto *Item){
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if(Aux1 != NULL){
        Aux2 = Aux1 -> prox;
        Aux1 -> prox = Aux2 -> prox;
        *Item = Aux2 -> item;
        if(Aux1 -> prox == NULL)
            Lista->ultimo = Aux1;
        free(Aux2);
        Lista -> tamanho--;
    }else{
        printf("\nProduto nao encontrado\n");
        Item -> codigo = -1;
    }

}


void deleteNthElement(TLista Lista, int nth){

    TCelula *Aux = Lista.primeiro;

    for(int i = 0; i < nth; i++){
        Aux = Aux -> prox;
    }

    if(Aux != NULL){
        Excluir(&Lista, &Aux->item);
    }else{
        printf("\n!Celula não existe!\n");
    }

}