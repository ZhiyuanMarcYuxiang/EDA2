//
// Created by Usuari on 26/4/2023.
//

// MARC BOSCH BRANCH

#ifndef XARXA_SOCIAL_MENU_H
#define XARXA_SOCIAL_MENU_H

#include "user.h"

// Funció principal amb el primer menú.
//      a) Nou usuari -> Aplica funció de "user.c"
//      b) Llista d'usuaris -> Aplica funció de "user.c"
//      c) Operar amb l'usuari -> Aplica funció de "user.c"
//      d) Sortir
void show_menu();

// Inicialitza la llista d'usuaris.
ArrayUsers* init_users();
void new_user(ArrayUsers *aU);
void print_list_users(ArrayUsers *aU);

#endif //XARXA_SOCIAL_MENU_H
