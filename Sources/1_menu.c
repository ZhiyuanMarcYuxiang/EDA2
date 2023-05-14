//
// Created by Marc on 26/4/2023.
//

#include "../Headers/1_menu.h"
#include "../Headers/utils.h"
#include "../Headers/new_user.h"
#include "../Headers/print_network.h"

// MARC BOSCH BRANCH


/**
 * @param n: Llista d'usuaris inicialitzada i necessàriament ordenada.
 * Submenú que ens mostra quatre opcions específiques d'un usuari si l'usuari està registrat.
 */
void operateUser (User *user) {

    printf("\nProfile of user %s initialized!\n",user->attr[NAME]);

    int option = INVALID_OPTION;

    while(option!=OPTION_RETURN_MENU){

        printf("\n%d. Send friend request.\n",OPTION_REQUEST);
        printf("%d. Manage the pending requests.\n",OPTION_MANAGE);
        printf("%d. Make a new post.\n",OPTION_POST);
        printf("%d. List all of the user posts.\n", OPTION_LIST_POSTS);
        printf("%d. Return to principal menu.\n",OPTION_RETURN_MENU);
        option = read_int("Choose your option:\n");

        if(option==OPTION_REQUEST){
            ;
        }
        else if(option==OPTION_MANAGE){
            ;
        }
        else if(option==OPTION_POST){
            ;
        }
        else if(option==OPTION_LIST_POSTS){
            ;
        }

        else if(option==OPTION_RETURN_MENU){
            ;//DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }
    }
}

/**
 * Menú principal del programa, que inicialitza la xarxa social.
 * Té tres opcions possibles, les quals ens porten a altres funcions i submenús.
 */
void showMenu () {
    printf("\nWelcome to our social Network!\n");
    printf("What do you want to do?\n");

    Network *net = initNetwork ();
    readFile (net,"../Files/20users.csv");

    int option = INVALID_OPTION;

    while (option != OPTION_QUIT){

        printf("\n%d. Insert new user.\n",OPTION_NEW_USER);
        printf("%d. List all existing users.\n",OPTION_LIST_USERS);
        printf("%d. Operate over an specific user.\n",OPTION_OPERATE_USER);
        printf("%d. Quit.\n",OPTION_QUIT);
        option = read_int("Choose your option:\n");

        // Afegim un nou usuari.
        if(option==OPTION_NEW_USER)
            newUser_Network (net);

        // Imprimim tots els usuaris.
        else if(option==OPTION_LIST_USERS)
            printNetwork (net);

        // Inspeccionem la llista i mirem si hi ha l'usuari que busquem.
        else if(option==OPTION_OPERATE_USER){

            printf("\nWhich user do you want to operate with?\n");

            char buffer[BUFFER_SIZE];
            fgets (buffer, BUFFER_SIZE, stdin);

            int idx = searchNetwork (buffer, net, NAME);

            // Si l'usuari és inexistent, hi ha error; si no, operem amb aquest.
            if(idx==USER_NOT_FOUND)
                printf("\nThe user was not found!\n");
            else
                operateUser (&net->user[idx]);
        }

        else if(option==OPTION_QUIT)
            ; //DO NOTHING

        else
            printf("\nInvalid option!\n");
    }

    clearNetwork (net);
}


