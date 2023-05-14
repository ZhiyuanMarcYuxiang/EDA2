//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/new_user.h"
#include "../Headers/file_control.h"

/**
 * @param net: Llista d'usuaris inicialitzada.
 * Funció que crea un nou usuari i li afegeix dades entrades per consola. Mida de
 */
void newUser_Network (Network *net){
    net->size += INCREMENT_SIZE;
    net->order = NOT_ORDERED;
    net->user = expandUsers (net->user,net->size);
    newUser (net->user, net->size);
}

/**
 * @param user: Llista d'usuaris.
 * Llegim dades per consola i les introdueix en un usuari.
 */
void newUser (User *user, int size){

    // String auxiliar o "buffer" per a desar l'entrada de l'usuari.
    char buffer[BUFFER_SIZE];

    for (int i = 0; i < ATTRIBUTES; ++i) {

        // Missatge perquè l'usuari introdueixi un tipus determinat.
        input_messages(i);

        // Llegim una string per consola i la desem a l'string auxiliar.
        fgets (buffer, BUFFER_SIZE, stdin);

        // Eliminem el caràcter '\n' que per defecte es col·loca al buff i hi col·loquem un caràcter finalitzador
        // d'string.
        int length = strlen(buffer);
        buffer[length -1] = '\0';

        // Reservem memòria i copiem el buffer a la llista d'atributs de l'últim.
        user[size-1].attr[i] = init_and_copy(buffer);
    }
    appendFile (user[size-1],"../Files/20users.csv");
}


void input_messages(int iteration){
    printf("Introduce your ");
    int num_hobby = iteration - 3;
    if(iteration>4)
        iteration = 4;
    switch(iteration){
        case NAME: printf("name:");
            break;
        case AGE:   printf("age:");
            break;
        case EMAIL: printf("e-mail:");
            break;
        case CITY:  printf("city:");
            break;
        case HOBBIES: printf("hobby %d:", num_hobby);
    }
}

/**
 * @param name: Nom de l'usuari que s'inicialitzarà.
 * @param user: Llista d'usuaris.
 * @param size: Mida màxima de la llista d'usuaris.
 * Demana per consola un nom d'usuari verificant que aquest no estigui ja a la llista i tingui una longitud
 * màxima de caràcters.
 */
void read_name (Network *net, int size){
    // Declarem un usuari temporal per a desar-hi la informació llegida.
    char buffer[BUFFER_SIZE];
    fgets (buffer, BUFFER_SIZE, stdin);
    if (size>1) {
        while (searchNetwork (buffer, net, NAME) != USER_NOT_FOUND){
            printf("Already registered name!\n");
            printf("Enter a new name:");
            fgets (buffer, BUFFER_SIZE, stdin);
        }
    }
    strcpy (buffer, buffer);
}
