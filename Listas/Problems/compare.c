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

//compare, order doesn't matter
int coparates(TLista Lista1, TLista Lista2){

    if(Lista1.tamanho != Lista2.tamanho){
        return 0;
    }

    TCelula *Aux2 = Lista2.primeiro->prox;

    while(Aux2 != NULL){

        int test=1;
        TCelula *Aux1 = Lista1.primeiro->prox;

        while(Aux1 != NULL){
            if(Aux1->item.codigo == Aux2->item.codigo){
                test = 1;
                break;
            }else{
                test = 0;
            }
            Aux1 = Aux1 -> prox;
        }

        if(test == 0){
            return 0;
        }

        Aux2 = Aux2->prox;

    }

    return 1;
}

//compare, order does matter
int coparates(TLista Lista1, TLista Lista2){

    if(Lista1.tamanho != Lista2.tamanho){
        return 0;
    }

    TCelula *Aux1 = Lista1.primeiro->prox;
    TCelula *Aux2 = Lista2.primeiro->prox;

    while(Aux1 != NULL){

        if(Aux1 -> item.codigo != Aux2 -> item.codigo){
            return 0;
        }

        Aux1 = Aux1 -> prox;
        Aux2 = Aux2 -> prox;

    }

    return 1;

}
