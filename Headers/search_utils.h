//
// Created by Usuari on 27/4/2023.
//

#ifndef XARXA_SOCIAL_SEARCH_UTILS_H
#define XARXA_SOCIAL_SEARCH_UTILS_H

#define USER_NOT_FOUND (-1)
#define STRING_NOT_FOUND (-1)

#include "sort_utils.h"



int searchInStringArray(char** StringArray, int size, char* String);

// Ens busca binàriament un usuari a la llista d'usuaris.

int searchNetwork (char* attribute, Network *net, int type);

#endif //XARXA_SOCIAL_SEARCH_UTILS_H
