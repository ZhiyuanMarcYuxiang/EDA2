//
// Created by Marc on 26/4/2023.
//

#include "../Headers/menu.h"


// MARC BOSCH BRANCH

void show_menu(){
    printf("\nWelcome to our social Network!\n");
    printf("What do you want to do?\n");

    int option = INVALID_OPTION;

    while (option != OPTION_QUIT){
        printf("\n%d. Insert new user.\n",OPTION_NEW_USER);
        printf("%d. List all existing users.\n",OPTION_LIST_USERS);
        printf("%d. Operate like an specific user.\n",OPTION_OPERATE_USER);
        printf("%d. Quit.\n",OPTION_QUIT);
        option = read_int("Choose your option:\n");

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

void new_user(){
    ;
}

void list_users(){
    ;
}

void operate_user(){
    printf("What do you want to do?\n");

    int option = INVALID_OPTION;

    while(option!=OPTION_RETURN_MENU){

        printf("\n%d. Send friend request.\n",OPTION_REQUEST);
        printf("%d. Manage the pending requests.\n",OPTION_MANAGE);
        printf("%d. Make a new post.\n",OPTION_POST);
        printf("%d. List all of the user posts.\n", OPTION_LIST_POSTS);
        option = read_int("Choose your option:\n");

        if(option==OPTION_REQUEST){

        }
        else if(option==OPTION_MANAGE){

        }
        else if(option==OPTION_POST){

        }
        else if(option==OPTION_LIST_POSTS){

        }

        else if(option==OPTION_RETURN_MENU){
            ;//DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }
    }
}



