//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/32.manage_requests.h"

// Aquí jo el que faria seria que l'usuari amb el qual estem operant pugui anar veient els noms dels usuaris que han
// enviat sol·licituds en forma de llista. A més, si vol desplegar la informació completa (Nom, Edat, Ciutat i Hobbies)
// d'un usuari en particular ho pot demanar.

// Poden passar dues coses
// 1) que l'usuari accepti la sol·licitud, la qual cosa significa actualitzar la llista d'user->friends i buidar la d'user->requests
// 2) que no l'accepti, que simplement no farem i passarem a analitzar la següent sol·licitud.

#define FIRST 0

void listRequests (char **request,int size_request) {

    printf("\nYou have %d requests.\n", size_request);

    if(size_request > ONE_SIZE){
        printf("\nWe will list all the requests from oldest to newest.\n\n");
    }

    for (int i = 0; i < size_request; i++)
        printf("%d. %s\n", i+1, request[i]);
}

void acceptUser (Network* net, User *operating_user, char* request_user) {

    /// Your new Friend X <- Your request form X

    // Copiem l'usuari que ens ha enviat la sol·licitud a la nostra estructura d'amics.
    // Com que les requests són una cua, llegim del primer a l'últim.

    int last = operating_user->size_friends;

    operating_user->friend = expandStringArray (operating_user->friend,last);
    operating_user->friend[last] = copyString(request_user);
    operating_user->size_friends += INCREMENT_SIZE;

    /// X has you as new friend, too. L'usuari que ens envia la sol·licitud sempre sabem que estarà a la llista.

    int request_user_idx = searchNetwork(request_user,net,NAME);

    int last2 = net->user[request_user_idx].size_friends;

    net->user[request_user_idx].friend = expandStringArray (net->user[request_user_idx].friend,last);
    net->user[request_user_idx].friend[last2] = copyString(operating_user->data[NAME]);
    net->user[request_user_idx].size_friends += INCREMENT_SIZE;

    printf("Request accepted. You have %s as new friend.\n",operating_user->friend[last]);
}

void manageRequests  (Network* net, User *operating_user) {

    int size_requests = operating_user->size_requests;
    char ** request = operating_user->request;

    // Imprimim les sol·licituds que ens han enviat.
    if (size_requests == NULL_SIZE){
        printf("\nYou don't have any requests.\n");
        return;
    }
    listRequests (request, size_requests);

    printf("\nWe are going to manage the requests.\n");
    printf("[1 for YES, 0 for NO]\n\n");

    int option = INVALID_OPTION;

    // Triem si acceptar o no les sol·licituds.
    for (int i=0; i < size_requests; i++){

        printf("Hi I'm %s! Do you want to be my friend?\n", request[0]);

        option = readInt ("\n");

        if (option == ACCEPT){
            acceptUser(net,operating_user,request[0]);

        }else{
            printf("Request denied\n");
        }

        // Esborrem la primera sol·licitud, ja que és una cua. Request Deleted.
        deleteString_InArray(operating_user->request,FIRST,operating_user->size_requests);
        operating_user->size_requests -= (INCREMENT_SIZE);

    }
}


void removeFriend(User *operating_user){

    // Triem l'usuari a desbanejar pel seu nom. Mirem que existeixi a la llista.

    printf("\nWhich friend do you want to remove?\n");
    char *name = readString();

    int friend_idx = searchInStringArray (operating_user->friend, operating_user->size_friends, name);

    if (friend_idx == STRING_NOT_FOUND){
        printf("\nThe friend user was not found!\n");
        return;
    }

    int size = operating_user->size_friends;

    // En cas de trobar l'usuari banejat, ens el borra de la llista dels banejats.
    deleteString_InArray(operating_user->friend, friend_idx, size);

    operating_user->size_friends += (-INCREMENT_SIZE);
}

