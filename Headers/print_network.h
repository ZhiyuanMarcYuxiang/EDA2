//
// Created by Usuari on 13/5/2023.
//

#ifndef XARXA_SOCIAL_PRINT_UTILS_H
#define XARXA_SOCIAL_PRINT_UTILS_H

#endif //XARXA_SOCIAL_PRINT_UTILS_H

#include "new_user.h"

#define TITLES 5

// b) Imprimir llista d'usuaris
//      Imprimeix tots els usuaris que hi ha inscrits.
void printNetwork (Network *n);

// b) Llista d'usuaris
//      Imprimeix tots els usuaris que hi ha inscrits.
void printUser (User user, int *maximums);

// Respecte a una columna d'un atribut, mira la string més llarga.
int maxAttributes (User *user,int size, int type);

int * array_maxAttributes (Network* net, char** titles);

char** array_titles ();

void printSpaces (int maximum, char *title);