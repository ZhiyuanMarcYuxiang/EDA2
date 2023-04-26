//
// Created by Usuari on 26/4/2023.
//

#ifndef XARXA_SOCIAL_USER_H
#define XARXA_SOCIAL_USER_H

#define MAX_HOBBY 20
#define MAX_EMAIL 30
#define MAX_HOME 20
#define MAX_NAME 16
#define MIN_STRING 1
#define QUANTITY 5

#include "utils.h"

// Subestructura per a desar-hi els gustos de l'usuari.
typedef struct{
    char *hobby[MAX_HOBBY];
}Hobbies;

// Estructura dels Usuaris.
typedef struct{
    char *name[MAX_NAME];       // Nom
    int age;                    // Edat
    char *email[MAX_EMAIL];     // Correu
    char * home[MAX_HOME];      // Lloc on viu
    Hobbies *hobbies[QUANTITY]; // Preferències
}User;

typedef struct{
    User *user;
    int size;
}ArrayUsers;


// a) Nou usuari
//      Inscriu un nou usuari a l'estructura de dades dels usuaris.
void new_data(User *user);

// b) Llista d'usuaris
//      Imprimeix tots els usuaris que hi ha inscrits.
void print_user(User *user);

// c) Operar amb un usuari
//      1) Enviar sol·liticituds d'amistat
//      2) Gestionar sol·licituds
//      3) Nova publicació
//      4) Llista de publicacions
//      5) Tornar al menú principal
void operate_user();

#endif //XARXA_SOCIAL_USER_H

