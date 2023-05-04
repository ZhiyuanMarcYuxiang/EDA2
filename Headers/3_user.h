//
// Created by Usuari on 26/4/2023.
//

#ifndef XARXA_SOCIAL_3_USER_H
#define XARXA_SOCIAL_3_USER_H

#define MAX_EMAIL 50
#define MAX_HOME 20
#define MAX_NAME 5

#define USER_NOT_FOUND (-1)

#include "4_hobbies.h"

/**
 * Estructura d'un usuari (nivell II).
 */
typedef struct{
    char name[MAX_NAME];       // Nom
    int age;                   // Edat
    char email[MAX_EMAIL];     // Correu
    char home[MAX_HOME];       // Lloc on viu
    Hobbies hobbies[QUANTITY]; // Llista estàtica preferències
}User;

// a) Nou usuari
//      Inscriu un nou usuari a l'estructura de dades dels usuaris.
void new_user_data(User *user, int size);

void read_age(int *num);
void read_name(char* user_name, User* user, int size);
void read_email(char *email);
// b) Llista d'usuaris
//      Imprimeix tots els usuaris que hi ha inscrits.
void print_user(User user);

// Auxiliar al "binary_search": cancel·la la cerca quan l'usuari és més petit que el primer de la llista
// o quan és més gran que l'últim usuari.
int user_fenced_in_list(char user_to_search[], User* user, int size);

// Funcions que serveixen per a buscar un usuari (per nom) dins l'estructura d'usuaris.
// La cerca binària utilitza "merge_sort", ja que ha d'estar ordenada la llista per a aplicar el respectiu algoritme-
int binary_search_users(char user_to_search[], User* user, int size);

// Funcions d'ordenació de llista de forma combinada i recursiva.
// La funció auxiliar és "merge", que combina dues llistes de forma ordenada.
User* merge_sort(User *user, int size);
User* merge(User* userA, int sizeA, User* userB, int sizeB);

// Copia per valor totes les dades d'un usuari a un altre.
void copy_user_data(User *copy,User *origin);

// Esborra el primer usuari de l'array.
void delete_first_user(User *user, int size);

#endif //XARXA_SOCIAL_3_USER_H

