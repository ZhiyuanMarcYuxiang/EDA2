//
// Created by Usuari on 26/4/2023.
//

#include "menu.h"
#include "stdio.h"

// Sóc el Yuxiang

void show_menu(){
    printf("\nWelcome to our social Network!\n");
    printf("What do you want to do?\n");

    int option = INVALID_OPTION;

    while (option != OPTION_QUIT){
        printf("\n%d. Insert new user.\n",OPTION_NEW_USER);
        printf("%d. List all existing users.\n",OPTION_LIST_USERS);
        printf("%d. Operate like an specific user.\n",OPTION_OPERATE_USER);
        printf("%d. Quit.\n",OPTION_QUIT);
        printf("Choose your option:\n");
        scanf("%d",&option);

        if(option==OPTION_NEW_USER){
            new_user();
        }
        else if(option==OPTION_LIST_USERS){
            list_users();
        }
        else if(option==OPTION_OPERATE_USER){
            operate_user();
        }
        else if(option==OPTION_QUIT){
            ; //DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }
    }
}

