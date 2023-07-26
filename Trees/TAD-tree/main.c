#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int main()
{
    TArvore Arvore;
    Iniciar(&Arvore.raiz);
    MENU(&Arvore);

    return 0;
}