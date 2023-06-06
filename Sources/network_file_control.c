//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/network_file_control.h"

void writeFile (User *user, int users_size, FILE *fp){

    fprintf(fp,"NAME,AGE,E-MAIL,HOME,HOBBY 1,HOBBY 2,HOBBY 3,HOBBY 4,HOBBY 5\n");
    for (int i = 0; i < users_size; ++i) {
        for (int j = 0; j < ATTRIBUTES; ++j) {
            fputs(user[i].data[j], fp);
            if (j< HOBBY5)
                fprintf(fp,",");
        }
        if(i<users_size-1)
            fprintf(fp,"\n");
    }
    fclose(fp);
}


void Read_Titles_Line (char * buffer, FILE *fp){
    fgets(buffer,BUFFER_SIZE,fp);
}

void Read_Users_Lines (Network *net, char* attribute, FILE *fp){

    char c;
    User *user = initUser();
    char **data = initStringArray(ATTRIBUTES);
    int user_idx = SET_ZERO;
    int attr_idx = SET_ZERO;
    int char_idx = SET_ZERO;
    int jump_count = SET_ZERO;

    do{
        c = fgetc(fp);

        if(!(c==',' || c=='\n' || c == EOF)){
            attribute[char_idx] = c;
            char_idx++; jump_count = RESET;
        }
        else{
            attribute[char_idx] = '\0';
            data[attr_idx] = copyString(attribute);
            attr_idx++; char_idx = RESET;

            if (c=='\n' || c==EOF){

                // Per a solucionar el bug que es produeix quan últimes files buides del fitxer.
                jump_count++;if (jump_count == JUMP_BUG) break;

                user = expandUsers (user, user_idx);
                user[user_idx].data = copyStringArray(data, ATTRIBUTES);

                user[user_idx].post = initStringArray(ONE_SIZE);
                user[user_idx].posts_size = SET_ZERO;

                user[user_idx].friend = initStringArray(ONE_SIZE);
                user[user_idx].size_friends = SET_ZERO;

                user[user_idx].request = initStringArray(ONE_SIZE);
                user[user_idx].size_requests = SET_ZERO;

                user_idx++; attr_idx = RESET;

            }
        }
    } while (c!=EOF);

    net->user = user;
    net->users_size = user_idx;
    net->users_order = NOT_ORDERED;
}



void readUsersFile (Network *net, const char *fileName){

    FILE *fp = fopen(fileName,READING_PLUS_MODE);
    char buffer[BUFFER_SIZE];
    Read_Titles_Line (buffer, fp);
    Read_Users_Lines (net, buffer, fp);
    fclose(fp);
}


void appendUsersFile (User user, const char *fileName){
    FILE *fp = fopen(fileName,APPENDING_MODE);
    fprintf(fp,"\n");
    for (int j = 0; j < ATTRIBUTES; ++j) {
        fputs(user.data[j], fp);
        if (j< HOBBY5)
            fprintf(fp,",");
    }
    fclose(fp);
}

