//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/network_file_control.h"

void writeFile (User *user, int size, FILE *fp){

    fprintf(fp,"NAME,AGE,E-MAIL,HOME,HOBBY 1,HOBBY 2,HOBBY 3,HOBBY 4,HOBBY 5\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < ATTRIBUTES; ++j) {
            fputs(user[i].data[j], fp);
            if (j< HOBBY5)
                fprintf(fp,",");
        }
        if(i<size-1)
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
    char **data = initData();
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
            data[attr_idx] = copyAttribute (attribute);
            attr_idx++; char_idx = RESET;

            if (c=='\n' || c==EOF){

                jump_count++; if (jump_count == JUMP_BUG) break;

                user = expandUsers (user, user_idx);
                user[user_idx].data = copyData (data);
                user_idx++; attr_idx = RESET;

            }
        }
    } while (c!=EOF);

    net->user = user;
    net->size = user_idx;
    net->order = NOT_ORDERED;
}



void readFile (Network *net, const char *fileName){

    FILE *fp = fopen(fileName,READING_PLUS_MODE);
    char buffer[BUFFER_SIZE];
    Read_Titles_Line (buffer, fp);
    Read_Users_Lines (net, buffer, fp);
    fclose(fp);
}


void appendFile (User user, const char *fileName){
    FILE *fp = fopen(fileName,APPENDING_MODE);
    fprintf(fp,"\n");
    for (int j = 0; j < ATTRIBUTES; ++j) {
        fputs(user.data[j], fp);
        if (j< HOBBY5)
            fprintf(fp,",");
    }
    fclose(fp);
}

