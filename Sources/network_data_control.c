//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/network_data_control.h"

/// Funcions per a inicialitzar dades.

Stack* initStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = 0;
    return stack;
}

char* initString (int size){
    return malloc(size * sizeof(char));
}

char** initStringArray (int size){
    return malloc(size *  sizeof(char *) );
}

User* initUser (){
    return malloc(sizeof(User));
}

Dict* init_dictionary() {
    Dict* dictionary = (Dict*) malloc(sizeof(Dict));
    dictionary->current_element = SET_ZERO;
    dictionary->element = (Element*) malloc(MAX_DICTIONARY_ELEMENTS * sizeof(Element));
    for (int i = 0; i < MAX_DICTIONARY_ELEMENTS; ++i) {
        dictionary->element[i].key = "";
        dictionary->element[i].value = SET_ZERO;
    }

    return dictionary;
}

Network* initNetwork (){
    // Inicialitza una llista dinàmica d'usuaris.
    Network *net = malloc(sizeof(Network));
    net->size_users = NULL_SIZE;
    net->order_users = NOT_ORDERED;

    // Inicialitzem el diccionari per a fer el top de paraules.
    net->dictionary  = init_dictionary();
    net->user = initUser();

    // Tant el post com el banned_user son una llista de string
    net->banned_user = initStringArray(ONE_SIZE);
    net->size_banned_users = NULL_SIZE;

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

char** expandStringArray (char **stringArray, int current_size){

    if ((current_size % MULTIPLICATIVE_FACTOR) == 0) {

        int real_size = current_size + MULTIPLICATIVE_FACTOR;
        stringArray = realloc(stringArray, real_size * sizeof(char *));
    }
    return stringArray;
}


/// Esborrar un element.

void deleteString_InArray(char **string_array, int size, int position_to_delete){

    for (int i = position_to_delete; i < size-1; ++i) {
        string_array[i] = copyString(string_array[i + 1]);
    }
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
        clearStringArray (user[i].post, user[i].size_posts);
        clearStringArray (user[i].friend,user[i].size_friends);
        clearStringArray (user[i].request,user[i].size_requests);
    }
    free(user);
}

void clearElements(Element* element, int current_elements) {
    for (int i = 0; i<current_elements; i++) {
        free(element[i].key);
    }
    free(element);
}

void clearDictionary (Dict* dictionary) {
    clearElements(dictionary->element, dictionary->current_element);
    free(dictionary);
}

void clearNetwork (Network *net){
    clearDictionary (net->dictionary);
    clearUsers (net->user, net->size_users);
    free(net);
}

/// Funcions de còpia de dades.

char* copyString (char *origin){

    int length = strlen(origin) + END_CHARACTER;

    char *copy = initString(length * sizeof(char));
    strcpy (copy, origin);
    return copy;
}


char** copyStringArray (char **origin, int size){

    char **copy = initStringArray(size);

    for (int i = 0; i < size; ++i) {
        copy[i] = copyString(origin[i]);
    }
    return copy;
}

void copyUser (User* copy, User* origin){

    copy->data = copyStringArray(origin->data, ATTRIBUTES);

    copy->post = copyStringArray(origin->post, origin->size_posts);
    copy->size_posts = origin->size_posts;

    copy->request = copyStringArray(origin->request, origin->size_requests);
    copy->size_requests = origin->size_requests;

    copy->friend = copyStringArray(origin->friend, origin->size_friends);
    copy->size_friends = origin->size_friends;

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

void printSpaces (char previous_string[], int max_length){
    int spaces = max_length - strlen(previous_string);
    for (int j = 0; j < spaces; ++j) {
        printf(" ");
    }
}

/// Funcions específiques d'una pila.


void push (Stack* stack, int random_user_idx) {
    stack->array[stack->top] = random_user_idx;
    stack->top += INCREMENT_SIZE;
}

void pop (Stack* stack) {
    stack->top += DECREMENT_SIZE;
}

int top (Stack* stack) {
    return stack->array[stack->top-1];
}
