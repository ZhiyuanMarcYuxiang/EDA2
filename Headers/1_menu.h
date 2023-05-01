//
// Created by Usuari on 26/4/2023.
//

// MARC BOSCH BRANCH

#ifndef XARXA_SOCIAL_1_MENU_H
#define XARXA_SOCIAL_1_MENU_H

#define OPTION_NEW_USER (1)
#define OPTION_LIST_USERS (2)
#define OPTION_OPERATE_USER (3)
#define OPTION_QUIT (0)

#include "2_network.h"

// Funció principal amb el primer menú.
//      a) Nou usuari -> Aplica funció
//      b) Llista d'usuaris -> Aplica funció
//      c) Operar amb l'usuari -> Aplica funció
//      d) Sortir
void show_menu();

#endif //XARXA_SOCIAL_1_MENU_H
