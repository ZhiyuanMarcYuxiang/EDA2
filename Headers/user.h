//
// Created by Usuari on 26/4/2023.
//

#ifndef XARXA_SOCIAL_USER_H
#define XARXA_SOCIAL_USER_H

#define MAX_HOBBY 20
#define MAX_EMAIL 30
#define QUANT_HOBBIES 5


typedef struct{
    char *hobby[MAX_HOBBY];
}Hobbies;

typedef struct{
    int age;
    char *email[MAX_EMAIL];
    char home;
    Hobbies *hobby[QUANT_HOBBIES];
}User;


#endif //XARXA_SOCIAL_USER_H

