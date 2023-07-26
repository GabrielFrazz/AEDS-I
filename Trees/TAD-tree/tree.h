# ifndef TREE_H_INCLUDED
# define TREE_H_INCLUDED

# include <stdio.h>
# include <stdlib.h>

#include "util.h"

typedef struct celula{
    TItem item;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;
} TCelula;


typedef struct arvore{
    TCelula *raiz;
}TArvore;

void Iniciar(TCelula **no);

TCelula *criaNo(TItem Item);

void Inserir(TCelula **x, TCelula *pai, TItem Item);

TCelula* Pesquisar(TCelula *x, TItem Item);

void Central(TCelula *x);

void PreOrdem(TCelula *x);

void PosOrdem(TCelula *x);

TCelula* Minimo(TCelula *x);

TCelula* Maximo(TCelula *x);

TCelula* Sucessor(TCelula *x);

TCelula* Predecessor(TCelula *x);

// Substitui subárvore enraizada no nó 'u' pela subárvore enraizada no nó 'v'.
void Transplante(TArvore *Arvore, TCelula **u, TCelula **v);

// Retira um nó 'z' na árvore 'Arvore'.
void Retirar(TArvore *Arvore, TCelula **z);

#endif