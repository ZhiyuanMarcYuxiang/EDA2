//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/31.send_request.h"

// Aquí el que podria fer seria, en primer lloc, aplicar un algoritme de cerca per a mirar si l'usuari que volem buscar
// existeix. Per exemple, podríem aplicar "chooseUser".

// Si l'usuari existeix, accedim a user->request d'aquell usuari i hi col·loquem la informació nostra.

// Hem d'anar fent real·locacions per a ampliar els requests d'aquell usuari en particular.


void sendFriendRequest (Network* net, User *operating_user, int random_user_idx) {
    int idx_requested_user;

    // Mida dels nostres amics i el nostre nom.
    int size_friends = operating_user->size_friends;
    char *operating_user_name = operating_user->data[NAME];

    //Si random_user_idx és igual a -1, vol dir que l'usuari és qui tria la persona qui vol afegir
    if (random_user_idx == -1) {
        // Missatge per a enviar la sol·licitud.
        printf("\nIntroduce the name of the user that you want to send a friend request.\n");
        char *requested_user_name = readString();

        // Condicions per enviar la sol·licitud:

        // 1) Mirem que no coindeixi aquest nom d'usuari a sol·licitar amistat amb el teu propi nom.
        if (strcmp(requested_user_name, operating_user_name) == 0) {
            printf("You can't send friend request to yourself!\n");
            return;
        }

        // 2) Mirem que aquest usuari existeixi a la llista d'usuaris.
        idx_requested_user = searchNetwork(requested_user_name, net, NAME);

        if (idx_requested_user == USER_NOT_FOUND) {
            printf("\nThe user was not found!\n");
            return;
        }

        // 3) Mirem que l'usuari no estigui a la llista d'amics teus. Fem una cerca seqüencial.
        for (int i = 0; i < size_friends; i++) {
            if (strcmp(requested_user_name, operating_user->friend[i]) == 0) {
                printf("%s and you are already friends!\n", requested_user_name);
                return;
            }
        }
    }
    // Això vol dir que l'usuari ha enviat una solicitud d'amistat a una persona desconegut
    // que el sistema ha trobat en la Xarxa Social
    else {
        idx_requested_user = random_user_idx;
    }

    // Si tot es compleix:

    int last = net->user[idx_requested_user].size_requests;

    net->user[idx_requested_user].request = expandStringArray (net->user[idx_requested_user].request,last);
    // La llista de sol·licituds de l'usuari que volem enviar sol·licitud <-- la informació nostra.
    net->user[idx_requested_user].request[last] = copyString(operating_user_name);
    net->user[idx_requested_user].size_requests += INCREMENT_SIZE;



    printf("You have send a friend request to %s successfully.\n", net->user[idx_requested_user].data[NAME]);
}

// Funcions de Stack

void push (Stack* stack, int random_user_idx) {
    stack->array[stack->top] = random_user_idx;
    stack->top += INCREMENT_SIZE;
}

void pop(Stack* stack) {
    stack->top -= INCREMENT_SIZE;
}

int top (Stack* stack) {
    return stack->array[stack->top-1];
}

Stack* fullStack (Network* net, User* operating_user) {
    Stack* stack = initStack();
    int friend_idx;
    int random_idx;
    User random_user;
    for (int i = 0; i<3; i++) {
        friend_idx = 0;
        printf("\nSearching...\n");
        while (friend_idx != STRING_NOT_FOUND) {
            random_idx = (rand()%net->size_users);
            random_user = net->user[random_idx];
            friend_idx = searchInStringArray(operating_user->friend, operating_user->size_friends,
                                             random_user.data[NAME]);
        }
        printf("IDX: %d", random_idx);
        push(stack, random_idx);
    }
    return stack;
}

// Funció que implementa una pila i simula Tinder
void searchRandomUser(Network* net, User* operating_user) {
    Stack* stack = fullStack(net, operating_user);
    int i = 0;
    int exit = FALSE;
    int random_user_idx;
    int option;

    while (i<3 && exit == FALSE) {
        printf("\nHello %d!\n", stack->top);
        random_user_idx = top(stack);
        printf("%s is not your friend. Do you want to send him/her a friend request?", net->user[random_user_idx].data[NAME]);
        printf("[1 for YES, 0 for NO, -1 for RETURN]\n");

        option = readInt("\n") ;

        if (option == -1) {
            return;
        }
        else if (option == ACCEPT){
            sendFriendRequest(net, operating_user, random_user_idx);
        }else{
            printf("Operation canceled!\n");
        }
        pop(stack);
        i++;
    }
}


