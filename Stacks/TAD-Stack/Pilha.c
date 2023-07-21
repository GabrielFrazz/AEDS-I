#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pilha.h"


void FPVazia(TPilha *Pilha){

    Pilha->topo = (TCelula*) malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;

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

int Vazia(TPilha Pilha){

    return(Pilha.fundo==Pilha.topo);

}

void Empilhar(TProduto x, TPilha *Pilha){

    TCelula *Aux;
    Aux = (TCelula*)malloc(sizeof(TCelula));
    Pilha -> topo -> item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;

}

void Desempilhar(TPilha *Pilha, TProduto *Item){

    TCelula *q;
    if(Vazia(*Pilha)){
        printf("Erro: Pilha vazia\n");
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);
    Pilha->tamanho--;

}

void imprimirPilha(TPilha *Pilha){

    if(Vazia(*Pilha)){
        return;
    }

    TProduto x = Pilha->topo->item;
    Desempilhar(Pilha, &x);

    imprimirPilha(Pilha);

    ImprimirProduto(x);
    Empilhar(x, Pilha);

}

void invertePilhaDuasPilhas(TPilha *Pilha){

    TProduto x;
    TPilha Aux1, Aux2;
    FPVazia(&Aux1);
    FPVazia(&Aux2);

    while(!Vazia(*Pilha)){
        Desempilhar(Pilha, &x);
        Empilhar(x, &Aux1);
    }

    while (!Vazia(Aux1)){
        Desempilhar(&Aux1, &x);
        Empilhar(x, &Aux2);
    }

    while (!Vazia(Aux2)){
        Desempilhar(&Aux2, &x);
        Empilhar(x, Pilha);
    }

    liberarPilha(&Aux1);
    liberarPilha(&Aux2);
    
}

void invertePilhaUmaPilha(TPilha *Pilha){

    TPilha Aux;
    FPVazia(&Aux);

    int loop = Pilha->tamanho;


    for(int i = 1; i < loop; i++){

    TProduto x, y;
    Desempilhar(Pilha,&x);

    int j = i;

    while(j < loop){
        Desempilhar(Pilha,&y);
        Empilhar(y, &Aux);
        j++;
    }

    Empilhar(x, Pilha);

    j = i;
    while(j < loop){
        Desempilhar(&Aux, &x);
        Empilhar(x, Pilha);
        j++;
    }

    }

    liberarPilha(&Aux);

}

void invertePilhaFila(TPilha *Pilha){
    
}

int PesquisarPilha(TPilha *Pilha, TProduto *Item){

    TPilha Aux;
    TProduto x;
    FPVazia(&Aux);

    while(!Vazia(*Pilha)){
        Desempilhar(Pilha, &x);
        Empilhar(x, &Aux);
        if(x.codigo == Item->codigo){
            Desempilhar(&Aux, Item);
            Empilhar(x, &Aux);
            while(!Vazia(Aux)){
                Desempilhar(&Aux, &x); 
                Empilhar(x, Pilha);
            }
            return 1;
        }

    }

    while(!Vazia(Aux)){
        Desempilhar(&Aux, &x); 
        Empilhar(x, Pilha);
    }

    return 0;

}

void liberarPilha(TPilha *Pilha){

    TProduto x;
    while (!Vazia(*Pilha))
    {
        Desempilhar(Pilha, &x);
    }

    free(Pilha->topo);
    //free(Pilha->fundo);
}