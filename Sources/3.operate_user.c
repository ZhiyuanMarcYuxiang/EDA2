//
// Created by Usuari on 27/5/2023.
//

#include "../Headers/3.operate_user.h"

void operateUserMenu (Network *net) {

    // Lectura d'un usuari.
    printf("\nWhich user do you want to operate with?\n");
    char *name = readString();

    // Si el nom és CEO, entrem en mode de desenvolupador. Després, sortim directament al menú principal.
    if ( strcmp(name, "CEO") == 0){
        ceoMenu(net);
        return;
    }

    // En cas contrari, mirem si l'usuari està a la llista. En cas de no ser trobat, sortim al menú principal.
    int operating_user = searchNetwork (name, net, NAME);

    if (operating_user == USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
        return;
    }

    // Si aquest usuari de la llista està banejat, sortim del menú, indicant que està banejat.
    if (searchInStringArray (net->banned_user, net->size_banned_users, net->user[operating_user].data[NAME]) != STRING_NOT_FOUND) {
        printIsBannedMessage ();
        return;
    }

    // Si tot és correcte (i el nom no és "CEO" ni està banejat), entrem a operar amb un usuari en concret.

    printf("\nProfile of user %s initialized!\n",net->user[operating_user].data[NAME]);

    int option = INVALID_OPTION;

    while(option != OPTION_RETURN_MENU){

        printf("\n%d. Send friend request.\n", OPTION_SEND_REQUEST);
        printf("%d. Manage the pending requests.\n", OPTION_MANAGE_REQUESTS);
        printf("%d. Make a new post.\n", OPTION_NEW_POST);
        printf("%d. List all of my posts.\n", OPTION_LIST_POSTS);
        printf("%d. See my friend list.\n", OPTION_FRIEND_LIST);
        printf("%d. See friend's posts.\n", OPTION_FRIEND_POST);
        printf("%d. Remove friend.\n", OPTION_REMOVE_FRIEND);
        printf("%d. Send friend request to random user\n", OPTION_SEARCH_RANDOM_USERS);
        printf("%d. Return to principal menu.\n",OPTION_RETURN_MENU);
        option = readInt("Choose your option:\n");

        system("cls");

        if(option == OPTION_SEND_REQUEST){
            // L'usuari tria qui vol enviar solicitud d'amistat
            sendFriendRequest(net,&net->user[operating_user], -1);
        }
        else if(option == OPTION_MANAGE_REQUESTS){
            manageRequests  (net, &net->user[operating_user]);
        }

        else if(option == OPTION_NEW_POST){
            newPost (net, operating_user);
        }
        else if(option == OPTION_LIST_POSTS){
            // who = 0 perquè volem imprimir els posts de l'usuari que hem inicialitzat
            // i no els posts dels seus amics
            listPosts (&net->user[operating_user], 0);
        }
        else if(option == OPTION_FRIEND_LIST) {
            listFriends(&net->user[operating_user]);
        }
        else if(option == OPTION_FRIEND_POST) {
            listfriendPosts(net, &net->user[operating_user]);
        }
        else if(option == OPTION_REMOVE_FRIEND) {
            removeFriend(&net->user[operating_user]);
        }
        else if(option == OPTION_SEARCH_RANDOM_USERS) {
            searchRandomUser(net, &net->user[operating_user]);
        }
        else if(option == OPTION_RETURN_MENU){
            ;//DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }

    }
}
