//
// Created by Usuari on 26/4/2023.
//

#include "../Headers/option_utils.h"

#define FALSE 0



void flushInput (){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}



int readInt (const char* message){
    int num, matched;
    printf("%s",message);

    matched = scanf("%d",&num);

    while(matched == FALSE){

        flushInput();

        printf("Try again!\n");
        printf("%s",message);
        matched = scanf("%d",&num);
    }
    flushInput();
    return num;
}




