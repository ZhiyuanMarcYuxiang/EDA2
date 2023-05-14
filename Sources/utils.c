//
// Created by Usuari on 26/4/2023.
//

#include "../Headers/utils.h"

/**
 * @param message: Un text que ens indica que hem d'entrar per consola un enter.
 * @return Llegeix un entern validat i ens el retorna. Hi col·labora la funció de "flush_input", que és per a treure el
 * caràcter de '\n' de la lectura per consola.
 */
int read_int(const char* message){
    int num, matched;
    printf("%s",message);
    // Entrem un enter i comprovem que sigui sols un enter (no altres caràcters).
    matched = scanf("%d",&num);
    while(matched == FALSE){
        // Esborra TOTS els caràcters incorrectes de stdin.
        // Elimina també el caràcter '\n' en clicar ENTER després d'introduir l'enter.
        flush_input();
        // Repetim l'entrada de l'enter.
        printf("Try again!\n");
        printf("%s",message);
        matched = scanf("%d",&num);
    }
    flush_input();
    return num;
}

/**
 * Funció que s'encarrega de cancel·lar el bucle que es produiria en el programa si no s'introdueix un enter a la
 * funció read_int. És la funció que supleix a fgetc(stdin), però és més efectiva, ja que esborra més d'un caràcter
 * incorrecte.
 */
void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @param string: String sense valors.
 * @param type: Tipus d'atribut.
 * @param max: Màxima longitud de l'string.
 * Funció que llegeix una cadena que té una longitud fitada entre un extrem màxim.
 */
void read_bounded_str(char string[], const char type[], int const max){
    scanf("%s",string);
    while(strlen(string)>max){
        printf("Length not correct!\n");
        printf("Enter a new %s",type);
        scanf("%s",string);
    }
}




