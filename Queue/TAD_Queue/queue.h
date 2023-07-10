#include <stdio.h>
#include <stdlib.h>

#ifndef Fila_H_INCLUDED
#define Fila_H_INCLUDED

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
    TCelula* frente;
    TCelula* tras;
    int tamanho;
}TFila;

void FFVazia(TFila *Fila);

int Vazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Imprimir(TFila Fila);

TCelula* Pesquisar(TFila Fila, TProduto Item);

void Desenfileirar(TFila *Fila, TProduto *Item);

void recursivePrintQueue(TCelula *Celula);

int recursiveSearch(TCelula *Celula, TProduto *Item);

void queueCpy(TFila fila1, TFila *fila2);

void LiberarFila(TFila *Fila);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif // Fila_H_INCLUDED
