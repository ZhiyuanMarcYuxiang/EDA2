//
// Created by Usuari on 26/4/2023.
//

#include "../Headers/3_user.h"

/**
 * @param user: Llista d'usuaris.
 * Llegim dades per consola i les introdueix en un usuari.
 */
void new_user_data(User *user, int size){
    // L'usuari nou és l'últim de la llista.
    int last = size-1;
    printf("\n");
    // Introduïm el nom de l'usuari. Verifiquem que no estigui ja a la llista l'usuari.
    printf("Introduce your username:");
    read_name(user[last].name, user, size);

    // Introduïm l'edat de l'usuari.
    read_age(&user[last].age);

    // Introduïm l'adreça de correu. Verifiquem que no el correu tampoc estigui agafat.
    printf("Introduce your e-mail:");
    read_email(user[last].email);

    // Introduïm el lloc d'habitatge.
    printf("Introduce your city or town:");
    read_bounded_str(user[last].home, "home", MAX_HOME);

    // Introduïm els hobbies de l'usuari.
    new_hobbies(user[last].hobbies);
}

void read_age(int *num){
    *num = read_int(MSG_AGE);
    while(*num<0){
        printf("The age cannot be a negative number!\n");
        *num = read_int(MSG_AGE);
    }
}

void read_email(char *email){
    read_bounded_str(email, "e-mail", MAX_EMAIL);
    int i = 0;
    while(email[i] != '@' && i<strlen(email)){
        i++;
    }
}


/**
 * @param name: Nom de l'usuari que s'inicialitzarà.
 * @param user: Llista d'usuaris.
 * @param size: Mida màxima de la llista d'usuaris.
 * Demana per consola un nom d'usuari verificant que aquest no estigui ja a la llista i tingui una longitud
 * màxima de caràcters.
 */
void read_name(char* user_name, User* user, int size){
    // Declarem un usuari temporal per a desar-hi la informació llegida.
    char temp[MAX_NAME];
    read_bounded_str(temp,"name",MAX_NAME);
    if(size>1){
        while (binary_search_users(temp, user, size) != USER_NOT_FOUND){
            printf("Already registered name!\n");
            printf("Enter a new name:");
            read_bounded_str(temp,"name",MAX_NAME);
        }
    }
    strcpy(user_name,temp);
}

/**
 * @param user: Usuari inicialitzat amb valors.
 * Imprimim per pantalla els atributs d'un usuari.
 */
void print_user(User user){
    printf("Name: %s\n""Age: %d\n""Address: %s\n""Home: %s\n",
           user.name, user.age, user.email, user.home);
    print_hobbies(user.hobbies);
}

/**
 * @param copy: Usuari no necessàriament inicialitzat que rebrà atributs copiats.
 * @param origin: Usuari inicialitzat d'on s'extrauran els valors per a copiar-los.
 * Copiem tots els valors de l'usuari d'origen a l'usuari còpia.
 */
void copy_user_data(User *copy,User *origin){
    copy->age = origin->age;
    strcpy(copy->name,origin->name);
    strcpy(copy->email,origin->email);
    strcpy(copy->home,origin->home);
    copy_hobbies(copy->hobbies,origin->hobbies);
}

/**
 * @param user_to_search: Nom de l'usuari que volem buscar.
 * @param user: Llista d'usuaris.
 * @param size: Mida de la llista.
 * @return Retornem TRUE si el nom d'usuari està fitat dins la llista alfabèticament i FALSE en cas contrari.
 * Exemple: tenim els usuaris ["Jordi", "Miquel", "Xavier"] i volem buscar si existeix "Arnau". Aquest nom sabem que
 * no pertany a la llista ja que els extrems són 'J' i 'X'. Això ens evitarà aplicar l'algoritme Binary Search.
 */
int user_fenced_in_list(char user_to_search[], User* user, int size){
    // Perquè estigui fitat l'usuari ha de ser més gran o igual al primer usuari o més petit o igual a l'últim.
    int lowBound = strcmp(user[0].name, user_to_search);
    int highBound = strcmp(user[size-1].name, user_to_search);
    if (-1<=lowBound && highBound<=1)
        return TRUE;
    return FALSE;
}


