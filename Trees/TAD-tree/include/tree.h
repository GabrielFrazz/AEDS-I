# ifndef TREE_H_INCLUDED
# define TREE_H_INCLUDED

# include <stdio.h>
# include <stdlib.h>

#include "util.h"
#include "Pilha.h"

typedef struct node{
    TItem item;
    struct node *pai;
    struct node *esq;
    struct node *dir;
} Tnode;


typedef struct arvore{
    Tnode *raiz;
}TArvore;

void Iniciar(Tnode **no);

Tnode *criaNo(TItem Item);

void Inserir(Tnode **x, Tnode *pai, TItem Item);

Tnode* Pesquisar(Tnode *x, TItem Item);

void Central(Tnode *x);

void CentralIterativo(Tnode *x);

void PreOrdem(Tnode *x);

void PosOrdem(Tnode *x);

Tnode* Minimo(Tnode *x);

Tnode* Maximo(Tnode *x);

Tnode* Sucessor(Tnode *x);

Tnode* Predecessor(Tnode *x);

// Substitui subárvore enraizada no nó 'u' pela subárvore enraizada no nó 'v'.
void Transplante(TArvore *Arvore, Tnode **u, Tnode **v);

// Retira um nó 'z' na árvore 'Arvore'.
void Retirar(TArvore *Arvore, Tnode **z);

#endif