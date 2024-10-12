#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 7

int **initProp(void) {
    int **table = (int **)malloc(sizeof(int *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
    return table;
}

char ***initQuantificateur(void) {
    char ***table = (char ***)malloc(sizeof(char **) * 2);
    for (int i = 0; i < 2; i++) {
        table[i] = (char **)malloc(sizeof(char *) * 50);
        for (int j = 0; j < 50; j++) {
            table[i][j] = NULL;
        }
    }
    char *tt = "Tout";
    char *ie = "Il existe";
    char *c = "Certains";
    table[0][0] = (char *)malloc(sizeof(char) * strlen(tt));
    table[1][0] = (char *)malloc(sizeof(char) * strlen(ie));
    table[1][1] = (char *)malloc(sizeof(char) * strlen(c));
    strcpy(table[0][0], tt);
    strcpy(table[1][0], ie);
    strcpy(table[1][1], c);
    return table;
}

int addProp(char **props, int index, char *value) {
    if (index < TABLE_SIZE && props != NULL && props[index] == NULL && value != NULL) {
        int len = strlen(value);
        char *temp = (char *)malloc(sizeof(char) * (len + 1));
        strcpy(temp, value);
        temp[len] = '\0';
        props[index] = temp;
        return 1;
    }
    return 0;
}

int removeProp(char **props, int index) {
    if (props != NULL && index < TABLE_SIZE) {
        if (props[index] != NULL) {
            free(props[index]);
            props[index] = NULL;
        }
        return 1;
    }
    return 0;
}

int replaceProp(char **props, int index, char *value) {
    if (props != NULL && index < TABLE_SIZE && value != NULL) {
        if (props[index] != NULL) {
            removeProp(props, index);
        }
        addProp(props, index, value);
        return 1;
    }
    return 0;
}

void freeProp(char **props) {
    if (props != NULL) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (props[i] != NULL) {
                free(props[i]);
            }
        }
        free(props);
    }
}

void freeQuantificateur(char ***quant) {
    for (int i = 0; i < 2; i++) {
        int j = 0;
        while (quant[i][j] != NULL) {
            free(quant[i][j]);
        }
        free(quant[i]);
    }
    free(quant);
}
