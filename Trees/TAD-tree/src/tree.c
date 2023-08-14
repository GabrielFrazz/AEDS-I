#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void Iniciar(Tnode **no){
    *no = NULL;
}

Tnode *criaNo(TItem Item){
    Tnode *no = (Tnode*) malloc(sizeof(Tnode));
    no->pai = NULL;
    no->esq = NULL;
    no->dir = NULL;
    no->item = Item;
    return no;
}

void Inserir(Tnode **x, Tnode *pai, TItem Item){
    if((*x) == NULL){
        (*x) = criaNo(Item);
        if(pai != NULL)
            (*x)->pai = pai;
        return;
    }
    if((*x)->item.chave > Item.chave){
        Inserir(&(*x)->esq, (*x), Item);
        return;
    }
    if ((*x)->item.chave <= Item.chave)
        Inserir(&(*x)->dir, (*x), Item);
}

Tnode* Pesquisar(Tnode *x, TItem Item){
    if((x == NULL)||(x->item.chave == Item.chave))
        return x;
    if(Item.chave < x->item.chave)
        return Pesquisar(x->esq,Item);
    else if(Item.chave > x->item.chave)
        return Pesquisar(x->dir, Item);
}

void Central(Tnode *x){
    if (x != NULL){
     Central(x->esq);
     printf("%d ",x->item.chave);
     Central(x->dir);
    }
}

void CentralIterativo(Tnode *x){
    
    TItem item;
    TPilha aux;
    FPVazia(&aux);

    int loop = 0;

    Tnode* atual = x;

    while(!loop){

        if(atual != NULL){
            Empilhar(atual->item, &aux);
            atual = atual->esq;
        }
        else{
            if(!VaziaPilha(aux)){
                Desempilhar(&aux, &item);
                atual = aux.topo;
                printf("%d ", item.chave);
                atual = atual->dir;
            }else{
                loop = 1;
            }
        }
    }
}

void PreOrdem(Tnode *x){
    if (x != NULL){
     printf("%d ",x->item.chave);
     PreOrdem(x->esq);
     PreOrdem(x->dir);
    }
}

void PreOrdemIterativo(Tnode *x){
    
    if(x == NULL){
        return;
    }

    TPilha aux1, aux2;
    FPVazia(&aux1);
    FPVazia(&aux2);

    Empilhar(x->item, &aux1);

    while(!VaziaPilha(aux1)){
        Tnode *node = aux1.topo;
        printf("%d ", node->item.chave);
        Desempilhar(&aux1, &node->item);

        TItem item;

        if (node->dir)
            Empilhar(x->dir->item, &aux1);
        if (node->esq)
            Empilhar(x->esq->item, &aux1);
    }

}

void PosOrdem(Tnode *x){
    if (x != NULL){
     PosOrdem(x->esq);
     PosOrdem(x->dir);
     printf("%d ",x->item.chave);
    }
}

Tnode* Minimo(Tnode *x){
    if (x == NULL)
        return NULL;
    while(x->esq != NULL){
        x = x->esq;
    }
    return x;
}

Tnode* Maximo(Tnode *x){
    if (x == NULL)
        return NULL;
    while(x->dir != NULL){
        x = x->dir;
    }
    return x;
}

Tnode* Sucessor(Tnode *x){
    if(x == NULL)
        return NULL;
    if(x->dir != NULL)
        return Minimo(x->dir);
    Tnode *y = x->pai;
    while(y != NULL && x == y->dir){
        x = y;
        y = y->pai;
    }
    return y;
}

Tnode* Predecessor(Tnode *x){
    if(x == NULL)
        return x;
    if(x->esq != NULL)
        return Maximo(x->esq);
    Tnode* y = x->pai;
    while(y != NULL && x == y->esq){
        x = y;
        y = y->pai;
    }
    return y;
}

// Substitui subárvore enraizada no nó 'u' pela subárvore enraizada no nó 'v'.
void Transplante(TArvore *Arvore, Tnode **u, Tnode **v){
    if ((*u)->pai == NULL)
        Arvore->raiz = (*v);
    else if((*u) == (*u)->pai->esq)
        (*u)->pai->esq = (*v);
    else
        (*u)->pai->dir = (*v);
    if(*v != NULL)
        (*v)->pai = (*u)->pai;

}

// Retira um nó 'z' na árvore 'Arvore'.
void Retirar(TArvore *Arvore, Tnode **z){
    if (*z == NULL){
        printf("\n>>>>> AVISO: NO' \"z\" E' NULO! <<<<<\n");
        return;
    }
    if((*z)->esq == NULL)
        Transplante(Arvore, z, &(*z)->dir);
    else if((*z)->dir == NULL)
        Transplante(Arvore, z, &(*z)->esq);
    else{
        Tnode *y = Minimo((*z)->dir);
        if(y->pai != (*z)){
            Transplante(Arvore, &y, &y->dir);
            y->dir = (*z)->dir;
            y->dir->pai = y;
        }
        Transplante(Arvore, z, &y);
        y->esq = (*z)->esq;
        y->esq->pai = y;
    }
    free(*z);
    *z = NULL;
}