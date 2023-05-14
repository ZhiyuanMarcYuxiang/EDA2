//
// Created by Usuari on 26/4/2023.
//

#ifndef XARXA_SOCIAL_SORT_UTILS_H
#define XARXA_SOCIAL_SORT_UTILS_H

#include "data_structures.h"

#define LESSTHAN (-1)
#define GREATERTHAN (1)

// Ens ordena ascendentment una llista d'usuaris.
void sortNetwork (Network *n, int type);

// Funcions d'ordenació de llista de forma combinada i recursiva.
// La funció auxiliar és "merge", que combina dues llistes de forma ordenada.

User* mergeSort(User *user, int size, int type);

User* merge (User* userA, int sizeA, User* userB, int sizeB, int type);


int compAttribute (User userA, User userB, int type);

// Copia per valor totes les dades d'un usuari a un altre.
void copyUser (User *copy,User *origin);


#endif //XARXA_SOCIAL_SORT_UTILS_H

