#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 3

char **initProp(void) {
    char **table = (char **)malloc(sizeof(char *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
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
