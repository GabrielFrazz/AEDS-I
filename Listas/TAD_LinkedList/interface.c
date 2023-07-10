#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR POR CODIGO");
    printf("  \n\t3. PESQUISAR POR NOME");
    printf("  \n\t4. EXCLUIR");
    printf("  \n\t5. EXCLUIR POR POSICAO");
    printf("  \n\t6. IMPRIMIR");
    printf("  \n\t7. IMPRIMIR POR POSICAO");
    printf("  \n\t8. SAIR");

}


void MENU(TLista* Lista){
    TProduto produto;
    int opcao=0;
    do
    {
        system("cls");
        printf("\n\t---tamanho atual da lista: %d---\n", Lista->tamanho);
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
                isertInOrder(Lista,produto);
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

                TCelula *Aux = Pesquisar(*Lista, produto);

                if(Aux != NULL){
                    ImprimirProduto(Aux->prox->item);
                    printf("\n");
                }else{
                    printf("\n!produto nao esta na lista!\n");
                }
                system("PAUSE");
                break;
            case 3:
                system("cls");
                printf("digite o nome do produto que deseja pesquisar:\n");
                printf("->");

                fflush(stdin);
                fgets(produto.nome, 50, stdin);
                fflush(stdin);

                Aux = recursiveSearch(Lista->primeiro->prox, produto);

                if(Aux != NULL){
                    ImprimirProduto(Aux->item);
                    printf("\n");
                }else{
                    printf("\n!produto nao esta na lista!\n");
                }
                system("PAUSE");
                break;   
            case 4:
                system("cls");
                printf("\ndigite o codigo do produto que deseja Excluir:\n");
                printf("->");
                fflush(stdin);
                scanf("%d",&produto.codigo);

                Aux = Pesquisar(*Lista, produto);

                if(Aux != NULL){
                    printf("\n------Produto a ser excluido------\n");
                    ImprimirProduto(Aux->prox->item);

                    int c;
                    printf("\n\tTem certeza que deseja continuar? (1-sim, 0-nao)\n");
                    printf("->");
                    fflush(stdin);
                    scanf("%d",&c);

                    if(c == 1){
                        Excluir(Lista, &produto);
                        printf("\n!Produto excluido com sucesso!\n");
                    }

                }else{
                    printf("\n!Produto nao encontrado!\n");
                }

                system("PAUSE");
                break;
            case 5:
                system("cls");
                printf("\ndigite a posicao do produto que deseja Excluir:\n");
                printf("->");
                fflush(stdin);
                scanf("%d", &produto.codigo);
                deleteNthElement(*Lista, produto.codigo);
                break;
            case 6:
                system("cls");
                recursivePrintList(Lista->primeiro->prox);
                system("PAUSE");
                break;
            case 7:
                system("cls");
                printf("\ndigite a posicao do produto que deseja Imprimir:\n");
                printf("->");
                fflush(stdin);
                scanf("%d", &produto.codigo);
                printNthElement(*Lista, produto.codigo);
                system("PAUSE");
                break;
            case 8:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<\n");
                LiberarLista(Lista);
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<\n");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 8);
    
}
