#include <stdio.h>
#include <stdlib.h>

#ifndef util_H_INCLUDED
#define util_H_INCLUDED

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

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif 