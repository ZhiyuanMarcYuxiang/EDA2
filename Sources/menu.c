//
// Created by Marc on 26/4/2023.
//

#include "../Headers/menu.h"

// MARC BOSCH BRANCH

void show_menu(){
    int option = INVALID_OPTION;
    ArrayUsers *arrayUsers = init_users();

    printf("\nWelcome to our social Network!\n");
    printf("What do you want to do?\n");

    while (option != OPTION_QUIT){
        printf("\n%d. Insert new user.\n",OPTION_NEW_USER);
        printf("%d. List all existing users.\n",OPTION_LIST_USERS);
        printf("%d. Operate over an specific user.\n",OPTION_OPERATE_USER);
        printf("%d. Quit.\n",OPTION_QUIT);
        option = read_int("Choose your option:\n");

        if(option==OPTION_NEW_USER){
            new_user(arrayUsers);
        }
        else if(option==OPTION_LIST_USERS){
            print_list_users(arrayUsers);
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

ArrayUsers* init_users(){
    ArrayUsers *aU = malloc(sizeof(ArrayUsers));
    aU->size = 0;
    aU->user = malloc(sizeof(User));
    return aU;
}

void new_user(ArrayUsers *aU){
    int i = aU->size;
    aU->size += 1;
    aU->user = realloc(aU->user,aU->size*sizeof(User));
    new_data(&aU->user[i]);
}

void print_list_users(ArrayUsers *aU){
    for(int i=0; i<aU->size; i++){
        print_user(&aU->user[i]);
    }
}



