#include <stdio.h>
#include <string.h> //um strcat zu nutzen.
#include <stdlib.h> //um malloc zu nutzen.

void toString(char *buffer);
void insertToBuf(char *buffer, char *newText);
void lengthOfBuf(char *buffer);
void copyBuf(char *buffer, char *buffer2);
int equals(char *str1, char *str2);
void split(char *buffer, char *delimiter, char** newArray);
void search(char **buffer, char *key);

int main(){
    //array ausgeben
    char *buffer = "hello world!";
    toString(buffer);

    //werte in array einfügen
    char buffer2[100];
    insertToBuf(buffer2, "das ist ein neuer Text\n");
    toString(buffer2);

    //größe des arrays
    lengthOfBuf(buffer2);
    
    //array kopieren
    copyBuf(buffer, buffer2);
    toString(buffer2);
    
    //arrays vergleichen
    printf( "equals liefert: %d\n", equals(buffer, buffer2) );

    //arrays splitten
    char buffer3[] = "test,split,now";
    char *newArray[3];
    split(buffer3, ",", newArray);
    toString(newArray[0]);
    toString(newArray[1]);
    toString(newArray[2]);

    //array durchsuchen:
    char buffer4[] = "cd $HOME";
    char *newArray3[3];
    split(buffer4, " ", newArray3);
    search(newArray3, "$");

    //char *buffer5 = "ls -als";
    //search(newArray2, "$");
    
    
    return 0;
}

void toString(char *buffer){
    printf("%s\n", buffer);
}

void insertToBuf(char *buffer, char *newText){
    strcat(buffer, newText); //fügt newText in den Buffer ein.
}

void lengthOfBuf(char *buffer){
    printf("Buffer-Length: %ld\n", strlen(buffer));
}

void copyBuf(char *buffer, char *buffer2){
    strcpy(buffer2, buffer); //buffer wird in buffer2 kopiert.
}

int equals(char *str1, char* str2){
    if( strcmp(str1, str2) == 0 ){ //Strings werden verglichen, wenn sie gleich sind wird 0 geliefert.
        return 1;
    } else{
        return 0;
    }
}

void split(char *buffer, char *delimiter, char **newArray){
    printf("\nsplit: ");
    toString(buffer);

    int i = 0;
    char *p = strtok(buffer, delimiter);

    while( p != NULL ){
        newArray[i++] = p;
        p = strtok(NULL, delimiter);
    }

    for(int j = 0; j<strlen(*newArray); j++){
        printf("Array: %s\n", newArray[j]);
    }
}

void search(char **buffer, char *key){
    for(int i = 0; i<strlen(*buffer); i++){
        if( strstr(buffer[i], key) != NULL ){
            printf("GEFUNDEN!\n");
            
            char *var = strtok(buffer[i], "$");
            printf("var: %s\n", var);

            buffer[i] = getenv(var);
            printf("AUFLÖSEN: %s\n", buffer[i]);
        } else{
            printf("NICHT GEFUNDEN!\n");
        }
    }
}