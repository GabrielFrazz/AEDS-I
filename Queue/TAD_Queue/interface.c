#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");

}


void MENU(TFila *Fila){
    TProduto produto;
    TCelula *Aux;
    int opcao=0;
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
                Enfileirar(produto, Fila);
                printf("\n");

                system("PAUSE");
                break;
            case 2:
                system("cls");
                printf("digite o codigo do produto que deseja pesquisar:\n");
                printf("->");

                fflush(stdin);
                scanf("%d",&produto.codigo);
                fflush(stdin);

                Aux = recursiveSearch(Fila, produto);

                if(Aux != NULL){
                    ImprimirProduto(Aux->item);
                }else{
                    printf("\n!produto não está na Fila!\n");
                }
                system("PAUSE");
                break;
            case 3:
                system("cls");
                printf("\ndigite o codigo do produto que deseja Excluir:\n");
                printf("->");
                fflush(stdin);
                scanf("%d",&produto.codigo);

                Aux = recursiveSearch(Fila, produto);

                if(Aux != NULL){
                    printf("\n------Produto a ser excluido------\n");
                    ImprimirProduto(Aux->item);

                    int c;
                    printf("\n\tTem certeza que deseja continuar? (1-sim, 0-nao)\n");
                    printf("->");
                    fflush(stdin);
                    scanf("%d",&c);

                    if(c == 1){
                        ExcluirDL(Fila, &produto);
                        printf("\n!Produto excluido com sucesso!\n");
                    }

                }else{
                    printf("\n!Produto nao encontrado!\n");
                }

                system("PAUSE");
                break;
            case 4:
                system("cls");
                recursivePrintQueue(Fila);
                system("PAUSE");
                break;
            case 5:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<\n");
                LiberarFila(Fila);
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}