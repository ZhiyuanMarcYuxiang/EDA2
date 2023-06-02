//
// Created by Usuari on 28/5/2023.
//

#ifndef XARXA_SOCIAL_33_NEW_POST_H
#define XARXA_SOCIAL_33_NEW_POST_H

#include "34.list_posts.h"

void add_value(int value, char* key, Dict* our_dictionary);

int search_index_with_key(char* key, Dict* our_dictionary);

int search_value(char* key, Dict* our_dictionary);

int eliminate_value(char* key, Dict* our_dictionary);

void print_dictionary_elements(Dict* dictionary);

void word_count(Dict* dictionary, char* post);

void newPost (Network* net, int idx);

#endif //XARXA_SOCIAL_33_NEW_POST_H
