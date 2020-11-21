#include <stdio.h>


void intSwap(int *a, int *b);
void stringSwap(char **str1, char **str2);

int main(){
    int a = 10;
    int b = 7;
    
    printf("INT SWAP:\nAnfang: a=%d b=%d\n", a, b);

    intSwap(&a, &b);
    printf("intSwap: a=%d b=%d\n", a, b);

    printf("\n==============================\n\n");

    char *str1 = "hello";
    char *str2 = "world";
    printf("STRING SWAP:\nAnfang: str1=%s str2=%s\n", str1, str2);
    
    stringSwap(&str1, &str2);
    printf("stringSwap: str1=%s str2=%s\n", str1, str2);
}

void intSwap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void stringSwap(char **str1, char **str2){
    char *tmp;
    tmp=*str1;
    *str1=*str2;
    *str2=tmp;
}