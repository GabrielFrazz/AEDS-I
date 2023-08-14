#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "util.h"
#include "queue.h"

typedef struct {
    TCelula* topo;
    TCelula* fundo;
    int tamanho;
}TPilha;

void FPVazia(TPilha *Pilha);

int VaziaPilha(TPilha Pilha);

void Empilhar(TItem x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TItem *Item);

void imprimirPilha(TPilha *Pilha);

void invertePilhaUmaPilha(TPilha *Pilha);

void invertePilhaDuasPilhas(TPilha *Pilha);

void invertePilhaFila(TPilha *Pilha);

void liberarPilha(TPilha *Pilha);

int PesquisarPilha(TPilha *Pilha, TItem *Item);

#endif // LISTA_H_INCLUDED
