//
// Created by Usuari on 27/4/2023.
//

#include "../Headers/2_network.h"

/**
 * @return Inicialitza una llista dinàmica d'usuaris.
 */
Network* init_users(){
    Network *n = malloc(sizeof(Network));
    n->user = malloc(sizeof(User));
    n->size = 0;
    return n;
}

/**
 * @param n: Llista d'usuaris inicialitzada.
 * Crea un nou usuari i li afegeix dades entrades per consola.
 * Finalment, per seguretat ordena la llista de forma ascendent segons el nom d'usuari.
 */
void new_user(Network *n){
    int i = n->size;
    n->size += 1;
    n->user = realloc(n->user, n->size*sizeof(User));
    new_user_data(&n->user[i]);
    sort_list(n);
}

/**
 * @param n: Llista d'usuaris inicialitzada.
 * Si la llista té més d'un usuari, i si el penúltim element no és més gran que l'últim (el més recent introduït),
 * aleshores ordenem la llista. En cas contrari, no caldrà fer-ho.
 */

void sort_list(Network *n){
    int last = n->size-1;
    if(n->size > 1)
        if(strcmp(n->user[last-1].name, n->user[last].name)==1)
            n->user = merge_sort(n->user, n->size);
}

/**
 * @param n: Llista d'usuaris inicialitzada i necessàriament ordenada.
 * @return: Ens retorna l'índex de l'usuari dins la llista en cas de ser trobat i un error en cas contrari.
 */
int search_list(Network *n){
    char user_to_search[MAX_NAME];
    scanf("%s",user_to_search);
    if(bounded_user(user_to_search, n->user, n->size) == TRUE)
        return binary_search_users(user_to_search, n->user, n->size);
    else
        return USER_NOT_FOUND;
}

/**
 * @param n: Llista d'usuaris inicialitzada.
 * Imprimeix per pantalla tots els usuaris inscrits a la xarxa.
 */
void print_list_users(Network *n){
    for(int i=0; i<n->size; i++){
        printf("\nUser: %d\n", i+1);
        print_user(n->user[i]);
    }
}

/**
 * @param n: Llista d'usuaris inicialitzada i necessàriament ordenada.
 * Submenú que ens mostra quatre opcions específiques d'un usuari si l'usuari està registrat.
 */
void operate_user(Network *n){
    printf("\nWhich user do you want to operate with?\n");
    int idx = search_list(n); // Inspecciona la llista i mira si existeix l'usuari que busquem.

    if(idx==USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
    }else{
        printf("\nProfile of user %s initialized!\n",n->user[idx].name);

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
}
