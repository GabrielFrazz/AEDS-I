#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"


void FLVaziaDL(TLista *Lista){
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = Lista->primeiro;
    Lista -> primeiro -> ant = Lista->primeiro;
    Lista -> tamanho = 0;
}

int VaziaDL(TLista Lista){
    return(Lista.primeiro == Lista.ultimo);
}

void InserirDL(TProduto x, TLista *Lista){
    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo -> prox -> ant = Lista -> ultimo;
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> prox = Lista -> primeiro;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = Lista->primeiro;
    Lista -> tamanho++;
}

void ImprimirDL(TLista Lista){
    TCelula* Aux;
    Aux = Lista.primeiro -> prox;
    while(Aux != Lista.primeiro){
        printf("\n");
        ImprimirProduto(Aux->item);
        Aux = Aux -> prox;
    }
}

TCelula* PesquisarDL(TLista Lista, TProduto Item){
    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux -> prox != Lista.primeiro){
        if(Aux->prox->item.codigo == Item.codigo)
            return Aux->prox;
        Aux = Aux -> prox;
    }
    return NULL;
}

void ExcluirDL(TLista *Lista, TProduto *Item){

    TCelula *Aux;
    Aux = PesquisarDL(*Lista, *Item);
    if(Aux != NULL){
        if(Aux != Lista -> ultimo){
            Aux -> ant -> prox = Aux -> prox;
            Aux -> prox -> ant = Aux -> ant;
        }else{
            Aux -> ant -> prox = Lista -> primeiro;
            Lista -> ultimo = Aux -> ant;
            Lista -> primeiro -> ant = Lista -> ultimo;
        }
        free(Aux);
        Lista -> tamanho--;
    }else{
        printf("\nProduto nao encontrado\n");
        Item -> codigo = -1;
    }

}

void LiberarListaDL(TLista *Lista){

    TCelula *Aux;
    Aux = Lista->ultimo;

    while(Aux != Lista -> primeiro){
        Aux = Aux->ant;
        free(Aux->prox);
    }

    free(Aux);

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
