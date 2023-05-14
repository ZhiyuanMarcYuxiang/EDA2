//
// Created by Usuari on 13/5/2023.
//

#ifndef XARXA_SOCIAL_2_NET_UTILS_H
#define XARXA_SOCIAL_2_NET_UTILS_H

#endif //XARXA_SOCIAL_2_NET_UTILS_H

#define READING_MODE "r"
#define WRITING_MODE "w"
#define APPENDING_MODE "a"

#include "search_utils.h"

// Es llegeix els usuaris del fitxer en mode lectura.
void readFile (Network *net, const char *fileName);

void writeFile (Network *net, const char *fileName);

void appendFile (User user, const char *fileName);

