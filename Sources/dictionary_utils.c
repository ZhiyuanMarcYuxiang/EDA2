
#include "../Headers/dictionary_utils.h"

void add_value(int value, char* key, Dict* our_dictionary) {
    int i = 0;
    while (i<our_dictionary->size_elements && our_dictionary->count != 0) {
        if (strcmp(key, our_dictionary->elements[i].key) == 0) {
            // substituïm el nou valor pel valor vell
            our_dictionary->elements[i].value = value;
            return;
        }
        i++;
    }

    if(our_dictionary->count == our_dictionary->size_elements) {
        printf("Dictionary is full");
        return;
    }
    // Si arriba a aquesta part, vol dir que la key no existeix i el diccionari no està ple
    our_dictionary->elements[our_dictionary->count].key = key;
    our_dictionary->elements[our_dictionary->count].value = value;
    our_dictionary->count++;
}

int search_index_with_key(char* key, Dict* our_dictionary) {
    int i = 0;
    while (i<our_dictionary->size_elements && our_dictionary->count != 0) {
        if (strcmp(key,our_dictionary->elements[i].key) == 0) {
            // retorna el index on està situat l’element (clau i valor)
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
    return our_dictionary->elements[idx].value;

}

void print_dictionary_elements(Dict* dictionary) {
    int idx = 0;
    printf("\n");
    while (idx<10 && dictionary->count>=10 || idx<dictionary->count && dictionary->count<10) {
        if (search_value(dictionary->elements[idx].key, dictionary) != 0) {
            printf("%d. WORD:%s USED:%d\n", idx+1, dictionary->elements[idx].key, dictionary->elements[idx].value);
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

// Funció molt similar a newUser.

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
                buffer[idx] = post[i];
                buffer[idx+1] = '\0';
            }
            count_words(dictionary, buffer);
        }
        dictionary = expandElements(dictionary, dictionary->count);
    }
}