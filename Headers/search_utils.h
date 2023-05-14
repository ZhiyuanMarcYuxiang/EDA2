//
// Created by Usuari on 27/4/2023.
//

#ifndef XARXA_SOCIAL_SEARCH_UTILS_H
#define XARXA_SOCIAL_SEARCH_UTILS_H

#include "sort_utils.h"

#define USER_NOT_FOUND (-1)

// Ens busca binàriament un usuari a la llista d'usuaris.
int searchNetwork (char* attribute, Network *net, int type);

// Funcions que serveixen per a buscar un usuari (per nom) dins l'estructura d'usuaris.
// La cerca binària utilitza "mergeSort", ja que ha d'estar ordenada la llista per a aplicar el respectiu algoritme-
int binarySearch (char* attribute, Network *n, int type);

// Auxiliar al "binary_search": cancel·la la cerca quan l'usuari és més petit que el primer de la llista
// o quan és més gran que l'últim usuari.
int fencedAttribute (char* attribute, Network *n, int type);





#endif //XARXA_SOCIAL_SEARCH_UTILS_H
