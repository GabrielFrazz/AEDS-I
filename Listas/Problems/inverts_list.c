#include <stdio.h>
#include <stdlib.h>

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


void invertsList(TLista *Lista){
    TCelula *Anterior, *Atual, *Proximo;
    Anterior = Proximo = NULL;
    Atual = Lista->primeiro;
    while(Atual != NULL){
        Proximo = Atual->prox;
        Atual->prox = Anterior;
        Anterior = Atual;
        Atual = Proximo;
    }
    Lista->primeiro = Anterior;
}

