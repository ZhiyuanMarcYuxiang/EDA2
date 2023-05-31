//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/1.new_user.h"


/// Funcions per a la validació del correu de l'usuari.

// D'un correu donat, mira d'extreure la part del domini, si exiteix.
char *createDomain (char *email) {
    char* user_domain = malloc(DOMAIN_LENGHT*sizeof(char));
    char c;

    // Copia els caràcters del final de l'email a una string nova fins que troba un punt.
    int idx_email = strlen(email)-1;
    int idx_array = 0;
    while (idx_email>= 0 && email[idx_email] != '.'){
        user_domain[idx_array] = email[idx_email];
        idx_array++;
        idx_email--;
    }

    // Reverteix els caràcters copiats.
    for (int i = 0; i<idx_array/2; i++) {
        c = user_domain[i];
        user_domain[i] = user_domain[idx_array-i-1];
        user_domain[idx_array-i-1] = c;
    }

    // Caràcter aturador d'string.
    user_domain[idx_array] = '\0';
    return user_domain;
}

// Comprova si el domini del correu pertany a la llista de dominis.
int checkDomain (char* email) {
    FILE *fp = fopen(DOMAINS_FILE, READING_MODE);

    char* file_domain = malloc(DOMAIN_LENGHT*sizeof(char));
    char* user_domain = createDomain(email);

    while (fscanf(fp, "%s", file_domain) > 0)
        if (strcmp(user_domain, file_domain) == 0)
            return TRUE;
    return FALSE;
}

// Comprova que el correu tingui arroba.
int checkArroba(char* email) {
    for (int i = 0; i<strlen(email); i++)
        if (email[i] == '@')
            return TRUE;
    return FALSE;
}

// Comprova que el correu no estigui a la llista d'usuaris.
int checkNotFound (char* buffer, Network *net, int type){
    if(searchNetwork(buffer, net, type) == USER_NOT_FOUND)
        return TRUE;
    return FALSE;
}

// Lectura del correu validat.
int readEmail (char *buffer, Network *net, int type) {

    int isArroba = checkArroba(buffer);
    if (isArroba == FALSE) printf("E-mail without arroba!\n");

    int isDomain = checkDomain (buffer);
    if (isDomain == FALSE) printf("Invalid domain!\n");

    int isNotFound = checkNotFound (buffer,net,type);
    if (isNotFound == FALSE) printf("Already registered e-mail!\n");

    return isArroba && isDomain && isNotFound;
}

/// Funció per a la validació del nom de l'usuari.

int readName (char *buffer, Network *net, int type){

    if (strlen(buffer) == NULL_SIZE){
        printf("The name must not be empty!\n");
        return FALSE;
    }

    if (searchNetwork(buffer, net, type) != USER_NOT_FOUND){
        printf("Already registered name!\n");
        return FALSE;
    }
    return TRUE;
}

/// Validació de l'edat de l'usuari.

int readAge (char *buffer) {

    if (strlen(buffer) == NULL_SIZE){
        printf("The age must have a value!\n");
        return FALSE;
    }

    int i = 0;
    while (buffer[i] != '\0'){
        if ('0' > buffer[i] || '9' < buffer[i]) {
            printf("Invalid age!\n");
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

/// Validació de la residència de l'usuari.

int readCity (char *buffer) {

    if (strlen(buffer) == NULL_SIZE) {
        printf("The city must not be empty\n!");
        return FALSE;
    }
    return TRUE;
}

/// Validació del nom, l'edat, l'email i el lloc on viu de l'usuari (els hobbies els considerem opcionals).

int check_input (Network *net, char buffer[], int type) {

    switch (type) {
        case NAME:
            // No ha de ser buit i no ha d'estar a la llista d'usuaris.
            return readName (buffer, net, type);
        case AGE:
            // No ha d'estar buit i ha de ser numèric.
            return readAge (buffer);
        case EMAIL:
            // Ha de tenir @, domini vàlid i no ha d'estar a la llista.
            return readEmail (buffer,net,type);
        case CITY:
            // No ha d'estar buit.
            return readCity (buffer);
    }
    return TRUE;
}


/// Impressió de missatges per a l'entrada de valors.

void print_inputMessages(int type){

    printf("Introduce your ");

    int num_hobby = type - HOBBY1;
    if(type > HOBBY1)
        type = HOBBY1;

    switch(type){
        case NAME: printf("name:");
            break;
        case AGE:   printf("age:");
            break;
        case EMAIL: printf("e-mail:");
            break;
        case CITY:  printf("city:");
            break;
        case HOBBY1: printf("hobby %d:", num_hobby+1);

    }
}

/// Lectura per consola dels atributs validats de l'usuari.

char** newUserData (Network net){

    char** data = initData();
    char* attribute;

    for (int i = 0; i < ATTRIBUTES; ++i) {
        do{
            print_inputMessages(i);
            attribute = readString();

        } while (check_input(&net, attribute, i) == FALSE);

        data[i] = copyAttribute (attribute);
    }

    free(attribute);

    return data;
}


/// Funció que crea un nou usuari i li afegeix dades entrades per consola.

void newUser (Network *net){

    int last = net->size;

    net->user = expandUsers (net->user,last);

    net->user[last].data = newUserData(*net);
    net->user[last].post = initPosts();
    net->user[last].size_posts = 0;

    net->size += INCREMENT_SIZE;
    net->order = NOT_ORDERED;

    appendFile (net->user[last],USERS_FILE);


}