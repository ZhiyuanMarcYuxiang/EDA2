//
// Created by Usuari on 13/5/2023.
//

#ifndef XARXA_SOCIAL_MEMORY_UTILS_H
#define XARXA_SOCIAL_MEMORY_UTILS_H

#define ATTRIBUTES (9)

#define NAME (0)
#define AGE (1)
#define EMAIL (2)
#define CITY (3)
#define HOBBY1 (4)
#define HOBBY2 (5)
#define HOBBY3 (6)
#define HOBBY4 (7)
#define HOBBY5 (8)

#define NULL_SIZE (0)
#define ONE_SIZE (1)

#define INCREMENT_SIZE (1)
#define MULTIPLICATIVE_FACTOR (5)

#define NOT_ORDERED (-1)

#define BUFFER_SIZE (1024)
#define END_CHARACTER (1)

#define RESET 0
#define SET_ZERO 0


#define LESSTHAN (-1)
#define GREATERTHAN 1

#include "option_utils.h"

/// Estructura d'un usuari.

typedef struct{
    char* key;
    int value;
} Element;

typedef struct{
    Element* elements;
    int count;
    int size;
} Dict;

typedef struct User{
    char** data;

    char** post;
    int posts_size;

    struct User* request;
    int old_requests;
    int new_size;

    struct User* friend;
    int size_friends;
}User;


/// Estructura de la xarxa.

typedef struct {
    User* user;
    int users_size;
    int users_order;
    Dict* dictionary;
    char **banned_user;
}Network;



char* initAttribute (int size);

char** initData();

char** initPosts();

User* initUser();

Dict* init_dictionary();

Network* initNetwork ();


User * expandUsers (User *user, int current_size);

char ** expandPosts (char** post, int current_size);

Dict* expandElements (Dict *dict, int current_size);

void clearUsers (User *user, int users_size);

void clearDictionary (Dict* dictionary);

void clearNetwork (Network *network);

char* copyString (char *origin);

char** copyStringArray (char **origin, int size);

void copyUser (User* copy, User* origin);

int compAttribute (User userA, User userB, int type);

char* readString();

#endif //XARXA_SOCIAL_MEMORY_UTILS_H