//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/32.manage_requests.h"

// Aquí jo el que faria seria que l'usuari amb el qual estem operant pugui anar veient els noms dels usuaris que han
// enviat sol·licituds en forma de llista. A més, si vol desplegar la informació completa (Nom, Edat, Ciutat i Hobbies)
// d'un usuari en particular ho pot demanar.

// Poden passar dues coses, que l'usuari accepti la sol·licitud, la qual cosa significa actualitzar la llista
// d'user->friends i buidar la d'user->requests, o que no l'accepti, que simplement no farem i passarem a analitzar
// la següent sol·licitud.

void manageRequests (Network *net){
    ;
}

void respondToFriendRequest(User* currentUser, Network* network, int index, int accept) {
    if (currentUser == NULL || index < currentUser->old_requests || index >= currentUser->new_size) {
        printf("Invalid input.\n");
        return;
    }

    User* requester = &currentUser->request[index];

    if (accept == ACCEPT) {
        currentUser->friend = realloc(currentUser->friend, (currentUser->size_friends + 1) * sizeof(User));
        if (currentUser->friend == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        currentUser->size_friends++;
        currentUser->friend[currentUser->size_friends] = *requester;
        printf("Accepted friend request from %s.\n", requester->data[0]);

        // Also add the current user to the requester's friend list
        for (int i = 0; i < network->users_size; i++) {
            if (strcmp(network->user[i].data[0], requester->data[0]) == 0) {
                network->user[i].friend = realloc(network->user[i].friend, (network->user[i].size_friends + 1) * sizeof(User));
                if (network->user[i].friend == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }
                network->user[i].size_friends++;
                network->user[i].friend[network->user[i].size_friends] = *currentUser;
                break;
            }
        }
    } else {
        printf("Rejected friend request from %s.\n", requester->data[0]);
    }

    // Shift remaining requests down
    for (int i = index; i < currentUser->new_size - 1; i++) {
        currentUser->request[i] = currentUser->request[i + 1];
    }
    currentUser->new_size--;
}

void handleFriendRequest(User* currentUser, Network* network, int index) {
    int accept = 0;
    printf("Hi I'm %s! Do you want to be my friend? (1 for YES, -1 for NO)\n", currentUser->request[index].data[0]);
    scanf("%d", &accept);

    while (accept != ACCEPT && accept != NOTACCEPT) {
        printf("Invalid option. Please enter 1 to accept the friend request or -1 to reject it.\n");
        scanf("%d", &accept);
    }

    respondToFriendRequest(currentUser, network, index, accept);
}


void removeFriend(User* currentUser, User* friendToRemove) {
    if (currentUser == NULL || friendToRemove == NULL) {
        printf("Invalid input.\n");
        return;
    }

    // Find and remove friendToRemove from currentUser's friend list
    for (int i = 0; i < currentUser->size_friends; i++) {
        if (strcmp(currentUser->friend[i].data[0], friendToRemove->data[0]) == 0) {
            for (int j = i; j < currentUser->size_friends - 1; j++) {
                currentUser->friend[j] = currentUser->friend[j + 1];
            }
            currentUser->size_friends--;
            currentUser->friend = realloc(currentUser->friend, currentUser->size_friends * sizeof(User));
            if (currentUser->friend == NULL && currentUser->size_friends != 0) {
                printf("Memory reallocation failed.\n");
                return;
            }
            break;
        }
    }

    // Find and remove currentUser from friendToRemove's friend list
    for (int i = 0; i < friendToRemove->size_friends; i++) {
        if (strcmp(friendToRemove->friend[i].data[0], currentUser->data[0]) == 0) {
            for (int j = i; j < friendToRemove->size_friends - 1; j++) {
                friendToRemove->friend[j] = friendToRemove->friend[j + 1];
            }
            friendToRemove->size_friends--;
            friendToRemove->friend = realloc(friendToRemove->friend, friendToRemove->size_friends * sizeof(User));
            if (friendToRemove->friend == NULL && friendToRemove->size_friends != 0) {
                printf("Memory reallocation failed.\n");
                return;
            }
            break;
        }
    }
}
