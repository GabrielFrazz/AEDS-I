#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lista.h"

void FLVazia(TLista *Lista){
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista -> tamanho = 0;
}

int Vazia(TLista Lista){
    return(Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista){
    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;
}

void isertInOrder(TLista *Lista, TProduto x){

    if(Vazia(*Lista) ||strcmp(Lista->ultimo->item.nome,x.nome)<0){
        Inserir(x,Lista);
        return;
    }

    TCelula *new = (TCelula *)malloc(sizeof(TCelula));
    new->item = x;
    TCelula *Aux = Lista->primeiro;
    
    while(Aux != NULL){
        
        if(strcmp(Aux->prox->item.nome, x.nome)>0){
            new->prox = Aux->prox;
            Aux->prox = new;
            return;
        }
        
        Aux = Aux->prox;
    }

}

void invertsList(TLista *Lista){

    TCelula *Anterior, *Atual, *Proximo;
    Anterior = Proximo = NULL;
    Atual = Lista->primeiro->prox;

    while(Atual != NULL){

        Proximo = Atual->prox;
        Atual->prox = Anterior;
        Anterior = Atual;
        Atual = Proximo;

    }

    Lista->ultimo = Lista->primeiro->prox;
    Lista->primeiro->prox = Anterior;
    
}


void Imprimir(TLista Lista){
    TCelula* Aux;
    Aux = Lista.primeiro -> prox;
    while(Aux != NULL){
        ImprimirProduto(Aux->item);
        Aux = Aux -> prox;
    }
}

void recursivePrintList(TCelula *Celula){
    
    if(Celula != NULL){
        ImprimirProduto(Celula -> item);
        recursivePrintList(Celula -> prox);
    }    

}

void printNthElement(TLista Lista, int nth){

    TCelula *Aux = Lista.primeiro;

    for(int i = 0; i < nth; i++){
        Aux = Aux -> prox;
    }

    if(Aux != NULL){
        ImprimirProduto(Aux->item);
    }else{
        printf("\n!Celula não existe!\n");
    }

}

TCelula* Pesquisar(TLista Lista, TProduto Item){
    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux -> prox != NULL){
        if(Aux->prox->item.codigo == Item.codigo)
            return Aux;
        Aux = Aux -> prox;
    }
    return NULL;
}

TCelula* recursiveSearch(TCelula *Celula, TProduto Item){

    if(Celula == NULL){
        return NULL;
    }

    if(strcmp(Item.nome, Celula->item.nome) == 0){
        return Celula;
    }

    return recursiveSearch(Celula->prox, Item);

}

void Excluir(TLista *Lista, TProduto *Item){
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if(Aux1 != NULL){
        Aux2 = Aux1 -> prox;
        Aux1 -> prox = Aux2 -> prox;
        *Item = Aux2 -> item;
        if(Aux1 -> prox == NULL)
            Lista->ultimo = Aux1;
        free(Aux2);
        Lista -> tamanho--;
    }else{
        printf("\nProduto nao encontrado\n");
        Item -> codigo = -1;
    }

}

void deleteNthElement(TLista Lista, int nth){

    TCelula *Aux = Lista.primeiro;

    for(int i = 0; i < nth; i++){
        Aux = Aux -> prox;
    }

    if(Aux != NULL){
        Excluir(&Lista, &Aux->item);
    }else{
        printf("\n!Celula não existe!\n");
    }

}

void LiberarLista(TLista *Lista){

    TCelula *Aux1, *Aux2;
    Aux1 = Lista -> primeiro;
    Aux2 = Lista -> primeiro -> prox;

    while(Aux1 != NULL){
        free(Aux1);
        Aux1 = Aux2;
        if(Aux2 != NULL)
            Aux2 = Aux2 -> prox;
    }
    

}

int numeroDeCelulas(TLista *Lista){

    TCelula *Aux;
    Aux = Lista->primeiro;
    int cont = 0;

    while(Aux != NULL){
        cont++;
        Aux = Aux->prox;
    }

    return cont;

}

int numeroDeCelulasRec(TCelula *Celula, int cont){

    cont++;
    if(Celula->prox == NULL){
        return cont+1;
    }

    numeroDeCelulasRec(Celula->prox, cont);

}

void LerProduto(TProduto *x){
    printf("---Digite as informacoes do produto---\n");
    printf("entre com o codigo: ");
    fflush(stdin);
    scanf("%d", &x->codigo);
    printf("entre com a quantidade: ");
    fflush(stdin);
    scanf("%d", &x->quantidade);
    printf("entre com o preco: ");
    fflush(stdin);
    scanf("%f", &x->preco);
    printf("entre com o nome: ");
    fflush(stdin);
    fgets(x->nome, 50, stdin);
    printf("entre com a descricao: ");
    fflush(stdin);
    fgets(x->descricao, 100, stdin);

}

void ImprimirProduto(TProduto x) {

    printf("\n---------------------------\n");

    printf("\nCodigo: %d\n", x.codigo);
    printf("\nNome: ");
    puts(x.nome);
    printf("Descricao: ");
    puts(x.descricao);
    printf("Preco: R$ %.2f\n", x.preco);
    printf("\nQuantidade: %d\n", x.quantidade);

    printf("\n---------------------------\n");
}

