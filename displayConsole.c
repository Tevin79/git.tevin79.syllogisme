#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "writing.h"
#include "displayConsole.h"

#define TABLE_SIZE 3

void printHeader(void) {
    system("clear");
    printf("\n\n-----SYLOGISME-----\n\n");
}

void printProps(char **props) {
    if (props != NULL) {
        printf("Propositions :\n");
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (props[i] != NULL) {
                printf("    Proposition %d : %s\n", i+1, props[i]);
            } else {
                printf("    Proposition %d : \n", i+1);
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
    int choice = 0;
    do {
        printf("Please enter an option : ");
        if (scanf(" %d", &choice) != 1) {
            clearerr( stdin );
            scanf( "%*[^\n]" );
            scanf( "%*c" );
            choice = 0;
        }
    } while (choice < 1 || choice > 4);
    switch (choice) {
        case 1:
            if (add) {
                printAddPropChoice(propTable);
            } else {
                printPropChoice(propTable);
            }
            break;
        case 2:
            if (rem) {
                printPropChoice(propTable);
            } else {
                printPropChoice(propTable);
            }
            break;
        case 3:
            if (rem) {
                printPropChoice(propTable);
            } else {
                printPropChoice(propTable);
            }
            break;
        case 4: exit(0);
    }
}

void printAddPropChoice(char **propTable) {
    printHeader();
    printf("Choose between the ... :\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (propTable[i] == NULL) {
            printf("    %d : Proposition %d \n",i+1 , i+1);
        }
    }
    printf("    4 : Back\n");
    printf("    5 : Exit\n");
    printf("\n");
    int choice;
    do {
        printf("Please enter an option : ");
        if (scanf(" %d", &choice) != 1) {
            clearerr( stdin );
            scanf( "%*[^\n]" );
            scanf( "%*c" );
            choice = 0;
        }
    } while (choice < 1 || choice > 5);
    if (choice >= 1 && choice <= 3) {
        printAddProp(propTable, choice);
    } else if (choice == 4) {
        printPropChoice(propTable);
    } else if (choice == 5) {
        exit(0);
    }
}

void printAddProp(char **propTable, int index) {
    if (propTable[index] != NULL) {
        printAddPropChoice(propTable);
    }
    printHeader();
    printf("Please enter a value to put in the proposition %d : ", index);
    char value[100];
    scanf(" %[^\n]", value);
    if (addProp(propTable, index-1, value) == 0) {
        printPropChoice(propTable);
    } else {
        printPropChoice(propTable);
    }
}
