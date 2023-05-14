//
// Created by Usuari on 27/4/2023.
//

#include "../Headers/search_utils.h"

/**
 * @param net: Llista d'usuaris inicialitzada i necessàriament ordenada.
 * @return: Ens retorna l'índex de l'usuari dins la llista en cas de ser trobat i un error en cas contrari.
 */
int searchNetwork (char* attribute, Network *net, int type){

    sortNetwork (net,type);                             // S'ordena la llista segons el tipus d'atribut escollit.

    if(fencedAttribute (attribute, net, type) == TRUE)  // Verifiquem que estigui fitat dins la llista (més probable que hi pertanyi).
        return binarySearch (attribute, net, type);     // Iniciem la cerca binària de l'atribut i en retornem l'índex.
    else
        return USER_NOT_FOUND;                          // Si el nom de l'usuari no està fitat, no intentarem cercar-lo.
}

/**
 * @param user_to_search: Nom de l'usuari que volem buscar.
 * @param user: Llista d'usuaris.
 * @param size: Mida de la llista d'usuaris.
 * @param type: Tipus d'atribut de l'usuari (NAME, AGE, EMAIL, etc.).
 * @return Retornem TRUE si el nom d'usuari està fitat dins la llista alfabèticament i FALSE en cas contrari.
 * Exemple: tenim els usuaris ["Jordi", "Miquel", "Xavier"] i volem buscar si existeix "Arnau". Aquest nom sabem que
 * no pertany a la llista ja que els extrems són 'J' i 'X'. Això ens evitarà aplicar l'algoritme Binary Search.
 */
int fencedAttribute (char* attribute, Network *n, int type){

    int first = 0;
    int last = n->size-1;

    int lowBound = strcmp(n->user[first].attr[type], attribute);     // Perquè estigui fitat l'usuari ha de ser més gran
    int highBound = strcmp(n->user[last].attr[type], attribute);     // o igual al primer usuari o més petit o igual a l'últim.
    if (LESSTHAN <= lowBound && highBound<= GREATERTHAN)
        return TRUE;
    return FALSE;
}


/**
 * @param user_to_search: Un usuari a cercar a la llista.
 * @param user: Llista d'usuaris inicialitzada i ordenada alfabèticament.
 * @param size: Un enter no negatiu.
 * @param type: Tipus d'atribut de l'usuari (NAME, AGE, EMAIL, etc.).
 * @return: Ens retorna l'índex de l'usuari dins la llista en cas de ser trobat i un error en cas contrari.
 */
int binarySearch (char* attribute, Network *n, int type){

    int left,right,mid; int cmp;               // Inicialitzem els tres índexs i també un enter de comparació.
    left = 0;                                  // L'índex de l'esquerra comença a la posició 0.
    right = n->size-1;                         // L'índex de la dreta comença a la posició última.

    while (left<=right) {                      // Mentre els índexs no es creuin.

        mid = (left+right)/2;
        cmp = strcmp(attribute, n->user[mid].attr[type]); // Comparació entre l'atribut a cercar i un atribut de la llista.

        if (cmp == GREATERTHAN){                // Si l'usuari que hem introduït és més gran en ASCII que el de la llista,
            left = mid+1;                       // vol dir que l'usuari no és entre els primers de l'alfabet i avancem el punter esquerre.

        }else if (cmp == LESSTHAN){             // Si no, si l'usuari és més petit en ASCII,
            right = mid-1;                      // llavors està entre els primers i avancem el dret.

        }else{                                  // Altrament, hem trobat l'usuari i retornem la posició dins de la llista.
            return mid;
        }
    }
    return USER_NOT_FOUND;           // En cas de no haver trobat l'usuari, la cerca no ha estat exitosa.
}







