//
// Created by Usuari on 27/5/2023.
//

#include "../Headers/3.operate_user.h"

int chooseOperatingUser (Network *net){

    // Lectura d'un usuari.
    printf("\nWhich user do you want to operate with?\n");
    char *name = readString();

    // Si el nom és CEO, entrem en mode de desenvolupador. Després, sortim directament al menú principal.
    if (strcmp(name, "CEO") == 0){
        ceoMenu(net);
        return EXIT;
    }

    // En cas contrari, mirem si l'usuari està a la llista. En cas de no ser trobat, sortim al menú principal.
    int operating_user = searchNetwork (name, net, NAME);

    if (operating_user == USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
        return EXIT;
    }

    // Si aquest usuari de la llista està banejat, sortim del menú, indicant que està banejat.
    if (searchInStringArray (net->user[operating_user].data[NAME], net->banned_user, net->size_banned_users) != STRING_NOT_FOUND) {
        printIsBannedMessage ();
        return EXIT;
    }

    // Si tot és correcte (i el nom no és "CEO" ni està banejat), entrem a operar amb un usuari en concret.

    printf("\nProfile of user %s initialized!\n",net->user[operating_user].data[NAME]);

    return operating_user;
}


void operateUserMenu (Network *net) {

    int idx_operating_user = chooseOperatingUser(net);

    if (idx_operating_user == EXIT){
        return;
    }

    int option = INVALID_OPTION;

    while(option != OPTION_RETURN_MENU){

        printf("\n==== OPERATE USER MENU ====\n\n");

        printf("%d. Manage Requests\n", OPTION_MANAGE_REQUESTS);
        printf("%d. Manage Friends\n", OPTION_MANAGE_FRIENDS);
        printf("%d. Manage Posts\n", OPTION_MANAGE_POSTS);
        printf("%d. Return to principal menu.\n",OPTION_RETURN_MENU);

        option = readInt("Choose your option:\n");

        system("cls");

        if(option == OPTION_MANAGE_REQUESTS){
            manageRequestsMenu(net, idx_operating_user);
        }
        else if(option == OPTION_MANAGE_FRIENDS){
            manageFriendsMenu (net, idx_operating_user);
        }

        else if(option == OPTION_MANAGE_POSTS){
            managePostsMenu (net, idx_operating_user);
        }

        else if(option == OPTION_RETURN_MENU){
            ;//DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }

    }
}
