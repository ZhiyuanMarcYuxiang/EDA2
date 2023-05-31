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
    net->users_size = NULL_SIZE;
    net->users_order = NOT_ORDERED;
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

void clearStringArray (char** string_array, int size){

    for (int i = 0; i < size; ++i) {
        free(string_array[i]);
    }

    free(string_array);
}

void clearUsers (User *user, int users_size){

    for (int i = 0; i < users_size; ++i) {

        clearStringArray (user[i].data, ATTRIBUTES);
        clearStringArray (user[i].post, user[i].posts_size);
    }
    free(user);
}

void clearNetwork (Network *net){

    clearUsers (net->user, net->users_size);
    free(net);
}

/// Funcions de còpia de dades.

char* copyString (char *origin){

    int length = strlen(origin) + END_CHARACTER;

    char *copy = initAttribute (length * sizeof(char));
    strcpy (copy, origin);
    return copy;
}


char** copyStringArray (char **origin, int size){

    char **copy = initData();

    for (int i = 0; i < size; ++i) {
        copy[i] = copyString(origin[i]);
    }
    return copy;
}

void copyUser (User* copy, User* origin){

    copy->data = copyStringArray(origin->data, ATTRIBUTES);

    copy->post = copyStringArray(origin->post, origin->posts_size);
    copy->posts_size = origin->posts_size;
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

