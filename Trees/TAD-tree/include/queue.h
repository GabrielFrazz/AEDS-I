#include <stdio.h>
#include <stdlib.h>

#ifndef Fila_H_INCLUDED
#define Fila_H_INCLUDED

#include "util.h"

typedef struct {
    TCelula* frente;
    TCelula* tras;
    int tamanho;
}TFila;

void FFVazia(TFila *Fila);

int VaziaFila(TFila Fila);

void Enfileirar(TItem x, TFila *Fila);

void Desenfileirar(TFila *Fila, TItem *Item);

void recursivePrintQueue(TCelula *Celula);

int PesquisarFila(TFila *Fila, TItem *Item);

void queueCpy(TFila *fila1, TFila *fila2);

void invertsQueue(TFila *Fila);

void LiberarFila(TFila *Fila);


#endif // Fila_H_INCLUDED
