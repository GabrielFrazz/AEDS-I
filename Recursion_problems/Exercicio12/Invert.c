#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char* invertsString(int size, char str[], int i);
void printString(char str[],int size);

int main(){
    char str[6] = "Hello!";
    printString(str,6);
    invertsString(6, str, 0);
    printString(str,6);
}

char* invertsString(int size, char str[], int i){

    if(i>=size){
        return str;
    }else{
        char temp = str[size-1];
        str[size-1]= str[i];
        str[i] = temp;
        return invertsString(size-1,str,i+1);
    }
    
}

void printString(char str[], int size){
    for(int i = 0; i < size; i++){
        printf("%c",str[i]);
    }
    printf("\n");
}
