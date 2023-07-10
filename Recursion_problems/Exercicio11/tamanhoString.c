#include <stdio.h>
#include <stdlib.h>


int stringSize(char string[], int cont){

    if(string[cont] == '\0'){
        return cont-1;
    }
    
    return stringSize(string,cont+1);

}

int main(){
    char string[101];
    printf("digite a sua string: ");
    fgets(string, 100, stdin);

    printf("o tamanho da string e: %d",tamanhoString(string,0));
}