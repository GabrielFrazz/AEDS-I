#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. EMPILHAR");
    printf("  \n\t2. IMPRIMIR");
    printf("  \n\t3. PESQUISAR");
    printf("  \n\t4. DESEMPILHAR");
    printf("  \n\t5. INVERTER_COM_UMA_PILHA");
    printf("  \n\t6. INVERTER_COM_DUAS_PILHAS");
    printf("  \n\t7. INVERTER_COM_UMA_FILA");
    printf("  \n\t8. SAIR");

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
                imprimirPilha(Pilha);
                system("PAUSE");
                break;
            case 3:
                system("cls");
                printf("entre com o codigo do produto:");
                scanf("%d", &produto.codigo);

                int a = PesquisarPilha(Pilha, &produto);

                if(a==1){
                    printf("\nProduto encontrado!\n\tImprimindo produto:\n\n");
                    ImprimirProduto(produto);
                }else{
                    printf("\nproduto nao encontrado");
                }
                system("PAUSE");
                break;    
            case 4:
                system("cls");    
                printf("\nentre com o codigo do produto a ser excluido\n");
                printf("->");
                scanf("%d", &produto.codigo);
                
                if(PesquisarPilha(Pilha, &produto) == 1){
                    int ch;
                    printf("\nProduto a ser excluido:\n\n");
                    ImprimirProduto(produto);
                    printf("deseja continuar? 1-(sim)_2-(nao)");
                    printf("\n->");
                    scanf("%d", &ch);
                    if(ch == 1){
                        Desempilhar(Pilha, &produto);
                    }else{
                        printf("\nproduto nao encontrado");
                    }
                }
                system("PAUSE");
                break;
            case 5:
                system("cls");
                invertePilhaUmaPilha(Pilha);
                printf("\n\tpilha invertida!\n");
                system("PAUSE");
                break;
            case 6:
                system("cls");
                invertePilhaDuasPilhas(Pilha);
                printf("\n\tpilha invertida!\n");
                system("PAUSE");
                break;
            case 7:
                break;
            case 8:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<\n");
                liberarPilha(Pilha);
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<\n");
                system("PAUSE");

        }
    }while(opcao != 8);
}
