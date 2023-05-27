#include <stdio.h>
#include <stdlib.h>

int isContained(char whole[], char sub[], int stts,int i, int j);

int main(){
    char whole[15] = "Paralelepipedo\0";
    char sub[5] = "pipe\0";

    int result = isContained(whole, sub, 0, 0, 0);

    if(result == 1){
        printf("yes! it is contained");
    }else if(result == 0){
        printf("no! it is not contained");
    }

    return 0;
}

int isContained(char whole[], char sub[], int stts, int i, int j){
    if(whole[i] == '\0' || sub[j] == '\0'){
        return stts;
    }
    if(whole[i]==sub[j]){
        stts = 1;
        return isContained(whole, sub, stts, i+1,j+1);
    }
    else{
        stts = 0;
        return isContained(whole, sub, stts,i+1, 0);
    }
}