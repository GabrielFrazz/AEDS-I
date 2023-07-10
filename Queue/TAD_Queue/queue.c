#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"


void FFVazia(TFila *Fila){
    Fila -> frente = (TCelula *) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> frente;
    Fila -> frente -> prox = NULL;
    Fila -> tamanho = 0;
}

int Vazia(TFila Fila){
    return(Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila){
    Fila -> tras -> prox = (TCelula *) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> tras -> prox;
    Fila -> tras -> item = x;
    Fila -> tras -> prox = NULL;
    Fila -> tamanho++;
}

void Imprimir(TFila Fila){
    TCelula* Aux;
    Aux = Fila.frente -> prox;
    while(Aux != NULL){
        ImprimirProduto(Aux->item);
        Aux = Aux -> prox;
    }
}

void recursivePrintQueue(TCelula *Celula){
    
    if(Celula != NULL){
        ImprimirProduto(Celula -> item);
        recursivePrintQueue(Celula -> prox);
    }    

}

int recursiveSearch(TFila *Fila, TProduto *Item){

    if(Vazia(*Fila)){
        return 0;
    }

    Desenfileirar(Fila, Item);
    
}

void Desenfileirar(TFila *Fila, TProduto *Item){

    TCelula *Aux;
    if(!Vazia(*Fila)){
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *Item = Aux->item;
        free(Aux);
        if(Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila -> tamanho--;
    }

}

void queueCpy(TFila *fila1, TFila *fila2){
    
    TProduto x;
    int aux = 0;
    while(aux<fila1->tamanho){
        Desenfileirar(fila1, &x);
        Enfileirar(x,fila2);
        Enfileirar(x,fila1);
        aux++;
    }

}


void LiberarFila(TFila *Fila){

    if(Vazia(*Fila)){
        free(Fila->frente);
    }

    TProduto temp;
    Desenfileirar(Fila,&temp);
    LiberarFila(Fila);

}

void invertsQueue(TFila *Fila){


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