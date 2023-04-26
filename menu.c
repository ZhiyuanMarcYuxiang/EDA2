//
// Created by Marc on 26/4/2023.
//

#include "menu.h"
#include "stdio.h"

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

void new_user(){
    ;
}

void list_users(){
    ;
}

void operate_user(){
    printf("What do you want to do?\n");
    int option = INVALID_OPTION;

    while (option != OPTION_QUIT){
        printf("%d. Send friend request\n");
    }


    ;
}

/*
 * Enviar solicitudes de amistad
Gestionar las solicitudes pendientes
Realizar una publicación
Listar las publicaciones del usuario seleccionado
volver al menú principal.
Salir (Terminar ejecución)
Crear el typedef para el usuario (20 min), como mínimo el usuario debe registrar:
nombre de usuario
edad ( o bien año de nacimiento)
dirección de correo electrónico
Ubicación actual (Ciudad)
Lista de 5 gustos o preferencias.
Crear una interfaz para llenar los datos básicos de los usuarios (60 min)
Añadir automáticamente cada usuario creado a una lista dinámica de usuarios (40 min)
Listar los usuarios registrados
 */

