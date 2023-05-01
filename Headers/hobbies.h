//
// Created by Usuari on 27/4/2023.
//

#ifndef XARXA_SOCIAL_HOBBIES_H
#define XARXA_SOCIAL_HOBBIES_H

#define MAX_HOBBY 20
#define MIN_STRING 1
#define QUANTITY 5

#include "utils.h"

/**
 * Estructura dels gustos d'un usuari (nivell III).
 */
typedef struct{
    char hobby[MAX_HOBBY];   // Afició de l'usuari
}Hobbies;


void new_hobbies(Hobbies *h);

void print_hobbies(Hobbies *h);

void copy_hobbies(Hobbies *copy, Hobbies *origin);

#endif //XARXA_SOCIAL_HOBBIES_H
