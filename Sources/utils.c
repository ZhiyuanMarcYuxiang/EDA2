//
// Created by Usuari on 26/4/2023.
//

#include "../Headers/utils.h"


// Funció que serveix per a llegir un enter validat.
int read_int(const char* message){
    int num, matched;
    printf("%s",message);
    matched = scanf("%d",&num);
    while(matched == FALSE){
        flush_input(); // Esborra TOTS els caràcters incorrectes de stdin.
        printf("Try again!\n");
        printf("%s",message);
        matched = scanf("%d",&num);
    }
    return num;
}

// Funció que s'encarrega de cancel·lar el bucle que es produiria en el programa
// si no s'introdueix un enter a la funció read_int. És la funció que supleix a
// fgetc(stdin), però és més efectiva, ja que esborra més d'un caràcter incorrecte.
void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

// Legeix una cadena que té una longitud fitada entre dos extrems (min i max).
void read_bounded_str(char string[], char name[], int const min, int const max){
    scanf("%s",string);
    while(strlen(string)<min || strlen(string)>max){
        printf("Length not correct!\n");
        printf("Introduce a new %s:",name); scanf("%s",string);
    }
}