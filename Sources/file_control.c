//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/file_control.h"


/**
 * @param net: Xarxa d'usuaris inicialitzada.
 * @param fileName: Nom d'un fitxer .csv existent amb la primera línia emprada per títols i la resta per amb els
 * atributs dels usuaris. D'atributs n'hi ha d'haver de 9 tipus, d'usuris (files) tants com vulguem.
 * @param mode: Mode de lectura "r".
 * Llegim caràcter a caràcter cadascuna de les strings separades per comes i les col·loquem a xarxa social.
 */
void readFile (Network *net, const char *fileName){
    FILE *fp = fopen(fileName,READING_MODE);          // Obrim el fitxer en mode lectura.

    char buffer[BUFFER_SIZE]; char c;                 // Declarem una string auxiliar o "buffer" per a la lectura de caràcters de fitxer.
    fgets(buffer,BUFFER_SIZE,fp);                     // Llegim per caràcters la primera línia, la qual és la dels títols (no la utilitzem).

    int user_idx=0, attr_idx=0, char_idx=0;           // Inicialitzem a 0 els índexs per a recórrer l'array multidimensional d'usuaris.
    int jump_count = 0;                               // Jump count

    do{
        c = fgetc(fp);                                // Realitzem la lectura de la resta de línies del fitxer caràcter a caràcter.

        if(!(c==',' || c=='\n' || c == EOF)){                    // Si el caràcter no és coma, salt de línia o final de fitxer...
            buffer[char_idx] = c;                                      // Col·loquem el càracter dins la string auxiliar
            char_idx++; jump_count = 0;                                //  Incrementant l'índex dels caràcters.
        }
        else{                                                    // En cas contrari...
            buffer[char_idx] = '\0';                                   // Després de l'últim caràcter del buffer, hi col·loquem l'acabament de string.
            net->user[user_idx].attr[attr_idx] = init_and_copy(buffer); // Reservem memòria per una nova string (atribut de l'usuari).
            char_idx = 0; attr_idx++;                                  // Ressetejem l'índex dels caràcters i incremenetem l'índex dels atributs.


            if (c=='\n'){                                              // Si en particular detectem un salt de línia...
                net->user = expandUsers(net->user, user_idx+1);           // Ampliem la llista dels usuaris (segons un factor multiplicador).
                attr_idx = 0; user_idx++; jump_count++;                    // Ressetejem l'índex dels atributs i incrementem l'índex dels usuaris.
            }
        }
    } while (c!=EOF);                                 // Mentre el caràcter no sigui End Of File (OxFFFFFFFF).

    net->size = (user_idx+1)-jump_count;
    net->order = NOT_ORDERED;

    if(jump_count > 0)
        writeFile (net,fileName);

    fclose(fp);
}


void writeFile (Network *net, const char *fileName){
    FILE *fp = fopen(fileName,WRITING_MODE);
    fprintf(fp,"NAME,AGE,E-MAIL,HOME,HOBBY 1,HOBBY 2,HOBBY 3,HOBBY 4,HOBBY 5\n");
    for (int i = 0; i < net->size; ++i) {
        for (int j = 0; j < ATTRIBUTES; ++j) {
            fputs(net->user[i].attr[j], fp);
            if (j< HOBBY5)
                fprintf(fp,",");
        }
        if(i<net->size-1)
            fprintf(fp,"\n");
    }
    fclose(fp);
}

void appendFile (User user, const char *fileName){
    FILE *fp = fopen(fileName,APPENDING_MODE);
    fprintf(fp,"\n");
    for (int j = 0; j < ATTRIBUTES; ++j) {
        fputs(user.attr[j], fp);
        if (j< HOBBY5)
            fprintf(fp,",");
    }
    fclose(fp);
}

