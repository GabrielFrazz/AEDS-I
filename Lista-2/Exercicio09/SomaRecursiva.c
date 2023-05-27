#include <stdio.h>
#include <stdlib.h>

int somaIterativa(int vet[], int tam);
int somaRecursiva(int vet[], int tam);

int main()
{
    int vect[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Soma iterativa = %d\n",somaIterativa(vect,10));
    printf("Soma Recursiva = %d",somaRecursiva(vect,10));
}

int somaIterativa(int vet[], int tam)
{
    int soma = 0;
    for (int i = 0; i < tam; i++)
    {
        soma += vet[i];
    }
    return soma;
}

int somaRecursiva(int vet[], int tam){
    
    if(tam == 1){
        return vet[0];
    }
    return vet[tam-1] + somaRecursiva(vet,tam-1);
}