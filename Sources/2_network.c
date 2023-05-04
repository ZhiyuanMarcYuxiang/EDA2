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
    n->size += 1;
    n->user = realloc(n->user, n->size*sizeof(User));
    new_user_data(n->user, n->size);
    sort_list(n);
}

/**
 * @param n: Llista d'usuaris inicialitzada.
 * Si la llista té més d'un usuari, i si el penúltim nom d'usuari no és més gran que l'últim  (el més recent introduït),
 * aleshores ordenem la llista. En cas contrari, no caldrà fer-ho.
 */

void sort_list(Network *n){
    int last = n->size-1;
    if(n->size > 1)  // Ordena si hi ha més d'un usuari
        if(strcmp(n->user[last-1].name, n->user[last].name)==1) // Ordena si el nom del penúltim > últim
            n->user = merge_sort(n->user, n->size);
}

/**
 * @param n: Llista d'usuaris inicialitzada i necessàriament ordenada.
 * @return: Ens retorna l'índex de l'usuari dins la llista en cas de ser trobat i un error en cas contrari.
 */
int search_list(Network *n){

    char user_to_search[MAX_NAME];
    scanf("%s",user_to_search);

    // Es verifica que l'usuari estigui fitat alfabèticament a la llista. Ex: 'J' pertany a ['B','T'].
    if(user_fenced_in_list(user_to_search, n->user, n->size) == TRUE)
        // S'inicia la cerca binària d'usuaris.
        return binary_search_users(user_to_search, n->user, n->size);

    // Si el nom de l'usuari no està fitat, no s'intentarà cercar-lo.
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

