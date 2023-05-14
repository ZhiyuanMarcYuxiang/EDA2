//
// Created by Usuari on 13/5/2023.
//

#ifndef XARXA_SOCIAL_NEW_USER_H
#define XARXA_SOCIAL_NEW_USER_H

#endif //XARXA_SOCIAL_NEW_USER_H

#define INCREMENT_SIZE 1

#include "file_control.h"

// a) Nou usuari
//      Inscriu un nou usuari a l'estructura de dades dels usuaris.
void newUser_Network (Network *n);

void newUser (User *user, int size);

void readName (char* user_name, User* user, int size);

void readEmail ();

void readAge ();

// Són els missatges que l'usuari rep quan ha d'introduir els atributs per consola.
void input_messages (int iteration);