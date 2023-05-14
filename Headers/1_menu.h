//
// Created by Usuari on 26/4/2023.
//

// MARC BOSCH BRANCH

#ifndef XARXA_SOCIAL_1_MENU_H
#define XARXA_SOCIAL_1_MENU_H

#define INVALID_OPTION (-1)

#define OPTION_NEW_USER (1)
#define OPTION_LIST_USERS (2)
#define OPTION_OPERATE_USER (3)
#define OPTION_QUIT (0)

#define OPTION_REQUEST (1)
#define OPTION_MANAGE (2)
#define OPTION_POST (3)
#define OPTION_LIST_POSTS (4)
#define OPTION_RETURN_MENU (0)

#include "print_network.h"

// Funció principal amb el primer menú.
//      a) Nou usuari -> Aplica funció
//      b) Llista d'usuaris -> Aplica funció
//      c) Operar amb l'usuari -> Aplica menú
//      d) Sortir
void showMenu ();

// c) Submenú per a operar amb un usuari
//      1) Enviar sol·liticituds d'amistat
//      2) Gestionar sol·licituds
//      3) Nova publicació
//      4) Llista de publicacions
//      5) Tornar al menú principal
void operateUser (User *user);

#endif //XARXA_SOCIAL_1_MENU_H
