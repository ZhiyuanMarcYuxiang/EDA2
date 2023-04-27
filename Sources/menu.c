//
// Created by Marc on 26/4/2023.
//

#include "../Headers/menu.h"

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

        if(option==OPTION_NEW_USER){
            new_user(n);
        }
        else if(option==OPTION_LIST_USERS){
            print_list_users(n);
        }
        else if(option==OPTION_OPERATE_USER){
            operate_user(n);
        }
        else if(option==OPTION_QUIT){
            ; //DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }
    }
}


