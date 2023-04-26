//
// Created by Usuari on 26/4/2023.
//

#include "../Headers/utils.h"


// Funció que serveix per a llegir un enter validat.
int read_int(const char* message){
    int option = INVALID_OPTION;
    printf("%s",message);
    scanf("%d",&option);

    flush_input();

    return option;
}

// Funció que s'encarrega de cancel·lar el bucle que es produiria en el programa
// si no s'introdueix un enter a la funció read_int.
void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

