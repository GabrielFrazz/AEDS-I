#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct {
    int codigo;
    float preco;
    char nome[50];
    char descricao[100];
    int quantidade;
} TProduto;

typedef struct celula{
    TProduto item;
    struct celula *ant;
    struct celula *prox;
} TCelula;

typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

void FLVaziaDL(TLista *Lista);

int VaziaDL(TLista Lista);

void InserirDL(TProduto x, TLista *Lista);

void ImprimirDL(TLista Lista);

TCelula* PesquisarDL(TLista Lista, TProduto Item);

void ExcluirDL(TLista *Lista, TProduto *Item);

void LiberarListaDL(TLista *Lista);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif // LISTA_H_INCLUDED
