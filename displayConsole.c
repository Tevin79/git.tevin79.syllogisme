#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "writing.h"

#define TABLE_SIZE 3

void printHeader(void) {
    system("clear");
    printf("-----SYLOGISME-----\n\n");
}

void printProps(char **props) {
    if (props != NULL) {
        printf("Propositions :\n");
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (props[i] != NULL) {
                printf("    Proposition %d : %s\n", i+1, props[i]);
            } else {
                printf("    Proposition %d : ?\n", i+1);
            }
        }
        printf("\n");
    }
}

bool addPossible(char **propTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (propTable[i] == NULL) {
            return true;
        }
    }
    return false;
}

bool remPossible(char **propTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (propTable[i] != NULL) {
            return true;
        }
    }
    return false;
}

void printPropChoice(char **propTable) {
    printHeader();
    printProps(propTable);
    printf("Choose between the ... :\n");
    bool add = addPossible(propTable);
    bool rem = remPossible(propTable);
    if (add) {
        printf("    1 : Add a proposition\n");
    }
    if (rem) {
        printf("    2 : Remove a proposition\n");
        printf("    3 : Replace a proposition\n");
    }
    printf("    4 : Exit\n");
    printf("\n");
    printf("Please enter an option : ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        if (add) {
            printPropChoice(propTable);
        } else {
            printPropChoice(propTable);
        }
    } else if (choice == 2) {
        if (rem) {
            printPropChoice(propTable);
        } else {
            printPropChoice(propTable);
        }
    } else if (choice == 3) {
        if (rem) {
            printPropChoice(propTable);
        } else {
            printPropChoice(propTable);
        }
    } else if (choice == 4) {
        exit(0);
    } else {
        printPropChoice(propTable);
    }
}
