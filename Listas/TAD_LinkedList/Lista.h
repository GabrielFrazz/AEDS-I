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
    struct celula* prox;
} TCelula;

typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

void FLVazia(TLista *Lista);

int Vazia(TLista Lista);

void Inserir(TProduto x, TLista *Lista);

void isertInOrder(TLista *Lista, TProduto x);

void Imprimir(TLista Lista);

void recursivePrintList(TCelula *Celula);

void printNthElement(TLista Lista, int nth);

TCelula* Pesquisar(TLista Lista, TProduto Item);

TCelula* recursiveSearch(TCelula *Celula, TProduto Item);

void Excluir(TLista *Lista, TProduto *Item);

void deleteNthElement(TLista Lista, int nth);

void LiberarLista(TLista *Lista);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif // LISTA_H_INCLUDED
