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
    struct celula* ant;
} TCelula;

typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

TCelula* Pesquisar(TLista Lista, TProduto Item){
    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux -> prox != NULL){
        if(Aux->prox->item.codigo == Item.codigo)
            return Aux;
        Aux = Aux -> prox;
    }
    return NULL;
}

TCelula* recursiveSearch(TCelula *Celula, TProduto Item){

    if(Celula == NULL){
        return NULL;
    }

    if(strcmp(Item.nome, Celula->item.nome) == 0){
        return Celula;
    }

    return recursiveSearch(Celula->prox, Item);

}