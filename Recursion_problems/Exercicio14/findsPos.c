#include <stdio.h>
#include <stdlib.h>

int findPos(char str[], char sub[], int pos, int i, int j);

int main(){
    char str[9] = "carteiro\0";
    char sub[4] = "tei\0";
    printf("%d",findPos(str,sub,0,0,0));
}

int findPos(char str[], char sub[], int pos, int i, int j){
    if(sub[j] == '\0' || str[i] == '\0'){
        return pos;
    }
    if(str[i]==sub[j]){
        if(j==0){
            pos = i;
        }
        return findPos(str, sub, pos, i+1,j+1);
    }else{
        pos = -1;
        return findPos(str, sub, pos, i+1,0);
    }
}