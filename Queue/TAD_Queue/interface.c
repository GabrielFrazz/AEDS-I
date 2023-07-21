#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. ENFILEIRAR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. DESENFILEIRAR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. COPIAR");
    printf("  \n\t6. IVERTER");
    printf("  \n\t7. SAIR");

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

                int a = PesquisarFila(Fila, &produto);

                if(a == 1){
                    ImprimirProduto(produto);
                }else{
                    printf("\n!produto nao esta na Fila!\n");
                }
                system("PAUSE");
                break;
            case 3:
                system("cls");    
                Desenfileirar(Fila, &produto);
                printf("\nproduto:\n");
                ImprimirProduto(produto);
                system("PAUSE");
                break;
            case 4:
                system("cls");
                recursivePrintQueue(Fila->frente->prox);
                system("PAUSE");
                break;
            case 5:
                system("cls");
                TFila Fila2;
                FFVazia(&Fila2);
                queueCpy(Fila, &Fila2);
                recursivePrintQueue(Fila2.frente->prox);
                system("PAUSE");
                break;
            case 6:
                system("cls");
                invertsQueue(Fila);
                printf("\n\tfila invertida!\n");
                system("PAUSE");
                break;
            case 7:
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
    } while(opcao != 7);
}