//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/31.send_request.h"

// Aquí el que podria fer seria, en primer lloc, aplicar un algoritme de cerca per a mirar si l'usuari que volem buscar
// existeix. Per exemple, podríem aplicar "chooseUser".

// Si l'usuari existeix, accedim a user->request d'aquell usuari i hi col·loquem la informació nostra.

// Hem d'anar fent real·locacions per a ampliar els requests d'aquell usuari en particular.


void sendFriendRequest (Network* net, User *operating_user) {

    // Mida dels nostres amics i el nostre nom.
    int size_friends = operating_user->size_friends;
    char *operating_user_name = operating_user->data[NAME];

    // Missatge per a enviar la sol·licitud.
    printf("\nIntroduce the name of the user that you want to send a friend request.\n");
    char *requested_user_name = readString();

    // Condicions per enviar la sol·licitud:

    // 1) Mirem que no coindeixi aquest nom d'usuari a sol·licitar amistat amb el teu propi nom.
    if (strcmp(requested_user_name, operating_user_name) == 0) {
        printf("\nYou can't send friend request to yourself!\n");
        return;
    }

    // 2) Mirem que aquest usuari existeixi a la llista d'usuaris.
    int idx_requested_user = searchNetwork(requested_user_name,net,NAME);

    if (idx_requested_user == USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
        return;
    }

    // 3) Mirem que l'usuari no estigui a la llista d'amics teus. Fem una cerca seqüencial.
    for (int i = 0; i < size_friends; i++) {
        if (strcmp(requested_user_name, operating_user->friend[i]) == 0) {
            printf("%s and you are already friends!",requested_user_name);
            return;
        }
    }

    // Si tot es compleix:

    int last = net->user[idx_requested_user].size_requests;

    net->user[idx_requested_user].request = expandStringArray (net->user[idx_requested_user].request,last);
    net->user[idx_requested_user].size_requests += INCREMENT_SIZE;

    // La llista de sol·licituds de l'usuari que volem enviar sol·licitud <-- la informació nostra.
    net->user[idx_requested_user].request[last] = copyString(operating_user_name);

    printf("You have send a friend request to %s successfully.\n", net->user[idx_requested_user].data[NAME]);
}


