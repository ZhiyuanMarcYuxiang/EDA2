//
// Created by Usuari on 26/4/2023.
//

#ifndef XARXA_SOCIAL_SORT_UTILS_H
#define XARXA_SOCIAL_SORT_UTILS_H

#define LESSTHAN (-1)
#define GREATERTHAN 1

#define ONE_USER (1)

#include "../Headers/network_file_control.h"

// Ens ordena ascendentment una llista d'usuaris a partir de l'ordenació combinada i recursiva (merge sort).
void sortNetwork (Network *net, int type);

#endif //XARXA_SOCIAL_SORT_UTILS_H

