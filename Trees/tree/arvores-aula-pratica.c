# include <stdio.h>
# include <stdlib.h>

typedef struct item{
    int chave;
} TItem;

typedef struct celula{
    TItem item;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;
} TCelula;


typedef struct arvore{
    TCelula *raiz;
}TArvore;

void Iniciar(TCelula **no){
    *no = NULL;
}

TCelula *criaNo(TItem Item){
    TCelula *no = (TCelula*) malloc(sizeof(TCelula));
    no->pai = NULL;
    no->esq = NULL;
    no->dir = NULL;
    no->item = Item;
    return no;
}

void Inserir(TCelula **x, TCelula *pai, TItem Item){
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

TCelula* Pesquisar(TCelula *x, TItem Item){
    if((x == NULL)||(x->item.chave == Item.chave))
        return x;
    if(Item.chave < x->item.chave)
        return Pesquisar(x->esq,Item);
    else if(Item.chave > x->item.chave)
        return Pesquisar(x->dir, Item);
}

//central iterativa
void CentralIterativa(TCelula *x){

    TCelula *y = x;
    TCelula *z = x;

   
    for(;y->esq != NULL; y = y->esq){
        z = y->pai;
        printf("%d", y->esq->item.chave);
    }
    for(;y->dir != NULL; y = y->pai){
        for(;y->esq != NULL; y = y->esq){
            z = y->pai;
            printf("%d", y->esq->item.chave);
        }
        printf("%d", y->dir->item.chave);
    }
           
}

void Central(TCelula *x){
    if (x != NULL){
     Central(x->esq);
     printf("%d ",x->item.chave);
     Central(x->dir);
    }
}

void PreOrdem(TCelula *x){
    if (x != NULL){
     printf("%d ",x->item.chave);
     PreOrdem(x->esq);
     PreOrdem(x->dir);
    }
}

void PosOrdem(TCelula *x){
    if (x != NULL){
     PosOrdem(x->esq);
     PosOrdem(x->dir);
     printf("%d ",x->item.chave);
    }
}

TCelula* Minimo(TCelula *x){
    if (x == NULL)
        return NULL;
    while(x->esq != NULL){
        x = x->esq;
    }
    return x;
}

TCelula* Maximo(TCelula *x){
    if (x == NULL)
        return NULL;
    while(x->dir != NULL){
        x = x->dir;
    }
    return x;
}

TCelula* Sucessor(TCelula *x){
    if(x == NULL)
        return NULL;
    if(x->dir != NULL)
        return Minimo(x->dir);
    TCelula *y = x->pai;
    while(y != NULL && x == y->dir){
        x = y;
        y = y->pai;
    }
    return y;
}

TCelula* Predecessor(TCelula *x){
    if(x == NULL)
        return x;
    if(x->esq != NULL)
        return Maximo(x->esq);
    TCelula* y = x->pai;
    while(y != NULL && x == y->esq){
        x = y;
        y = y->pai;
    }
    return y;
}

// Substitui subárvore enraizada no nó 'u' pela subárvore enraizada no nó 'v'.
void Transplante(TArvore *Arvore, TCelula **u, TCelula **v){
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
void Retirar(TArvore *Arvore, TCelula **z){
    if (*z == NULL){
        printf("\n>>>>> AVISO: NO' \"z\" E' NULO! <<<<<\n");
        return;
    }
    if((*z)->esq == NULL)
        Transplante(Arvore, z, &(*z)->dir);
    else if((*z)->dir == NULL)
        Transplante(Arvore, z, &(*z)->esq);
    else{
        TCelula *y = Minimo((*z)->dir);
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

int main(){
    TArvore Arvore;
    Iniciar(&Arvore.raiz);
    //printf("\np = %p\n", Arvore.raiz);

    TItem x;

    x.chave = 6;
    Inserir(&Arvore.raiz,NULL,x);

    x.chave  = 5;
    Inserir(&Arvore.raiz,NULL,x);

    x.chave = 7;
    Inserir(&Arvore.raiz,NULL,x);

    x.chave = 5;
    Inserir(&Arvore.raiz,NULL,x);

    x.chave = 2;
    Inserir(&Arvore.raiz,NULL,x);

    x.chave = 8;
    Inserir(&Arvore.raiz,NULL,x);

    printf("\n(a) Caminhamento in-ordem:\t");
    CentralIterativa(Arvore.raiz);
    printf("\n");
    printf("\n(b) Caminhamento pré-ordem:\t");
    PreOrdem(Arvore.raiz);
    printf("\n");
    printf("\n(c) Caminhamento pós-ordem:\t");
    PosOrdem(Arvore.raiz);
    printf("\n");

    printf("\nFilho direito da raiz: %d\n", Arvore.raiz->dir->item.chave);

    TCelula *y;
    y=Maximo(Arvore.raiz);
    if(y != NULL)
        printf("\nMaximo: %d\n",y->item.chave);

    y=Minimo(Arvore.raiz);
    if(y != NULL)
        printf("\nMinimo: %d\n",y->item.chave);

    printf("\nRaiz: %d\n",Arvore.raiz->item.chave);

    x.chave=10;
    printf("\nPesquisando pelo elemento %d...\n",x.chave);
    y=Pesquisar(Arvore.raiz, x);
    if (y != NULL)
        printf("\nElemento %d encontrado!\n",y->item.chave);
    else
        printf("\nELEMENTO NAO ENCONTRADO...\n");

    y=Sucessor(y);
    if(y != NULL)
        printf("\nSucessor: %d\n",y->item.chave);

    y=Predecessor(y);
    if(y != NULL)
        printf("\nPredecessor: %d\n",y->item.chave);

    printf("\nPai da raiz: %p\n", Arvore.raiz->pai);

    TCelula *no;
    x.chave = 7;
    printf("\nPesquisando pelo elemento %d para retira-lo da arvore...\n",x.chave);
    y=Pesquisar(Arvore.raiz, x);

    if (y != NULL){
        printf("\nElemento %d encontrado!\n",y->item.chave);
        Retirar(&Arvore, &y);
        printf("\nElemento %d removido da arvore! Agora seu ponteiro e' %p...\n",x.chave,y);
        printf("\n");
    }
    else
        printf("\nELEMENTO NAO ENCONTRADO...\n");

    x.chave=7;
    printf("\nPesquisando pelo elemento %d...\n",x.chave);
    y=Pesquisar(Arvore.raiz, x);
    if (y != NULL)
        printf("\nElemento %d encontrado!\n",y->item.chave);
    else
        printf("\nELEMENTO NAO ENCONTRADO...\n");

    printf("\n(a) Caminhamento in-ordem:\t");
    Central(Arvore.raiz);
    printf("\n");
    printf("\n(b) Caminhamento pré-ordem:\t");
    PreOrdem(Arvore.raiz);
    printf("\n");
    printf("\n(c) Caminhamento pós-ordem:\t");
    PosOrdem(Arvore.raiz);
    printf("\n");

    printf("\nFilho direito da raiz: %d\n", Arvore.raiz->dir->item.chave);

    system("PAUSE");
    
    return 0;
}
