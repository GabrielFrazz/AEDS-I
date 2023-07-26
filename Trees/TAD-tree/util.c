#include <stdio.h>
#include <stdlib.h>

#include "util.h"

void LerItem(TItem *x){
    printf("\n\tEntre com o item\n");
    printf("\tchave: ");
    scanf("%d", &x->chave);
}

void ImprimirItem(TItem x){
    printf("----------\n");
    printf("chave: %d", x.chave);
    printf("----------\n");
}


