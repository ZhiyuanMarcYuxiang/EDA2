//
// Created by Usuari on 13/5/2023.
//

#ifndef XARXA_SOCIAL_FILE_CONTROL_H
#define XARXA_SOCIAL_FILE_CONTROL_H



#define USERS_FILE "../Files/20users.csv"

#define JUMP_BUG 2

#define READING_PLUS_MODE "r+"
#define READING_MODE "r"
#define APPENDING_MODE "a"

#include "network_data_control.h"


// Es llegeix els usuaris del fitxer en mode lectura.
void readFile (Network *net, const char *fileName);

void appendFile (User user, const char *fileName);

#endif //XARXA_SOCIAL_FILE_CONTROL_H

