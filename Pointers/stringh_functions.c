#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adress {
    char *avenue;
    int number;
    char *country;
} TAdress;

typedef struct record {
    char *lastName;
    char *firstName;
    char *middleName;
    TAdress adr;
} TNameAndAdress;

typedef struct recordAll {
    TNameAndAdress name;
    int employeeNumber;
    float hoursWorked;
} TInputRecord;

TInputRecord *ptrDataInput; // declaração do ponteiro

char* Strcat(char *dest, const char *src){
    
    int i;

    for(i = 0; dest[i] != '\0'; i++);

    for(int j = 0; src[j] != '\0'; j++){
        dest[i] = src[j];
        i++;
    }

    return dest;

}

int Strlen(char *string){

    int i;
    for(i = 0; string[i] != '\0';i++);

    return i;

}

int Strcmp(char* str1, char* str2){

    int i;

    for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++){

        if(str1[i] != str2[i]){
            return 1;
        }

    }

    return str1[i] - str2[i];

}

int StrEnd(char *s, char *t){

    int start = Strlen(s) - Strlen(t);

    for(int j = start,i = 0; s[i] != '\0'; j++, i++){
    
        if(s[j] != t[i]){
            return 0;
        }

    }

    return 1;

}

int main(){
    
    //(a)
    ptrDataInput = (TInputRecord*)calloc(1,sizeof(TInputRecord));
    //(b)
    ptrDataInput->name.adr.avenue = (char*)calloc(100, sizeof(char));
    //(c)
    ptrDataInput->name.adr.country = (char*)calloc(50, sizeof(char));
    //(d)
    ptrDataInput->name.lastName = (char*)calloc(10, sizeof(char));
    //(e)
    ptrDataInput->name.firstName = (char*)calloc(100, sizeof(char));
    //(f)
    ptrDataInput->name.middleName = (char*)calloc(50, sizeof(char));
    //(g)
    char *av = ptrDataInput->name.adr.avenue;
    //(h)
    printf("->");
    fflush(stdin);
    fgets(ptrDataInput->name.adr.avenue,100, stdin);
    //(i)
    printf("->");
    fflush(stdin);
    fgets(ptrDataInput->name.firstName,100, stdin);
    //(j)
    puts(ptrDataInput->name.firstName);
    puts(ptrDataInput->name.adr.avenue);
    //(k)
    free(ptrDataInput->name.firstName);
    free(ptrDataInput->name.adr.avenue);
    //(L)
    free(ptrDataInput);
    
    return 0;

}