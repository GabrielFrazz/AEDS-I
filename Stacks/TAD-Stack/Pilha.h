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
    TCelula* topo;
    TCelula* fundo;
    int tamanho;
}TPilha;

void FPVazia(TPilha *Pilha);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

int Vazia(TPilha Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *Item);

void imprimirPilha(TPilha *Pilha);

void invertePilhaUmaPilha(TPilha *Pilha);

void invertePilhaDuasPilhas(TPilha *Pilha);

void liberarPilha(TPilha *Pilha);

int PesquisarPilha(TPilha *Pilha, TProduto *Item);

#endif // LISTA_H_INCLUDED
