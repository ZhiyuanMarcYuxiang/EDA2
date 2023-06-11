
#include "../Headers/dictionary_utils.h"

void add_value(int value, char* key, Dict* dictionary) {

    // Diccionari ple.
    if(dictionary->current_element == MAX_DICTIONARY_ELEMENTS) {
        printf("Dictionary is full");
        return;
    }

    // Diccionari no buit amb clau existent.
    int i = 0;
    while (i<MAX_DICTIONARY_ELEMENTS && dictionary->current_element != 0) {
        if (strcmp(key, dictionary->element[i].key) == 0) {
            // Substituïm el nou valor pel valor vell
            dictionary->element[i].value = value;
            return;
        }
        i++;
    }

    // Si arriba a aquesta part, vol dir que la clau no existeix i el diccionari no està ple
    dictionary->element[dictionary->current_element].key = copyString(key);
    dictionary->element[dictionary->current_element].value = value;
    dictionary->current_element += INCREMENT_SIZE;
}

int search_index_with_key(char* key, Dict* dictionary) {
    int i = 0;
    while (i<MAX_DICTIONARY_ELEMENTS && dictionary->current_element != 0) {
        if (strcmp(key, dictionary->element[i].key) == 0) {
            // retorna l'índex on està situat l’element (clau i valor)
            return i;
        }
        i++;
    }
    return -1;
}

int search_value(char* key, Dict* our_dictionary) {
    // aprofitar la funció definida abans
    if (search_index_with_key(key, our_dictionary) == -1) {
        return -1;
    }

    int idx = search_index_with_key(key, our_dictionary);
    return our_dictionary->element[idx].value;

}

int maxWordlength (Dict* dictionary) {
    int idx = 0;
    int max = 0;
    int length;

    while (idx<MAX_DICTIONARY_ELEMENTS && dictionary->current_element >= MAX_DICTIONARY_ELEMENTS ||
    idx < dictionary->current_element && dictionary->current_element < MAX_DICTIONARY_ELEMENTS) {

        length = strlen(dictionary->element[idx].key);
        if(max < length) {
            max = length;
        }
        idx++;
    }
    return max;
}

void print_dictionary_elements(Dict* dictionary) {
    int idx = 0;
    printf("\n");

    while (idx<MAX_DICTIONARY_ELEMENTS && dictionary->current_element >= MAX_DICTIONARY_ELEMENTS ||
    idx < dictionary->current_element && dictionary->current_element < MAX_DICTIONARY_ELEMENTS) {

        if (search_value(dictionary->element[idx].key, dictionary) != 0) {
            printf("WORD:%s ", dictionary->element[idx].key);
            printSpaces(dictionary->element[idx].key, maxWordlength(dictionary));
            printf("USED:%d\n", dictionary->element[idx].value);
        }
        idx++;
    }
}

void count_words(Dict* dictionary, char* post) {

    int value;
    if (search_value(post, dictionary) == -1) {
        add_value(1, post, dictionary);
    }
    else {
        value = search_value(post, dictionary);
        add_value(value + 1, post, dictionary);
    }
}

void read_words(Dict *dictionary, char* post) {
    int idx = 0;
    char* buffer = malloc(BUFFER_SIZE*sizeof(char));
    count_words(dictionary, "");
    for(int i = 0; i<strlen(post); i++) {
        if(post[i] != ' ' && post[i] != '!' && post[i] != '?' && post[i] != '.' &&
           post[i] != ',' && post[i] != ':' && post[i] != ';' && i!= strlen(post)-1) {
            buffer[idx] = tolower(post[i]);
            idx++;
        }
        else if(post[i] == ' ' || post[i] == '!' || post[i] == '?' || post[i] == '.' ||
                post[i] == ',' || post[i] == ':' || post[i] == ';') {
            buffer[idx] = '\0';
            count_words(dictionary, buffer);
            buffer = NULL;
            buffer = malloc(BUFFER_SIZE*sizeof(char));
            idx = 0;
        }
        else if(i == strlen(post)-1) {
            if (post[i] != ' ' && post[i] != '!' && post[i] != '?' && post[i] != '.' ||
                post[i] != ',' && post[i] != ':' && post[i] != ';'){
                buffer[idx] = tolower(post[i]);
                buffer[idx+1] = '\0';
            }
            count_words(dictionary, buffer);
        }
    }
}