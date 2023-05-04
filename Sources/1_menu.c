//
// Created by Marc on 26/4/2023.
//

#include "../Headers/1_menu.h"

// MARC BOSCH BRANCH

/**
 * Menú principal del programa, que inicialitza la xarxa social.
 * Té tres opcions possibles, les quals ens porten a altres funcions i submenús.
 */
void show_menu(){
    printf("\nWelcome to our social Network!\n");
    printf("What do you want to do?\n");

    Network *n = init_users();
    int option = INVALID_OPTION;

    while (option != OPTION_QUIT){
        printf("\n%d. Insert new user.\n",OPTION_NEW_USER);
        printf("%d. List all existing users.\n",OPTION_LIST_USERS);
        printf("%d. Operate over an specific user.\n",OPTION_OPERATE_USER);
        printf("%d. Quit.\n",OPTION_QUIT);
        option = read_int("Choose your option:\n");

        // Afegim un nou usuari.
        if(option==OPTION_NEW_USER)
            new_user(n);

        // Imprimim tots els usuaris.
        else if(option==OPTION_LIST_USERS)
            print_list_users(n);

        // Inspeccionem la llista i mirem si hi ha l'usuari que busquem.
        else if(option==OPTION_OPERATE_USER){

            printf("\nWhich user do you want to operate with?\n");
            int idx = search_list(n);

            // Si l'usuari és inexistent, hi ha error; si no, operem amb aquest.
            if(idx==USER_NOT_FOUND)
                printf("\nThe user was not found!\n");
            else
                operate_user(&n->user[idx]);
        }

        else if(option==OPTION_QUIT)
            ; //DO NOTHING

        else
            printf("\nInvalid option!\n");

    }
}

/**
 * @param n: Llista d'usuaris inicialitzada i necessàriament ordenada.
 * Submenú que ens mostra quatre opcions específiques d'un usuari si l'usuari està registrat.
 */
void operate_user(User *user){

    printf("\nProfile of user %s initialized!\n",user->name);

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

