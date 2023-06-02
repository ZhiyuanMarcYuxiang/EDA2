//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/33.new_post.h"

void add_value(int value, char* key, Dict* our_dictionary) {
    int i = 0;
    while (i<our_dictionary->size && our_dictionary->count != 0) {
        if (strcmp(key, our_dictionary->elements[i].key) == 0) {
            our_dictionary->elements[i].value = value;
            return;
        }
        i++;
    }

    if(our_dictionary->count == our_dictionary->size) {
        printf("Dictionary is full");
        return;
    }

    our_dictionary->elements[our_dictionary->count].key = key;
    our_dictionary->elements[our_dictionary->count].value = value;
    our_dictionary->count++;
}

int search_index_with_key(char* key, Dict* our_dictionary) {
    int i = 0;
    while (i<our_dictionary->size && our_dictionary->count != 0) {
        if (strcmp(key,our_dictionary->elements[i].key) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

int search_value(char* key, Dict* our_dictionary) {
    if (search_index_with_key(key, our_dictionary) == -1) {
        return -1;
    }
    int idx = search_index_with_key(key, our_dictionary);
    return our_dictionary->elements[idx].value;

}

int eliminate_value(char* key, Dict* our_dictionary) {
    if (search_index_with_key(key, our_dictionary) == -1) {
        return -1;
    }
    int idx = search_index_with_key(key, our_dictionary);
    our_dictionary->elements[idx].key = NULL;
    our_dictionary->elements[idx].value = 0;
    our_dictionary->count--;
}


void print_dictionary_elements(Dict* dictionary) {
    int idx = 0;
    while (idx<10 && dictionary->count>=10 || idx<dictionary->count) {
        if (search_value(dictionary->elements[idx].key, dictionary) != 0) {
            printf("%d %s %d\n", idx, dictionary->elements[idx].key, dictionary->elements[idx].value);
        }
        idx++;
    }
}

void word_count(Dict* dictionary, char* post) {

    int value;
    if (search_value(post, dictionary) == -1) {
            add_value(1, post, dictionary);
    }
    else {
            value = search_value(post, dictionary);
            add_value(value + 1, post, dictionary);
    }
    print_dictionary_elements(dictionary);
}

// Funció molt similar a newUser.

void newPost (Network *net, int idx) {
    int last = net->user->posts_size;
    net->user->post = expandPosts(net->user->post, last);
    net->dictionary = expandElements(net->dictionary, net->dictionary->count);
    printf("dict_size: %d %d", net->dictionary->count, net->dictionary->size);
    printf("\nWrite your new post:\n");
    net->user[idx].post[last] = readString();
    word_count(net->dictionary, net->user[idx].post[last]);
    net->user[idx].posts_size += INCREMENT_SIZE;
}