/**
 * @param user_to_search: Un usuari a cercar a la llista.
 * @param user: Llista d'usuaris inicialitzada i ordenada alfabèticament.
 * @param size: Un enter no negatiu.
 * @return: Ens retorna l'índex de l'usuari dins la llista en cas de ser trobat i un error en cas contrari.
 */
int binary_search_users(char user_to_search[], User* user, int size){

    // Inicialitzem els tres índexs.
    int left,right,mid;
    left = 0;
    right = size-1;

    while (left<=right){

        mid = (left+right)/2;

        // Si l'usuari que hem introduït és més gran en ASCII que el de la llista,
        // senyal que l'usuari no és entre els primers de l'alfabet i avancem el punter esquerre.
        if(strcmp(user_to_search,user[mid].name)==1){
            left = mid+1;
            // Si l'usuari és més petit en ASCII, llavors està entre els primers i avancem el dret.
        }else if(strcmp(user_to_search,user[mid].name)==-1){
            right = mid-1;
            // Altrament, hem trobat l'usuari i retornem la posició dins de la llista.
        }else{
            return mid;
        }
    }
    // Si no hem trobat l'usuari, la cerca no ha estat exitosa.
    return USER_NOT_FOUND;
}


/**
 * @param user: Usuari inicialitzat amb valors per als seus atributs.
 * @param size: Mida de la llista d'usuaris.
 * @return Retornem una nova llista d'usuaris ordenada ascendentment a partir de l'atribut del nom.
 * "Merge Sort" és un ordenament de recursiu a partir de trossejar i combinar la llista.
 */
User* merge_sort(User *user, int size){
    //
    if (size == 1)
        return user;

    int mid = size/2;

    User *lowerHalf = &user[0];
    User *upperHalf = &user[mid];

    lowerHalf = merge_sort(lowerHalf, mid);
    upperHalf = merge_sort(upperHalf, size-mid);

    return merge(lowerHalf, mid, upperHalf, size-mid);
}

/**
 * @param userA: Sub-llista d'usuaris inicialitzada (meitat inferior).
 * @param sizeA: Mida de "userA".
 * @param userB: Sub-llista d'usuaris inicialitzada (meitat superior)
 * @param sizeB: Mida de "userB".
 * @return Retornem una nova llista d'usuaris, userC, que és la combinació ordenada de les llistes userA i userB.
 */
User* merge(User *userA, int sizeA, User *userB, int sizeB){
    User *userC = malloc(sizeof(User));
    int sizeC = 0, idx;

    // Afegim els elements de A i B de forma ordenada a C.
    while(sizeA!=0 && sizeB!=0){
        idx = sizeC;
        sizeC++;
        userC = realloc(userC,sizeC*sizeof(User));

        if(strcmp(userA[0].name,userB[0].name) == 1){
            copy_user_data(&userC[idx],&userB[0]);
            delete_first_user(userB,sizeB);
            sizeB--;
        }else{
            copy_user_data(&userC[idx],&userA[0]);
            delete_first_user(userA,sizeA);
            sizeA--;
        }
    }

    // En aquest punt, alguna de les dues llistes, A o B, està buida.

    // Afegim els elements que falten de A a la llista C.
    while(sizeA != 0){
        idx = sizeC;
        sizeC++;
        userC = realloc(userC,sizeC*sizeof(User));

        copy_user_data(&userC[idx],&userA[0]);
        delete_first_user(userA,sizeA);
        sizeA--;
    }

    // Afegim els elements que falten de B a la llista C.
    while(sizeB != 0){
        idx = sizeC;
        sizeC++;
        userC = realloc(userC,sizeC*sizeof(User));

        copy_user_data(&userC[idx],&userB[0]);
        delete_first_user(userB,sizeB);
        sizeB--;
    }

    // Retornem la llista combinada.
    return userC;
}

/**
 * @param user: Llista d'usuaris inicialitzada amb almenys dos usuaris.
 * @param size: Tamany de la llista.
 * S'elimina el primer usuari de la llista: això s'assoleix desplaçant tots els usuaris una posició endavant.
 */
void delete_first_user(User *user, int size){
    if(size>=2)
        for(int i = 0; i < (size-1); i++)
            user[i] = user[i+1];
}

