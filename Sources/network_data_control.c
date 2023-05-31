//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/network_data_control.h"

/// Funcions per a inicialitzar dades.

char* initAttribute (int size){
    return malloc(size * sizeof(char));
}

char** initPosts (){
    return malloc(sizeof(char *));
}

char** initData (){
    return malloc(ATTRIBUTES * sizeof(char *));
}

User* initUser (){
    return malloc(sizeof(User));
}

Network* initNetwork (){
    // Inicialitza una llista dinàmica d'usuaris.
    Network *net = malloc(sizeof(Network));
    net->size = NULL_SIZE;
    net->order = NOT_ORDERED;
    net->user = initUser();
    return net;
}

/// Funcions d'expansió de dades.

User* expandUsers (User *user, int current_size){

    // Quan la mida la llista d'usuaris té uns certs valors, l'ampliem.
    if ((current_size % MULTIPLICATIVE_FACTOR) == 0) {

        int real_size = current_size + MULTIPLICATIVE_FACTOR;
        user = realloc(user, real_size * sizeof(User));
    }
    return user;
}

char** expandPosts (char **post, int current_size){

    if ((current_size % MULTIPLICATIVE_FACTOR) == 0) {

        int real_size = current_size + MULTIPLICATIVE_FACTOR;
        post = realloc(post, real_size * sizeof(char *));
    }
    return post;
}

/// Funcions d'alliberament de dades.

void clearAttribute (char* attribute){
    free(attribute);
}

void clearData (char** data){
    for (int i = 0; i < ATTRIBUTES; ++i) {
        clearAttribute(data[i]);
    }
    free(data);
}


void clearUsers (User *user, int quanity_users){
    for (int i = 0; i < quanity_users; ++i) {
        clearData(user[i].data);
    }
    free(user);
}

void clearNetwork (Network *net){
    clearUsers (net->user, net->size);
    free(net);
}

/// Funcions de còpia de dades.

char* copyAttribute (char *origin){

    int length = strlen(origin)+END_CHARACTER;

    char *copy = initAttribute (length * sizeof(char));
    strcpy (copy, origin);
    return copy;
}


char** copyData (char **origin){

    char **copy = initData();
    for (int i = 0; i < ATTRIBUTES; ++i) {
        copy[i] = copyAttribute (origin[i]);
    }
    return copy;
}

void copyUser (User* copy, User* origin){
    copy->data = copyData (origin->data);
}

/// Funcions de comparació de dades

int compAttribute (User userA, User userB, int type){
    return strcmp(userA.data[type], userB.data[type]);
}


/// Lectura d'strings mitjançant un buffer i inicialització dinàmica d'un atribut.

char* readString() {

    char buffer[BUFFER_SIZE];

    fgets (buffer, BUFFER_SIZE, stdin);

    int length = strlen(buffer);
    buffer[length -1] = '\0';

    char* string = malloc(length * sizeof(char));
    strcpy(string, buffer);

    return string;
}

