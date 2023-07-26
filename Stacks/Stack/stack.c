#include <stdio.h>
#include <stdlib.h>

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
    TCelula* topo;
    TCelula* fundo;
    int tamanho;
}TPilha;

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

void imprimirPilha(TPilha Pilha){

    TProduto x;
    while(!Vazia(Pilha)) {
      Desempilhar(&Pilha, &x);
      ImprimirProduto(x);
   }

}

void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. IMPRIMIR");
    printf("  \n\t3. SAIR");

}

void MENU(TPilha *Pilha){
    int opcao;
    TProduto produto;
     do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                system("cls");
                printf("Entre com um produto:\n\n");

                LerProduto(&produto);
                Empilhar(produto, Pilha);
                printf("\n");

                system("PAUSE");
                break;
            case 2:
                system("cls");
                imprimirPilha(*Pilha);
                system("PAUSE");
                break;
        }
    }while(opcao != 3);
}

int main()
{
    TPilha Pilha;
    FPVazia(&Pilha);
    MENU(&Pilha);

    return 0;
}