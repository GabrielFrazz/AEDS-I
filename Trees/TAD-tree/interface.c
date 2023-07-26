#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. CAMINHAMENTO_CENTRAL");
    printf("  \n\t3. PRE_ORDEM");
    printf("  \n\t4. POS_ORDEM");
    printf("  \n\t5. PESQUISAR");
    printf("  \n\t6. SUCESSOR");
    printf("  \n\t7. PREDECESSOR");
    printf("  \n\t8. MAXIMO");
    printf("  \n\t9. MINIMO");
    printf(" \n\t10. RETIRAR_NO");
    printf(" \n\t11. SAIR");
}

void MENU(TArvore *Arvore){

    int num;
    TItem x;
    TCelula celula;
    TCelula *y;

    int opcao;
     do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
            printf("\nquantas chaves deseja inserir?\n-> ");
            scanf("%d", &num);
            for(int i = 0; i<num; i++){
                system("cls");
                printf("\n\t\t insercao #%d\n\n", i+1);
                LerItem(&x);
                Inserir(&Arvore->raiz, NULL,x);
                printf("\n");
            }
            break;

            case 2:
            system("cls");
            printf("\n\n\tRealizando o caminhamento central\n");
            printf("\t ->");
            Central(Arvore->raiz);
            printf("\n");
            system("PAUSE");
            break;

            case 3:
            system("cls");
            printf("\n\n\tPre ordem\n");
            printf("\t-> ");
            PreOrdem(Arvore->raiz);
            printf("\n");
            system("PAUSE");
            break;
            
            case 4:
            system("cls");
            printf("\n\n\tPos ordem\n");
            printf("\t-> ");
            PosOrdem(Arvore->raiz);
            printf("\n");
            system("PAUSE");
            break;

            case 5:
            system("cls");
            printf("\n\n\tEntre com o elemento que deseja pesquisar\n");
            printf("\t-> ");
            scanf("%d", &x.chave);
            y = Pesquisar(Arvore->raiz, x);
            if (y != NULL)
                printf("\nElemento %d encontrado!\n",y->item.chave);
            else
                printf("\nELEMENTO NAO ENCONTRADO...\n");
            system("PAUSE");
            break;

            case 6:
            system("cls");
            printf("\n\n\tEntre com o elemento que deseja encontrar o sucessor\n");
            printf("\t-> ");
            scanf("%d", &x.chave);
            y = Pesquisar(Arvore->raiz, x);
            y = Sucessor(y);
            if (y != NULL){
               printf("\n\nSucessor: %d\n", y->item.chave);
            }
            else
                printf("\nELEMENTO %d NAO ESTA NA ARVORE...\n", x.chave);
            system("PAUSE");
            break;

            case 7:
            system("cls");
            printf("\n\n\tEntre com o elemento que deseja encontrar o predecessor\n");
            printf("\t-> ");
            scanf("%d", &x.chave);
            y = Pesquisar(Arvore->raiz, x);
            y = Predecessor(y);
            if (y != NULL){
               printf("\n\nPredecessor: %d\n", y->item.chave);
            }
            else
                printf("\nELEMENTO %d NAO ESTA NA ARVORE...\n", x.chave);
            system("PAUSE");
            break;

            case 8:
            system("cls");
            y = Maximo(Arvore->raiz);
            printf("\n\nMaximo: %d\n", y->item.chave);
            system("PAUSE");
            break;

            case 9:
            system("cls");
            y = Minimo(Arvore->raiz);
            printf("\n\nMinimo: %d\n", y->item.chave);
            system("PAUSE");
            break;

            case 10:
            system("cls");
            printf("\n\n\tEntre com a chave do no que deseja retirar\n");
            printf("\t-> ");
            scanf("%d", &x.chave);
            y = Pesquisar(Arvore->raiz, x);
            
            Retirar(Arvore, &y);

            if(&y!=NULL)
                printf("\n\tExclusao bem sucedida!\n");
            
            system("PAUSE");
            break;

            case 11:
            system("cls");
            printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<\n");
            system("PAUSE");
            break;

            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<\n");
                system("PAUSE");


        }

    }while(opcao != 11);

}