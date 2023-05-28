#include <stdio.h>
#include <stdlib.h>

int mdc(int n, int m);

int main(){
    printf("%d",mdc(12,20));
}

int mdc(int n, int m){
    if(m<=n && n%m == 0){
        return m;
    }else if(n<m){
        return mdc(m,n);
    }else{
        return mdc(m,n%m);
    }
}