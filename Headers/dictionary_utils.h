//
// Created by yjian on 05/06/2023.
//

#ifndef XARXA_SOCIAL_DICTIONARY_UTILS_H
#define XARXA_SOCIAL_DICTIONARY_UTILS_H

#include "search_utils.h"

void add_value(int value, char* key, Dict* dictionary);

int search_index_with_key(char* key, Dict* dictionary);

int search_value(char* key, Dict* our_dictionary);

void print_dictionary_elements(Dict* dictionary);

void count_words(Dict* dictionary, char* post);

void read_words(Dict* dictionary, char* post);

#endif //XARXA_SOCIAL_DICTIONARY_UTILS_H
