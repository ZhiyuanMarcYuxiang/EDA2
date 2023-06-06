//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/31.send_request.h"

// Aquí el que podria fer seria, en primer lloc, aplicar un algoritme de cerca per a mirar si l'usuari que volem buscar
// existeix. Per exemple, podríem aplicar "chooseUser".

// Si l'usuari existeix, accedim a user->request d'aquell usuari i hi col·loquem la informació de l'usuari
// d'on volem enviar la sol·licitud.

// Hem d'anar fent real·locacions per a ampliar els requests d'aquell usuari en particular.

void sendRequest (Network *net){
    ;
}

void printFriendRequests(User* user) {
    if (user == NULL) {
        printf("Invalid user.\n");
        return;
    }
    if (user->old_requests == user->new_size) {
        printf("No new friend requests.\n");
        return;
    }
    printf("New friend requests:\n");
    for (int i = user->old_requests; i < user->new_size; i++) {
        printf("Request from %s\n", user->request[i].data[0]);  // Assuming the first element in data is username
    }
}


User* sendFriendRequest(User* currentUser, Network* network, const char* friendName) {
    if (currentUser == NULL || network == NULL || friendName == NULL) {
        printf("Invalid input.\n");
        return NULL;
    }
    for (int j = 0; j < currentUser->size_friends; j++) {
        if (strcmp(currentUser->friend[j].data[0], friendName) == 0) {
            printf("You already are his friend!");
            return NULL;
        }
    }
    User* friend = NULL;
    for (int i = 0; i < network->users_size; i++) {
        if (strcmp(network->user[i].data[0], friendName) == 0) {
            friend = &network->user[i];
            break;
        }
    }
    if (friend == NULL) {
        printf("User not found.\n");
        return NULL;
    }

    friend->request = realloc(friend->request, (friend->new_size + 1) * sizeof(User));
    if (friend->request == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    friend->request[friend->new_size++] = *currentUser;
    printf("Friend request sent to %s.\n", friendName);
    return friend;
}


