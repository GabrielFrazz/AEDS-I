#include <stdio.h>
#include <stdlib.h>

int maiorIterativo(int vet[], int tam);
int maiorRecursiva(int vet[], int tam);

int main()
{
    int vet[10] = {1, 2, 3, 4, 55, 6, 7, 8, 9, 10};
    printf("%d\n", maiorIterativo(vet, 10));
    printf("%d", maiorRecursiva(vet, 10));
}

int maiorIterativo(int vet[], int tam)
{

    int maior = vet[0];
    for (int i = 1; i < tam; i++)
    {
        if (vet[i] > maior)
        {
            maior = vet[i];
        }
    }
    return maior;
}

int maiorRecursiva(int vet[], int tam){
    
    if(tam == 1){
        return vet[0];
    }else{
        int m = maiorRecursiva(vet, tam-1);
        if(m>vet[tam-1]){
            return m;
        }else{
            return vet[tam-1];
        }
    }
}