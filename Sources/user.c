//
// Created by Usuari on 26/4/2023.
//

#include "../Headers/user.h"


void new_data(User *user){
    // Introduïm el nom de l'usuari.
    printf("Introduce your username:");
    read_bounded_str(user->name, "name", MIN_STRING, MAX_NAME);
    // Introduïm l'edat de l'usuari.
    user->age = read_int("Introduce your age:");
    // Introduïm la direcció.
    printf("Introduce your e-mail:");
    read_bounded_str(user->email, "e-mail", MIN_STRING, MAX_EMAIL);
    // Introduïm l'habitatge.
    printf("Introduce your city or town:");
    read_bounded_str(user->home, "home", MIN_STRING, MAX_HOME);
    // Introduïm les aficions
    printf("Introduce your hobbies:\n");
    for(int i=0; i<QUANTITY; i++){
        printf("\tHobby %d:", i+1);
        read_bounded_str(user->hobbies[i]->hobby, "hobby", MIN_STRING, MAX_HOBBY);
    }
}

void print_user(User *user){
    printf("Name: %s\n""Age: %d\n""Address: %s\n""Home: %s\n",
           *user->name, user->age, *user->email, *user->home);
    for(int i=0; i<QUANTITY; i++){
        printf("Hobby %d: %s", i, *user->hobbies[i]->hobby);
    }
}

void operate_user(){
    printf("\nWhat do you want to do?\n");

    int option = INVALID_OPTION;

    while(option!=OPTION_RETURN_MENU){

        printf("\n%d. Send friend request.\n",OPTION_REQUEST);
        printf("%d. Manage the pending requests.\n",OPTION_MANAGE);
        printf("%d. Make a new post.\n",OPTION_POST);
        printf("%d. List all of the user posts.\n", OPTION_LIST_POSTS);
        printf("%d. Return to principal menu.\n",OPTION_RETURN_MENU);
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