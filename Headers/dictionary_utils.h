//
// Created by yjian on 05/06/2023.
//

#ifndef XARXA_SOCIAL_DICTIONARY_UTILS_H
#define XARXA_SOCIAL_DICTIONARY_UTILS_H

#include "search_utils.h"

#define KEY_NOT_FOUND (-1)

void addValue(int value, char* key, Dict* dictionary);

int searchIndexWithKey(char* key, Dict* dictionary);

int getValue(char* key, Dict* dictionary);

void printDictionaryElements(Dict* dictionary);

void countWords(Dict* dictionary, char* post);

void readWords(Dict* dictionary, char* post);

#endif //XARXA_SOCIAL_DICTIONARY_UTILS_H
