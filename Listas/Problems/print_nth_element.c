#include <stdio.h>

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
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

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