//
// Created by Usuari on 27/4/2023.
//

#ifndef XARXA_SOCIAL_2_NETWORK_H
#define XARXA_SOCIAL_2_NETWORK_H

#define OPTION_REQUEST (1)
#define OPTION_MANAGE (2)
#define OPTION_POST (3)
#define OPTION_LIST_POSTS (4)
#define OPTION_RETURN_MENU (0)

#define INVALID_OPTION (-1)

#include "3_user.h"

/**
 * Estructura de la llista d'usuaris (nivell I).
 */
typedef struct{
    User *user; // Llista dinàmica d'usuaris
    int size;   // Quantitat d'usuaris
}Network;

// Inicialitza la llista d'usuaris.
Network* init_users();
// a) Nou usuari
//      Inscriu un nou usuari a l'estructura de dades dels usuaris.
void new_user(Network *n);

// b) Imprimir llista d'usuaris
//      Imprimeix tots els usuaris que hi ha inscrits.
void print_list_users(Network *n);

// c) Operar amb un usuari
//      1) Enviar sol·liticituds d'amistat
//      2) Gestionar sol·licituds
//      3) Nova publicació
//      4) Llista de publicacions
//      5) Tornar al menú principal
void operate_user(Network *n);

// Ens ordena ascendentment una llista d'usuaris.
void sort_list(Network *n);

// Ens busca binàriament un usuari a la llista d'usuaris.
int search_list(Network *n);

#endif //XARXA_SOCIAL_2_NETWORK_H
