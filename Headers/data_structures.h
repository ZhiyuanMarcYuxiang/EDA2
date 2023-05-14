//
// Created by Usuari on 13/5/2023.
//

#ifndef XARXA_SOCIAL_MEMORY_UTILS_H
#define XARXA_SOCIAL_MEMORY_UTILS_H

#endif //XARXA_SOCIAL_MEMORY_UTILS_H

#define NAME 0
#define AGE 1
#define EMAIL 2
#define CITY 3
#define HOBBIES 4
#define HOBBY1 4
#define HOBBY2 5
#define HOBBY3 6
#define HOBBY4 7
#define HOBBY5 8

#define NULL_SIZE 0      // Per a incrementar el tamany de la llista.


#define NOT_ORDERED (-1) // La llista no té cap tipus d'ordenació actual.

#define ATTRIBUTES 9     // Quantitat d'informacions de l'usuari.
#define BUFFER_SIZE 1024 // Un nombre molt gran, per a un buffer de caràcters (2^10 bytes)

#define MULT_FACTOR 5

#include "utils.h"

/**
 * Estructura d'un usuari (nivell II).
 */
typedef struct {
    char *attr[ATTRIBUTES];  // Array estàtica de strings dinàmiques.
}User;

/**
 * Estructura de la llista d'usuaris (nivell I).
 */
typedef struct {
    User *user;  // Array dinàmica d'usuaris
    int size;    // Quantitat d'usuaris
    int order;   // Ens diu de quina forma està ordenada la llista.
}Network;


// Inicialitza la llista d'usuaris.
Network* initNetwork ();

// Eliminem tot les al·locacions manuals de memòria de l'estructura .
void clearNetwork (Network *network);

// Ens serveix per a expandir la memòria dinàmica de l'array d'usuaris.
User * expandUsers (User *user, int real_size);

// Funció que ens inicialitza una string dinàmica i se li copien els caràcters d'una altra string.
char* init_and_copy (char origin[]);

char* initAttribute (int size);