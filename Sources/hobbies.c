//
// Created by Usuari on 27/4/2023.
//

#include "../Headers/hobbies.h"

/**
 * @param h: Llista de hobbies declarada.
 * Afegim totes les dades introduïts per consola a l'estructura dels hobbies.
 */
void new_hobbies(Hobbies *h){
    printf("Introduce your hobbies:\n");
    for(int i=0; i<QUANTITY; i++){
        printf(" - Hobby %d:", i+1);
        read_bounded_str(h[i].hobby,"hobbies",MIN_STRING,MAX_HOBBY);
    }
}

/**
 * @param h: Llista de hobbies inicialitzada amb valors.
 * Imprimim tots els hobbies d'un usuari.
 */
void print_hobbies(Hobbies *h){
    printf("Hobbies:\n");
    for(int i=0; i<QUANTITY; i++)
        printf(" - Hobby %d: %s\n", i+1, h[i].hobby);
}

/**
 * @param copy:
 * @param origin
 */
void copy_hobbies(Hobbies *copy, Hobbies *origin){
    for(int i=0; i<QUANTITY; i++)
        strcpy(copy[i].hobby,origin[i].hobby);
}
