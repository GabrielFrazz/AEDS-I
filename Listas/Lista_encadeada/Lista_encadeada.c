#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void Imprimir(TLista Lista){
    TCelula* Aux;
    Aux = Lista.primeiro -> prox;
    while(Aux != NULL){
        printf("%d\n", Aux->item.codigo);
        Aux = Aux -> prox;
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

void ImprimirProduto(TProduto x){
    printf("\nProduto: %d\n", x.codigo);
    puts(x.nome);
    puts(x.descricao);
    printf("preco: %.2f", x.preco);
    printf("preco: %d", x.quantidade);
}

int main(){

    TLista Lista;
    TProduto x;
    FLVazia(&Lista);

    //Testa se a lista está vazia
    if(Vazia(Lista)){
        printf("lista vazia");
    }

    //Le produtos
    printf("Entre com dez produtos:\n\n");
    for(int i = 0; i < 10; i++){
        LerProduto(&x);
        Inserir(x, &Lista);
        printf("\n");
    }

    //Testa se determinado produto esta na lista
    printf("digite o codigo do produto que deseja pesquisar:\n");
    printf("->");
    fflush(stdin);
    scanf("%d",&x.codigo);

    if(Pesquisar(Lista, x) != NULL){
        printf("\n!Produto esta na lista!");
    }else{
        printf("!produto não está na lista!");
    }

    //Primeira impressao da Lista
    printf("\n---Imprimindo a lista---\n");
    Imprimir(Lista);

    //Excluindo um item
    printf("\ndigite o codigo do produto que deseja Excluir:\n");
    printf("->");
    fflush(stdin);
    scanf("%d",&x.codigo);

    Excluir(&Lista, &x);

    if(x.codigo == -1){
        printf("\nNao foi possivel realizar a exclusao!\n");
        //Impressao apos exclusao falha
        Imprimir(Lista);
    }else{
        printf("\nLista atualizada:\n");
        //Impressao apos exclusao
        Imprimir(Lista);
    }

    return 0;
}

