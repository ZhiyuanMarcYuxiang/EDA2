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
    int choosed_user = searchNetwork (name, net, NAME);

    if (choosed_user == USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
        return;
    }

    // Si aquest usuari de la llista està banejat, sortim del menú, indicant que està banejat.
    if (searchIfUserIsBanned (net, net->user[choosed_user].data[NAME]) != BANNED_NOT_FOUND) {
        printIsBannedMessage ();
        return;
    }

    // Si tot és correcte (i el nom no és "CEO" ni està banejat), entrem a operar amb un usuari en concret.

    printf("\nProfile of user %s initialized!\n",net->user[choosed_user].data[NAME]);

    int option = INVALID_OPTION;

    while(option != OPTION_RETURN_MENU){

        printf("\n%d. Send friend request.\n", OPTION_SEND_REQUEST);
        printf("%d. Manage the pending requests.\n", OPTION_MANAGE_REQUESTS);
        printf("%d. Make a new post.\n", OPTION_NEW_POST);
        printf("%d. List all of the user posts.\n", OPTION_LIST_POSTS);
        printf("%d. Return to principal menu.\n",OPTION_RETURN_MENU);
        option = readInt("Choose your option:\n");

        if(option == OPTION_SEND_REQUEST){
            printf("\nIntroduce the name of the friend that you want to send request.\n");
            char *string = readString();
            if (strcmp(string, net->user[choosed_user].data[0]) == 0) {
                printf("\nYou can't send friend request to yourself!\n");
            }
            else if (searchNetwork (name, net, NAME) != USER_NOT_FOUND) {
                sendFriendRequest(&net->user[choosed_user], net, string);
            }
            else {
                printf("This user does not exist!");
            }
        }
        else if(option == OPTION_MANAGE_REQUESTS){
            printFriendRequests(&net->user[choosed_user]);
            printf("SIZE:%d\n", net->user[choosed_user].new_size);
            for (int k=0; k < net->user[choosed_user].new_size; k++){
                printf("%d %s",k, net->user[choosed_user].request[k].data[0]);
                handleFriendRequest(&net->user[choosed_user], net, k);
            }
        }
        else if(option == OPTION_NEW_POST){
            newPost (net, choosed_user);
        }
        else if(option == OPTION_LIST_POSTS){
            listPosts (&net->user[choosed_user]);
        }

        else if(option == OPTION_RETURN_MENU){
            ;//DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }

    }
}
