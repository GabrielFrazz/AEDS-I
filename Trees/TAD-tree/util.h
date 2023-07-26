#include <stdio.h>
#include <stdlib.h>

#ifndef util_H_INCLUDED
#define util_H_INCLUDED

typedef struct item{
    int chave;
} TItem;

void LerItem(TItem *x);

void ImprimirItem(TItem x);

#endif 